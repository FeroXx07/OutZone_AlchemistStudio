#include "Application.h"
#include "Enemy_Cookies.h"
#include "ModuleCollision.h"
#include "Path.h"




Enemy_Cookies::Enemy_Cookies(int x, int y) : Enemy(x, y)
{
	original_pos.x = x;
	original_pos.y = y;
	fly.PushBack({ 3, 38, 23, 23 });
	path.PushBack({ 0.3f, 1.5f }, 150);
	path.PushBack({ 0.3f, -1.5f }, 150);
	/*
	fly.PushBack({ 38, 6, 24, 24 });
	fly.PushBack({ 71, 6, 24, 24 });
	fly.PushBack({ 104, 6, 24, 24 });
	fly.PushBack({ 137, 6, 24, 24 });
	fly.PushBack({ 170, 6, 24, 24 });
	fly.PushBack({ 203, 6, 24, 24 });
	fly.PushBack({ 236, 6, 24, 24 });*/
	fly.speed = 0.2f;
	

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	
	original_y = y;
}

void Enemy_Cookies::Move()
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
