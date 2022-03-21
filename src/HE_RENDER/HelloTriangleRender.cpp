#include "pch.h"
#include "HelloTriangleRender.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC_RENDER_GROUP(CHelloTriangleRender, RenderType::HelloTriangle, RenderGroup::learn_opengl)

CHelloTriangleRender::CHelloTriangleRender()
{
}

CHelloTriangleRender::~CHelloTriangleRender()
{
}

void CHelloTriangleRender::WGLDraw()
{

}

void CHelloTriangleRender::WGLBuild()
{
}

void CHelloTriangleRender::WGLRelease()
{
}
