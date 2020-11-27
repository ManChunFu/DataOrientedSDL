#include "SpawnManager.h"

void SpawnManager::AddWave(Uint8 spawnWaveCount, EnemyContainer& enemyContainer)
{
	if (spawnWaveCount == 0)
		return;

	short intervalPosX = 1440 / (spawnWaveCount + 1);
	short posY = -enemyContainer.TextureHeight;
	short width = enemyContainer.TextureWidth;
	short height = enemyContainer.TextureHeight;

	for(Uint8 count = 1; count <= spawnWaveCount; count++)
	{
		enemyContainer.Add(intervalPosX * count, posY, width, height);
	}
}
