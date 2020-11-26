// Car.h: interface for the CCar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAR_H__F25BBCF5_AC5C_40A0_A13F_4E552B4DD10C__INCLUDED_)
#define AFX_CAR_H__F25BBCF5_AC5C_40A0_A13F_4E552B4DD10C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCar  
{
public:
	void DrawXingZhuang();
	int AnLuXian_Move(float deltat);
	void DrawLuXian();
	void AnLuXian_SheDing(CPoint point);
	int Move(float deltat);
	void yunSuDaoMuBiaoDian(CPoint point);
	void DianMove(CPoint point);
	void DrawCar(CDC *p);
	CCar();
	virtual ~CCar();

	float m_x,m_y;
	float m_vx,m_vy,m_v;
	float m_l,m_h,m_r;
	CDC *pDC;
	CPoint m_YD;
	float m_kx,m_ky;
	float m_MBDx,m_MBDy;

	float m_LuXian[100][2];
	int m_nLX;
	int m_nMBDLX;

};

#endif // !defined(AFX_CAR_H__F25BBCF5_AC5C_40A0_A13F_4E552B4DD10C__INCLUDED_)
