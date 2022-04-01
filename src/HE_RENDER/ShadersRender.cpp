#include "pch.h"
#include "ShadersRender.h"
#include "RenderEngine.h"

#include "../HE_WGL/ShaderDefine.h"
#include "../HE_WGL/ShaderManager.h"
#include "../HE_WGL/ShaderProgram.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC_RENDER_GROUP(CShadersRender, RenderType::tutorial_Shaders, RenderGroup::learn_opengl)

CShadersRender::CShadersRender()
{
}

CShadersRender::~CShadersRender()
{
}

void CShadersRender::wglInitialUpdate(IRenderEngine* pRenderEngine)
{
	auto pRenderEngineImpl = static_cast<CRenderEngine*>(pRenderEngine);
	auto pShaderManager = pRenderEngineImpl->GetShaderManager();

	m_pProgram = pShaderManager->wglGetShaderProgram(ProgramType::tutorial_3_3_shaders);
}

void CShadersRender::wglRelease()
{
	if (m_VAO)
		glDeleteVertexArrays(1, &m_VAO);
	if (m_VBO)
		glDeleteBuffers(1, &m_VBO);

	m_VAO = m_VBO = 0;
}

void CShadersRender::wglBuild()
{
	float vertices[] = {
		// 위치              // 컬러
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 우측 하단
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 좌측 하단
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 위 
	};

	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);

	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	size_t stride = sizeof(float) * 6;
	size_t offset = sizeof(float) * 3;
	// TODO. vertex attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, static_cast<GLsizei>(stride), reinterpret_cast<void*>(0));
	glEnableVertexAttribArray(0);
	// TODO. color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, static_cast<GLsizei>(stride), reinterpret_cast<void*>(offset));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void CShadersRender::wglDraw()
{
	m_pProgram->wglBind();

	glBindVertexArray(m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	m_pProgram->wglUnbind();
}
