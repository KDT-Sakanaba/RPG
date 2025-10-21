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

void key_check() {

}

int main() {

	GameState mode = GameState::Title;
	int keyPress;

	Player& p1 = Player::PlayerInstance();
	ObjectPool<Enemy> enemyPool(3);
	p1.PlayerSet();

	auto enemy1 = enemyPool.Acquire();
	enemy1->EnemyInstance();
	enemy1->EnemySet();

	auto enemy2 = enemyPool.Acquire();
	enemy2->EnemyInstance();
	enemy2->EnemySet();

	auto enemy3 = enemyPool.Acquire();
	enemy3->EnemyInstance();
	enemy3->EnemySet();

	while (mode != GameState::End) {
		switch (mode) {
		case GameState::Title:
			cout << "1 to GAMESTART" << endl;
			cout << "“G‚ð“|‚¹" << endl;
			cin >> keyPress;
			if (keyPress == 1) {
				mode = GameState::Game;
				keyPress = 0;
			}
			
			break;
	
		case GameState::Game:

			p1.PlayerState();
			enemy1->EnemyState();

			cin >> keyPress;
			if (keyPress == 1) {
				p1.PlayerAttack(enemy1->EnemyDEFGet()); 
				enemy1->EnemyDefence(p1.PlayerATKGet());
				if (enemy1->EnemyHPGet() >= 1) {
					enemy1->EnemyAttack(p1.PlayerDEFGet());
					p1.PlayerDefence(enemy1->EnemyATKGet());
				}
				else {
					mode = GameState::End;
				}
			}

			cout << endl;

			break;
	
		case GameState::End:
	
			break;
		}
	}


}