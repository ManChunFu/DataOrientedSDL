#pragma once
#include <SDL_stdinc.h>
#include <vector>
#include <string>
#include <SDL_image.h>
#include "RenderBase.h"

namespace Engine
{
	struct EntityContainerBase : public RenderBase
	{
	public:
		short* PositionsX;
		short* PositionsY;
		short* Widths;
		short* Heights;
		bool* Usages;

		short MaxScreenX, MaxScreenY;
		short IndexCounter = 0;
		short TextureWidth, TextureHeight = 0;
		short MaxLength;
		SDL_Texture* Sprite;

		void Init(short maxLength, short maxScreenX, short maxScreenY, short textureWidth, short textureHeight, const std::string& path);
		void Add(short positionX, short positionY, short widths, short height);
		void BackToPool(short index);
		SDL_Texture* AddImage(const std::string& path);
		void Render();
		void ShutDown();
		short CheckEntityUsage();
		
	};
}

