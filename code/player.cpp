#include "player.h"
#include <iostream>

using namespace std;

// �v���C���[�̃C���X�^���X�̐���
Player& Player::PlayerInstance()
{
	static Player instance;
	return instance;
}

// �v���C���[�̐ݒ�
void Player::PlayerSet()
{
	currentPlayer = PlayerFactory::CreatePlayer(1);
}

// �v���C���[�̃X�e�[�^�X�̕\��
void Player::PlayerState()
{
	cout << "Player";
	cout << " : LVL " << currentPlayer->LVL;
	cout << " : HP " << currentPlayer->HP;
	cout << " : ATK " << currentPlayer->ATK;
	cout << " : DEF " << currentPlayer->DEF << endl;
}

// �v���C���[���G��|�����Ƃ��Ƀ��x���A�b�v���鏈��
void Player::PlayerLvlUp()
{
	currentPlayer = PlayerFactory::CreatePlayer(currentPlayer->LVL + 1);
}

// �v���C���[���G���U������Ƃ��̏���
void Player::PlayerAttack(int EnemyDEF)
{
	cout << "�v���C���[�̍U��" << endl;
	if (currentPlayer->ATK - EnemyDEF >= 1) {
		cout << currentPlayer->ATK - EnemyDEF << "�̃_���[�W" << endl;
	}
	else {
		cout << "1�̃_���[�W" << endl;
	}
}

// �v���C���[���G�̍U�����U�����ꂽ�Ƃ��̏���
void Player::PlayerDefence(int EnemyATK)
{
	currentPlayer->HP = currentPlayer->HP - (EnemyATK - currentPlayer->DEF);
}