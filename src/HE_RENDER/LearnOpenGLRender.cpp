#include "pch.h"
#include "LearnOpenGLRender.h"

#include "../HE_LIB/HELib.h"

#include <filesystem>

using namespace lib;
namespace fs = std::filesystem;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString CLearnOpenGLRender::GetImagePath(CString file_name)
{
	CString strFilePath = GetModuleFilePath();
	CString strTrgFilePath = strFilePath + _T("\\image");
	CString strSrcFilePath = strFilePath + _T("\\..\\..\\..\\..\\file\\LearnOpenGL");

	CString strSrcPath = strSrcFilePath + _T("\\") + file_name;
	CString strTrgPath = strTrgFilePath + _T("\\") + file_name;
	std::string src_path = ToStr(strSrcPath.GetBuffer());
	std::string trg_path = ToStr(strTrgPath.GetBuffer());
	std::string trg_dir = ToStr(strTrgFilePath.GetBuffer());

	if (fs::exists(trg_path) == false)
	{
		if (fs::exists(trg_dir) == false)
			fs::create_directory(trg_dir);

		if (fs::exists(src_path))
			fs::copy_file(src_path, trg_path);
	}

	ASSERT(fs::exists(trg_path));
    return strTrgPath;
}
