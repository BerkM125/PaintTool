/****************************************************************
  Bachelor of Software Engineering
  Media Design School
  Auckland
  New Zealand

  (c) 2018 Media Design School

  File Name   :   [Filename]
  Description :   [One line description of what is the file is for]
  Author      :   [Your name]
  Mail        :   [your.name]@mediadesign.school.nz
********************************************************************/

#ifndef __POLYGON_H__
#define __POLYGON_H__

//	Library Includes
#include <windows.h>
#include <windowsx.h>

#include "shape.h"

class CPolygon : public IShape
{
public:
	CPolygon(int _iHatchStyle, COLORREF _FillColor, int _iPenStyle, COLORREF _PenColor, int _iPenWidth);
	CPolygon();
	virtual ~CPolygon();

	virtual void Draw(HDC _hdc);
	void SetFillColor(COLORREF _newColor);
	void SetPenColor(COLORREF _newColor);
	void AddPoint(POINT p);


private:
	COLORREF m_iFillColor;
	COLORREF m_iPenColor;
	POINT* m_pPointList;
	int m_nPoints;
	int m_iFillStyle;
	int m_iPenStyle;
	int m_iPenWidth;
};

#endif