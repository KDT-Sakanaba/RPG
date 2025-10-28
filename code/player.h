#pragma once
#include "PlayerFactory.h"

class Player {
private:

	// ��{�I�ȃf�[�^
	int LVL;
	int HP;
	int ATK;
	int DEF;

	// �f�[�^��������
	Player* currentPlayer = nullptr;

public:

	// �C���X�^���X�̐���
	static Player& PlayerInstance();

	// ������
	Player()
		: LVL(0), HP(0), ATK(0), DEF(0) {
	}
	
	// ��b�f�[�^������
	Player(const PlayerData& data)
		: LVL(data.LVL),
		HP(data.HP),
		ATK(data.ATK),
		DEF(data.DEF)
	{}

	// �Q�b�^�[
	int PlayerLVLGet() { return currentPlayer->LVL; }
	int PlayerHPGet() { return currentPlayer->HP; }
	int PlayerATKGet() { return currentPlayer->ATK; }
	int PlayerDEFGet() { return currentPlayer->DEF; }

	// �v���C���[�̐ݒ�
	void PlayerSet();

	//// �v���C���[�̃X�e�[�^�X�̕\��
	//void PlayerState();

	// �v���C���[�̃��x���A�b�v
	void PlayerLvlUp();

	// �U���������̏���
	//void PlayerAttack(int EnemyDEF);

	// �U�����ꂽ���̏���
	void PlayerDefence(int Enemy_ATK);
};
