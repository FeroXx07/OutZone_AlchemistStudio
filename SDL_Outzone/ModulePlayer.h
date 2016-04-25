#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);
	enum LAST_KEY
	{
		NO_KEY_PRESSED = 0,
		LAST_KEY_W,
		LAST_KEY_WD,
		LAST_KEY_WA,
		LAST_KEY_A,
		LAST_KEY_S,
		LAST_KEY_SA,
		LAST_KEY_SD,
		LAST_KEY_D
	};

public:
	LAST_KEY lastkeypressed = LAST_KEY::NO_KEY_PRESSED;
	SDL_Texture* graphics = nullptr;
	Animation* current_animation = nullptr;
	Animation idle;
	Animation up;
	Animation down;
	Animation left;
	Animation right;
	Animation Drightop;
	Animation Lefthtop;
	Animation Drighbot;
	Animation Lefthbot;
	iPoint position;

	Animation idle_w;
	Animation idle_wa;
	Animation idle_wd;
	Animation idle_a;
	Animation idle_s;
	Animation idle_sa;
	Animation idle_sd;
	Animation idle_d;
	Collider* col;
	bool destroyed = false;
};

#endif