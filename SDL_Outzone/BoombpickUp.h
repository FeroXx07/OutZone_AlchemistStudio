#ifndef __BOOMBPICKUP_H__
#define __BOOMBPICKUP_H__

#include "Enemy.h"

class BoombPickUp : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	unsigned int lastTime = 0;
	Animation BoombpickUp;
public:

	BoombPickUp(int x, int y);

};

#endif // __ENEMY_TURRET1_H__