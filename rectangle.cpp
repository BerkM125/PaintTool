#include <Windows.h>

#include "rectangle.h"

CRectangle::CRectangle()
{
}

CRectangle::~CRectangle()
{
}

void CRectangle::Draw(HDC _hdc)
{
	HPEN green_pen = CreatePen(m_iBrushStyle, 10, m_Color);
	HPEN old_pen = static_cast<HPEN>(SelectObject(_hdc, green_pen));

	HBRUSH brush = CreateSolidBrush(m_iFillColor);

	MoveToEx(_hdc, m_iStartX, m_iStartY, NULL);
	
	Rectangle(_hdc, m_iStartX, m_iStartY, m_iEndX, m_iEndY);

	SelectObject(_hdc, old_pen);
	SelectObject(_hdc, brush);
	//DeleteObject(brush);
	DeleteObject(green_pen);
}

void CRectangle::SetBrushStyle(EBRUSHSTYLE _brushStyle)
{
	m_iBrushStyle = _brushStyle;
}

void CRectangle::SetFillColor(COLORREF _newColor)
{
	m_iFillColor = _newColor;
}

void CRectangle::SetPenStyle(int _iPenStyle)
{
	m_iPenStyle = _iPenStyle;
}

void CRectangle::SetPenColor(COLORREF _newColor)
{
	m_iPenColor = _newColor;
}

void CRectangle::SetHatchStyle(int _iHatchStyle)
{
	m_iHatchStyle = _iHatchStyle;
}

CRectangle::CRectangle(EBRUSHSTYLE _iBrushStyle, int _iHatchStyle, COLORREF _FillColor, int _iPenStyle, COLORREF _PenColor, int _X, int _Y)
{
	m_iBrushStyle = _iBrushStyle;
	m_iHatchStyle = _iHatchStyle;
	m_iFillColor = _FillColor;
	m_iPenStyle = _iPenStyle;
	m_iPenColor = _PenColor;
	m_Color = _PenColor;
}