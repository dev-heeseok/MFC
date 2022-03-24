#include "pch.h"
#include "WGLRenderContext.h"


const static PIXELFORMATDESCRIPTOR pfdLegecy =
{
	sizeof(PIXELFORMATDESCRIPTOR),
	1,
	PFD_DRAW_TO_WINDOW |            // Support window 
	PFD_SUPPORT_OPENGL |            // Support OpenGL double buffered RBGA surface
	PFD_SWAP_EXCHANGE |            // 
	PFD_DOUBLEBUFFER,               // _
	PFD_TYPE_RGBA,                  //  |  COLOR - Minimum 24bit RGB
	32,                             //  |  " Specifies the number of color bitplanes in each color buffer. 
	0, 0,                           //  +-   For RGBA pixel types, it is the size of the color buffer,
	0, 0,                           //  |    excluding the alpha bitplanes. " 
	0, 0,                           //  | ( http://msdn.microsoft.com/en-us/library/dd368826(v=vs.85).aspx )   
	0, 0,                           // -   So should be 24, but we set 32.
	0,                              // ACCUM     - off
	0, 0, 0, 0,                     // 
	24,                             // DEPTH     - 24bit Z-Buffer
	8,                              // STENCIL   - on
	0,                              // AUXILIARY - off
	PFD_MAIN_PLANE,                 // Main Drawing Layer - (obsolete iLayerType, equals 0)
	0,
	0, 0, 0
};

CWGLRenderContext::CWGLRenderContext(HDC hDC)
	: m_hDC(hDC)
	, m_hRC(0)
	, m_tPixelFormatDescriptor(pfdLegecy)
{
	ASSERT(m_hDC);
}

CWGLRenderContext::~CWGLRenderContext()
{
}

void CWGLRenderContext::wglBind()
{
	VERIFY(::wglMakeCurrent(m_hDC, m_hRC));
}

void CWGLRenderContext::wglUnbind()
{
	VERIFY(::wglMakeCurrent(m_hDC, NULL));
}

void CWGLRenderContext::wglSwapBuffer()
{
	::SwapBuffers(m_hDC);
}

void CWGLRenderContext::OnCreate()
{
	do
	{
		// Choose a pixel format that best matches that described in pfd
		int nPixelFormat = ChoosePixelFormat(m_hDC, &m_tPixelFormatDescriptor);

		// Describe pixel format
		DescribePixelFormat(m_hDC, nPixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &m_tPixelFormatDescriptor);

		// Set the pixel format for the device context
		VERIFY(SetPixelFormat(m_hDC, nPixelFormat, &m_tPixelFormatDescriptor));

		// Create the rendering context
		m_hRC = wglCreateContext(m_hDC);


		wglBind();
		{
			GLenum err = glewInit();
			if (GLEW_OK != err)
			{
				AfxMessageBox(_T("GLEW is not initialized!"));
				break;
			}
		}
		wglUnbind();

	} while (false);
}

void CWGLRenderContext::OnDestroy()
{
	wglDeleteContext(m_hRC);
}
