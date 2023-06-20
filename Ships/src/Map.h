#pragma once

#include <vector>
#include "Tile.h"
#include <string>

class Map
{
private:
	std::vector<Tile> mTiles;
	std::string mSpritesheet;
	int mTilesPerRow = 0;
	int mTilesPerColumn = 0;

	int mMapWidth = 0;
	int mMapHeight = 0;
	const int TILE_SIZE = 64;

protected:
	void SetLevelSize();
public:
	Map();
	bool OnLoad(const std::string& filename, const std::string& spritesheet);
	int GetIdFromCoordinates(int x, int y);
	void OnRender(int x, int y);
	void AddToRenderQueue(int x, int y);
	void GetLevelSize(int& w, int& h);
};

