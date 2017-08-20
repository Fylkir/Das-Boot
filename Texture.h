#pragma once
#include <wincodec.h>
#include <d2d1_1.h>
#include "Graphics.h"


class Texture
{
private:
	IWICImagingFactory* _imFac_p;
	wchar_t* _filename;
	ID2D1Bitmap* _bmp_p;
	IWICBitmapDecoder* _bmpDec_p;
	IWICBitmapFrameDecode* _wicFrame_p;
	IWICFormatConverter* _wicConv_p;
	HRESULT _hr;
	

public:

	static Graphics* gfx;
	static void Init(Graphics& graphics);

	Texture(wchar_t* filename);
	Texture() {};
	~Texture();
	void Draw(float& x, float& y);
};

