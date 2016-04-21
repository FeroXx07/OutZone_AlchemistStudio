#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleSceneLvl1.h"
#include "ModuleFadeToBlack.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneLvl1::ModuleSceneLvl1()
{
	back.x = 0;
	back.y = 0;
	back.w = 240;
	back.h = 3634;
}

ModuleSceneLvl1::~ModuleSceneLvl1()
{}

// Load assets
bool ModuleSceneLvl1::Start()
{
	LOG("Loading lvl1 scene");
	
	background = App->textures->Load("Outzone/Maps1.png");

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();

	App->audio->PlayMusic("rtype/outzone_002.ogg", 1.0f);
	
	// Colliders ---
	App->collision->AddCollider({ 120, 2650, 30, 62 }, COLLIDER_WALL);

	// Enemies ---
	/*
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 600, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 625, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 640, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 665, 80);
	*/
	
	// TODO 1: Add a new wave of red birds
	
	return true;
}

// UnLoad assets
bool ModuleSceneLvl1::CleanUp()
{
	LOG("Unloading lvl1 scene");

 	App->textures->Unload(background);

	App->enemies->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleSceneLvl1::Update()
{
	// Move camera forward -----------------------------
	//App->render->camera.x += 1 * SCREEN_SIZE;

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, -3634 + SCREEN_HEIGHT, &back, 0.75f);

	if ((App->player->position.y == -4284) && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene_intro);
	}
	
	return UPDATE_CONTINUE;
}