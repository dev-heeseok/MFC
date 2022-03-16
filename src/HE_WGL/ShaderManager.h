#pragma once

#include <unordered_map>

enum class ShaderType;

class CShader;
class CShaderManager
{
	using SHADER_MAP = std::unordered_map<ShaderType, std::shared_ptr<CShader>>;

public:
	CShaderManager();
	virtual ~CShaderManager();

public:
	void WGLClearAll();
	void WGLBuildAll();
	void WGLBuild(ShaderType type);

private:
	SHADER_MAP m_mShader;
};

