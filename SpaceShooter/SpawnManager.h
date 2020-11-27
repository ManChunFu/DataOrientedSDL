#pragma once
#include <SDL_stdinc.h>
#include "EnemyContainer.h"
struct SpawnManager
{
public:
	float SpawnTimer = 0;
	Uint8 EnemySpawnRate = 5;
	void AddWave(Uint8 count, EnemyContainer& enemy);
private:
	Uint8 _spawnWaveCount;
	void SpawnWave(EnemyContainer& enemy);
};

