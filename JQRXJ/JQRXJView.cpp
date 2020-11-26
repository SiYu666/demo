// JQRXJView.cpp : implementation of the CJQRXJView class
//

#include "stdafx.h"
#include "JQRXJ.h"

#include "JQRXJDoc.h"
#include "JQRXJView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "ChangJing.h"
#include "Car.h"
#include "WuRenJi.h"
#include "XieLou.h"
/////////////////////////////////////////////////////////////////////////////
// CJQRXJView

IMPLEMENT_DYNCREATE(CJQRXJView, CView)

BEGIN_MESSAGE_MAP(CJQRXJView, CView)
	//{{AFX_MSG_MAP(CJQRXJView)
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_M_Car_DianMove, OnMCarDianMove)
	ON_COMMAND(ID_M_Car_LuXianMove, OnMCarLuXianMove)
	ON_WM_TIMER()
	ON_COMMAND(ID_M_CaryunSuDaoMuBiaoDian, OnMCaryunSuDaoMuBiaoDian)
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_M_WRJ_DianMove, OnMWRJDianMove)
	ON_COMMAND(ID_M_WRJ_LuXianMove, OnMWRJLuXianMove)
	ON_COMMAND(ID_M_WRJ_YunSu, OnMWRJYunSu)
	ON_COMMAND(ID_M_MeiQistart, OnMMeiQistart)
	ON_COMMAND(ID_M_MeiQiZaiTing, OnMMeiQiZaiTing)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJQRXJView construction/destruction

CJQRXJView::CJQRXJView()
{
	// TODO: add construction code here
	m_flag = 0;
	m_BJ = CJKZ;
}

CJQRXJView::~CJQRXJView()
{
}

BOOL CJQRXJView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CJQRXJView drawing

void CJQRXJView::OnDraw(CDC* pDC)
{
	CJQRXJDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CDC MemDc;
	int width,height;
	CRect rect;
	CBitmap MemBitmap;
	GetWindowRect(&rect);
	width = rect.Width();
	height =rect.Height();
	MemDc.CreateCompatibleDC(NULL);
	MemBitmap.CreateCompatibleBitmap(pDC,width,height);
	CBitmap *pOldBit = MemDc.SelectObject(&MemBitmap);
	MemDc.FillSolidRect(0,0,width,height,RGB(255,255,255));
	MemDc.SetBkMode(TRANSPARENT);
	
	m_Car.DrawCar(&MemDc);
	m_WRJ.DrawWaiXing(&MemDc);
	m_XL.Draw(&MemDc);
	m_WRJ.DrawLuXian();
	m_CJ.Draw(&MemDc);
	pDC->BitBlt(0,0,width,height,&MemDc,0,0,SRCCOPY);
	MemBitmap.DeleteObject();
	MemDc.DeleteDC();

	pDC->TextOut(880,50,m_NDstr);
//	m_CJ.Draw(pDC);
//	m_Car.DrawCar(pDC);	
}

/////////////////////////////////////////////////////////////////////////////
// CJQRXJView printing

BOOL CJQRXJView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CJQRXJView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CJQRXJView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CJQRXJView diagnostics

#ifdef _DEBUG
void CJQRXJView::AssertValid() const
{
	CView::AssertValid();
}

void CJQRXJView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CJQRXJDoc* CJQRXJView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJQRXJDoc)));
	return (CJQRXJDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CJQRXJView message handlers

BOOL CJQRXJView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	if(zDelta>0)
	{
		m_CJ.m_kx *=1.1;
		m_CJ.m_ky *=1.1;
		m_Car.m_kx = m_CJ.m_kx;
		m_Car.m_ky = m_CJ.m_ky;
		m_WRJ.m_kx = m_CJ.m_kx;
		m_WRJ.m_ky = m_CJ.m_ky;
		m_XL.m_kx = m_CJ.m_kx;
		m_XL.m_ky = m_CJ.m_ky;

	}
	if(zDelta<0)
	{
		m_CJ.m_kx *= 0.9;
		m_CJ.m_ky *= 0.9;
		m_Car.m_kx = m_CJ.m_kx;
		m_Car.m_ky = m_CJ.m_ky;
		m_WRJ.m_kx = m_CJ.m_kx;
		m_WRJ.m_ky = m_CJ.m_ky;
		m_XL.m_kx = m_CJ.m_kx;
		m_XL.m_ky = m_CJ.m_ky;
	}
	Invalidate(true);
	
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}

