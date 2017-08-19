#pragma once
#include "GameObject.h"
#include <string>
class ScoreIndicator :
	public GameObject
{
	int _score;

public:
	ScoreIndicator();
	~ScoreIndicator();
	void Update(int score);
	void Render();
};

