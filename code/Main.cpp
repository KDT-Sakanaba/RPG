#include <stdio.h>
#include <iostream>
#include "player.h"
#include "Enemy.h"
#include "Pool.h"
#include "View.h"
#include "Process.h"

using namespace std;

#define ENEMY_MAX 3

enum class GameState {
	Title,
	Game,
	End
};

enum {
	Enemy_Attack_1,
	Enemy_Attack_2,
	Enemy_Attack_3,
	ZENTAIKOUGEKI
};

int main() {

	// State ŠÇ—
	GameState mode = GameState::Title;
	int keyPress;

	// Å‰‚Éì‚é
	Player& player = Player::PlayerInstance();
	ObjectPool<Enemy> enemyPool(ENEMY_MAX);
	// ‚±‚¢‚Â‚ğ‹¤—L‚µ‚½‚¢
	shared_ptr<View> view;
	unique_ptr<Process> process;


	// ‰Šúİ’è
	player.PlayerSet();
	PoolHandle<Enemy> enemy[ENEMY_MAX] = {enemyPool.Acquire(),enemyPool.Acquire(),enemyPool.Acquire()};
	for (int a = 0; a < ENEMY_MAX; a++) {
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

			view->PlayerState(player.PlayerLVLGet(), player.PlayerHPGet(), player.PlayerATKGet(), player.PlayerDEFGet());
			for (int e_num = 0; e_num < ENEMY_MAX; e_num++) {
				view->EnemyState(enemy[e_num]->EnemyNAMEGet(), enemy[e_num]->EnemyHPGet(), enemy[e_num]->EnemyATKGet(), enemy[e_num]->EnemyDEFGet());
			}
			view->LOG();

			cin >> keyPress;
			keyPress = keyPress - 1;
			
			cout << "--------------------" << endl;
			
			// ’P‘Ì‚Ì“G‚ÉUŒ‚‚·‚é‚Æ‚«‚Ìˆ—
			if (keyPress == Enemy_Attack_1 or keyPress == Enemy_Attack_2 or keyPress == Enemy_Attack_3) {
				process->AttackPrcess(player, enemy[keyPress]);
			}
			
			// “G‘S‘Ì‚ÉUŒ‚‚µ‚½‚Ìˆ—
			if (keyPress == ZENTAIKOUGEKI) {
				for (int e_num = 0; e_num < ENEMY_MAX; e_num++) {
					process->AttackPrcess(player, enemy[e_num]);
				}
			//
			//	// ˆê”ÔUŒ‚—Í‚Ì‚‚¢“G‚ªUŒ‚‚µ‚Ä‚­‚éˆ—
				//@‚±‚¢‚Â‚ğŠÈ’P‚É‚Ü‚Æ‚ß‚é
				int max_power = 0;
				for (int e_num = 0; e_num < ENEMY_MAX; e_num++) {
					if (enemy[e_num]->EnemyHPGet() > 0 and max_power <= enemy[e_num]->EnemyATKGet()) {
						max_power = enemy[e_num]->EnemyATKGet();
					}
					if (e_num == 2 and max_power >= 0) {
						view->Damage(max_power, player.PlayerDEFGet());
						player.PlayerDefence(max_power);
					}
				}
				
			}

			// ‚±‚±‚ğ‚¢‚¶‚é•K—v«‚È‚¢
			// “G‚ğ‚·‚×‚Ä“|‚µ‚½‚çƒQ[ƒ€ƒNƒŠƒA
			if (enemy[0]->EnemyHPGet() <= 0 and enemy[1]->EnemyHPGet() <= 0 and enemy[2]->EnemyHPGet() <= 0) {
				mode = GameState::End;
				view->WIN();
			}
			// “G‚É“|‚³‚ê‚½‚çƒQ[ƒ€ƒI[ƒo[
			if (player.PlayerHPGet() <= 0) {
				mode = GameState::End;
				view->LOSE();
			}

			break;
		}
	}


}