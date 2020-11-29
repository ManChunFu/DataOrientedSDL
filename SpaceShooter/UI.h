#pragma once

#include <RenderBase.h>

class UI : public Engine::RenderBase
{
public:
	SDL_Texture* BackgroundSprite;
	SDL_Texture** LiveSprites;
	SDL_Texture* GameOverSprite;
	short MaxScreenX = 1440;
	short MaxScreenY = 900;
	void Init();
	void Render(bool isGameEnd);
	void ShutDown();
	Uint8 currentLives = 3;

private:
	void BackgroundMove();
	short currentBGPosY = 0;
};

