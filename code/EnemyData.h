#pragma once
// プレイヤーを表す構造体
struct EnemyData {

	// Id
	int ID;
	// 種族
	const char* NAME;
	// 体力
	int HP;
	// 攻撃力
	int ATK;
	// 防御力
	int DEF;

};