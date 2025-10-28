#pragma once

class View {
private:

public:

	void Start();
	void No();

	void PlayerState(int LVL, int HP, int ATK, int DEF);
	void EnemyState(const char* NAME,int HP,int ATK,int DEF);

	void LOG();

	void Attack(const char* NAME,int Patk, int Edef);
	void Defence(const char* NAME, int Eatk, int Pdef);
	void OUT(const char* NAME);

	void Damage(int power, int Pdef);

	void WIN();
	void LOSE();

};