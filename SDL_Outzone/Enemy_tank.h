#ifndef __ENEMY_TANK_H__
#define __ENEMY_TANK_H__

#include "Enemy.h"
#include "Path.h"
class Enemy_Tank : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation back;
	Animation front;
	Path path;
	iPoint original_pos;
public:

	Enemy_Tank(int x, int y);

	void Move();
};

#endif // __ENEMY_COOKIES_H__