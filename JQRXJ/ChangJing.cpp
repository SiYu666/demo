// ChangJing.cpp: implementation of the CChangJing class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "JQRXJ.h"
#include "ChangJing.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChangJing::CChangJing()
{
	m_YD.x = 500;
	m_YD.y = 300;
	m_kx = 1000.0/1600;
	m_ky = -600.0/1000;
	m_nLM = 0;
	
	InitialDataJianZhu();
	InitialDataLuMian();
		
}

CChangJing::~CChangJing()
{

}

void CChangJing::Draw(CDC *p)
{
	int	x,y,r;
	int i;
	CPoint dd[4];
	pDC = p;

	x=m_YD.x;
	y = m_YD.y;
	r =10;
	pDC->Ellipse(x-r,y-r,x+r,y+r);
	//DrawJianZhu(m_TUShuGan);
	DrawJianZhu(m_YFL);
	DrawLuMian(m_L_HZ);	
//	DrawLuMian(m_L_XL);
}

void CChangJing::InitialDataJianZhu()
{
/*	m_TUShuGan.Name  = "图书馆";
	m_TUShuGan.Pos[0] = 60;
	m_TUShuGan.Pos[1] = -100;

	m_TUShuGan.DD[0][0] = 44;
	m_TUShuGan.DD[0][1] = -81;

	m_TUShuGan.DD[1][0] = 167;
	m_TUShuGan.DD[1][1] = -81;

	m_TUShuGan.DD[2][0] = 167;
	m_TUShuGan.DD[2][1] = -173;

	m_TUShuGan.DD[3][0] = 44;
	m_TUShuGan.DD[3][1] = -130;*/
	ReadJianZhu();

}

void CChangJing::InitialDataLuMian()
{
	/*m_L_XL.n= 2;
	m_L_XL.Name = "小路";
	m_L_XL.DD1[0][0] = -13;
	m_L_XL.DD1[0][1] = 5;
	m_L_XL.DD1[1][0] = -39; 
	m_L_XL.DD1[1][1] = 224;

	m_L_XL.DD2[0][0] = -9;
	m_L_XL.DD2[0][1] = 5;
	m_L_XL.DD2[1][0] = -34;
	m_L_XL.DD2[1][1] = 224;

	m_L_XL.Pos[0] = -37;
	m_L_XL.Pos[1] = 100;

	m_L_HZ.n= 2;
	m_L_HZ.Name = "汇中路";
	m_L_HZ.DD1[0][0] = -152;
	m_L_HZ.DD1[0][1] = 0;
	m_L_HZ.DD1[1][0] = 852;
	m_L_HZ.DD1[1][1] = 0;

	m_L_HZ.DD2[0][0] = -152;
	m_L_HZ.DD2[0][1] = 5;
	m_L_HZ.DD2[1][0] = 852;
	m_L_HZ.DD2[1][1] = 5;

	m_L_HZ.Pos[0] = 20;
	m_L_HZ.Pos[1] = 3;*/
	ReadLuMian();
}

void CChangJing::DrawJianZhu(SJianZhu jz)
{
	/*int	x,y;
	int i;
	x= m_YD.x +m_kx*jz.DD[3][0];
	y= m_YD.y +m_ky*jz.DD[3][1];
	pDC->MoveTo(x,y);
	for(i=0;i<4;i++)
	{
		x= m_YD.x +m_kx*jz.DD[i][0];
		y= m_YD.y +m_ky*jz.DD[i][1];
		pDC->LineTo(x,y);
	}
	x= m_YD.x +m_kx*jz.Pos[0];
	y= m_YD.y +m_ky*jz.Pos[1];
	pDC->TextOut(x,y,jz.Name);*/
	int	x,y,j;
	int i;
	for(j=0;j<100;j++)
	{
		x= m_YD.x +m_kx*m_JZ[j].DD[3][0];
		y= m_YD.y +m_ky*m_JZ[j].DD[3][1];
		pDC->MoveTo(x,y);
		for(i=0;i<4;i++)
		{
			x= m_YD.x +m_kx*m_JZ[j].DD[i][0];
			y= m_YD.y +m_ky*m_JZ[j].DD[i][1];
			pDC->LineTo(x,y);
		}
		x= m_YD.x +m_kx*m_JZ[j].Pos[0];
		y= m_YD.y +m_ky*m_JZ[j].Pos[1];
		pDC->TextOut(x,y,m_JZ[j].str);
	}
}

