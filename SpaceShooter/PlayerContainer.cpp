#include "PlayerContainer.h"

void PlayerContainer::Move(short inputX, short inputY)
{
	short newX = PositionsX[IndexID] + inputX;
	if (newX > 0 && newX < MaxScreenX - Widths[IndexID])
		PositionsX[IndexID] = newX;

	short newY = PositionsY[IndexID] + inputY;
	if (newY > 0 && newY < MaxScreenY - Heights[IndexID])
		PositionsY[IndexID] = newY;

}


