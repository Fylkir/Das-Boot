#pragma once
#include <wincodec.h>
#include <d2d1_1.h>
#include "Graphics.h"


class Texture
{
	IWICImagingFactory* imFac;


	wchar_t* _filename;
	ID2D1Bitmap* bmp;
	IWICBitmapDecoder* bmpDec;
	IWICBitmapFrameDecode* wicFrame;
	IWICFormatConverter* wicConv;
	HRESULT hr;

public:
	static Graphics* gfx;
	static void Init(Graphics* graphics);
	Texture(wchar_t* filename);
	~Texture();
	void Draw(float& x, float& y);
};

