#include "ellipse.h"

CEllipse::CEllipse(COLORREF _newColor, COLORREF _fillcolor, int iX, int iY, int _iPenWidth, int _iPenStyle, int _iBrushStyle)
{
	m_Color = _newColor;
	m_iFillColor = _fillcolor;
	m_iStartX = iX;
	m_iStartY = iY;
	m_iPenWidth = _iPenWidth;
	m_iPenStyle = _iPenStyle;
	m_iBrushStyle = _iBrushStyle;
}

CEllipse::CEllipse()
{
}

CEllipse::~CEllipse()
{
}

void CEllipse::Draw(HDC _hdc)
{
	HPEN green_pen = CreatePen(m_iPenStyle, m_iPenWidth, m_Color);
	HPEN old_pen = static_cast<HPEN>(SelectObject(_hdc, green_pen));

	HBRUSH brush = CreateHatchBrush(m_iBrushStyle, m_iFillColor);
	HBRUSH o_brush = static_cast<HBRUSH>(SelectObject(_hdc, brush));

	MoveToEx(_hdc, m_iStartX, m_iStartY, NULL);

	Ellipse(_hdc, m_iStartX, m_iStartY, m_iEndX, m_iEndY);

	SelectObject(_hdc, old_pen);
	SelectObject(_hdc, brush);
	DeleteObject(o_brush);
	DeleteObject(green_pen);
}

void CEllipse::SetColor(COLORREF _newColor)
{
	m_Color = _newColor;
}
