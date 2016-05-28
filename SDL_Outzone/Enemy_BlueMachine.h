#ifndef __BLUE_MACHINE_H__
#define __BLUE_MACHINE_H__

#include "Enemy.h"

class Enemy_BlueMachine : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	unsigned int lastTime = 0;
	Animation BlueMachine;
	Animation BlueMachine__0;
	Animation BlueMachine__22_5;
	Animation BlueMachine__45;
	Animation BlueMachine__67_5;
	Animation BlueMachine__90;
	Animation BlueMachine__112_5;
	Animation BlueMachine__135;
	Animation BlueMachine__157_5;
	Animation BlueMachine__180;
	Animation BlueMachine__202_5;
	Animation BlueMachine__225;
	Animation BlueMachine__247_5;
	Animation BlueMachine__270;
	Animation BlueMachine__292_5;
	Animation BlueMachine__315;
	Animation BlueMachine__337_5;

public:

	Enemy_BlueMachine(int x, int y);

	void Move();
	void Shoot();
};

#endif // __ENEMY_TURRET1_H__