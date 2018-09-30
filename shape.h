/***********************************************************
  Bachelor of Software Engineering
  Media Design School
  Auckland
  New Zealand

  (c) 2018 Media Design School

  File Name   :   [Filename]
  Description :   [One line description of what is the file is for]
  Author      :   [Your name]
  Mail        :   [your.name]@mediadesign.school.nz
*************************************************************/


#ifndef __SHAPE_H__
#define __SHAPE_H__

//	Library Includes
#include <windows.h>
#include <windowsx.h>

class IShape
{
public:
	IShape();
	virtual ~IShape(){}

	virtual void Draw(HDC _hdc) = 0;

	void SetStartX(int _iStartX);
	void SetEndX(int _iEndX);
	void SetStartY(int _iStartX);
	void SetEndY(int _iStartX);
	//void SetColor(COLORREF _newColor);

protected:
	int m_iStartX;
	int m_iEndX;
	int m_iStartY;
	int m_iEndY;
	//COLORREF m_ColorRef;
};

#endif