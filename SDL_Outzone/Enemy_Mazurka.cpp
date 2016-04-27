#include "Application.h"
#include "Enemy_Mazurka.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"

Enemy_Mazurka::Enemy_Mazurka(int x, int y) : Enemy(x, y)
{

	Mazurka.PushBack({ 384, 97, 66, 62 });
	Mazurka1.PushBack({ 464, 97, 64, 61 });

	animation = &Mazurka;

	collider = App->collision->AddCollider({ 0, 0, 66, 62 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}

void Enemy_Mazurka::Move()
{
	position.y = original_y;
	position.x = original_x;

}

void Enemy_Mazurka::Shoot()
{}