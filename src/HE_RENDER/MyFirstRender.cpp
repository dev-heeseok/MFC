#include "pch.h"
#include "MyFirstRender.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC_RENDER(CMyFirstRender, IRender)

CMyFirstRender::CMyFirstRender()
{
}

CMyFirstRender::~CMyFirstRender()
{
}

void CMyFirstRender::WGLDraw()
{
	glClearColor(0.2f, 0.2f, 0.2f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);

}

void CMyFirstRender::WGLBuild()
{
}

void CMyFirstRender::WGLRelease()
{
}
