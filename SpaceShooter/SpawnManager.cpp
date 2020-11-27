#include "SpawnManager.h"

void SpawnManager::AddWave(Uint8 spawnWaveCount, EnemyContainer& enemy)
{
	if (spawnWaveCount == 0)
		return;

	short intervalPosX = 1440 / (spawnWaveCount + 1);
	short posY = -enemy.TextureHeight;
	short width = enemy.TextureWidth;
	short height = enemy.TextureHeight;

	for(Uint8 count = 1; count <= spawnWaveCount; count++)
	{
		enemy.Add(intervalPosX * count, posY, width, height);
	}
}
