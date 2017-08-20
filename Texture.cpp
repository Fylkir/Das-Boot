#include "Texture.h"


Graphics* Texture::gfx;
void Texture::Init(Graphics& graphics)
{

	gfx = &graphics;
}


Texture::Texture(wchar_t* filename)
{
	_filename = filename;
	_bmp_p = NULL;
	CoInitialize(NULL);
	HRESULT res = CoCreateInstance(
		CLSID_WICImagingFactory,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IWICImagingFactory,
		(LPVOID*)&_imFac_p
	);
	_hr = _imFac_p->CreateDecoderFromFilename(
		filename,
		NULL,
		GENERIC_READ,
		WICDecodeMetadataCacheOnLoad,
		&_bmpDec_p
	);
	if (_hr != S_OK) throw - 1;

	_hr = _bmpDec_p->GetFrame(0, &_wicFrame_p);

	if (_hr != S_OK) throw - 1;

	_hr = _imFac_p->CreateFormatConverter(&_wicConv_p);

	if (_hr != S_OK) throw - 1;

	_hr = _wicConv_p->Initialize(
		_wicFrame_p,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		NULL,
		0.0,
		WICBitmapPaletteTypeCustom
	);

	if (_hr != S_OK) MessageBox(NULL, L"Error creating the Image Factory", L"ERROR", MB_OK);;

	
		_hr = gfx->getRenderTarget()->CreateBitmapFromWicBitmap(
			_wicConv_p,
			NULL,
			&_bmp_p
		);




	if (_hr != S_OK) throw - 1;
	
}


Texture::~Texture()
{
	if(_bmp_p) _bmp_p->Release();
	if(_bmpDec_p) _bmpDec_p->Release();
	if(_wicFrame_p) _wicFrame_p->Release();
	if(_wicConv_p) _wicConv_p->Release();
}

void Texture::Draw(float& x, float& y)
{
		gfx->getRenderTarget()->DrawBitmap(
			_bmp_p,
			D2D1::RectF(x - _bmp_p->GetSize().width / 2.,
				y - _bmp_p->GetSize().height / 2.,
				x + _bmp_p->GetSize().width / 2.,
				y + _bmp_p->GetSize().height / 2.
			),
			1.0f,
			D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
			D2D1::RectF(0.0F, 0.0F,
				_bmp_p->GetSize().width,
				_bmp_p->GetSize().height)
		);
	
}
