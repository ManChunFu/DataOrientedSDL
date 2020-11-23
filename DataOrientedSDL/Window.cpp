#include "Window.h"

#include <SDL_video.h>
#include <SDL_render.h>
#include <iostream>

SDL_Renderer* Engine::Window::Renderer = nullptr;

namespace Engine
{
	Window::Window(const std::string& title, int width, int height) : _title(title), _width(width), _height(height){}

	Window::~Window()
	{
		if (Renderer)
		{
			SDL_DestroyRenderer(Renderer);
			Renderer = nullptr;
		}

		if (_window)
		{
			SDL_DestroyWindow(_window);
			_window = nullptr;
		}
	}

	bool Window::Init()
	{
		_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, 0);
		if (_window == nullptr)
		{
			std::cout << "Failed to create window. SDL Error: " << SDL_GetError << std::endl;
			return false;
		}

		Renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (Renderer == nullptr)
		{
			std::cout << "Failed to create SDL_Renderer. SDL Error: " << SDL_GetError << std::endl;
			return false;
		}

		return true;
	}
}