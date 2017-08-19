#pragma once
#include <d2d1_1.h>
#include <dwrite_1.h>
#include <Windows.h>
#include "Constants.h"


class Graphics
{

	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget;
	ID2D1SolidColorBrush* brush, *blueBrush, *blackBrush, *whiteBrush, *redBrush;
	ID2D1GeometrySink *pSink;
	ID2D1PathGeometry *pathGeometry;
	IDWriteFactory* pDWriteFactory;
	IDWriteTextFormat* pTextFormat;
	wchar_t* wszText;
	UINT32 cTextLength;


public:
	Graphics();
	~Graphics();

	bool Init(HWND windowHandle);
	ID2D1HwndRenderTarget* getRenderTarget() { return renderTarget; };
	void BeginDraw() { renderTarget->BeginDraw(); }
	void EndDraw() { renderTarget->EndDraw(); }
	void ClearScreen(float r, float g, float b);
	void DrawCircle(float x, float y, float radius, float r, float g, float b, float a);
	void DrawObject(float x, float y);
	void DrawBoat(float x, float y);
	void DrawPlayer(float x, float y);
	void DrawTrapezium(float x_bl, float x_br, float x_tl, float x_tr, float y_centre);
	void DrawBlackRectangleFrame(float xbl, float ybl, float width, float height);
	void DrawRedRectangle(float xbl, float ybl, float width, float height);
	void DrawWhiteRectangle(float xbl, float ybl, float width, float height);
	void PrintText(const wchar_t* text, float xbl, float ybl, float width, float height);
};

