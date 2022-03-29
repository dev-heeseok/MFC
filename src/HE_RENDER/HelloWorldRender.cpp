#include "pch.h"
#include "HelloWorldRender.h"
#include "RenderEngine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC_RENDER_GROUP(CHelloWorldRender, RenderType::Tutorial_HelloWorld, RenderGroup::learn_opengl)

CHelloWorldRender::CHelloWorldRender()
{
}

CHelloWorldRender::~CHelloWorldRender()
{
}

void CHelloWorldRender::wglDraw()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);

}