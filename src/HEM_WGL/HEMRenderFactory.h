#pragma once

#include <typeindex>
#include <functional>
#include <unordered_map>

class CHEMRenderBase;
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

