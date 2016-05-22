#include "Application.h"
#include "Enemy_BlueMachine.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "SDL/include/SDL_timer.h"
#include <math.h>

#define RANGE 30
#define PI 3.14159265
#define ANGLE_CONVERT (180.0 / PI)
#define ANGLE_CONVERT_REVERSE (PI / 180.0)
#define ENEMY_SHOOT_SPEED 4
#define ENEMYSHOOTDELAY 2500

Enemy_BlueMachine::Enemy_BlueMachine(int x, int y) : Enemy(x, y)
{
	live = 100;
	BlueMachine.PushBack({ 0, 409, 57, 49 });
	BlueMachine.PushBack({ 57, 409, 57, 49 });
	BlueMachine.PushBack({ 114, 409, 57, 49 });
	BlueMachine.PushBack({ 171, 409, 57, 49 });
	BlueMachine.speed = 0.25f;
	animation = &BlueMachine;

	collider = App->collision->AddCollider({ 0, 0, 50, 43 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}

void Enemy_BlueMachine::Move()
{
	/*
	bool left = false;
	float angle = 0;

	if ((original_y >= (App->render->camera.y / 2) - RANGE) && (original_y <= (App->render->camera.y / 2) + 340 - RANGE)){
		//left or right of the turret
		if (App->player->position.x >= original_x){
			left = false;
		}
		else{
			left = true;
		}

		//angle
		//angle = (float)acos(((App->player->position.x * 0) + (App->player->position.y * 1)) / ((sqrt((pow((double)App->player->position.x, 2)) + (pow((double)App->player->position.y, 2))))*(sqrt((pow(0.0, 2.0)) + (pow(1.0, 2.0)))))) * ANGLE_CONVERT;

		//angle = ((float)acos(((App->player->position.x * 0) + (App->player->position.y * 1)) / (sqrt((double)((App->player->position.x)*(App->player->position.x) + (App->player->position.y)*(App->player->position.y)))*sqrt((double)(0 * 0 + 1 * 1))))) * ANGLE_CONVERT;

		angle = ((float)acos((((App->player->position.x - original_x) * 0) + ((App->player->position.y - original_y) * 1)) / (sqrt((double)((App->player->position.x - original_x)*(App->player->position.x - original_x) + (App->player->position.y - original_y)*(App->player->position.y - original_y)))*sqrt((double)(0 * 0 + 1 * 1))))) * ANGLE_CONVERT;

		//LOG("Angle %.2f", angle);

		//Right
		if ((angle <= 11.25) && (angle >= 0) && (left == false)){
			animation = &BlueMachine__180;
		}
		else if ((angle <= 33.75) && (angle >= 11.25) && (left == false)){
			animation = &BlueMachine__157_5;
		}
		else if ((angle <= 56.25) && (angle >= 33.75) && (left == false)){
			animation = &BlueMachine__135;
		}
		else if ((angle <= 78.75) && (angle >= 56.25) && (left == false)){
			animation = &BlueMachine__112_5;
		}
		else if ((angle <= 101.25) && (angle >= 78.75) && (left == false)){
			animation = &BlueMachine__90;
		}
		else if ((angle <= 123.75) && (angle >= 101.25) && (left == false)){
			animation = &BlueMachine__67_5;
		}
		else if ((angle <= 146.25) && (angle >= 123.75) && (left == false)){
			animation = &BlueMachine__45;
		}
		else if ((angle <= 168.75) && (angle >= 146.25) && (left == false)){
			animation = &BlueMachine__22_5;
		}
		else if ((angle <= 180) && (angle >= 168.75) && (left == false)){
			animation = &BlueMachine__0;
		}

		//Left
		else if ((angle <= 11.25) && (angle >= 0) && (left == true)){
			animation = &BlueMachine__180;
		}
		else if ((angle <= 33.75) && (angle >= 11.25) && (left == true)){
			animation = &BlueMachine__202_5;
		}
		else if ((angle <= 56.25) && (angle >= 33.75) && (left == true)){
			animation = &BlueMachine__225;
		}
		else if ((angle <= 78.75) && (angle >= 56.25) && (left == true)){
			animation = &BlueMachine__247_5;
		}
		else if ((angle <= 101.25) && (angle >= 78.75) && (left == true)){
			animation = &BlueMachine__270;
		}
		else if ((angle <= 123.75) && (angle >= 101.25) && (left == true)){
			animation = &BlueMachine__292_5;
		}
		else if ((angle <= 146.25) && (angle >= 123.75) && (left == true)){
			animation = &BlueMachine__315;
		}
		else if ((angle <= 168.75) && (angle >= 146.25) && (left == true)){
			animation = &BlueMachine__337_5;
		}
		else if ((angle <= 180) && (angle >= 168.75) && (left == true)){
			animation = &BlueMachine__0;
		}
	}
	*/
	position.y = original_y;
	position.x = original_x;
}

void Enemy_BlueMachine::Shoot()
{
	/*
	unsigned int currentTime = 0;
	bool left = false;
	float angle = 0;
	int i = 0;

	currentTime = SDL_GetTicks();

	if ((original_y >= (App->render->camera.y / 2) - RANGE) && (original_y <= (App->render->camera.y / 2) + 340 - RANGE)){

		if (App->player->position.x >= original_x){
			left = false;
		}
		else{
			left = true;
		}

		angle = ((float)acos((((App->player->position.x + 14 - original_x) * 0) + ((App->player->position.y + 16 - original_y) * 1)) / (sqrt((double)((App->player->position.x + 14 - original_x)*(App->player->position.x + 14 - original_x) + (App->player->position.y + 16 - original_y)*(App->player->position.y + 16 - original_y)))*sqrt((double)(0 * 0 + 1 * 1))))) * ANGLE_CONVERT;
		//LOG("Angle %.2f", angle);

		if (currentTime > (lastTime + ENEMYSHOOTDELAY)) {
			if (left == true){
				if ((angle < 90) && (angle >= 0)){
					App->particles->enemyshoot.speed.x = -ENEMY_SHOOT_SPEED * sin(angle * ANGLE_CONVERT_REVERSE);
					App->particles->enemyshoot.speed.y = ENEMY_SHOOT_SPEED * cos(angle * ANGLE_CONVERT_REVERSE);
				}
				else{
					App->particles->enemyshoot.speed.x = -ENEMY_SHOOT_SPEED * sin(angle * ANGLE_CONVERT_REVERSE);
					App->particles->enemyshoot.speed.y = ENEMY_SHOOT_SPEED * cos(angle * ANGLE_CONVERT_REVERSE);
				}
			}
			else{
				if ((angle < 90) && (angle >= 0)){
					App->particles->enemyshoot.speed.x = ENEMY_SHOOT_SPEED * sin(angle * ANGLE_CONVERT_REVERSE);
					App->particles->enemyshoot.speed.y = ENEMY_SHOOT_SPEED * cos(angle * ANGLE_CONVERT_REVERSE);
				}
				else{
					App->particles->enemyshoot.speed.x = ENEMY_SHOOT_SPEED * sin(angle * ANGLE_CONVERT_REVERSE);
					App->particles->enemyshoot.speed.y = ENEMY_SHOOT_SPEED * cos(angle * ANGLE_CONVERT_REVERSE);
				}
			}

			if ((angle <= 11.25) && (angle >= 0) && (left == false)){
				App->particles->AddParticle(App->particles->enemyshoot, original_x + 8, original_y + 20, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 33.75) && (angle >= 11.25) && (left == false)){
				App->particles->AddParticle(App->particles->enemyshoot, original_x + 13, original_y + 17, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 56.25) && (angle >= 33.75) && (left == false)){
				App->particles->AddParticle(App->particles->enemyshoot, original_x + 17, original_y + 17, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 78.75) && (angle >= 56.25) && (left == false)){
				App->particles->AddParticle(App->particles->enemyshoot, original_x + 20, original_y + 14, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 101.25) && (angle >= 78.75) && (left == false)){
				App->particles->AddParticle(App->particles->enemyshoot, original_x + 22, original_y + 10, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 123.75) && (angle >= 101.25) && (left == false)){
				App->particles->AddParticle(App->particles->enemyshoot, original_x + 20, original_y + 3, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 146.25) && (angle >= 123.75) && (left == false)){
				App->particles->AddParticle(App->particles->enemyshoot, original_x + 18, original_y, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 168.75) && (angle >= 146.25) && (left == false)){
				App->particles->AddParticle(App->particles->enemyshoot, original_x + 14, original_y - 3, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 180) && (angle >= 168.75) && (left == false)){
				App->particles->AddParticle(App->particles->enemyshoot, original_x + 8, original_y - 4, COLLIDER_ENEMY_SHOT);
			}

			//Left
			else if ((angle <= 11.25) && (angle >= 0) && (left == true)){
				App->particles->AddParticle(App->particles->enemyshoot, original_x + 8, original_y + 20, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 33.75) && (angle >= 11.25) && (left == true)){
				App->particles->AddParticle(App->particles->enemyshoot, original_x + 3, original_y + 19, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 56.25) && (angle >= 33.75) && (left == true)){
				App->particles->AddParticle(App->particles->enemyshoot, original_x - 1, original_y + 13, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 78.75) && (angle >= 56.25) && (left == true)){
				App->particles->AddParticle(App->particles->enemyshoot, original_x - 3, original_y + 9, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 101.25) && (angle >= 78.75) && (left == true)){
				App->particles->AddParticle(App->particles->enemyshoot, original_x - 4, original_y + 8, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 123.75) && (angle >= 101.25) && (left == true)){
				App->particles->AddParticle(App->particles->enemyshoot, original_x - 3, original_y + 3, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 146.25) && (angle >= 123.75) && (left == true)){
				App->particles->AddParticle(App->particles->enemyshoot, original_x - 1, original_y + 1, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 168.75) && (angle >= 146.25) && (left == true)){
				App->particles->AddParticle(App->particles->enemyshoot, original_x + 4, original_y, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 180) && (angle >= 168.75) && (left == true)){
				App->particles->AddParticle(App->particles->enemyshoot, original_x + 8, original_y - 4, COLLIDER_ENEMY_SHOT);
			}
			lastTime = currentTime;
		}
	}
	*/
}