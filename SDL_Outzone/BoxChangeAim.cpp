#include "Application.h"
#include "BoxChangeAim.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "SDL/include/SDL_timer.h"
#include <math.h>
Box::Box(int x, int y) : Enemy(x, y)
{
	live = 100;
	boxchaim.PushBack({ 281, 368, 32, 33 });
	collider = App->collision->AddCollider({ 0, 0, 32, 33 }, COLLIDER_TYPE::COLLIDER_BOX, (Module*)App->enemies);
	animation = &boxchaim;
	original_y = y;
	original_x = x;
}