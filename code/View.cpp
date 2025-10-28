#include "View.h"
#include <iostream>

using namespace std;

void View::Start()
{
	cout << "1 to GAMESTART" << endl;
	cout << "“G‚ð“|‚¹" << endl;
}

void View::No()
{
	cout << "‚»‚±‚É‚Í“G‚Í‚¢‚È‚¢" << endl;
}

void View::PlayerState(int LVL, int HP, int ATK, int DEF)
{
	cout << "--------------------" << endl;
	cout << "Player";
	cout << " : LVL " << LVL;
	cout << " : HP " <<  HP;
	cout << " : ATK " << ATK;
	cout << " : DEF " << DEF << endl;
}

void View::EnemyState(const char* NAME, int HP, int ATK, int DEF) {
	cout << NAME;
	cout << " : HP " << HP;
	cout << " : ATK " << ATK;
	cout << " : DEF " << DEF << endl;
}

void View::LOG()
{
	cout << "--------------------" << endl;
	// UŒ‚•û–@‚Ì‘I‘ð
	cout << "1-“G1‚ÉUŒ‚ : 2-“G2‚ÉUŒ‚ : 3-“G3‚ÉUŒ‚ : 4-“G‘S‘Ì‚ÉUŒ‚ " << endl;
}

void View::Attack(const char* NAME, int Patk, int Edef)
{
	cout << NAME << "‚Ö";
	cout << "ƒvƒŒƒCƒ„[‚ÌUŒ‚" << endl;
	if (Patk - Edef >= 1) {
		cout << Patk - Edef << "‚Ìƒ_ƒ[ƒW" << endl;
	}
	else {
		cout << "1‚Ìƒ_ƒ[ƒW" << endl;
	}
}

void View::Defence(const char* NAME, int Eatk, int Pdef)
{
	cout << NAME << "‚ÌUŒ‚" << endl;
	cout << Eatk - Pdef << "‚Ìƒ_ƒ[ƒW" << endl;
}

void View::OUT(const char* NAME)
{
	cout << NAME << "‚ð“|‚µ‚½" << endl;
	cout << "ƒŒƒxƒ‹ƒAƒbƒv‚µ‚½" << endl;
}

void View::Damage(int power,int Pdef)
{
	cout << "“G‚ÌUŒ‚" << endl;
	cout << power - Pdef << "‚Ìƒ_ƒ[ƒW" << endl;
}

void View::WIN() {

	cout << "--------------------" << endl;
	cout << "YOU WIN" << endl;
	cout << "--------------------" << endl;

}

void View::LOSE() {

	cout << "--------------------" << endl;
	cout << "YOU LOSE" << endl;
	cout << "--------------------" << endl;
}