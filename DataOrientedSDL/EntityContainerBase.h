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
		static SDL_Texture* SpriteTexture;

		void Init(short maxLength, short maxScreenX, short maxScreenY, Uint8 textureWidth, Uint8 textureHeight);
		void Add(short positionX, short positionY, short widths, short height);
		void Remove(short index);
		void Move(short index, short incrementX, short incrementY);
		void AddImage(const std::string& path);
		void Render();
		void ShutDown();
	private:
		short _indexCounter = 0;
		short _maxScreenX, _maxScreenY = 0;
		Uint8 _textureWidth, _textureHeight = 0;
		
	};
}

