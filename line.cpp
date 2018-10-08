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


	//HPEN green_pen = CreatePen(PS_SOLID, 7, RGB(0, 255, 0));
	//HPEN old_pen = static_cast<HPEN>(SelectObject(_hdc, green_pen));

	MoveToEx(_hdc, 10, 10, NULL);
	LineTo(_hdc, 50, 60);

	//SelectObject(_hdc, old_pen);
	//DeleteObject(green_pen);

}

void CLine::SetWidth(int _iNewWidth) {


}

void CLine::CLinec(int _iStyle, int _iWidth, COLORREF _newColor, int _iStartX, int _iStartY) {

	_iStyle = PS_SOLID;
	_iWidth = 1;
	_newColor = RGB(0, 0, 0);
	_iStartX = 0;
	_iStartY = 0;
}