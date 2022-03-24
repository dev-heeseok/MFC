#pragma once

#include "../HE_INTERFACE/IRenderContext.h"

class CWGLRenderContext : public IRenderContext
{
public:
	CWGLRenderContext(HDC hDC);
	virtual ~CWGLRenderContext();

public:
	virtual void wglBind() override;
	virtual void wglUnbind() override;
	virtual void wglSwapBuffer() override;

public:
	void OnCreate();
	void OnDestroy();

protected:
	HDC m_hDC = nullptr;
	HGLRC m_hRC = nullptr;
	
	PIXELFORMATDESCRIPTOR m_tPixelFormatDescriptor;

};

