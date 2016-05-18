#ifndef __ORANGE_ROBOT_H__
#define __ORANGE_ROBOT_H__

#include "Enemy.h"

class Enemy_OrangeRobot : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	unsigned int lastTime = 0;
	Animation OrangeRobot__0;
	Animation OrangeRobot__22_5;
	Animation OrangeRobot__45;
	Animation OrangeRobot__67_5;
	Animation OrangeRobot__90;
	Animation OrangeRobot__112_5;
	Animation OrangeRobot__135;
	Animation OrangeRobot__157_5;
	Animation OrangeRobot__180;
	Animation OrangeRobot__202_5;
	Animation OrangeRobot__225;
	Animation OrangeRobot__247_5;
	Animation OrangeRobot__270;
	Animation OrangeRobot__292_5;
	Animation OrangeRobot__315;
	Animation OrangeRobot__337_5;

public:

	Enemy_OrangeRobot(int x, int y);

	void Move();
	void Shoot();
};

#endif // __ENEMY_TURRET1_H__