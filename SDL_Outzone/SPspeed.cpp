#include "Application.h"
#include "SPspeed.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "SDL/include/SDL_timer.h"
#include <math.h>
SPspeed::SPspeed(int x, int y) : Enemy(x, y)
{
	live = 100;
	spspeed.PushBack({ 47, 1179, 24, 24 });
	spspeed.PushBack({ 71, 1179, 24, 24 });
	spspeed.speed = 0.2f;
	collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_SPSPEED, (Module*)App->enemies);
	animation = &spspeed;
	original_y = y;
	original_x = x;
}