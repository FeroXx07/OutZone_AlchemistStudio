#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

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

enum BEFORE_LAST_KEY
{
	NO_KEY_PRESSED_BEFORE = 0,
	BEFORE_LAST_KEY_KEY_W,
	BEFORE_LAST_KEY_WD,
	BEFORE_LAST_KEY_WA,
	BEFORE_LAST_KEY_A,
	BEFORE_LAST_KEY_S,
	BEFORE_LAST_KEY_SA,
	BEFORE_LAST_KEY_SD,
	BEFORE_LAST_KEY_D
};

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	unsigned int playerinitialtime = 0;
	unsigned int playertime = 0;
	unsigned int playercurrenttime = 0;
	unsigned int playeractiontime = 0;
	unsigned int shootcurrenttime = 0;
	unsigned int shootactiontime = 0;
	unsigned int godcurrenttime = 0;
	unsigned int godactiontime = 0;
	bool Start();
	bool Invencible = false;
	bool Superspeed = false;
	bool Fly = false;
	bool Immobile = false;
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

public:

	LAST_KEY lastkeypressed = LAST_KEY::LAST_KEY_W;
	BEFORE_LAST_KEY beforelastkeypressed = BEFORE_LAST_KEY::BEFORE_LAST_KEY_KEY_W;

public:

	SDL_Texture* graphics = nullptr;
	Animation* current_animation = nullptr;

	Animation fall;

	Animation idle_w;
	Animation idle_wa;
	Animation idle_wd;
	Animation idle_a;
	Animation idle_s;
	Animation idle_sa;
	Animation idle_sd;
	Animation idle_d;

	Animation up;
	Animation down;
	Animation left;
	Animation right;
	Animation Drightop;
	Animation Lefthtop;
	Animation Drighbot;
	Animation Lefthbot;
	iPoint position;
	iPoint PreviousPos;
	Collider* playercollision;
	bool destroyed = false;
	bool collisionWallS = false;
	bool collisionWallT = false;
	bool collisionPrint = false;
};

#endif