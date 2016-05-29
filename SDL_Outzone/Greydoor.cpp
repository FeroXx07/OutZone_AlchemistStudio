#include "Application.h"
#include "Greydoor.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "SDL/include/SDL_timer.h"
#include <math.h>
Greydoor::Greydoor(int x, int y) : Enemy(x, y)
{
	live = 100;
	greydoor.PushBack({ 170, 2170, 56, 60 });
	greydoor.PushBack({ 114, 2170, 56, 60 });
	greydoor.speed = 0.25f;
	collider = App->collision->AddCollider({ 0, 0, 60, 64 }, COLLIDER_TYPE::COLLIDER_DOOR, (Module*)App->enemies);
	animation = &greydoor;
	original_y = y;
	original_x = x;
}