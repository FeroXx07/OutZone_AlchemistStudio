#ifndef __MODULESCENE1_H__
#define __MODULESCENE1_H__

#include "Module.h"

struct SDL_Texture;

class ModuleScene1 : public Module
{
public:
	ModuleScene1();
	~ModuleScene1();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background = nullptr;
	SDL_Texture* stars = nullptr;
	SDL_Rect back;
};

#endif // __MODULESCENE1_H__