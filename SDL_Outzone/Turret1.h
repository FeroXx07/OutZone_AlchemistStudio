#ifndef _ENEMY_TURRET1_H_
#define _ENEMY_TURRET1_H_

#include "Enemy.h"

class Enemy_Turret1 : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;

	Animation turret1__0;
	Animation turret1__22_5;
	Animation turret1__45;
	Animation turret1__67_5;
	Animation turret1__90;
	Animation turret1__112_5;
	Animation turret1__135;
	Animation turret1__157_5;
	Animation turret1__180;
	Animation turret1__202_5;
	Animation turret1__225;
	Animation turret1__247_5;
	Animation turret1__270;
	Animation turret1__292_5;
	Animation turret1__315;
	Animation turret1__337_5;



public:

	Enemy_Turret1(int x, int y);

	void Move();
};

#endif // __ENEMY_REDBIRD_H__