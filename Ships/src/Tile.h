#pragma once

#include <SDL.h>


enum
{
	TILE_TYPE_NONE = 0,

	TILE_TYPE_NORMAL,
	TILE_TYPE_BLOCK
};

class Tile
{
public:
	//int     TileID;
	int     mTileSpritesheetX;
	int     mTileSpritesheetY;

	int		mTileId;

	// This value corresponds to lua tileset id value
	// this max value is sum of all counts of loaded tilesets elements
	int		mSpriteId;
	int     mTypeId;

	SDL_Rect mCollider;
	//CAnimation m_tile_animation;

public:
	Tile();
	Tile(int tile_spritesheet_x, int tile_spritesheet_y, int tile_id, int type_id, const SDL_Rect& collider);
};

