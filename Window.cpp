#include "Window.h"


WNDCLASSEX Window::_windowClass;
HWND Window::_windowHandle;

int Window::_h = 0;
int Window::_v = 0;
int Window::_s = 0;



Window::Window(HINSTANCE hInstance)
{

	ZeroMemory(&_windowClass, sizeof(WNDCLASSEX));
	_windowClass.cbSize = sizeof(WNDCLASSEX);
	_windowClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	_windowClass.hInstance = hInstance;
	_windowClass.lpfnWndProc = WindowProc;
	_windowClass.lpszClassName = L"MainWindow";
	_windowClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClassEx(&_windowClass);


	RECT rect = { 0, 0, 800, 600 };
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);
	_windowHandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"MainWindow", L"Das Boot", WS_OVERLAPPEDWINDOW, 100, 100, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, 0);

}


Window::~Window()
{
}







LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_DESTROY) { PostQuitMessage(0); return 0; }



	if (uMsg == WM_KEYDOWN)
	{
		switch (wParam)
		{

		case VK_LEFT:

			_h = -1;

			break;

		case VK_RIGHT:

			_h = 1;
			break;

		case VK_UP:

			_v = -1;
			break;
		case VK_DOWN:

			_v = 1;
			break;

		case VK_SPACE:

			// STRZELAJ
			_s = 1;
			break;

		case VK_ESCAPE:

			//WLACZ MENU GRY

			break;
		}

		//GameController::ProcessKey(_h, _v, _s);
	}

	if (uMsg == WM_KEYUP)
	{
		switch (wParam)
		{

		case VK_LEFT:

			_h = 0;

			break;

		case VK_RIGHT:

			_h = 0;
			break;

		case VK_UP:

			_v = 0;
			break;
		case VK_DOWN:

			_v = 0;
			break;

		case VK_SPACE:

			// STRZELAJ
			_s = -1;
			break;

		case VK_ESCAPE:

			//WLACZ MENU GRY

			break;
		}
		//GameController::ProcessKey(_h, _v, _s);
	}



	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}

HWND Window::getHandle()
{
	return _windowHandle;
}

int Window::getH()
{
	return _h;
}

int Window::getV()
{
	return _v;
}

int Window::getS()
{
	return _s;
}
