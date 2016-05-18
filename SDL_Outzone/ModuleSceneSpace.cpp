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

	App->audio->PlayMusic("Outzone/outzone_2.ogg", 1.0f);
	
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
	App->collision->AddCollider({ 208, -3989, 35, 45 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 80, -4021, 48, 76 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 0, -4021, 32, 76 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 208, -4149, 35, 76 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 80, -4181, 48, 76 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 144, -4149, 18, 76 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 110, -4149, 48, 44 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 0, -4341, 52, 76 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 47, -4373, 19, 139 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 55, -4310, 70, 45 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 111, -4341, 19, 76 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 0, -4469, 66, 44 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 111, -4469, 19, 76 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 175, -4469, 66, 100 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 175, -4373, 66, 44 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 120, -4438, 70, 45 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 0, -4629, 66, 44 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 50, -4598, 70, 45 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 110, -4661, 20, 108 }, COLLIDER_HOLE);

	App->collision->AddCollider({ 176, -4693, 70, 45 }, COLLIDER_HOLE);
	
	App->collision->AddCollider({ 0, -4789, 66, 44 }, COLLIDER_HOLE);
	
	App->collision->AddCollider({ 176, -4789, 18, 44 }, COLLIDER_HOLE);
	// Enemies ---
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 124, -714);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 148, -746);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 188, -762);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 28, -859);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, -4, -1066);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 204, -1066);

	App->enemies->AddEnemy(ENEMY_TYPES::REDMACHINE, 50, 200);
	App->enemies->AddEnemy(ENEMY_TYPES::BLUEMACHINE, 50, 150);
	App->enemies->AddEnemy(ENEMY_TYPES::ORANGEROBOT, 50, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::PURPLEMACHINE, 50, 50);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET3, 50, 0);

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
	// Draw everything --------------------------------------
	App->render->Blit(background, 0, -5253, NULL);
	
	return UPDATE_CONTINUE;
}