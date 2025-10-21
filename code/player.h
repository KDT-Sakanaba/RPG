#pragma once
#include "PlayerFactory.h"

class Player {
private:

	// ��{�I�ȃf�[�^
	int LVL;
	int HP;
	int ATK;
	int DEF;
	int SPD;
	//int Gold;
	//int EXP;

	// �f�[�^��������
	Player* currentPlayer = nullptr;

public:

	// �V���O���g���ȁ@��蒼��
	static Player& PlayerInstance();

	// ������
	Player()
		: LVL(0), HP(0), ATK(0), DEF(0), SPD(0) {
	}
	
	// ��b�f�[�^������
	Player(const PlayerData& data)
		: LVL(data.LVL),
		HP(data.HP),
		ATK(data.ATK),
		DEF(data.DEF),
		SPD(data.SPD)
		//Gold(data.Gold),
		//EXP(data.EXP),
	{}

	// �Q�b�^�[
	int PlayerHPGet() { return currentPlayer->HP; }
	int PlayerATKGet() { return currentPlayer->ATK; }
	int PlayerDEFGet() { return currentPlayer->DEF; }
	int PlayerSPDGet() { return currentPlayer->SPD; }

	// �v���C���[���쐬
	void PlayerSet();

	// �\��
	void PlayerState();

	// �v���C���[�̃��x���A�b�v
	void PlayerLvlUp();

	// �U���������̏���
	void PlayerAttack(int EnemyDEF);

	// �U�����ꂽ���̏���
	void PlayerDefence(int Enemy_ATK);

	void PlayerHeal();
};
