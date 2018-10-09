#include "polygon.h"

CPolygon::CPolygon(int _iHatchStyle, COLORREF _FillColor, int _iPenStyle, COLORREF _PenColor, int _iPenWidth)
{
	_iHatchStyle = 0;
	m_iFillColor = _FillColor;
	m_iPenStyle = _iPenStyle;
	m_iPenColor = _PenColor;
	m_iPenWidth = _iPenWidth;
}

CPolygon::CPolygon()
{
}

CPolygon::~CPolygon()
{
}

void CPolygon::Draw(HDC _hdc)
{

	HPEN green_pen = CreatePen(m_iPenStyle, m_iPenWidth, m_iPenColor);
	HPEN old_pen = static_cast<HPEN>(SelectObject(_hdc, green_pen));

	MoveToEx(_hdc, m_iStartX, m_iStartY, NULL);

	//Polygon(_hdc, , m);

	SelectObject(_hdc, old_pen);
	DeleteObject(green_pen);

}

void CPolygon::SetFillColor(COLORREF _newColor)
{
	m_iFillColor = _newColor;
}

void CPolygon::SetPenColor(COLORREF _newColor)
{
	m_iPenColor = _newColor;
}

void CPolygon::AddPoint(POINT p)
{
}
