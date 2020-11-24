#include "EntityContainerBase.h"
#include "Window.h"

namespace Engine
{
	Uint8 EntityContainerBase::indexCounter = 0;

	void Engine::EntityContainerBase::Add(Uint8 positionY, Uint8 positionX, Uint8 width, Uint8 height)
	{
		indexCounter++;
		PositionsY[indexCounter] = positionY;
		PositionsX[indexCounter] = positionX;
		Widths[indexCounter] = width;
		Heights[indexCounter] = height;
	}

	void EntityContainerBase::Remove(Uint8 index)
	{
		PositionsY[index] = NULL;
		PositionsX[index] = NULL;
		Widths[index] = NULL;
		Heights[index] = NULL;
	}

	void EntityContainerBase::Move(Uint8 index, Uint8 incrementX, Uint8 incrementY)
	{
		if (incrementX != 0)
		{
			PositionsX[index] += incrementX;
		}

		if (incrementY != 0)
		{
			PositionsY[index] += incrementY;
		}
	}

	void EntityContainerBase::ShutDown()
	{
		delete PositionsY;
		PositionsY = nullptr;

		delete PositionsX;
		PositionsX = nullptr;

		delete Widths;
		Widths = nullptr;

		delete Heights;
		Heights = nullptr;
	}
	/*void EntityContainerBase::Draw(Uint8 index)
	{

		if (Engine::Window::Renderer)
			SDL_RenderCopy(Engine::Window::Renderer, sprite, &srcRect, &desRect);

	}*/
}
