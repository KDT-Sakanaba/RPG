#include "Process.h"

void Process::AttackPrcess(Player& player, PoolHandle<Enemy>& enemy)
{
	if (enemy->EnemyHPGet() > 0) {
		view.Attack(enemy->EnemyNAMEGet(), player.PlayerATKGet(), enemy->EnemyDEFGet());
		enemy->EnemyDefence(player.PlayerATKGet());
		if (enemy->EnemyHPGet() > 0) {
			view.Defence(enemy->EnemyNAMEGet(), enemy->EnemyATKGet(), player.PlayerDEFGet());
			player.PlayerDefence(enemy->EnemyATKGet());
		}
		else {
			view.OUT(enemy->EnemyNAMEGet());
			player.PlayerLvlUp();
		}
	}
	else {
		view.No();
	}

}
