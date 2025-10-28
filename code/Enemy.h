#pragma once
#include "EnemyFactory.h"

class Enemy {
private:

	// ��{�I�ȃf�[�^
	int ID;
	const char* NAME;
	int HP;
	int ATK;
	int DEF;


	// �f�[�^��������
	Enemy* currentEnemy = nullptr;

public:

	// �V���O���g���ȁ@��蒼��
	static Enemy& EnemyInstance();

	// ������
	Enemy()
		: ID(0),NAME(0), HP(0), ATK(0), DEF(0) {
	}

	// ��b�f�[�^������
	Enemy(const EnemyData& data)
		:ID (data.ID),
		NAME(data.NAME),
		HP(data.HP),
		ATK(data.ATK),
		DEF(data.DEF)

	{
	}

	// �Q�b�^�[
	int EnemyIDGet() { return currentEnemy->ID; }
	const char* EnemyNAMEGet() { return currentEnemy->NAME; };
	int EnemyHPGet() { return currentEnemy->HP; }
	int EnemyATKGet() { return currentEnemy->ATK; }
	int EnemyDEFGet() { return currentEnemy->DEF; }
	auto EnemyStateGet() { return currentEnemy->NAME, currentEnemy->HP, currentEnemy->ATK, currentEnemy->DEF; }

	// �G�l�~�[�̐ݒ�
	void EnemySet(int num);

	//// �G�l�~�[�̃X�e�[�^�X�̕\��
	//void EnemyState();

	// �G�l�~�[�̍U���������̏���
	//void EnemyAttack(int PlayerDEF);

	// �G�l�~�[�̍U�����ꂽ���̏���
	void EnemyDefence(int EnemyDEF);


};