#include "pch.h"
#include "resource.h"
#include "ShaderManager.h"
#include "Shader.h"

#include "../HE_LIB/HELib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace lib;

CShaderManager::CShaderManager()
{
}

CShaderManager::~CShaderManager()
{
}

void CShaderManager::WGLClearAll()
{
	for (auto [_, pShader] : m_mShader)
		pShader->WGLDelete();
}

void CShaderManager::WGLBuildAll()
{
	constexpr auto idxBegin = EnumIndex(ShaderType::begin_shader);
	constexpr auto idxEnd = EnumIndex(ShaderType::end_shader);

	for (auto idx = idxBegin; idx < idxEnd; ++idx)
		WGLBuild(static_cast<ShaderType>(idx));
}

void CShaderManager::WGLBuild(ShaderType type)
{
	if (m_mShader.find(type) != m_mShader.cend())
	{
		ASSERT(FALSE);
		return;
	}

	auto pShader = std::make_shared<CShader>();
	
	pShader->WGLCreate();

	switch (type)
	{
	case ShaderType::scene:
	{
		pShader->WGLAttach(GL_VERTEX_SHADER, IDR_SCENE_VERT);
		pShader->WGLAttach(GL_FRAGMENT_SHADER, IDR_SCENE_FRAG);
	}
	break;
	default:
	{
		ASSERT(FALSE);
	}
	break;
	}

	pShader->WGLLink();

	if (pShader != nullptr)
		m_mShader.insert({ type, pShader });
} 