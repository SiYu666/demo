// JQRXJView.h : interface of the CJQRXJView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_JQRXJVIEW_H__0786C04E_29B8_445B_994D_AECD5837A792__INCLUDED_)
#define AFX_JQRXJVIEW_H__0786C04E_29B8_445B_994D_AECD5837A792__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ChangJing.h"
#include "Car.h"
#include  "WuRenJi.h"
#include "XieLou.h"

enum BiaoJi{CJKZ,CarZNDN,CarALX,CarYSDMBD,WRJZNDN,WRJALX,WRJYSDMBD,LIZI};
class CJQRXJView : public CView
{
protected: // create from serialization only
	CJQRXJView();
	DECLARE_DYNCREATE(CJQRXJView)

// Attributes
public:
	CJQRXJDoc* GetDocument();
	CChangJing m_CJ;
	CCar m_Car;
	CXieLou m_XL;


	CWuRenJi m_WRJ;
	CPoint m_LB;
	CPoint m_LinShi;
	int m_flag;
	int m_BJ;

	CString m_NDstr;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJQRXJView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CJQRXJView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CJQRXJView)
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMCarDianMove();
	afx_msg void OnMCarLuXianMove();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMCaryunSuDaoMuBiaoDian();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMWRJDianMove();
	afx_msg void OnMWRJLuXianMove();
	afx_msg void OnMWRJYunSu();
	afx_msg void OnMMeiQistart();
	afx_msg void OnMMeiQiZaiTing();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in JQRXJView.cpp
inline CJQRXJDoc* CJQRXJView::GetDocument()
   { return (CJQRXJDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JQRXJVIEW_H__0786C04E_29B8_445B_994D_AECD5837A792__INCLUDED_)
