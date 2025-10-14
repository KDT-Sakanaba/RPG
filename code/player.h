#pragma once
#include "PlayerFactory.h"

class Player {
private:
	//// �V���O���g����
	//// �R���X�g���N�^�ƃf�X�g���N�^
	//Player() = default;
	//~Player() = default;

	// ��{�I�ȃf�[�^
	int LVL;
	int HP;
	int ATK;
	int DEF;
	int SPD;
	//int Gold;
	//int EXP;

	int a = 0;

public:

	////�R�s�[�Ƒ���֎~
	//Player(const Player&) = default;
	//Player& operator = (const Player&) = default;
	//
	//// �ŏ��ɂ�����������d�g��
	//static Player& PlayerInstance() {
	//	static Player instance;
	//	return instance;
	//}


	// �V���O���g���ȁ@��蒼��
	static Player& PlayerInstance();

	// �������G���[�̌����ł��Ώ����Ă����Ă�������
	Player() = default;
	
	// ��b�f�[�^������

	Player(const PlayerDate& data)
		: LVL(data.LVL),
		HP(data.HP),
		ATK(data.ATK),
		DEF(data.DEF),
		SPD(data.SPD)
		//Gold(data.Gold),
		//EXP(data.EXP),
	{}

	// �Z�b�^�[
	//int PlayerHPSet(int hp) {
	//	HP = hp;
	//}

	// �Q�b�^�[
	int PlayerHPGet() { return HP; }
	int PlayerATKGet() { return ATK; }
	int PlayerDEFGet() { return DEF; }
	int PlayerSPDGet() { return SPD; }

	// �v���C���[���쐬
	void PlayerSet();

	// �v���C���[�̃��x���A�b�v
	void PlayerLvlUp(int beforeLVL);

	// �U���������̏���
	void PlayerAttack();

	// �U�����ꂽ���̏���
	void PlayerDefence(int Enemy_ATK);


};
