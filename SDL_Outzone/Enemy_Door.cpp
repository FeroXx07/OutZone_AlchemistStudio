#include "Application.h"
#include "Enemy_Door.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"

Enemy_Door::Enemy_Door(int x, int y) : Enemy(x, y)
{

	Door.PushBack({ 548, 51, 116, 108 });

	animation = &Door;

	collider = App->collision->AddCollider({ 0, 0, 116, 108 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}

void Enemy_Door::Move()
{
	position.y = original_y;
	position.x = original_x;

}