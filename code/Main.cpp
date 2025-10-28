#include <stdio.h>
#include <iostream>
#include "player.h"
#include "Enemy.h"
#include "Pool.h"
#include "View.h"

using namespace std;

enum class GameState {
	Title,
	Game,
	End
};

int main() {

	// State ŠÇ—
	GameState mode = GameState::Title;
	int keyPress;

	// Å‰‚Éì‚é
	Player& p1 = Player::PlayerInstance();
	ObjectPool<Enemy> enemyPool(3);
	p1.PlayerSet();

	unique_ptr<View> view;

	PoolHandle<Enemy> enemy[3] = {enemyPool.Acquire(),enemyPool.Acquire(),enemyPool.Acquire()};
	for (int a = 0; a < 3; a++) {
		enemy[a]->EnemyInstance();
		enemy[a]->EnemySet(a);
	}

	// ŠÇ—
	while (mode != GameState::End) {
		switch (mode) {
			// ƒ^ƒCƒgƒ‹
		case GameState::Title:
			view->Start();

			cin >> keyPress;
			if (keyPress == 1) {
				mode = GameState::Game;
				keyPress = 0;
			}
			
			break;
	
			// ƒQ[ƒ€
		case GameState::Game:

			view->PlayerState(p1.PlayerLVLGet(), p1.PlayerHPGet(), p1.PlayerATKGet(), p1.PlayerDEFGet());
			for (int a = 0; a < 3; a++) {
				view->EnemyState(enemy[a]->EnemyNAMEGet(), enemy[a]->EnemyHPGet(), enemy[a]->EnemyATKGet(), enemy[a]->EnemyDEFGet());
			}
			view->LOG();

			cin >> keyPress;
			
			cout << "--------------------" << endl;
			
			// ’P‘Ì‚Ì“G‚ÉUŒ‚‚·‚é‚Æ‚«‚Ìˆ—
			if (keyPress == 1 or keyPress == 2 or keyPress == 3) {
				if (enemy[keyPress - 1]->EnemyHPGet() >= 1) {
					view->Attack(enemy[keyPress -1]->EnemyNAMEGet(),p1.PlayerATKGet(),enemy[keyPress-1]->EnemyDEFGet());
					enemy[keyPress - 1]->EnemyDefence(p1.PlayerATKGet());
					if (enemy[keyPress - 1]->EnemyHPGet() > 0) {
						view->Defence(enemy[keyPress - 1]->EnemyNAMEGet(), enemy[keyPress - 1]->EnemyATKGet(), p1.PlayerDEFGet());
						p1.PlayerDefence(enemy[keyPress - 1]->EnemyATKGet());
					}
					else {
						view->OUT(enemy[keyPress - 1]->EnemyNAMEGet());
						p1.PlayerLvlUp();
					}
				}
				else {
					view->No();
				}
			}
			
			// “G‘S‘Ì‚ÉUŒ‚‚µ‚½‚Ìˆ—
			if (keyPress == 4) {
				for (int e_num = 0; e_num < 3; e_num++) {
					if (enemy[e_num]->EnemyHPGet() >= 1) {
						view->Attack(enemy[e_num]->EnemyNAMEGet(), p1.PlayerATKGet(), enemy[e_num]->EnemyDEFGet());
						enemy[e_num]->EnemyDefence(p1.PlayerATKGet());
						if (enemy[e_num]->EnemyHPGet() <= 0) {
							view->OUT(enemy[e_num]->EnemyNAMEGet());
							p1.PlayerLvlUp();
						}
					}
					else {
						view->No();
					}
				}
			//
			//	// ˆê”ÔUŒ‚—Í‚Ì‚‚¢“G‚ªUŒ‚‚µ‚Ä‚­‚éˆ—
				int max_power = 0;
				for (int e_num = 0; e_num < 3; e_num++) {
					if (enemy[e_num]->EnemyHPGet() >= 1 and max_power <= enemy[e_num]->EnemyATKGet()) {
						max_power = enemy[e_num]->EnemyATKGet();
					}
					if (e_num == 2 and max_power >= 0) {
						view->Damage(max_power, p1.PlayerDEFGet());
						p1.PlayerDefence(max_power);
					}
				}
				
			}

			// “G‚ğ‚·‚×‚Ä“|‚µ‚½‚çƒQ[ƒ€ƒNƒŠƒA
			if (enemy[0]->EnemyHPGet() <= 0 and enemy[1]->EnemyHPGet() <= 0 and enemy[2]->EnemyHPGet() <= 0) {
				mode = GameState::End;
				view->WIN();
			}
			// “G‚É“|‚³‚ê‚½‚çƒQ[ƒ€ƒI[ƒo[
			if (p1.PlayerHPGet() <= 0) {
				mode = GameState::End;
				view->LOSE();
			}

			if (keyPress == 0) {
				mode = GameState::End;
			}

			break;
	
			// ‚±‚ê‚Í‚¢‚ç‚È‚¢
		case GameState::End:

			break;
		}
	}


}