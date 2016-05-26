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

#define laser0uplife 600
#define laser1uplife 600
#define laser2uplife 600

#define trilaser0uplife 600
#define trilaser1uplife 600
#define trilaser2uplife 600

#define enemyshootlife 2000

#define laser0upspeed 10
#define laser1upspeed 10
#define laser2upspeed 10

#define trilaser0upspeed 10
#define trilaser1upspeed 10
#define trilaser2upspeed 10

#define PI 3.14159265
#define ANGLE_CONVERT_REVERSE (PI / 180.0)

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

	soldierexplosion.anim.PushBack({ 0, 192, 36, 39 });
	soldierexplosion.anim.PushBack({ 36, 192, 36, 39 });
	soldierexplosion.anim.PushBack({ 72, 192, 36, 39 });
	soldierexplosion.anim.PushBack({ 108, 192, 36, 39 });
	soldierexplosion.anim.PushBack({ 144, 192, 36, 39 });
	soldierexplosion.anim.PushBack({ 180, 192, 36, 39 });
	soldierexplosion.anim.PushBack({ 216, 192, 36, 39 });
	soldierexplosion.anim.loop = false;
	soldierexplosion.anim.speed = 0.3f;

	tankexplosion.anim.PushBack({ 802, 11, 68, 68 });
	tankexplosion.anim.PushBack({ 873, 11, 65, 68 });
	tankexplosion.anim.PushBack({ 939, 11, 68, 68 });
	tankexplosion.anim.PushBack({ 1008, 11, 68, 68 });
	tankexplosion.anim.PushBack({ 1008, 80, 68, 68 });
	tankexplosion.anim.PushBack({ 939, 80, 68, 68 });
	tankexplosion.anim.PushBack({ 873, 80, 68, 68 });
	tankexplosion.anim.PushBack({ 802, 80, 68, 68 });
	tankexplosion.anim.PushBack({ 1143, 11, 68, 68 });
	tankexplosion.anim.PushBack({ 1075, 11, 68, 68 });
	tankexplosion.anim.loop = false;
	tankexplosion.anim.speed = 0.3f;

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
	//0powerup
	Frontthreeshoot.anim.PushBack({ 58, 63, 6, 14 });
	Frontthreeshoot.anim.speed = 0.2f;
	Frontthreeshoot.speed.y = -trilaser0upspeed;
	Frontthreeshoot.life = trilaser0uplife;

	Rightthreeshoot.anim.PushBack({ 81, 104, 8, 14 });
	Rightthreeshoot.anim.speed = 0.2f;
	Rightthreeshoot.speed.x = (trilaser0upspeed * cos(70 * ANGLE_CONVERT_REVERSE));
	Rightthreeshoot.speed.y = -(trilaser0upspeed * sin(70 * ANGLE_CONVERT_REVERSE));
	Rightthreeshoot.life = trilaser0uplife;

	Leftthreeshoot.anim.PushBack({ 71, 104, 8, 12 });
	Leftthreeshoot.anim.speed = 0.2f;
	Leftthreeshoot.speed.x = -(trilaser0upspeed * cos(70 * ANGLE_CONVERT_REVERSE));
	Leftthreeshoot.speed.y = -(trilaser0upspeed * sin(70 * ANGLE_CONVERT_REVERSE));
	Leftthreeshoot.life = trilaser0uplife;

	//1powerup
	Frontthreeshootonepowerup.anim.PushBack({ 47, 63, 10, 18 });
	Frontthreeshootonepowerup.anim.speed = 0.2f;
	Frontthreeshootonepowerup.speed.y = -trilaser1upspeed;
	Frontthreeshootonepowerup.life = trilaser1uplife;

	Rightthreeshootonepowerup.anim.PushBack({ 81, 85, 11, 17 });
	Rightthreeshootonepowerup.anim.speed = 0.2f;
	Rightthreeshootonepowerup.speed.x = (trilaser1upspeed * cos(70 * ANGLE_CONVERT_REVERSE));
	Rightthreeshootonepowerup.speed.y = -(trilaser1upspeed * sin(70 * ANGLE_CONVERT_REVERSE));
	Rightthreeshootonepowerup.life = trilaser1uplife;

	Leftthreeshootonepowerup.anim.PushBack({ 69, 85, 10, 17 });
	Leftthreeshootonepowerup.anim.speed = 0.2f;
	Leftthreeshootonepowerup.speed.x = -(trilaser1upspeed * cos(70 * ANGLE_CONVERT_REVERSE));
	Leftthreeshootonepowerup.speed.y = -(trilaser1upspeed * sin(70 * ANGLE_CONVERT_REVERSE));
	Leftthreeshootonepowerup.life = trilaser1uplife;

	//2powerup
	Frontthreeshoottwopowerup.anim.PushBack({ 32, 63, 14, 23 });
	Frontthreeshoottwopowerup.anim.speed = 0.2f;
	Frontthreeshoottwopowerup.speed.y = -trilaser2upspeed;
	Frontthreeshoottwopowerup.life = trilaser2uplife;

	Rightthreeshoottwopowerup.anim.PushBack({ 80, 63, 15, 22 });
	Rightthreeshoottwopowerup.anim.speed = 0.2f;
	Rightthreeshoottwopowerup.speed.x = (trilaser2upspeed * cos(70 * ANGLE_CONVERT_REVERSE));
	Rightthreeshoottwopowerup.speed.y = -(trilaser2upspeed * sin(70 * ANGLE_CONVERT_REVERSE));
	Rightthreeshoottwopowerup.life = trilaser2uplife;

	Leftthreeshoottwopowerup.anim.PushBack({ 65, 63, 15, 22 });
	Leftthreeshoottwopowerup.anim.speed = 0.2f;
	Leftthreeshoottwopowerup.speed.x = -(trilaser2upspeed * cos(70 * ANGLE_CONVERT_REVERSE));
	Leftthreeshoottwopowerup.speed.y = -(trilaser2upspeed * sin(70 * ANGLE_CONVERT_REVERSE));
	Leftthreeshoottwopowerup.life = trilaser2uplife;

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

	//TRILASER

	trilaser.anim.PushBack({ 32, 86, 36, 17 });
	trilaser.anim.speed = 0.2f;
	trilaser.life = weaponshootlife;

	//Normal weapon
	//1st q
	laser0.anim.PushBack({ 26, 87, 4, 16 });
	laser0.anim.speed = 0.2f;
	laser0.speed.y = -laser0upspeed;
	laser0.life = laser0uplife;

	laser22_5.anim.PushBack({ 96, 103, 9, 15 });
	laser22_5.anim.speed = 0.2f;
	laser22_5.speed.x = (laser0upspeed * cos(22.5 * ANGLE_CONVERT_REVERSE));
	laser22_5.speed.y = -(laser0upspeed * sin(22.5 * ANGLE_CONVERT_REVERSE));
	laser22_5.life = laser0uplife;

	laser45.anim.PushBack({ 96, 87, 12, 13 });
	laser45.anim.speed = 0.2f;
	laser45.speed.x = (laser0upspeed * cos(45 * ANGLE_CONVERT_REVERSE));
	laser45.speed.y = -(laser0upspeed * sin(45 * ANGLE_CONVERT_REVERSE));
	laser45.life = laser0uplife;

	laser67_5.anim.PushBack({ 90, 120, 15, 8 });
	laser67_5.anim.speed = 0.2f;
	laser67_5.speed.x = (laser0upspeed * cos(67.5 * ANGLE_CONVERT_REVERSE));
	laser67_5.speed.y = -(laser0upspeed * sin(67.5 * ANGLE_CONVERT_REVERSE));
	laser67_5.life = laser0uplife;

	//4st q
	laser90.anim.PushBack({ 89, 138, 16, 4 });
	laser90.anim.speed = 0.2f;
	laser90.speed.x = laser0upspeed;
	laser90.life = laser0uplife;

	laser112_5.anim.PushBack({ 125, 123, 15, 8 });
	laser112_5.anim.speed = 0.2f;
	laser112_5.speed.x = (laser0upspeed * cos(112.5 * ANGLE_CONVERT_REVERSE));
	laser112_5.speed.y = (laser0upspeed * sin(112.5 * ANGLE_CONVERT_REVERSE));
	laser112_5.life = laser0uplife;

	laser135.anim.PushBack({ 75, 118, 12, 13 });
	laser135.anim.speed = 0.2f;
	laser135.speed.x = (laser0upspeed * cos(135 * ANGLE_CONVERT_REVERSE));
	laser135.speed.y = (laser0upspeed * sin(135 * ANGLE_CONVERT_REVERSE));
	laser135.life = laser0uplife;

	laser157_5.anim.PushBack({ 127, 86, 8, 16 });
	laser157_5.anim.speed = 0.2f;
	laser157_5.speed.x = (laser0upspeed * cos(157.5 * ANGLE_CONVERT_REVERSE));
	laser157_5.speed.y = (laser0upspeed * sin(157.5 * ANGLE_CONVERT_REVERSE));
	laser157_5.life = laser0uplife;

	//3st q
	laser180.anim.PushBack({ 26, 87, 4, 16 });
	laser180.anim.speed = 0.2f;
	laser180.speed.y = laser0upspeed;
	laser180.life = laser0uplife;

	laser202_5.anim.PushBack({ 96, 103, 9, 15 });
	laser202_5.anim.speed = 0.2f;
	laser202_5.speed.x = -(laser0upspeed * cos(202.5 * ANGLE_CONVERT_REVERSE));
	laser202_5.speed.y = (laser0upspeed * sin(202.5 * ANGLE_CONVERT_REVERSE));
	laser202_5.life = laser0uplife;

	laser225.anim.PushBack({ 96, 87, 12, 13 });
	laser225.anim.speed = 0.2f;
	laser225.speed.x = -(laser0upspeed * cos(225 * ANGLE_CONVERT_REVERSE));
	laser225.speed.y = (laser0upspeed * sin(225 * ANGLE_CONVERT_REVERSE));
	laser225.life = laser0uplife;

	laser247_5.anim.PushBack({ 90, 120, 15, 8 });
	laser247_5.anim.speed = 0.2f;
	laser247_5.speed.x = -(laser0upspeed * cos(247.5 * ANGLE_CONVERT_REVERSE));
	laser247_5.speed.y = (laser0upspeed * sin(247.5 * ANGLE_CONVERT_REVERSE));
	laser247_5.life = laser0uplife;

	//2st q
	laser270.anim.PushBack({ 89, 138, 16, 4 });
	laser270.anim.speed = 0.2f;
	laser270.speed.x = -laser0upspeed;
	laser270.life = laser0uplife;

	laser292_5.anim.PushBack({ 125, 123, 15, 8 });
	laser292_5.anim.speed = 0.2f;
	laser292_5.speed.x = -(laser0upspeed * cos(292.5 * ANGLE_CONVERT_REVERSE));
	laser292_5.speed.y = -(laser0upspeed * sin(292.5 * ANGLE_CONVERT_REVERSE));
	laser292_5.life = laser0uplife;

	laser315.anim.PushBack({ 75, 118, 12, 13 });
	laser315.anim.speed = 0.2f;
	laser315.speed.x = -(laser0upspeed * cos(315 * ANGLE_CONVERT_REVERSE));
	laser315.speed.y = -(laser0upspeed * sin(315 * ANGLE_CONVERT_REVERSE));
	laser315.life = laser0uplife;

	laser337_5.anim.PushBack({ 127, 86, 8, 16 });
	laser337_5.anim.speed = 0.2f;
	laser337_5.speed.x = -(laser0upspeed * cos(337.5 * ANGLE_CONVERT_REVERSE));
	laser337_5.speed.y = -(laser0upspeed * sin(337.5 * ANGLE_CONVERT_REVERSE));
	laser337_5.life = laser0uplife;

	//1shoot weapon 1 up
	//1st q
	poweredlaser0.anim.PushBack({ 15, 87, 10, 16 });
	poweredlaser0.anim.speed = 0.2f;
	poweredlaser0.speed.y = -10;
	poweredlaser0.life = laser1uplife;

	poweredlaser22_5.anim.PushBack({ 108, 103, 13, 17 });
	poweredlaser22_5.anim.speed = 0.2f;
	poweredlaser22_5.speed.x = 4;
	poweredlaser22_5.speed.y = -9;
	poweredlaser22_5.life = laser1uplife;

	poweredlaser45.anim.PushBack({ 108, 87, 15, 16 });
	poweredlaser45.anim.speed = 0.2f;
	poweredlaser45.speed.x = 7;
	poweredlaser45.speed.y = -7;
	poweredlaser45.life = laser1uplife;

	poweredlaser67_5.anim.PushBack({ 108, 120, 16, 14 });
	poweredlaser67_5.anim.speed = 0.2f;
	poweredlaser67_5.speed.x = 9;
	poweredlaser67_5.speed.y = -4;
	poweredlaser67_5.life = laser1uplife;

	//4st q
	poweredlaser90.anim.PushBack({ 108, 135, 16, 10 });
	poweredlaser90.anim.speed = 0.2f;
	poweredlaser90.speed.x = 10;
	poweredlaser90.life = laser1uplife;

	poweredlaser112_5.anim.PushBack({ 124, 134, 16, 14 });
	poweredlaser112_5.anim.speed = 0.2f;
	poweredlaser112_5.speed.x = 9;
	poweredlaser112_5.speed.y = 4;
	poweredlaser112_5.life = laser1uplife;

	poweredlaser135.anim.PushBack({ 72, 132, 15, 15 });
	poweredlaser135.anim.speed = 0.2f;
	poweredlaser135.speed.x = 7;
	poweredlaser135.speed.y = 7;
	poweredlaser135.life = laser1uplife;

	poweredlaser157_5.anim.PushBack({ 125, 103, 14, 17 });
	poweredlaser157_5.anim.speed = 0.2f;
	poweredlaser157_5.speed.x = 4;
	poweredlaser157_5.speed.y = 9;
	poweredlaser157_5.life = laser1uplife;

	//3st q
	poweredlaser180.anim.PushBack({ 15, 87, 10, 16 });
	poweredlaser180.anim.speed = 0.2f;
	poweredlaser180.speed.y = 10;
	poweredlaser180.life = laser1uplife;

	poweredlaser202_5.anim.PushBack({ 108, 103, 13, 17 });
	poweredlaser202_5.anim.speed = 0.2f;
	poweredlaser202_5.speed.x = -4;
	poweredlaser202_5.speed.y = 9;
	poweredlaser202_5.life = laser1uplife;

	poweredlaser225.anim.PushBack({ 108, 87, 15, 16 });
	poweredlaser225.anim.speed = 0.2f;
	poweredlaser225.speed.x = -7;
	poweredlaser225.speed.y = 7;
	poweredlaser225.life = laser1uplife;

	poweredlaser247_5.anim.PushBack({ 108, 120, 16, 14 });
	poweredlaser247_5.anim.speed = 0.2f;
	poweredlaser247_5.speed.x = -9;
	poweredlaser247_5.speed.y = 4;
	poweredlaser247_5.life = laser1uplife;

	//2st q
	poweredlaser270.anim.PushBack({ 108, 135, 16, 10 });
	poweredlaser270.anim.speed = 0.2f;
	poweredlaser270.speed.x = -10;
	poweredlaser270.life = laser1uplife;

	poweredlaser292_5.anim.PushBack({ 124, 134, 16, 14 });
	poweredlaser292_5.anim.speed = 0.2f;
	poweredlaser292_5.speed.x = -9;
	poweredlaser292_5.speed.y = -4;
	poweredlaser292_5.life = laser1uplife;

	poweredlaser315.anim.PushBack({ 72, 132, 15, 15 });
	poweredlaser315.anim.speed = 0.2f;
	poweredlaser315.speed.x = -7;
	poweredlaser315.speed.y = -7;
	poweredlaser315.life = laser1uplife;

	poweredlaser337_5.anim.PushBack({ 125, 103, 14, 17 });
	poweredlaser337_5.anim.speed = 0.2f;
	poweredlaser337_5.speed.x = -4;
	poweredlaser337_5.speed.y = -9;
	poweredlaser337_5.life = laser1uplife;

	//1shoot weapon 2 up
	//1st q
	balllaser0.anim.PushBack({ 0, 63, 24, 24 });
	balllaser0.anim.speed = 0.2f;
	balllaser0.speed.y = -10;
	balllaser0.life = laser2uplife;

	balllaser22_5.anim.PushBack({ 0, 63, 24, 24 });
	balllaser22_5.anim.speed = 0.2f;
	balllaser22_5.speed.x = 4;
	balllaser22_5.speed.y = -9;
	balllaser22_5.life = laser2uplife;

	balllaser45.anim.PushBack({ 0, 63, 24, 24 });
	balllaser45.anim.speed = 0.2f;
	balllaser45.speed.x = 7;
	balllaser45.speed.y = -7;
	balllaser45.life = laser2uplife;

	balllaser67_5.anim.PushBack({ 0, 63, 24, 24 });
	balllaser67_5.anim.speed = 0.2f;
	balllaser67_5.speed.x = 9;
	balllaser67_5.speed.y = -4;
	balllaser67_5.life = laser2uplife;

	//4st q
	balllaser90.anim.PushBack({ 0, 63, 24, 24 });
	balllaser90.anim.speed = 0.2f;
	balllaser90.speed.x = 10;
	balllaser90.life = laser2uplife;

	balllaser112_5.anim.PushBack({ 0, 63, 24, 24 });
	balllaser112_5.anim.speed = 0.2f;
	balllaser112_5.speed.x = 9;
	balllaser112_5.speed.y = 4;
	balllaser112_5.life = laser2uplife;

	balllaser135.anim.PushBack({ 0, 63, 24, 24 });
	balllaser135.anim.speed = 0.2f;
	balllaser135.speed.x = 7;
	balllaser135.speed.y = 7;
	balllaser135.life = laser2uplife;

	balllaser157_5.anim.PushBack({ 0, 63, 24, 24 });
	balllaser157_5.anim.speed = 0.2f;
	balllaser157_5.speed.x = 4;
	balllaser157_5.speed.y = 9;
	balllaser157_5.life = laser2uplife;

	//3st q
	balllaser180.anim.PushBack({ 0, 63, 24, 24 });
	balllaser180.anim.speed = 0.2f;
	balllaser180.speed.y = 10;
	balllaser180.life = laser2uplife;

	balllaser202_5.anim.PushBack({ 0, 63, 24, 24 });
	balllaser202_5.anim.speed = 0.2f;
	balllaser202_5.speed.x = -4;
	balllaser202_5.speed.y = 9;
	balllaser202_5.life = laser2uplife;

	balllaser225.anim.PushBack({ 0, 63, 24, 24 });
	balllaser225.anim.speed = 0.2f;
	balllaser225.speed.x = -7;
	balllaser225.speed.y = 7;
	balllaser225.life = laser2uplife;

	balllaser247_5.anim.PushBack({ 0, 63, 24, 24 });
	balllaser247_5.anim.speed = 0.2f;
	balllaser247_5.speed.x = -9;
	balllaser247_5.speed.y = 4;
	balllaser247_5.life = laser2uplife;

	//2st q
	balllaser270.anim.PushBack({ 0, 63, 24, 24 });
	balllaser270.anim.speed = 0.2f;
	balllaser270.speed.x = -10;
	balllaser270.life = laser2uplife;

	balllaser292_5.anim.PushBack({ 0, 63, 24, 24 });
	balllaser292_5.anim.speed = 0.2f;
	balllaser292_5.speed.x = -9;
	balllaser292_5.speed.y = -4;
	balllaser292_5.life = laser2uplife;

	balllaser315.anim.PushBack({ 0, 63, 24, 24 });
	balllaser315.anim.speed = 0.2f;
	balllaser315.speed.x = -7;
	balllaser315.speed.y = -7;
	balllaser315.life = laser2uplife;

	balllaser337_5.anim.PushBack({ 0, 63, 24, 24 });
	balllaser337_5.anim.speed = 0.2f;
	balllaser337_5.speed.x = -4;
	balllaser337_5.speed.y = -9;
	balllaser337_5.life = laser2uplife;

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
	soldierexplosion.fx = App->audio->LoadFx("Outzone/outzone_033.wav");
	playerexplosion.fx = App->audio->LoadFx("Outzone/outzone_019.wav");

	laserweaponshoot0.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laserweaponshoot22_5.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laserweaponshoot45.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laserweaponshoot67_5.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laserweaponshoot90.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laserweaponshoot112_5.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laserweaponshoot135.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laserweaponshoot157_5.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laserweaponshoot180.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laserweaponshoot202_5.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laserweaponshoot225.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laserweaponshoot247_5.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laserweaponshoot270.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laserweaponshoot292_5.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laserweaponshoot315.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	laserweaponshoot337_5.fx = App->audio->LoadFx("Outzone/outzone_040.wav");

	trilaser.fx = App->audio->LoadFx("Outzone/outzone_040.wav");
	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	App->audio->UnLoadFx(explosionturret.fx);
	App->audio->UnLoadFx(soldierexplosion.fx);
	App->audio->UnLoadFx(playerexplosion.fx);

	App->audio->UnLoadFx(laserweaponshoot0.fx);
	App->audio->UnLoadFx(laserweaponshoot22_5.fx);
	App->audio->UnLoadFx(laserweaponshoot45.fx);
	App->audio->UnLoadFx(laserweaponshoot67_5.fx);
	App->audio->UnLoadFx(laserweaponshoot90.fx);
	App->audio->UnLoadFx(laserweaponshoot112_5.fx);
	App->audio->UnLoadFx(laserweaponshoot135.fx);
	App->audio->UnLoadFx(laserweaponshoot157_5.fx);
	App->audio->UnLoadFx(laserweaponshoot180.fx);
	App->audio->UnLoadFx(laserweaponshoot202_5.fx);
	App->audio->UnLoadFx(laserweaponshoot225.fx);
	App->audio->UnLoadFx(laserweaponshoot247_5.fx);
	App->audio->UnLoadFx(laserweaponshoot270.fx);
	App->audio->UnLoadFx(laserweaponshoot292_5.fx);
	App->audio->UnLoadFx(laserweaponshoot315.fx);
	App->audio->UnLoadFx(laserweaponshoot337_5.fx);

	App->audio->UnLoadFx(trilaser.fx);

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
			if ((c2->type != COLLIDER_ENEMY_SHOT) && (c2->type != COLLIDER_STOP_SHOTS)){
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

