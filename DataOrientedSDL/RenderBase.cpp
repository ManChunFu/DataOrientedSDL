#include "RenderBase.h"
#include <SDL_image.h>
#include <iostream>

namespace Engine
{
	void RenderBase::Draw(SDL_Texture* sprite, SDL_Rect srcRect, SDL_Rect desRect)
	{
		if (sprite && Engine::Window::Renderer)
			SDL_RenderCopy(Engine::Window::Renderer, sprite, &srcRect, &desRect);
	}

	void RenderBase::Draw(SDL_Texture* sprite, SDL_Rect srcRect, SDL_Rect desRect, float rotation, SDL_RendererFlip flip)
	{
		if (sprite && Engine::Window::Renderer)
			SDL_RenderCopyEx(Engine::Window::Renderer, sprite, &srcRect, &desRect, rotation, nullptr, flip);
	}


	SDL_Texture* RenderBase::CreateTexture(const std::string& texturePath)
	{
		SDL_Surface* surface = IMG_Load(texturePath.c_str());
		if (!surface)
			std::cout << "Failed to create SDL_surface. SDL Error. " << SDL_GetError << std::endl;
		else
		{
			SDL_Texture* newTexture = SDL_CreateTextureFromSurface(Engine::Window::Renderer, surface);
			SDL_FreeSurface(surface);
			surface = nullptr;
			return newTexture;
		}

		return nullptr;
	}
}

