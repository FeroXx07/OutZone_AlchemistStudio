#ifndef __RED_MACHINE_H__
#define __RED_MACHINE_H__

#include "Enemy.h"

class Enemy_RedMachine : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	unsigned int lastTime = 0;
	Animation RedMachine__0;
	Animation RedMachine__22_5;
	Animation RedMachine__45;
	Animation RedMachine__67_5;
	Animation RedMachine__90;
	Animation RedMachine__112_5;
	Animation RedMachine__135;
	Animation RedMachine__157_5;
	Animation RedMachine__180;
	Animation RedMachine__202_5;
	Animation RedMachine__225;
	Animation RedMachine__247_5;
	Animation RedMachine__270;
	Animation RedMachine__292_5;
	Animation RedMachine__315;
	Animation RedMachine__337_5;

public:

	Enemy_RedMachine(int x, int y);

	void Move();
	void Shoot();
};

#endif // __ENEMY_TURRET1_H__