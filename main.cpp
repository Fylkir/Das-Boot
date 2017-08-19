#include <Windows.h>
#include "Graphics.h"
#include "GameController.h"
#include "GameLevel.h"
#include "MainLevel.h"
#include "GameObject.h"
#include "GameOverLevel.h"



Graphics* graphics;
//ZMIENNE DO STEROWANIA GRA
int h = 0, v = 0, s = 0;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_DESTROY) { PostQuitMessage(0); return 0; }
	
	
	
	if (uMsg == WM_KEYDOWN)
	{
		switch (wParam)
		{

		case VK_LEFT:

			h = -1;

			break;

		case VK_RIGHT:

			h = 1;
			break;

		case VK_UP:

			v = -1;
			break;
		case VK_DOWN:

			v = 1;
			break;

		case VK_SPACE:

			// STRZELAJ
			s = 1;
			break;

		case VK_ESCAPE:

			//WLACZ MENU GRY

			break;
		}
		
		GameController::ProcessKey(h, v, s);
	}

	if (uMsg == WM_KEYUP)
	{
		switch (wParam)
		{

		case VK_LEFT:

			h = 0;

			break;

		case VK_RIGHT:

			h = 0;
			break;

		case VK_UP:

			v = 0;
			break;
		case VK_DOWN:

			v = 0;
			break;

		case VK_SPACE:

			// STRZELAJ
			s = 0;
			break;

		case VK_ESCAPE:

			//WLACZ MENU GRY

			break;
		}
		GameController::ProcessKey(h, v, s);
	}
		


	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmd, INT nCmdShow)
{
	
	/****PRZYGOTOWANIE OKNA****/

	WNDCLASSEX windowclass;
	ZeroMemory(&windowclass, sizeof(WNDCLASSEX));
	windowclass.cbSize = sizeof(WNDCLASSEX);
	windowclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	windowclass.hInstance = hInstance;
	windowclass.lpfnWndProc = WindowProc;
	windowclass.lpszClassName = L"MainWindow";
	windowclass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassEx(&windowclass);




	/****STWORZENIE OKNA ****/
	RECT rect = { 0, 0, 800, 600 };
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);
	HWND windowhandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"MainWindow", L"Das Boot", WS_OVERLAPPEDWINDOW, 100, 100, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, 0);

	if (!windowhandle) return -1;

	/****INICJALIZACJA SILNIKA GRAFICZNEGO****/
	graphics = new Graphics();
	if(!graphics->Init(windowhandle))
	{
		delete graphics;
		return -1;
	}
	Texture::Init(graphics);
	GameLevel::Init(graphics);
	GameObject::Init(graphics);


	/*****WCZYTANIE POZIOMÓW****/
	std::vector<GameLevel*> levels;

	levels.push_back(new MainLevel);
	levels.push_back(new GameOverLevel);

	/****INICJALIZACJA SILNIKA GRY****/
	GameController::LoadLevels(levels);



	ShowWindow(windowhandle, nCmdShow);


	/****OBSLUGA WIADOMOSCI****/

	MSG message;
	message.message = WM_NULL;
	while (message.message != WM_QUIT)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		else
		{
			graphics->BeginDraw();
			GameController::ProcessKey(h, v, s=0);
			GameController::Update();

			GameController::Render();
			graphics->EndDraw();
		}
	}


	return 0;
}