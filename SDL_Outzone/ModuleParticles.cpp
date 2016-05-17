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

	explosionturret.anim.PushBack({0, 153, 36, 39});
	explosionturret.anim.PushBack({ 36, 153, 36, 39 });
	explosionturret.anim.PushBack({ 72, 153, 36, 39 });
	explosionturret.anim.PushBack({ 108, 153, 36, 39 });
	explosionturret.anim.PushBack({ 144, 153, 36, 39 });
	explosionturret.anim.PushBack({ 180, 153, 36, 39 });
	explosionturret.anim.PushBack({ 216, 153, 36, 39 });
	explosionturret.anim.loop = false;
	explosionturret.anim.speed = 0.3f;

	playerexplosion.anim.PushBack({ 682, 114, 118, 115 });
	playerexplosion.anim.PushBack({ 448, 228, 118, 115 });
	playerexplosion.anim.PushBack({ 565, 228, 118, 115 });
	playerexplosion.anim.PushBack({ 682, 228, 118, 115 });
	playerexplosion.anim.PushBack({ 448, 0, 118, 115 });
	playerexplosion.anim.PushBack({ 565, 0, 118, 115 });
	playerexplosion.anim.PushBack({ 682, 0, 118, 115 });
	playerexplosion.anim.PushBack({ 448, 114, 118, 115 });
	playerexplosion.anim.PushBack({ 565, 114, 118, 115 });
	playerexplosion.anim.loop = false;
	playerexplosion.anim.speed = 0.4f;

	//Thre shoot aim
	Frontthreeshoot.anim.PushBack({ 58, 63, 6, 14 });
	Frontthreeshoot.anim.speed = 0.2f;
	Frontthreeshoot.speed.y = -10;
	Frontthreeshoot.life = laserlife;

	Rightthreeshoot.anim.PushBack({ 81, 104, 8, 14 });
	Rightthreeshoot.anim.speed = 0.2f;
	Rightthreeshoot.speed.x = 3;
	Rightthreeshoot.speed.y = -9;
	Rightthreeshoot.life = laserlife;

	Leftthreeshoot.anim.PushBack({ 71, 104, 8, 12 });
	Leftthreeshoot.anim.speed = 0.2f;
	Leftthreeshoot.speed.x = -3;
	Leftthreeshoot.speed.y = -9;
	Leftthreeshoot.life = laserlife;

	//colision particle normal weapon
	lascoll.anim.PushBack({ 180, 89, 16, 16 });
	lascoll.anim.PushBack({ 144, 121, 16, 16 });
	lascoll.anim.PushBack({ 142, 104, 16, 16 });
	lascoll.anim.PushBack({ 141, 87, 16, 16 });
	lascoll.anim.loop = false;
	lascoll.anim.speed = 0.25f;

	//colision particle 3shoot weapon
	lascoll2.anim.PushBack({ 180, 107, 16, 16 });
	lascoll2.anim.PushBack({ 161, 121, 16, 16 });
	lascoll2.anim.PushBack({ 160, 103, 16, 16 });
	lascoll2.anim.PushBack({ 161, 87, 16, 16 });
	lascoll2.anim.loop = false;
	lascoll2.anim.speed = 0.25f;

	//Normal weapon
	//1st q
	laser0.anim.PushBack({ 26, 87, 4, 16 });
	laser0.anim.speed = 0.2f;
	laser0.speed.y = -10;
	laser0.life = laserlife;

	laser22_5.anim.PushBack({ 96, 103, 9, 15 });
	laser22_5.anim.speed = 0.2f;
	laser22_5.speed.x = 4;
	laser22_5.speed.y = -9;
	laser22_5.life = laserlife;

	laser45.anim.PushBack({ 96, 87, 12, 13 });
	laser45.anim.speed = 0.2f;
	laser45.speed.x = 7;
	laser45.speed.y = -7;
	laser45.life = laserlife;

	laser67_5.anim.PushBack({ 90, 120, 15, 8 });
	laser67_5.anim.speed = 0.2f;
	laser67_5.speed.x = 9;
	laser67_5.speed.y = -4;
	laser67_5.life = laserlife;

	//4st q
	laser90.anim.PushBack({ 89, 138, 16, 4 });
	laser90.anim.speed = 0.2f;
	laser90.speed.x = 10;
	laser90.life = laserlife;

	laser112_5.anim.PushBack({ 125, 123, 15, 8 });
	laser112_5.anim.speed = 0.2f;
	laser112_5.speed.x = 9;
	laser112_5.speed.y = 4;
	laser112_5.life = laserlife;

	laser135.anim.PushBack({ 75, 118, 12, 13 });
	laser135.anim.speed = 0.2f;
	laser135.speed.x = 7;
	laser135.speed.y = 7;
	laser135.life = laserlife;

	laser157_5.anim.PushBack({ 127, 86, 8, 16 });
	laser157_5.anim.speed = 0.2f;
	laser157_5.speed.x = 4;
	laser157_5.speed.y = 9;
	laser157_5.life = laserlife;

	//3st q
	laser180.anim.PushBack({ 26, 87, 4, 16 });
	laser180.anim.speed = 0.2f;
	laser180.speed.y = 10;
	laser180.life = laserlife;

	laser202_5.anim.PushBack({ 96, 103, 9, 15 });
	laser202_5.anim.speed = 0.2f;
	laser202_5.speed.x = -4;
	laser202_5.speed.y = 9;
	laser202_5.life = laserlife;

	laser225.anim.PushBack({ 96, 87, 12, 13 });
	laser225.anim.speed = 0.2f;
	laser225.speed.x = -7;
	laser225.speed.y = 7;
	laser225.life = laserlife;

	laser247_5.anim.PushBack({ 90, 120, 15, 8 });
	laser247_5.anim.speed = 0.2f;
	laser247_5.speed.x = -9;
	laser247_5.speed.y = 4;
	laser247_5.life = laserlife;

	//2st q
	laser270.anim.PushBack({ 89, 138, 16, 4 });
	laser270.anim.speed = 0.2f;
	laser270.speed.x = -10;
	laser270.life = laserlife;

	laser292_5.anim.PushBack({ 125, 123, 15, 8 });
	laser292_5.anim.speed = 0.2f;
	laser292_5.speed.x = -9;
	laser292_5.speed.y = -4;
	laser292_5.life = laserlife;

	laser315.anim.PushBack({ 75, 118, 12, 13 });
	laser315.anim.speed = 0.2f;
	laser315.speed.x = -7;
	laser315.speed.y = -7;
	laser315.life = laserlife;

	laser337_5.anim.PushBack({ 127, 86, 8, 16 });
	laser337_5.anim.speed = 0.2f;
	laser337_5.speed.x = -4;
	laser337_5.speed.y = -9;
	laser337_5.life = laserlife;

	//3shoot weapon
	//1st q
	poweredlaser0.anim.PushBack({ 15, 87, 10, 16 });
	poweredlaser0.anim.speed = 0.2f;
	poweredlaser0.speed.y = -10;
	poweredlaser0.life = laserlife;

	poweredlaser22_5.anim.PushBack({ 108, 103, 13, 17 });
	poweredlaser22_5.anim.speed = 0.2f;
	poweredlaser22_5.speed.x = 4;
	poweredlaser22_5.speed.y = -9;
	poweredlaser22_5.life = laserlife;

	poweredlaser45.anim.PushBack({ 108, 87, 15, 16 });
	poweredlaser45.anim.speed = 0.2f;
	poweredlaser45.speed.x = 7;
	poweredlaser45.speed.y = -7;
	poweredlaser45.life = laserlife;

	poweredlaser67_5.anim.PushBack({ 108, 120, 16, 14 });
	poweredlaser67_5.anim.speed = 0.2f;
	poweredlaser67_5.speed.x = 9;
	poweredlaser67_5.speed.y = -4;
	poweredlaser67_5.life = laserlife;

	//4st q
	poweredlaser90.anim.PushBack({ 108, 135, 16, 10 });
	poweredlaser90.anim.speed = 0.2f;
	poweredlaser90.speed.x = 10;
	poweredlaser90.life = laserlife;

	poweredlaser112_5.anim.PushBack({ 124, 134, 16, 14 });
	poweredlaser112_5.anim.speed = 0.2f;
	poweredlaser112_5.speed.x = 9;
	poweredlaser112_5.speed.y = 4;
	poweredlaser112_5.life = laserlife;

	poweredlaser135.anim.PushBack({ 72, 132, 15, 15 });
	poweredlaser135.anim.speed = 0.2f;
	poweredlaser135.speed.x = 7;
	poweredlaser135.speed.y = 7;
	poweredlaser135.life = laserlife;

	poweredlaser157_5.anim.PushBack({ 125, 103, 14, 17 });
	poweredlaser157_5.anim.speed = 0.2f;
	poweredlaser157_5.speed.x = 4;
	poweredlaser157_5.speed.y = 9;
	poweredlaser157_5.life = laserlife;

	//3st q
	poweredlaser180.anim.PushBack({ 15, 87, 10, 16 });
	poweredlaser180.anim.speed = 0.2f;
	poweredlaser180.speed.y = 10;
	poweredlaser180.life = laserlife;

	poweredlaser202_5.anim.PushBack({ 108, 103, 13, 17 });
	poweredlaser202_5.anim.speed = 0.2f;
	poweredlaser202_5.speed.x = -4;
	poweredlaser202_5.speed.y = 9;
	poweredlaser202_5.life = laserlife;

	poweredlaser225.anim.PushBack({ 108, 87, 15, 16 });
	poweredlaser225.anim.speed = 0.2f;
	poweredlaser225.speed.x = -7;
	poweredlaser225.speed.y = 7;
	poweredlaser225.life = laserlife;

	poweredlaser247_5.anim.PushBack({ 108, 120, 16, 14 });
	poweredlaser247_5.anim.speed = 0.2f;
	poweredlaser247_5.speed.x = -9;
	poweredlaser247_5.speed.y = 4;
	poweredlaser247_5.life = laserlife;

	//2st q
	poweredlaser270.anim.PushBack({ 108, 135, 16, 10 });
	poweredlaser270.anim.speed = 0.2f;
	poweredlaser270.speed.x = -10;
	poweredlaser270.life = laserlife;

	poweredlaser292_5.anim.PushBack({ 124, 134, 16, 14 });
	poweredlaser292_5.anim.speed = 0.2f;
	poweredlaser292_5.speed.x = -9;
	poweredlaser292_5.speed.y = -4;
	poweredlaser292_5.life = laserlife;

	poweredlaser315.anim.PushBack({ 72, 132, 15, 15 });
	poweredlaser315.anim.speed = 0.2f;
	poweredlaser315.speed.x = -7;
	poweredlaser315.speed.y = -7;
	poweredlaser315.life = laserlife;

	poweredlaser337_5.anim.PushBack({ 125, 103, 14, 17 });
	poweredlaser337_5.anim.speed = 0.2f;
	poweredlaser337_5.speed.x = -4;
	poweredlaser337_5.speed.y = -9;
	poweredlaser337_5.life = laserlife;

	//laserball
	laserball.anim.PushBack({ 0, 63, 24, 24 });
	laserball.anim.speed = 0.2f;
	laserball.speed.x = 0;
	laserball.speed.y = 0;
	laserball.life = laserlife;

	//Weapon shoots
	laserweaponshoot0.anim.PushBack({ 0, 87, 14, 16 });
	laserweaponshoot0.life = weaponshootlife;

	laserweaponshoot22_5.anim.PushBack({ 59, 118, 13, 15 });
	laserweaponshoot22_5.life = weaponshootlife;

	laserweaponshoot45.anim.PushBack({ 16, 134, 14, 14 });
	laserweaponshoot45.life = weaponshootlife;

	laserweaponshoot67_5.anim.PushBack({ 0, 134, 16, 13 });
	laserweaponshoot67_5.life = weaponshootlife;

	laserweaponshoot90.anim.PushBack({ 0, 118, 16, 14 });
	laserweaponshoot90.life = weaponshootlife;

	laserweaponshoot112_5.anim.PushBack({ 30, 133, 14, 14 });
	laserweaponshoot112_5.life = weaponshootlife;

	laserweaponshoot135.anim.PushBack({ 44, 134, 13, 14 });
	laserweaponshoot135.life = weaponshootlife;

	laserweaponshoot157_5.anim.PushBack({ 30, 118, 14, 15 });
	laserweaponshoot157_5.life = weaponshootlife;

	laserweaponshoot180.anim.PushBack({ 16, 118, 14, 16 });
	laserweaponshoot180.life = weaponshootlife;

	laserweaponshoot202_5.anim.PushBack({ 0, 103, 14, 15 });
	laserweaponshoot202_5.life = weaponshootlife;

	laserweaponshoot225.anim.PushBack({ 14, 103, 13, 13 });
	laserweaponshoot225.life = weaponshootlife;

	laserweaponshoot247_5.anim.PushBack({ 27, 103, 15, 14 });
	laserweaponshoot247_5.life = weaponshootlife;

	laserweaponshoot270.anim.PushBack({ 42, 103, 14, 14 });
	laserweaponshoot270.life = weaponshootlife;

	laserweaponshoot292_5.anim.PushBack({ 44, 118, 15, 14 });
	laserweaponshoot292_5.life = weaponshootlife;

	laserweaponshoot315.anim.PushBack({ 56, 103, 13, 14 });
	laserweaponshoot315.life = weaponshootlife;

	laserweaponshoot337_5.anim.PushBack({ 57, 133, 14, 15 });
	laserweaponshoot337_5.life = weaponshootlife;

	enemyshoot.anim.PushBack({ 282, 36, 6, 6 });
	enemyshoot.life = enemyshootlife;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("Outzone/particle.png");

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
				if (App->player->changetaim == false){
					AddParticle(lascoll, (active[i]->position.x) - 7, (active[i]->position.y) - 6);
				}
				else{
					AddParticle(lascoll2, (active[i]->position.x) - 7, (active[i]->position.y) - 6);
				}
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

