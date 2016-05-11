#ifndef __MODULESCENESPACEUPPER_H__
#define __MODULESCENESPACEUPPER_H__

#include "Module.h"

struct SDL_Texture;

class ModuleSceneSpaceUpper : public Module
{
public:
	ModuleSceneSpaceUpper();
	~ModuleSceneSpaceUpper();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	bool firstimeblit = true;
	SDL_Texture* background = nullptr;
	SDL_Texture* stars = nullptr;
};

#endif // __MODULESCENESPACEUPPER_H__