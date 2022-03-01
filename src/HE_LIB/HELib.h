#pragma once

#include <string>

namespace lib
{
	template <typename E>
	AFX_API_EXPORT constexpr std::underlying_type_t<E> EnumIndex(E enumerator) noexcept
	{
		return static_cast<std::underlying_type_t<E>>(enumerator);
	}

	AFX_API_EXPORT std::string ToStr(const std::wstring& wstr, int codepage = CP_ACP) noexcept
	{
		return std::string(CT2CA(wstr.c_str(), codepage));
	}

	AFX_API_EXPORT std::wstring ToWStr(const std::string& str, int codepage = CP_ACP) noexcept
	{
		return std::wstring(CA2CT(str.c_str(), codepage));
	}
}