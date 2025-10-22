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

	// State ä«óù
	GameState mode = GameState::Title;
	int keyPress;

	// ç≈èâÇ…çÏÇÈ
	Player& p1 = Player::PlayerInstance();
	ObjectPool<Enemy> enemyPool(3);
	p1.PlayerSet();

	PoolHandle<Enemy> enemy[3] = {enemyPool.Acquire(),enemyPool.Acquire(),enemyPool.Acquire()};
	for (int a = 0; a < 3; a++) {
		enemy[a]->EnemyInstance();
		enemy[a]->EnemySet(a);
	}

	// ä«óù
	while (mode != GameState::End) {
		switch (mode) {
			// É^ÉCÉgÉã
		case GameState::Title:
			cout << "1 to GAMESTART" << endl;
			cout << "ìGÇì|Çπ" << endl;

			cin >> keyPress;
			if (keyPress == 1) {
				mode = GameState::Game;
				keyPress = 0;
			}
			
			break;
	
			// ÉQÅ[ÉÄ
		case GameState::Game:

			cout << "--------------------" << endl;

			// ìGÇ∆ñ°ï˚ÇÃèÛë‘ÇÃï\é¶
			p1.PlayerState();
			for (int a = 0; a < 3; a++) {
				enemy[a]->EnemyState();
			}

			cout << "--------------------" << endl;

			// çUåÇï˚ñ@ÇÃëIë
			cout << "1-ìG1Ç…çUåÇ : 2-ìG2Ç…çUåÇ : 3-ìG3Ç…çUåÇ : 4-ìGëSëÃÇ…çUåÇ " << endl;

			cin >> keyPress;

			cout << "--------------------" << endl;

			// íPëÃÇÃìGÇ…çUåÇÇ∑ÇÈÇ∆Ç´ÇÃèàóù
			if (keyPress == 1 or keyPress == 2 or keyPress == 3) {
				if (enemy[keyPress - 1]->EnemyHPGet() >= 1) {
					cout << enemy[keyPress - 1]->EnemyNAMEGet() << "Ç÷";
					p1.PlayerAttack(enemy[keyPress - 1]->EnemyDEFGet());
					enemy[keyPress - 1]->EnemyDefence(p1.PlayerATKGet());
					if (enemy[keyPress - 1]->EnemyHPGet() > 0) {
						enemy[keyPress - 1]->EnemyAttack(p1.PlayerDEFGet());
						p1.PlayerDefence(enemy[keyPress - 1]->EnemyATKGet());
					}
					else {
						cout << enemy[keyPress - 1]->EnemyNAMEGet() << "Çì|ÇµÇΩ" << endl;
						cout << "ÉåÉxÉãÉAÉbÉvÇµÇΩ" << endl;
						p1.PlayerLvlUp();
					}
				}
				else {
					cout << "ÇªÇ±Ç…ÇÕìGÇÕÇ¢Ç»Ç¢" << endl;
				}
			}

			// ìGëSëÃÇ…çUåÇÇµÇΩéûÇÃèàóù
			if (keyPress == 4) {
				for (int e_num = 0; e_num < 3; e_num++) {
					if (enemy[e_num]->EnemyHPGet() >= 1) {
						cout << enemy[e_num]->EnemyNAMEGet() << "Ç÷";
						p1.PlayerAttack(enemy[e_num]->EnemyDEFGet());
						enemy[e_num]->EnemyDefence(p1.PlayerATKGet());
						if (enemy[e_num]->EnemyHPGet() <= 0) {
							cout << enemy[e_num]->EnemyNAMEGet() << "Çì|ÇµÇΩ" << endl;
							cout << "ÉåÉxÉãÉAÉbÉvÇµÇΩ" << endl;
							p1.PlayerLvlUp();
						}
					}
					else {
						cout << "ÇªÇ±Ç…ÇÕìGÇÕÇ¢Ç»Ç¢" << endl;
					}
				}

				// àÍî‘çUåÇóÕÇÃçÇÇ¢ìGÇ™çUåÇÇµÇƒÇ≠ÇÈèàóù
				int max_power = 0;
				for (int e_num = 0; e_num < 3; e_num++) {
					if (enemy[e_num]->EnemyHPGet() >= 1 and max_power <= enemy[e_num]->EnemyATKGet()) {
						max_power = enemy[e_num]->EnemyATKGet();
					}
					if (e_num == 2 and max_power >= 0) {
						cout << "ìGÇÃçUåÇ" << endl;
						cout << max_power - p1.PlayerDEFGet() << "ÇÃÉ_ÉÅÅ[ÉW" << endl;
						p1.PlayerDefence(max_power);
					}
				}
				
			}

			// ìGÇÇ∑Ç◊Çƒì|ÇµÇΩÇÁÉQÅ[ÉÄÉNÉäÉA
			if (enemy[0]->EnemyHPGet() <= 0 and enemy[1]->EnemyHPGet() <= 0 and enemy[2]->EnemyHPGet() <= 0) {
				cout << "--------------------" << endl;
				mode = GameState::End;
				cout << "YOU WIN" << endl;
				cout << "--------------------" << endl;
			}
			// ìGÇ…ì|Ç≥ÇÍÇΩÇÁÉQÅ[ÉÄÉIÅ[ÉoÅ[
			if (p1.PlayerHPGet() <= 0) {
				cout << "--------------------" << endl;
				mode = GameState::End;
				cout << "YOU LOSE" << endl;
				cout << "--------------------" << endl;
			}
			break;
	
			// Ç±ÇÍÇÕÇ¢ÇÁÇ»Ç¢
		case GameState::End:

			break;
		}
	}


}