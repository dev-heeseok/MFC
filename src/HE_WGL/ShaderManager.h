#pragma once

#include <unordered_map>

enum class ShaderType;
class CShaderManager
{
public:
	CShaderManager();
	virtual ~CShaderManager();

public:
	void WGLRemoveAll();
	void WGLBuildAll();
	void WGLBuild(ShaderType type);

private:

};

