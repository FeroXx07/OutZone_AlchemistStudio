#ifndef __CHANGEAIM_H__
#define __CHANGEAIM_H__

#include "Enemy.h"

class ChangeAim : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	unsigned int lastTime = 0;

public:

	ChangeAim(int x, int y);

};

#endif // __ENEMY_TURRET1_H__