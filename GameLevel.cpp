#include "GameLevel.h"



GameLevel::GameLevel()
{
}


GameLevel::~GameLevel()
{
}


Graphics* GameLevel::gfx;

void GameLevel::Init(Graphics* graphics) { gfx = graphics; }