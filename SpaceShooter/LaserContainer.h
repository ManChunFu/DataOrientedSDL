#pragma once

#include <EntityContainerBase.h>

struct LaserContainer : public Engine::EntityContainerBase
{
public:
	Uint8 IndexID;
	SDL_Texture* Sprite;
	const short Speed = 10;
	void Move();
};

