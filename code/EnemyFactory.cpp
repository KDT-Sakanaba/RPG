#include "EnemyFactory.h"
#include "Enemy.h"

// データを持っているところ
const EnemyData EnemyFactory::EnemyTable[] = {
	// ID,レベル,名前,体力,攻撃力,防御力,速度
	{0,1,"スライム",10,10,5,10},
	{0,2,"スライム",20,20,20,20},
	{0,3,"スライム",30,30,30,30},
	{0,4,"スライム",40,40,40,40},
	{0,5,"スライム",50,50,50,50},
};
// データのサイズを取得
const int EnemyFactory::EnemyTableSize = sizeof(EnemyTable) / sizeof(EnemyData);

// プレイヤーの作成
Enemy* EnemyFactory::CreateEnemy(int ID,int LVL) {
	for (int id = 0; id < EnemyTableSize; id++) {
		for (int lvl = 0; lvl < EnemyTableSize; lvl++) {
			if (EnemyTable[id].ID == ID) {
				if (EnemyTable[lvl].LVL == LVL) {
					return new Enemy(EnemyTable[id,lvl]);
				}
			}
		}
	}

	return nullptr;

}