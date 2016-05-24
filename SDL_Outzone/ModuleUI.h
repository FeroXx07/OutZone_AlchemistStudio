#ifndef __MODULEUUI_H__
#define __MODULEUUI_H__

#include "Module.h"

struct SDL_Texture;

class ModuleUI : public Module
{
public:
	ModuleUI();
	~ModuleUI();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	bool firstimeblit = true;
	SDL_Texture* background = nullptr;
	SDL_Texture* stars = nullptr;
	Animation* effect1 = nullptr;
	Animation* effect2 = nullptr;
	Animation UI;
	Animation UI2;
};

#endif // __MODULESCENESPACEUPPER_H__