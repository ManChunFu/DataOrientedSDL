#pragma once

#include <RenderBase.h>

class UI : public Engine::RenderBase
{
public:
	SDL_Texture* BackgroundSprite = nullptr;
	SDL_Texture** LiveSprites = nullptr;
	SDL_Texture* GameOverSprite = nullptr;
	SDL_Texture* QuitSprite = nullptr;
	const Uint8 LiveSpritesLength = 4;
	short MaxScreenX = 1440;
	short MaxScreenY = 900;
	Uint8 currentLives = 3;
	void Init();
	void Render(bool isGameEnd);
	void ShutDown();
private:
	void BackgroundMove();
	float currentBGPosY = 0.0f;
	float nextBGPosY = -900.0f;
	float moveRate = 0.5f;
};

