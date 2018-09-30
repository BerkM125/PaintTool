/**************************************************************
  Bachelor of Software Engineering
  Media Design School
  Auckland
  New Zealand

  (c) 2018 Media Design School

  File Name   :   [Filename]
  Description :   [One line description of what is the file is for]
  Author      :   [Your name]
  Mail        :   [your.name]@mediadesign.school.nz
*******************************************************************/

#ifndef __STAMP_H__
#define __STAMP_H__

#include <Windows.h>

#include "shape.h"
class CStamp : public IShape
{
public:
	CStamp();
	CStamp(HINSTANCE hInstance, wchar_t* filename, int, int );
	virtual ~CStamp();

	virtual void Draw(HDC _hdc);
	void SetStartX(int _iX);
	void SetStartY(int _iY);

private:
	HBITMAP m_hBitMap;
	BITMAP m_bitmapStructure;
};

#endif