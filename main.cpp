#include <Windows.h>
#include "Graphics.h"
#include "GameController.h"
#include "GameLevel.h"
#include "MainLevel.h"
#include "GameObject.h"
#include "GameOverLevel.h"
#include "Window.h"








int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmd, INT nCmdShow)
{


	int h, v, s = -1, sp = -1, sh = 1;
	Window window(hInstance);
	Graphics graphics;


	/****INICJALIZACJA SILNIKA GRAFICZNEGO****/
	if(!graphics.Init(window.getHandle()))
	{
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




	ShowWindow(window.getHandle(), nCmdShow);


	/****PÊTLA GRY****/

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
			h = window.getH();
			v = window.getV();
			
			sp = s;
			s = window.getS();

			// ENSURE THAT ONE SPACE PUSH = ONE SHOT
			if (sp*s < 0 && sp == -1) sh = 1;
			else sh = 0;
			
			
			graphics.BeginDraw();
			GameController::ProcessKey(h, v, sh);
			GameController::Update();

			GameController::Render();
			graphics.EndDraw();
		}
	}


	return 0;
}