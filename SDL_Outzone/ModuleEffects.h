#ifndef __ModuleEffects_H__
#define __ModuleEffects_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class ModuleEffects : public Module
{
public:
	ModuleEffects();
	~ModuleEffects();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	bool bombactive = false;
	bool goaheadfirstloop = true;
	unsigned int godcurrenttime = 0;
	unsigned int godactiontime = 0;
	unsigned int bombcurrenttime = 0;
	unsigned int bombactiontime = 0;
	unsigned int goaheadcurrenttime = 0;
	unsigned int goaheadactiontime = 0;

	SDL_Texture* graphics = nullptr;
	Animation* effect1 = nullptr;
	Animation* effect2 = nullptr;
	Collider* effect2collider;
	bool effect2collidercreated = false;
	Animation* effect3 = nullptr;

	Animation god;
	Animation lascoll;
	Animation bomb;
	Animation goahead;

	iPoint position;
};

#endif