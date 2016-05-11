#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"

#include "SDL/include/SDL_timer.h"

#define PLAYER_MULTIPLE_SHOOT_DELAY 750
#define SHOOTDELAY 125
#define PLAYERCOLIDERX 9
#define PLAYERCOLIDERY 7
#define SUPERSPEED 5

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	graphics = NULL;
	current_animation = NULL;

	position.x = 100;
	position.y = 200;

	// idle animation
	idle_w.PushBack({ 0, 50, 40, 50 });
	idle_wa.PushBack({ 0, 450, 40, 50 });
	idle_wd.PushBack({ 40, 550, 40, 50 });
	idle_a.PushBack({ 120, 100, 40, 50 });
	idle_s.PushBack({ 120, 0, 40, 50 });
	idle_sa.PushBack({ 120, 400, 40, 50 });
	idle_sd.PushBack({ 120, 500, 40, 50 });
	idle_d.PushBack({ 160, 150, 40, 50 });
	//MOVEMENT
	// move upwards
	up.PushBack({ 0, 50, 40, 50 });
	up.PushBack({ 40, 50, 40, 50 });
	up.PushBack({ 80, 50, 40, 50 });
	up.PushBack({ 120, 50, 40, 50 });
	up.PushBack({ 160, 50, 40, 50 });
	up.loop = true;
	up.speed = 0.1f;

	// Move down
	down.PushBack({ 0, 0, 40, 50 });
	down.PushBack({ 40, 0, 40, 50 });
	down.PushBack({ 80, 0, 40, 50 });
	down.PushBack({ 120, 0, 40, 50 });
	down.PushBack({ 160, 0, 40, 50 });
	down.loop = true;
	down.speed = 0.1f;
	//left
	left.PushBack({ 0, 100, 40, 50 });
	left.PushBack({ 40, 100, 40, 50 });
	left.PushBack({ 80, 100, 40, 50 });
	left.PushBack({ 120, 100, 40, 50 });
	left.PushBack({ 160, 100, 40, 50 });
	left.loop = true;
	left.speed = 0.1f;
	//right
	right.PushBack({ 0, 150, 40, 50 });
	right.PushBack({ 40, 150, 40, 50 });
	right.PushBack({ 80, 150, 40, 50 });
	right.PushBack({ 120, 150, 40, 50 });
	right.PushBack({ 160, 150, 40, 50 });
	right.loop = true;
	right.speed = 0.1f;
	//Diagonal right top
	Drightop.PushBack({ 0, 550, 40, 50 });
	Drightop.PushBack({ 40, 550, 40, 50 });
	Drightop.PushBack({ 80, 550, 40, 50 });
	Drightop.PushBack({ 120, 550, 40, 50 });
	Drightop.loop = true;
	Drightop.speed = 0.1f;
	//Diagonal left top
	Lefthtop.PushBack({ 0, 450, 40, 50 });
	Lefthtop.PushBack({ 40, 450, 40, 50 });
	Lefthtop.PushBack({ 80, 450, 40, 50 });
	Lefthtop.PushBack({ 120, 450, 40, 50 });
	Lefthtop.loop = true;
	Lefthtop.speed = 0.1f;
	//Diagonal right bot
	Drighbot.PushBack({ 0, 500, 40, 50 });
	Drighbot.PushBack({ 40, 500, 40, 50 });
	Drighbot.PushBack({ 80, 500, 40, 50 });
	Drighbot.PushBack({ 120, 500, 40, 50 });
	Drighbot.loop = true;
	Drighbot.speed = 0.1f;
	//Diagonal left bot
	Lefthbot.PushBack({ 0, 400, 40, 50 });
	Lefthbot.PushBack({ 40, 400, 40, 50 });
	Lefthbot.PushBack({ 80, 400, 40, 50 });
	Lefthbot.PushBack({ 120, 400, 40, 50 });
	Lefthbot.loop = true;
	Lefthbot.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("Outzone/spritesheetPlayer.png");

	destroyed = false;
	position.x = 100;
	position.y = 250;

	playercollision = App->collision->AddCollider({ position.x + PLAYERCOLIDERX, position.y + PLAYERCOLIDERY, 23, 28 }, COLLIDER_PLAYER, this);

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->collision->EraseCollider(playercollision);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	int speed = 0;
	PreviousPos = position;

	speed = 4;
	if (Superspeed == true){
		speed *= SUPERSPEED;
	}

	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT){
		if (App->player->position.y <= (160 + (App->render->camera.y / 2))){
			App->render->camera.y -= speed;
		}
		
	}

	speed = 1;
	if (Superspeed == true){
		speed *= SUPERSPEED;
	}

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		if ((position.x -= speed) <= 0){
			position.x = 0;
		}
		if (collisionWallS == true)
		{
			position.x = PreviousPos.x;
			collisionWallS = false;
		}
		else{
			position.x -= speed;
		}
		if (current_animation != &left)
		{
			left.Reset();
			current_animation = &left;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		if ((position.x += speed) >= 200){
			position.x = 200;
		}
		if (collisionWallS == true)
		{
			position.x = PreviousPos.x;
			collisionWallS = false;
		}
		else{
			position.x += speed;
		}
		current_animation = &right;
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT){
			current_animation = &idle_w;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		if (collisionWallT == true)
		{
			position.y = PreviousPos.y;
			collisionWallT = false;
		}
		if ((position.y += speed) >= (280 + (App->render->camera.y / 2))){
			position.y = (280 + (App->render->camera.y / 2));
		}
		else{
			position.y += speed;
		}

		current_animation = &down;

		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT){
			if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT){
				current_animation = &down;
			}
			else{
				current_animation = &Drighbot;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT){
			if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT){
				current_animation = &down;
			}
			else{
				current_animation = &Lefthbot;
			}
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		if ((position.y -= speed) <= -4980){
			position.y = -4980;
		}
		if (collisionWallT == true)
		{
			position.y = PreviousPos.y;
			collisionWallT = false;
		}
		else{
			position.y -= speed;
		}

		//if (current_animation != &up)
		//{
		//	up.Reset();
		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT){
			current_animation = &idle_w;
		}
		else{
			current_animation = &up;
		}

		//}
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT){
			if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT){
				current_animation = &up;
			}
			else{
				current_animation = &Drightop;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT){
			if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT){
				current_animation = &up;
			}
			else{
				current_animation = &Lefthtop;
			}
		}
	}

	// A
	if ((App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE) && (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE) && (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE))
	{
		if (lastkeypressed != LAST_KEY_A){
			beforelastkeypressed = (BEFORE_LAST_KEY)lastkeypressed;
			playeractiontime = SDL_GetTicks();
		}
		lastkeypressed = LAST_KEY::LAST_KEY_A;
	}

	// D
	if ((App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE) && (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE) && (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE))
	{
		if (lastkeypressed != LAST_KEY_D){
			beforelastkeypressed = (BEFORE_LAST_KEY)lastkeypressed;
			playeractiontime = SDL_GetTicks();
		}
		lastkeypressed = LAST_KEY::LAST_KEY_D;
	}

	// S / ASD
	if (((App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE) && (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE) && (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)) || ((App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE) && (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)))
	{
		if (lastkeypressed != LAST_KEY_S){
			beforelastkeypressed = (BEFORE_LAST_KEY)lastkeypressed;
			playeractiontime = SDL_GetTicks();
		}
		lastkeypressed = LAST_KEY::LAST_KEY_S;
	}

	// SD
	if ((App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE) && (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE)){
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT){
		}
		else{
			if (lastkeypressed != LAST_KEY_SD){
				beforelastkeypressed = (BEFORE_LAST_KEY)lastkeypressed;
				playeractiontime = SDL_GetTicks();
			}
			lastkeypressed = LAST_KEY::LAST_KEY_SD;
		}
	}

	// SA
	if ((App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE) && (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)){
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT){
		}
		else{
			if (lastkeypressed != LAST_KEY_SA){
				beforelastkeypressed = (BEFORE_LAST_KEY)lastkeypressed;
				playeractiontime = SDL_GetTicks();
			}
			lastkeypressed = LAST_KEY::LAST_KEY_SA;
		}
	}

	// W / AWD
	if (((App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE) && (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE) && (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)) || ((App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE) && (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)))
	{
		lastkeypressed = LAST_KEY::LAST_KEY_W;
	}

	// WD
	if ((App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE) && (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE)){
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT){
		}
		else{
			if (lastkeypressed != LAST_KEY_WD){
				beforelastkeypressed = (BEFORE_LAST_KEY)lastkeypressed;
				playeractiontime = SDL_GetTicks();
			}
			lastkeypressed = LAST_KEY::LAST_KEY_WD;
		}
	}

	// WA
	if (((App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE) && (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE))){
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT){
		}
		else{
			if (lastkeypressed != LAST_KEY_WA){
				beforelastkeypressed = (BEFORE_LAST_KEY)lastkeypressed;
				playeractiontime = SDL_GetTicks();
			}
			lastkeypressed = LAST_KEY::LAST_KEY_WA;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN){
		if (Invencible == false){
			Invencible = true;
		}
		else{
			Invencible = false;
		}
	}
	
	if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN){
		if (Superspeed == false){
			Superspeed = true;
		}
		else{
			Superspeed = false;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN){
		if (Fly == false){
			Fly = true;
		}
		else{
			Fly = false;
		}
	}

	// AD
	if ((App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE) && (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE) && (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
	{
		lastkeypressed = LAST_KEY::LAST_KEY_W;
	}

	// WS
	if ((App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE) && (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE))
	{
		lastkeypressed = LAST_KEY::LAST_KEY_W;
	}

	// WASD
	if ((App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
	{
		lastkeypressed = LAST_KEY::LAST_KEY_W;
	}

	//WSD
	if ((App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE) && (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
	{
		lastkeypressed = LAST_KEY::LAST_KEY_WD;
	}

	//WAS
	if ((App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT) && (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE))
	{
		lastkeypressed = LAST_KEY::LAST_KEY_WA;
	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_REPEAT)
	{
		shootcurrenttime = SDL_GetTicks();
		playercurrenttime = SDL_GetTicks();

		if (shootcurrenttime > (shootactiontime + SHOOTDELAY)){
			if (lastkeypressed == LAST_KEY_W){
				/*
				if (playercurrenttime < (playeractiontime + PLAYER_MULTIPLE_SHOOT_DELAY)) {
				if (beforelastkeypressed == LAST_KEY_A){
				App->particles->AddParticle(App->particles->laser292_5, position.x + 2, position.y - 6, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser315, position.x + 2, position.y - 6, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser337_5, position.x + 2, position.y - 6, COLLIDER_PLAYER_SHOT);
				}
				else if (beforelastkeypressed == LAST_KEY_D){
				App->particles->AddParticle(App->particles->laser67_5, position.x + 17, position.y - 1, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser45, position.x + 17, position.y - 1, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser22_5, position.x + 17, position.y - 1, COLLIDER_PLAYER_SHOT);
				}
				//beforelastkeypressed = BEFORE_LAST_KEY::NO_KEY_PRESSED_BEFORE;
				playeractiontime = playercurrenttime;
				}
				*/
				App->particles->AddParticle(App->particles->laser0, position.x + 18, position.y, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laserweaponshoot0, position.x + 13, position.y - 13);
			}
			else if (lastkeypressed == LAST_KEY_A){
				/*
				if (playercurrenttime < (playeractiontime + PLAYER_MULTIPLE_SHOOT_DELAY)) {
				if (beforelastkeypressed == LAST_KEY_W){
				App->particles->AddParticle(App->particles->laser337_5, position.x + 2, position.y - 6, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser315, position.x + 2, position.y - 6, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser292_5, position.x + 2, position.y - 6, COLLIDER_PLAYER_SHOT);
				}
				else if (beforelastkeypressed == LAST_KEY_S){
				App->particles->AddParticle(App->particles->laser202_5, position.x - 1, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser247_5, position.x - 1, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser225, position.x - 1, position.y + 7, COLLIDER_PLAYER_SHOT);
				}
				//beforelastkeypressed = BEFORE_LAST_KEY::NO_KEY_PRESSED_BEFORE;
				playeractiontime = playercurrenttime;
				}
				*/
				App->particles->AddParticle(App->particles->laser270, position.x - 2, position.y + 5, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laserweaponshoot270, position.x - 12, position.y + 2);
			}
			else if (lastkeypressed == LAST_KEY_S){
				/*
				if (playercurrenttime < (playeractiontime + PLAYER_MULTIPLE_SHOOT_DELAY)) {
				if (beforelastkeypressed == LAST_KEY_A){
				App->particles->AddParticle(App->particles->laser247_5, position.x - 1, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser225, position.x - 1, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser202_5, position.x - 1, position.y + 7, COLLIDER_PLAYER_SHOT);
				}
				else if (beforelastkeypressed == LAST_KEY_D){
				App->particles->AddParticle(App->particles->laser112_5, position.x + 10, position.y + 10, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser135, position.x + 10, position.y + 10, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser157_5, position.x + 10, position.y + 10, COLLIDER_PLAYER_SHOT);
				}
				//beforelastkeypressed = BEFORE_LAST_KEY::NO_KEY_PRESSED_BEFORE;
				playeractiontime = playercurrenttime;
				}
				*/
				App->particles->AddParticle(App->particles->laser180, position.x + 5, position.y + 13, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laserweaponshoot180, position.x + 1, position.y + 23);
			}
			else if (lastkeypressed == LAST_KEY_D){
				/*
				if (playercurrenttime < (playeractiontime + PLAYER_MULTIPLE_SHOOT_DELAY)) {
				if (beforelastkeypressed == LAST_KEY_W){
				App->particles->AddParticle(App->particles->laser22_5, position.x + 17, position.y - 1, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser45, position.x + 17, position.y - 1, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser67_5, position.x + 17, position.y - 1, COLLIDER_PLAYER_SHOT);
				}
				else if (beforelastkeypressed == LAST_KEY_S){
				App->particles->AddParticle(App->particles->laser157_5, position.x + 10, position.y + 10, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser135, position.x + 10, position.y + 10, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser112_5, position.x + 10, position.y + 10, COLLIDER_PLAYER_SHOT);
				}
				//beforelastkeypressed = BEFORE_LAST_KEY::NO_KEY_PRESSED_BEFORE;
				playeractiontime = playercurrenttime;
				}
				*/
				App->particles->AddParticle(App->particles->laser90, position.x + 15, position.y + 10, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laserweaponshoot90, position.x + 25, position.y + 4);
			}
			else if (lastkeypressed == LAST_KEY_WA){
				if (playercurrenttime < (playeractiontime + PLAYER_MULTIPLE_SHOOT_DELAY)) {
					if (beforelastkeypressed == LAST_KEY_W){
						App->particles->AddParticle(App->particles->laser337_5, position.x + 2, position.y - 6, COLLIDER_PLAYER_SHOT);
					}
					else if (beforelastkeypressed == LAST_KEY_A){
						App->particles->AddParticle(App->particles->laser292_5, position.x + 2, position.y - 6, COLLIDER_PLAYER_SHOT);
					}
					beforelastkeypressed = BEFORE_LAST_KEY::NO_KEY_PRESSED_BEFORE;
					playeractiontime = playercurrenttime;
				}
				App->particles->AddParticle(App->particles->laser315, position.x + 2, position.y - 6, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laserweaponshoot315, position.x, position.y - 10);
			}
			else if (lastkeypressed == LAST_KEY_WD){
				if (playercurrenttime < (playeractiontime + PLAYER_MULTIPLE_SHOOT_DELAY)) {
					if (beforelastkeypressed == LAST_KEY_W){
						App->particles->AddParticle(App->particles->laser22_5, position.x + 17, position.y - 1, COLLIDER_PLAYER_SHOT);
					}
					else if (beforelastkeypressed == LAST_KEY_D){
						App->particles->AddParticle(App->particles->laser67_5, position.x + 17, position.y - 1, COLLIDER_PLAYER_SHOT);
					}
					beforelastkeypressed = BEFORE_LAST_KEY::NO_KEY_PRESSED_BEFORE;
					playeractiontime = playercurrenttime;
				}
				App->particles->AddParticle(App->particles->laser45, position.x + 17, position.y - 1, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laserweaponshoot45, position.x + 23, position.y - 8);
			}
			else if (lastkeypressed == LAST_KEY_SA){
				if (playercurrenttime < (playeractiontime + PLAYER_MULTIPLE_SHOOT_DELAY)) {
					if (beforelastkeypressed == LAST_KEY_S){
						App->particles->AddParticle(App->particles->laser202_5, position.x - 1, position.y + 7, COLLIDER_PLAYER_SHOT);
					}
					else if (beforelastkeypressed == LAST_KEY_A){
						App->particles->AddParticle(App->particles->laser247_5, position.x - 1, position.y + 7, COLLIDER_PLAYER_SHOT);
					}
					beforelastkeypressed = BEFORE_LAST_KEY::NO_KEY_PRESSED_BEFORE;
					playeractiontime = playercurrenttime;
				}
				App->particles->AddParticle(App->particles->laser225, position.x - 1, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laserweaponshoot225, position.x - 8, position.y + 13);
			}
			else if (lastkeypressed == LAST_KEY_SD){
				if (playercurrenttime < (playeractiontime + PLAYER_MULTIPLE_SHOOT_DELAY)) {
					if (beforelastkeypressed == LAST_KEY_S){
						App->particles->AddParticle(App->particles->laser112_5, position.x + 10, position.y + 10, COLLIDER_PLAYER_SHOT);
					}
					else if (beforelastkeypressed == LAST_KEY_D){
						App->particles->AddParticle(App->particles->laser157_5, position.x + 10, position.y + 10, COLLIDER_PLAYER_SHOT);
					}
					beforelastkeypressed = BEFORE_LAST_KEY::NO_KEY_PRESSED_BEFORE;
					playeractiontime = playercurrenttime;
				}
				App->particles->AddParticle(App->particles->laser135, position.x + 10, position.y + 10, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laserweaponshoot135, position.x + 15, position.y + 15);
			}
			shootactiontime = shootcurrenttime;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->bomb, App->render->camera.x/2, App->render->camera.y/2, COLLIDER_BOMB);
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE){

		playertime = SDL_GetTicks();

		if (lastkeypressed == LAST_KEY_W){
			current_animation = &idle_w;
		}
		else if (lastkeypressed == LAST_KEY_A){
			current_animation = &idle_a;
		}
		else if (lastkeypressed == LAST_KEY_S){
			current_animation = &idle_s;
		}
		else if (lastkeypressed == LAST_KEY_D){
			current_animation = &idle_d;
		}
		else if (lastkeypressed == LAST_KEY_WA){
			current_animation = &idle_wa;
		}
		else if (lastkeypressed == LAST_KEY_WD){
			current_animation = &idle_wd;
		}
		else if (lastkeypressed == LAST_KEY_SA){
			current_animation = &idle_sa;
		}
		else if (lastkeypressed == LAST_KEY_SD){
			current_animation = &idle_sd;
		}
		else{
			current_animation = &idle_w;
		}

		if (playertime > (playerinitialtime + 7000)) {
			App->particles->AddParticle(App->particles->goahead, (App->render->camera.x / 2) + 95, (App->render->camera.y / 2) + 60);
			playerinitialtime = playertime;
		}

	}

	playercollision->SetPos(position.x + PLAYERCOLIDERX, position.y + PLAYERCOLIDERY);

	// Draw everything --------------------------------------
	if (current_animation == nullptr){
	}
	else{
		if (collisionPrint == true)
		{
			App->render->Blit(graphics, PreviousPos.x, PreviousPos.y, &(current_animation->GetCurrentFrame()));
			//collisionPrint = false;
		}
		else
		{

			App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

		}
	}
		
	

	return UPDATE_CONTINUE;
}


void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (Fly == false){
		if (c1 == playercollision && destroyed == false && App->fade->IsFading() == false)
		{
			if (c2->type == COLLIDER_WALL)
			{
				int speed = 1;
				int height;
				if ((((c2->rect.y) + c2->rect.h) <= c1->rect.y + 2))
				{
					position = PreviousPos;
					collisionWallT = true;
				}
				else if (((c2->rect.x + c2->rect.w) <= c1->rect.x + 1) || ((c1->rect.x + c1->rect.w) >= c2->rect.x + 1))
				{
					position = PreviousPos;
					collisionWallS = true;
				}
			}
			else if (c2->type == COLLIDER_DOOR)
			{
				int height;
				if ((((c2->rect.y) + c2->rect.h) <= c1->rect.y + 2))
				{
					position = PreviousPos;
					collisionWallT = true;
				}
				else if (((c2->rect.x + c2->rect.w) <= c1->rect.x + 1) || ((c1->rect.x + c1->rect.w) >= c2->rect.x + 1))
				{
					position = PreviousPos;
					collisionWallS = true;
				}
			}
			else if (c2->type == COLLIDER_WALL2)
			{
				int height;
				if ((((c2->rect.y) + c2->rect.h) <= c1->rect.y + 2))
				{
					position = PreviousPos;
					collisionWallT = true;
				}
				else if (((c2->rect.x + c2->rect.w) <= c1->rect.x + 1) || ((c1->rect.x + c1->rect.w) >= c2->rect.x + 1))
				{
					position = PreviousPos;
					collisionWallS = true;
				}
			}
			else{
				if (Invencible == false){
					App->player->Disable();
					App->particles->AddParticle(App->particles->playerexplosion, position.x - 47, position.y - 54, COLLIDER_NONE);
					App->fade->FadeToBlack((Module*)App->scene_space, (Module*)App->scene_gameover);
					destroyed = true;
				}
			}
		}
	}
}