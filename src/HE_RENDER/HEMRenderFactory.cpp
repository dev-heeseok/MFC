#include "pch.h"
#include "HEMRenderFactory.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CHEMRenderFactory& CHEMRenderFactory::GetInstance()
{
    static CHEMRenderFactory instance;
    return instance;
}

CHEMRenderFactory::CHEMRenderFactory()
{
}

CHEMRenderFactory::~CHEMRenderFactory()
{
}

BOOL CHEMRenderFactory::Register(std::type_index index, CRuntimeClass* pRuntime)
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

void CHEMRenderFactory::Unregister(std::type_index index)
{
    auto it = m_mMember.find(index);
    if (it == m_mMember.cend())
    {
        ASSERT(FALSE);
        return;
    }

    m_mMember.erase(it);
}
