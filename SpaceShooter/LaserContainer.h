#pragma once

#include <EntityContainerBase.h>

struct LaserContainer : public Engine::EntityContainerBase
{
public:
	SDL_Texture* Sprite;
	const short Speed = 800;
	void Move();
};

