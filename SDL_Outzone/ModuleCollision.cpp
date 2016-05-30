#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

ModuleCollision::ModuleCollision()
{
	for(uint i = 0; i < MAX_COLLIDERS; ++i)
		colliders[i] = nullptr;

	matrix[COLLIDER_HOLE][COLLIDER_WALL] = false;
	matrix[COLLIDER_HOLE][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_HOLE][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_HOLE][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_HOLE][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_HOLE][COLLIDER_BOMB] = false;
	matrix[COLLIDER_HOLE][COLLIDER_DOOR] = false;
	matrix[COLLIDER_HOLE][COLLIDER_WALL2] = false;
	matrix[COLLIDER_HOLE][COLLIDER_HOLE] = false;
	matrix[COLLIDER_HOLE][COLLIDER_CHANGEAIM] = false;
	matrix[COLLIDER_HOLE][COLLIDER_BOX] = false;
	matrix[COLLIDER_HOLE][COLLIDER_SHIELD] = false;
	matrix[COLLIDER_HOLE][COLLIDER_GREY_ROBOT] = false;
	matrix[COLLIDER_HOLE][COLLIDER_BIG_RED_MACHINE] = false;
	matrix[COLLIDER_HOLE][COLLIDER_BLUE_MACHINE] = false;
	matrix[COLLIDER_HOLE][COLLIDER_ORANGE_ROBOT] = false;
	matrix[COLLIDER_HOLE][COLLIDER_PURPLE_MACHINE] = false;
	matrix[COLLIDER_HOLE][COLLIDER_TURRET1] = false;
	matrix[COLLIDER_HOLE][COLLIDER_TURRET3] = false;
	matrix[COLLIDER_HOLE][COLLIDER_RED_MACHINE] = false;
	matrix[COLLIDER_HOLE][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_HOLE][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_HOLE][COLLIDER_BOSS] = false;
	matrix[COLLIDER_HOLE][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_HOLE][COLLIDER_BOSSEYE] = false;

	matrix[COLLIDER_WALL][COLLIDER_WALL] = false;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_WALL][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_WALL][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_WALL][COLLIDER_BOMB] = false;
	matrix[COLLIDER_WALL][COLLIDER_DOOR] = false;
	matrix[COLLIDER_WALL][COLLIDER_WALL2] = false;
	matrix[COLLIDER_WALL][COLLIDER_HOLE] = false;
	matrix[COLLIDER_WALL][COLLIDER_CHANGEAIM] = false;
	matrix[COLLIDER_WALL][COLLIDER_BOX] = false;
	matrix[COLLIDER_WALL][COLLIDER_SHIELD] = false;
	matrix[COLLIDER_WALL][COLLIDER_GREY_ROBOT] = false;
	matrix[COLLIDER_WALL][COLLIDER_BIG_RED_MACHINE] = false;
	matrix[COLLIDER_WALL][COLLIDER_BLUE_MACHINE] = false;
	matrix[COLLIDER_WALL][COLLIDER_ORANGE_ROBOT] = false;
	matrix[COLLIDER_WALL][COLLIDER_PURPLE_MACHINE] = false;
	matrix[COLLIDER_WALL][COLLIDER_TURRET1] = false;
	matrix[COLLIDER_WALL][COLLIDER_TURRET3] = false;
	matrix[COLLIDER_WALL][COLLIDER_RED_MACHINE] = false;
	matrix[COLLIDER_WALL][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_WALL][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_WALL][COLLIDER_BOSS] = false;
	matrix[COLLIDER_WALL][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_WALL][COLLIDER_BOSSEYE] = false;

	matrix[COLLIDER_WALL2][COLLIDER_WALL] = false;
	matrix[COLLIDER_WALL2][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_WALL2][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_WALL2][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_WALL2][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_WALL2][COLLIDER_BOMB] = false;
	matrix[COLLIDER_WALL2][COLLIDER_DOOR] = false;
	matrix[COLLIDER_WALL2][COLLIDER_WALL2] = false;
	matrix[COLLIDER_WALL2][COLLIDER_HOLE] = false;
	matrix[COLLIDER_WALL2][COLLIDER_CHANGEAIM] = false;
	matrix[COLLIDER_WALL2][COLLIDER_BOX] = false;
	matrix[COLLIDER_WALL2][COLLIDER_SHIELD] = false;
	matrix[COLLIDER_WALL2][COLLIDER_GREY_ROBOT] = false;
	matrix[COLLIDER_WALL2][COLLIDER_BIG_RED_MACHINE] = false;
	matrix[COLLIDER_WALL2][COLLIDER_BLUE_MACHINE] = false;
	matrix[COLLIDER_WALL2][COLLIDER_ORANGE_ROBOT] = false;
	matrix[COLLIDER_WALL2][COLLIDER_PURPLE_MACHINE] = false;
	matrix[COLLIDER_WALL2][COLLIDER_TURRET1] = false;
	matrix[COLLIDER_WALL2][COLLIDER_TURRET3] = false;
	matrix[COLLIDER_WALL2][COLLIDER_RED_MACHINE] = false;
	matrix[COLLIDER_WALL2][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_WALL2][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_WALL2][COLLIDER_BOSS] = false;
	matrix[COLLIDER_WALL2][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_WALL2][COLLIDER_BOSSEYE] = false;

	matrix[COLLIDER_DOOR][COLLIDER_WALL] = false;
	matrix[COLLIDER_DOOR][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_DOOR][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_DOOR][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_DOOR][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_DOOR][COLLIDER_BOMB] = false;
	matrix[COLLIDER_DOOR][COLLIDER_DOOR] = false;
	matrix[COLLIDER_DOOR][COLLIDER_WALL2] = false;
	matrix[COLLIDER_DOOR][COLLIDER_HOLE] = false;
	matrix[COLLIDER_DOOR][COLLIDER_CHANGEAIM] = false;
	matrix[COLLIDER_DOOR][COLLIDER_BOX] = false;
	matrix[COLLIDER_DOOR][COLLIDER_SHIELD] = false;
	matrix[COLLIDER_DOOR][COLLIDER_GREY_ROBOT] = false;
	matrix[COLLIDER_DOOR][COLLIDER_BIG_RED_MACHINE] = false;
	matrix[COLLIDER_DOOR][COLLIDER_BLUE_MACHINE] = false;
	matrix[COLLIDER_DOOR][COLLIDER_ORANGE_ROBOT] = false;
	matrix[COLLIDER_DOOR][COLLIDER_PURPLE_MACHINE] = false;
	matrix[COLLIDER_DOOR][COLLIDER_TURRET1] = false;
	matrix[COLLIDER_DOOR][COLLIDER_TURRET3] = false;
	matrix[COLLIDER_DOOR][COLLIDER_RED_MACHINE] = false;
	matrix[COLLIDER_DOOR][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_DOOR][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_DOOR][COLLIDER_BOSS] = false;
	matrix[COLLIDER_DOOR][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_DOOR][COLLIDER_BOSSEYE] = false;

	matrix[COLLIDER_BOMB][COLLIDER_WALL] = false;
	matrix[COLLIDER_BOMB][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_BOMB][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_BOMB][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_BOMB][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_BOMB][COLLIDER_BOMB] = false;
	matrix[COLLIDER_BOMB][COLLIDER_DOOR] = false;
	matrix[COLLIDER_BOMB][COLLIDER_WALL2] = false;
	matrix[COLLIDER_BOMB][COLLIDER_HOLE] = false;
	matrix[COLLIDER_BOMB][COLLIDER_CHANGEAIM] = false;
	matrix[COLLIDER_BOMB][COLLIDER_BOX] = true;
	matrix[COLLIDER_BOMB][COLLIDER_SHIELD] = false;
	matrix[COLLIDER_BOMB][COLLIDER_GREY_ROBOT] = true;
	matrix[COLLIDER_BOMB][COLLIDER_BIG_RED_MACHINE] = true;
	matrix[COLLIDER_BOMB][COLLIDER_BLUE_MACHINE] = true;
	matrix[COLLIDER_BOMB][COLLIDER_ORANGE_ROBOT] = true;
	matrix[COLLIDER_BOMB][COLLIDER_PURPLE_MACHINE] = true;
	matrix[COLLIDER_BOMB][COLLIDER_TURRET1] = true;
	matrix[COLLIDER_BOMB][COLLIDER_TURRET3] = true;
	matrix[COLLIDER_BOMB][COLLIDER_RED_MACHINE] = true;
	matrix[COLLIDER_BOMB][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_BOMB][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_BOMB][COLLIDER_BOSS] = false;
	matrix[COLLIDER_BOMB][COLLIDER_BOSSWEAPON] = true;
	matrix[COLLIDER_BOMB][COLLIDER_BOSSEYE] = true;

	matrix[COLLIDER_PLAYER][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_BOMB] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_DOOR] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_WALL2] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_HOLE] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_CHANGEAIM] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_BOX] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_SHIELD] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_GREY_ROBOT] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_BIG_RED_MACHINE] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_BLUE_MACHINE] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_ORANGE_ROBOT] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_PURPLE_MACHINE] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_TURRET1] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_TURRET3] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_RED_MACHINE] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ENERGY] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_BOSS] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_BOSSWEAPON] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_BOSSEYE] = true;

	matrix[COLLIDER_ENEMY][COLLIDER_WALL] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_BOMB] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_DOOR] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_WALL2] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_HOLE] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_CHANGEAIM] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_BOX] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_SHIELD] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_GREY_ROBOT] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_BIG_RED_MACHINE] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_BLUE_MACHINE] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_ORANGE_ROBOT] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PURPLE_MACHINE] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_TURRET1] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_TURRET3] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_RED_MACHINE] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_BOSS] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_BOSSEYE] = false;

	matrix[COLLIDER_GREY_ROBOT][COLLIDER_WALL] = false;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_BOMB] = true;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_DOOR] = false;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_WALL2] = false;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_HOLE] = false;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_CHANGEAIM] = false;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_BOX] = true;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_SHIELD] = true;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_GREY_ROBOT] = true;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_BIG_RED_MACHINE] = true;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_BLUE_MACHINE] = true;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_ORANGE_ROBOT] = true;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_PURPLE_MACHINE] = true;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_TURRET1] = true;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_TURRET3] = true;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_RED_MACHINE] = true;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_BOSS] = false;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_GREY_ROBOT][COLLIDER_BOSSEYE] = false;

	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_WALL] = false;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_BOMB] = true;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_DOOR] = false;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_WALL2] = false;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_HOLE] = false;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_CHANGEAIM] = false;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_BOX] = true;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_SHIELD] = true;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_GREY_ROBOT] = true;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_BIG_RED_MACHINE] = true;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_BLUE_MACHINE] = true;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_ORANGE_ROBOT] = true;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_PURPLE_MACHINE] = true;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_TURRET1] = true;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_TURRET3] = true;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_RED_MACHINE] = true;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_BOSS] = false;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_BIG_RED_MACHINE][COLLIDER_BOSSEYE] = false;

	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_WALL] = false;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_BOMB] = true;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_DOOR] = false;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_WALL2] = false;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_HOLE] = false;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_CHANGEAIM] = false;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_BOX] = true;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_SHIELD] = true;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_GREY_ROBOT] = true;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_BIG_RED_MACHINE] = true;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_BLUE_MACHINE] = true;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_ORANGE_ROBOT] = true;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_PURPLE_MACHINE] = true;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_TURRET1] = true;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_TURRET3] = true;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_RED_MACHINE] = true;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_BOSS] = false;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_BLUE_MACHINE][COLLIDER_BOSSEYE] = false;

	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_WALL] = false;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_BOMB] = true;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_DOOR] = false;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_WALL2] = false;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_HOLE] = false;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_CHANGEAIM] = false;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_BOX] = true;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_SHIELD] = true;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_GREY_ROBOT] = true;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_BIG_RED_MACHINE] = true;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_BLUE_MACHINE] = true;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_ORANGE_ROBOT] = true;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_PURPLE_MACHINE] = true;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_TURRET1] = true;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_TURRET3] = true;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_RED_MACHINE] = true;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_BOSS] = false;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_ORANGE_ROBOT][COLLIDER_BOSSEYE] = false;

	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_WALL] = false;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_BOMB] = true;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_DOOR] = false;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_WALL2] = false;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_HOLE] = false;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_CHANGEAIM] = false;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_BOX] = true;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_SHIELD] = true;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_GREY_ROBOT] = true;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_BIG_RED_MACHINE] = true;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_BLUE_MACHINE] = true;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_ORANGE_ROBOT] = true;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_PURPLE_MACHINE] = true;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_TURRET1] = true;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_TURRET3] = true;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_RED_MACHINE] = true;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_BOSS] = false;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_PURPLE_MACHINE][COLLIDER_BOSSEYE] = false;

	matrix[COLLIDER_TURRET1][COLLIDER_WALL] = false;
	matrix[COLLIDER_TURRET1][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_TURRET1][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_TURRET1][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_TURRET1][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_TURRET1][COLLIDER_BOMB] = true;
	matrix[COLLIDER_TURRET1][COLLIDER_DOOR] = false;
	matrix[COLLIDER_TURRET1][COLLIDER_WALL2] = false;
	matrix[COLLIDER_TURRET1][COLLIDER_HOLE] = false;
	matrix[COLLIDER_TURRET1][COLLIDER_CHANGEAIM] = false;
	matrix[COLLIDER_TURRET1][COLLIDER_BOX] = true;
	matrix[COLLIDER_TURRET1][COLLIDER_SHIELD] = true;
	matrix[COLLIDER_TURRET1][COLLIDER_GREY_ROBOT] = true;
	matrix[COLLIDER_TURRET1][COLLIDER_BIG_RED_MACHINE] = true;
	matrix[COLLIDER_TURRET1][COLLIDER_BLUE_MACHINE] = true;
	matrix[COLLIDER_TURRET1][COLLIDER_ORANGE_ROBOT] = true;
	matrix[COLLIDER_TURRET1][COLLIDER_PURPLE_MACHINE] = true;
	matrix[COLLIDER_TURRET1][COLLIDER_TURRET1] = true;
	matrix[COLLIDER_TURRET1][COLLIDER_TURRET3] = true;
	matrix[COLLIDER_TURRET1][COLLIDER_RED_MACHINE] = true;
	matrix[COLLIDER_TURRET1][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_TURRET1][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_TURRET1][COLLIDER_BOSS] = false;
	matrix[COLLIDER_TURRET1][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_TURRET1][COLLIDER_BOSSEYE] = false;

	matrix[COLLIDER_TURRET3][COLLIDER_WALL] = false;
	matrix[COLLIDER_TURRET3][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_TURRET3][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_TURRET3][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_TURRET3][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_TURRET3][COLLIDER_BOMB] = true;
	matrix[COLLIDER_TURRET3][COLLIDER_DOOR] = false;
	matrix[COLLIDER_TURRET3][COLLIDER_WALL2] = false;
	matrix[COLLIDER_TURRET3][COLLIDER_HOLE] = false;
	matrix[COLLIDER_TURRET3][COLLIDER_CHANGEAIM] = false;
	matrix[COLLIDER_TURRET3][COLLIDER_BOX] = true;
	matrix[COLLIDER_TURRET3][COLLIDER_SHIELD] = true;
	matrix[COLLIDER_TURRET3][COLLIDER_GREY_ROBOT] = true;
	matrix[COLLIDER_TURRET3][COLLIDER_BIG_RED_MACHINE] = true;
	matrix[COLLIDER_TURRET3][COLLIDER_BLUE_MACHINE] = true;
	matrix[COLLIDER_TURRET3][COLLIDER_ORANGE_ROBOT] = true;
	matrix[COLLIDER_TURRET3][COLLIDER_PURPLE_MACHINE] = true;
	matrix[COLLIDER_TURRET3][COLLIDER_TURRET1] = true;
	matrix[COLLIDER_TURRET3][COLLIDER_TURRET3] = true;
	matrix[COLLIDER_TURRET3][COLLIDER_RED_MACHINE] = true;
	matrix[COLLIDER_TURRET3][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_TURRET3][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_TURRET3][COLLIDER_BOSS] = false;
	matrix[COLLIDER_TURRET3][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_TURRET3][COLLIDER_BOSSEYE] = false;

	matrix[COLLIDER_RED_MACHINE][COLLIDER_WALL] = false;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_BOMB] = true;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_DOOR] = false;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_WALL2] = false;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_HOLE] = false;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_CHANGEAIM] = false;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_BOX] = true;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_SHIELD] = true;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_GREY_ROBOT] = true;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_BIG_RED_MACHINE] = true;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_BLUE_MACHINE] = true;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_ORANGE_ROBOT] = true;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_PURPLE_MACHINE] = true;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_TURRET1] = true;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_TURRET3] = true;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_RED_MACHINE] = true;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_BOSS] = false;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_RED_MACHINE][COLLIDER_BOSSEYE] = false;

	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_BOMB] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_DOOR] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_WALL2] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_HOLE] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_CHANGEAIM] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_BOX] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_SHIELD] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_GREY_ROBOT] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_BIG_RED_MACHINE] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_BLUE_MACHINE] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ORANGE_ROBOT] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PURPLE_MACHINE] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_TURRET1] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_TURRET3] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_RED_MACHINE] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_STOP_SHOTS] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_BOSS] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_BOSSWEAPON] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_BOSSEYE] = true;

	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_WALL] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_BOMB] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_DOOR] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_WALL2] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_HOLE] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_CHANGEAIM] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_BOX] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_SHIELD] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_GREY_ROBOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_BIG_RED_MACHINE] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_BLUE_MACHINE] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ORANGE_ROBOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PURPLE_MACHINE] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_TURRET1] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_TURRET3] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_RED_MACHINE] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_BOSS] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_BOSSEYE] = false;
	//ENERGY

	// CHANGE AIM
	matrix[COLLIDER_CHANGEAIM][COLLIDER_WALL] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_BOMB] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_DOOR] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_WALL2] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_HOLE] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_BOX] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_SHIELD] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_GREY_ROBOT] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_BIG_RED_MACHINE] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_BLUE_MACHINE] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_ORANGE_ROBOT] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_PURPLE_MACHINE] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_TURRET1] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_TURRET3] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_RED_MACHINE] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_BOSS] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_CHANGEAIM][COLLIDER_BOSSEYE] = false;

	//BOX
	matrix[COLLIDER_BOX][COLLIDER_WALL] = false;
	matrix[COLLIDER_BOX][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_BOX][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_BOX][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_BOX][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_BOX][COLLIDER_BOMB] = true;
	matrix[COLLIDER_BOX][COLLIDER_DOOR] = false;
	matrix[COLLIDER_BOX][COLLIDER_WALL2] = false;
	matrix[COLLIDER_BOX][COLLIDER_HOLE] = false;
	matrix[COLLIDER_BOX][COLLIDER_CHANGEAIM] = false;
	matrix[COLLIDER_BOX][COLLIDER_SHIELD] = false;
	matrix[COLLIDER_BOX][COLLIDER_GREY_ROBOT] = true;
	matrix[COLLIDER_BOX][COLLIDER_BIG_RED_MACHINE] = true;
	matrix[COLLIDER_BOX][COLLIDER_BLUE_MACHINE] = true;
	matrix[COLLIDER_BOX][COLLIDER_ORANGE_ROBOT] = true;
	matrix[COLLIDER_BOX][COLLIDER_PURPLE_MACHINE] = true;
	matrix[COLLIDER_BOX][COLLIDER_TURRET1] = true;
	matrix[COLLIDER_BOX][COLLIDER_TURRET3] = true;
	matrix[COLLIDER_BOX][COLLIDER_RED_MACHINE] = true;
	matrix[COLLIDER_BOX][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_BOX][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_BOX][COLLIDER_BOSS] = false;
	matrix[COLLIDER_BOX][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_BOX][COLLIDER_BOSSEYE] = false;

	//COLLIDER SHIELD
	matrix[COLLIDER_SHIELD][COLLIDER_WALL] = false;
	matrix[COLLIDER_SHIELD][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_SHIELD][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_SHIELD][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_SHIELD][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_SHIELD][COLLIDER_BOMB] = true;
	matrix[COLLIDER_SHIELD][COLLIDER_DOOR] = false;
	matrix[COLLIDER_SHIELD][COLLIDER_WALL2] = false;
	matrix[COLLIDER_SHIELD][COLLIDER_HOLE] = false;
	matrix[COLLIDER_SHIELD][COLLIDER_BOX] = false;
	matrix[COLLIDER_SHIELD][COLLIDER_CHANGEAIM] = false;
	matrix[COLLIDER_SHIELD][COLLIDER_GREY_ROBOT] = true;
	matrix[COLLIDER_SHIELD][COLLIDER_BIG_RED_MACHINE] = true;
	matrix[COLLIDER_SHIELD][COLLIDER_BLUE_MACHINE] = true;
	matrix[COLLIDER_SHIELD][COLLIDER_ORANGE_ROBOT] = true;
	matrix[COLLIDER_SHIELD][COLLIDER_PURPLE_MACHINE] = true;
	matrix[COLLIDER_SHIELD][COLLIDER_TURRET1] = true;
	matrix[COLLIDER_SHIELD][COLLIDER_TURRET3] = true;
	matrix[COLLIDER_SHIELD][COLLIDER_RED_MACHINE] = true;
	matrix[COLLIDER_SHIELD][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_SHIELD][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_SHIELD][COLLIDER_BOSS] = true;
	matrix[COLLIDER_SHIELD][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_SHIELD][COLLIDER_BOSSEYE] = false;

	matrix[COLLIDER_STOP_SHOTS][COLLIDER_WALL] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_BOMB] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_DOOR] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_WALL2] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_HOLE] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_BOX] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_CHANGEAIM] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_GREY_ROBOT] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_BIG_RED_MACHINE] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_BLUE_MACHINE] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_ORANGE_ROBOT] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_PURPLE_MACHINE] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_TURRET1] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_TURRET3] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_RED_MACHINE] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_ENERGY] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_BOSS] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_STOP_SHOTS][COLLIDER_BOSSEYE] = false;

	matrix[COLLIDER_ENERGY][COLLIDER_WALL] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ENERGY][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_BOMB] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_DOOR] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_WALL2] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_HOLE] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_BOX] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_SHIELD] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_GREY_ROBOT] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_BIG_RED_MACHINE] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_BLUE_MACHINE] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_ORANGE_ROBOT] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_PURPLE_MACHINE] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_TURRET1] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_TURRET3] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_RED_MACHINE] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_BOSS] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_ENERGY][COLLIDER_BOSSEYE] = false;
	
	matrix[COLLIDER_BOSS][COLLIDER_WALL] = false;
	matrix[COLLIDER_BOSS][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_BOSS][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_BOSS][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_BOSS][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_BOSS][COLLIDER_BOMB] = false;
	matrix[COLLIDER_BOSS][COLLIDER_DOOR] = false;
	matrix[COLLIDER_BOSS][COLLIDER_WALL2] = false;
	matrix[COLLIDER_BOSS][COLLIDER_HOLE] = false;
	matrix[COLLIDER_BOSS][COLLIDER_BOX] = false;
	matrix[COLLIDER_BOSS][COLLIDER_SHIELD] = true;
	matrix[COLLIDER_BOSS][COLLIDER_GREY_ROBOT] = false;
	matrix[COLLIDER_BOSS][COLLIDER_BIG_RED_MACHINE] = false;
	matrix[COLLIDER_BOSS][COLLIDER_BLUE_MACHINE] = false;
	matrix[COLLIDER_BOSS][COLLIDER_ORANGE_ROBOT] = false;
	matrix[COLLIDER_BOSS][COLLIDER_PURPLE_MACHINE] = false;
	matrix[COLLIDER_BOSS][COLLIDER_TURRET1] = false;
	matrix[COLLIDER_BOSS][COLLIDER_TURRET3] = false;
	matrix[COLLIDER_BOSS][COLLIDER_RED_MACHINE] = false;
	matrix[COLLIDER_BOSS][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_BOSS][COLLIDER_BOSSWEAPON] = false;
	matrix[COLLIDER_BOSS][COLLIDER_BOSSEYE] = false;


	matrix[COLLIDER_BOSSWEAPON][COLLIDER_WALL] = false;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_BOMB] = true;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_DOOR] = false;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_WALL2] = false;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_HOLE] = false;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_BOX] = false;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_SHIELD] = false;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_GREY_ROBOT] = false;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_BIG_RED_MACHINE] = false;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_BLUE_MACHINE] = false;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_ORANGE_ROBOT] = false;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_PURPLE_MACHINE] = false;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_TURRET1] = false;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_TURRET3] = false;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_RED_MACHINE] = false;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_BOSS] = false;
	matrix[COLLIDER_BOSSWEAPON][COLLIDER_BOSSEYE] = false;

	matrix[COLLIDER_BOSSEYE][COLLIDER_WALL] = false;
	matrix[COLLIDER_BOSSEYE][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_BOSSEYE][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_BOSSEYE][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_BOSSEYE][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_BOSSEYE][COLLIDER_BOMB] = true;
	matrix[COLLIDER_BOSSEYE][COLLIDER_DOOR] = false;
	matrix[COLLIDER_BOSSEYE][COLLIDER_WALL2] = false;
	matrix[COLLIDER_BOSSEYE][COLLIDER_HOLE] = false;
	matrix[COLLIDER_BOSSEYE][COLLIDER_BOX] = false;
	matrix[COLLIDER_BOSSEYE][COLLIDER_SHIELD] = false;
	matrix[COLLIDER_BOSSEYE][COLLIDER_GREY_ROBOT] = false;
	matrix[COLLIDER_BOSSEYE][COLLIDER_BIG_RED_MACHINE] = false;
	matrix[COLLIDER_BOSSEYE][COLLIDER_BLUE_MACHINE] = false;
	matrix[COLLIDER_BOSSEYE][COLLIDER_ORANGE_ROBOT] = false;
	matrix[COLLIDER_BOSSEYE][COLLIDER_PURPLE_MACHINE] = false;
	matrix[COLLIDER_BOSSEYE][COLLIDER_TURRET1] = false;
	matrix[COLLIDER_BOSSEYE][COLLIDER_TURRET3] = false;
	matrix[COLLIDER_BOSSEYE][COLLIDER_RED_MACHINE] = false;
	matrix[COLLIDER_BOSSEYE][COLLIDER_STOP_SHOTS] = false;
	matrix[COLLIDER_BOSSEYE][COLLIDER_BOSS] = false;
	matrix[COLLIDER_BOSSEYE][COLLIDER_BOSSWEAPON] = false;
}

