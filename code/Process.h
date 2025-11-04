#pragma once

#include <iostream>
#include "player.h"
#include "Enemy.h"
#include "View.h"
#include "Pool.h"

class Process {

private:

	// ‚±‚¢‚Â‚Ç‚¤‚É‚©‚µ‚ë
	View view;

public:

	void AttackPrcess(Player& player,PoolHandle<Enemy>&enemy);
};