#include "Application.h"
#include "Enemy.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"

Enemy::Enemy(int x, int y) : position(x, y), collider(nullptr)
{}

Enemy::~Enemy()
{
	if(collider != nullptr)
		App->collision->EraseCollider(collider);
}

const Collider* Enemy::GetCollider() const
{
	return collider;
}

void Enemy::Draw(SDL_Texture* sprites)
{
	if (collider != nullptr){
		switch (collider->type){
		case COLLIDER_TURRET1:
			collider->SetPos(position.x + 7, position.y + 5);
			break;
		case COLLIDER_TURRET3:
			collider->SetPos(position.x + 2, position.y + 2);
			break;
		case COLLIDER_BLUE_MACHINE:
			collider->SetPos(position.x + 5, position.y + 4);
			break;
		case COLLIDER_RED_MACHINE:
			collider->SetPos(position.x + 5, position.y + 4);
			break;
		case COLLIDER_ORANGE_ROBOT:
			collider->SetPos(position.x + 5, position.y + 5);
			break;
		case COLLIDER_PURPLE_MACHINE:
			collider->SetPos(position.x + 5, position.y + 5);
			break;
		default:
			collider->SetPos(position.x, position.y);
		}
	}

	if (animation != nullptr){
		App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
	}
}
