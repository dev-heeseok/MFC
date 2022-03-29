#pragma once

#include <string>

#ifndef DEF_LIB
#define DEF_LIB

namespace lib
{
	template <typename E>
	constexpr std::underlying_type_t<E> EnumIndex(E enumerator) noexcept
	{
		return static_cast<std::underlying_type_t<E>>(enumerator);
	}

	inline std::string ToStr(const std::wstring& wstr, int codepage = CP_ACP) noexcept
	{
		return std::string(CT2CA(wstr.c_str(), codepage));
	}

	inline std::wstring ToWStr(const std::string& str, int codepage = CP_ACP) noexcept
	{
		return std::wstring(CA2CT(str.c_str(), codepage));
	}

	inline CString GetModuleFilePath() noexcept
	{
		TCHAR szModuleFileName[MAX_PATH] = _T("");
		::GetModuleFileName(0, szModuleFileName, MAX_PATH);
		
		CString strFilePath = _T("");
		CString strModuleFileName = szModuleFileName;

		int slash = strModuleFileName.ReverseFind('/');
		int backslash = strModuleFileName.ReverseFind('\\');
		if (slash != -1 || backslash != -1)
		{
			int item = backslash < slash ? slash : backslash;
			strFilePath = strModuleFileName.Left(item);
		}

		return strFilePath;
	}
}

#endif // !DEF_LIB