#include "PlayerContainer.h"
#include <GameTime.h>
#include "UI.h"
#include "Explosion.h"

#pragma warning(disable: 4244)
#pragma warning(disable: 26812)

void PlayerContainer::Initilize()
{
	Init(1, 1400, 900, 70, 91, "Assets/Player/Left1.png");
	Add(700, 800, TextureWidth, TextureHeight);
	TurningSprites = new SDL_Texture* [TurningSpritesLength]
	{
		CreateTexture("Assets/Player/Left1.png"),
		CreateTexture("Assets/Player/Left2.png"),
		CreateTexture("Assets/Player/Left3.png"),
		CreateTexture("Assets/Player/Left4.png"),
		CreateTexture("Assets/Player/Left5.png"),
		CreateTexture("Assets/Player/Left6.png"),
		CreateTexture("Assets/Player/Left7.png"),
		CreateTexture("Assets/Player/Left8.png")
	};
	FireSprites = new SDL_Texture * [FireSpritesLength]
	{
		CreateTexture("Assets/Player/Fire1.png"),
		CreateTexture("Assets/Player/Fire2.png"),
		CreateTexture("Assets/Player/Fire3.png"),
		CreateTexture("Assets/Player/Fire4.png"),
		CreateTexture("Assets/Player/Fire5.png"),
		CreateTexture("Assets/Player/Fire6.png"),
		CreateTexture("Assets/Player/Fire7.png"),
		CreateTexture("Assets/Player/Fire8.png"),
		CreateTexture("Assets/Player/Fire9.png"),
		CreateTexture("Assets/Player/Fire10.png"),
		CreateTexture("Assets/Player/Fire11.png"),
		CreateTexture("Assets/Player/Fire12.png"),
		CreateTexture("Assets/Player/Fire13.png"),
	};
}

// Animation example 
void PlayerContainer::RenderMovement()
{
	switch (Directions)
	{
	case PlayerContainer::Left:
		for (Uint8 index = 0; index < 8; index++)
		{
			Draw(TurningSprites[index], { 0, 0, 70, 91, }, { PositionsX[0], PositionsY[0], 70, 91 });
		}
		break;
	case PlayerContainer::Right:
		for (Uint8 index = 0; index < 8; index++)
		{
			Draw(TurningSprites[index], { 0, 0, 70, 91, }, { PositionsX[0], PositionsY[0], 70, 91 }, 0, SDL_FLIP_HORIZONTAL);
		}
		break;
	case PlayerContainer::None:
		Render(); // calling base to rander
		break;
	}

	if (currentLives < 3)
	{
		FrameTime++;
		for (Uint8 index = 0; index < 13; index++)
		{
			if (FrameTime > FrameRate)
			{
				FrameTime = 0;
				Draw(FireSprites[index], { 0, 0, 20, 100 }, { PositionsX[0], PositionsY[0] + 65, 20, 100 });
				if (currentLives == 1)
					Draw(FireSprites[index], { 0, 0, 20, 100 }, { PositionsX[0] + 50, PositionsY[0] + 60, 20, 100 });
			}
		}
	}
}

// it's only one player, so the index = 0
void PlayerContainer::Move(short inputX, short inputY)
{
	if (inputX == 0 && inputY == 0)
	{
		Directions = MoveDirections::None;
		return;
	}

	if (inputX != 0)
	{
		Directions = inputX < 0 ? MoveDirections::Left : MoveDirections::Right;

		short newX = PositionsX[0] + inputX * Speed * Engine::GameTime::DeltaTime();
		if (newX > 0 && newX < MaxScreenX - (TextureWidth * 0.5f))
			PositionsX[0] = newX;
	}

	if (inputY != 0)
	{
		short newY = PositionsY[0] + inputY * Speed * Engine::GameTime::DeltaTime();
		if (newY > 0 && newY < MaxScreenY - TextureHeight)
			PositionsY[0] = newY;
	}

}

void PlayerContainer::CheckCollision(EnemyContainer& enemyContainer, UI* ui, Explosion* explo)
{
	for (short index = 0; index < enemyContainer.IndexCounter; index++)
	{
		if (enemyContainer.Usages[index])
		{
			if (PositionsY[0] <= enemyContainer.PositionsY[index] + (enemyContainer.TextureHeight * SpriteIndentOffset))
			{
				short enemyPositionX = enemyContainer.PositionsX[index];
				short playerPositionX = PositionsX[0];
				short playerXOffset = TextureWidth * SpriteIndentOffset; 

				if (playerPositionX > enemyPositionX && playerPositionX < (enemyPositionX + enemyContainer.TextureWidth) ||
					(playerPositionX + playerXOffset) > enemyPositionX && (playerPositionX + playerXOffset) < (enemyPositionX + enemyContainer.TextureWidth))
				{
					explo->PositionX = enemyContainer.PositionsX[index];
					explo->PositionY = enemyContainer.PositionsY[index];
					enemyContainer.BackToPool(index);
					explo->IsExploding = true;
					Damage(ui, explo);
				}
			}
		}
	}
}

void PlayerContainer::Damage(UI* ui, Explosion* explo)
{
	if (--currentLives == 0)
	{
		explo->PositionX = PositionsX[0];
		explo->PositionY = PositionsY[0];
		IsDead = true;
		BackToPool(0);
		explo->IsExploding = true;
	}
	ui->currentLives = currentLives;
}

void PlayerContainer::ShutDownAll()
{
	for (Uint8 index = 0; index < TurningSpritesLength; index++)
	{
		SDL_DestroyTexture(TurningSprites[index]);
		TurningSprites[index] = nullptr;
	}
	TurningSprites = nullptr;

	for (Uint8 index = 0; index < FireSpritesLength; index++)
	{
		SDL_DestroyTexture(FireSprites[index]);
		FireSprites[index] = nullptr;
	}
	FireSprites = nullptr;

	// calling base to shutdown
	ShutDown();
}


