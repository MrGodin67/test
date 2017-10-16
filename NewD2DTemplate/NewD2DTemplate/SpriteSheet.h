#pragma once
#include "includes.h"
#include "D2D1Texture.h"

#include "Rect.h"
class SpriteSheet
{
	float width;
	float height;
	float clipWidth;
	float clipHeight;
	int columns;
	std::unique_ptr<D2D1Texture> texture;
public:
	SpriteSheet(std::wstring filename,float clipWidth,float clipHeight);
	~SpriteSheet();
	RectF GetClippedImage(const int& index, RectF offsets = {0.0f,0.0f,0.0f,0.0f});
	int Columns() { return columns; }
	float Width() { return width; }
	float Height() { return height; }

	ID2D1Bitmap* GetTexture();
};
