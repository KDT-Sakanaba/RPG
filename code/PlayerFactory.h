#pragma once
#include "PlayerDate.h"

class Player;

// プレイヤーの生成をするファクトリー（なぜ作ったかわからないが敵に移設するので残す）
class PlayerFactory
{
	// プレイヤーのデータを管理する
	static const PlayerDate PlayerTable[];
	// 上のサイズ
	static const int PlayerTableSize;

public:
	// レベルによって持ってくるデータが違う
	static Player* CreatePlayer(int LVL);
};