#pragma once

#include <EntityContainerBase.h>


struct PlayerContainer : public Engine::EntityContainerBase
{
public:
	Uint8 IndexID;
	SDL_Texture* Sprite;
	const short Speed = 300;
	void Move(short inputX, short inputY);
private:
};

