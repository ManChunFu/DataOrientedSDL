#pragma once

#include <RenderBase.h>

class Explosion : public Engine::RenderBase
{
public:
	SDL_Texture** Sprites = nullptr;
	bool IsExploding = false;
	short PositionX = 0, PositionY = 0;
	const Uint8 SpritesLength = 18;
	void Init();
	void Render();
	void ShutDown();
	Uint8 framtime = 0;
	Uint8 framrate = 8;
};

