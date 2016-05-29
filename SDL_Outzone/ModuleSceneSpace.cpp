#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleSceneSpace.h"
#include "ModuleFadeToBlack.h"
#include "ModuleEffects.h"
#include "ModuleUI.h"


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneSpace::ModuleSceneSpace()
{}

ModuleSceneSpace::~ModuleSceneSpace()
{}

// Load assets
bool ModuleSceneSpace::Start()
{
	LOG("Loading space scene");
	
	background = App->textures->Load("Outzone/level2.png");

	App->player->Enable();
	App->effects->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	App->ui->Enable();


	App->audio->PlayMusic("Outzone/outzone_008.ogg", 1.0f);
	
	// Colliders ---
	App->collision->AddCollider({ 160, -500, 80, 67 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -985, 90, 40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 163, -985, 90, 40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -2265, 100, 40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 155, -2265, 100, 40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -2390, 37, 40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 90, -2390, 150, 40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 160, -2908, 32, 110 }, COLLIDER_WALL);
	App->collision->AddCollider({ 64, -2908, 32, 110 }, COLLIDER_WALL);
	App->collision->AddCollider({ 190, -3100, 69, 108 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -3100, 69, 108 }, COLLIDER_WALL);
	App->collision->AddCollider({ 95, -2550, 68, 169 }, COLLIDER_WALL);
	
	//Bottom holes
	App->collision->AddCollider({ 0, -1469, 58, 190 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 198, -1469, 65, 190 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 80, -1599, 80, 36 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 0, -1727, 80, 37 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 48, -1790, 46, 100 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 176, -1759, 14, 65 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 176, -1726, 70, 35 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 0, -1918, 32, 35 }, COLLIDER_HOLE);
	
	App->collision->AddCollider({ 112, -1918, 70, 35 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 179, -1918, 70, 65 }, COLLIDER_HOLE);
	
	App->collision->AddCollider({ 0, -2111, 32, 100 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 112, -2111, 16, 100 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 208, -2111, 35, 100 }, COLLIDER_HOLE);
	//Top holes
	App->collision->AddCollider({ 209, -3998, 35, 37 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 83, -4030, 40, 67 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 0, -4030, 29, 67 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 210, -4158, 35, 67 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 82, -4190, 46, 67 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 148, -4158, 9, 67 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 110, -4158, 44, 35 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 0, -4350, 52, 66 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 52, -4382, 11, 129 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 55, -4319, 70, 35 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 115, -4350, 9, 66 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 0, -4478, 61, 33 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 112, -4478, 15, 65 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 178, -4478, 66, 90 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 178, -4388, 66, 40 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 120, -4447, 70, 34 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 0, -4638, 63, 37 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 50, -4607, 70, 38 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 111, -4670, 15, 101 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 176, -4702, 70, 37 }, COLLIDER_HOLE);
	
	App->collision->AddCollider({ 0, -4798, 62, 37 }, COLLIDER_HOLE);
	
	App->collision->AddCollider({ 176, -4798, 15, 37 }, COLLIDER_HOLE);

	//CHANGE AIM COLLIDER

	//colliderchangeaim1 = App->collision->AddCollider({ 90, -100, 40, 40 }, COLLIDER_CHANGEAIM);
	//colliderchangeaim1 = App->collision->AddCollider({ 90, -150, 40, 40 }, COLLIDER_CHANGEAIM);
	// Enemies ---
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 124, -714);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 148, -746);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 188, -762);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 28, -859);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, -4, -1066);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 204, -1066);

	App->enemies->AddEnemy(ENEMY_TYPES::TURRET3, 45, -940);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET3, 175, -940);

	App->enemies->AddEnemy(ENEMY_TYPES::GREYROBOT, 20, -100);
	App->enemies->AddEnemy(ENEMY_TYPES::GREYROBOT, 40, -100);
	App->enemies->AddEnemy(ENEMY_TYPES::GREYROBOT, 60, -100);
	App->enemies->AddEnemy(ENEMY_TYPES::GREYROBOT, 220, -100);

	App->enemies->AddEnemy(ENEMY_TYPES::REDMACHINE, 50, 200);
	App->enemies->AddEnemy(ENEMY_TYPES::BLUEMACHINE, 50, 150);
	App->enemies->AddEnemy(ENEMY_TYPES::ORANGEROBOT, 50, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::PURPLEMACHINE, 50, 50);
	App->enemies->AddEnemy(ENEMY_TYPES::ORANGEROBOT, 200, -480);
	App->enemies->AddEnemy(ENEMY_TYPES::ORANGEROBOT, 210, -480);
	//BOX
	//App->enemies->AddEnemy(ENEMY_TYPES::CHANGEAIM, 90, -100);
	
	App->enemies->AddEnemy(ENEMY_TYPES::CHANGEAIM, 18, -462);
	App->enemies->AddEnemy(ENEMY_TYPES::BOX, 10, -470);
	//App->enemies->AddEnemy(ENEMY_TYPES::BOX, 10, -470);
	
	App->enemies->AddEnemy(ENEMY_TYPES::CHANGEAIM, 13, -932);
	App->enemies->AddEnemy(ENEMY_TYPES::BOX, 5, -940);
	
	App->enemies->AddEnemy(ENEMY_TYPES::CHANGEAIM, 203, -1232);
	App->enemies->AddEnemy(ENEMY_TYPES::BOX, 195, -1240);
	
	App->enemies->AddEnemy(ENEMY_TYPES::CHANGEAIM, 183, -2422);
	App->enemies->AddEnemy(ENEMY_TYPES::BOX, 175, -2430);

	App->enemies->AddEnemy(ENEMY_TYPES::CHANGEAIM, 213, -2472);
	App->enemies->AddEnemy(ENEMY_TYPES::BOX, 205, -2480);

	App->enemies->AddEnemy(ENEMY_TYPES::CHANGEAIM, 173, -2512);
	App->enemies->AddEnemy(ENEMY_TYPES::BOX, 165, -2520);

	App->enemies->AddEnemy(ENEMY_TYPES::CHANGEAIM, 13, -3352);
	App->enemies->AddEnemy(ENEMY_TYPES::BOX, 5, -3360);

	App->enemies->AddEnemy(ENEMY_TYPES::CHANGEAIM, 213, -3822);
	App->enemies->AddEnemy(ENEMY_TYPES::BOX, 205, -3830);

	App->enemies->AddEnemy(ENEMY_TYPES::CHANGEAIM, 10, -4250);
	App->enemies->AddEnemy(ENEMY_TYPES::BOX, 2, -4258);

	App->enemies->AddEnemy(ENEMY_TYPES::CHANGEAIM, 173, -4850);
	App->enemies->AddEnemy(ENEMY_TYPES::BOX, 165, -4858);

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMYCHARGE, 18, -362);
	App->enemies->AddEnemy(ENEMY_TYPES::BOXENERGY, 10, -370);

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMYCHARGE, 18, -1232);
	App->enemies->AddEnemy(ENEMY_TYPES::BOXENERGY, 10, -1240);

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMYCHARGE, 10, -1762);
	App->enemies->AddEnemy(ENEMY_TYPES::BOXENERGY, 2, -1770);

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMYCHARGE, 215, -2432);
	App->enemies->AddEnemy(ENEMY_TYPES::BOXENERGY, 207, -2440);

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMYCHARGE, 175, -2472);
	App->enemies->AddEnemy(ENEMY_TYPES::BOXENERGY, 168, -2480);

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMYCHARGE, 20, -2972);
	App->enemies->AddEnemy(ENEMY_TYPES::BOXENERGY, 13, -2980);

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMYCHARGE, 190, -3350);
	App->enemies->AddEnemy(ENEMY_TYPES::BOXENERGY, 183, -3358);

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMYCHARGE, 15, -3880);
	App->enemies->AddEnemy(ENEMY_TYPES::BOXENERGY, 8, -3888);

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMYCHARGE, 7, -4390);
	App->enemies->AddEnemy(ENEMY_TYPES::BOXENERGY, 0, -4398);

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMYCHARGE, 97, -4790);
	App->enemies->AddEnemy(ENEMY_TYPES::BOXENERGY, 90, -4798);

	App->enemies->AddEnemy(ENEMY_TYPES::BLUEMACHINE, 191,-1179);
	App->enemies->AddEnemy(ENEMY_TYPES::BLUEMACHINE, 0, -1180);
	App->enemies->AddEnemy(ENEMY_TYPES::BLUEMACHINE, 191, -1139);
	App->enemies->AddEnemy(ENEMY_TYPES::BLUEMACHINE, 0, -1140);
	App->enemies->AddEnemy(ENEMY_TYPES::BLUEMACHINE, 191, -1099);
	App->enemies->AddEnemy(ENEMY_TYPES::BLUEMACHINE, 0, -1100);

	App->enemies->AddEnemy(ENEMY_TYPES::GREYROBOT, 0, -1850);//platos
	App->enemies->AddEnemy(ENEMY_TYPES::GREYROBOT, 0, -1970);
	App->enemies->AddEnemy(ENEMY_TYPES::GREYROBOT, 206, -1970);
	App->enemies->AddEnemy(ENEMY_TYPES::GREYROBOT, 0, -2160);
	App->enemies->AddEnemy(ENEMY_TYPES::GREYROBOT, 206, -2160);

	App->enemies->AddEnemy(ENEMY_TYPES::TURRET3, 205, -1778);

	App->enemies->AddEnemy(ENEMY_TYPES::ROOLLINGROBOT, 0, -1850);//platos
	App->enemies->AddEnemy(ENEMY_TYPES::ROOLLINGROBOT, 0, -1970);
	//App->enemies->AddEnemy(ENEMY_TYPES::ROOLLINGROBOT, 206, -1970);
	App->enemies->AddEnemy(ENEMY_TYPES::ROOLLINGROBOT, 0, -2160);
	App->enemies->AddEnemy(ENEMY_TYPES::ROOLLINGROBOT, 206, -2200);

	App->enemies->AddEnemy(ENEMY_TYPES::PURPLEMACHINE, 1, -2310);
	App->enemies->AddEnemy(ENEMY_TYPES::PURPLEMACHINE, 30, -2340);
	App->enemies->AddEnemy(ENEMY_TYPES::PURPLEMACHINE, 50, -2310);

	App->enemies->AddEnemy(ENEMY_TYPES::PURPLEMACHINE, 200, -2310);
	App->enemies->AddEnemy(ENEMY_TYPES::PURPLEMACHINE, 170, -2340);
	App->enemies->AddEnemy(ENEMY_TYPES::PURPLEMACHINE, 150, -2310);

	App->enemies->AddEnemy(ENEMY_TYPES::PURPLEMACHINE, 40, -2440);
	App->enemies->AddEnemy(ENEMY_TYPES::PURPLEMACHINE, 40, -2480);
	App->enemies->AddEnemy(ENEMY_TYPES::PURPLEMACHINE, 40, -2520);

	App->enemies->AddEnemy(ENEMY_TYPES::PURPLEMACHINE, 10, -2440);
	App->enemies->AddEnemy(ENEMY_TYPES::PURPLEMACHINE, 10, -2480);
	App->enemies->AddEnemy(ENEMY_TYPES::PURPLEMACHINE, 10, -2520);

	App->enemies->AddEnemy(ENEMY_TYPES::GREYDOOR, 95, -2280);
	App->enemies->AddEnemy(ENEMY_TYPES::GREYDOOR, 30, -2407);

	//Boss
	App->enemies->AddEnemy(ENEMY_TYPES::BOSS, 15, -5403);

	return true; 
}

// UnLoad assets
bool ModuleSceneSpace::CleanUp()
{
	LOG("Unloading space scene");
	
	App->audio->Disable();
	Mix_FadeOutMusic(500);
	App->enemies->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->player->Disable();
	App->effects->Disable();
	App->textures->Unload(background);

	return true;
}

// Update: draw background
update_status ModuleSceneSpace::Update()
{
	// Move camera forward -----------------------------
	//App->render->camera.x += 1 * SCREEN_SIZE;
	/*
	if (App->player->position.y <= -3160){
		App->fade->FadeToBlack(this, (Module*)App->scene_gamewin);
	}
	*/
	App->render->Blit(background, 0, -5253, NULL);
	
	return UPDATE_CONTINUE;
}