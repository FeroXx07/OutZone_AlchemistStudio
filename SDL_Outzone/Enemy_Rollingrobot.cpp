#include "Application.h"
#include"Enemy_Roollingrobot.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "SDL/include/SDL_timer.h"
#include <math.h>
#include <math.h>

#define RANGE 30
#define PI 3.14159265
#define ANGLE_CONVERT (180.0 / PI)
#define ANGLE_CONVERT_REVERSE (PI / 180.0)
#define ENEMY_SHOOT_SPEED 4
#define ENEMYSHOOTDELAY 1000
#define ENEMYMOVEDELAY 10

Enemy_Rollingrobot::Enemy_Rollingrobot(int x, int y) : Enemy(x, y)
{
	live = 100;
	Rollingrobot.PushBack({ 2, 2123, 46, 48 });
	Rollingrobot.PushBack({ 58, 2123, 46, 48 });
	Rollingrobot.speed = 0.09f;
	animation = &Rollingrobot;

	collider = App->collision->AddCollider({ 0, 0, 44, 42 }, COLLIDER_TYPE::COLLIDER_ROLLINGROBOT, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}

void Enemy_Rollingrobot::Move()
{
	unsigned int currentTime = 0;
	currentTime = SDL_GetTicks();
	if ((original_y >= (App->render->camera.y / 2) - RANGE) && (original_y <= (App->render->camera.y / 2) + 340 - RANGE)){
		if (currentTime > (lastTime + ENEMYMOVEDELAY)){
			if (original_x == 0 && original_y == -1970){
				//if (position.x > 120){
				position.x += 1;
				//}

			}
			if (original_x == 0 && original_y == -2160){

				position.x += 1;


			}
			if (original_x == 206 && original_y == -2200){
				position.x -= 1;

			}

			if (original_x == 0 && original_y == -1850){
				if (position.x < 110 && position.y ==-1850){
					position.x += 1;
				}
				else if (position.x < 120 && position.y <-1830){
					position.y += 1;
				}
				else{
					position.x += 1;
				}

			}

		}

	}




}

void Enemy_Rollingrobot::Shoot()
{
	unsigned int currentTime = 0;
	bool left = false;
	float angle = 0;
	int i = 0;

	currentTime = SDL_GetTicks();

	if ((original_y >= (App->render->camera.y / 2) - RANGE) && (original_y <= (App->render->camera.y / 2) + 340 - RANGE)){
		if (currentTime > (lastTime + ENEMYSHOOTDELAY)) {
			
			App->particles->AddParticle(App->particles->enemymissile, position.x + 13, position.y + 17, COLLIDER_ENEMY_SHOT);


			lastTime = currentTime;
		}
	}
}