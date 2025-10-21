#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy& Enemy::EnemyInstance()
{
	static Enemy instance;
	return instance;
}

void Enemy::EnemySet()
{
	currentEnemy = EnemyFactory::CreateEnemy(0,1);
}

void Enemy::EnemyState()
{
	cout << currentEnemy->NAME;
	cout << " : LVL " << currentEnemy->LVL;
	cout << " : HP " << currentEnemy->HP;
	cout << " : ATK " << currentEnemy->ATK;
	cout << " : DEF " << currentEnemy->DEF;
	cout << " : SPD " << currentEnemy->SPD << endl;
}

void Enemy::EnemyLvlUp()
{
	currentEnemy = EnemyFactory::CreateEnemy(currentEnemy->ID,currentEnemy->LVL + 1);
}

void Enemy::EnemyAttack(int PlayerDEF)
{
	cout << currentEnemy->NAME << "‚ÌUŒ‚" << endl;
	cout << currentEnemy->ATK - PlayerDEF << "‚Ìƒ_ƒ[ƒW" << endl;
}

void Enemy::EnemyDefence(int PlayerATK)
{
	currentEnemy->HP = currentEnemy->HP - (PlayerATK - currentEnemy->DEF);
}