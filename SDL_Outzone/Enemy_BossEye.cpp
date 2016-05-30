#include "Application.h"
#include"Enemy_BossEye.h"
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

Enemy_Bosseye::Enemy_Bosseye(int x, int y) : Enemy(x, y)
{
	live = 100;
	BossEYElvl2idleopen.PushBack({ 279, 1291, 40, 35 });
	BossEYElvl2idleopen.speed = 0.25f;

	BossEYElvl2idleclose.PushBack({ 232, 1334, 40, 35 });
	BossEYElvl2idleclose.speed = 0.25f;

	BossEYElvl2open.PushBack({ 232, 1334, 40, 35 });
	BossEYElvl2open.PushBack({ 279, 1335, 40, 35 });
	BossEYElvl2open.PushBack({ 232, 1290, 40, 35 });
	BossEYElvl2open.PushBack({ 279, 1291, 40, 35 });
	BossEYElvl2open.loop = false;
	BossEYElvl2open.speed = 0.1f;

	BossEYElvl2close.PushBack({ 279, 1291, 40, 35 });
	BossEYElvl2close.PushBack({ 232, 1290, 40, 35 });
	BossEYElvl2close.PushBack({ 279, 1335, 40, 35 });
	BossEYElvl2close.PushBack({ 232, 1334, 40, 35 });
	BossEYElvl2close.loop = false;
	BossEYElvl2close.speed = 0.1f;

	animation = &BossEYElvl2idleclose;

	collider = App->collision->AddCollider({ 0, 0, 40, 35 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}

void Enemy_Bosseye::Move()
{
	currentTime = SDL_GetTicks();

	if (App->render->camera.y <= -10376){
		if (firsttime == true){
			lastTime = SDL_GetTicks();
			firsttime = false;
			movement = 1;
		}
		switch (movement){
		case 1:
			if ((currentTime > lastTime) && (position.y < -5125)) {
				position.y += 1;
			}
			else if (position.y == -5125){
				movement = 2;
				lastTime = currentTime;
			}
			break;
		case 2:
			if ((currentTime > lastTime) && (currentTime < (lastTime + 1750))){
				position.y = -5125;
			}
			else if (currentTime >= (lastTime + 1750)){
				movement = 3;
				lastTime = currentTime;
			}
			break;
		case 3:
			if ((currentTime > lastTime) && (position.y > -5157)) {
				position.y -= 1;
			}
			else if (position.y == -5157){
				movement = 4;
				lastTime = currentTime;
			}
			break;
		case 4:
			if ((currentTime > lastTime) && (currentTime < (lastTime + 1250))){
				animation = &BossEYElvl2open;
				if (animation->Finished() == true){
					animation->Reset();
					animation = &BossEYElvl2idleopen;
				}
			}
			if ((currentTime > lastTime) && (currentTime < (lastTime + 1450))){
				position.y = -5157;
			}
			else if (currentTime >= (lastTime + 1450)){
				movement = 5;
				lastTime = currentTime;
			}
			break;
		case 5:
			if ((currentTime > lastTime) && (position.y > -5187)) {
				position.y -= 1;
			}
			else if (position.y == -5187){
				movement = 6;
				lastTime = currentTime;
			}
			break;
		case 6:
			if ((currentTime > lastTime) && (currentTime < (lastTime + 100))){
				animation = &BossEYElvl2close;
				if (animation->Finished() == true){
					animation->Reset();
					animation = &BossEYElvl2idleclose;
				}
			}
			if ((currentTime > lastTime) && (currentTime < (lastTime + 970))){
				position.y = -5187;
			}
			else if (currentTime >= (lastTime + 970)){
				movement = 7;
				lastTime = currentTime;
			}
			break;
		case 7:
			if ((currentTime > lastTime) && (position.y < -5157)) {
				position.y += 1;
			}
			else if (position.y == -5157){
				movement = 8;
				lastTime = currentTime;
			}
			break;
		case 8:
			if ((currentTime > lastTime) && (currentTime < (lastTime + 1930))){
				position.y = -5157;
			}
			else if (currentTime >= (lastTime + 1930)){
				movement = 9;
				lastTime = currentTime;
			}
			break;
		case 9:
			if ((currentTime > lastTime) && (position.y < -5125)) {
				position.y += 1;
			}
			else if (position.y == -5125){
				movement = 10;
				lastTime = currentTime;
			}
			break;
		case 10:
			if ((currentTime > lastTime) && (currentTime < (lastTime + 1500))){
				position.y = -5125;
			}
			else if (currentTime >= (lastTime + 1500)){
				movement = 11;
				lastTime = currentTime;
				//To do the loop
				movement = 1;
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

void Enemy_Bosseye::Shoot()
{


}