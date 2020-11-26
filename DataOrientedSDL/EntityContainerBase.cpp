#include "EntityContainerBase.h"
#include "Window.h"
#include <string.h>

namespace Engine
{
	SDL_Texture* EntityContainerBase::SpriteTexture;

	void EntityContainerBase::Init(short maxLength, short maxScreenX, short maxScreenY, Uint8 textureWidth, Uint8 textureHeight)
	{
		PositionsX = new short[maxLength];
		PositionsY = new short[maxLength];
		Widths = new short[maxLength];
		Heights = new short[maxLength];

		_maxScreenX = maxScreenX;
		_maxScreenY = maxScreenY;

		_textureWidth = textureWidth;
		_textureHeight = textureHeight;
	}

	void Engine::EntityContainerBase::Add(short positionX, short positionY, short width, short height)
	{
		PositionsX[_indexCounter] = positionX;
		PositionsY[_indexCounter] = positionY;
		Widths[_indexCounter] = width;
		Heights[_indexCounter++] = height;
	}

	void EntityContainerBase::Remove(short index)
	{
		PositionsY[index] = NULL;
		PositionsX[index] = NULL;
		Widths[index] = NULL;
		Heights[index] = NULL;
	}

	void EntityContainerBase::Move(short index, short incrementX, short incrementY)
	{
		if (incrementX != 0)
		{
			short newX = PositionsX[index] + incrementX;
			if (newX > 0 && newX < _maxScreenX - Widths[index])
				PositionsX[index] = newX;
		}

		if (incrementY != 0)
		{
			short newY = PositionsY[index] + incrementY;
			if (newY > 0 && newY < _maxScreenY - Heights[index])
				PositionsY[index] = newY;
		}
	}

	void EntityContainerBase::AddImage(const std::string& path)
	{
		SpriteTexture = CreateTexture(path);
	}

	void EntityContainerBase::Render()
	{
		for (Uint16 index = 0; index < _indexCounter; index++)
		{
			Draw(SpriteTexture, { 0, 0, _textureWidth, _textureHeight },
				{ PositionsX[index], PositionsY[index], Widths[index], Heights[index]});
		}
	}


	void EntityContainerBase::ShutDown()
	{
		SDL_DestroyTexture(SpriteTexture);
		SpriteTexture = nullptr;

		delete PositionsX;
		PositionsX = nullptr;

		delete PositionsY;
		PositionsY = nullptr;

		delete Widths;
		Widths = nullptr;

		delete Heights;
		Heights = nullptr;
	}
}
