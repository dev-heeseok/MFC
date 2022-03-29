#pragma once

#include "LearnOpenGLRender.h"

class AFX_EXT_CLASS CTexturesRender : public CLearnOpenGLRender
{
	DECLARE_DYNAMIC_RENDER(CTexturesRender)

public:
	CTexturesRender();
	virtual ~CTexturesRender();

private:
	virtual void wglInitialUpdate(IRenderEngine* pRenderEngine) override;
	virtual void wglRelease() override;
	virtual void wglBuild() override;
	virtual void wglDraw() override;

private:
	std::shared_ptr<CImageFile> m_imgWall;
	std::shared_ptr<CImageFile> m_imgAwesome;

	CShaderProgram* m_pProgram = nullptr;
	GLuint m_vbo = 0;
	GLuint m_vao = 0;
	GLuint m_ebo = 0;
	GLuint m_t2d_wall = 0;
	GLuint m_t2d_awesome = 0;
};

