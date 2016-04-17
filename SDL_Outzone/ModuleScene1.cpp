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
	back.h = 3312;
}

ModuleScene1::~ModuleScene1()
{}

// Load assets
bool ModuleScene1::Start()
{
	LOG("Loading space scene");

	backgroundo = App->textures->Load("rtype/Maps1.png");

	App->player->Enable();

	return true;
}

// UnLoad assets
bool ModuleScene1::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(backgroundo);
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
	App->render->Blit(backgroundo, 0, -3312+SCREEN_HEIGHT, &back, 0.75f);
	//App->render->Blit(background, 0, 0, NULL);

	return UPDATE_CONTINUE;
}