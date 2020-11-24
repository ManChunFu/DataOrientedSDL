#include "Scene.h"

#include "Application.h"

namespace Engine
{
	Uint8 Scene::_idControl = 0;
	Scene* Scene::ActiveScene = nullptr;

	Scene::Scene(Application* app, InputSystem* input)
	{
		ActiveScene = this;
		entityContainer = new Engine::EntityContainerBase();
		App = app;
		inputSystem = input;
		_idControl++;
		_loadScene = false;
	}

	void Scene::ShutDown()
	{
		if (inputSystem)
		{
			inputSystem->ShutDown();
			delete inputSystem;
		}
	}

	void Scene::Update()
	{
		if (_loadScene)
		{
			//App->LoadScene(_scene);
			_loadScene = false;
		}
	}

	void Scene::HandleEvents()
	{

	}

	void Scene:: Render()
	{

	}

	void Scene::Start()
	{
		ActiveScene = this;
	}

	void Scene::LoadScene(Uint8 scene)
	{
		_loadScene = true;
		_scene = scene;
	}


}
