#pragma once

#include <unordered_map>

enum class ProgramType;

class CShaderProgram;
class AFX_EXT_CLASS CShaderManager
{
	using SHADER_MAP = std::unordered_map<ProgramType, std::shared_ptr<CShaderProgram>>;

public:
	CShaderManager();
	virtual ~CShaderManager();

public:
	CShaderProgram* wglGetShaderProgram(ProgramType type);

	void wglCreateProgramAll();
	void wglDeleteProgramAll();

protected:
	std::shared_ptr<CShaderProgram> wglCreateProgram(ProgramType type);

private:
	SHADER_MAP m_mShader;
};

