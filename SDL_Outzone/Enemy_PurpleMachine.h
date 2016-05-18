#ifndef __PURPLE_MACHINE_H__
#define __PURPLE_MACHINE_H__

#include "Enemy.h"

class Enemy_PurpleMachine : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	unsigned int lastTime = 0;
	Animation PurpleMachine__0;
	Animation PurpleMachine__22_5;
	Animation PurpleMachine__45;
	Animation PurpleMachine__67_5;
	Animation PurpleMachine__90;
	Animation PurpleMachine__112_5;
	Animation PurpleMachine__135;
	Animation PurpleMachine__157_5;
	Animation PurpleMachine__180;
	Animation PurpleMachine__202_5;
	Animation PurpleMachine__225;
	Animation PurpleMachine__247_5;
	Animation PurpleMachine__270;
	Animation PurpleMachine__292_5;
	Animation PurpleMachine__315;
	Animation PurpleMachine__337_5;

public:

	Enemy_PurpleMachine(int x, int y);

	void Move();
	void Shoot();
};

#endif // __ENEMY_TURRET1_H__