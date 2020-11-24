#pragma once

#include "Window.h"
#include <unordered_map>
#include <string>
#include <SDL_rect.h>

struct SDL_Texture;

namespace Engine
{
	typedef std::unordered_map<std::string, SDL_Texture*> TextureMap;

	static class Textures
	{
	public:
		static void Draw(SDL_Texture* sprite, SDL_Rect srcRect, SDL_Rect desRect);
		static void Draw(SDL_Texture* sprite, SDL_Rect srcRect, SDL_Rect desRect, float rotation, SDL_RendererFlip flip);
		static void AddTexture(std::string name, const std::string& path);
		static bool HasTexture(std::string name);
		static SDL_Texture* GetTexture(std::string name);
		static void ShutDown();

	private:
		static SDL_Texture* LoadTexture(const std::string& texturePath);
		static TextureMap _textureMap;
	};
}

