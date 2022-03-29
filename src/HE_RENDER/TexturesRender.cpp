#include "pch.h"
#include "TexturesRender.h"
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

IMPLEMENT_DYNAMIC_RENDER_GROUP(CTexturesRender, RenderType::Tutorial_Textures, RenderGroup::learn_opengl)

CTexturesRender::CTexturesRender()
{
}

CTexturesRender::~CTexturesRender()
{
}

void CTexturesRender::wglInitialUpdate(IRenderEngine* pRenderEngine)
{
	auto pRenderEngineImpl = static_cast<CRenderEngine*>(pRenderEngine);
	auto pShaderManager = pRenderEngineImpl->GetShaderManager();
	
	m_pProgram = pShaderManager->wglGetShaderProgram(ProgramType::tutorial_textures);
	
	CString strWallPath = GetImagePath(_T("wall.jpg"));
	m_imgWall = std::make_shared<CImageFile>(strWallPath);

	CString strAwesomePath = GetImagePath(_T("awesomeface.png"));
	m_imgAwesome = std::make_shared<CImageFile>(strAwesomePath);
}

void CTexturesRender::wglRelease()
{
	if (m_vao)
		glDeleteVertexArrays(1, &m_vao);
	if (m_vbo)
		glDeleteBuffers(1, &m_vbo);
	if (m_ebo)
		glDeleteBuffers(1, &m_ebo);
	if (m_t2d_wall)
		glDeleteTextures(1, &m_t2d_wall);

	m_vao = m_vbo = m_ebo = m_t2d_wall = 0;
}

void CTexturesRender::wglBuild()
{
	float vertices[] = {
		// 위치              // 컬러             // 텍스처 좌표
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 우측 상단
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 우측 하단
	   -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 좌측 하단
	   -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 좌측 상단
	};
	
	unsigned int indices[] = {
	   0, 1, 3, // first triangle
	   1, 2, 3  // second triangle
	};

	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ebo);

	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	size_t stride = sizeof(float) * 8;
	size_t offset_color = sizeof(float) * 3;
	size_t offset_tex = sizeof(float) * 6;

	// TODO. vertex attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, static_cast<GLsizei>(stride), reinterpret_cast<void*>(0));
	glEnableVertexAttribArray(0);
	// TODO. color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, static_cast<GLsizei>(stride), reinterpret_cast<void*>(offset_color));
	glEnableVertexAttribArray(1);
	// TODO. texture attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, static_cast<GLsizei>(stride), reinterpret_cast<void*>(offset_tex));
	glEnableVertexAttribArray(2);
		
	glBindVertexArray(0);

	// TODO. wall texture
	glGenTextures(1, &m_t2d_wall);
	glBindTexture(GL_TEXTURE_2D, m_t2d_wall);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	auto& imgWall = *m_imgWall;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWall.width, imgWall.height, 0, GL_RGB, GL_UNSIGNED_BYTE, &imgWall.buffer[0]);
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
	m_pProgram->wglUniformInt("u_t2d_wall", 0);
	m_pProgram->wglUniformInt("u_t2d_awesome", 1);
	m_pProgram->wglUnbind();
}

void CTexturesRender::wglDraw()
{
	m_pProgram->wglBind();

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_t2d_wall);
	glActiveTexture(GL_TEXTURE0 + 1); // TODO. GL_TEXTURE1
	glBindTexture(GL_TEXTURE_2D, m_t2d_awesome);

	glBindVertexArray(m_vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	m_pProgram->wglUnbind();
}
