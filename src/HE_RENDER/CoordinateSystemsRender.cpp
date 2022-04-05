#include "pch.h"
#include "CoordinateSystemsRender.h"
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

IMPLEMENT_DYNAMIC_RENDER_GROUP(CCoordinateSystemsRender, RenderType::tutorial_CoordinateSystems, RenderGroup::learn_opengl)

CCoordinateSystemsRender::CCoordinateSystemsRender()
{
}

CCoordinateSystemsRender::~CCoordinateSystemsRender()
{
}

void CCoordinateSystemsRender::wglInitialUpdate(IRenderEngine* pRenderEngine)
{
	m_pRenderEngine = pRenderEngine;

	//////////////////////////////////////////////////////////////

	auto pRenderEngineImpl = static_cast<CRenderEngine*>(pRenderEngine);
	auto pShaderManager = pRenderEngineImpl->GetShaderManager();

	m_pProgram = pShaderManager->wglGetShaderProgram(ProgramType::tutorial_6_1_coordinate_systems);

	CString strContainer = GetImagePath(_T("container.jpg"));
	m_imgContainer = std::make_shared<CImageFile>(strContainer);

	CString strAwesome = GetImagePath(_T("awesomeface.png"));
	m_imgAwesome = std::make_shared<CImageFile>(strAwesome);
}

void CCoordinateSystemsRender::wglRelease()
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

void CCoordinateSystemsRender::wglBuild()
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

void CCoordinateSystemsRender::wglDraw()
{
	auto pRenderEngineImpl = static_cast<CRenderEngine*>(m_pRenderEngine);	
	auto fov = pRenderEngineImpl->GetFov();

	// render
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// bind textures on corresponding texture units
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_t2d_container);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, m_t2d_awesome);

	// create transformations
	glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	projection = glm::perspective(glm::radians(45.0f), fov, 0.1f, 100.0f);
	
	// get matrix's uniform location and set matrix
	m_pProgram->wglBind();
	m_pProgram->wglUniformMatrix4("u_model", model);
	m_pProgram->wglUniformMatrix4("u_view", view);
	m_pProgram->wglUniformMatrix4("u_projection", projection);

	// render container
	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	m_pProgram->wglUnbind();
}
