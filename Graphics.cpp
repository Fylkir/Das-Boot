#include "Graphics.h"



Graphics::Graphics()
{
	factory = NULL;
	renderTarget = NULL;
	pDWriteFactory = NULL;
	pTextFormat = NULL;
	pSink = NULL;
	pathGeometry = NULL;
	brush = NULL;
	blueBrush = NULL;
	blackBrush = NULL;
	redBrush = NULL;
	whiteBrush = NULL;

}


Graphics::~Graphics()
{
	if (factory) factory->Release();
	if (renderTarget) renderTarget->Release();
	if (brush) brush->Release();
	if (blueBrush) blueBrush->Release();
	if (pDWriteFactory) pDWriteFactory->Release();
	if (pTextFormat) pTextFormat->Release();
}

bool Graphics::Init(HWND windowHandle)
{

	HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
	if (res != S_OK) return false;
	static const WCHAR msc_fontName[] = L"Verdana";
	static const float msc_fontSize = 50;

	RECT rect;
	GetClientRect(windowHandle, &rect);

	res = factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(windowHandle, D2D1::SizeU(rect.right, rect.bottom)),
		&renderTarget);

	if (res != S_OK) return false;

	res = DWriteCreateFactory(
		DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(pDWriteFactory),
		reinterpret_cast<IUnknown **>(&pDWriteFactory)
	);

	res = pDWriteFactory->CreateTextFormat(
		L"Courier New",                // Font family name.
		NULL,                       // Font collection (NULL sets it to use the system font collection).
		DWRITE_FONT_WEIGHT_REGULAR,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		20.0f,
		L"en-us",
		&pTextFormat
	);

	if (SUCCEEDED(res))
	{
		res = pTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
	}

	if (SUCCEEDED(res))
	{
		res = pTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
	}


	res = renderTarget->CreateSolidColorBrush(D2D1::ColorF(0.5, 0.0, 0.0, 1), &brush);
	res = renderTarget->CreateSolidColorBrush(D2D1::ColorF(0.0, 0.0, 0.7, 1), &blueBrush);
	res = renderTarget->CreateSolidColorBrush(D2D1::ColorF(0.0, 0.0, 0.0, 1), &blackBrush);
	res = renderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0, 1.0, 1.0, 1), &whiteBrush);
	res = renderTarget->CreateSolidColorBrush(D2D1::ColorF(0.7, 0.0, 0.0, 1), &redBrush);

	if (res != S_OK) return false;

	return true;
}

void Graphics::ClearScreen(float r, float g, float b)
{
	renderTarget->Clear(D2D1::ColorF(r,g,b));
}
void Graphics::DrawCircle(float x, float y, float radius, float r, float g, float b, float a)
{
	brush->SetColor(D2D1::ColorF(r, g, b, a));
	renderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius), brush, 3.0f);
}

void Graphics::DrawObject(float x, float y)
{
	renderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), 5., 5.), brush, 3.0f);
}

void Graphics::DrawBoat(float x, float y)
{
	renderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), 20., 10.), brush, 3.0f);
}
void Graphics::DrawPlayer(float x, float y)
{
	renderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), 10., 20.), brush, 3.0f);
}


/****RYSUJ TRAPEZ**********/
//x_bl - lewy dolny rog
//x_br - prawy dolny rog
//x_tl - lewy gorny rog
//x_tr - prawy gorny rog
//y_center - wspolrzedna y srodka trapezu
// WYSOKOSC JEST STALA I WYNOSI 200 px

void Graphics::DrawTrapezium(float x_bl, float x_br, float x_tl, float x_tr, float y_centre)
{
	HRESULT hr = factory->CreatePathGeometry(&pathGeometry);

	if (SUCCEEDED(hr))
	{
		// Write to the path geometry using the geometry sink.
		pSink = NULL;
		hr = pathGeometry->Open(&pSink);

		if (SUCCEEDED(hr))
		{
			pSink->SetFillMode(D2D1_FILL_MODE_WINDING);
			pSink->BeginFigure(
				D2D1::Point2F(x_bl, y_centre + 800./RIV_SEGMENTS/2),
				D2D1_FIGURE_BEGIN_FILLED
			);

			pSink->AddLine(D2D1::Point2F(x_br, y_centre + 800. / RIV_SEGMENTS / 2));

			pSink->AddLine(D2D1::Point2F(x_tr, y_centre - 800. / RIV_SEGMENTS / 2));

			pSink->AddLine(D2D1::Point2F(x_tl, y_centre - 800. / RIV_SEGMENTS / 2));

			pSink->EndFigure(D2D1_FIGURE_END_CLOSED);

			hr = pSink->Close();

			renderTarget->FillGeometry(pathGeometry, blueBrush);
			pathGeometry->Release();
			pSink->Release();
		}
	}
}

void Graphics::DrawBlackRectangleFrame(float xbl, float ybl, float width, float height)
{
	D2D1_RECT_F rectangle1 = D2D1::RectF(xbl, ybl + height, xbl + width, ybl);
	renderTarget->DrawRectangle(rectangle1, blackBrush,3.0f);
}
void Graphics::DrawRedRectangle(float xbl, float ybl, float width, float height)
{
	D2D1_RECT_F rectangle1 = D2D1::RectF(xbl, ybl + height, xbl + width, ybl);
	renderTarget->FillRectangle(rectangle1, redBrush);
}

void Graphics::DrawWhiteRectangle(float xbl, float ybl, float width, float height)
{
	D2D1_RECT_F rectangle1 = D2D1::RectF(xbl, ybl + height, xbl + width, ybl);
	renderTarget->FillRectangle(rectangle1, whiteBrush);
}

void Graphics::PrintText(const wchar_t* text, float xbl, float ybl, float width, float height)
{
	D2D1_RECT_F layoutRect = D2D1::RectF(xbl, ybl + height, xbl + width, ybl);
	cTextLength = (UINT32)wcslen(text);

	renderTarget->DrawText(
		text,        // The string to render.
		cTextLength,    // The string's length.
		pTextFormat,    // The text format.
		layoutRect,       // The region of the window where the text will be rendered.
		whiteBrush     // The brush used to draw the text.
	);

}

