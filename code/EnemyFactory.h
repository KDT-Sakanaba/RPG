#pragma once
#include "EnemyData.h"

class Enemy;

// �v���C���[�̐���������t�@�N�g���[�i�Ȃ���������킩��Ȃ����G�Ɉڐ݂���̂Ŏc���j
class EnemyFactory
{
	// �v���C���[�̃f�[�^���Ǘ�����
	static const EnemyData EnemyTable[];
	// ��̃T�C�Y
	static const int EnemyTableSize;

public:
	// ���x���ɂ���Ď����Ă���f�[�^���Ⴄ
	static Enemy* CreateEnemy(int ID,int LVL);
};