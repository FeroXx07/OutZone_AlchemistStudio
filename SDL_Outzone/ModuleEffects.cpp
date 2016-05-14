#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModuleEffects.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"

#include "SDL/include/SDL_timer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleEffects::ModuleEffects()
{
	graphics = NULL;
	effect1 = NULL;
	effect2 = NULL;
	effect3 = NULL;

	position.x = 100;
	position.y = 200;

	god.PushBack({ 248, 47, 38, 38 });
	god.PushBack({ 286, 47, 38, 38 });
	god.PushBack({ 324, 47, 38, 38 });
	god.PushBack({ 362, 47, 38, 38 });
	god.loop = true;
	god.speed = 0.2f;
}

ModuleEffects::~ModuleEffects()
{}

// Load assets
bool ModuleEffects::Start()
{
	LOG("Loading effects");

	graphics = App->textures->Load("Outzone/particle.png");

	position.x = App->player->position.x;
	position.y = App->player->position.y;

	return true;
}

// Unload assets
bool ModuleEffects::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}

update_status ModuleEffects::Update()
{
	if ((App->player->Invencible == true) || (App->player->Superspeed == true) || (App->player->Fly == true)){
		godcurrenttime = SDL_GetTicks();
		if (godcurrenttime > (godactiontime + 400)){
			effect1 = &god;
			godactiontime = godcurrenttime;
		}
	}
	else{
		effect1 = NULL;
	}
	position = App->player->position;

	if (effect1 != nullptr){
		App->render->Blit(graphics, position.x, position.y, &(effect1->GetCurrentFrame()));
	}

	return UPDATE_CONTINUE;
}