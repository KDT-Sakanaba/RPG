#include "PlayerFactory.h"
#include "player.h"

// データを持っているところ
const PlayerData PlayerFactory::PlayerTable[] = {
	// レベル,体力,攻撃力,防御力,速度
	{1,10,10,5,10},
	{2,20,20,20,20},
	{3,30,30,30,30},
	{4,40,40,40,40},
	{5,50,50,50,50},
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