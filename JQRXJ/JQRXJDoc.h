// JQRXJDoc.h : interface of the CJQRXJDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_JQRXJDOC_H__39F5BFB8_5B89_424A_B96A_36C6EB802C31__INCLUDED_)
#define AFX_JQRXJDOC_H__39F5BFB8_5B89_424A_B96A_36C6EB802C31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CJQRXJDoc : public CDocument
{
protected: // create from serialization only
	CJQRXJDoc();
	DECLARE_DYNCREATE(CJQRXJDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJQRXJDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CJQRXJDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CJQRXJDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JQRXJDOC_H__39F5BFB8_5B89_424A_B96A_36C6EB802C31__INCLUDED_)
