#include "pch.h"
#include "resource.h"
#include "ShaderManager.h"
#include "ShaderProgram.h"

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
	wglDeleteProgramAll();
}

CShaderProgram* CShaderManager::wglGetShaderProgram(ProgramType type)
{
	auto it = m_mShader.find(type);
	if (it == m_mShader.end())
	{
		auto pShader = wglCreateProgram(type);
		it = m_mShader.insert({ type, pShader }).first;
	}

	return it->second.get();
}

void CShaderManager::wglCreateProgramAll()
{
	constexpr auto idxBegin = EnumIndex(ProgramType::begin_iterate);
	constexpr auto idxEnd = EnumIndex(ProgramType::end_iterate);

	for (auto idx = idxBegin; idx < idxEnd; ++idx)
		wglCreateProgram(static_cast<ProgramType>(idx));
}

void CShaderManager::wglDeleteProgramAll()
{
	for (auto [_, pShader] : m_mShader)
		pShader->wglDelete();
}

std::shared_ptr<CShaderProgram> CShaderManager::wglCreateProgram(ProgramType type)
{
	auto pShader = std::make_shared<CShaderProgram>();

	pShader->wglCreate();

	switch (type)
	{
	case ProgramType::scene:
	{
		pShader->wglAttach(GL_VERTEX_SHADER, IDR_SCENE_VERT);
		pShader->wglAttach(GL_FRAGMENT_SHADER, IDR_SCENE_FRAG);
	}
	break;
	case ProgramType::tutorial_2_1_triangle:
	{
		pShader->wglAttach(GL_VERTEX_SHADER, IDR_TUTORIAL_2_1_TRIANGLE_VERT);
		pShader->wglAttach(GL_FRAGMENT_SHADER, IDR_TUTORIAL_2_1_TRIANGLE_FRAG);
	}
	break;
	case ProgramType::tutorial_3_3_shaders:
	{
		pShader->wglAttach(GL_VERTEX_SHADER, IDR_TUTORIAL_3_3_SHADERS_VERT);
		pShader->wglAttach(GL_FRAGMENT_SHADER, IDR_TUTORIAL_3_3_SHADERS_FRAG);
	}
	break;
	case ProgramType::tutorial_4_2_textures:
	{
		pShader->wglAttach(GL_VERTEX_SHADER, IDR_TUTORIAL_4_2_TEXTURES_VERT);
		pShader->wglAttach(GL_FRAGMENT_SHADER, IDR_TUTORIAL_4_2_TEXTURES_FRAG);
	}
	break;
	case ProgramType::tutorial_5_1_transform:
	{
		pShader->wglAttach(GL_VERTEX_SHADER, IDR_TUTORIAL_5_1_TRANSFORM_VERT);
		pShader->wglAttach(GL_FRAGMENT_SHADER, IDR_TUTORIAL_5_1_TRANSFORM_FRAG);
	}
	break;
	default:
	{
		ASSERT(FALSE);
	}
	break;
	}

	pShader->wglLink();

	return pShader;
}