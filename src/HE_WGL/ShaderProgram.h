#pragma once

#include "ShaderDefine.h"

class AFX_EXT_CLASS CShaderProgram
{
public:
	CShaderProgram();
	virtual ~CShaderProgram();

public:
	void wglCreate();
	void wglDelete();
	void wglAttach(GLenum shader_type, UINT res_id);
	void wglLink();

	void wglBind();
	void wglUnbind();

	BOOL wglUniformInt(const GLchar* aName, int nData);
	BOOL wglUniformBoolean(const GLchar* aName, bool bData);
	BOOL wglUniformFloat(const GLchar* aName, float fData);
	BOOL wglUniformDouble(const GLchar* aName, double dData);
	BOOL wglUniformVector3(const GLchar* aName, glm::vec3& vec3);
	BOOL wglUniformMatrix4(const GLchar* aName, glm::mat4& mat4);

private:
	GLuint m_program = 0;
	std::vector<GLuint> m_shaders;

};

