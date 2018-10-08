/*************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand

(c) 2018 Media Design School

File Name   :   line.cpp
Description :   Draws Lines
Author      :   Henry Oliver
Mail        :   henry.oliver@mediadesign.school.nz
*******************************************************************/

#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.
#include "shape.h"
#include "line.h"

CLine::CLine() {


}

CLine:: ~CLine() {

}

void CLine::Draw(HDC _hdc) {


	HPEN green_pen = CreatePen(m_iStyle, m_iWidth, m_Color);
	HPEN old_pen = static_cast<HPEN>(SelectObject(_hdc, green_pen));

	MoveToEx(_hdc, m_iStartX, m_iStartY, NULL);
	LineTo(_hdc, m_iEndX, m_iEndY);

	SelectObject(_hdc, old_pen);
	DeleteObject(green_pen);

}

void CLine::SetWidth(int _iNewWidth) {
	m_iWidth = _iNewWidth;
}

CLine::CLine(int _iStyle, int _iWidth, COLORREF _newColor, int _iStartX, int _iStartY, int _iEndX, int _iEndY)
{
	m_Color = _newColor;
	m_iStyle = _iStyle;
	m_iWidth = _iWidth;
	m_iStartX = _iStartX;
	m_iStartY = _iStartY;
	m_iEndX = _iEndX;
	m_iEndY = _iEndY;
}
