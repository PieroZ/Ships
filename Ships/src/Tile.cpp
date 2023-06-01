#include "Tile.h"

Tile::Tile()
{
	mTileSpritesheetX = 0;
	mTileSpritesheetY = 0;
	mTypeId = TILE_TYPE_NONE;
	mCollider = { 0, 0, 0, 0 };

	mTileId = 0;
	mSpriteId = 0;
}

Tile::Tile(int tile_spritesheet_x, int tile_spritesheet_y, int tile_id, int type_id, const SDL_Rect& collider) :
	mTileSpritesheetX(tile_spritesheet_x), mTileSpritesheetY(tile_spritesheet_y), mTileId(tile_id), mTypeId(type_id), mCollider(collider), mSpriteId(0)
{
}
