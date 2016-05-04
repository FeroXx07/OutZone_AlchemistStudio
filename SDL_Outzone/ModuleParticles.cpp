#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

#include "SDL/include/SDL_timer.h"

#define weaponshootlife 30
#define laserlife 600
#define enemyshootlife 2000

ModuleParticles::ModuleParticles()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
	//bomb
	bomb.anim.PushBack({ 0, 490, 240, 320 });
	bomb.anim.PushBack({240, 490, 240, 320 });
	bomb.anim.PushBack({ 480, 490, 240, 320 });
	bomb.anim.PushBack({720, 490, 240, 320 });
	bomb.anim.PushBack({ 960, 490, 240, 320 });
	bomb.anim.PushBack({ 1200, 490, 240, 320 });
	bomb.anim.PushBack({ 1440, 490, 240, 320 });
	bomb.anim.PushBack({ 1680, 490, 240, 320 });
	bomb.anim.PushBack({1920, 490, 240, 320 });
	bomb.anim.PushBack({ 2160, 490, 240, 320 });
	bomb.anim.PushBack({ 2400, 490, 240, 320 });
	bomb.anim.PushBack({ 2640, 490, 240, 320 });
	bomb.anim.PushBack({ 2880, 490, 240, 320 });
	bomb.anim.PushBack({ 3120, 490, 240, 320 });
	bomb.anim.PushBack({ 3360, 490, 240, 320 });
	bomb.anim.PushBack({ 3600, 490, 240, 320 });
	bomb.anim.PushBack({ 3840, 490, 240, 320 });
	bomb.anim.speed = 0.5f;
	bomb.speed.x = 0;
	bomb.speed.y = 0;


	explosionturret.anim.PushBack({117, 332, 33, 38});
	explosionturret.anim.PushBack({215, 333, 35, 35});
	explosionturret.anim.PushBack({ 14, 387, 38, 38 });
	explosionturret.anim.PushBack({ 98, 390, 30, 35 });
	explosionturret.anim.PushBack({ 138, 387, 31, 38 });
	explosionturret.anim.PushBack({ 179, 386, 31, 39 });
	explosionturret.anim.PushBack({ 219, 384, 27, 42 });
	explosionturret.anim.loop = false;
	explosionturret.anim.speed = 0.3f;

	playerexplosion.anim.PushBack({ 348, 16, 118, 116 });
	playerexplosion.anim.PushBack({ 462, 16, 118, 116 });
	playerexplosion.anim.PushBack({ 584, 16, 118, 116 });
	playerexplosion.anim.PushBack({ 700, 16, 118, 116 });
	playerexplosion.anim.PushBack({ 307, 185, 118, 116 });
	playerexplosion.anim.PushBack({ 425, 185, 118, 116 });
	playerexplosion.anim.PushBack({ 541, 185, 118, 116 });
	playerexplosion.anim.PushBack({ 659, 185, 118, 116 });
	playerexplosion.anim.PushBack({ 775, 185, 118, 118 });
	//playerexplosion.life = 1;
	playerexplosion.anim.loop = false;
	playerexplosion.anim.speed = 0.4f;

	/*
	laser.anim.PushBack({232, 103, 16, 12});
	laser.anim.PushBack({249, 103, 16, 12});
	laser.anim.speed = 0.2f;
	laser.speed.x = 5;
	laser.life = 3000;
	*/
	//

	lascoll.anim.PushBack({ 136, 158, 16, 16 });
	lascoll.anim.PushBack({ 137, 139, 15, 15 });
	lascoll.anim.PushBack({ 83, 161, 16, 15 });
	lascoll.anim.PushBack({ 83, 139, 18, 19 });
	lascoll.anim.loop = false;
	lascoll.anim.speed = 0.25f;
	/*
	lascoll.PushBack({ 136, 137, 18, 18 });
	lascoll.PushBack({ 136, 137, 18, 18 });
	lascoll.loop = false;
	lascoll.speed = 0.05f;*/
	//1st q

	laser0.anim.PushBack({ 17, 146, 4, 16 });
	laser0.anim.speed = 0.2f;
	laser0.speed.y = -10;
	laser0.life = laserlife;

	laser22_5.anim.PushBack({ 199, 162, 9, 16 });
	laser22_5.anim.speed = 0.2f;
	laser22_5.speed.x = 4;
	laser22_5.speed.y = -9;
	laser22_5.life = laserlife;

	laser45.anim.PushBack({ 228, 172, 12, 14 });
	laser45.anim.speed = 0.2f;
	laser45.speed.x = 7;
	laser45.speed.y = -7;
	laser45.life = laserlife;

	laser67_5.anim.PushBack({ 216, 212, 15, 10 });
	laser67_5.anim.speed = 0.2f;
	laser67_5.speed.x = 9;
	laser67_5.speed.y = -4;
	laser67_5.life = laserlife;

	//4st q
	laser90.anim.PushBack({ 219, 243, 16, 4 });
	laser90.anim.speed = 0.2f;
	laser90.speed.x = 10;
	laser90.life = laserlife;

	laser112_5.anim.PushBack({ 156, 194, 16, 10 });
	laser112_5.anim.speed = 0.2f;
	laser112_5.speed.x = 9;
	laser112_5.speed.y = 4;
	laser112_5.life = laserlife;

	laser135.anim.PushBack({ 149, 222, 13, 14 });
	laser135.anim.speed = 0.2f;
	laser135.speed.x = 7;
	laser135.speed.y = 7;
	laser135.life = laserlife;

	laser157_5.anim.PushBack({ 106, 201, 10, 16 });
	laser157_5.anim.speed = 0.2f;
	laser157_5.speed.x = 4;
	laser157_5.speed.y = 9;
	laser157_5.life = laserlife;

	//3st q
	laser180.anim.PushBack({ 79, 207, 4, 16 });
	laser180.anim.speed = 0.2f;
	laser180.speed.y = 10;
	laser180.life = laserlife;

	laser202_5.anim.PushBack({ 15, 205, 9, 16 });
	laser202_5.anim.speed = 0.2f;
	laser202_5.speed.x = -4;
	laser202_5.speed.y = 9;
	laser202_5.life = laserlife;

	laser225.anim.PushBack({ 39, 213, 13, 14 });
	laser225.anim.speed = 0.2f;
	laser225.speed.x = -7;
	laser225.speed.y = 7;
	laser225.life = laserlife;

	laser247_5.anim.PushBack({ 29, 256, 16, 10 });
	laser247_5.anim.speed = 0.2f;
	laser247_5.speed.x = -9;
	laser247_5.speed.y = 4;
	laser247_5.life = laserlife;

	//2st q
	laser270.anim.PushBack({ 28, 289, 15, 4 });
	laser270.anim.speed = 0.2f;
	laser270.speed.x = -10;
	laser270.life = laserlife;

	laser292_5.anim.PushBack({ 85, 272, 16, 10 });
	laser292_5.anim.speed = 0.2f;
	laser292_5.speed.x = -9;
	laser292_5.speed.y = -4;
	laser292_5.life = laserlife;

	laser315.anim.PushBack({ 121, 259, 13, 14 });
	laser315.anim.speed = 0.2f;
	laser315.speed.x = -7;
	laser315.speed.y = -7;
	laser315.life = laserlife;

	laser337_5.anim.PushBack({ 170, 283, 9, 16 });
	laser337_5.anim.speed = 0.2f;
	laser337_5.speed.x = -4;
	laser337_5.speed.y = -9;
	laser337_5.life = laserlife;

	//Weapon shoots
	laserweaponshoot0.anim.PushBack({ 12, 166, 14, 16 });
	laserweaponshoot0.life = weaponshootlife;

	laserweaponshoot22_5.anim.PushBack({ 188, 181, 15, 16 });
	laserweaponshoot22_5.life = weaponshootlife;

	laserweaponshoot45.anim.PushBack({ 212, 187, 14, 14 });
	laserweaponshoot45.life = weaponshootlife;

	laserweaponshoot67_5.anim.PushBack({ 197, 218, 16, 14 });
	laserweaponshoot67_5.life = weaponshootlife;

	laserweaponshoot90.anim.PushBack({ 199, 238, 16, 14 });
	laserweaponshoot90.life = weaponshootlife;

	laserweaponshoot112_5.anim.PushBack({ 137, 184, 16, 14 });
	laserweaponshoot112_5.life = weaponshootlife;

	laserweaponshoot135.anim.PushBack({ 134, 207, 13, 15 });
	laserweaponshoot135.life = weaponshootlife;

	laserweaponshoot157_5.anim.PushBack({ 96, 183, 14, 16 });
	laserweaponshoot157_5.life = weaponshootlife;

	laserweaponshoot180.anim.PushBack({ 74, 187, 14, 16 });
	laserweaponshoot180.life = weaponshootlife;

	laserweaponshoot202_5.anim.PushBack({ 21, 186, 14, 17 });
	laserweaponshoot202_5.life = weaponshootlife;

	laserweaponshoot225.anim.PushBack({ 53, 198, 14, 15 });
	laserweaponshoot225.life = weaponshootlife;

	laserweaponshoot247_5.anim.PushBack({ 47, 245, 16, 15 });
	laserweaponshoot247_5.life = weaponshootlife;

	laserweaponshoot270.anim.PushBack({ 46, 284, 15, 14 });
	laserweaponshoot270.life = weaponshootlife;

	laserweaponshoot292_5.anim.PushBack({ 104, 278, 16, 14 });
	laserweaponshoot292_5.life = weaponshootlife;

	laserweaponshoot315.anim.PushBack({ 136, 273, 13, 16 });
	laserweaponshoot315.life = weaponshootlife;

	laserweaponshoot337_5.anim.PushBack({ 176, 301, 14, 16 });
	laserweaponshoot337_5.life = weaponshootlife;

	enemyshoot.anim.PushBack({ 152, 301, 7, 7 });
	enemyshoot.life = enemyshootlife;

	goahead.anim.PushBack({ 4, 437, 50, 48 });
	goahead.anim.PushBack({ 0, 0, 1, 1 });
	goahead.anim.PushBack({ 4, 437, 50, 48 });
	goahead.anim.PushBack({ 0, 0, 1, 1 });
	goahead.anim.PushBack({ 4, 437, 50, 48 });
	goahead.anim.PushBack({ 0, 0, 1, 1 });
	goahead.anim.PushBack({ 4, 437, 50, 48 });
	goahead.anim.PushBack({ 0, 0, 1, 1 });
	goahead.anim.PushBack({ 4, 437, 50, 48 });
	goahead.anim.PushBack({ 0, 0, 1, 1 });
	goahead.anim.PushBack({ 4, 437, 50, 48 });
	goahead.anim.PushBack({ 0, 0, 1, 1 });
	goahead.anim.speed = 0.2f;
	goahead.anim.loop = true;
	goahead.life = 2000;

}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("Outzone/particlesoutzoneREAL.png");

	// Load particles fx particle
	explosionturret.fx = App->audio->LoadFx("Outzone/outzone_033.wav");
	playerexplosion.fx = App->audio->LoadFx("Outzone/outzone_019.wav");
	laser0.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laser22_5.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laser45.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laser67_5.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laser90.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laser112_5.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laser135.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laser157_5.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laser180.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laser202_5.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laser225.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laser247_5.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laser270.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laser292_5.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laser315.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laser337_5.fx = App->audio->LoadFx("Outzone/outzone_040.wav");

	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	// Unload fx

	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if(p == nullptr)
			continue;

		if(p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if(SDL_GetTicks() >= p->born)
		{
			if (p != nullptr){
				App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
				if (p->fx_played == false)
				{
					p->fx_played = true;
					App->audio->PlayFx(p->fx);
				}
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if (p != nullptr){
				if (collider_type != COLLIDER_NONE)
					p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			}
			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if(active[i] != nullptr && active[i]->collider == c1)
		{
			if (c1->type != COLLIDER_ENEMY_SHOT){
				AddParticle(lascoll4, (active[i]->position.x) - 4, (active[i]->position.y) + 5);
				AddParticle(lascoll3, (active[i]->position.x) - 7, active[i]->position.y);
				AddParticle(lascoll2, (active[i]->position.x) - 7, (active[i]->position.y) - 6);
				AddParticle(lascoll, (active[i]->position.x) - 7, (active[i]->position.y) - 6);
			}
				delete active[i];
				active[i] = nullptr;
				break;
			
		}
	}
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) : 
anim(p.anim), position(p.position), speed(p.speed),
fx(p.fx), born(p.born), life(p.life)
{}

Particle::~Particle()
{
	if(collider != nullptr)
		App->collision->EraseCollider(collider);
}

bool Particle::Update()
{
	bool ret = true;

	if(life > 0)
	{
		if((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if(anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	if(collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}

