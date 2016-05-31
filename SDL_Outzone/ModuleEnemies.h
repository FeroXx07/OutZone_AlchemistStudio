#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"
#include "Enemy_RedBird.h"

#define MAX_ENEMIES 200

// TODO 2: Add a new enemy: Brown Cookies!

// TODO 3: Have the Brown Cookies describe a path in the screen

// TODO 4: Create a new enemy type: the Mech

enum ENEMY_TYPES
{
	NO_TYPE,
	REDBIRD,
	BROWCOOKIES,
	TANK,
	TURRET1,
	TURRET2,
	GREYROBOT,
	REDMACHINE,
	BLUEMACHINE,
	ORANGEROBOT,
	PURPLEMACHINE,
	TURRET3,
	CHANGEAIM,
	ENEMYCHARGE,
	ROOLLINGROBOT,
	GREYDOOR,
	BOSS,
	BOSSAIM,
	EYEBOSS,
	GREENROBOT,
	BOX,
	BOXENERGY,
	SPSPEED,
	BIGREDMACHINE,
	MAZURKA,
	DOOR,
};

class Enemy;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	int x, y;
};

class ModuleEnemies : public Module
{
public:

	ModuleEnemies();
	~ModuleEnemies();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	bool AddEnemy(ENEMY_TYPES type, int x, int y);

private:

	void SpawnEnemy(const EnemyInfo& info);

private:

	EnemyInfo queue[MAX_ENEMIES];
	Enemy* enemies[MAX_ENEMIES];
	SDL_Texture* sprites;

public:
	unsigned int enemycount = 0;
	unsigned int pointscount = 0;
	unsigned int maxpointsearned = 0;
	bool onprobot = false;
	bool onprobot2 = false;
	int bosseyehits = 0;
	int bossweaponhits = 0;

	int bigredmachinehits = 0;
	int bluemachinehits = 0;
	int redmachinehits = 0;
	int orangerobothits = 0;
	int turret1hits = 0;
	int turret3hits = 0;
	int rollingrobothits = 0;
};

#endif // __ModuleEnemies_H__