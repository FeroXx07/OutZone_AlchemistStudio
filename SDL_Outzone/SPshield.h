#ifndef __SPSHIELD_H__
#define __SPSHIELD_H__

#include "Enemy.h"

class SPshield : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	unsigned int lastTime = 0;
	Animation spshield;
public:

	SPshield(int x, int y);

};

#endif // __ENEMY_TURRET1_H__