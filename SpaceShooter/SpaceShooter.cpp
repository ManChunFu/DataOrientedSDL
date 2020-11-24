#include "SpaceShooter.h"
#include <Window.h>
#include <iostream>
#include <SDL_image.h>
#include <Scene.cpp>
#include <GameTime.h>


int main(int argc, char** argv)
{
	App = new Engine::Application();

	if (!App->Initialize())
	{
		App->ShutDown();
		delete App;
		App = nullptr;
		return -5;
	}

	App->Run();
	App->ShutDown();
	delete App;
	App = nullptr;

	return 0;
}

bool Engine::Application::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Failed to inialize SDL. SDL Error: " << SDL_GetError << std::endl;
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		std::cout << "Failed to inialize SDL_Image. SDL Error: " << SDL_GetError << std::endl;
		return false;
	}

	Window = new Engine::Window("Main Window", 1440, 900);
	if (!Window->Init())
	{
		std::cout << "Failed to initialize. SDL Error: " << SDL_GetError << std::endl;
		return false;
	}

	InputSystem = new Engine::InputSystem();

	return true;
}

void Engine::Application::Run()
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStartTick;
	int frameTime;

	while (IsRunning)
	{
		Engine::GameTime::StartFrame();
		frameStartTick = SDL_GetTicks();
		Engine::Window::RenderClear();
		Update();
		HandleEvents();
		Render();
		frameTime = SDL_GetTicks() - frameStartTick;
		if (frameDelay > frameTime) {
			if (frameDelay - frameTime > 0)
				SDL_Delay(frameDelay - frameTime);
		}
		Engine::GameTime::EndFrame();
	}
}

void Engine::Application::ShutDown()
{
	if (InputSystem) {
		delete InputSystem;
		InputSystem = nullptr;
	}
	if (Window)
	{
		delete Window;
		Window = nullptr;
	}
	Engine::Textures::ShutDown();
	IMG_Quit();
	SDL_Quit();
}


void Engine::Application::HandleEvents()
{
	/*if (!App->IsPause)
	{
		Engine::Scene::ActiveScene->HandleEvents();
	}*/
	/*if (InputSystem->IsKeyPressed(Keys::BACKSPACE))
	{
		LoadScene(0);
	}*/
}

void Engine::Application::Update()
{
	InputSystem->Update(IsRunning);
	if (ActiveScene == 1 && InputSystem->IsKeyPressed(Keys::ESCAPE))
	{
		IsPause = !IsPause;
		//if (!IsPause)
		//{
		//	InputSystem->ClearClickables();
		//	Engine::UIManager::ActiveCanvas = 10;
		//}
		//else
		//{
		//	Engine::UIManager::ActiveCanvas = 2;
		//	scenes[3]->Start();
		//}
	}
	/*Engine::UIManager::Update();
	if (!application->Pause)
	{
		Engine::Scene::ActiveScene->Update();
	}*/

}

void Engine::Application::Render()
{
	SDL_SetRenderDrawColor(Engine::Window::Renderer, 100, 100, 100, 255);//background color
	Engine::Textures::AddTexture("StarBackground", "Assets/Stars_Background.png");
	Engine::Textures::Draw(Textures::GetTexture("StarBackground"), { 0, 0, 1400, 900 }, { 0, 0, 1400, 900 });
	//Engine::Scene::ActiveScene->Render();
	//Engine::UIManager::Render();
	Engine::Window::RenderPresent();
}
//void Engine::Application::LoadScene(int scene)
//{
//	Engine::Scene::ActiveScene->Shutdown();
//	Engine::Scene::ActiveScene = scenes[scene];
//	Engine::Scene::ActiveScene->Start();
//	Engine::UIManager::ActiveCanvas = scene;
//	Engine::Camera::ActiveCamera = scenes[scene]->Camera();
//	inputManager->ClearClickables();
//	scenes[scene]->AddClickables();
//	ActiveScene = scene;
//}


