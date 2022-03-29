#pragma once

#include "RenderFactory.h"

class CImageFile;
class CShaderProgram;
class CLearnOpenGLRender : public IRender
{
protected:
	CString GetImagePath(CString file_name);

};

