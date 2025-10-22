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

// プレイヤーのステータスの表示
void Player::PlayerState()
{
	cout << "Player";
	cout << " : LVL " << currentPlayer->LVL;
	cout << " : HP " << currentPlayer->HP;
	cout << " : ATK " << currentPlayer->ATK;
	cout << " : DEF " << currentPlayer->DEF << endl;
}

// プレイヤーが敵を倒したときにレベルアップする処理
void Player::PlayerLvlUp()
{
	currentPlayer = PlayerFactory::CreatePlayer(currentPlayer->LVL + 1);
}

// プレイヤーが敵を攻撃するときの処理
void Player::PlayerAttack(int EnemyDEF)
{
	cout << "プレイヤーの攻撃" << endl;
	if (currentPlayer->ATK - EnemyDEF >= 1) {
		cout << currentPlayer->ATK - EnemyDEF << "のダメージ" << endl;
	}
	else {
		cout << "1のダメージ" << endl;
	}
}

// プレイヤーが敵の攻撃を攻撃されたときの処理
void Player::PlayerDefence(int EnemyATK)
{
	currentPlayer->HP = currentPlayer->HP - (EnemyATK - currentPlayer->DEF);
}