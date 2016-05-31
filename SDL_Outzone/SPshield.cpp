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
	spshield.PushBack({ 0, 1203, 16, 16 });
	spshield.PushBack({ 16, 1203, 16, 16 });
	spshield.speed = 0.2f;
	collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_CHANGEAIM, (Module*)App->enemies);
	animation = &spshield;
	original_y = y;
	original_x = x;
}