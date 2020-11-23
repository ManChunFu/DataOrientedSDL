#include "InputSystem.h"

#include <SDL_mouse.h>

namespace Engine
{
	SDL_Event InputSystem::_event;

	InputSystem::InputSystem()
	{
		_keys = SDL_GetKeyboardState(nullptr);
		std::copy(_keys, _keys + 256, _lastKeys);
	}

	void InputSystem::ShutDown()
	{
		delete _keys;
		_keys = nullptr;
	}

	void InputSystem::Update(bool& isRunning, bool& isPaused)
	{
		std::copy(_keys, _keys + 256, _lastKeys);
		_keys = SDL_GetKeyboardState(nullptr);

		while (SDL_PollEvent(&_event))
		{
			if (_event.type == SDL_QUIT)
			{
				isRunning = false;
				return;
			}
		}
	}

	bool InputSystem::IsKeyPressed(Keys key)
	{
		switch (key)
		{
		case W:
			return IsKeyPressedScancode(SDL_SCANCODE_W);
			break;
		case E:
			return IsKeyPressedScancode(SDL_SCANCODE_E);
			break;
		case R:
			return IsKeyPressedScancode(SDL_SCANCODE_R);
			break;
		case A:
			return IsKeyPressedScancode(SDL_SCANCODE_A);
			break;
		case S:
			return IsKeyPressedScancode(SDL_SCANCODE_S);
			break;
		case D:
			return IsKeyPressedScancode(SDL_SCANCODE_D);
			break;
		case ESCAPE:
			return IsKeyPressedScancode(SDL_SCANCODE_ESCAPE);
			break;
		case SPACE:
			return IsKeyPressedScancode(SDL_SCANCODE_SPACE);
			break;
		default:
			break;
		}

		return false;
	}

	bool InputSystem::IsKeyReleased(Keys key)
	{
		switch (key)
		{
		case W:
			return IsKeyReleasedScancode(SDL_SCANCODE_W);
			break;
		case E:
			return IsKeyReleasedScancode(SDL_SCANCODE_E);
			break;
		case R:
			return IsKeyReleasedScancode(SDL_SCANCODE_R);
			break;
		case A:
			return IsKeyReleasedScancode(SDL_SCANCODE_A);
			break;
		case S:
			return IsKeyReleasedScancode(SDL_SCANCODE_S);
			break;
		case D:
			return IsKeyReleasedScancode(SDL_SCANCODE_D);
			break;
		case ESCAPE:
			return IsKeyReleasedScancode(SDL_SCANCODE_ESCAPE);
			break;
		case SPACE:
			return IsKeyReleasedScancode(SDL_SCANCODE_SPACE);
			break;
		default:
			break;
		}

		return false;
	}

	int InputSystem::GetAxis(std::string Axis)
	{
		if (Axis == "Horizontal")
		{
			if (IsKeyDown(SDL_SCANCODE_D) || IsKeyDown(SDL_SCANCODE_RIGHT))
				return 1;
			
			if (IsKeyDown(SDL_SCANCODE_A) || IsKeyDown(SDL_SCANCODE_LEFT))
				return -1;
		}

		if (Axis == "Vertical")
		{
			if (IsKeyDown(SDL_SCANCODE_S) || IsKeyDown(SDL_SCANCODE_DOWN))
				return 1;

			if (IsKeyDown(SDL_SCANCODE_W) || IsKeyDown(SDL_SCANCODE_UP))
				return -1;
		}

		return 0;
	}

	int InputSystem::GetAction(std::string action)
	{
		if (action == "Escape")
		{
			if (IsKeyDown(SDL_SCANCODE_ESCAPE))
				return 1;
		}

		if (action == "Space")
		{
			if (IsKeyDown(SDL_SCANCODE_SPACE))
				return 1;
		}

		return 0;
	}

	bool InputSystem::IsKeyPressedScancode(SDL_Scancode key) const
	{
		if (!_lastKeys[key] && _keys[key])
			return true;

		return false;
	}

	bool InputSystem::IsKeyReleasedScancode(SDL_Scancode key) const
	{
		if (_lastKeys[key] && !_keys[key])
			return true;

		return false;
	}

	void InputSystem::SetMouseCursor(SDL_SystemCursor newCursor)
	{
		SDL_Cursor* cursor;
		cursor = SDL_CreateSystemCursor(newCursor);
		SDL_SetCursor(cursor);
	}

}
