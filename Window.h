#pragma once

#include <Windows.h>
#include "GameController.h"
class Window
{

private:
	static WNDCLASSEX _windowClass;
	static HWND _windowHandle;
	static int _h, _v, _s;

public:
	Window(HINSTANCE hInstance);
	~Window();
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	
	HWND getHandle();
	int getH();
	int getV();
	int getS();



};

