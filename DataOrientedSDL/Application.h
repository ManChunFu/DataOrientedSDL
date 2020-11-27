#pragma once

#include "Window.h"
#include "EntityContainerBase.h"
#include "InputSystem.h"
#include "RenderBase.h"

namespace Engine
{
	class Window;
	class InputSystem;
	class EntityContainerBase;

	class Application
	{
	public:
		~Application() {};

		void Quit() { IsRunning = false; }

		bool Initialize();
		void Run();
		void Update();
		void ShutDown();
		void CheckCollision();
		Engine::Window* Window = nullptr;
		Engine::InputSystem* InputSystem = nullptr;
		bool IsPause = false;
		bool IsRunning = true;
		Uint8 ActiveScene;

	private:
		//std::vector<Scene*> _scenes;
		//void Update();
		void ListenInputs();
		void Render();
	};

	Application* CreateApplication();
}

