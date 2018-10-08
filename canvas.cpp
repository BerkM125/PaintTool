#include "canvas.h"

CCanvas::CCanvas()
{
}

CCanvas::~CCanvas()
{
}

bool CCanvas::Initialise(HWND _hwnd, int _iWidth, int _iHeight)
{
	return false;
}

CBackBuffer * CCanvas::GetBackBuffer()
{
	return nullptr;
}

bool CCanvas::Draw(HDC _hdc)
{
	MoveToEx(_hdc, 0, 0, NULL);
	LineTo(_hdc, 100, 500);

	return false;
}

void CCanvas::Save(HWND _hwnd)
{
	
}

void CCanvas::AddShape(IShape *)
{



}
