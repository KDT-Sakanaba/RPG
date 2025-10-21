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
	currentPlayer = PlayerFactory::CreatePlayer(1);
}

void Player::PlayerState()
{
	cout << "Player : ";
	cout << " : LVL " << currentPlayer->LVL;
	cout << " : HP " << currentPlayer->HP;
	cout << " : ATK " << currentPlayer->ATK;
	cout << " : DEF " << currentPlayer->DEF;
	cout << " : SPD " << currentPlayer->SPD << endl;
}

void Player::PlayerLvlUp()
{
	currentPlayer = PlayerFactory::CreatePlayer(currentPlayer->LVL + 1);
}

void Player::PlayerAttack(int EnemyDEF)
{
	cout << "プレイヤーの攻撃" << endl;
	cout << currentPlayer->ATK - EnemyDEF << "のダメージ" << endl;
}

void Player::PlayerDefence(int EnemyATK)
{
	currentPlayer->HP = currentPlayer->HP - (EnemyATK - currentPlayer->DEF);
}

void Player::PlayerHeal()
{
	currentPlayer->HP = currentPlayer->HP + 10;
}
