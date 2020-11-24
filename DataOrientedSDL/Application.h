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
		//void LoadScene(Uint8 scene);
		Engine::Window* Window = nullptr;
		Engine::InputSystem* InputSystem = nullptr;
		bool IsPause = false;
		bool IsRunning = true;
		Uint8 ActiveScene;

	private:
		//std::vector<Scene*> _scenes;
		void Update();
		void HandleEvents();
		void Render();
	};

	Application* CreateApplication();
}

