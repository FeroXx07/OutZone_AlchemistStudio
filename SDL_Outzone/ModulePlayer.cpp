#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleScene1.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	//camera.x = camera.y = 0;
	graphics = NULL;
	current_animation = NULL;

	position.x = 100;
	position.y = 200;

	// idle animation
	idle.PushBack({ 24, 343, 29, 38 });
	//MOVEMENT
	// move upwards
	up.PushBack({ 65, 344, 27, 37 });
	up.PushBack({ 102, 344, 27, 37 });
	up.PushBack({ 138, 344, 26, 37 });
	up.PushBack({ 173, 344, 28, 37 });
	up.loop = true;
	up.speed = 0.1f;

	// Move down
	down.PushBack({ 191, 285, 31, 39 });
	down.PushBack({ 234, 285, 28, 39 });
	down.PushBack({ 274, 287, 27, 37 });
	down.PushBack({ 316, 285, 28, 39 });
	down.loop = true;
	down.speed = 0.1f;
	//left
	left.PushBack({ 21, 137, 28, 33 });
	left.PushBack({ 59, 135, 28, 35 });
	left.PushBack({ 97, 135, 29, 35 });
	left.PushBack({ 136, 135, 27, 35 });
	left.PushBack({ 173, 135, 29, 35 });
	left.loop = true;
	left.speed = 0.1f;
	//right
	right.PushBack({ 61, 25, 27, 35 });
	right.PushBack({ 103, 25, 25, 36 });
	right.PushBack({ 138, 26, 28, 35 });
	right.PushBack({ 176, 24, 26, 37 });
	right.PushBack({ 212, 26, 29, 35 });
	right.loop = true;
	right.speed = 0.1f;
	//Diagonal right top
	Drightop.PushBack({ 19, 24, 27, 36 });
	Drightop.PushBack({ 297, 344, 25, 37 });
	Drightop.loop = true;
	Drightop.speed = 0.05f;
	//Diagonal left top
	Lefthtop.PushBack({ 58, 79, 29, 36 });
	Lefthtop.PushBack({ 97, 78, 28, 37 });
	Lefthtop.loop = true;
	Lefthtop.speed = 0.05f;
	//Diagonal right bot
	Drighbot.PushBack({ 27, 238, 28, 37 });
	Drighbot.PushBack({ 66, 238, 27, 37 });
	Drighbot.loop = true;
	Drighbot.speed = 0.05f;
	//Diagonal left bot
	Lefthbot.PushBack({ 63, 187, 30, 37 });
	Lefthbot.PushBack({ 105, 288, 30, 36 });
	Lefthbot.loop = true;
	Lefthbot.speed = 0.05f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("rtype/playermovement.png");

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	int speed = 1;

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed;
		if (current_animation != &left)
		{
			left.Reset();
			current_animation = &left;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
		if (current_animation != &right)
		{
			right.Reset();
			current_animation = &right;
		}

	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
		if (current_animation != &down)
		{
			down.Reset();
			current_animation = &down;
		}
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT){

			if (current_animation != &Drighbot)
			{

				current_animation = &Drighbot;


			}
		}

		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT){

			if (current_animation != &Lefthbot)
			{

				current_animation = &Lefthbot;


			}
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;

		if (current_animation != &up)
		{
			up.Reset();
			current_animation = &up;


		}
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT){

			if (current_animation != &Drightop)
			{

				current_animation = &Drightop;


			}
		}
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT){

			if (current_animation != &Lefthtop)
			{

				current_animation = &Lefthtop;


			}
		}
	}



	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		int i = 0;
		i++;
		App->particles->AddParticle(App->particles->shoot, position.x + 19, position.y - 8);
		//App->particles->AddParticle(App->particles->shoot, position.x +11, position.y, 500);







	}
	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)
		current_animation = &idle;


	// Draw everything --------------------------------------

	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}