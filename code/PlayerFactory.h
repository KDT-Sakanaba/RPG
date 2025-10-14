#pragma once
#include "PlayerDate.h"

class Player;

// �v���C���[�̐���������t�@�N�g���[�i�Ȃ���������킩��Ȃ����G�Ɉڐ݂���̂Ŏc���j
class PlayerFactory
{
	// �v���C���[�̃f�[�^���Ǘ�����
	static const PlayerDate PlayerTable[];
	// ��̃T�C�Y
	static const int PlayerTableSize;

public:
	// ���x���ɂ���Ď����Ă���f�[�^���Ⴄ
	static Player* CreatePlayer(int LVL);
};