#pragma once
#include "SceneManager.h"
#include <memory>
#include "player.h"
#include "Enemy.h"
#include "Pool.h"


class GameScene : public Scene
{
	const int ENEMY_MAX = 3;

	int keyPress;
	// Å‰‚Éì‚é
	Player& player = Player::PlayerInstance();
	std::unique_ptr<ObjectPool<Enemy>> enemyPool;
public:

	void Init() override;
	void Update(SceneManager* manager) override;
	void Exit() override;
};


