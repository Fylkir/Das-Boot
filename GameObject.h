#pragma once
#include "Graphics.h"
#include "Texture.h"


class GameObject
{
protected:
	static Graphics* gfx;
	float _x, _y, _x0, _y0, _t0=0.; //WSPOLRZEDNE PUNKTU REFERENCYJNEGO OBIEKTU

public:
	static void Init(Graphics& graphics);

	virtual ~GameObject();


	//virtual void Update(float& time)=0;


	virtual void Render(); //WYSWIETL
	
	float getX();
	float getY();

};

