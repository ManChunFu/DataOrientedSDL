#include "PlayerContainer.h"

#include <GameTime.h>

// it's only one player, so the index = 0
void PlayerContainer::Move(short inputX, short inputY)
{
	short newX = PositionsX[0] + inputX * Speed * Engine::GameTime::DeltaTime();
	if (newX > 0 && newX < MaxScreenX - TextureWidth)
		PositionsX[0] = newX;

	short newY = PositionsY[0] + inputY * Speed * Engine::GameTime::DeltaTime();
	if (newY > 0 && newY < MaxScreenY - TextureHeight)
		PositionsY[0] = newY;

}

void PlayerContainer::CheckCollision(EnemyContainer& enemyContainer)
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
					BackToPool(0);
			}
		}
	}
}


