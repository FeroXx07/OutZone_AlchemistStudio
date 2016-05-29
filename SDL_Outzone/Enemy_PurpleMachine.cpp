#include "Application.h"
#include "Enemy_PurpleMachine.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "SDL/include/SDL_timer.h"
#include"Enemy.h"
#include"ModuleEnemies.h"
#include <math.h>

#define RANGE 30
#define PI 3.14159265
#define ANGLE_CONVERT (180.0 / PI)
#define ANGLE_CONVERT_REVERSE (PI / 180.0)
#define ENEMY_SHOOT_SPEED 4
#define ENEMYSHOOTDELAY 2500
#define ENEMYMOVEDELAY 10

Enemy_PurpleMachine::Enemy_PurpleMachine(int x, int y) : Enemy(x, y)
{
	live = 100;
	PurpleMachine.PushBack({ 0, 508, 40, 42 });
	PurpleMachine.PushBack({ 40, 508, 40, 42 });
	PurpleMachine.speed = 0.25f;

	animation = &PurpleMachine;

	collider = App->collision->AddCollider({ 0, 0, 30, 30 }, COLLIDER_TYPE::COLLIDER_PURPLE_MACHINE, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}

void Enemy_PurpleMachine::Move()
{
	
	unsigned int currentTime = 0;
	currentTime = SDL_GetTicks();
	if ((original_y >= (App->render->camera.y / 2) - RANGE) && (original_y <= (App->render->camera.y / 2) + 340 - RANGE)){
		if (App->enemies->onprobot == true){
			if (original_x == 50 && original_y == -2310){
				if (position.x < 95 && position.y == -2310){
					position.x += 1;
				}
				else if (position.x < 110 && position.y < -2220){
					position.y += 1;
				}
				else{
					position.x -= 1;
				}

			}

			if (original_x == 1 && original_y == -2310){
				if (position.x < 50 && position.y == -2310){
					position.x += 1;
				}
				else if (position.x < 95 && position.y == -2310){
					position.x += 1;
				}
				else if (position.x < 110 && position.y <-2220){
					position.y += 1;
				}
				else{
					position.x -= 1;
				}

			}

			if (original_x == 30 && original_y == -2340){
				if (position.x > 1 && position.y == -2340){
					position.x -= 1;
				}
				else if (position.x > 1 && position.y < -2310){
					position.y += 1;
				}
				else if (position.x < 95 && position.y == -2310){
					position.x += 1;
				}
				else if (position.x < 110 && position.y <-2220){
					position.y += 1;
				}
				else{
					position.x -= 1;
				}

			}

			if (original_x == 150 && original_y == -2310){
				if (position.x > 122 && position.y == -2310){
					position.x -= 1;
				}
				else if (position.x > 119 && position.y <-2220){
					position.y += 1;
				}
				else{
					position.x += 1;
				}

			}

			if (original_x == 200 && original_y == -2310){
				if (position.x > 122 && position.y == -2310){
					position.x -= 1;
				}
				else if (position.x > 119 && position.y < -2220){
					position.y += 1;
				}
				else{
					position.x += 1;
				}

			}

			if (original_x == 170 && original_y == -2340){
				if (position.x < 200 && position.y == -2340){
					position.x += 1;
				}
				else if (position.x <202 && position.y <-2310){
					position.y += 1;
				}
				else if (position.x > 122 && position.y == -2310){
					position.x -= 1;
				}
				else if (position.x >119 && position.y < -2220){
					position.y += 1;
				}
				else{
					position.x += 1;
				}

			}
			/*if (original_x == 0 && original_y == -2160){

				position.x += 1;


				}
				if (original_x == 206 && original_y == -2200){
				position.x -= 1;

				}

				if (original_x == 0 && original_y == -1850){
				if (position.x < 110 && position.y == -1850){
				position.x += 1;
				}
				else if (position.x < 120 && position.y <-1830){
				position.y += 1;
				}
				else{
				position.x += 1;
				}

				}*/

		}
		//App->enemies->onprobot = false;
		
		if (App->enemies->onprobot2 == true){

			if (original_x == 40 && original_y == -2440){
				if (position.x == 40 && position.y < -2350){
					position.y += 1;
				}
				else{
					position.x += 1;
				}

			}








		}

	}
	
}

void Enemy_PurpleMachine::Shoot()
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