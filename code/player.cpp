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
	cout << "�v���C���[�̍U��" << endl;
	cout << PlayerATKGet() << "�̃_���[�W" << endl;
}

void Player::PlayerDefence(int EnemyATK)
{
	//PlayerHPSet(PlayerHPGet() - (EnemyATK - PlayerDEFGet()));
	cout << "�c��HP" << PlayerHPGet() << endl;
}
