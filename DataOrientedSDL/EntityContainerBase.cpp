#include "EntityContainerBase.h"
#include "Window.h"

namespace Engine
{
	void Engine::EntityContainerBase::Add(Uint8 positionY, Uint8 positionX, Uint8 width, Uint8 height)
	{
		PositionsY.push_back(positionY);
		PositionsX.push_back(positionX);
		Widths.push_back(width);
		Heights.push_back(height);
	}

	void EntityContainerBase::Remove(Uint8 index)
	{
		PositionsY.erase(PositionsY.begin() + index);
		PositionsX.erase(PositionsX.begin() + index);
		Widths.erase(Widths.begin() + index);
		Heights.erase(Heights.begin() + index);
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
	/*void EntityContainerBase::Draw(Uint8 index)
	{

		if (Engine::Window::Renderer)
			SDL_RenderCopy(Engine::Window::Renderer, sprite, &srcRect, &desRect);

	}*/
}
