#pragma once

#include <string>
#include <SDL.h>

namespace Engine
{
	class Window
	{
	public:
		Window(const std::string& title, int width, int height);
		~Window();

		bool Init();
		static SDL_Renderer* Renderer;
		static void RenderClear() { SDL_RenderClear(Renderer); }
		static void RenderPresent() { SDL_RenderPresent(Renderer); }
		int ScreenWidth() { return _width; }
		int ScreenHeight() { return _height; }

	private:
		std::string _title;
		int _width;
		int _height;
		
		SDL_Window* _window = nullptr;
	};
}

