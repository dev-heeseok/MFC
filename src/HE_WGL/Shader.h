#pragma once

#include "ShaderDefine.h"

class CShader
{
public:
	CShader();
	virtual ~CShader();

public:
	void WGLCreate();
	void WGLDelete();

	void WGLAttach(GLenum shader_type, UINT res_id);
	void WGLLink();

	void WGLBind();
	void WGLUnbind();

	BOOL WGLSetInt(const GLchar* aName, int nData);
	BOOL WGLSetBoolean(const GLchar* aName, bool bData);
	BOOL WGLSetFloat(const GLchar* aName, float fData);
	BOOL WGLSetDouble(const GLchar* aName, double dData);
	BOOL WGLSetVector3(const GLchar* aName, glm::vec3& vec3);
	BOOL WGLSetMatrix4(const GLchar* aName, glm::mat4& mat4);

private:
	GLuint m_program = 0;
	std::vector<GLuint> m_shaders;

};

