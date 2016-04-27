#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleWinScreen.h"


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleWinScreen::ModuleWinScreen()
{}

ModuleWinScreen::~ModuleWinScreen()
{}

// Load assets
bool ModuleWinScreen::Start()
{
	LOG("Loading game over");

	background = App->textures->Load("Outzone/Gamefinal1v.1.png");

	//App->audio->PlayMusic("rtype/intro.ogg", 1.0f);
	//	fx = App->audio->LoadFx("rtype/starting.wav");
	App->render->camera.x = App->render->camera.y = 0;

	return true;
}

// UnLoad assets
bool ModuleWinScreen::CleanUp()
{
	LOG("Unloading game over");

	App->textures->Unload(background);
	App->audio->UnLoadFx(fx);

	return true;
}

// Update: draw background
update_status ModuleWinScreen::Update()
{
	
	App->render->Blit(background, 0, 0, NULL);
	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack((Module*)App->scene_gamewin, (Module*)App->scene_intro);
		App->audio->PlayFx(fx);
	}

	return UPDATE_CONTINUE;
}