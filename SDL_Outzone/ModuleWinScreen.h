#ifndef __MODULEWINSCREEN_H__
#define __MODULEWINSCREEN_H__

#include "Module.h"

struct SDL_Texture;

class ModuleWinScreen : public Module
{
public:
	ModuleWinScreen();
	~ModuleWinScreen();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background = nullptr;
	uint fx = 0;
};

#endif // __MODULEWINSCREEN_H__