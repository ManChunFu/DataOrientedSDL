#pragma once

#include <EntityContainerBase.h>
#include "EnemyContainer.h"

class UI;
typedef struct PlayerContainer : public Engine::EntityContainerBase
{
	const short Speed = 300;
	void Move(short inputX, short inputY);
	void CheckCollision(EnemyContainer& enemyContainer, UI* ui);
	bool IsDead = false;
	Uint8 currentLives = 3;
	void Damage(UI* ui);

} PlayerContainer;

