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

	Window = new Engine::Window("Main Window", background.MaxScreenX = 1440, background.MaxScreenY = 900);

	if (!Window->Init())
	{
		std::cout << "Failed to initialize. SDL Error: " << SDL_GetError << std::endl;
		return false;
	}

	InputSystem = new Engine::InputSystem();
	
	// Background
	_backgroundTexture = background.CreateTexture("Assets/SpaceBG_Overlay.png");
	
	// Player
	playerContainer.Init(1, background.MaxScreenX, background.MaxScreenY, 70, 90);
	playerContainer.Sprite = playerContainer.AddImage("Assets/Player.png");
	playerContainer.Add(700, 800, playerContainer.TextureWidth, playerContainer.TextureHeight);

	// Laser
	laserContainer.Init(10, background.MaxScreenX, background.MaxScreenY, 8, 40);
	laserContainer.Sprite = laserContainer.AddImage("Assets/laser.png");

	// Enemy
	enemyContainer.Init(10, background.MaxScreenX, background.MaxScreenY, 100, 130);
	enemyContainer.Sprite = enemyContainer.AddImage("Assets/Enemy.png");

	//laserContainer.enemyContainer = enemyContainer;
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

void Engine::Application::Update()
{
	spawnTimer += Engine::GameTime::DeltaTime();

	laserContainer.Move(enemyContainer);

	if (spawnTimer > spawnRate)
	{
		spawnTimer = 0;
		enemyContainer.Add(enemyContainer.RandomPositionX(), -enemyContainer.TextureHeight, enemyContainer.TextureWidth, enemyContainer.TextureHeight);
	}
	enemyContainer.Move();
}

void Engine::Application::CheckCollision()
{

}

void Engine::Application::ListenInputs()
{
	InputSystem->Update(IsRunning);

	if (InputSystem->IsKeyPressed(Keys::ESCAPE))
		IsRunning = false;

	//Player
	playerContainer.Move(InputSystem->GetAxis("Horizontal"), InputSystem->GetAxis("Vertical"));

	if (InputSystem->IsKeyPressed(Keys::SPACE))
	{
		laserContainer.Add((playerContainer.PositionsX[0] + laserContainer.InstantiateOffsetX), 
			(playerContainer.PositionsY[0] - laserContainer.InstantiateOffsetY), laserContainer.TextureWidth, laserContainer.TextureHeight);
	}
}

void Engine::Application::Render()
{
	SDL_SetRenderDrawColor(Engine::Window::Renderer, 100, 100, 100, 255);//background color

	//Background
	background.Draw(_backgroundTexture, { 0, 0, 1440, 900 }, { 0, 0, background.MaxScreenX, background.MaxScreenY });

	//Player
	playerContainer.Render(playerContainer.Sprite);

	//Laser
	laserContainer.Render(laserContainer.Sprite);

	//Enemy
	enemyContainer.Render(enemyContainer.Sprite);

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
	laserContainer.ShutDown();
	enemyContainer.ShutDown();

	IMG_Quit();
	SDL_Quit();
}


