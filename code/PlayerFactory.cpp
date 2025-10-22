#include "PlayerFactory.h"
#include "player.h"

// データを持っているところ
const PlayerData PlayerFactory::PlayerTable[] = {
	// レベル,体力,攻撃力,防御力,速度
	{1,20,10,5},
	{2,35,20,10},
	{3,50,30,15},
	{4,65,40,20},
	{5,80,50,25},
};
// データのサイズを取得
const int PlayerFactory::PlayerTableSize = sizeof(PlayerTable) / sizeof(PlayerData);

// プレイヤーの作成
Player* PlayerFactory::CreatePlayer(int LVL) {
	for (int lvl = 0; lvl < PlayerTableSize; lvl++) {
		if (PlayerTable[lvl].LVL == LVL) {
			return new Player(PlayerTable[lvl]);
		}
	}

	return nullptr;
}