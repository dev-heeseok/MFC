#pragma once

#include <string>

namespace lib
{
	AFX_API_EXPORT std::string ToStr(const std::wstring& wstr, int codepage = CP_ACP) noexcept
	{
		return std::string(CT2CA(wstr.c_str(), codepage));
	}

	AFX_API_EXPORT std::wstring ToWStr(const std::string& str, int codepage = CP_ACP) noexcept
	{
		return std::wstring(CA2CT(str.c_str(), codepage));
	}
}