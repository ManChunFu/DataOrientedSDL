#include "EnemyContainer.h"

#include <GameTime.h>

void EnemyContainer::Move()
{
	for(short index = 0; index < IndexCounter; index++)
	{

		PositionsY[index] += Speed * Engine::GameTime::DeltaTime();
	}
}
