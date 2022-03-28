#pragma once

#include "RenderFactory.h"

class CShaderProgram;
class AFX_EXT_CLASS CHelloTriangleRender : public IRender
{
	DECLARE_DYNAMIC_RENDER(CHelloTriangleRender)

public:
	CHelloTriangleRender();
	virtual ~CHelloTriangleRender();

private:
	virtual void wglInitialUpdate(IRenderEngine* pRenderEngine) override;
	virtual void wglRelease() override;
	virtual void wglBuild() override;
	virtual void wglDraw() override;

private:
	CShaderProgram* m_pProgram = nullptr;

	GLuint m_vbo = 0;
	GLuint m_vao = 0;
	GLuint m_ebo = 0;

};

