#pragma once
#include "EnemyFactory.h"

class Enemy {
private:

	// 基本的なデータ
	int ID;
	const char* NAME;
	int HP;
	int ATK;
	int DEF;


	// データを持つもの
	Enemy* currentEnemy = nullptr;

public:

	// シングルトン科　やり直し
	static Enemy& EnemyInstance();

	// 初期化
	Enemy()
		: ID(0),NAME(0), HP(0), ATK(0), DEF(0) {
	}

	// 基礎データを持つ
	Enemy(const EnemyData& data)
		:ID (data.ID),
		NAME(data.NAME),
		HP(data.HP),
		ATK(data.ATK),
		DEF(data.DEF)

	{
	}

	// ゲッター
	int EnemyIDGet() { return currentEnemy->ID; }
	const char* EnemyNAMEGet() { return currentEnemy->NAME; };
	int EnemyHPGet() { return currentEnemy->HP; }
	int EnemyATKGet() { return currentEnemy->ATK; }
	int EnemyDEFGet() { return currentEnemy->DEF; }
	auto EnemyStateGet() { return currentEnemy->NAME, currentEnemy->HP, currentEnemy->ATK, currentEnemy->DEF; }

	// エネミーの設定
	void EnemySet(int num);

	//// エネミーのステータスの表示
	//void EnemyState();

	// エネミーの攻撃した時の処理
	//void EnemyAttack(int PlayerDEF);

	// エネミーの攻撃された時の処理
	void EnemyDefence(int EnemyDEF);


};