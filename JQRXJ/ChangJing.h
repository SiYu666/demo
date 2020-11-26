// ChangJing.h: interface for the CChangJing class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHANGJING_H__ED192BE0_827C_411D_898C_4C5183197600__INCLUDED_)
#define AFX_CHANGJING_H__ED192BE0_827C_411D_898C_4C5183197600__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct
{
	float DD[4][2];
	float Pos[2];
	CString Name;
	char str[30];
}SJianZhu;
typedef struct
{
	float DD1[10][2];
	float DD2[10][2];
	int n;
	float Pos[2];
	CString Name;
	char str[30];
}SLuMian;
class CChangJing  
{
public:
	void ReadLuMian();
	void ReadJianZhu();
	void DrawLuMian(SLuMian LU);
	void DrawJianZhu(SJianZhu jz);
	void InitialDataLuMian();
	void InitialDataJianZhu();
	void Draw(CDC *p);
	CChangJing();
	virtual ~CChangJing();
	CDC *pDC;
	CPoint m_YD;
	float m_kx,m_ky;
	SJianZhu m_TUShuGan,m_YFL;
	SLuMian m_L_HZ,m_L_XL;
	SJianZhu m_JZ[100];
	SLuMian m_LM[100];
	float m_nLM;
};

#endif // !defined(AFX_CHANGJING_H__ED192BE0_827C_411D_898C_4C5183197600__INCLUDED_)
