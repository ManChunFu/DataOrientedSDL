#pragma once

#include <EntityContainerBase.h>
#include "EnemyContainer.h"

class UI;
class Explosion;

typedef struct PlayerContainer : public Engine::EntityContainerBase
{
	const short Speed = 300;
	const float SpriteIndentOffset = 0.8f; // for making collision more real
	Uint8 currentLives = 3;
	SDL_Texture** TurningSprites = nullptr;
	SDL_Texture** FireSprites = nullptr;
	const Uint8 TurningSpritesLength = 8;
	const Uint8 FireSpritesLength = 13;
	bool IsDead = false;
	void Initilize();
	void Move(short inputX, short inputY);
	void CheckCollision(EnemyContainer& enemyContainer, UI* ui, Explosion* explo);
	void Damage(UI* ui, Explosion* explo);
	void RenderMovement(); 
	void ShutDownAll();
	enum MoveDirections
	{
		Left,
		Right,
		None
	}; 
	MoveDirections Directions = MoveDirections::None; // for animation purpose
	Uint8 FrameTime = 0;
	Uint8 FrameRate = 2;
} PlayerContainer;

