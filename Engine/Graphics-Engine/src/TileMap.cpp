#include "TileMap.h"

TileMap::TileMap(int _width, int _height, float _tileWidth, float _tileHeight, float initialX, float initialY, Sprite* baseSprite, Renderer* renderer)
{
	width = _width;
	height = _height;
	tileWidth = _tileWidth;
	tileHeight = _tileHeight;
	tiles = new Tile*[width * height];

	for (int y = 0; y < height; y++)
	{
		float tileY = initialY + tileHeight * y;

		for (int x = 0; x < width; x++)
		{
			float tileX = initialX + tileWidth * x;

			tiles[y * width + x] = new Tile(tileX, tileY, tileWidth, tileHeight, true, baseSprite, renderer);
		}
	}
}

TileMap::~TileMap() {}

int TileMap::getWidth()
{
	return width;
}

int TileMap::getHeight()
{
	return height;
}

float TileMap::getTileWidth()
{
	return tileWidth;
}

float TileMap::getTileHeight()
{
	return tileHeight;
}

Tile* TileMap::getTile(int x, int y)
{
	return tiles[y * width + x];
}

void TileMap::draw(Renderer* renderer)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			Tile* tile = tiles[y * width + x];
			tile->draw();
		}
	}
}