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
	currentEnemy = EnemyFactory::CreateEnemy((std::rand() + num) % 4);
}

// エネミーのステータスの表示
void Enemy::EnemyState()
{
	cout << currentEnemy->NAME;
	cout << " : HP " << currentEnemy->HP;
	cout << " : ATK " << currentEnemy->ATK;
	cout << " : DEF " << currentEnemy->DEF << endl;
}

// エネミーが攻撃した時の処理
void Enemy::EnemyAttack(int PlayerDEF)
{
	cout << currentEnemy->NAME << "の攻撃" << endl;
	cout << currentEnemy->ATK - PlayerDEF << "のダメージ" << endl;
}

// エネミーが攻撃を受けた時の処理
void Enemy::EnemyDefence(int PlayerATK)
{
	if (PlayerATK - currentEnemy->DEF <= 0) {
		PlayerATK = currentEnemy->DEF + 1;
	}
	
	currentEnemy->HP = currentEnemy->HP - (PlayerATK - currentEnemy->DEF);
}