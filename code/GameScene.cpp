#include "GameScene.h"
#include "View.h"
#include "Process.h"
#include <iostream>
enum {
	Enemy_Attack_1,
	Enemy_Attack_2,
	Enemy_Attack_3,
	ZENTAIKOUGEKI
};

void GameScene::Init()
{
	enemyPool = std::make_unique<ObjectPool<Enemy>>(ENEMY_MAX);

	// ‰Šúİ’è
	player.PlayerSet();
	PoolHandle<Enemy> enemy[ENEMY_MAX] = { enemyPool->Acquire(),enemyPool->Acquire(),enemyPool->Acquire() };
	for (int a = 0; a < ENEMY_MAX; a++) {
		enemy[a]->EnemyInstance();
		enemy[a]->EnemySet(a);
	}
}

void GameScene::Update(SceneManager* manager)
{

	
}

void GameScene::Exit()
{
}
