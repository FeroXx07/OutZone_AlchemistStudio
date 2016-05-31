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
	powerup.PushBack({ 143, 1179, 24, 24 });
	powerup.PushBack({ 167, 1179, 24, 24 });
	powerup.speed = 0.2f;
	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_SPSHIELD, (Module*)App->enemies);
	animation = &powerup;
	original_y = y;
	original_x = x;
}