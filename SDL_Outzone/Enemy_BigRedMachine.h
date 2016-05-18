#ifndef __BIG_RED_MACHINE_H__
#define __BIG_RED_MACHINE_H__

#include "Enemy.h"

class Enemy_BigRedMachine : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	unsigned int lastTime = 0;


public:

	Enemy_BigRedMachine(int x, int y);


};

#endif // __ENEMY_TURRET1_H__