#include "LaserContainer.h"

#include <GameTime.h>
#include "Explosion.h"

#pragma warning(disable: 4244)

void LaserContainer::Move(EnemyContainer& enemyContainer, Explosion* explo)
{
	for (Uint8 index = 0; index < IndexCounter; index++)
	{
		if (!Usages[index])
			continue;

		if (PositionsY[index] + Heights[index] < 0)
			BackToPool(index);
		else if (CheckCollision(PositionsX[index], PositionsY[index], enemyContainer, explo))
			BackToPool(index);
		else
			PositionsY[index] -= Speed * Engine::GameTime::DeltaTime();
	}
}

bool LaserContainer::CheckCollision(short positionX, short positionY, EnemyContainer& enemyContainer, Explosion* explo)
{
	for (short index = 0; index < enemyContainer.IndexCounter; index++)
	{
		if (enemyContainer.Usages[index])
		{
			if (positionY <= enemyContainer.PositionsY[index] + enemyContainer.TextureHeight * SpriteIndentOffset)
			{
				short enemyPositionX = enemyContainer.PositionsX[index];
				if (positionX > enemyPositionX && positionX < enemyPositionX + enemyContainer.TextureWidth * SpriteIndentOffset)
				{
					explo->PositionX = enemyContainer.PositionsX[index];
					explo->PositionY = enemyContainer.PositionsY[index];
					enemyContainer.BackToPool(index);
					explo->IsExploding = true;
					return true;
				}
			}
		}
	}
	return false;
}