#ifndef __MODULESCENELVL1_H__
#define __MODULESCENELVL1_H__

#include "Module.h"

struct SDL_Texture;

class ModuleSceneLvl1 : public Module
{
public:
	ModuleSceneLvl1();
	~ModuleSceneLvl1();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	SDL_Texture* background = nullptr;
	SDL_Texture* stars = nullptr;
	SDL_Rect back;
};

#endif // __MODULESCENELVL1_H__