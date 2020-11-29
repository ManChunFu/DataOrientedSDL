#pragma once

#include <EntityContainerBase.h>
#include "EnemyContainer.h"

typedef struct LaserContainer : public Engine::EntityContainerBase
{
	const short Speed = 800;
	const Uint8 InstantiateOffsetX = 31;
	const Uint8 InstantiateOffsetY = 45;
	void Move(EnemyContainer& enemies);
	bool CheckCollision(short positionY, short positionX, EnemyContainer& enemies);

}LaserContainer;

