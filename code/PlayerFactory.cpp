#include "PlayerFactory.h"
#include "player.h"

// �f�[�^�������Ă���Ƃ���
const PlayerData PlayerFactory::PlayerTable[] = {
	// ���x��,�̗�,�U����,�h���,���x
	{1,20,10,5},
	{2,35,20,10},
	{3,50,30,15},
	{4,65,40,20},
	{5,80,50,25},
};
// �f�[�^�̃T�C�Y���擾
const int PlayerFactory::PlayerTableSize = sizeof(PlayerTable) / sizeof(PlayerData);

// �v���C���[�̍쐬
Player* PlayerFactory::CreatePlayer(int LVL) {
	for (int lvl = 0; lvl < PlayerTableSize; lvl++) {
		if (PlayerTable[lvl].LVL == LVL) {
			return new Player(PlayerTable[lvl]);
		}
	}

	return nullptr;
}