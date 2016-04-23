#include "Application.h"
#include "Enemy_RedBird.h"
#include "ModuleCollision.h"
#include "Turret1.h"

Enemy_Turret1::Enemy_Turret1(int x, int y) : Enemy(x, y)
{
	turret1__0.PushBack({342,54,27,47});
	turret1__22_5.PushBack({342,110,26,46});
	turret1__45.PushBack({297,111,27,45});
	turret1__67_5.PushBack({252,113,27,43});
	turret1__90.PushBack({206,113,28,43});
	turret1__112_5.PushBack({161,113,27,44});
	turret1__135.PushBack({115,113,28,44});
	turret1__157_5.PushBack({69,113,28,45});
	turret1__180.PushBack({22,113,29,45});
	turret1__202_5.PushBack({25,57,27,45});
	turret1__225.PushBack({71,58,26,44});
	turret1__247_5.PushBack({114,57,29,44});
	turret1__270.PushBack({157,58,30,43});
	turret1__292_5.PushBack({206,58,28,43});
	turret1__315.PushBack({254,56,24,45});
	turret1__337_5.PushBack({299,55,24,46});

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_Turret1::Move()
{
	/*
	if(going_up)
	{
	if(wave > 1.0f)
	going_up = false;
	else
	wave += 0.05f;
	}
	else
	{
	if(wave < -1.0f)
	going_up = true;
	else
	wave -= 0.05f;
	}

	position.y = original_y + (25.0f * sinf(wave));
	position.x -= 1;
	*/

}