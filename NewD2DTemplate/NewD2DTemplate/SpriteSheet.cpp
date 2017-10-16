#include "SpriteSheet.h"
#include "Locator.h"
SpriteSheet::SpriteSheet(std::wstring filename, float clipWidth, float clipHeight)
	:clipWidth(clipWidth),clipHeight(clipHeight)
{
	texture = std::make_unique<D2D1Texture>(Locator::RenderTarget, filename);
	assert(texture);
	width = (float)texture->Width();
	height = (float)texture->Height();
	columns = (int)(width / clipWidth);
}

SpriteSheet::~SpriteSheet()
{
}

RectF SpriteSheet::GetClippedImage(const int & index, RectF offsets)
{
	int col = index % columns;
	int row = index / columns;
	float left = (float)((col*clipWidth) + offsets.left);
	float top = (float)((row*clipWidth) + offsets.top);
	float right = (float)((col*clipWidth) + (clipWidth + offsets.right));
	float bottom = (float)((row*clipWidth) + (clipWidth + offsets.bottom));
	return RectF(left,top,right,bottom);
}

ID2D1Bitmap * SpriteSheet::GetTexture()
{
	return texture->GetBitmap();
}
