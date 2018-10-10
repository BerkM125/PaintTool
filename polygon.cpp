#include "polygon.h"
#include <vector>

std::vector<POINT> m_Points;

CPolygon::CPolygon(int _iHatchStyle, COLORREF _FillColor, int _iPenStyle, COLORREF _PenColor, int _iPenWidth)
{
	m_iBrushStyle = _iHatchStyle;
	m_nPoints = 0;
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

	HBRUSH brush = CreateHatchBrush(m_iBrushStyle, m_iFillColor);
	HBRUSH o_brush = static_cast<HBRUSH>(SelectObject(_hdc, brush));

	MoveToEx(_hdc, m_iStartX, m_iStartY, NULL);
 	Polygon(_hdc, m_Points.data(), static_cast<int>(m_Points.size()));

	SelectObject(_hdc, old_pen);
	SelectObject(_hdc, o_brush);

	DeleteObject(green_pen);
	DeleteObject(brush);
	DeleteObject(o_brush);
	DeleteObject(Polygon);
}

void CPolygon::SetFillColor(COLORREF _newColor)
{
	m_iFillColor = _newColor;
}

void CPolygon::SetPenColor(COLORREF _newColor)
{
	m_iPenColor = _newColor;
}

void CPolygon::AddPoint(POINT p) {
	m_Points.push_back(p);
}