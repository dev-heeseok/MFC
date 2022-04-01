#pragma once

#include "LearnOpenGLRender.h"

class AFX_EXT_CLASS CTransformationRender : public CLearnOpenGLRender
{
	DECLARE_DYNAMIC_RENDER(CTransformationRender);

public:
	CTransformationRender();
	virtual ~CTransformationRender();

private:
	virtual void wglInitialUpdate(IRenderEngine* pRenderEngine) override;
	virtual void wglRelease() override;
	virtual void wglBuild() override;
	virtual void wglDraw() override;

private:
	std::shared_ptr<CImageFile> m_imgContainer;
	std::shared_ptr<CImageFile> m_imgAwesome;

	CShaderProgram* m_pProgram = nullptr;
	GLuint m_VBO = 0;
	GLuint m_VAO = 0;
	GLuint m_EBO = 0;
	GLuint m_t2d_container = 0;
	GLuint m_t2d_awesome = 0;
};

