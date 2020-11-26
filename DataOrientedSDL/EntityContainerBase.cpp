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

		MaxScreenX = maxScreenX;
		MaxScreenY = maxScreenY;

		_textureWidth = textureWidth;
		_textureHeight = textureHeight;

	}

	short EntityContainerBase::Add(short positionX, short positionY, short width, short height)
	{
		if (IndexCounter >= MaxLength)
			return -1;


		PositionsX[IndexCounter] = positionX;
		PositionsY[IndexCounter] = positionY;
		Widths[IndexCounter] = width;
		Heights[IndexCounter] = height;

		return IndexCounter++;
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


	void EntityContainerBase::Remove(short index)
	{
		PositionsX[index] = NULL;
		PositionsY[index] = NULL;
		Widths[index] = NULL;
		Heights[index] = NULL;
	}

	void EntityContainerBase::Move(short index, short incrementX, short incrementY)
	{
		
		/*if (incrementX != 0)
		{
			short newX = PositionsX[index] + incrementX;
			short currentWidth = Widths[index];
			short rigthBoarder = _maxScreenX - currentWidth;

			if (newX > 0 && newX < rigthBoarder)
				PositionsX[index] = newX;
			else
				BoundaryBehavior(index, newX, NULL, currentWidth, rigthBoarder);
		}

		if (incrementY != 0)
		{
			short newY = PositionsY[index] + incrementY;
			if (newY > 0 && newY < _maxScreenY - Heights[index])
				PositionsY[index] = newY;
			else
				BoundaryBehavior(index, NULL, newY, currentWidth, rigthBoarder);
		}*/
	}

	SDL_Texture* EntityContainerBase::AddImage(const std::string& path)
	{
		return CreateTexture(path);
	}

	void EntityContainerBase::Render(SDL_Texture* sprite)
	{
		for (Uint16 index = 0; index < IndexCounter; index++)
		{
			Draw(sprite, { 0, 0, _textureWidth, _textureHeight },
				{ PositionsX[index], PositionsY[index], Widths[index], Heights[index]});
		}
	}


	void EntityContainerBase::ShutDown()
	{
		delete []PositionsX;
		PositionsX = nullptr;

		delete []PositionsY;
		PositionsY = nullptr;

		delete []Widths;
		Widths = nullptr;

		delete []Heights;
		Heights = nullptr;
	}

}
