#pragma once

#include "Window.h"
#include <unordered_map>
#include <string>
#include <SDL_rect.h>

struct SDL_Texture;

namespace Engine
{
	struct RenderBase
	{
	public:
		void Draw(SDL_Texture* sprite, SDL_Rect srcRect, SDL_Rect desRect);
		void Draw(SDL_Texture* sprite, SDL_Rect srcRect, SDL_Rect desRect, float rotation, SDL_RendererFlip flip);
		SDL_Texture* CreateTexture(const std::string& texturePath);
	};
}
