#pragma once

#include <typeindex>
#include <functional>
#include <unordered_map>

#include "RenderDefine.h"

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
private: virtual RenderType GetType() override;

#define IMPLEMENT_DYNAMIC_RENDER(class_name, render_type)\
IMPLEMENT_DYNCREATE(class_name, IRender);\
RenderType class_name::GetType() { return render_type; }\
BOOL b##class_name = CRenderFactory::GetInstance().Register(render_type, RUNTIME_CLASS(class_name));
