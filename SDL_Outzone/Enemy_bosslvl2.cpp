#include "Application.h"
#include"Enemy_bosslvl2.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "SDL/include/SDL_timer.h"
#include"Enemy.h"
#include"ModuleEnemies.h"
#include <math.h>

#define RANGE 30
#define PI 3.14159265
#define ANGLE_CONVERT (180.0 / PI)
#define ANGLE_CONVERT_REVERSE (PI / 180.0)
#define ENEMY_SHOOT_SPEED 4
#define ENEMYSHOOTDELAY 2500
#define ENEMYMOVEDELAY 10

Enemy_Boss::Enemy_Boss(int x, int y) : Enemy(x, y)
{
	live = 100;
	Bosslvl2move.PushBack({ 0, 1284, 224, 208 });
	Bosslvl2move.PushBack({ 0, 1492, 224, 208 });
	Bosslvl2move.PushBack({ 0, 1700, 224, 208 });
	Bosslvl2move.PushBack({ 0, 1908, 224, 208 });
	Bosslvl2move.speed = 0.25f;

	Bosslvl2idle.PushBack({ 0, 1284, 224, 208 });
	Bosslvl2idle.speed = 0.25f;

	animation = &Bosslvl2move;

	collider = App->collision->AddCollider({ 0, 0, 30, 30 }, COLLIDER_TYPE::COLLIDER_PURPLE_MACHINE, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}

void Enemy_Boss::Move()
{
	unsigned int currentTime = 0;
	currentTime = SDL_GetTicks();

	if (App->render->camera.y <= -10376){
		if (firsttime == true){
			lastTime = SDL_GetTicks();
			firsttime = false;
			movement = 1;
		}
		switch (movement){
		case 1:
			if ((currentTime > lastTime) && (position.y < -5188)) {
				position.y += 1;
			}
			else if (position.y == -5188){
				movement = 2;
				animation = &Bosslvl2idle;
				lastTime = currentTime;
			}
			break;
		case 2:
			if ((currentTime > lastTime) && (currentTime < (lastTime + 1750))){
				position.y = -5188;
			}
			else if (currentTime >= (lastTime + 1750)){
				movement = 3;
				animation = &Bosslvl2move;
				lastTime = currentTime;
			}
			break;
		case 3:
			if ((currentTime > lastTime) && (position.y > -5220)) {
				position.y -= 1;
			}
			else if (position.y == -5220){
				movement = 4;
				animation = &Bosslvl2idle;
				lastTime = currentTime;
			}
			break;
		case 4:
			if ((currentTime > lastTime) && (currentTime < (lastTime + 1450))){
				position.y = -5220;
			}
			else if (currentTime >= (lastTime + 1450)){
				movement = 5;
				animation = &Bosslvl2move;
				lastTime = currentTime;
			}
			break;
		case 5:
			if ((currentTime > lastTime) && (position.y > -5250)) {
				position.y -= 1;
			}
			else if (position.y == -5250){
				movement = 6;
				animation = &Bosslvl2idle;
				lastTime = currentTime;
			}
			break;
		case 6:
			if ((currentTime > lastTime) && (currentTime < (lastTime + 970))){
				position.y = -5250;
			}
			else if (currentTime >= (lastTime + 970)){
				movement = 7;
				animation = &Bosslvl2move;
				lastTime = currentTime;
			}
			break;
		case 7:
			if ((currentTime > lastTime) && (position.y < -5220)) {
				position.y += 1;
			}
			else if (position.y == -5220){
				movement = 8;
				animation = &Bosslvl2idle;
				lastTime = currentTime;
			}
			break;
		case 8:
			if ((currentTime > lastTime) && (currentTime < (lastTime + 1930))){
				position.y = -5220;
			}
			else if (currentTime >= (lastTime + 1930)){
				movement = 9;
				animation = &Bosslvl2move;
				lastTime = currentTime;
			}
			break;
		case 9:
			if ((currentTime > lastTime) && (position.y < -5188)) {
				position.y += 1;
			}
			else if (position.y == -5188){
				movement = 10;
				animation = &Bosslvl2idle;
				lastTime = currentTime;
			}
			break;
		case 10:
			if ((currentTime > lastTime) && (currentTime < (lastTime + 1500))){
				position.y = -5188;
			}
			else if (currentTime >= (lastTime + 1500)){
				movement = 1;
				animation = &Bosslvl2move;
				lastTime = currentTime;
			}
			break;
		case 11:

			break;
		case 12:

			break;
		case 13:

			break;
		case 14:

			break;
		case 15:

			break;
		case 16:

			break;
		case 17:

			break;
		case 18:

			break;
		case 19:

			break;
		case 20:

			break;
		default:

			break;
		}
		//lastTime = currentTime;
	}
}

void Enemy_Boss::Shoot()
{
	

}