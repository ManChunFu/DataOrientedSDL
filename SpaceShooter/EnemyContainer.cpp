#include "EnemyContainer.h"

#include <GameTime.h>
#include <iostream>

void EnemyContainer::Move()
{
	for(short index = 0; index < IndexCounter; index++)
	{
		if (!Usages[index])
			continue;

		if (PositionsY[index] - TextureHeight > MaxScreenY)
		{
			PositionsX[index] = RandomPositionX();
			PositionsY[index] =  -TextureHeight;
		}
		else
			PositionsY[index] += Speed * Engine::GameTime::DeltaTime();
	}
}

short EnemyContainer::RandomPositionX()
{
	return rand() % (MaxScreenX - TextureWidth);
}
