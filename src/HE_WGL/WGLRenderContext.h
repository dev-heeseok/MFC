#pragma once

class CWGLRenderContext
{
public:
	CWGLRenderContext(HDC hDC);
	virtual ~CWGLRenderContext();

public:
	void OnCreate();
	void OnDestroy();

	void WGLBind();
	void WGLUnbind();
	void SwapBuffer();

protected:
	HDC m_hDC = nullptr;
	HGLRC m_hRC = nullptr;
	
	PIXELFORMATDESCRIPTOR m_tPixelFormatDescriptor;

};

