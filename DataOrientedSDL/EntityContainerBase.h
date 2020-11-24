#pragma once
#include <SDL_stdinc.h>
#include <vector>


namespace Engine
{
	class EntityContainerBase
	{
	public:
		static std::vector<Uint8> PositionsY;
		static std::vector<Uint8> PositionsX;
		static std::vector<Uint8> Widths;
		static std::vector<Uint8> Heights;

		void Add(Uint8 positionY, Uint8 positionX, Uint8 widths, Uint8  height);
		void Remove(Uint8 index);
		void Move(Uint8 index, Uint8 incrementX, Uint8 incrementY);
		void Draw(Uint8 index);
	};
}

