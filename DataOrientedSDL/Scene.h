#pragma once

#include <SDL_stdinc.h>

namespace Engine
{
	class Application;
	class InputSystem;
	class EntityContainerBase;

	class Scene
	{
	public:
		Scene(Application* app, InputSystem* input);
		virtual ~Scene(){}

		virtual void ShutDown();
		virtual void Update();
		virtual void HandleEvents();
		virtual void Render();
		virtual void Start();
		void LoadScene(Uint8 scene);
		const Uint8 ID = _idControl;
		static Scene* ActiveScene;

		Engine::Application* App;

	protected:
		Engine::InputSystem* inputSystem;
		Engine::EntityContainerBase* entityContainer;
	private:
		bool _loadScene;
		Uint8 _scene;
		static Uint8 _idControl;

	};
}

