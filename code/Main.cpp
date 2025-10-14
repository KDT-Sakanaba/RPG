#include <stdio.h>
#include <iostream>
#include "player.h"

using namespace std;

int main() {

	Player& p1 = Player::PlayerInstance();

	p1.PlayerSet();

	p1.PlayerAttack();
}