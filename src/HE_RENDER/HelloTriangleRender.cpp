#include "pch.h"
#include "HelloTriangleRender.h"
#include "RenderEngine.h"

#include "../HE_WGL/ShaderDefine.h"
#include "../HE_WGL/ShaderManager.h"
#include "../HE_WGL/ShaderProgram.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC_RENDER_GROUP(CHelloTriangleRender, RenderType::tutorial_HelloTriangle, RenderGroup::learn_opengl)

CHelloTriangleRender::CHelloTriangleRender()
{
}

CHelloTriangleRender::~CHelloTriangleRender()
{
}

void CHelloTriangleRender::wglInitialUpdate(IRenderEngine* pRenderEngine)
{
	auto pRenderEngineImpl = static_cast<CRenderEngine*>(pRenderEngine);
	auto pShaderManager = pRenderEngineImpl->GetShaderManager();

	m_pProgram = pShaderManager->wglGetShaderProgram(ProgramType::tutorial_2_1_triangle);
}

void CHelloTriangleRender::wglRelease()
{
	if (m_VAO)
		glDeleteVertexArrays(1, &m_VAO);
	if (m_VBO)
		glDeleteBuffers(1, &m_VBO);

	m_VAO = m_VBO = 0;
}

void CHelloTriangleRender::wglBuild()
{
	float vertices[] = {
	  -0.5f, -0.5f, 0.0f, // left  
	   0.5f, -0.5f, 0.0f, // right 
	   0.0f,  0.5f, 0.0f  // top   
	};

	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);

	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLsizei stride = sizeof(float) * 3;
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void CHelloTriangleRender::wglDraw()
{
	m_pProgram->wglBind();

	glBindVertexArray(m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	m_pProgram->wglUnbind();
}
