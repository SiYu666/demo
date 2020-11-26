// WuRenJi.h: interface for the CWuRenJi class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WURENJI_H__FFF84F6D_B4F8_4426_BE7C_559CC416A8AB__INCLUDED_)
#define AFX_WURENJI_H__FFF84F6D_B4F8_4426_BE7C_559CC416A8AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Car.h"

class CWuRenJi : public CCar  
{
public:
	void DrawWaiXing(CDC *p);
	CWuRenJi();
	virtual ~CWuRenJi();

};

#endif // !defined(AFX_WURENJI_H__FFF84F6D_B4F8_4426_BE7C_559CC416A8AB__INCLUDED_)
