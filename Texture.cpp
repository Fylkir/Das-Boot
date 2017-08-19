#include "Texture.h"

//IWICImagingFactory* Texture::imFac = NULL;
Graphics* Texture::gfx;
void Texture::Init(Graphics* graphics)
{
	//CoInitialize(NULL);

	//HRESULT res = CoCreateInstance(
	//	CLSID_WICImagingFactory,
	//	NULL,
	//	CLSCTX_INPROC_SERVER,
	//	IID_IWICImagingFactory,
	//	(LPVOID*)&imFac
	//);



			// I GET THIS MESSAGE
	//if (res == S_OK) MessageBox(NULL, L"Error creating the Image Factory", L"ERROR", MB_OK);
	gfx = graphics;

}


Texture::Texture(wchar_t* filename)
{
	_filename = filename;
	bmp = NULL;
	CoInitialize(NULL);
	HRESULT res = CoCreateInstance(
		CLSID_WICImagingFactory,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IWICImagingFactory,
		(LPVOID*)&imFac
	);
	hr = imFac->CreateDecoderFromFilename(
		filename,
		NULL,
		GENERIC_READ,
		WICDecodeMetadataCacheOnLoad,
		&bmpDec
	);
	if (hr != S_OK) throw - 1;

	hr = bmpDec->GetFrame(0, &wicFrame);

	if (hr != S_OK) throw - 1;

	hr = imFac->CreateFormatConverter(&wicConv);

	if (hr != S_OK) throw - 1;

	hr = wicConv->Initialize(
		wicFrame,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		NULL,
		0.0,
		WICBitmapPaletteTypeCustom
	);

	//if (hr != S_OK) MessageBox(NULL, L"Error creating the Image Factory", L"ERROR", MB_OK);;

	hr = gfx->getRenderTarget()->CreateBitmapFromWicBitmap(
		wicConv,
		NULL,
		&bmp
	);



	if (hr != S_OK) throw - 1;
	
}


Texture::~Texture()
{
	if(bmp) bmp->Release();
	if(bmpDec) bmpDec->Release();
	if(wicFrame) wicFrame->Release();
	if(wicConv) wicConv->Release();
}

void Texture::Draw(float& x, float& y)
{
	gfx->getRenderTarget()->DrawBitmap(
		bmp,
		D2D1::RectF(x - bmp->GetSize().width / 2.,
			y - bmp->GetSize().height / 2.,
			x + bmp->GetSize().width / 2.,
			y + bmp->GetSize().height / 2.
		),
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF(0.0F, 0.0F,
			bmp->GetSize().width,
			bmp->GetSize().height)
	);
	
}
