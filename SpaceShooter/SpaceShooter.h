#pragma once

#include <Application.h>

class UI;

class SpaceShooter : public Engine::Application {};

Engine::Application* Engine::CreateApplication()
{
	return new SpaceShooter();
}
	
Engine::Application* App;
UI* Ui;



