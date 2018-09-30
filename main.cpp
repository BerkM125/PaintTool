/*************************************************************
  Bachelor of Software Engineering
  Media Design School
  Auckland
  New Zealand

  (c) 2018 Media Design School

  File Name   :   main.cpp
  Description :   the main script for my paint tool
  Author      :   Henry Oliver
  Mail        :   henry.oliver@mediadesign.school.nz
*******************************************************************/

//#define WIN32_LEAN_AND_MEAN

#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.

#include "resource.h"
#include "shape.h"
#include "line.h"
#include "canvas.h"
#include "rectangle.h"
#include "ellipse.h"
#include "polygon.h"
#include "stamp.h"
#include "backBuffer.h"

#define WINDOW_CLASS_NAME L"WINCLASS1"
typedef DWORD COLORREF;
typedef DWORD* LPCOLORREF;

//Global variables
HINSTANCE g_hInstance;
CCanvas* g_pCanvas;
IShape* g_pShape = 0;
HMENU g_hMenu;

//Enum to decalre the type of tool supported by the application.
enum ESHAPE
{
	FREEHAND = 0,
	LINESHAPE,
	RECTANGLESHAPE,
	ELLIPSESHAPE,
	POLYGONSHAPE,
	STAMP
};

COLORREF DoChooseColor(HWND const _hWnd, const COLORREF _CurrentColor)
{
	CHOOSECOLOR cc;
	ZeroMemory(&cc, sizeof(cc));
	static COLORREF UserCustomColors[16]{};

	cc.lStructSize = sizeof(cc);
	cc.hwndOwner = _hWnd;
	cc.lpCustColors = static_cast<LPDWORD>(UserCustomColors);
	cc.rgbResult = _CurrentColor;
	cc.Flags = CC_FULLOPEN | CC_RGBINIT;

	if (ChooseColor(&cc))
	{
		return cc.rgbResult;
	}
	// else
	return _CurrentColor;
}

void GameLoop()
{
	//One frame of game logic occurs here...
}

