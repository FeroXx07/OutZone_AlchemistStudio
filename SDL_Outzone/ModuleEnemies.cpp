#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "Enemy.h"
#include"Enemy_Turret2.h"
#include "Enemy_RedBird.h"
#include "Enemy_Cookies.h"
#include "Enemy_Turret1.h"
#include "Enemy_Mazurka.h"
#include "Enemy_tank.h"
#include "Enemy_Door.h"
#include"Enemy_Grey_Robot.h"
#include"Enemy_GreenRobot.h"
#include"Enemy_RedMachine.h"
#include"Enemy_BlueMachine.h"
#include"Enemy_OrangeRobot.h"
#include"Enemy_Roollingrobot.h"
#include"Enemy_PurpleMachine.h"
#include"Enemy_Turret3.h"
#include"Enemy_BigRedMachine.h"
#include"ChangeAim.h"
#include "BoxChangeAim.h"
#include"ModulePlayer.h"
#include"EnergyCharge.h"
#include"BoxChargeEnergy.h"
#include"Greydoor.h"
#include"Enemy_bosslvl2.h"
#include"Enemy_BossAim.h"
#include"Enemy_BossEye.h"
#include"ModuleFadeToBlack.h"
#include"SPspeed.h"
#include"SPshield.h"
#include"PowerUp.h"
#include "ModuleEffects.h"
#include"BoombpickUp.h"
#define SPAWN_MARGIN 50

ModuleEnemies::ModuleEnemies()
{
	for(uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	sprites = App->textures->Load("Outzone/enemies.png");

	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// check camera position to decide what to spawn
	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
		//	if (queue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				SpawnEnemy(queue[i]);
				queue[i].type = ENEMY_TYPES::NO_TYPE;
				LOG("Spawning enemy at %d", queue[i].y * SCREEN_SIZE);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleEnemies::Update()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{ 
			enemies[i]->Move(); 
		}
	}
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			enemies[i]->Shoot();
		}
	}
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr) 
		{ 
			enemies[i]->Draw(sprites); 
		}
	}
	if (maxpointsearned < pointscount)
	{
		maxpointsearned = pointscount;
	}

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to spawn
	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies[i] != nullptr)
		{
			//if(enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				//LOG("DeSpawning enemy at %d", enemies[i]->position.x * SCREEN_SIZE);
				//delete enemies[i];
				//enemies[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	App->textures->Unload(sprites);

	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPES type, int x, int y)
{
	bool ret = false;

	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(queue[i].type == ENEMY_TYPES::NO_TYPE)
		{
			queue[i].type = type;
			queue[i].x = x;
			queue[i].y = y;
			ret = true;
			break;
		}
	}
	return ret;
}

