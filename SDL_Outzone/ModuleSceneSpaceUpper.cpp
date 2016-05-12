#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "ModuleSceneSpaceUpper.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"

#include "SDL/include/SDL_timer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneSpaceUpper::ModuleSceneSpaceUpper()
{}

ModuleSceneSpaceUpper::~ModuleSceneSpaceUpper()
{}

// Load assets
bool ModuleSceneSpaceUpper::Start()
{
	LOG("Loading space scene");
	background = App->textures->Load("Outzone/Map2_Upper.png");
	return true;
}

// UnLoad assets
bool ModuleSceneSpaceUpper::CleanUp()
{
	LOG("Unloading space scene");
	
	App->audio->Disable();
	Mix_FadeOutMusic(500);
	App->enemies->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->player->Disable();
	App->textures->Unload(background);

	return true;
}

// Update: draw background
update_status ModuleSceneSpaceUpper::Update()
{
	/*
	if (App->player->position.y <= -3160){
		App->fade->FadeToBlack(this, (Module*)App->scene_gamewin);
	}
	*/
	// Draw everything --------------------------------------
	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT){
		if (App->player->position.y == (160 + (App->render->camera.y / 2))){
			if (firstimeblit == true){
				App->render->Blit(background, 0, -5253, NULL);
				firstimeblit = false;
			}
			else{
				App->render->Blit(background, 0, -5255, NULL);
			}
		}
		else{
			App->render->Blit(background, 0, -5253, NULL);
		}
	}
	else{
		App->render->Blit(background, 0, -5253, NULL);
	}
	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT){
		firstimeblit = true;
	}
	return UPDATE_CONTINUE;
}