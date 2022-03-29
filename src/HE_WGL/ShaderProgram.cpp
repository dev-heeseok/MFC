#include "pch.h"
#include "ShaderProgram.h"

#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CShaderProgram::CShaderProgram()
{
}

CShaderProgram::~CShaderProgram()
{
}

void CShaderProgram::wglCreate()
{
	m_program = glCreateProgram();
}

void CShaderProgram::wglDelete()
{
	if (m_program == 0)
		return;

	glDeleteProgram(m_program);
	m_program = 0;
}

void CShaderProgram::wglAttach(GLenum shader_type, UINT res_id)
{
	auto lambda_source = [](UINT res_id, std::string& source)
	{
		auto hHandle = GetModuleHandle(_T("HE_WGL.dll"));
		auto hRes = FindResource(hHandle, MAKEINTRESOURCE(res_id), _T("GLSL"));
		if (hRes == nullptr)
			return FALSE;

		auto dwResSize = static_cast<int>(SizeofResource(hHandle, hRes));
		auto hResData = LoadResource(hHandle, hRes);
		if (dwResSize == 0 || hResData == nullptr)
			return FALSE;

		std::vector<GLchar> aBuffer(dwResSize);
		auto aResData = reinterpret_cast<const GLchar*>(LockResource(hResData));
		std::copy(aResData, aResData + dwResSize, &aBuffer[0]);
		aBuffer.push_back('\0');

		source.assign(aBuffer.begin(), aBuffer.end());

		UnlockResource(hResData);
		FreeResource(hResData);

		return TRUE;
	};

	auto lambda_status = [](GLuint shader, GLenum ptype)
	{
		GLint res_compile = 0;
		glGetShaderiv(shader, ptype, &res_compile);

		if (res_compile == GL_TRUE)
			return TRUE;

		GLint log_length = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_length);

		if (log_length > 0)
		{
			std::vector<GLchar> aBuffer(log_length);
			glGetShaderInfoLog(shader, log_length, &log_length, &aBuffer[0]);

			std::string log;
			log.assign(aBuffer.begin(), aBuffer.end());

			TRACE(log.c_str());
		}

		ASSERT(FALSE);
		return FALSE;
	};

	std::string source;
	lambda_source(res_id, source);

	auto pSource = source.c_str();

	auto shader = glCreateShader(shader_type);
	glShaderSource(shader, 1, &pSource, NULL);
	glCompileShader(shader);

	if (lambda_status(shader, GL_COMPILE_STATUS))
		glAttachShader(m_program, shader);

	m_shaders.push_back(shader);
}

void CShaderProgram::wglLink()
{
	auto lambda_status = [](GLuint id, GLenum ptype)
	{
		GLint res_link = 0;
		glGetProgramiv(id, ptype, &res_link);
		if (res_link == GL_TRUE)
			return TRUE;

		GLint log_length = 0;
		glGetProgramiv(id, GL_INFO_LOG_LENGTH, &log_length);

		if (log_length > 0)
		{
			std::vector<GLchar> aBuffer(log_length);
			glGetProgramInfoLog(id, log_length, &log_length, &aBuffer[0]);

			std::string log;
			log.assign(aBuffer.begin(), aBuffer.end());

			TRACE(log.c_str());
		}

		ASSERT(FALSE);
		return FALSE;
	};

	glLinkProgram(m_program);
	lambda_status(m_program, GL_LINK_STATUS);

	for (auto shader : m_shaders)
		glDeleteShader(shader);
}

void CShaderProgram::wglBind()
{
	ASSERT(m_program > 0);

	glUseProgram(m_program);
}

void CShaderProgram::wglUnbind()
{
	glUseProgram(0);
}

BOOL CShaderProgram::wglUniformInt(const GLchar* aName, int nData)
{
	auto location = glGetUniformLocation(m_program, aName);
	if (location == -1)
		return FALSE;

	glUniform1i(location, nData);

	return TRUE;
}

BOOL CShaderProgram::wglUniformBoolean(const GLchar* aName, bool bData)
{
	auto location = glGetUniformLocation(m_program, aName);
	if (location == -1)
		return FALSE;

	glUniform1i(location, bData);

	return TRUE;
}

BOOL CShaderProgram::wglUniformFloat(const GLchar* aName, float fData)
{
	auto location = glGetUniformLocation(m_program, aName);
	if (location == -1)
		return FALSE;

	glUniform1f(location, fData);

	return TRUE;
}

BOOL CShaderProgram::wglUniformDouble(const GLchar* aName, double dData)
{
	auto location = glGetUniformLocation(m_program, aName);
	if (location == -1)
		return FALSE;

	glUniform1d(location, dData);

	return TRUE;
}

BOOL CShaderProgram::wglUniformVector3(const GLchar* aName, glm::vec3& vec3)
{
	auto location = glGetUniformLocation(m_program, aName);
	if (location == -1)
		return FALSE;

	glUniform3fv(location, 1, glm::value_ptr(vec3));

	return TRUE;
}

BOOL CShaderProgram::wglUniformMatrix4(const GLchar* aName, glm::mat4& mat4)
{
	auto location = glGetUniformLocation(m_program, aName);
	if (location == -1)
		return FALSE;

	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat4));

	return TRUE;
}
