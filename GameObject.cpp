#include "GameObject.h"



Graphics* GameObject::gfx;
void GameObject::Init(Graphics* graphics) { gfx = graphics; }

void GameObject::Render()
{
	gfx->DrawObject(_x, _y);
}

GameObject::~GameObject() {};

float GameObject::getY()
{
	return _y;
}

float GameObject::getX()
{
	return _x;
}