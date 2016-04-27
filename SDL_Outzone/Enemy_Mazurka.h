#ifndef __ENEMY_MAZURKA_H__
#define __ENEMY_MAZURKA_H__

#include "Enemy.h"

class Enemy_Mazurka : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;

	Animation Mazurka;
	Animation Mazurka1;

public:

	Enemy_Mazurka(int x, int y);

	void Move();
	void Shoot();

};

#endif // __ENEMY_MAZURKA_H__