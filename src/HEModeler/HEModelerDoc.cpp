// 이 MFC 샘플 소스 코드는 MFC Microsoft Office Fluent 사용자 인터페이스("Fluent UI")를
// 사용하는 방법을 보여 주며, MFC C++ 라이브러리 소프트웨어에 포함된
// Microsoft Foundation Classes Reference 및 관련 전자 문서에 대해
// 추가적으로 제공되는 내용입니다.
// Fluent UI를 복사, 사용 또는 배포하는 데 대한 사용 약관은 별도로 제공됩니다.
// Fluent UI 라이선싱 프로그램에 대한 자세한 내용은
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// HEModelerDoc.cpp: CHEModelerDoc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "HEModeler.h"
#endif

#include "HEModelerDoc.h"
#include "HEModelerView.h"
#include "MainFrm.h"

#include <propkey.h>

#include "../HE_INTERFACE/NotifyDefine.h"
#include "../HEM_UI/UIDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHEModelerDoc

IMPLEMENT_DYNCREATE(CHEModelerDoc, CHEDocBase)

BEGIN_MESSAGE_MAP(CHEModelerDoc, CHEDocBase)

#define ON_COMMAND_CATEGORY_DEV(id, func) ON_COMMAND_RANGE(id, id, func)
	ON_COMMAND_CATEGORY_DEV(ID_RIBBON_DEVELOP_BTN, OnCategoryDev)
	ON_COMMAND_CATEGORY_DEV(ID_RIBBON_TUTORIAL_BTN, OnCategoryDev)

#define ON_UPDATE_CATEGORY_DEV(id, func) ON_UPDATE_COMMAND_UI_RANGE(id, id, func)
	ON_UPDATE_CATEGORY_DEV(ID_RIBBON_DEVELOP_BTN, OnUpdateCategoryDev)
	ON_UPDATE_CATEGORY_DEV(ID_RIBBON_TUTORIAL_BTN, OnUpdateCategoryDev)

END_MESSAGE_MAP()


// CHEModelerDoc 생성/소멸

CHEModelerDoc::CHEModelerDoc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CHEModelerDoc::~CHEModelerDoc()
{
}

BOOL CHEModelerDoc::OnNewDocument()
{
	if (!CHEDocBase::OnNewDocument())
		return FALSE;

	InitScene();

	return TRUE;
}

BOOL CHEModelerDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CHEDocBase::OnOpenDocument(lpszPathName))
		return FALSE;

	InitScene();

	return TRUE;
}

void CHEModelerDoc::OnCloseDocument()
{
	UpdateAllViews(nullptr, static_cast<WPARAM>(NotifyType::closed_document), NULL);

	CHEDocBase::OnCloseDocument();
}


// CHEModelerDoc serialization

void CHEModelerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CHEModelerDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CHEModelerDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CHEModelerDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl* pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

#ifdef _DEBUG
void CHEModelerDoc::AssertValid() const
{
	CHEDocBase::AssertValid();
}

void CHEModelerDoc::Dump(CDumpContext& dc) const
{
	CHEDocBase::Dump(dc);
}
#endif //_DEBUG

int CHEModelerDoc::GetViewCount()
{
	auto count = 0;
	auto pos = GetFirstViewPosition();
	while (pos)
	{
		auto pView = GetNextView(pos);
		if (pView && IsWindow(pView->GetSafeHwnd()))
			count++;
	}

	return count;
}

void CHEModelerDoc::InitScene()
{
	auto pos = GetFirstViewPosition();
	while (pos)
	{
		auto pView = GetNextView(pos);
		if (pView == nullptr || IsWindow(pView->GetSafeHwnd()) == FALSE)
			continue;

		auto pHEModelerView = static_cast<CHEModelerView*>(pView);
		pHEModelerView->InitScene();
	}
}

void CHEModelerDoc::OnCategoryDev(UINT nID)
{
	switch (nID)
	{
	case ID_RIBBON_DEVELOP_BTN:
	{
		CUIDialog::DoModeless(this, _T("CUIDevelopDlg"));
	}
	break;
	case ID_RIBBON_TUTORIAL_BTN:
	{
		CUIDialog::DoModeless(this, _T("CUITutorialDlg"));
	}
	break;
	default:
	{
		ASSERT(FALSE);
	}
	break;
	}
}

void CHEModelerDoc::OnUpdateCategoryDev(CCmdUI* pCmdUI)
{
	switch (pCmdUI->m_nID)
	{
	case ID_RIBBON_DEVELOP_BTN:
	case ID_RIBBON_TUTORIAL_BTN:
	{
		pCmdUI->Enable(TRUE);
	}
	break;
	default:
	{
		pCmdUI->Enable(FALSE);
	}
	break;
	}

}
