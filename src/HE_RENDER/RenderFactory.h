#pragma once

#include <typeindex>
#include <functional>
#include <unordered_map>

#include "../HE_INTERFACE/RenderDefine.h"
#include "../HE_INTERFACE/IRender.h"

class AFX_EXT_CLASS CRenderFactory
{
public:
	static CRenderFactory& GetInstance();

public:
	CRenderFactory();
	~CRenderFactory();

public:
	BOOL Register(RenderType index, CRuntimeClass* pRuntime);
	void Unregister(RenderType index);

	template <typename T>
	void Create(std::function<void(RenderType, T*)> callback)
	{
		for (auto [index, maker] : m_mMember)
		{
			auto pObject = static_cast<T*>(maker->CreateObject());
			callback(index, pObject);
		}
	}

private:
	std::unordered_map<RenderType, CRuntimeClass*> m_mMember;

};

#define DECLARE_DYNAMIC_RENDER(class_name)\
DECLARE_DYNCREATE(class_name)\
virtual RenderType GetType() override;\
virtual RenderGroup GetGroup() override;

#define IMPLEMENT_DYNAMIC_RENDER_GROUP(class_name, render_type, render_group)\
IMPLEMENT_DYNCREATE(class_name, IRender);\
RenderType class_name::GetType() { return render_type; }\
RenderGroup class_name::GetGroup() { return render_group; }\
BOOL b##class_name = CRenderFactory::GetInstance().Register(render_type, RUNTIME_CLASS(class_name));

#define IMPLEMENT_DYNAMIC_RENDER(class_name, render_type)\
IMPLEMENT_DYNAMIC_RENDER_GROUP(class_name, render_type, RenderGroup::general)
