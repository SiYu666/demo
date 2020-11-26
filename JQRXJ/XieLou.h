// XieLou.h: interface for the CXieLou class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XIELOU_H__63E2A425_B14D_42DF_A3EF_F465B069EA92__INCLUDED_)
#define AFX_XIELOU_H__63E2A425_B14D_42DF_A3EF_F465B069EA92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct
{
	float x,y;
	float vx,vy;
	float size;
	float color;
	float scT;//总生存期
	float czT;//当前存在时间

}SliZi;
class CXieLou  
{
public:
	int NongDu(float x,float y);
	int NongDu(CPoint point);
	void DeleteLiZi(int n);
	void Draw(CDC *p);
	void Move(float deltat);
	void CreateLiZi(float deltat);
	CXieLou();
	virtual ~CXieLou();
	CDC *pDC;
	SliZi m_LZ[100000];
	int m_nLZ;
	float m_x,m_y;
	CPoint m_YD;
	float m_kx,m_ky;

};

#endif // !defined(AFX_XIELOU_H__63E2A425_B14D_42DF_A3EF_F465B069EA92__INCLUDED_)
