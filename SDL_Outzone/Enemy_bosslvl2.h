#ifndef __BOSS_H__
#define __BOSS_H__

#include "Enemy.h"

class Enemy_Boss : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	unsigned int lastTime = 0;
	bool firsttime = true;
	Animation Bosslvl2idle;
	Animation Bosslvl2move;
	int count;

public:
	int movement = 0;

public:
	Enemy_Boss(int x, int y);
	void Move();
	void Shoot();
};

#endif // __ENEMY_TURRET1_H__