//=============================================================================
#include "TextureBank.h"
#include "App.h"
#include <filesystem>
#include <iostream>
#include "Log.h"

//=============================================================================
std::map<std::string, Texture*> TextureBank::TexList;

//=============================================================================
bool TextureBank::Init()
{
	Cleanup();

	SDL_Renderer* mRenderer = App::GetInstance()->GetRenderer();
	if (!mRenderer) return false;


	std::string directoryPath = "res/sprites";
	try
	{
		// Iterate over the files in the directory
		for (const auto& entry : std::filesystem::directory_iterator(directoryPath))
		{
			if (entry.is_regular_file())
			{
				std::string fileName = entry.path().string();
				std::string ID = entry.path().filename().stem().string();
				std::string fileExtension = entry.path().extension().string();
				// Skip all non-png files
				if (fileExtension != ".png") continue;

				//Log("Add Texture : ID = %s : Filename = %s : Ext = %s", ID.c_str(), Filename.c_str(), Ext.c_str());
				AddTexture(mRenderer, ID, fileName);



				LOG_INFO("File: {0}  Extension: {1}", fileName, fileExtension);
			}
		}
	}
	catch (const std::exception& e)
	{
		LOG_CRITICAL("An exception occurred: {0}", e.what());;
		return false;
	}

	return true;
}

//-----------------------------------------------------------------------------
void TextureBank::Cleanup()
{
	if (TexList.size() <= 0) return;

	for (auto& Iterator : TexList)
	{
		Texture* TheTexture = (Texture*)Iterator.second;

		if (TheTexture)
		{
			delete TheTexture;
			TheTexture = NULL;
		}
	}

	TexList.clear();
}

//=============================================================================
void TextureBank::AddTexture(SDL_Renderer* mRenderer, std::string ID, std::string Filename)
{
	if (ID == "") return;

	Texture* NewTexture = new Texture();
	if (NewTexture->Load(mRenderer, Filename) == false)
	{
		LOG_ERROR("Unable to Load Texture: %s", ID.c_str());
		return;
	}

	TexList[ID] = NewTexture;
}

//-----------------------------------------------------------------------------
Texture* TextureBank::Get(std::string ID)
{
	if (TexList.find(ID) == TexList.end()) return 0;

	return TexList[ID];
}

//=============================================================================