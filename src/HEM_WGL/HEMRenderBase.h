#pragma once

#include "HEMRenderFactory.h"

class AFX_EXT_CLASS CHEMRenderBase : public CObject
{
public:
	CHEMRenderBase();
	virtual ~CHEMRenderBase();

public:
	virtual void WGLDraw() = 0;
	virtual void WGLBuild() {};
	virtual void WGLRelease() {};

};


#define DECLARE_DYNAMIC_RENDER(class_name)\
DECLARE_DYNCREATE(class_name);\
BOOL b##class_name = CHEMRenderFactory::GetInstance().Register(std::type_index(typeid(class_name)), RUNTIME_CLASS(class_name));

#define IMPLEMENT_DYNAMIC_RENDER(class_name, base_class_name)\
IMPLEMENT_DYNCREATE(class_name, base_class_name);