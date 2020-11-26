// JQRXJ.h : main header file for the JQRXJ application
//

#if !defined(AFX_JQRXJ_H__84CD2E7D_4A07_4858_B28C_637A9B1676B3__INCLUDED_)
#define AFX_JQRXJ_H__84CD2E7D_4A07_4858_B28C_637A9B1676B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CJQRXJApp:
// See JQRXJ.cpp for the implementation of this class
//

class CJQRXJApp : public CWinApp
{
public:
	CJQRXJApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJQRXJApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CJQRXJApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JQRXJ_H__84CD2E7D_4A07_4858_B28C_637A9B1676B3__INCLUDED_)
