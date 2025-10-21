#pragma once
#include "EnemyData.h"

class Enemy;

// プレイヤーの生成をするファクトリー（なぜ作ったかわからないが敵に移設するので残す）
class EnemyFactory
{
	// プレイヤーのデータを管理する
	static const EnemyData EnemyTable[];
	// 上のサイズ
	static const int EnemyTableSize;

public:
	// レベルによって持ってくるデータが違う
	static Enemy* CreateEnemy(int ID,int LVL);
};