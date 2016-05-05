#include "Application.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "Enemy_Turret2.h"
#include "SDL/include/SDL_timer.h"
#include <math.h>

#define RANGE 30
#define PI 3.14159265
#define ANGLE_CONVERT (180.0 / PI)
#define ANGLE_CONVERT_REVERSE (PI / 180.0)
#define ENEMY_SHOOT_SPEED 4
#define ENEMYSHOOTDELAY 2500

Enemy_Turret2::Enemy_Turret2(int x, int y) : Enemy(x, y)
{
	turret2.PushBack({ 464, 24, 63, 63 });


	animation = &turret2;

	collider = App->collision->AddCollider({ 0, 0, 63, 63 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}

void Enemy_Turret2::Move()
{
	
	position.y = original_y;
	position.x = original_x;
}
