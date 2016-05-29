#ifndef __BOSSAIM_H__
#define __BOSSAIM_H__

#include "Enemy.h"

class Enemy_Bossaim : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	unsigned int lastTime = 0;
	Animation BossAIMlvl2;
	int count;
public:

	Enemy_Bossaim(int x, int y);

	void Move();
	void Shoot();
};

#endif // __ENEMY_TURRET1_H__