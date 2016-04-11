#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleScene1.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleScene1::ModuleScene1()
{
	// Background / sky
	
	back.x = 0;
	back.y = 0;
	back.w = 240;
	back.h = 14359;
}

ModuleScene1::~ModuleScene1()
{}

// Load assets
bool ModuleScene1::Start()
{
	LOG("Loading space scene");

	background = App->textures->Load("rtype/Maps.png");

	App->player->Enable();

	return true;
}

// UnLoad assets
bool ModuleScene1::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleScene1::Update()
{
	// Move camera forward -----------------------------
	//int scroll_speed = 1;

	//App->player->position.x += 1;
	//App->render->camera.x -= 3;


	// Draw everything --------------------------------------
	App->render->Blit(background, 0, -14034, &back, 0.75f);
	//App->render->Blit(background, 0, 0, NULL);

	return UPDATE_CONTINUE;
}