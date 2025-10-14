#include "player.h"
#include <iostream>

using namespace std;

Player& Player::PlayerInstance()
{
	static Player instance;
	return instance;
}

void Player::PlayerSet()
{
	PlayerFactory::CreatePlayer(1);
}

void Player::PlayerLvlUp(int beforeLVL)
{
	PlayerFactory::CreatePlayer(beforeLVL + 1);
}

void Player::PlayerAttack()
{
	cout << "プレイヤーの攻撃" << endl;
	cout << PlayerATKGet() << "のダメージ" << endl;
}

void Player::PlayerDefence(int EnemyATK)
{
	//PlayerHPSet(PlayerHPGet() - (EnemyATK - PlayerDEFGet()));
	cout << "残りHP" << PlayerHPGet() << endl;
}
