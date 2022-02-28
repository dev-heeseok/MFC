#pragma once

#include <typeindex>
#include <functional>
#include <unordered_map>

#include "../HE_WGL/IRender.h"

class AFX_EXT_CLASS CHEMRenderFactory
{
public:
	static CHEMRenderFactory& GetInstance();

public:
	CHEMRenderFactory();
	~CHEMRenderFactory();

public:
	BOOL Register(std::type_index index, CRuntimeClass* pRuntime);
	void Unregister(std::type_index index);

	template <typename T>
	void Create(std::function<void(std::type_index, T*)> callback)
	{
		for (auto [index, maker] : m_mMember)
		{
			auto pObject = static_cast<T*>(maker->CreateObject());
			callback(index, pObject);
		}
	}

private:
	std::unordered_map<std::type_index, CRuntimeClass*> m_mMember;

};

#define DECLARE_DYNAMIC_RENDER(class_name)\
DECLARE_DYNCREATE(class_name);

#define IMPLEMENT_DYNAMIC_RENDER(class_name, base_class_name)\
IMPLEMENT_DYNCREATE(class_name, base_class_name);\
BOOL b##class_name = CHEMRenderFactory::GetInstance().Register(std::type_index(typeid(class_name)), RUNTIME_CLASS(class_name));