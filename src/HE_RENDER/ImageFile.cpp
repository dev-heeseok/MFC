#include "pch.h"
#include "ImageFile.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "../HE_LIB/HELib.h"

using namespace lib;

CImageFile::CImageFile(CString strFileName)
	: file_name(strFileName)
{
	std::string name = ToStr(strFileName.GetBuffer());

	stbi_set_flip_vertically_on_load(true);
	auto data = stbi_load(name.c_str(), &width, &height, &component, 0);
	if (data != nullptr)
	{
		auto size = width * height * component;
		buffer.resize(size);
		std::copy(data, data + size, &buffer[0]);

		stbi_image_free(data);
	}
	else
	{
		ASSERT(FALSE);
	}
}

CImageFile::~CImageFile()
{
}