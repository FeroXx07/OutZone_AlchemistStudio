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
	BossEYElvl2.PushBack({ 0, 508, 40, 42 });
	BossEYElvl2.PushBack({ 40, 508, 40, 42 });
	BossEYElvl2.speed = 0.25f;

	animation = &BossEYElvl2;

	collider = App->collision->AddCollider({ 0, 0, 30, 30 }, COLLIDER_TYPE::COLLIDER_PURPLE_MACHINE, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}

void Enemy_Bosseye::Move()
{



}

void Enemy_Bosseye::Shoot()
{


}