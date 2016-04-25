#ifndef __ENEMY_TURRET1_H__
#define __ENEMY_TURRET1_H__

#include "Enemy.h"

class Enemy_Turret1 : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	Animation Turret1;

public:

	Enemy_Turret1(int x, int y);

	void Move();
};

#endif // __ENEMY_TURRET1_H__