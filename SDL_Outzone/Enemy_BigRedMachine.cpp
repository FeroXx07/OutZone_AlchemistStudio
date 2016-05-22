#include "Application.h"
#include "Enemy_BigRedMachine.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "SDL/include/SDL_timer.h"
#include <math.h>

#define RANGE 30
#define PI 3.14159265
#define ANGLE_CONVERT (180.0 / PI)
#define ANGLE_CONVERT_REVERSE (PI / 180.0)
#define ENEMY_SHOOT_SPEED 4
#define ENEMYSHOOTDELAY 2500

Enemy_BigRedMachine::Enemy_BigRedMachine(int x, int y) : Enemy(x, y)
{
	live = 100;


	collider = App->collision->AddCollider({ 0, 0, 27, 47 }, COLLIDER_TYPE::COLLIDER_BIG_RED_MACHINE, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}