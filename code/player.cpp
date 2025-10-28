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

// �v���C���[���G��|�����Ƃ��Ƀ��x���A�b�v���鏈��
void Player::PlayerLvlUp()
{
	currentPlayer = PlayerFactory::CreatePlayer(currentPlayer->LVL + 1);
}

// �v���C���[���G�̍U�����U�����ꂽ�Ƃ��̏���
void Player::PlayerDefence(int EnemyATK)
{
	currentPlayer->HP = currentPlayer->HP - (EnemyATK - currentPlayer->DEF);
}