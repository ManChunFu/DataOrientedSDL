#include "UI.h"

#pragma warning(disable: 4244)

void UI::Init()
{
	BackgroundSprite = CreateTexture("Assets/Sky.png");
	LiveSprites = new SDL_Texture * [4]
	{
		CreateTexture("Assets/UI/no_lives.png"),
		CreateTexture("Assets/UI/One.png"),
		CreateTexture("Assets/UI/Two.png"),
		CreateTexture("Assets/UI/Three.png")
	};
	GameOverSprite = CreateTexture("Assets/UI/GameOver.png");
	QuitSprite = CreateTexture("Assets/UI/Quit.png");
}

void UI::Render(bool isGameEnd)
{
	Draw(BackgroundSprite, { 0, 0, 1440, 900 }, { 0, (short)currentBGPosY, MaxScreenX, MaxScreenY });
	Draw(BackgroundSprite, { 0, 0, 1440, 900 }, { 0, (short)nextBGPosY, MaxScreenX, MaxScreenY });
	Draw(QuitSprite, { 0, 0, 150, 36 }, { 1280, 10, 150, 36 });

	if (currentLives > -1)
		Draw(LiveSprites[currentLives], { 0, 0, 154, 65 }, { 10, 10, 154, 65 });

	if(isGameEnd)
		Draw(GameOverSprite, { 0, 0, 512, 512 }, { 450, 200, 512, 512 });

	BackgroundMove();
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

	SDL_DestroyTexture(QuitSprite);
	QuitSprite = nullptr;
}

void UI::BackgroundMove()
{
	if ((currentBGPosY += moveRate) > MaxScreenY)
		currentBGPosY = -MaxScreenY;

	if ((nextBGPosY += moveRate) > MaxScreenY)
		nextBGPosY = -MaxScreenY;
}
