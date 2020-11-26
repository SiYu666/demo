// JQRXJDoc.cpp : implementation of the CJQRXJDoc class
//

#include "stdafx.h"
#include "JQRXJ.h"

#include "JQRXJDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJQRXJDoc

IMPLEMENT_DYNCREATE(CJQRXJDoc, CDocument)

BEGIN_MESSAGE_MAP(CJQRXJDoc, CDocument)
	//{{AFX_MSG_MAP(CJQRXJDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJQRXJDoc construction/destruction

CJQRXJDoc::CJQRXJDoc()
{
	// TODO: add one-time construction code here

}

CJQRXJDoc::~CJQRXJDoc()
{
}

BOOL CJQRXJDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CJQRXJDoc serialization

void CJQRXJDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CJQRXJDoc diagnostics

#ifdef _DEBUG
void CJQRXJDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CJQRXJDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CJQRXJDoc commands
