#pragma once
#include <SDL_stdinc.h>
#include "EnemyContainer.h"

typedef struct SpawnManager
{
	float SpawnTimer = 0;
	Uint8 EnemySpawnRate = 3;
	void AddWave(Uint8 count, EnemyContainer& enemyContainer);
	Uint8 SpawnWaveCount = 0;
}SpawnManager;

