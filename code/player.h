#pragma once
#include "PlayerFactory.h"

class Player {
private:
	//// シングルトン科
	//// コンストラクタとデストラクタ
	//Player() = default;
	//~Player() = default;

	// 基本的なデータ
	int LVL;
	int HP;
	int ATK;
	int DEF;
	int SPD;
	//int Gold;
	//int EXP;

	int a = 0;

public:

	////コピーと代入禁止
	//Player(const Player&) = default;
	//Player& operator = (const Player&) = default;
	//
	//// 最初にだけ生成する仕組み
	//static Player& PlayerInstance() {
	//	static Player instance;
	//	return instance;
	//}


	// シングルトン科　やり直し
	static Player& PlayerInstance();

	// こいつがエラーの原因です対処しておいてください
	Player() = default;
	
	// 基礎データを持つ

	Player(const PlayerDate& data)
		: LVL(data.LVL),
		HP(data.HP),
		ATK(data.ATK),
		DEF(data.DEF),
		SPD(data.SPD)
		//Gold(data.Gold),
		//EXP(data.EXP),
	{}

	// セッター
	//int PlayerHPSet(int hp) {
	//	HP = hp;
	//}

	// ゲッター
	int PlayerHPGet() { return HP; }
	int PlayerATKGet() { return ATK; }
	int PlayerDEFGet() { return DEF; }
	int PlayerSPDGet() { return SPD; }

	// プレイヤーを作成
	void PlayerSet();

	// プレイヤーのレベルアップ
	void PlayerLvlUp(int beforeLVL);

	// 攻撃した時の処理
	void PlayerAttack();

	// 攻撃された時の処理
	void PlayerDefence(int Enemy_ATK);


};
