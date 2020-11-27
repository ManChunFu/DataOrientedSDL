#pragma once

#include <EntityContainerBase.h>
#include "EnemyContainer.h"

struct LaserContainer : public Engine::EntityContainerBase
{
public:
	const short Speed = 800;
	const Uint8 InstantiateOffsetX = 31;
	const Uint8 InstantiateOffsetY = 45;
	void Move(EnemyContainer& enemyContainer);


private:
	bool CheckCollision(short positionY, short positionX, EnemyContainer& enemyContainer);
};

