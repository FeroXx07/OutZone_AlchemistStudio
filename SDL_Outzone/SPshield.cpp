#include "Application.h"
#include "SPshield.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "SDL/include/SDL_timer.h"
#include <math.h>
SPshield::SPshield(int x, int y) : Enemy(x, y)
{
	live = 100;
	spshield.PushBack({ 143, 1179, 24, 24 });
	spshield.PushBack({ 167, 1179, 24, 24 });
	spshield.speed = 0.2f;
	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_SPSHIELD, (Module*)App->enemies);
	animation = &spshield;
	original_y = y;
	original_x = x;
}