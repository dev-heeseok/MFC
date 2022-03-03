#include "pch.h"
#include "Shader.h"

#include <memory>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CShader::CShader()
{
}

CShader::~CShader()
{
}

void CShader::WGLCreate()
{
	m_program = glCreateProgram();
}

void CShader::WGLDelete()
{
	if (m_program == 0)
		return;

	glDeleteProgram(m_program);
	m_program = 0;
}

void CShader::WGLAttachShader(GLenum shader_type, UINT res_id)
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

		if (res_compile == 0)
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

void CShader::WGLLinkShader()
{
	auto lambda_status = [](GLuint id, GLenum ptype)
	{
		GLint res_link = 0;
		glGetProgramiv(id, ptype, &res_link);
		if (res_link == 0)
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