void CChangJing::DrawLuMian(SLuMian LU)
{
	/*int	x,y;
	int i;
	x= m_YD.x +m_kx*LU.DD1[0][0];
	y= m_YD.y +m_ky*LU.DD1[0][1];
	pDC->MoveTo(x,y);
	for(i=0;i<LU.n;i++)
	{
		x= m_YD.x +m_kx*LU.DD1[i][0];
		y= m_YD.y +m_ky*LU.DD1[i][1];
		pDC->LineTo(x,y);
	}
	x= m_YD.x +m_kx*LU.DD2[0][0];
	y= m_YD.y +m_ky*LU.DD2[0][1];
	pDC->MoveTo(x,y);
	for(i=0;i<LU.n;i++)
	{
		x= m_YD.x +m_kx*LU.DD2[i][0];
		y= m_YD.y +m_ky*LU.DD2[i][1];
		pDC->LineTo(x,y);
	}
	x= m_YD.x +m_kx*LU.Pos[0];
	y= m_YD.y +m_ky*LU.Pos[1];
	pDC->TextOut(x,y,LU.Name);*/
	int	x,y;
	int i,j;
	for(j=0;j<m_nLM;j++)
	{
		x= m_YD.x +m_kx*m_LM[j].DD1[0][0];
		y= m_YD.y +m_ky*m_LM[j].DD1[0][1];
		pDC->MoveTo(x,y);
		for(i=0;i<m_LM[j].n;i++)
		{
			x= m_YD.x +m_kx*m_LM[j].DD1[i][0];
			y= m_YD.y +m_ky*m_LM[j].DD1[i][1];
			pDC->LineTo(x,y);
		}
		x= m_YD.x +m_kx*m_LM[j].DD2[0][0];
		y= m_YD.y +m_ky*m_LM[j].DD2[0][1];
		pDC->MoveTo(x,y);
		for(i=0;i<m_LM[j].n;i++)
		{
			x= m_YD.x +m_kx*m_LM[j].DD2[i][0];
			y= m_YD.y +m_ky*m_LM[j].DD2[i][1];
			pDC->LineTo(x,y);
		}
		x= m_YD.x +m_kx*m_LM[j].Pos[0];
		y= m_YD.y +m_ky*m_LM[j].Pos[1];
		pDC->TextOut(x,y,m_LM[j].Name);
	}

}

void CChangJing::ReadJianZhu()
{
	int i;
	FILE *fp;
	fp = fopen(".\\JianZhu.txt","r");
	for(i=0;i<100;i++)
	{
		fscanf(fp,"%s %f %f %f %f %f %f %f %f %f %f",m_JZ[i].str,&m_JZ[i].Pos[0],&m_JZ[i].Pos[1],&m_JZ[i].DD[0][0],&m_JZ[i].DD[0][1],&m_JZ[i].DD[1][0],&m_JZ[i].DD[1][1],&m_JZ[i].DD[2][0],&m_JZ[i].DD[2][1],&m_JZ[i].DD[3][0],&m_JZ[i].DD[3][1]);
	}
	fclose(fp);
}

void CChangJing::ReadLuMian()
{
/*	int i,j,n;
	i = 0;
	float dd[20][2];
	CString str,luming,temp;
	CStdioFile f;
	f.Open(".\\LuMian.txt",CFile::modeRead);
	while(f.ReadString(str))
	{
		n = str.Find(':');
		m_LM[i].Name = str.Left(n);
		str.Delete(0,n+2);

		n = str.Find(' ');
		temp = str.Left(n);

		m_LM[i].n= atoi(temp);

		str.Delete(0,n+1);
		n = str.Find(' ');
		temp = str.Left(n);
		m_LM[i].Pos[0] = atof(temp);
		
		str.Delete(0,n+1);
		n = str.Find(' ');
		temp = str.Left(n);
		m_LM[i].Pos[1] = atof(temp);
		for(j=0;j<m_LM[i].n;j++)
		{
			str.Delete(0,n+1);
			n = str.Find(' ');
			temp = str.Left(n);
			m_LM[i].DD1[j][0] = atof(temp);

			str.Delete(0,n+1);
			n = str.Find(' ');
			if(n==-1)
				temp = str;
			else
				temp = str.Left(n);
			m_LM[i].DD2[j][1]  = atof(temp);
		}
		i++;
	}
	m_nLM = i;*/
	int i=0,j;
	int n;//n标记位置
	CStdioFile f;
	CString str,luming,temp;
	f.Open(".\\LuMian.txt",CFile::modeReadWrite);
	while(f.ReadString(str))
	{
		n = str.Find(':');
		m_LM[i].Name = str.Left(n);
		str.Delete(0,n+2);

		n = str.Find(' ');
		temp = str.Left(n);

		m_LM[i].n = atoi(temp);

		str.Delete(0,n+1);
		n = str.Find(' ');
		temp = str.Left(n);
		m_LM[i].Pos[0] = atof(temp);
		
		str.Delete(0,n+1);
		n = str.Find(' ');
		temp = str.Left(n);
		m_LM[i].Pos[1] = atof(temp);

		for(j=0;j<m_LM[i].n;j++)
		{
			str.Delete(0,n+1);
			n = str.Find(' ');
			temp = str.Left(n);
			m_LM[i].DD1[j][0] = atof(temp);

			str.Delete(0,n+1);
			n = str.Find(' ');
			if(n==-1)
				temp = str;
			else 
				temp = str.Left(n);
			m_LM[i].DD1[j][1] = atof(temp);
		}
		for(j=0;j<m_LM[i].n;j++)
		{
			str.Delete(0,n+1);
			n = str.Find(' ');
			temp = str.Left(n);
			m_LM[i].DD2[j][0] = atof(temp);

			str.Delete(0,n+1);
			n = str.Find(' ');
			if(n==-1)
				temp = str;
			else 
				temp = str.Left(n);
			m_LM[i].DD2[j][1] = atof(temp);
		}
		i++;
	}
	m_nLM = i;
}