void CJQRXJView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	/*int nd;
	nd = m_XL.NongDu(point);
	m_NDstr.Format("ÃºÆøÃÜ¶È £º%d",nd);*/

	m_LB = point;
	m_LinShi = m_CJ.m_YD;
	m_flag = 1;
	if(m_BJ == CarZNDN)
	{
		m_Car.DianMove(point);
		Invalidate(true);
	}
	if(m_BJ == CarYSDMBD)
	{
		m_Car.yunSuDaoMuBiaoDian(point);
	
		SetTimer(CarYSDMBD,100,NULL);
		Invalidate(true);
	}
	if(m_BJ == CarALX)
	{
		m_Car.AnLuXian_SheDing(point);
		Invalidate(true);
	}


	if(m_BJ == WRJZNDN)
	{
		m_WRJ.DianMove(point);
		Invalidate(true);
	}
	if(m_BJ == WRJYSDMBD)
	{
		m_WRJ.yunSuDaoMuBiaoDian(point);
	
		SetTimer(WRJYSDMBD,100,NULL);
		Invalidate(true);
	}
	if(m_BJ == WRJALX)
	{
		m_WRJ.AnLuXian_SheDing(point);
		Invalidate(true);
	}
	CView::OnLButtonDown(nFlags, point);

}

void CJQRXJView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_flag = 0;
	CView::OnLButtonUp(nFlags, point);
}

void CJQRXJView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_flag==1)
	{
		m_CJ.m_YD.x = m_LinShi.x + (point.x - m_LB.x);
		m_CJ.m_YD.y = m_LinShi.y + (point.y - m_LB.y);
		m_Car.m_YD = m_CJ.m_YD;
		m_WRJ.m_YD = m_CJ.m_YD;
		m_XL.m_YD = m_CJ.m_YD;

		Invalidate(true);
	}
	CView::OnMouseMove(nFlags, point);
}

void CJQRXJView::OnMCarDianMove() 
{
	// TODO: Add your command handler code here
	m_BJ = CarZNDN;
	KillTimer(CarYSDMBD);
	KillTimer(CarALX);

}

void CJQRXJView::OnMCarLuXianMove() 
{
	// TODO: Add your command handler code here
	m_BJ = CarALX;
	m_Car.m_nLX = 0;
	KillTimer(CarYSDMBD);
}

void CJQRXJView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent)
	{
	case CarYSDMBD:
		if(m_Car.Move(0.1))
			KillTimer(CarYSDMBD);
		break;
	case CarALX:
		if(m_Car.AnLuXian_Move(0.1))
			KillTimer(CarALX);
		break;
	case WRJYSDMBD:
		if(m_WRJ.Move(0.1))
			KillTimer(WRJYSDMBD);
		break;
	case WRJALX:
		if(m_WRJ.AnLuXian_Move(0.1))
			KillTimer(WRJALX);
		break;
	case LIZI:
		m_XL.Move(0.1);
		m_XL.CreateLiZi(0.1);
		break;
	}
	Invalidate(true);
	CView::OnTimer(nIDEvent);
	
}

void CJQRXJView::OnMCaryunSuDaoMuBiaoDian() 
{
	// TODO: Add your command handler code here
	m_BJ = CarYSDMBD;
	KillTimer(CarALX);
}

BOOL CJQRXJView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return true;
	return CView::OnEraseBkgnd(pDC);
}

void CJQRXJView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_BJ == CarALX)
	{
		SetTimer(CarALX,100,NULL);
		m_Car.m_nMBDLX = 0;
		m_BJ = CJKZ;
	}
	if(m_BJ == WRJALX)
	{
		SetTimer(WRJALX,100,NULL);
		m_WRJ.m_nMBDLX = 0;
		m_BJ = CJKZ;
	}
	CView::OnLButtonDblClk(nFlags, point);
}

void CJQRXJView::OnMWRJDianMove() 
{
	// TODO: Add your command handler code here
	m_BJ = WRJZNDN;
	KillTimer(WRJYSDMBD);
	KillTimer(WRJALX);
}

void CJQRXJView::OnMWRJLuXianMove() 
{
	// TODO: Add your command handler code here
	m_BJ = WRJALX;
	m_WRJ.m_nLX = 0;
	KillTimer(WRJYSDMBD);
}

void CJQRXJView::OnMWRJYunSu() 
{
	// TODO: Add your command handler code here
	m_BJ = WRJYSDMBD;
	KillTimer(WRJALX);
}

void CJQRXJView::OnMMeiQistart() 
{
	// TODO: Add your command handler code here
	SetTimer(LIZI,100,NULL);
}

void CJQRXJView::OnMMeiQiZaiTing() 
{
	// TODO: Add your command handler code here
	KillTimer(LIZI);
}
