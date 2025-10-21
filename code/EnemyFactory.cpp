#include "EnemyFactory.h"
#include "Enemy.h"

// �f�[�^�������Ă���Ƃ���
const EnemyData EnemyFactory::EnemyTable[] = {
	// ID,���x��,���O,�̗�,�U����,�h���,���x
	{0,1,"�X���C��",10,10,5,10},
	{0,2,"�X���C��",20,20,20,20},
	{0,3,"�X���C��",30,30,30,30},
	{0,4,"�X���C��",40,40,40,40},
	{0,5,"�X���C��",50,50,50,50},
};
// �f�[�^�̃T�C�Y���擾
const int EnemyFactory::EnemyTableSize = sizeof(EnemyTable) / sizeof(EnemyData);

// �v���C���[�̍쐬
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