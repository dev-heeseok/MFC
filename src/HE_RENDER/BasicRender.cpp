#include "pch.h"
#include "BasicRender.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC_RENDER_GROUP(CBasicRender, RenderType::Basic, RenderGroup::learn_opengl)

CBasicRender::CBasicRender()
{
}

CBasicRender::~CBasicRender()
{
}

void CBasicRender::wglDraw()
{
	glClearColor(0.5f, 0.3f, 0.3f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);
}