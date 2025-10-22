#include "EnemyFactory.h"
#include "Enemy.h"

// �f�[�^�������Ă���Ƃ���
const EnemyData EnemyFactory::EnemyTable[] = {
	// ID,���x��,���O,�̗�,�U����,�h���,���x
	{0,"�X���C��",10,10,5 },
	{1,"�S�u����",20,20,10},
	{2,"�S�[����",30,30,15},
	{3,"�h���S��",40,40,20},
	{4,"�X���C��",50,50,25},
};
// �f�[�^�̃T�C�Y���擾
const int EnemyFactory::EnemyTableSize = sizeof(EnemyTable) / sizeof(EnemyData);

// �v���C���[�̍쐬
Enemy* EnemyFactory::CreateEnemy(int ID) {
	for (int id = 0; id < EnemyTableSize; id++) {
		if (EnemyTable[id].ID == ID) {
			return new Enemy(EnemyTable[id]);
		}
	}

	return nullptr;

}