#pragma once

#include <Application.h>
#include "PlayerContainer.h"
#include "LaserContainer.h"
#include "EnemyContainer.h"
#include "SpawnManager.h"
	
class SpaceShooter : public Engine::Application
{
public:
private:
};

Engine::Application* Engine::CreateApplication()
{
	return new SpaceShooter();
}
	
Engine::Application* App;
SDL_Texture* _backgroundTexture;
SDL_Texture* _ui;
Engine::RenderBase background;
PlayerContainer playerContainer;
LaserContainer laserContainer;
EnemyContainer enemyContainer;
SpawnManager spawnManager;

