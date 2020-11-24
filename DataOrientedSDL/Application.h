#pragma once

#include "Window.h"
#include "EntityContainerBase.h"
#include "InputSystem.h"
#include "Textures.h"

namespace Engine
{
	class Window;
	class InputSystem;
	class EntityContainerBase;
	class Textures;

	class Application
	{
	public:
		~Application() {};

		void Quit() { IsRunning = false; }

		bool Initialize();
		void Run();
		void ShutDown();
		Engine::Window* Window = nullptr;
		Engine::InputSystem* InputSystem = nullptr;
		bool Pause = false;
		bool IsRunning = true;

	private:
		void Update();
		void HandleEvents();
		void Render();
	};

	Application* CreateApplication();
}

