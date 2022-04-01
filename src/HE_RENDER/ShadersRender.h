#pragma once

#include "LearnOpenGLRender.h"

class AFX_EXT_CLASS CShadersRender : public CLearnOpenGLRender
{
	DECLARE_DYNAMIC_RENDER(CShadersRender);

public:
	CShadersRender();
	virtual ~CShadersRender();

private:
	virtual void wglInitialUpdate(IRenderEngine* pRenderEngine) override;
	virtual void wglRelease() override;
	virtual void wglBuild() override;
	virtual void wglDraw() override;

private:
	CShaderProgram* m_pProgram = nullptr;
	GLuint m_VBO = 0;
	GLuint m_VAO = 0;
	GLuint m_EBO = 0;
};