void ModuleEnemies::SpawnEnemy(const EnemyInfo& info)
{
	// find room for the new enemy
	uint i = 0;
	for(; enemies[i] != nullptr && i < MAX_ENEMIES; ++i);

	if(i != MAX_ENEMIES)
	{
		switch(info.type)
		{
			case ENEMY_TYPES::REDBIRD:
				enemies[i] = new Enemy_RedBird(info.x,info.y);
				break;
			case ENEMY_TYPES::BROWCOOKIES:
				enemies[i] = new Enemy_Cookies(info.x, info.y);
				break;

			case ENEMY_TYPES::TANK:
				enemies[i] = new Enemy_Tank(info.x, info.y);
				break;

			case ENEMY_TYPES::TURRET1:
				enemies[i] = new Enemy_Turret1(info.x, info.y);
				break;

			case ENEMY_TYPES::TURRET2:
				enemies[i] = new Enemy_Turret2(info.x, info.y);
				break;

			case ENEMY_TYPES::GREYROBOT:
				enemies[i] = new Enemy_GreyRobot(info.x, info.y);
				break;

			case ENEMY_TYPES::GREENROBOT:
				enemies[i] = new Enemy_GeenRobot(info.x, info.y);
				break;

			case ENEMY_TYPES::REDMACHINE:
				enemies[i] = new Enemy_RedMachine(info.x, info.y);
				break;

			case ENEMY_TYPES::BLUEMACHINE:
				enemies[i] = new Enemy_BlueMachine(info.x, info.y);
				break;

			case ENEMY_TYPES::ORANGEROBOT:
				enemies[i] = new Enemy_OrangeRobot(info.x, info.y);
				break;

			case ENEMY_TYPES::ROOLLINGROBOT:
				enemies[i] = new Enemy_Rollingrobot(info.x, info.y);
				break;

			case ENEMY_TYPES::PURPLEMACHINE:
				enemies[i] = new Enemy_PurpleMachine(info.x, info.y);
				break;

			case ENEMY_TYPES::TURRET3:
				enemies[i] = new Enemy_Turret3(info.x, info.y);
				break;
				

			case ENEMY_TYPES::GREYDOOR:
				enemies[i] = new Greydoor(info.x, info.y);
				break;

			case ENEMY_TYPES::BOSS:
				enemies[i] = new Enemy_Boss(info.x, info.y);
				break;

			case ENEMY_TYPES::BOSSAIM:
				enemies[i] = new Enemy_Bossaim(info.x, info.y);
				break;

			case ENEMY_TYPES::EYEBOSS:
				enemies[i] = new Enemy_Bosseye(info.x, info.y);
				break;

			case ENEMY_TYPES::CHANGEAIM:
				enemies[i] = new ChangeAim(info.x, info.y);
				break;
			
			case ENEMY_TYPES::ENEMYCHARGE:
				enemies[i] = new Energycharge(info.x, info.y);
				break;

			case ENEMY_TYPES::BOXENERGY:
				enemies[i] = new BoxChargeEnergy(info.x, info.y);
				break;
				
			case ENEMY_TYPES::BOX:
				enemies[i] = new Box(info.x, info.y);
				break;

			case ENEMY_TYPES::SPSPEED:
				enemies[i] = new SPspeed(info.x, info.y);
				break;

			case ENEMY_TYPES::SPSHIELD:
				enemies[i] = new SPshield(info.x, info.y);
				break;

			case ENEMY_TYPES::POWERUP:
				enemies[i] = new Powerup(info.x, info.y);
				break;

			case ENEMY_TYPES::BOOMBPICKUP:
				enemies[i] = new BoombPickUp(info.x, info.y);
				break;

			case ENEMY_TYPES::BIGREDMACHINE:
				enemies[i] = new Enemy_BigRedMachine(info.x, info.y);
				break;

			case ENEMY_TYPES::MAZURKA:
				enemies[i] = new Enemy_Mazurka(info.x, info.y);
				break;

			case ENEMY_TYPES::DOOR:
				enemies[i] = new Enemy_Door(info.x, info.y);
				break;
		}
		
		
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			if ((c1->type == COLLIDER_ENEMY) && ((c2->type == COLLIDER_PLAYER_SHOT) || (c2->type == COLLIDER_BOMB) || (c2->type == COLLIDER_PLAYER) || (c2->type == COLLIDER_SHIELD))){
				App->particles->AddParticle(App->particles->explosionturret, enemies[i]->position.x, enemies[i]->position.y);
				delete enemies[i];
				enemies[i] = nullptr;
				enemycount++;
				break;
			}
			else if ((c1->type == COLLIDER_ROLLINGROBOT) && ((c2->type == COLLIDER_PLAYER_SHOT) || (c2->type == COLLIDER_BOMB) || (c2->type == COLLIDER_PLAYER) || (c2->type == COLLIDER_SHIELD))){
 				rollingrobothits++;
				if (rollingrobothits >= 3){
					App->particles->AddParticle(App->particles->explosionturret, enemies[i]->position.x, enemies[i]->position.y);
					delete enemies[i];
					enemies[i] = nullptr;
					enemycount++;
					pointscount += 1490;
					rollingrobothits = 0;
				}
				break;
			}
			else if ((c1->type == COLLIDER_GREY_ROBOT) && ((c2->type == COLLIDER_PLAYER_SHOT) || (c2->type == COLLIDER_BOMB) || (c2->type == COLLIDER_PLAYER) || (c2->type == COLLIDER_SHIELD))){
				App->particles->AddParticle(App->particles->soldierexplosion, enemies[i]->position.x, enemies[i]->position.y);
				delete enemies[i];
				enemies[i] = nullptr;
				enemycount++;
				pointscount += 390;
				break;
			}
			else if ((c1->type == COLLIDER_BIG_RED_MACHINE) && ((c2->type == COLLIDER_PLAYER_SHOT) || (c2->type == COLLIDER_BOMB) || (c2->type == COLLIDER_PLAYER) || (c2->type == COLLIDER_SHIELD))){
				bigredmachinehits++;
				if (bigredmachinehits >= 5){
					App->particles->AddParticle(App->particles->tankexplosion, enemies[i]->position.x, enemies[i]->position.y);
					delete enemies[i];
					enemies[i] = nullptr;
					enemycount++;
					pointscount += 830;
					bigredmachinehits = 0;
				}
				break;
			}
			else if ((c1->type == COLLIDER_BLUE_MACHINE) && ((c2->type == COLLIDER_PLAYER_SHOT) || (c2->type == COLLIDER_BOMB) || (c2->type == COLLIDER_PLAYER) || (c2->type == COLLIDER_SHIELD))){
				bluemachinehits++;
				if (bluemachinehits >= 2){
					App->particles->AddParticle(App->particles->soldierexplosion, enemies[i]->position.x, enemies[i]->position.y);
					delete enemies[i];
					enemies[i] = nullptr;
					enemycount++;
					pointscount += 940;
					bluemachinehits = 0;
				}
				break;
			}
			else if ((c1->type == COLLIDER_ORANGE_ROBOT) && ((c2->type == COLLIDER_PLAYER_SHOT) || (c2->type == COLLIDER_BOMB) || (c2->type == COLLIDER_PLAYER) || (c2->type == COLLIDER_SHIELD))){
  				orangerobothits++;
				if (orangerobothits >= 2){
					App->particles->AddParticle(App->particles->soldierexplosion, enemies[i]->position.x, enemies[i]->position.y);
					delete enemies[i];
					enemies[i] = nullptr;
					enemycount++;
					pointscount += 430;
					orangerobothits = 0;
				}
				break;
			}
			else if ((c1->type == COLLIDER_PURPLE_MACHINE) && ((c2->type == COLLIDER_PLAYER_SHOT) || (c2->type == COLLIDER_BOMB) || (c2->type == COLLIDER_PLAYER) || (c2->type == COLLIDER_SHIELD))){
				App->particles->AddParticle(App->particles->soldierexplosion, enemies[i]->position.x, enemies[i]->position.y);
				delete enemies[i];
				enemies[i] = nullptr;
				enemycount++;
				pointscount += 410;
				break;
			}
			else if ((c1->type == COLLIDER_RED_MACHINE) && ((c2->type == COLLIDER_PLAYER_SHOT) || (c2->type == COLLIDER_BOMB) || (c2->type == COLLIDER_PLAYER) || (c2->type == COLLIDER_SHIELD))){
				redmachinehits++;
				if (redmachinehits >= 2){
					App->particles->AddParticle(App->particles->soldierexplosion, enemies[i]->position.x, enemies[i]->position.y);
					delete enemies[i];
					enemies[i] = nullptr;
					enemycount++;
					pointscount += 1220;
					redmachinehits = 0;
				}
				break;
			}
			else if ((c1->type == COLLIDER_TURRET1) && ((c2->type == COLLIDER_PLAYER_SHOT) || (c2->type == COLLIDER_BOMB) || (c2->type == COLLIDER_PLAYER) || (c2->type == COLLIDER_SHIELD))){
				turret1hits++;
				if (turret1hits >= 2){
					App->particles->AddParticle(App->particles->explosionturret, enemies[i]->position.x, enemies[i]->position.y);
					delete enemies[i];
					enemies[i] = nullptr;
					enemycount++;
					pointscount += 410;
					turret1hits = 0;
				}
				break;
			}
			else if ((c1->type == COLLIDER_TURRET3) && ((c2->type == COLLIDER_PLAYER_SHOT) || (c2->type == COLLIDER_BOMB) || (c2->type == COLLIDER_PLAYER) || (c2->type == COLLIDER_SHIELD))){
				turret3hits++;
				if (turret3hits >= 3){
					App->particles->AddParticle(App->particles->soldierexplosion, enemies[i]->position.x, enemies[i]->position.y);
					delete enemies[i];
					enemies[i] = nullptr;
					enemycount++;
					pointscount += 290;
					turret3hits = 0;
				}
				break;
			}
			else if ((c1->type == COLLIDER_BOSSEYE) && ((c2->type == COLLIDER_PLAYER_SHOT) || (c2->type == COLLIDER_BOMB) || (c2->type == COLLIDER_PLAYER) || (c2->type == COLLIDER_SHIELD))){
				bosseyehits++;
				pointscount += 10;
				if (c2->type == COLLIDER_BOMB){
					bosseyehits++;
					pointscount += 10;
					bosseyehits++;
					pointscount += 10;
					bosseyehits++;
					pointscount += 10;
					bosseyehits++;
					pointscount += 10;
				}
				if (bosseyehits >= 35){
					delete enemies[i];
					enemies[i] = nullptr;
					enemycount++;
					pointscount += 20000;
					bosseyehits = 0;

					App->player->Disable();
					App->fade->FadeToBlack((Module*)App->scene_space, (Module*)App->scene_gamewin);
					App->player->destroyed = true;
					App->player->poweruplevel = 0;
					App->player->changetaim = false;
					App->enemies->onprobot = false;
					App->enemies->onprobot2 = false;
					App->player->SPSpeed = false;
					App->effects->shieldactive = false;
				}
				break;
			}
			else if ((c1->type == COLLIDER_BOSSWEAPON) && ((c2->type == COLLIDER_PLAYER_SHOT) || (c2->type == COLLIDER_BOMB) || (c2->type == COLLIDER_PLAYER) || (c2->type == COLLIDER_SHIELD))){
				bossweaponhits++;
				pointscount += 10;
				if (c2->type == COLLIDER_BOMB){
					bossweaponhits++;
					pointscount += 10;
					bossweaponhits++;
					pointscount += 10;
					bossweaponhits++;
					pointscount += 10;
					bossweaponhits++;
					pointscount += 10;
				}
				if (bossweaponhits >= 10){
					delete enemies[i];
					enemies[i] = nullptr;
					enemycount++;
					pointscount += 1690;
					bossweaponhits = 0;
				}
				break;
			}
			/*
			else if (((c2->type == COLLIDER_CHANGEAIM) || (c2->type == COLLIDER_ENERGY) || (c2->type == COLLIDER_SPSHIELD) || (c2->type == COLLIDER_SPSPEED) || (c2->type == COLLIDER_POWERUP)) && (c1->type == COLLIDER_SHIELD)){
				break;
			}
			*/
			else if (((c1->type == COLLIDER_CHANGEAIM) || (c1->type == COLLIDER_ENERGY) || (c1->type == COLLIDER_SPSHIELD) || (c1->type == COLLIDER_SPSPEED) || (c1->type == COLLIDER_POWERUP) || (c1->type == COLLIDER_BOOMBPICKUP)) && (c2->type == COLLIDER_SHIELD)){
				break;
			}
			else if (((c1->type == COLLIDER_CHANGEAIM) || (c1->type == COLLIDER_ENERGY) || (c1->type == COLLIDER_SPSHIELD) || (c1->type == COLLIDER_SPSPEED) || (c1->type == COLLIDER_POWERUP) || (c1->type == COLLIDER_BOOMBPICKUP)) && (c2->type == COLLIDER_PLAYER)){
				delete enemies[i];
				enemies[i] = nullptr;
				pointscount += 100;
				break;
			}
			else if ((c1->type == COLLIDER_DOOR) && (c2->type == COLLIDER_PLAYER_SHOT)){
				delete enemies[i];
				enemies[i] = nullptr; 
				pointscount += 100;// i don't know
				if (c1->rect.x == 95 && c1->rect.y == -2280){
					App->enemies->onprobot = true;
				}
				if (c1->rect.x == 30 && c1->rect.y == -2407){
					App->enemies->onprobot2 = true;
				}
				break;
			}
			else if ((c1->type == COLLIDER_BOX) && ((c2->type == COLLIDER_PLAYER_SHOT) || (c2->type == COLLIDER_BOMB))){
				App->particles->AddParticle(App->particles->explosionturret, enemies[i]->position.x, enemies[i]->position.y);
				delete enemies[i];
				enemies[i] = nullptr;
				pointscount += 210;
				break;
			}
		}
	}
}
