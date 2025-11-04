#include "Enemy.h"
#include <iostream>

using namespace std;

// エネミーのインスタンスの生成
Enemy& Enemy::EnemyInstance()
{
	static Enemy instance;
	return instance;
}

// エネミーの設定
void Enemy::EnemySet(int num)
{
	std::srand(std::time(0)); // 現在時刻を疑似乱数のシード値とする。
	currentEnemy = EnemyFactory::CreateEnemy((std::rand() + num) % Enemy_type);
}

// エネミーが攻撃を受けた時の処理
void Enemy::EnemyDefence(int PlayerATK)
{
	if (PlayerATK - currentEnemy->DEF <= 0) {
		PlayerATK = currentEnemy->DEF + 1;
	}
	
	currentEnemy->HP = currentEnemy->HP - (PlayerATK - currentEnemy->DEF);
}