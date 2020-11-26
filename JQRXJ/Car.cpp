// Car.cpp: implementation of the CCar class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "JQRXJ.h"
#include "Car.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCar::CCar()
{
	m_x = 312;
	m_y = 53;
	m_v=0;
	m_vx = 0;
	m_vy = 0;
	m_l = 40;
	m_h = 20;
	m_r = 6;

	m_YD.x = 500;
	m_YD.y = 300;
	m_kx = 1000.0/1600;
	m_ky = -600.0/1000;
	m_MBDx=0;
	m_MBDy=0;
}

CCar::~CCar()
{

}

void CCar::DrawCar(CDC *p)
{
	
	pDC = p;
	DrawXingZhuang();
	DrawLuXian();
	

}

void CCar::DianMove(CPoint point)
{
	m_x = (point.x - m_YD.x)/m_kx;
	m_y = (point.y - m_YD.y)/m_ky;
}

void CCar::yunSuDaoMuBiaoDian(CPoint point)
{
	float d;
	m_v = 30;
	m_MBDx = (point.x - m_YD.x)/m_kx;
	m_MBDy = (point.y - m_YD.y)/m_ky;
	
	d = sqrt((m_x-m_MBDx)*(m_x-m_MBDx) +(m_y-m_MBDy)*(m_y-m_MBDy));
	m_vx = m_v*(m_MBDx - m_x)/d;
	m_vy = m_v*(m_MBDy - m_y)/d;
}

int CCar::Move(float deltat)
{
	float d;
	m_x += m_vx*deltat;
	m_y += m_vy*deltat;
	d = sqrt((m_x-m_MBDx)*(m_x-m_MBDx) +(m_y-m_MBDy)*(m_y-m_MBDy));
	if(d<3)
		return 1;
	else
		return 0;
}

void CCar::AnLuXian_SheDing(CPoint point)
{
	int i;
	float d;
	m_v = 30;
	m_LuXian[m_nLX][0] = (point.x - m_YD.x)/m_kx;
	m_LuXian[m_nLX][1] = (point.y - m_YD.y)/m_ky;
	m_nLX++;	
}

void CCar::DrawLuXian()
{
	int i,x,y;
	CPen pen(PS_SOLID,1,RGB(0,0,255));
	CPen *pOldPen=pDC->SelectObject(&pen);
	x = m_YD.x + m_LuXian[0][0]*m_kx;
	y = m_YD.y + m_LuXian[0][1]*m_ky;
	pDC->MoveTo(x,y);
	for(i=1;i<m_nLX;i++)
	{
		x = m_YD.x + m_LuXian[i][0]*m_kx;
		y = m_YD.y + m_LuXian[i][1]*m_ky;
		pDC->LineTo(x,y);
	}
	pDC->SelectObject(pOldPen);
}

int CCar::AnLuXian_Move(float deltat)
{
	float d1,d;
	int i;
	m_v = 30;
	m_MBDx = m_LuXian[m_nMBDLX][0];
	m_MBDy = m_LuXian[m_nMBDLX][1];
	
	d = sqrt((m_x-m_MBDx)*(m_x-m_MBDx) +(m_y-m_MBDy)*(m_y-m_MBDy));
	if(d<3)
	{
		m_nMBDLX++;
		if(m_nMBDLX==m_nLX)
		{
			m_nLX = 0;
			return 1;
		}
	}	
	else
	{
		m_vx = m_v*(m_MBDx - m_x)/d;
		m_vy = m_v*(m_MBDy - m_y)/d;
		Move(deltat);
	}
	return 0;
}

void CCar::DrawXingZhuang()
{
	int x,y,r,r1,r2;
	x = m_YD.x + m_x*m_kx;
	y = m_YD.y + m_y*m_ky;
	r1 = m_l/2*m_kx;
	r2 = m_h/2*m_kx;
	CBrush brush,*pOldBrush;
	brush.CreateSolidBrush(RGB(200,0,0));
	pOldBrush =pDC->SelectObject(&brush);
	pDC->Rectangle(x-r1,y-r2,x+r1,y+r2);
	brush.DeleteObject();
	pDC->SelectObject(pOldBrush);

	x = m_YD.x + (m_x - m_l/4)*m_kx;
	y = m_YD.y + (m_y - m_h/2 -m_r)*m_ky;
	r = m_r*m_kx;
	pDC->Ellipse(x-r,y-r,x+r,y+r);

	x = m_YD.x + (m_x+m_l/4)*m_kx;
	pDC->Ellipse(x-r,y-r,x+r,y+r);
}