LRESULT CALLBACK WindowProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{
	// This is the main message handler of the system.
	PAINTSTRUCT ps; // Used in WM_PAINT.
	HDC hdc;        // Handle to a device context.
	
	switch (_msg)
	{
	case WM_CREATE:
	{
		// Do initialization stuff here.
		

		// Return Success.
		return (0);
	}
	break;
	case WM_PAINT:
	{
		hdc = BeginPaint(_hwnd, &ps);
		// You would do all your painting here...
		


		EndPaint(_hwnd, &ps);
		// Return Success.
		return (0);
	}
	break;
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		case ID_FILE_OPEN:
		{+
			MessageBox(_hwnd, L"[INSERT FILE OPEN FEATURE HERE]", L"PLACEHOLDER", MB_OK | MB_ICONWARNING);
			break;
		}
		case ID_FILE_SAVE:
		{
			MessageBox(_hwnd, L"[INSERT FILE SAVE FEATURE HERE]", L"PLACEHOLDER", MB_OK | MB_ICONWARNING);
			break;
		} 
		case ID_FILE_EXIT:
		{
			int msgboxID = MessageBox(_hwnd, L"Are you sure you want to exit?", L"Goodbye", MB_YESNO | MB_ICONEXCLAMATION);
			switch (msgboxID)
			{
			case IDYES:
				PostQuitMessage(0);
				break;
			case IDNO:
				//do nothing
				break;
			}
			break;
		}

		case ID_SHAPE_LINE: {
			MessageBox(_hwnd, L"This is line, AND HE IS THIN", L"Author Information", MB_OK | MB_ICONEXCLAMATION);
			break;
		}

		case ID_SHAPE_R: {
			MessageBox(_hwnd, L"This is box, AND HE THICK", L"Author Information", MB_OK | MB_ICONEXCLAMATION);
			break;
		}

		case ID_SHAPE_ELLIPSE: {
			MessageBox(_hwnd, L"This is ellipse, AND HE IS CURVED", L"Author Information", MB_OK | MB_ICONEXCLAMATION);
			break;
		}

		case ID_SHAPE_POLYGON: {
			MessageBox(_hwnd, L"This is polygon, AND HE IS polly?", L"Author Information", MB_OK | MB_ICONEXCLAMATION);
			break;
		}

		case ID_PEN_WIDTH: {
			MessageBox(_hwnd, L"This is pen, HE IS NOT FAT!", L"Author Information", MB_OK | MB_ICONEXCLAMATION);
			break;
		}

		case ID_PEN_COLOR:{
			MessageBox(_hwnd, L"This is pen, COLORS!", L"Author Information", MB_OK | MB_ICONEXCLAMATION);
			DoChooseColor(_hwnd, (0,0,0));
			break;
		}

		case ID_PEN_STYLE: {
			MessageBox(_hwnd, L"This is pen, AND HE IS STYLISH", L"Author Information", MB_OK | MB_ICONEXCLAMATION);
			break;
		}

		case ID_BRUSH_COLOR: {
			MessageBox(_hwnd, L"This is brush, COLOR!", L"Author Information", MB_OK | MB_ICONEXCLAMATION);
			break;
		}

		case ID_BRUSH_STYLE: {
			MessageBox(_hwnd, L"This is brush, AND HE IS STYLISH", L"Author Information", MB_OK | MB_ICONEXCLAMATION);
			break;
		}

		case ID_ADD_STAMP: {
			MessageBox(_hwnd, L"This is stamp, AND HE IS A COLLECTOR", L"Author Information", MB_OK | MB_ICONEXCLAMATION);
			break;
		}

		case ID_HELP_ABOUT:
		{
			MessageBox(_hwnd, L"This paint tool was developed by Henry Oliver", L"Author Information", MB_OK | MB_ICONINFORMATION);
			break;
		}
		default:
			break;
		}
		return(0);
	}
	break;
	case WM_DESTROY:
	{
		// Kill the application, this sends a WM_QUIT message.
		PostQuitMessage(0);

		// Return success.
		return (0);
	}
	break;

		default:break;
	} // End switch.

	  // Process any messages that we did not take care of...

	return (DefWindowProc(_hwnd, _msg, _wparam, _lparam));
}


int WINAPI WinMain(HINSTANCE _hInstance,
	HINSTANCE _hPrevInstance,
	LPSTR _lpCmdLine,
	int _nCmdShow)
{
	WNDCLASSEX winclass; // This will hold the class we create.
	HWND hwnd;           // Generic window handle.
	MSG msg;             // Generic message.

	g_hInstance = _hInstance;
	// First fill in the window class structure.
	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = _hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = WINDOW_CLASS_NAME;
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// register the window class
	if (!RegisterClassEx(&winclass))
	{
		return (0);
	}

	g_hMenu = LoadMenu(_hInstance, MAKEINTRESOURCE(IDR_MENU1));
	// create the window
	hwnd = CreateWindowEx(NULL, // Extended style.
		WINDOW_CLASS_NAME,      // Class.
		L"My Paint Tool",   // Title.
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100,                    // Initial x,y.
		1500, 800,                // Initial width, height.
		NULL,                   // Handle to parent.
		g_hMenu,                   // Handle to menu.
		_hInstance,             // Instance of this application.
		NULL);                  // Extra creation parameters.

	if (!(hwnd))
	{
		return (0);
	}



	// Enter main event loop
	while (true)
	{
		// Test if there is a message in queue, if so get it.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// Test if this is a quit.
			if (msg.message == WM_QUIT)
			{
				break;
			}

			// Translate any accelerator keys.
			TranslateMessage(&msg);
			// Send the message to the window proc.
			DispatchMessage(&msg);
		}

		// Main game processing goes here.
		GameLoop(); //One frame of game logic occurs here...
	}

	// Return to Windows like this...
	return (static_cast<int>(msg.wParam));
}
