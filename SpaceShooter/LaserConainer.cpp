#include "LaserContainer.h"

#include <GameTime.h>

void LaserContainer::Move()
{
	for (Uint8 index = 0; index < IndexCounter; index++)
	{
		if (PositionsY[index] - Heights[index] < 0)
			BackToPool(index);
					
		PositionsY[index] -= Speed * Engine::GameTime::DeltaTime();
	}
}