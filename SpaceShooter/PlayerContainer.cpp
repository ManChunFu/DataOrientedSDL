#include "PlayerContainer.h"

#include <GameTime.h>

// it's only one player, so the index = 0
void PlayerContainer::Move(short inputX, short inputY)
{
	short newX = PositionsX[0] + inputX * Speed * Engine::GameTime::DeltaTime();
	if (newX > 0 && newX < MaxScreenX - Widths[0])
		PositionsX[0] = newX;

	short newY = PositionsY[0] + inputY * Speed * Engine::GameTime::DeltaTime();
	if (newY > 0 && newY < MaxScreenY - Heights[0])
		PositionsY[0] = newY;

}


