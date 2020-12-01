#pragma once

#include <RenderBase.h>

class UI : public Engine::RenderBase
{
public:
	SDL_Texture* BackgroundSprite = nullptr;
	SDL_Texture** LiveSprites;
	SDL_Texture* GameOverSprite = nullptr;
	SDL_Texture* QuitSprite = nullptr;
	short MaxScreenX = 1440;
	short MaxScreenY = 900;
	void Init();
	void Render(bool isGameEnd);
	void ShutDown();
	Uint8 currentLives = 3;

private:
	void BackgroundMove();
	float currentBGPosY = 0.0f;
	float nextBGPosY = -900.0f;
	float moveRate = 0.5f;
};

