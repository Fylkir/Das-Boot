#include "GameController.h"



GameController::GameController()
{
}


GameController::~GameController()
{
}

GameLevel* GameController::currentLevel;
bool GameController::Loading;
std::vector<GameLevel*> GameController::_levels;
Timer* GameController::timer;



void GameController::Init()
{
	Loading = true;
	currentLevel = 0;
}



void GameController::LoadLevels(std::vector<GameLevel*> levels)
{
	timer = new Timer();
	Loading = true;
	_levels = levels;
	currentLevel = _levels[0];
	currentLevel->Load();
	Loading = false;
}
void GameController::SwitchLevel(int a)
{
	Loading = true;
	currentLevel->Unload();
	//delete currentLevel;
	currentLevel = _levels[a];
	currentLevel->Load();
	timer->Reset();
	Loading = false;
}
void GameController::Render()
{
	if (Loading) return;
	currentLevel->Render();
}
void GameController::Update()
{
	if (Loading) return;
	timer->Update();
	if(currentLevel->switchTo <0) currentLevel->Update(timer->GetTimeTotal(), timer->GetTimeDelta());
	else SwitchLevel(currentLevel->switchTo);
}

void GameController::ProcessKey(int& h, int& v, int& s)
{
	currentLevel->ProcessKey(h, v, s, timer->GetTimeDelta());
}