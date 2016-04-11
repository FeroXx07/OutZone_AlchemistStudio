#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleMenu.h"
#include "ModuleInput.h"
#include "ModuleScene1.h"
#include "ModuleFadeToBlack.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleMenu::ModuleMenu()
{}

ModuleMenu::~ModuleMenu()
{}

// Load assets
bool ModuleMenu::Start()
{
	LOG("Loading space scene");

	background = App->textures->Load("rtype/UI_Title.png");
	App->scene_1->Disable();
	App->player->Disable();

	return true;
}

// UnLoad assets
bool ModuleMenu::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleMenu::Update()
{
	// Move camera forward -----------------------------
	//int scroll_speed = 0;

	//App->player->position.x += 1;
	//App->render->camera.x -= 3;


	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);
	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
	{
		App->fade->FadeToBlack(App->menu, App->scene_1, 0.1);

	}
	return UPDATE_CONTINUE;
}