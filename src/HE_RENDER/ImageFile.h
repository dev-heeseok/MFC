#pragma once

class AFX_EXT_CLASS CImageFile
{
public:
	CImageFile(CString strFileName);
	~CImageFile();

public:
	CString file_name = _T("");

	int width = 0;
	int height = 0;
	int component = 0;
	std::vector<unsigned char> buffer;

};