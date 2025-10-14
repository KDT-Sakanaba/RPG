#include <stdio.h>
#include <iostream>
#include "player.h"

using namespace std;

int main() {

	Player::PlayerInstance().PlayerSet();
	Player::PlayerInstance().PlayerAttack();
}