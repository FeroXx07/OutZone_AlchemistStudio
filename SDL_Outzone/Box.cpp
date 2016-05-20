#include "Application.h"
#include "Box.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "SDL/include/SDL_timer.h"
#include <math.h>
Box::Box(int x, int y) : Enemy(x, y)
{
	live = 100;

	collider = App->collision->AddCollider({ 0, 0, 30, 30 }, COLLIDER_TYPE::COLLIDER_CHANGEAIM, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}