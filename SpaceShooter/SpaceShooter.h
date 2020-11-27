#pragma once

#include <Application.h>
#include "PlayerContainer.h"
#include "LaserContainer.h"
#include "EnemyContainer.h"
	
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
Engine::RenderBase background;
PlayerContainer playerContainer;
LaserContainer laserContainer;
static EnemyContainer enemyContainer;
float spawnRate = 5;
float spawnTimer = 0;

