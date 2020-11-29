#pragma once

#include "Window.h"
#include "EntityContainerBase.h"
#include "InputSystem.h"
#include "RenderBase.h"

namespace Engine
{
	class Window;
	class InputSystem;
	class Application
	{
	public:
		~Application() {};

		void Quit() { IsRunning = false; }

		bool Initialize();
		void Run();
		void Update();
		void ShutDown();
		Engine::Window* Window = nullptr;
		Engine::InputSystem* InputSystem = nullptr;
		bool IsPause = false;
		bool IsRunning = true;

	private:
		void ListenInputs();
		void Render();
	};

	Application* CreateApplication();
}

