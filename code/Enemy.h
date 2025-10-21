#pragma once
#include "EnemyFactory.h"

class Enemy {
private:

	// ��{�I�ȃf�[�^
	int ID;
	int LVL;
	const char* NAME;
	int HP;
	int ATK;
	int DEF;
	int SPD;
	//int Gold;
	//int EXP;

	// �f�[�^��������
	Enemy* currentEnemy = nullptr;

public:

	// �V���O���g���ȁ@��蒼��
	static Enemy& EnemyInstance();

	// ������
	Enemy()
		: ID(0),LVL(0),NAME(0), HP(0), ATK(0), DEF(0), SPD(0) {
	}

	// ��b�f�[�^������
	Enemy(const EnemyData& data)
		:ID (data.ID),
		LVL(data.LVL),
		NAME(data.NAME),
		HP(data.HP),
		ATK(data.ATK),
		DEF(data.DEF),
		SPD(data.SPD)
		//Gold(data.Gold),
		//EXP(data.EXP),
	{
	}

	// �Q�b�^�[
	int EnemyHPGet() { return currentEnemy->HP; }
	int EnemyATKGet() { return currentEnemy->ATK; }
	int EnemyDEFGet() { return currentEnemy->DEF; }
	int EnemySPDGet() { return currentEnemy->SPD; }

	// �v���C���[���쐬
	void EnemySet();

	// �\��
	void EnemyState();

	// �v���C���[�̃��x���A�b�v
	void EnemyLvlUp();

	// �U���������̏���
	void EnemyAttack(int PlayerDEF);

	// �U�����ꂽ���̏���
	void EnemyDefence(int EnemyDEF);


};