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

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneSpace::ModuleSceneSpace()
{}

ModuleSceneSpace::~ModuleSceneSpace()
{}

// Load assets
bool ModuleSceneSpace::Start()
{
	LOG("Loading space scene");
	
	background = App->textures->Load("Outzone/MapRealSize.png");

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();

	//App->audio->PlayMusic("rtype/stage1.ogg", 1.0f);
	
	// Colliders ---
	
	App->collision->AddCollider({ 60, -1624, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 180, -1654, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -1684, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 90, -1773, 30, 62 }, COLLIDER_WALL);

	App->collision->AddCollider({ 0, -1124, 31, 37 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -1258, 117, 139 }, COLLIDER_WALL);
	App->collision->AddCollider({ 186, -1257, 54, 136 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -1522, 56, 131 }, COLLIDER_WALL);
	App->collision->AddCollider({ 127, -1524, 114, 136 }, COLLIDER_WALL);

	App->collision->AddCollider({ 120, -668, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 180, -728, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -846, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 150, -996, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 151, -130, 89, 87 }, COLLIDER_WALL);
	App->collision->AddCollider({ 177, -43, 64, 34 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -137, 90, 196 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -160, 51, 24 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -2908, 90, 70 }, COLLIDER_WALL);
	App->collision->AddCollider({ 150, -2908, 90, 70 }, COLLIDER_WALL);

	// Enemies ---
	/*
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 600, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 625, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 640, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 665, 80);
	
	// TODO 1: Add a new wave of red birds
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 650, 120);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 675, 120);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 695, 120);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 715, 120);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWCOOKIES, 650, 50);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWCOOKIES, 675, 50);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWCOOKIES, 695, 50);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWCOOKIES, 715, 50);
	App->enemies->AddEnemy(ENEMY_TYPES::TANK, 715, 150);
	*/
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 123, -568);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 3, -538);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 183, -628);

	return true;
}

// UnLoad assets
bool ModuleSceneSpace::CleanUp()
{
	LOG("Unloading space scene");

 	App->textures->Unload(background);

	App->enemies->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleSceneSpace::Update()
{
	// Move camera forward -----------------------------
	//App->render->camera.x += 1 * SCREEN_SIZE;
	if (App->player->position.y <= -3160){
		App->fade->FadeToBlack(this, (Module*)App->scene_intro);
	}

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, -3314, NULL);
	
	return UPDATE_CONTINUE;
}