#pragma once
#include "PlayerFactory.h"

class Player {
private:

	// 基本的なデータ
	int LVL;
	int HP;
	int ATK;
	int DEF;

	// データを持つもの
	Player* currentPlayer = nullptr;

public:

	// インスタンスの生成
	static Player& PlayerInstance();

	// 初期化
	Player()
		: LVL(0), HP(0), ATK(0), DEF(0) {
	}
	
	// 基礎データを持つ
	Player(const PlayerData& data)
		: LVL(data.LVL),
		HP(data.HP),
		ATK(data.ATK),
		DEF(data.DEF)
	{}

	// ゲッター
	int PlayerLVLGet() { return currentPlayer->LVL; }
	int PlayerHPGet() { return currentPlayer->HP; }
	int PlayerATKGet() { return currentPlayer->ATK; }
	int PlayerDEFGet() { return currentPlayer->DEF; }

	// プレイヤーの設定
	void PlayerSet();

	//// プレイヤーのステータスの表示
	//void PlayerState();

	// プレイヤーのレベルアップ
	void PlayerLvlUp();

	// 攻撃した時の処理
	//void PlayerAttack(int EnemyDEF);

	// 攻撃された時の処理
	void PlayerDefence(int Enemy_ATK);
};
