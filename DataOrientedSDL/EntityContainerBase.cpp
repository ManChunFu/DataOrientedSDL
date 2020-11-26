#include "EntityContainerBase.h"
#include "Window.h"
#include <string.h>

namespace Engine
{
	void EntityContainerBase::Init(short maxLength, short maxScreenX, short maxScreenY, Uint8 textureWidth, Uint8 textureHeight)
	{
		MaxLength = maxLength;
		PositionsX = new short[MaxLength];
		PositionsY = new short[MaxLength];
		Widths = new short[MaxLength];
		Heights = new short[MaxLength];
		Usages = new bool[MaxLength];

		MaxScreenX = maxScreenX;
		MaxScreenY = maxScreenY;

		_textureWidth = textureWidth;
		_textureHeight = textureHeight;

	}

	void EntityContainerBase::Add(short positionX, short positionY, short width, short height)
	{
		if (IndexCounter >= MaxLength)
		{ 
			short unusedIndex = CheckEntityUsage();
			
 			PositionsX[unusedIndex] = positionX;
			PositionsY[unusedIndex] = positionY;
			Widths[unusedIndex] = width;
			Heights[unusedIndex] = height;
			Usages[unusedIndex] = true;
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
				Draw(sprite, { 0, 0, _textureWidth, _textureHeight },
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
