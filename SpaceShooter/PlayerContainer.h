#pragma once

#include <EntityContainerBase.h>
#include "EnemyContainer.h"

class UI;
typedef struct PlayerContainer : public Engine::EntityContainerBase
{
	const short Speed = 300;
	Uint8 currentLives = 3;
	SDL_Texture** TurningSprites = nullptr;
	bool IsDead = false;
	void Initilize();
	void Move(short inputX, short inputY);
	void CheckCollision(EnemyContainer& enemyContainer, UI* ui);
	void Damage(UI* ui);
	void RenderMovement();
	void ShutDownAll();

	enum MoveDirections
	{
		Left,
		Right,
		None
	};
	MoveDirections Directions = MoveDirections::None;

} PlayerContainer;

