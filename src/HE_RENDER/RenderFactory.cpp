#include "pch.h"
#include "RenderFactory.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CRenderFactory& CRenderFactory::GetInstance()
{
	static CRenderFactory instance;
	return instance;
}

CRenderFactory::CRenderFactory()
{
}

CRenderFactory::~CRenderFactory()
{
}

BOOL CRenderFactory::Register(RenderType index, CRuntimeClass* pRuntime)
{
	auto it = m_mMember.find(index);
	if (it != m_mMember.cend())
	{
		ASSERT(FALSE);
		return FALSE;
	}

	m_mMember.insert({ index, pRuntime });

	return TRUE;
}

void CRenderFactory::Unregister(RenderType index)
{
	auto it = m_mMember.find(index);
	if (it == m_mMember.cend())
	{
		ASSERT(FALSE);
		return;
	}

	m_mMember.erase(it);
}
