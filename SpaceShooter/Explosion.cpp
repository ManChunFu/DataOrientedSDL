#include "Explosion.h"

void Explosion::Init()
{
	Sprites = new SDL_Texture * [SpritesLength]
	{
		CreateTexture("Assets/Explosion/E1.png"),
		CreateTexture("Assets/Explosion/E2.png"),
		CreateTexture("Assets/Explosion/E3.png"),
		CreateTexture("Assets/Explosion/E4.png"),
		CreateTexture("Assets/Explosion/E5.png"),

		CreateTexture("Assets/Explosion/E6.png"),
		CreateTexture("Assets/Explosion/E7.png"),
		CreateTexture("Assets/Explosion/E8.png"),
		CreateTexture("Assets/Explosion/E9.png"),
		CreateTexture("Assets/Explosion/E10.png"),

		CreateTexture("Assets/Explosion/E11.png"),
		CreateTexture("Assets/Explosion/E12.png"),
		CreateTexture("Assets/Explosion/E13.png"),
		CreateTexture("Assets/Explosion/E14.png"),
		CreateTexture("Assets/Explosion/E15.png"),

		CreateTexture("Assets/Explosion/E16.png"),
		CreateTexture("Assets/Explosion/E17.png"),
		CreateTexture("Assets/Explosion/E18.png")
	};
}

void Explosion::Render()
{
	for (Uint8 index = 0; index < 18; index++)
	{
		framtime++;
		if (framtime > framrate)
		{
			framtime = 0;
			Draw(Sprites[index], { 0, 0, 100, 107 }, { PositionX, PositionY, 100, 107 });
		}
	}
	IsExploding = false;
}

void Explosion::ShutDown()
{
	for (Uint8 index = 0; index < SpritesLength; index++)
	{
		SDL_DestroyTexture(Sprites[index]);
		Sprites[index] = nullptr;
	}
	Sprites = nullptr;
}