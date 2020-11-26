// WuRenJi.cpp: implementation of the CWuRenJi class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "JQRXJ.h"
#include "WuRenJi.h"
#include "math.h"
#define PI 3.1415926
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWuRenJi::CWuRenJi()
{
	m_x = -20;
	m_y = 53;
	m_r = 20;
}

CWuRenJi::~CWuRenJi()
{

}

void CWuRenJi::DrawWaiXing(CDC *p)
{
	pDC = p;
	int x,y,r,l1,l2;
	l1=50;
	l2=14;
	x = m_YD.x + m_x*m_kx;
	y = m_YD.y + m_y*m_ky;
	r = m_r*m_kx;
	CBrush brush,*pOldBrush;
	brush.CreateSolidBrush(RGB(200,0,0));
	pOldBrush =pDC->SelectObject(&brush);
	pDC->Ellipse(x-r,y-r,x+r,y+r);
	brush.DeleteObject();
	pDC->SelectObject(pOldBrush);

	CPen pen(PS_SOLID,1,RGB(255,0,0));
	CPen *pOldPen=pDC->SelectObject(&pen);

//	
	x = m_YD.x + m_x*m_kx;
	y = m_YD.y + m_y*m_ky;
	pDC->MoveTo(x,y);
	x = m_YD.x + (m_x-l1)*m_kx;
	pDC->LineTo(x,y);

	pDC->MoveTo(x,y);
	x -= sin(PI/4)*l2*m_kx;
	y += l2*cos(PI/4)*m_ky;
	pDC->LineTo(x,y);

	x = m_YD.x + (m_x-l1)*m_kx;
	y = m_YD.y + m_y*m_ky;
	pDC->MoveTo(x,y);
	x -= sin(PI/4)*l2*m_kx;
	y -= l2*cos(PI/4)*m_ky;
	pDC->LineTo(x,y);

	x = m_YD.x + (m_x-l1)*m_kx;
	y = m_YD.y + m_y*m_ky;
	pDC->MoveTo(x,y);
	x += sin(PI/4)*l2*m_kx;
	y -= l2*cos(PI/4)*m_ky;
	pDC->LineTo(x,y);

	x = m_YD.x + (m_x-l1)*m_kx;
	y = m_YD.y + m_y*m_ky;
	pDC->MoveTo(x,y);
	x += sin(PI/4)*l2*m_kx;
	y += l2*cos(PI/4)*m_ky;
	pDC->LineTo(x,y);
//

	x = m_YD.x + m_x*m_kx;
	y = m_YD.y + m_y*m_ky;
	pDC->MoveTo(x,y);
	x = m_YD.x + (m_x+l1)*m_kx;
	pDC->LineTo(x,y);
	pDC->MoveTo(x,y);
	x -= sin(PI/4)*l2*m_kx;
	y += l2*cos(PI/4)*m_ky;
	pDC->LineTo(x,y);

	x = m_YD.x + (m_x+l1)*m_kx;
	y = m_YD.y + m_y*m_ky;
	pDC->MoveTo(x,y);
	x -= sin(PI/4)*l2*m_kx;
	y -= l2*cos(PI/4)*m_ky;
	pDC->LineTo(x,y);

	x = m_YD.x + (m_x+l1)*m_kx;
	y = m_YD.y + m_y*m_ky;
	pDC->MoveTo(x,y);
	x += sin(PI/4)*l2*m_kx;
	y -= l2*cos(PI/4)*m_ky;
	pDC->LineTo(x,y);

	x = m_YD.x + (m_x+l1)*m_kx;
	y = m_YD.y + m_y*m_ky;
	pDC->MoveTo(x,y);
	x += sin(PI/4)*l2*m_kx;
	y += l2*cos(PI/4)*m_ky;
	pDC->LineTo(x,y);
//
	x = m_YD.x + m_x*m_kx;
	y = m_YD.y + m_y*m_ky;
	pDC->MoveTo(x,y);
	y = m_YD.y + (m_y-l1)*m_ky;
	pDC->LineTo(x,y);
	pDC->MoveTo(x,y);
	x -= sin(PI/4)*l2*m_kx;
	y += l2*cos(PI/4)*m_ky;
	pDC->LineTo(x,y);

	x = m_YD.x + m_x*m_kx;
	y = m_YD.y + (m_y-l1)*m_ky;
	pDC->MoveTo(x,y);
	x -= sin(PI/4)*l2*m_kx;
	y -= l2*cos(PI/4)*m_ky;
	pDC->LineTo(x,y);

	x = m_YD.x + m_x*m_kx;
	y = m_YD.y + (m_y-l1)*m_ky;
	pDC->MoveTo(x,y);
	x += sin(PI/4)*l2*m_kx;
	y -= l2*cos(PI/4)*m_ky;
	pDC->LineTo(x,y);

	x = m_YD.x + m_x*m_kx;
	y = m_YD.y + (m_y-l1)*m_ky;
	pDC->MoveTo(x,y);
	x += sin(PI/4)*l2*m_kx;
	y += l2*cos(PI/4)*m_ky;
	pDC->LineTo(x,y);
//
	x = m_YD.x + m_x*m_kx;
	y = m_YD.y + m_y*m_ky;
	pDC->MoveTo(x,y);
	y = m_YD.y + (m_y+l1)*m_ky;
	pDC->LineTo(x,y);
		pDC->MoveTo(x,y);
	y = m_YD.y + (m_y+l1)*m_ky;
	pDC->LineTo(x,y);
	pDC->MoveTo(x,y);
	x -= sin(PI/4)*l2*m_kx;
	y += l2*cos(PI/4)*m_ky;
	pDC->LineTo(x,y);

	x = m_YD.x + m_x*m_kx;
	y = m_YD.y + (m_y+l1)*m_ky;
	pDC->MoveTo(x,y);
	x -= sin(PI/4)*l2*m_kx;
	y -= l2*cos(PI/4)*m_ky;
	pDC->LineTo(x,y);

	x = m_YD.x + m_x*m_kx;
	y = m_YD.y + (m_y+l1)*m_ky;
	pDC->MoveTo(x,y);
	x += sin(PI/4)*l2*m_kx;
	y -= l2*cos(PI/4)*m_ky;
	pDC->LineTo(x,y);

	x = m_YD.x + m_x*m_kx;
	y = m_YD.y + (m_y+l1)*m_ky;
	pDC->MoveTo(x,y);
	x += sin(PI/4)*l2*m_kx;
	y += l2*cos(PI/4)*m_ky;
	pDC->LineTo(x,y);
	pDC->SelectObject(pOldPen);

}
