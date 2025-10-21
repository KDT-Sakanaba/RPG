#pragma once
#include "EnemyFactory.h"

class Enemy {
private:

	// 基本的なデータ
	int ID;
	int LVL;
	const char* NAME;
	int HP;
	int ATK;
	int DEF;
	int SPD;
	//int Gold;
	//int EXP;

	// データを持つもの
	Enemy* currentEnemy = nullptr;

public:

	// シングルトン科　やり直し
	static Enemy& EnemyInstance();

	// 初期化
	Enemy()
		: ID(0),LVL(0),NAME(0), HP(0), ATK(0), DEF(0), SPD(0) {
	}

	// 基礎データを持つ
	Enemy(const EnemyData& data)
		:ID (data.ID),
		LVL(data.LVL),
		NAME(data.NAME),
		HP(data.HP),
		ATK(data.ATK),
		DEF(data.DEF),
		SPD(data.SPD)
		//Gold(data.Gold),
		//EXP(data.EXP),
	{
	}

	// ゲッター
	int EnemyHPGet() { return currentEnemy->HP; }
	int EnemyATKGet() { return currentEnemy->ATK; }
	int EnemyDEFGet() { return currentEnemy->DEF; }
	int EnemySPDGet() { return currentEnemy->SPD; }

	// プレイヤーを作成
	void EnemySet();

	// 表示
	void EnemyState();

	// プレイヤーのレベルアップ
	void EnemyLvlUp();

	// 攻撃した時の処理
	void EnemyAttack(int PlayerDEF);

	// 攻撃された時の処理
	void EnemyDefence(int EnemyDEF);


};