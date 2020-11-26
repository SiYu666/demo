// XieLou.cpp: implementation of the CXieLou class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "JQRXJ.h"
#include "XieLou.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CXieLou::CXieLou()
{
	m_x = 44;
	m_y = -81;
	m_nLZ = 0;
	m_YD.x = 500;
	m_YD.y = 300;
	m_kx = 1000.0/1600;
	m_ky = -600.0/1000;
}

CXieLou::~CXieLou()
{

}

void CXieLou::CreateLiZi(float deltat)
{
	int i;
	for(i=0;i<100;i++)
	{
		m_LZ[m_nLZ].x = m_x;
		m_LZ[m_nLZ].y = m_y;
		m_LZ[m_nLZ].vx = rand()%100 - 50;
		m_LZ[m_nLZ].vy = rand()%100 - 50;
		m_LZ[m_nLZ].size = (rand()%5+1)/100;
		m_LZ[m_nLZ].scT = rand()%10 + 20;
		m_LZ[m_nLZ].czT = 0;
		m_nLZ++;
	}
}

void CXieLou::Move(float deltat)
{
	int i;
	for(i=0;i<m_nLZ;i++)
	{
		m_LZ[i].x +=m_LZ[i].vx*deltat;
		m_LZ[i].y +=m_LZ[i].vy*deltat;
		m_LZ[i].czT +=deltat;
		if(m_LZ[i].czT>=m_LZ[i].scT)
			DeleteLiZi(i);
	}
}

void CXieLou::Draw(CDC *p)
{
	int i,x,y,r;
	pDC = p;
	CBrush brush,*pOldBrush;
	brush.CreateSolidBrush(RGB(0,255,0));
	pOldBrush =pDC->SelectObject(&brush);
	for(i=0;i<m_nLZ;i++)
	{
		x=m_YD.x + m_LZ[i].x*m_kx;
		y=m_YD.y + m_LZ[i].y*m_ky;
		r = m_LZ[i].size*m_kx;
		r = 3;
		pDC->Ellipse(x-r,y-r,x+r,y+r);
	}
	brush.DeleteObject();
	pDC->SelectObject(pOldBrush);

}

void CXieLou::DeleteLiZi(int n)
{
	m_LZ[n] = m_LZ[m_nLZ-1];
	m_nLZ--;
}

int CXieLou::NongDu(CPoint point)
{
	float x,y;
	x = (point.x - m_YD.x)/m_kx;
	y = (point.y - m_YD.y)/m_ky;

	return NongDu(x,y);
}

int CXieLou::NongDu(float x, float y)
{
	int i;
	int nd = 0;
	float d;
	for(i=0;i<m_nLZ;i++)
	{
		d = sqrt((x-m_LZ[i].x)*(x-m_LZ[i].x) + (y-m_LZ[i].y)*(y-m_LZ[i].y));
		if(d<=20)
			nd++;
	}
	return nd;
}
