#include "EnemyFactory.h"
#include "Enemy.h"

// データを持っているところ
const EnemyData EnemyFactory::EnemyTable[] = {
	// ID,レベル,名前,体力,攻撃力,防御力,速度
	{0,"スライム",10,10,5 },
	{1,"ゴブリン",20,20,10},
	{2,"ゴーレム",30,30,15},
	{3,"ドラゴン",40,40,20},
	{4,"スライム",50,50,25},
};
// データのサイズを取得
const int EnemyFactory::EnemyTableSize = sizeof(EnemyTable) / sizeof(EnemyData);

// プレイヤーの作成
Enemy* EnemyFactory::CreateEnemy(int ID) {
	for (int id = 0; id < EnemyTableSize; id++) {
		if (EnemyTable[id].ID == ID) {
			return new Enemy(EnemyTable[id]);
		}
	}

	return nullptr;

}