#include "View.h"
#include <iostream>

using namespace std;

void View::Start()
{
	cout << "1 to GAMESTART" << endl;
	cout << "�G��|��" << endl;
}

void View::No()
{
	cout << "�����ɂ͓G�͂��Ȃ�" << endl;
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
	// �U�����@�̑I��
	cout << "1-�G1�ɍU�� : 2-�G2�ɍU�� : 3-�G3�ɍU�� : 4-�G�S�̂ɍU�� " << endl;
}

void View::Attack(const char* NAME, int Patk, int Edef)
{
	cout << NAME << "��";
	cout << "�v���C���[�̍U��" << endl;
	if (Patk - Edef >= 1) {
		cout << Patk - Edef << "�̃_���[�W" << endl;
	}
	else {
		cout << "1�̃_���[�W" << endl;
	}
}

void View::Defence(const char* NAME, int Eatk, int Pdef)
{
	cout << NAME << "�̍U��" << endl;
	cout << Eatk - Pdef << "�̃_���[�W" << endl;
}

void View::OUT(const char* NAME)
{
	cout << NAME << "��|����" << endl;
	cout << "���x���A�b�v����" << endl;
}

void View::Damage(int power,int Pdef)
{
	cout << "�G�̍U��" << endl;
	cout << power - Pdef << "�̃_���[�W" << endl;
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