#include "canvas.h"
#include "shape.h"
#include <vector>

std::vector<IShape>shapeIterator;

void CCanvas::PopShape()
{
	m_shapes.pop_back();
}

CCanvas::CCanvas()
{
}

CCanvas::~CCanvas()
{
	for (int i = 0; i < m_shapes.size(); i++) {
		delete(m_shapes[i]);
	}
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

	for (int i = 0; i < m_shapes.size(); i++) {

		m_shapes[i]->Draw(_hdc);
	}

	return true;
}

void CCanvas::Save(HWND _hwnd)
{
	
}

void CCanvas::AddShape(IShape * shape)
{

	m_shapes.push_back(shape);

}
