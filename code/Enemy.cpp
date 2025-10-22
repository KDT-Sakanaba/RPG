#include "Enemy.h"
#include <iostream>

using namespace std;

// �G�l�~�[�̃C���X�^���X�̐���
Enemy& Enemy::EnemyInstance()
{
	static Enemy instance;
	return instance;
}

// �G�l�~�[�̐ݒ�
void Enemy::EnemySet(int num)
{
	std::srand(std::time(0)); // ���ݎ������^�������̃V�[�h�l�Ƃ���B
	currentEnemy = EnemyFactory::CreateEnemy((std::rand() + num) % 4);
}

// �G�l�~�[�̃X�e�[�^�X�̕\��
void Enemy::EnemyState()
{
	cout << currentEnemy->NAME;
	cout << " : HP " << currentEnemy->HP;
	cout << " : ATK " << currentEnemy->ATK;
	cout << " : DEF " << currentEnemy->DEF << endl;
}

// �G�l�~�[���U���������̏���
void Enemy::EnemyAttack(int PlayerDEF)
{
	cout << currentEnemy->NAME << "�̍U��" << endl;
	cout << currentEnemy->ATK - PlayerDEF << "�̃_���[�W" << endl;
}

// �G�l�~�[���U�����󂯂����̏���
void Enemy::EnemyDefence(int PlayerATK)
{
	if (PlayerATK - currentEnemy->DEF <= 0) {
		PlayerATK = currentEnemy->DEF + 1;
	}
	
	currentEnemy->HP = currentEnemy->HP - (PlayerATK - currentEnemy->DEF);
}