#include "Application.h"
#include"BoombpickUp.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "SDL/include/SDL_timer.h"
#include <math.h>
BoombPickUp::BoombPickUp(int x, int y) : Enemy(x, y)
{
	live = 100;
	BoombpickUp.PushBack({ 245, 1183, 15, 16 });
	BoombpickUp.PushBack({ 263, 1183, 15, 16 });
	BoombpickUp.speed = 0.2f;
	collider = App->collision->AddCollider({ 0, 0, 15, 16 }, COLLIDER_TYPE::COLLIDER_BOOMBPICKUP, (Module*)App->enemies);
	animation = &BoombpickUp;
	original_y = y;
	original_x = x;
}