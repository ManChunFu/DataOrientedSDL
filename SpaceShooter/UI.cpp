#include "UI.h"

void UI::Init()
{
	BackgroundSprite = CreateTexture("Assets/Universe1440.png");
	LiveSprites = new SDL_Texture * [4]
	{
		CreateTexture("Assets/UI/no_lives.png"),
		CreateTexture("Assets/UI/One.png"),
		CreateTexture("Assets/UI/Two.png"),
		CreateTexture("Assets/UI/Three.png")
	};
	GameOverSprite = CreateTexture("Assets/UI/GameOver.png");
}

void UI::Render(bool isGameEnd)
{
	Draw(BackgroundSprite, { 0, 0, 1440, 900 }, { 0, 0, MaxScreenX, MaxScreenY });

	if (currentLives > -1)
		Draw(LiveSprites[currentLives], { 0, 0, 154, 65 }, { 10, 10, 154, 65 });

	if (isGameEnd)
		Draw(GameOverSprite, { 0, 0, 512, 512 }, { 450, 200, 512, 512 });

	//BackgroundMove();
}

void UI::ShutDown()
{
	SDL_DestroyTexture(BackgroundSprite);
	BackgroundSprite = nullptr;

	for (Uint8 index = 0; index < 4; index++)
	{
		SDL_DestroyTexture(LiveSprites[index]);
		LiveSprites[index] = nullptr;
	}

	SDL_DestroyTexture(GameOverSprite);
	GameOverSprite = nullptr;
}

void UI::BackgroundMove()
{
	
	currentBGPosY+= (int) 0.1f;
}
