#pragma once

#include <vector>

class CShader
{
public:
	CShader();
	virtual ~CShader();

public:
	void WGLCreate();
	void WGLDelete();

	void WGLAttachShader(GLenum shader_type, UINT res_id);
	void WGLLinkShader();

private:
	GLuint m_program = 0;
	std::vector<GLuint> m_shaders;

};

