#pragma once

#include <SDL_KeyCode.h>
#include <SDL_scanCode.h>
#include <SDL_events.h>
#include <string>

#pragma warning (disable : 26812)

namespace Engine
{
	enum Keys
	{
		W,
		E,
		R,
		A,
		S,
		D,
		ESCAPE,
		SPACE
	};

	class InputSystem
	{
	public:
		InputSystem();
		void ShutDown();
		void Update(bool& isRunning);
		bool IsKeyDown(SDL_Scancode key) const { return _keys[key]; };
		bool IsKeyPressed(Keys key);
		bool IsKeyReleased(Keys key);
		int GetAxis(std::string Axis);
		int GetAction(std::string action);

	private:
		bool IsKeyPressedScancode(SDL_Scancode key) const;
		bool IsKeyReleasedScancode(SDL_Scancode key) const;
		void SetMouseCursor(SDL_SystemCursor newCursor);

		static SDL_Event _event;
		const Uint8* _keys = nullptr;
		Uint8 _lastKeys[256];
	};
}

