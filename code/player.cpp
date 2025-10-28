#include "player.h"
#include <iostream>

using namespace std;

// プレイヤーのインスタンスの生成
Player& Player::PlayerInstance()
{
	static Player instance;
	return instance;
}

// プレイヤーの設定
void Player::PlayerSet()
{
	currentPlayer = PlayerFactory::CreatePlayer(1);
}

// プレイヤーが敵を倒したときにレベルアップする処理
void Player::PlayerLvlUp()
{
	currentPlayer = PlayerFactory::CreatePlayer(currentPlayer->LVL + 1);
}

// プレイヤーが敵の攻撃を攻撃されたときの処理
void Player::PlayerDefence(int EnemyATK)
{
	currentPlayer->HP = currentPlayer->HP - (EnemyATK - currentPlayer->DEF);
}