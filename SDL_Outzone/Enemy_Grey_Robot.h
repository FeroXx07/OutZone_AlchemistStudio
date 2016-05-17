#ifndef __GREY_ROBOT_H__
#define __GREY_ROBOT_H__

#include "Enemy.h"

class Enemy_GreyRobot : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	unsigned int lastTime = 0;
	Animation GRobot__0;
	Animation GRobot__22_5;
	Animation GRobot__45;
	Animation GRobot__67_5;
	Animation GRobot__90;
	Animation GRobot__112_5;
	Animation GRobot__135;
	Animation GRobot__157_5;
	Animation GRobot__180;
	Animation GRobot__202_5;
	Animation GRobot__225;
	Animation GRobot__247_5;
	Animation GRobot__270;
	Animation GRobot__292_5;
	Animation GRobot__315;
	Animation GRobot__337_5;

	Animation GRobot__w;
	Animation GRobot__wa;
	Animation GRobot__wd;
	Animation GRobot__a;
	Animation GRobot__s;
	Animation GRobot__sa;
	Animation GRobot__sd;
	Animation GRobot__d;

public:

	Enemy_GreyRobot(int x, int y);

	void Move();
	void Shoot();
};

#endif // __ENEMY_TURRET1_H__