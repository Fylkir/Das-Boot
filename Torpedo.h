#pragma once
#include "GameObject.h"
class Torpedo :
	public GameObject
{

private:
	static Texture* _tex;
	bool _isShot;
public:

	Torpedo(float x, float y, float t0);
	~Torpedo();

	void Move(const float& time);
	void Update(const float& time);
	bool IsOutOfScreen();
	void Render();
	static void LoadTexture();
	static void UnloadTexture();
	void SetAsShot();
	bool IsShot();


};

