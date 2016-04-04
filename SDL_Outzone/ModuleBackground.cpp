#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
{
	// ground
	ground.x = 8;
	ground.y = 391;
	ground.w = 896;
	ground.h = 72;

	// Background / sky
	background.x = 0;
	background.y = 0;
	background.w = 240;
	background.h = 14359;

	// flag animation
	flag.PushBack({848, 208, 40, 40});
	flag.PushBack({848, 256, 40, 40});
	flag.PushBack({848, 304, 40, 40});
	flag.speed = 0.08f;

	//Ship
	ship.x = 8;
	ship.y = 24;
	ship.w = 529;
	ship.h = 205;
	/*ship.PushBack({ 8, 24, 529, 205 });
	ship.PushBack({ 8, 26, 529, 205 });
	ship.PushBack({ 8, 28, 529, 205 });
	ship.PushBack({ 8, 26, 529, 205 });
	ship.speed = 0.08f;*/
	//People1
	people1.PushBack({ 624, 17, 31, 56});
	people1.PushBack({ 624, 81, 31, 56 });
	people1.PushBack({ 624, 145, 31, 56 });
	people1.PushBack({ 624, 81, 31, 56 });
	
	//people1.PushBack({ 8, 26, 529, 205 });
	//people1.PushBack({ 8, 28, 529, 205 });
	
	people1.speed = 0.08f;
	
}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Maps.png");
	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{
	// Draw everything --------------------------------------
	
	App->render->Blit(graphics, 0, -14034, &background, 0.75f); // sea and sky
	//App->render->Blit(graphics, 200, 200, &background, 0.75f);
	//App->render->Blit(graphics, 560, 8, &(flag.GetCurrentFrame()), 0.75f); // flag animation

	// TODO 2: Draw the ship from the sprite sheet with some parallax effect
	
	
		//App->render->Blit(graphics, 0, 0 - i, &ship, 0.75f);
		
	
		
	
	
	
	// TODO 3: Animate the girl on the ship (see the sprite sheet)
	

	
	//App->render->Blit(graphics, 192,  105, &(people1.GetCurrentFrame()), 0.75f);
	
	//App->render->Blit(graphics, 0, 170, &ground);

	return UPDATE_CONTINUE;
}