#include "Application.h"
#include "Enemy_Turret1.h"
#include "ModuleCollision.h"

Enemy_Turret1::Enemy_Turret1(int x, int y) : Enemy(x, y)
{
	Turret1.PushBack({ 342, 54, 27, 47 });

	animation = &Turret1;

	collider = App->collision->AddCollider({ 0, 0, 27, 47 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}

void Enemy_Turret1::Move()
{
	/*if (going_up)
	{
	if (wave > 1.0f)
	going_up = false;
	else
	wave += 0.05f;
	}
	else
	{
	if (wave < -1.0f)
	going_up = true;
	else
	wave -= 0.05f;
	}
	*/
	position.y = original_y;
	position.x = original_x;
}
