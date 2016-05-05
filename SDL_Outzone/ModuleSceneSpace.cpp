#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleSceneSpace.h"
#include "ModuleFadeToBlack.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneSpace::ModuleSceneSpace()
{}

ModuleSceneSpace::~ModuleSceneSpace()
{}

// Load assets
bool ModuleSceneSpace::Start()
{
	LOG("Loading space scene");
	
	background = App->textures->Load("Outzone/MapRealSize.png");

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();

	App->audio->PlayMusic("Outzone/outzone_2.ogg", 1.0f);
	
	// Colliders ---
	
	App->collision->AddCollider({ 60, -1624, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 180, -1654, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -1684, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 90, -1773, 30, 62 }, COLLIDER_WALL);

	App->collision->AddCollider({ 0, -1124, 31, 37 }, COLLIDER_WALL2);
	App->collision->AddCollider({ 0, -1258, 117, 139 }, COLLIDER_WALL2);
	App->collision->AddCollider({ 186, -1257, 54, 136 }, COLLIDER_WALL2);
	App->collision->AddCollider({ 0, -1522, 56, 131 }, COLLIDER_WALL2);
	App->collision->AddCollider({ 127, -1524, 114, 136 }, COLLIDER_WALL2);

	App->collision->AddCollider({ 120, -668, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 180, -728, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -846, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 150, -996, 30, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 151, -130, 89, 87 }, COLLIDER_WALL);
	App->collision->AddCollider({ 177, -43, 64, 34 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -137, 90, 196 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -160, 51, 24 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, -2908, 90, 70 }, COLLIDER_WALL);
	App->collision->AddCollider({ 150, -2908, 90, 70 }, COLLIDER_WALL);

	// Enemies ---
	App->enemies->AddEnemy(ENEMY_TYPES::DOOR, 60, -2920);

	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 123, -568);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 3, -538);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 183, -628);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 123, -928);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 190, -1998);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 3, -2006);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 70, -2013);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 18, -1968);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 130, -2020);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 93, -1975);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 145, -1968);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 40, -1929);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 138, -1900);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 100, -1929);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 70, -1893);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 10, -1886);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 190, -1879);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 168, -1923);

	App->enemies->AddEnemy(ENEMY_TYPES::MAZURKA, 90, -3100);

	return true;
}

// UnLoad assets
bool ModuleSceneSpace::CleanUp()
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
update_status ModuleSceneSpace::Update()
{
	// Move camera forward -----------------------------
	//App->render->camera.x += 1 * SCREEN_SIZE;
	if (App->player->position.y <= -3160){
		App->fade->FadeToBlack(this, (Module*)App->scene_gamewin);
	}

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, -3314, NULL);
	
	return UPDATE_CONTINUE;
}