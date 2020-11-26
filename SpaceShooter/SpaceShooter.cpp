#include "SpaceShooter.h"
#include <Window.h>
#include <iostream>
#include <SDL_image.h>
#include <GameTime.h>
#include <RenderBase.h>


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
	
	// new codes
	_backgroundTexture = background.CreateTexture("Assets/SpaceBG_Overlay.png");
	
	playerContainer.Init(1, 1440, 900, 100, 128);
	playerContainer.Add(500, 500, 70, 88);
	playerContainer.AddImage("Assets/Player.png");

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
		ListenInputs();
		Render();

		frameTime = SDL_GetTicks() - frameStartTick;
		if (frameDelay > frameTime) {
			if (frameDelay - frameTime > 0)
				SDL_Delay(frameDelay - frameTime);
		}
		Engine::GameTime::EndFrame();
	}
}


void Engine::Application::ListenInputs()
{
	InputSystem->Update(IsRunning);

	if (InputSystem->IsKeyPressed(Keys::ESCAPE))
		IsRunning = false;

	playerContainer.Move(0, InputSystem->GetAxis("Horizontal") * playerContainer.Speed * Engine::GameTime::DeltaTime(), InputSystem->GetAxis("Vertical") * playerContainer.Speed * Engine::GameTime::DeltaTime());

}

void Engine::Application::Render()
{
	SDL_SetRenderDrawColor(Engine::Window::Renderer, 100, 100, 100, 255);//background color

	//Background
	background.Draw(_backgroundTexture, { 0, 0, 1920, 1080 }, { 0, 0, 1440, 900 });

	//Player
	playerContainer.Render();

	Engine::Window::RenderPresent();
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
	
	playerContainer.ShutDown();

	IMG_Quit();
	SDL_Quit();
}


