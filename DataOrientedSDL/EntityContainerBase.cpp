#include "EntityContainerBase.h"
#include "Window.h"
#include <string.h>

namespace Engine
{
	void EntityContainerBase::Init(short maxLength, short maxScreenX, short maxScreenY, short textureWidth, short textureHeight)
	{
		MaxLength = maxLength;
		PositionsX = new short[MaxLength];
		PositionsY = new short[MaxLength];
		Widths = new short[MaxLength];
		Heights = new short[MaxLength];
		Usages = new bool[MaxLength];

		MaxScreenX = maxScreenX;
		MaxScreenY = maxScreenY;

		TextureWidth = textureWidth;
		TextureHeight = textureHeight;

	}

	void EntityContainerBase::Add(short positionX, short positionY, short width, short height)
	{
		if (IndexCounter >= MaxLength)
		{ 
			short unusedIndex = CheckEntityUsage();
			
			if (unusedIndex != -1)
			{
				PositionsX[unusedIndex] = positionX;
				PositionsY[unusedIndex] = positionY;
				Widths[unusedIndex] = width;
				Heights[unusedIndex] = height;
				Usages[unusedIndex] = true;
			}
			else
				return;
		}
		else
		{
			PositionsX[IndexCounter] = positionX;
			PositionsY[IndexCounter] = positionY;
			Widths[IndexCounter] = width;
			Heights[IndexCounter] = height;
			Usages[IndexCounter++] = true;
		}
	}

	short EntityContainerBase::CheckEntityUsage()
	{
		for (short index = 0; index < IndexCounter; index++)
		{
			if (!Usages[index])
				return index;
		}
		return -1;
	}


	void EntityContainerBase::BackToPool(short index)
	{
		Usages[index] = false;
}
	

	SDL_Texture* EntityContainerBase::AddImage(const std::string& path)
	{
		return CreateTexture(path);
	}

	void EntityContainerBase::Render(SDL_Texture* sprite)
	{
		for (Uint16 index = 0; index < IndexCounter; index++)
		{
			if (Usages[index])
				Draw(sprite, { 0, 0, TextureWidth, TextureHeight },
				{ PositionsX[index], PositionsY[index], Widths[index], Heights[index]});
		}
	}


	void EntityContainerBase::ShutDown()
	{
		IndexCounter = 0;

		delete []PositionsX;
		PositionsX = nullptr;

		delete []PositionsY;
		PositionsY = nullptr;

		delete []Widths;
		Widths = nullptr;

		delete []Heights;
		Heights = nullptr;

		delete[]Usages;
		Usages = nullptr;
	}

}
