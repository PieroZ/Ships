#include <fstream>
#include <sstream>

#include "TextureBank.h"
#include "Map.h"
#include "Log.h"



Map::Map()
{
}

bool Map::OnLoad(const std::string& filename, const std::string& spritesheet)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		LOG_ERROR("Unable to open map filename {0}!", filename);
		return false;
	}

    mSpritesheet = spritesheet;

	std::string line;
	std::vector<std::string> valuesPerRow;
	int row = 0;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string value;

        // Store the values in each row
        while (iss >> value)
        {
            valuesPerRow.push_back(value);
        }

        // Check the number of values per row
        if (row == 0)
        {
            mTilesPerRow = valuesPerRow.size();
        }
        else if (valuesPerRow.size() != mTilesPerRow)
        {
            // Handle mismatched values per row error
            LOG_ERROR("Mismatched values per row in {0}", filename);
            return false;
        }

        // Process the values and fill the Tile vector
        for (const std::string& val : valuesPerRow)
        {
            Tile tile;
            std::istringstream tileIss(val);
            char delimiter;
            tileIss >> tile.mSpriteId >> delimiter >> tile.mTypeId;
            mTiles.push_back(tile);
        }

        // Clear the values for the next row
        valuesPerRow.clear();
        ++row;
    }

    // Set the number of tiles per column
    mTilesPerColumn = row;
    return true;
}

int Map::GetIdFromCoordinates(int x, int y)
{
    if (mTilesPerRow == 0 || mTilesPerColumn == 0)
    {
        LOG_INFO("Unable to determine tile id if mTilesPerColumn or mTilesPerRow is equal to 0");
        return -1;
    }
    int xId = x / TILE_SIZE;
    int yId = mTilesPerRow * (y / TILE_SIZE);

    int id = xId + yId;

    LOG_TRACE("id = {0}", id);
    return id;
}

void Map::OnRender(int x, int y)
{
    for (int mY = 0; mY < mTilesPerColumn; mY++)
    {
        for (int mX = 0; mX < mTilesPerRow; mX++)
        {
            int vectorId = mX + mY * mTilesPerColumn;
            int screenX = mX * TILE_SIZE;
            int screenY = mY * TILE_SIZE;

            int spriteX = mTiles[vectorId].mSpriteId * TILE_SIZE;
            TextureBank::Get(mSpritesheet)->RenderScaled(screenX, screenY, TILE_SIZE, TILE_SIZE, spriteX, 0, TILE_SIZE, TILE_SIZE);
        }
    }
}

void Map::AddToRenderQueue(int x, int y)
{
    for (int mY = 0; mY < mTilesPerColumn; mY++)
    {
        for (int mX = 0; mX < mTilesPerRow; mX++)
        {
            int vectorId = mX + mY * mTilesPerRow;
            int screenX = mX * TILE_SIZE;
            int screenY = mY * TILE_SIZE;

            int spritesPerRowInSpritesheet = TextureBank::Get(mSpritesheet)->GetWidth() / TILE_SIZE;
            int spriteX = (mTiles[vectorId].mSpriteId % spritesPerRowInSpritesheet) * TILE_SIZE;

            int spriteY = (mTiles[vectorId].mSpriteId / spritesPerRowInSpritesheet) * TILE_SIZE;
            TextureBank::Get(mSpritesheet)->AddToRenderQueue(screenX, screenY, TILE_SIZE, TILE_SIZE, spriteX, spriteY, TILE_SIZE, TILE_SIZE, 0);
        }
    }
}
