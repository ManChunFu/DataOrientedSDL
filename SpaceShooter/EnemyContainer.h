#pragma once

#include <EntityContainerBase.h>

struct EnemyContainer : public Engine::EntityContainerBase
{
public:
	SDL_Texture* Sprite;
	const short Speed = 300;

	void Move();

};

