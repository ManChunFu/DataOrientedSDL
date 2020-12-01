#include "PlayerContainer.h"

#include <GameTime.h>
#include "UI.h"

#pragma warning(disable: 4244)
#pragma warning(disable: 26812)
void PlayerContainer::Initilize()
{

	Init(1, 1400, 900, 70, 91, "Assets/Player/Left1.png");
	Add(700, 800, TextureWidth, TextureHeight);
	TurningSprites = new SDL_Texture * [8]
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
}

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
		Render();
		break;
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

void PlayerContainer::CheckCollision(EnemyContainer& enemyContainer, UI* ui)
{
	for (short index = 0; index < enemyContainer.IndexCounter; index++)
	{
		if (enemyContainer.Usages[index])
		{
			if (PositionsY[0] <= enemyContainer.PositionsY[index] + enemyContainer.TextureHeight)
			{
				short enemyPositionX = enemyContainer.PositionsX[index];
				short playerPositionX = PositionsX[0];
				if ((playerPositionX > enemyPositionX && playerPositionX < enemyPositionX + enemyContainer.TextureWidth) ||
					(playerPositionX + TextureWidth > enemyPositionX && playerPositionX + TextureWidth < enemyPositionX + enemyContainer.TextureWidth))
				{
					enemyContainer.BackToPool(index);
					Damage(ui);
				}
			}
		}
	}
}

void PlayerContainer::Damage(UI* ui)
{
	if (--currentLives == 0)
	{
		IsDead = true;
		BackToPool(0);
	}

	ui->currentLives = currentLives;
}

void PlayerContainer::ShutDownAll()
{
	for (Uint8 index = 0; index < 8; index++)
	{
		SDL_DestroyTexture(TurningSprites[index]);
		TurningSprites[index] = nullptr;
	}

	ShutDown();
}


