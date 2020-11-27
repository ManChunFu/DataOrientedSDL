#pragma once

#include <EntityContainerBase.h>
#include "EnemyContainer.h"

struct PlayerContainer : public Engine::EntityContainerBase
{
public:
	const short Speed = 300;
	void Move(short inputX, short inputY);
	void CheckCollision(EnemyContainer& enemyContainer);
};

