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
#define ENEMYMOVEDELAY 25

Enemy_BlueMachine::Enemy_BlueMachine(int x, int y) : Enemy(x, y)
{
	live = 100;
	BlueMachine.PushBack({ 0, 409, 57, 49 });
	BlueMachine.PushBack({ 57, 409, 57, 49 });
	BlueMachine.PushBack({ 114, 409, 57, 49 });
	BlueMachine.PushBack({ 171, 409, 57, 49 });
	BlueMachine.speed = 0.25f;
	animation = &BlueMachine;

	collider = App->collision->AddCollider({ 0, 0, 44, 35 }, COLLIDER_TYPE::COLLIDER_BLUE_MACHINE, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}

void Enemy_BlueMachine::Move()
{
	unsigned int currentTime = 0;
	currentTime = SDL_GetTicks();
	if ((original_y >= (App->render->camera.y / 2) - RANGE) && (original_y <= (App->render->camera.y / 2) + 340 - RANGE)){
		if (currentTime > (lastTime + ENEMYMOVEDELAY)){
			if (original_x == 191 && original_y == -1179){
				if (position.x > 120){
					position.x -= 2;
				}

			}
			if (original_x == 191 && original_y == -1139){
				if (position.x > 145){
					position.x -= 2;
				}

			}
			if (original_x == 191 && original_y == -1099){
				if (position.x > 165){
					position.x -= 2;
				}

			}

			if (original_x == 0 && original_y == -1180){
				if (position.x < 65){
					position.x += 2;
				}

			}

			if (original_x == 0 && original_y == -1140){
				if (position.x < 50){
					position.x += 2;
				}

			}

			if (original_x == 0 && original_y == -1100){
				if (position.x < 25){
					position.x += 2;
				}

			}

			if (original_x == -50  && original_y == -3500){
				if (position.x < 30 && position.y == -3500){
					position.x += 2;
				}
				else if (position.x < 31 && position.y >= -3550){
					position.y -= 2;
				}
				else if (position.x < 55 && position.y >= -3555){
					position.x += 2;
				}
				else if (position.y <= -3470 && position.x < 58){
					position.y += 2;
				}
				

			}

			if (original_x == -50 && original_y == -3550){
				if (position.x < 30 && position.y == -3550){
					position.x += 2;
				}
				else if (position.x < 31 && position.y >= -3600){
					position.y -= 2;
				}
				else if (position.x < 55 && position.y >= -3605){
					position.x += 2;
				}
				else if (position.y <= -3520 && position.x < 58){
					position.y += 2;
				}


			}

			if (original_x == -50 && original_y == -3600){
				if (position.x < 30 && position.y == -3600){
					position.x += 2;
				}
				else if (position.x < 31 && position.y >= -3650){
					position.y -= 2;
				}
				else if (position.x < 55 && position.y >= -3655){
					position.x += 2;
				}
				else if (position.y <= -3570 && position.x < 58){
					position.y += 2;
				}


			}
		     }

		if (original_x == 230 && original_y == -3570){
			if (position.x > 150 && position.y == -3570){
				position.x -= 2;
			}
		}

		if (original_x == 230 && original_y == -3520){
			if (position.x > 150 && position.y == -3520){
				position.x -= 2;
			}
		}

		if (original_x == 230 && original_y == -3470){
			if (position.x > 150 && position.y == -3470){
				position.x -= 2;
			}
		}


		if (original_x == -30 && original_y == -3690){
			if (position.x < 260 && position.y == -3690){
				position.x += 2;
			}
		}


		if (original_x == 230 && original_y == -3630){
			if (position.x > -60 && position.y == -3630){
				position.x -= 2;
			}
		}

	}

	}


	
	


void Enemy_BlueMachine::Shoot()
{
	unsigned int currentTime = 0;
	bool left = false;
	float angle = 0;
	int i = 0;

	currentTime = SDL_GetTicks();

	if ((original_y >= (App->render->camera.y / 2) - RANGE) && (original_y <= (App->render->camera.y / 2) + 340 - RANGE)){

		if (App->player->position.x >= position.x){
			left = false;
		}
		else{
			left = true;
		}

		angle = ((float)acos((((App->player->position.x + 14 - position.x) * 0) + ((App->player->position.y + 16 - position.y) * 1)) / (sqrt((double)((App->player->position.x + 14 - position.x)*(App->player->position.x + 14 - position.x) + (App->player->position.y + 16 - position.y)*(App->player->position.y + 16 - position.y)))*sqrt((double)(0 * 0 + 1 * 1))))) * ANGLE_CONVERT;
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
				App->particles->AddParticle(App->particles->enemyshoot, position.x + 8, position.y + 20, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 33.75) && (angle >= 11.25) && (left == false)){
				App->particles->AddParticle(App->particles->enemyshoot, position.x + 13, position.y + 17, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 56.25) && (angle >= 33.75) && (left == false)){
				App->particles->AddParticle(App->particles->enemyshoot, position.x + 17, position.y + 17, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 78.75) && (angle >= 56.25) && (left == false)){
				App->particles->AddParticle(App->particles->enemyshoot, position.x + 20, position.y + 14, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 101.25) && (angle >= 78.75) && (left == false)){
				App->particles->AddParticle(App->particles->enemyshoot, position.x + 22, position.y + 10, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 123.75) && (angle >= 101.25) && (left == false)){
				App->particles->AddParticle(App->particles->enemyshoot, position.x + 20, position.y + 3, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 146.25) && (angle >= 123.75) && (left == false)){
				App->particles->AddParticle(App->particles->enemyshoot, position.x + 18, position.y, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 168.75) && (angle >= 146.25) && (left == false)){
				App->particles->AddParticle(App->particles->enemyshoot, position.x + 14, position.y - 3, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 180) && (angle >= 168.75) && (left == false)){
				App->particles->AddParticle(App->particles->enemyshoot, position.x + 8, position.y - 4, COLLIDER_ENEMY_SHOT);
			}

			//Left
			else if ((angle <= 11.25) && (angle >= 0) && (left == true)){
				App->particles->AddParticle(App->particles->enemyshoot, position.x + 8, position.y + 20, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 33.75) && (angle >= 11.25) && (left == true)){
				App->particles->AddParticle(App->particles->enemyshoot, position.x + 3, position.y + 19, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 56.25) && (angle >= 33.75) && (left == true)){
				App->particles->AddParticle(App->particles->enemyshoot, position.x - 1, position.y + 13, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 78.75) && (angle >= 56.25) && (left == true)){
				App->particles->AddParticle(App->particles->enemyshoot, position.x - 3, position.y + 9, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 101.25) && (angle >= 78.75) && (left == true)){
				App->particles->AddParticle(App->particles->enemyshoot, position.x - 4, position.y + 8, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 123.75) && (angle >= 101.25) && (left == true)){
				App->particles->AddParticle(App->particles->enemyshoot, position.x - 3, position.y + 3, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 146.25) && (angle >= 123.75) && (left == true)){
				App->particles->AddParticle(App->particles->enemyshoot, position.x - 1, position.y + 1, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 168.75) && (angle >= 146.25) && (left == true)){
				App->particles->AddParticle(App->particles->enemyshoot, position.x + 4, position.y, COLLIDER_ENEMY_SHOT);
			}
			else if ((angle <= 180) && (angle >= 168.75) && (left == true)){
				App->particles->AddParticle(App->particles->enemyshoot, position.x + 8, position.y - 4, COLLIDER_ENEMY_SHOT);
			}
			lastTime = currentTime;
		}
	}
}