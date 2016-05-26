#include "Application.h"
#include"BoxChargeEnergy.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "SDL/include/SDL_timer.h"
#include <math.h>
BoxChargeEnergy::BoxChargeEnergy(int x, int y) : Enemy(x, y)
{
	live = 100;
	boxchaim.PushBack({ 239, 363, 42, 42 });
	collider = App->collision->AddCollider({ 0, 0, 42, 42 }, COLLIDER_TYPE::COLLIDER_BOX, (Module*)App->enemies);
	animation = &boxchaim;
	original_y = y;
	original_x = x;
}