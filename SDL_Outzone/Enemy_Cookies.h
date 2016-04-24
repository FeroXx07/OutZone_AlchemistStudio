#ifndef __ENEMY_COOKIES_H__
#define __ENEMY_COOKIES_H__

#include "Enemy.h"
#include "Path.h"
class Enemy_Cookies : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;
	Path path;
	iPoint original_pos;
public:

	Enemy_Cookies(int x, int y);

	void Move();
};

#endif // __ENEMY_COOKIES_H__