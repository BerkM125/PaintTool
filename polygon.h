/*******************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand

(c) 2018 Media Design School

File Name   :   polygon.h
Description :   this holds important infomation for the polygon
Author      :   Henry Oliver
Mail        :   henry.oliver@mediadesign.school.nz
***********************************************************************/

#ifndef __POLYGON_H__
#define __POLYGON_H__



//	Library Includes
#include <windows.h>
#include <windowsx.h>
#include <vector>
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
	int GetSize() const;
	int GetStartX() const;
	int GetStartY() const;

	


private:
	COLORREF m_iFillColor;
	COLORREF m_iPenColor;
	std::vector<POINT> m_Points;
	int m_nPoints;
	int m_iFillStyle;
	int m_iPenStyle;
	int m_iPenWidth;
	int m_iBrushStyle;
};

#endif