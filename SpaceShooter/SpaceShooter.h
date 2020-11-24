#pragma once

#include <Application.h>

class SpaceShooter : public Engine::Application
{
public:
private:
};

Engine::Application* Engine::CreateApplication()
{
	return new SpaceShooter();
}
	
Engine::Application* Application;

