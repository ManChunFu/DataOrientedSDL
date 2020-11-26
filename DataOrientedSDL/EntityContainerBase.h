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
		Uint8 _textureWidth, _textureHeight = 0;
		short MaxLength;

		void Init(short maxLength, short maxScreenX, short maxScreenY, Uint8 textureWidth, Uint8 textureHeight);
		short Add(short positionX, short positionY, short widths, short height);
		void Remove(short index);
		void Move(short index, short incrementX, short incrementY);
		SDL_Texture* AddImage(const std::string& path);
		void Render(SDL_Texture* sprite);
		void ShutDown();
		short CheckEntityUsage();
		
	};
}

