#include "Application.h"
#include"PowerUp.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "SDL/include/SDL_timer.h"
#include <math.h>
Powerup::Powerup(int x, int y) : Enemy(x, y)
{
	live = 100;
	powerup.PushBack({ 64, 1203, 16, 16 });
	powerup.PushBack({ 80, 1203, 16, 16 });
	powerup.speed = 0.2f;
	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->enemies);
	animation = &powerup;
	original_y = y;
	original_x = x;
}