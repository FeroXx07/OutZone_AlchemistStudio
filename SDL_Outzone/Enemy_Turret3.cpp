#include "Application.h"
#include"Enemy_Turret3.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "SDL/include/SDL_timer.h"
#include <math.h>

#define RANGE 30
#define SPINSPEED 0.5f
#define PI 3.14159265
#define ANGLE_CONVERT (180.0 / PI)
#define ANGLE_CONVERT_REVERSE (PI / 180.0)
#define ENEMY_SHOOT_SPEED 4
#define ENEMYSHOOTDELAY 1000

Enemy_Turret3::Enemy_Turret3(int x, int y) : Enemy(x, y)
{
	live = 100;
	Turret3.PushBack({ 0, 550, 30, 45 });
	Turret3.PushBack({ 30, 550, 30, 45 });
	Turret3.speed = 0.25f;

	animation = &Turret3;

	collider = App->collision->AddCollider({ 0, 0, 30, 45 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}

void Enemy_Turret3::Move()
{
	position.y = original_y;
	position.x = original_x;
}

void Enemy_Turret3::Shoot()
{
	int i = 0;

	if ((original_y >= (App->render->camera.y / 2) - RANGE) && (original_y <= (App->render->camera.y / 2) + 320 - RANGE)){
		if (angle == 0){
			left = !left;
		}
		else if ((angle == 0) || (angle == SHOOTRANGE)){
			bounce = !bounce;
		}

		if ((left == true) && (bounce == true)){
			angle -= SPINSPEED;
		}
		else if ((left == true) && (bounce == false)){
			angle += SPINSPEED;
		}
		else if ((left == false) && (bounce == true)){
			angle += SPINSPEED;
		}
		else if ((left == false) && (bounce == false)){
			angle -= SPINSPEED;
		}

		LOG("Angle %.2f", angle);
		LOG("Left %i", left);

		if (left == true){
			if ((angle < 90) && (angle >= 0)){
				App->particles->enemyshoot.speed.x = -ENEMY_SHOOT_SPEED * sin(angle * ANGLE_CONVERT_REVERSE);
				App->particles->enemyshoot.speed.y = ENEMY_SHOOT_SPEED * cos(angle * ANGLE_CONVERT_REVERSE);
			}
			else{
				App->particles->enemyshoot.speed.x = -ENEMY_SHOOT_SPEED * sin(angle * ANGLE_CONVERT_REVERSE);
				App->particles->enemyshoot.speed.y = ENEMY_SHOOT_SPEED * cos(angle * ANGLE_CONVERT_REVERSE);
			}
		}
		else{
			if ((angle < 90) && (angle >= 0)){
				App->particles->enemyshoot.speed.x = ENEMY_SHOOT_SPEED * sin(angle * ANGLE_CONVERT_REVERSE);
				App->particles->enemyshoot.speed.y = ENEMY_SHOOT_SPEED * cos(angle * ANGLE_CONVERT_REVERSE);
			}
			else{
				App->particles->enemyshoot.speed.x = ENEMY_SHOOT_SPEED * sin(angle * ANGLE_CONVERT_REVERSE);
				App->particles->enemyshoot.speed.y = ENEMY_SHOOT_SPEED * cos(angle * ANGLE_CONVERT_REVERSE);
			}
		}
		if ((angle == 0) || (angle == 11.5) || (angle == 22.5) || (angle == 34) || (angle == 45) || (angle == 56.5) || (angle == 67.5)){
			App->particles->AddParticle(App->particles->enemyshoot, original_x + 12, original_y + 13, COLLIDER_ENEMY_SHOT);
		}
	}
}

/*
void Enemy_Turret3::Shoot()
{
unsigned int currentTime = 0;

int i = 0;

currentTime = SDL_GetTicks();

if ((original_y >= (App->render->camera.y / 2) - RANGE) && (original_y <= (App->render->camera.y / 2) + 320 - RANGE)){
if (angle == 0){
left = !left;
}
else if ((angle == 0) || (angle == SHOOTRANGE)){
bounce = !bounce;
}

if ((left == true) && (bounce == true)){
angle -= SPINSPEED;
}
else if ((left == true) && (bounce == false)){
angle += SPINSPEED;
}
else if ((left == false) && (bounce == true)){
angle += SPINSPEED;
}
else if ((left == false) && (bounce == false)){
angle -= SPINSPEED;
}

LOG("Angle %.2f", angle);
LOG("Left %i", left);

if (currentTime > (lastTime + ENEMYSHOOTDELAY)) {
if (left == true){
if ((angle < 90) && (angle >= 0)){
App->particles->enemyshoot.speed.x = -ENEMY_SHOOT_SPEED * sin(angle * ANGLE_CONVERT_REVERSE);
App->particles->enemyshoot.speed.y = ENEMY_SHOOT_SPEED * cos(angle * ANGLE_CONVERT_REVERSE);
}
else{
App->particles->enemyshoot.speed.x = -ENEMY_SHOOT_SPEED * sin(angle * ANGLE_CONVERT_REVERSE);
App->particles->enemyshoot.speed.y = ENEMY_SHOOT_SPEED * cos(angle * ANGLE_CONVERT_REVERSE);
}
}
else{
if ((angle < 90) && (angle >= 0)){
App->particles->enemyshoot.speed.x = ENEMY_SHOOT_SPEED * sin(angle * ANGLE_CONVERT_REVERSE);
App->particles->enemyshoot.speed.y = ENEMY_SHOOT_SPEED * cos(angle * ANGLE_CONVERT_REVERSE);
}
else{
App->particles->enemyshoot.speed.x = ENEMY_SHOOT_SPEED * sin(angle * ANGLE_CONVERT_REVERSE);
App->particles->enemyshoot.speed.y = ENEMY_SHOOT_SPEED * cos(angle * ANGLE_CONVERT_REVERSE);
}
}
App->particles->AddParticle(App->particles->enemyshoot, original_x + 12, original_y + 13, COLLIDER_ENEMY_SHOT);
lastTime = currentTime;
}
}
}
*/