// Destructor
ModuleCollision::~ModuleCollision()
{}

update_status ModuleCollision::PreUpdate()
{
	// Remove all colliders scheduled for deletion
	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] != nullptr && colliders[i]->to_delete == true)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}
	Collider* c1;
	Collider* c2;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		// skip empty colliders
		if (colliders[i] == nullptr)
			continue;

		c1 = colliders[i];

		// avoid checking collisions already checked
		for (uint k = i + 1; k < MAX_COLLIDERS; ++k)
		{
			// skip empty colliders
			if (colliders[k] == nullptr)
				continue;

			c2 = colliders[k];

			if (c1->CheckCollision(c2->rect) == true)
			{
				if (matrix[c1->type][c2->type] && c1->callback)
				{
					if (App->player->current_animation != nullptr){

					//	App->render->Blit(App->player->graphics, App->player->PreviousPos.x+2, App->player->PreviousPos.y-10, &(App->player->current_animation->GetCurrentFrame()));
						App->player->collisionPrint = true;
						c1->callback->OnCollision(c1, c2);
					}

				}


				if (matrix[c2->type][c1->type] && c2->callback)
				{
					//c2->callback->OnCollision(c2, c1);
				}

			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleCollision::Update()
{
	Collider* c1;
	Collider* c2;

	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		// skip empty colliders
		if(colliders[i] == nullptr)
			continue;

		c1 = colliders[i];

		// avoid checking collisions already checked
		for(uint k = i+1; k < MAX_COLLIDERS; ++k)
		{
			// skip empty colliders
			if(colliders[k] == nullptr)
				continue;

			c2 = colliders[k];

			if (c1->CheckCollision(c2->rect) == true)
			{
				if (matrix[c1->type][c2->type] && c1->callback)
				{
					
					c1->callback->OnCollision(c1, c2);
			//	App->render->Blit(App->player->graphics, App->player->PreviousPos.x, App->player->PreviousPos.y-1, &(App->player->current_animation->GetCurrentFrame()));

				}
					
				
			if (matrix[c2->type][c1->type] && c2->callback)
			{
				 c2->callback->OnCollision(c2, c1);
			}
					
			}
		}
	}

	DebugDraw();

	return UPDATE_CONTINUE;
}

void ModuleCollision::DebugDraw()
{
	if(App->input->keyboard[SDL_SCANCODE_F1] == KEY_DOWN)
		debug = !debug;

	if(debug == false)
		return;

	Uint8 alpha = 80;
	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] == nullptr)
			continue;
		
		switch(colliders[i]->type)
		{
			case COLLIDER_NONE: // white
				App->render->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
				break;
			case COLLIDER_WALL: // blue
				App->render->DrawQuad(colliders[i]->rect, 0, 0, 255, alpha);
				break;
			case COLLIDER_PLAYER: // green
				App->render->DrawQuad(colliders[i]->rect, 0, 255, 0, alpha);
				break;
			case COLLIDER_ENEMY: // red
				App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
				break;
			case COLLIDER_PLAYER_SHOT: // yellow
				App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
				break;
			case COLLIDER_ENEMY_SHOT: // magenta
				App->render->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
				break;
			case COLLIDER_WALL2:
				App->render->DrawQuad(colliders[i]->rect, 0, 150, 150, alpha);
				break;
			case COLLIDER_BOMB:
				App->render->DrawQuad(colliders[i]->rect, 0, 0, 0, alpha);
				break;
			case COLLIDER_DOOR:
				App->render->DrawQuad(colliders[i]->rect, 150, 150, 0, alpha);
				break;
			case COLLIDER_BOX:
				App->render->DrawQuad(colliders[i]->rect, 255, 0, 145, alpha);
				break;
			case COLLIDER_CHANGEAIM:
				App->render->DrawQuad(colliders[i]->rect, 190, 250, 90, alpha);
				break;
			case COLLIDER_ENERGY:
				App->render->DrawQuad(colliders[i]->rect, 190, 250, 90, alpha);
				break;
			case COLLIDER_HOLE:
				App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
				break;
			case COLLIDER_GREY_ROBOT:
				App->render->DrawQuad(colliders[i]->rect, 126, 126, 126, alpha);
				break;
			case COLLIDER_BIG_RED_MACHINE:
				App->render->DrawQuad(colliders[i]->rect, 155, 0, 0, alpha);
				break;
			case COLLIDER_BLUE_MACHINE:
				App->render->DrawQuad(colliders[i]->rect, 0, 50, 255, alpha);
				break;
			case COLLIDER_ORANGE_ROBOT:
				App->render->DrawQuad(colliders[i]->rect, 255, 150, 0, alpha);
				break;
			case COLLIDER_PURPLE_MACHINE:
				App->render->DrawQuad(colliders[i]->rect, 170, 255, 255, alpha);
				break;
			case COLLIDER_RED_MACHINE:
				App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
				break;
			case COLLIDER_TURRET1:
				App->render->DrawQuad(colliders[i]->rect, 0, 255, 175, alpha);
				break;
			case COLLIDER_TURRET3:
				App->render->DrawQuad(colliders[i]->rect, 200, 255, 0, alpha);
				break;
			case COLLIDER_STOP_SHOTS:
				App->render->DrawQuad(colliders[i]->rect, 0, 0, 0, alpha);
				break;
			case COLLIDER_BOSS:
				App->render->DrawQuad(colliders[i]->rect, 90, 90, 90, alpha);
				break;
			case COLLIDER_BOSSWEAPON:
				App->render->DrawQuad(colliders[i]->rect, 155, 115, 0, alpha);
				break;
			case COLLIDER_BOSSEYE:
				App->render->DrawQuad(colliders[i]->rect, 0, 95, 25, alpha);
				break;

		}
	}
}

// Called before quitting
bool ModuleCollision::CleanUp()
{
	LOG("Freeing all colliders");

	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] != nullptr)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	return true;
}

Collider* ModuleCollision::AddCollider(SDL_Rect rect, COLLIDER_TYPE type, Module* callback)
{
	Collider* ret = nullptr;

	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] == nullptr)
		{
			ret = colliders[i] = new Collider(rect, type, callback);
			break;
		}
	}

	return ret;
}

bool ModuleCollision::EraseCollider(Collider* collider)
{
	if(collider != nullptr)
	{
		// we still search for it in case we received a dangling pointer
		for(uint i = 0; i < MAX_COLLIDERS; ++i)
		{
			if(colliders[i] == collider)
			{
				collider->to_delete = true;
				break;
			}
		}
	}
		

	return false;
}

// -----------------------------------------------------

bool Collider::CheckCollision(const SDL_Rect& r) const
{
	return (rect.x < r.x + r.w &&
			rect.x + rect.w > r.x &&
			rect.y < r.y + r.h &&
			rect.h + rect.y > r.y);
}