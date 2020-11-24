#include "Textures.h"

#include <SDL_image.h>
#include <iostream>

namespace Engine
{
	TextureMap Textures::_textureMap;

	void Textures::Draw(SDL_Texture* sprite, SDL_Rect srcRect, SDL_Rect desRect)
	{
		if (sprite && Engine::Window::Renderer)
			SDL_RenderCopy(Engine::Window::Renderer, sprite, &srcRect, &desRect);
	}

	void Textures::Draw(SDL_Texture* sprite, SDL_Rect srcRect, SDL_Rect desRect, float rotation, SDL_RendererFlip flip)
	{
		if (sprite && Engine::Window::Renderer)
			SDL_RenderCopyEx(Engine::Window::Renderer, sprite, &srcRect, &desRect, rotation, nullptr, flip);
	}

	SDL_Texture* Textures::LoadTexture(const std::string& texturePath)
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

	void Textures::AddTexture(std::string name, const std::string& path)
	{
		if (!HasTexture(name))
		{
			SDL_Texture* texture = Engine::Textures::LoadTexture(path);
			_textureMap.insert({ name, texture });
		}
	}

	bool Textures::HasTexture(std::string name)
	{
		auto item = _textureMap.find(name);
		if (item != _textureMap.end())
			return true;

		return false;
	}

	SDL_Texture* Textures::GetTexture(std::string name)
	{
		if (HasTexture(name))
			return _textureMap.find(name)->second;

		return nullptr;
	}

	void Textures::ShutDown()
	{
		for (auto item = _textureMap.begin(); item != _textureMap.end(); item++)
		{
			SDL_DestroyTexture(item->second);
		}
		_textureMap.clear();
	}
}

