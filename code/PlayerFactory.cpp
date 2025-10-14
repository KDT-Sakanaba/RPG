#include "PlayerFactory.h"
#include "player.h"

// �f�[�^�������Ă���Ƃ���
const PlayerDate PlayerFactory::PlayerTable[] = {
	// ���x��,�̗�,�U����,�h���,���x
	{1,10,10,10,10},
	{2,20,20,20,20},
	{3,30,30,30,30},
	{4,40,40,40,40},
	{5,50,50,50,50},
};
// �f�[�^�̃T�C�Y���擾
const int PlayerFactory::PlayerTableSize = sizeof(PlayerTable) / sizeof(PlayerDate);

// �v���C���[�̍쐬
Player* PlayerFactory::CreatePlayer(int LVL) {
	for (int lvl = 0; lvl < PlayerTableSize; lvl++) {
		if (PlayerTable[lvl].LVL == LVL) {
			return new Player(PlayerTable[lvl]);
		}
	}

	return nullptr;

}