#include "ellipse.h"

CEllipse::CEllipse(COLORREF _newColor, int iX, int iY)
{
	m_Color = _newColor;
	m_iStartX = iX;
	m_iStartY = iY;
	m_iEndX = 300;
	m_iEndY = 30;
}

CEllipse::CEllipse()
{
}

CEllipse::~CEllipse()
{
}

void CEllipse::Draw(HDC _hdc)
{
	HPEN green_pen = CreatePen(0, 10, m_Color);
	HPEN old_pen = static_cast<HPEN>(SelectObject(_hdc, green_pen));

	MoveToEx(_hdc, m_iStartX, m_iStartY, NULL);

	Ellipse(_hdc, m_iStartX, m_iStartY, m_iEndX, m_iEndY);

	SelectObject(_hdc, old_pen);
	DeleteObject(green_pen);
}

void CEllipse::SetColor(COLORREF _newColor)
{
	m_Color = _newColor;
}
