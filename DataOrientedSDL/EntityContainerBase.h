#pragma once
#include <SDL_stdinc.h>
#include <vector>


namespace Engine
{
	class EntityContainerBase
	{
	public:
		static Uint8* PositionsY;
		static Uint8* PositionsX;
		static Uint8* Widths;
		static Uint8* Heights;
		static 

		void Add(Uint8 positionY, Uint8 positionX, Uint8 widths, Uint8  height);
		void Remove(Uint8 index);
		void Move(Uint8 index, Uint8 incrementX, Uint8 incrementY);
		void Draw(Uint8 index);

		void ShutDown();
	private:
		static Uint8 indexCounter;
	};
}

