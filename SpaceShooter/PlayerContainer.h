#pragma once

#include <EntityContainerBase.h>


struct PlayerContainer : public Engine::EntityContainerBase
{
public:
	const short Speed = 300;
	void Move(short inputX, short inputY);
private:
};

