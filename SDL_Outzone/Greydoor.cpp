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
	greydoor.PushBack({ 114, 2170, 65, 70 });
	greydoor.PushBack({ 180, 2170, 65, 70 });
	greydoor.speed = 0.05f;
	
	collider = App->collision->AddCollider({ 0, 0, 65, 70 }, COLLIDER_TYPE::COLLIDER_DOOR, (Module*)App->enemies);
	animation = &greydoor;
	original_y = y;
	original_x = x;
}