#include "LaserContainer.h"

#include <GameTime.h>

void LaserContainer::Move(EnemyContainer& enemyContainer)
{
	for (Uint8 index = 0; index < IndexCounter; index++)
	{
		if (!Usages[index])
			continue;

		if (PositionsY[index] + Heights[index] < 0)
			BackToPool(index);
		else if (CheckCollision(PositionsY[index], PositionsX[index], enemyContainer))
			BackToPool(index);
		else
			PositionsY[index] -= Speed * Engine::GameTime::DeltaTime();
	}
}

bool LaserContainer::CheckCollision(short positionY, short positionX, EnemyContainer& enemyContainer)
{
	for (short index = 0; index < IndexCounter; index++)
	{
		if (enemyContainer.Usages[index])
		{
			if (positionY <= enemyContainer.PositionsY[index] + enemyContainer.TextureHeight)
			{
				short enemyPositionX = enemyContainer.PositionsX[index];
				if (positionX > enemyPositionX && positionX < enemyPositionX + enemyContainer.TextureWidth)
				{
					enemyContainer.BackToPool(index);
					return true;
				}
			}
		}
	}
	return false;
}