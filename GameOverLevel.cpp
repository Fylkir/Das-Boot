#include "GameOverLevel.h"



GameOverLevel::GameOverLevel()
{
}


GameOverLevel::~GameOverLevel()
{
}

void GameOverLevel::Load()
{

}
void GameOverLevel::Unload()
{
	switchTo = -1;
	MainLevel::_score = 0;

}
void GameOverLevel::Update(double time, double dtime)
{

}
void GameOverLevel::Render()
{
	gfx->DrawRedRectangle(250, 200, 300, 200);
	gfx->DrawBlackRectangleFrame(250, 200, 300, 200);
	gfx->PrintText(L"YOU LOST!", 325, 250, 150, 20);
	gfx->PrintText(L"SCORE:", 360, 290, 80, 20);
	gfx->PrintText(std::to_wstring(MainLevel::_score).c_str(), 375, 320, 50, 20);
	gfx->PrintText(L"PRESS SPACE TO RETRY", 275, 350, 250, 20);
}

void GameOverLevel::ProcessKey(int& h, int& v, int& s, double dtime)
{
	if (s == 1) switchTo = 0;
}