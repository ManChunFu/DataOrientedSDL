#include "LaserContainer.h"

#include <GameTime.h>

void LaserContainer::Move()
{
	for (Uint8 index = 0; index < IndexCounter; index++)
	{
		if (!Usages[index])
			continue;

		if (PositionsY[index] + Heights[index] < 0)
			BackToPool(index);
		else
			PositionsY[index] -= Speed * Engine::GameTime::DeltaTime();
	}
}