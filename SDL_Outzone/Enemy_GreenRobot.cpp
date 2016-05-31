#include "Application.h"
#include "Enemy_Turret1.h"
#include"Enemy_GreenRobot.h"
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

Enemy_GeenRobot::Enemy_GeenRobot(int x, int y) : Enemy(x, y)
{
	live = 100;
	GRobot__0.PushBack({ 280, 0, 40, 40 });
	GRobot__22_5.PushBack({ 280, 40, 40, 40 });
	GRobot__45.PushBack({ 240, 40, 40, 40 });
	GRobot__67_5.PushBack({ 200, 40, 40, 40 });
	GRobot__90.PushBack({ 160, 40, 40, 40 });
	GRobot__112_5.PushBack({ 120, 40, 40, 40 });
	GRobot__135.PushBack({ 80, 40, 40, 40 });
	GRobot__157_5.PushBack({ 40, 40, 40, 40 });
	GRobot__180.PushBack({ 0, 40, 40, 40 });
	GRobot__202_5.PushBack({ 0, 0, 40, 40 });
	GRobot__225.PushBack({ 40, 0, 40, 40 });
	GRobot__247_5.PushBack({ 80, 0, 40, 40 });
	GRobot__270.PushBack({ 120, 0, 40, 40 });
	GRobot__292_5.PushBack({ 160, 0, 40, 40 });
	GRobot__315.PushBack({ 200, 0, 40, 40 });
	GRobot__337_5.PushBack({ 240, 0, 40, 40 });

	GRobot__w.PushBack({ 160, 900, 40, 40 });
	GRobot__w.PushBack({ 200, 900, 40, 40 });
	GRobot__w.PushBack({ 240, 900, 40, 40 });
	GRobot__w.PushBack({ 280, 900, 40, 40 });
	GRobot__w.loop = true;
	GRobot__w.speed = 0.1f;

	GRobot__wa.PushBack({ 0, 860, 40, 40 });
	GRobot__wa.PushBack({ 40, 860, 40, 40 });
	GRobot__wa.PushBack({ 80, 860, 40, 40 });
	GRobot__wa.PushBack({ 120, 860, 40, 40 });
	GRobot__wa.loop = true;
	GRobot__wa.speed = 0.1f;

	GRobot__wd.PushBack({ 160, 782, 40, 40 });
	GRobot__wd.PushBack({ 200, 782, 40, 40 });
	GRobot__wd.PushBack({ 240, 782, 40, 40 });
	GRobot__wd.PushBack({ 280, 782, 40, 40 });
	GRobot__wd.loop = true;
	GRobot__wd.speed = 0.1f;

	GRobot__a.PushBack({ 120, 822, 40, 40 });
	GRobot__a.PushBack({ 160, 822, 40, 40 });
	GRobot__a.PushBack({ 200, 822, 40, 40 });
	GRobot__a.PushBack({ 240, 822, 40, 40 });
	GRobot__a.loop = true;
	GRobot__a.speed = 0.1f;

	GRobot__s.PushBack({ 0, 900, 40, 40 });
	GRobot__s.PushBack({ 40, 900, 40, 40 });
	GRobot__s.PushBack({ 80, 900, 40, 40 });
	GRobot__s.PushBack({ 120, 900, 40, 40 });
	GRobot__s.loop = true;
	GRobot__s.speed = 0.1f;

	GRobot__sa.PushBack({ 0, 782, 40, 40 });
	GRobot__sa.PushBack({ 40, 782, 40, 40 });
	GRobot__sa.PushBack({ 80, 782, 40, 40 });
	GRobot__sa.PushBack({ 120, 782, 40, 40 });
	GRobot__sa.loop = true;
	GRobot__sa.speed = 0.1f;

	GRobot__sd.PushBack({ 160, 860, 40, 40 });
	GRobot__sd.PushBack({ 200, 860, 40, 40 });
	GRobot__sd.PushBack({ 240, 860, 40, 40 });
	GRobot__sd.PushBack({ 280, 860, 40, 40 });
	GRobot__sd.loop = true;
	GRobot__sd.speed = 0.1f;

	GRobot__d.PushBack({ 0, 820, 40, 40 });
	GRobot__d.PushBack({ 40, 820, 40, 40 });
	GRobot__d.PushBack({ 80, 820, 40, 40 });
	GRobot__d.PushBack({ 280, 820, 40, 40 });
	GRobot__d.loop = true;
	GRobot__d.speed = 0.1f;


	animation = &GRobot__180;

	collider = App->collision->AddCollider({ 0, 0, 27, 37 }, COLLIDER_TYPE::COLLIDER_GREY_ROBOT, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}

void Enemy_GeenRobot::Move()
{
	bool left = false;
	float angle = 0;



	if ((original_y >= (App->render->camera.y / 2) - RANGE) && (position.y <= (App->render->camera.y / 2) + 340 - RANGE)){
		//left or right of the turret
		if (original_y == -1450)
		{
				position.y += 1;
		}

		else if (original_y == -1420)
		{
				position.y += 1;
		}

		else if (original_y == -1610)
		{
			if (original_x < 50)
			{
				position.y += 1;
				if (position.y > -1520)
				{
					position.y -= 1;
					position.x = position.x + 1;
				}
			}
			else if (original_x > 50)
			{
				position.y += 1;
				if (position.y > -1555)
				{
					position.y -= 1;
					position.x = position.x - 1;
				}
			}
		}

		else if (original_y == -2750)
		{
			if (original_x < 100)
			{
				position.y += 1;
				if (position.y > -2690)
				{
					position.x = position.x - 1;
				}
			}
			else if (original_x > 100)
			{
				position.y += 1;
				if (position.y > -2690)
				{
					position.x = position.x + 1;
				}
			}
		}

		else if (original_y == -2900)
		{
			if (original_x < 60)
			{
				position.y += 1;
				if (position.y > -2770)
				{
					position.y -= 1;
					position.x = position.x + 1;
				}
			}
			else if (original_x > 60 && original_x < 130)
			{
				position.y += 1;
			}
			else if (original_x > 130)
			{
				position.y += 1;
				if (position.y > -2730)
				{
					position.y -= 1;
					position.x = position.x - 1;
				}
			}
		}

		else if (original_y == -3100)
		{
			if (original_x < 90)
			{
				position.y += 1;
				if (position.y > -2950)
				{
					position.y -= 1;
					position.x = position.x - 1;
					if (position.x < 10)
					{
						position.y += 1;
						position.x = position.x + 1;
					}
				}
			}
			else if (original_x > 90)
			{
				position.y += 1;
				if (position.y > -2950)
				{
					position.y -= 1;
					position.x = position.x + 1;
					if (position.x > 200)
					{
						position.y += 1;
						position.x = position.x - 1;
					}
				}
			}
		}

		else if (original_y == -3950)
		{
			if (position.x > 60)
			{
				position.x += 1;
			}
			if (position.x < 60)
			{
				position.x -= 1;
			}
		}

		else if (original_y == -4220)
		{
			if (original_x == 0)
			{
				position.y += 1;
				if (position.y > -4100)
				{
					position.y -= 1;
					position.x = position.x - 1;
				}
			}
			if (original_x == 35)
			{
				position.y += 1;
				if (position.y > -4070)
				{
					position.y -= 1;
					position.x = position.x + 1;
				}
			}
			if (original_x == 160)
			{
				position.y += 1;
				if (position.y > -4040)
				{
					position.y -= 1;
					position.x = position.x + 1;
				}
			}
		}

		else if (original_y == -4520)
		{
			if (original_x == 63)
			{
				position.y -= 1;
				if (position.y < -4560)
				{
					position.y += 1;
					position.x = position.x + 1;
				}
			}
		}

		else if (original_y == -4840)
		{
			if (original_x == 80)
			{
				position.x -= 1;
				
			}
			if (original_x == 200)
			{
				position.y += 1;
				if (position.y > -4745)
				{
					position.y -= 1;
					position.x = position.x - 1;
				}

			}
		}
		//position.x += 1;
		if (App->player->position.x >= position.x){
			left = false;
		}
		else{
			left = true;
		}

		angle = ((float)acos((((App->player->position.x - original_x) * 0) + ((App->player->position.y - original_y) * 1)) / (sqrt((double)((App->player->position.x - original_x)*(App->player->position.x - original_x) + (App->player->position.y - original_y)*(App->player->position.y - original_y)))*sqrt((double)(0 * 0 + 1 * 1))))) * ANGLE_CONVERT;

		//LOG("Angle %.2f", angle);
		//Right

		if (App->player->position.x == position.x && App->player->position.y > position.y){
			animation = &GRobot__s;
		}
		else if (App->player->position.x > position.x && App->player->position.y > position.y){
			animation = &GRobot__sd;
		}

		else if (App->player->position.x > position.x && App->player->position.y == position.y){
			animation = &GRobot__d;
		}
		else if (App->player->position.x > position.x && App->player->position.y < position.y){
			animation = &GRobot__wd;
		}
		else if (App->player->position.x == position.x && App->player->position.y < position.y){
			animation = &GRobot__w;
		}
		//Left
		else if (App->player->position.x < position.x && App->player->position.y > position.y){
			animation = &GRobot__sa;
		}
		else if (App->player->position.x < position.x && App->player->position.y == position.y){
			animation = &GRobot__a;
		}
		else if (App->player->position.x < position.x && App->player->position.y < position.y){
			animation = &GRobot__wa;
		}
	}

}

void Enemy_GeenRobot::Shoot()
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