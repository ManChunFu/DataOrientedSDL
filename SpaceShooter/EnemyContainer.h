#pragma once

#include <EntityContainerBase.h>

typedef struct EnemyContainer : public Engine::EntityContainerBase
{
	const short Speed = 200;
	void Move();
	short RandomPositionX();
}EnemyContainer;

