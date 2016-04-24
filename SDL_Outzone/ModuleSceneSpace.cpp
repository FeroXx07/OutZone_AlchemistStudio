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

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneSpace::ModuleSceneSpace()
{}

ModuleSceneSpace::~ModuleSceneSpace()
{}

// Load assets
bool ModuleSceneSpace::Start()
{
	LOG("Loading space scene");
	
	background = App->textures->Load("Outzone/Maps1.png");

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();

	//App->audio->PlayMusic("rtype/stage1.ogg", 1.0f);
	
	// Colliders ---
	App->collision->AddCollider({0, 224, 3930, 16}, COLLIDER_WALL);
	App->collision->AddCollider({1375, 0, 111, 96}, COLLIDER_WALL);
	App->collision->AddCollider({1375, 145, 111, 96}, COLLIDER_WALL);
	App->collision->AddCollider({ 60, 1894, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 180, 1664, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, 1634, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 90, 1545, 30, 62 }, COLLIDER_WALL);

	App->collision->AddCollider({ 0, 2194, 31, 37 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -2060, 117, 139 }, COLLIDER_WALL);
	App->collision->AddCollider({ 186, -2061, 54, 136 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -1796, 56, 131 }, COLLIDER_WALL);
	App->collision->AddCollider({ 127, -1794, 114, 136 }, COLLIDER_WALL);

	App->collision->AddCollider({ 120, -665, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 180, -2590, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -2472, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 152, -2323, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 151, -3188, 89, 87 }, COLLIDER_WALL);
	App->collision->AddCollider({ 177, -3275, 64, 34 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -3377, 90, 98 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -3158, 51, 24 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -416, 90, 60 }, COLLIDER_WALL);
	App->collision->AddCollider({ 150, -416, 90, 60 }, COLLIDER_WALL);

	// Enemies ---
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

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, -3314, NULL);
	
	return UPDATE_CONTINUE;
}