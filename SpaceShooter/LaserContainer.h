#pragma once

#include <EntityContainerBase.h>
#include "EnemyContainer.h"

class Explosion;

typedef struct LaserContainer : public Engine::EntityContainerBase
{
	const short Speed = 800;
	const Uint8 InstantiateOffsetX = 31;
	const Uint8 InstantiateOffsetY = 45;
	const float SpriteIndentOffset = 0.8f;
	void Move(EnemyContainer& enemies, Explosion* explo);
	bool CheckCollision(short positionY, short positionX, EnemyContainer& enemyContainer, Explosion* explo);
}LaserContainer;

