#include "pch.h"
#include "TransformationRender.h"
#include "RenderEngine.h"
#include "ImageFile.h"

#include "../HE_WGL/ShaderDefine.h"
#include "../HE_WGL/ShaderManager.h"
#include "../HE_WGL/ShaderProgram.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC_RENDER_GROUP(CTransformationRender, RenderType::tutorial_transformations, RenderGroup::learn_opengl)

CTransformationRender::CTransformationRender()
{
}

CTransformationRender::~CTransformationRender()
{
}

void CTransformationRender::wglInitialUpdate(IRenderEngine* pRenderEngine)
{
	auto pRenderEngineImpl = static_cast<CRenderEngine*>(pRenderEngine);
	auto pShaderManager = pRenderEngineImpl->GetShaderManager();

	m_pProgram = pShaderManager->wglGetShaderProgram(ProgramType::tutorial_5_1_transform);

	CString strContainer = GetImagePath(_T("container.jpg"));
	m_imgContainer = std::make_shared<CImageFile>(strContainer);

	CString strAwesome = GetImagePath(_T("awesomeface.png"));
	m_imgAwesome = std::make_shared<CImageFile>(strAwesome);
}

void CTransformationRender::wglRelease()
{
	if (m_VAO)
		glDeleteVertexArrays(1, &m_VAO);
	if (m_VBO)
		glDeleteBuffers(1, &m_VBO);
	if (m_EBO)
		glDeleteBuffers(1, &m_EBO);
	if (m_t2d_container)
		glDeleteTextures(1, &m_t2d_container);
	if (m_t2d_awesome)
		glDeleteTextures(1, &m_t2d_awesome);

	m_VAO = m_VBO = m_EBO = m_t2d_container = m_t2d_awesome = 0;
}

void CTransformationRender::wglBuild()
{
	float vertices[] = {
		// positions          // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // top right
		 0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, // bottom left
		-0.5f,  0.5f, 0.0f,   0.0f, 1.0f  // top left 
	};
	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_EBO);

	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	m_t2d_container = 0;
	m_t2d_awesome = 0;


	// TODO. wall texture
	glGenTextures(1, &m_t2d_container);
	glBindTexture(GL_TEXTURE_2D, m_t2d_container);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	auto& imgContainer = *m_imgContainer;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgContainer.width, imgContainer.height, 0, GL_RGB, GL_UNSIGNED_BYTE, &imgContainer.buffer[0]);
	glGenerateMipmap(GL_TEXTURE_2D);

	// TODO. awesome texture
	glGenTextures(1, &m_t2d_awesome);
	glBindTexture(GL_TEXTURE_2D, m_t2d_awesome);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	auto& imgAwesome = *m_imgAwesome;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgAwesome.width, imgAwesome.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &imgAwesome.buffer[0]);
	glGenerateMipmap(GL_TEXTURE_2D);

	m_pProgram->wglBind();
	m_pProgram->wglUniformInt("u_t2d_container", 0);
	m_pProgram->wglUniformInt("u_t2d_awesome", 1);
	m_pProgram->wglUnbind();

}
#include <chrono>
void CTransformationRender::wglDraw()
{
	auto since_epoch = std::chrono::system_clock::now().time_since_epoch();
	auto msec_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(since_epoch).count();
	auto angle = static_cast<float>(msec_since_epoch % 720);

	// render
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// bind textures on corresponding texture units
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_t2d_container);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, m_t2d_awesome);

	// create transformations
	glm::mat4 transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
	transform = glm::rotate(transform, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));

	// get matrix's uniform location and set matrix
	m_pProgram->wglBind();
	m_pProgram->wglUniformMatrix4("u_transform", transform);

	// render container
	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	m_pProgram->wglUnbind();
}
