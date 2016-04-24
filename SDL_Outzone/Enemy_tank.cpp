#include "Application.h"
#include "Enemy_Tank.h"
#include "ModuleCollision.h"
#include "Path.h"




Enemy_Tank::Enemy_Tank(int x, int y) : Enemy(x, y)
{
	original_pos.x = x;
	original_pos.y = y;
	front.PushBack({ 5, 107, 30, 30 });
	front.PushBack({ 40, 107, 30, 30 });
	front.PushBack({ 70, 107, 30, 30 });
	path.PushBack({ -0.3f, 0.0f }, 150, &front);
	path.PushBack({ 1.2f, 0.0f }, 150, &front);
	/*
	fly.PushBack({ 38, 6, 24, 24 });
	fly.PushBack({ 71, 6, 24, 24 });
	fly.PushBack({ 104, 6, 24, 24 });
	fly.PushBack({ 137, 6, 24, 24 });
	fly.PushBack({ 170, 6, 24, 24 });
	fly.PushBack({ 203, 6, 24, 24 });
	fly.PushBack({ 236, 6, 24, 24 });*/
	front.speed = 0.2f;


	animation = &front;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_Tank::Move()
{
	
	if (going_up)
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
	position = original_pos + path.GetCurrentSpeed();
	//position.y = orginal_pos + (25.0f * sinf(wave));
	//position.x -= 1;
}
