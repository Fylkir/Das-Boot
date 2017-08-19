#include "ScoreIndicator.h"



ScoreIndicator::ScoreIndicator()
{
	_x = 50;
	_y = 550;
	_x0 = 650;
	_y0 = 550;
	_score = NULL;
}


ScoreIndicator::~ScoreIndicator()
{
}

void ScoreIndicator::Update(int score)
{
	_score = score;
}
void ScoreIndicator::Render()
{
	
	
	gfx->PrintText(L"SCORE:", _x, _y - 40, 80, 20);
	gfx->PrintText(std::to_wstring(_score).c_str() , _x, _y, 50, 20);

}