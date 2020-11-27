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

		void Init(short maxLength, short maxScreenX, short maxScreenY, short textureWidth, short textureHeight);
		void Add(short positionX, short positionY, short widths, short height);
		void BackToPool(short index);
		SDL_Texture* AddImage(const std::string& path);
		void Render(SDL_Texture* sprite);
		void ShutDown();
		short CheckEntityUsage();
		
	};
}

