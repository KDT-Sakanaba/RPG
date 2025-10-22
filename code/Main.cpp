#include <stdio.h>
#include <iostream>
#include "player.h"
#include "Enemy.h"
#include "Pool.h"

using namespace std;

enum class GameState {
	Title,
	Game,
	End
};

int main() {

	// State �Ǘ�
	GameState mode = GameState::Title;
	int keyPress;

	// �ŏ��ɍ��
	Player& p1 = Player::PlayerInstance();
	ObjectPool<Enemy> enemyPool(3);
	p1.PlayerSet();

	PoolHandle<Enemy> enemy[3] = {enemyPool.Acquire(),enemyPool.Acquire(),enemyPool.Acquire()};
	for (int a = 0; a < 3; a++) {
		enemy[a]->EnemyInstance();
		enemy[a]->EnemySet(a);
	}

	// �Ǘ�
	while (mode != GameState::End) {
		switch (mode) {
			// �^�C�g��
		case GameState::Title:
			cout << "1 to GAMESTART" << endl;
			cout << "�G��|��" << endl;

			cin >> keyPress;
			if (keyPress == 1) {
				mode = GameState::Game;
				keyPress = 0;
			}
			
			break;
	
			// �Q�[��
		case GameState::Game:

			cout << "--------------------" << endl;

			// �G�Ɩ����̏�Ԃ̕\��
			p1.PlayerState();
			for (int a = 0; a < 3; a++) {
				enemy[a]->EnemyState();
			}

			cout << "--------------------" << endl;

			// �U�����@�̑I��
			cout << "1-�G1�ɍU�� : 2-�G2�ɍU�� : 3-�G3�ɍU�� : 4-�G�S�̂ɍU�� " << endl;

			cin >> keyPress;

			cout << "--------------------" << endl;

			// �P�̂̓G�ɍU������Ƃ��̏���
			if (keyPress == 1 or keyPress == 2 or keyPress == 3) {
				if (enemy[keyPress - 1]->EnemyHPGet() >= 1) {
					cout << enemy[keyPress - 1]->EnemyNAMEGet() << "��";
					p1.PlayerAttack(enemy[keyPress - 1]->EnemyDEFGet());
					enemy[keyPress - 1]->EnemyDefence(p1.PlayerATKGet());
					if (enemy[keyPress - 1]->EnemyHPGet() > 0) {
						enemy[keyPress - 1]->EnemyAttack(p1.PlayerDEFGet());
						p1.PlayerDefence(enemy[keyPress - 1]->EnemyATKGet());
					}
					else {
						cout << enemy[keyPress - 1]->EnemyNAMEGet() << "��|����" << endl;
						cout << "���x���A�b�v����" << endl;
						p1.PlayerLvlUp();
					}
				}
				else {
					cout << "�����ɂ͓G�͂��Ȃ�" << endl;
				}
			}

			// �G�S�̂ɍU���������̏���
			if (keyPress == 4) {
				for (int e_num = 0; e_num < 3; e_num++) {
					if (enemy[e_num]->EnemyHPGet() >= 1) {
						cout << enemy[e_num]->EnemyNAMEGet() << "��";
						p1.PlayerAttack(enemy[e_num]->EnemyDEFGet());
						enemy[e_num]->EnemyDefence(p1.PlayerATKGet());
						if (enemy[e_num]->EnemyHPGet() <= 0) {
							cout << enemy[e_num]->EnemyNAMEGet() << "��|����" << endl;
							cout << "���x���A�b�v����" << endl;
							p1.PlayerLvlUp();
						}
					}
					else {
						cout << "�����ɂ͓G�͂��Ȃ�" << endl;
					}
				}

				// ��ԍU���͂̍����G���U�����Ă��鏈��
				int max_power = 0;
				for (int e_num = 0; e_num < 3; e_num++) {
					if (enemy[e_num]->EnemyHPGet() >= 1 and max_power <= enemy[e_num]->EnemyATKGet()) {
						max_power = enemy[e_num]->EnemyATKGet();
					}
					if (e_num == 2 and max_power >= 0) {
						cout << "�G�̍U��" << endl;
						cout << max_power - p1.PlayerDEFGet() << "�̃_���[�W" << endl;
						p1.PlayerDefence(max_power);
					}
				}
				
			}

			// �G�����ׂē|������Q�[���N���A
			if (enemy[0]->EnemyHPGet() <= 0 and enemy[1]->EnemyHPGet() <= 0 and enemy[2]->EnemyHPGet() <= 0) {
				cout << "--------------------" << endl;
				mode = GameState::End;
				cout << "YOU WIN" << endl;
				cout << "--------------------" << endl;
			}
			// �G�ɓ|���ꂽ��Q�[���I�[�o�[
			if (p1.PlayerHPGet() <= 0) {
				cout << "--------------------" << endl;
				mode = GameState::End;
				cout << "YOU LOSE" << endl;
				cout << "--------------------" << endl;
			}
			break;
	
			// ����͂���Ȃ�
		case GameState::End:

			break;
		}
	}


}