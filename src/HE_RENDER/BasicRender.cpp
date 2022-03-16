#include "pch.h"
#include "BasicRender.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC_RENDER(CBasicRender, RenderType::Basic)

CBasicRender::CBasicRender()
{
}

CBasicRender::~CBasicRender()
{
}

void CBasicRender::WGLDraw()
{
}

void CBasicRender::WGLBuild()
{
}

void CBasicRender::WGLRelease()
{
}
