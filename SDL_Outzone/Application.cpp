#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleSceneSpace.h"
#include "ModuleSceneSpaceUpper.h"
#include "ModuleSceneIntro.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleSceneGameOver.h"
#include "ModuleWinScreen.h"
#include "ModuleEffects.h"
#include "ModuleUI.h"

Application::Application()
{
	int i = 0;
	modules[i++] = window = new ModuleWindow();
	modules[i++] = render = new ModuleRender();
	modules[i++] = input = new ModuleInput();
	modules[i++] = textures = new ModuleTextures();
	modules[i++] = audio = new ModuleAudio();
	modules[i++] = scene_intro = new ModuleSceneIntro();
	modules[i++] = scene_space = new ModuleSceneSpace();
	modules[i++] = scene_gameover = new ModuleGameOver();
	modules[i++] = scene_gamewin = new ModuleWinScreen();
	modules[i++] = enemies = new ModuleEnemies();
	modules[i++] = player = new ModulePlayer();
	modules[i++] = scene_space_upper = new ModuleSceneSpaceUpper();
	modules[i++] = particles = new ModuleParticles();
	modules[i++] = effects = new ModuleEffects();
	modules[i++] = ui = new ModuleUI();
	modules[i++] = collision = new ModuleCollision();
	modules[i++] = fade = new ModuleFadeToBlack();

}	

Application::~Application()
{
	for(int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	// Deactivate modules here ----
	scene_gamewin->Disable();
	scene_space->Disable();
	scene_gameover->Disable();
	player->Disable();
	effects->Disable();
	collision->Disable();
	enemies->Disable();
	ui->Disable();
	// ----------------------------

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->IsEnabled() ? modules[i]->CleanUp() : true;

	return ret;
}