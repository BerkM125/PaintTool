/*******************************************************************
  Bachelor of Software Engineering
  Media Design School
  Auckland
  New Zealand

  (c) 2018 Media Design School

  File Name   :   canvas.h
  Description :   this holds important infomation for the backbuffer
  Author      :   Henry Oliver
  Mail        :   henry.oliver@mediadesign.school.nz
***********************************************************************/

#ifndef __CANVAS_H__
#define __CANVAS_H__

//	Library Includes
#include <windows.h>
#include <windowsx.h>
#include <vector>

typedef enum
{
	LINE = 0,
	BOX,
	ELLIPSE,
	MAX_SHAPE
}EShape;

class IShape; //Forward Declaration
class CLine;
class CStamp;
class CBackBuffer;

class CCanvas
{
public:
	CCanvas();
	~CCanvas();
	bool Initialise(HWND _hwnd, int _iWidth, int _iHeight);
	CBackBuffer* GetBackBuffer();
	bool Draw(HDC _hdc);
	void Save(HWND _hwnd);
	void AddShape(IShape*);
	
	
private:
	CBackBuffer* m_pBackBuffer; // A canvas has a backbuffer.
	std::vector<IShape*> m_shapes;
};

#endif