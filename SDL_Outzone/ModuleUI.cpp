#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleUI.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleEffects.h"
#include "ModuleTextures.h"
#include "ModuleWinScreen.h"
#include "ModuleSceneGameOver.h"
#include "ModuleSceneIntro.h"

#include "SDL/include/SDL_timer.h"
#include<string.h>
#include <stdio.h>

#define LIFEPOSITION 19	
#define BOMBPOSITIONX 2
#define BOMBPOSITIONY 301	

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleUI::ModuleUI()
{}

ModuleUI::~ModuleUI()
{}
// Load new texture from file path
int ModuleUI::Load(const char* texture_path, const char* characters, uint rows)
{
	int id = -1;

	if (texture_path == nullptr || characters == nullptr || rows == 0)
	{
		LOG("Could not load font");
		return id;
	}

	SDL_Texture* tex = App->textures->Load(texture_path);

	if (tex == nullptr || strlen(characters) >= MAX_FONT_CHARS)
	{
		LOG("Could not load font at %s with characters '%s'", texture_path, characters);
		return id;
	}

	id = 0;
	for (; id < MAX_FONTS; ++id)
	if (fonts[id].graphic == nullptr)
		break;

	if (id == MAX_FONTS)
	{
		LOG("Cannot load font %s. Array is full (max %d).", texture_path, MAX_FONTS);
		return id;
	}

	// if we reach this point we can safely create a new bmp font
	Font* f = &fonts[id];
	f->graphic = tex;
	strcpy_s(fonts[id].table, MAX_FONT_CHARS, characters);
	f->rows = rows;
	f->len = strlen(characters);
	f->row_chars = fonts[id].len / rows;

	uint w, h;
	App->textures->GetSize(tex, w, h);
	f->row_chars = fonts[id].len / rows;
	f->char_w = w / fonts[id].row_chars;
	f->char_h = h / rows;
	
	LOG("Successfully loaded BMP font from %s", texture_path);

	return id;
}
void ModuleUI::UnLoad(int font_id)
{
	if (font_id >= 0 && font_id < MAX_FONTS && fonts[font_id].graphic != nullptr)
	{
		App->textures->Unload(fonts[font_id].graphic);
		fonts[font_id].graphic = nullptr;
		LOG("Successfully Unloaded BMP font_id %d", font_id);
	}
}
void ModuleUI::Blit(int x, int y, int font_id, const char* text) const
{
	if (text == nullptr || font_id < 0 || font_id >= MAX_FONTS || fonts[font_id].graphic == nullptr)
	{
		LOG("Unable to render text with bmp font id %d", font_id);
		return;
	}

	const Font* font = &fonts[font_id];
	SDL_Rect rect;
	uint len = strlen(text);

	rect.w = font->char_w;
	rect.h = font->char_h;

	for (uint i = 0; i < len; ++i)
	{
		// we could use strchr instead ?
		for (uint j = 0; j < font->len; ++j)
		{
			if (font->table[j] == text[i])
			{
				rect.x = rect.w * (j % font->row_chars);
				rect.y = rect.h * (j / font->row_chars);
				App->render->Blit(font->graphic, x, y, &rect, 0.0f);
				x += rect.w;
				break;
			}
		}
	}
}



// Load assets
bool ModuleUI::Start()
{
	LOG("Loading space scene");
	background = App->textures->Load("Outzone/UI.png");
	font_score = App->ui->Load("Outzone/scoreNumbers.png", "0123456789", 1);
	UI.PushBack({ 25, 3, 93, 10 });
	effect1 = &UI;
	UI2.PushBack({ 0, 85, 110, 7 });
	effect2 = &UI2;
	UI3.PushBack({ 20, 4, 1, 6 });
	effect3 = &UI3;
	UI4.PushBack({ 5, 14, 8, 16 });
	effect4 = &UI4;
	return true;
}

// UnLoad assets
bool ModuleUI::CleanUp()
{
	LOG("Unloading space scene");

	App->audio->Disable();
	Mix_FadeOutMusic(500);
	App->enemies->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->player->Disable();
	App->effects->Disable();
	App->textures->Unload(background);
	App->ui->Disable();

	return true;
}

// Update: draw background
update_status ModuleUI::Update()
{
	//if (effect)
	if (effect1 != nullptr){
		if ((App->scene_gamewin->IsEnabled() == false) && (App->scene_gameover->IsEnabled() == false) && (App->scene_intro->IsEnabled() == false)){
			App->render->Blit(background, App->render->camera.x + 2, App->render->camera.y / 2 + 18, &(effect1->GetCurrentFrame()));
		}
	}
	if (effect2 != nullptr){
		App->render->Blit(background, App->render->camera.x + 19, App->render->camera.y / 2 + 1, &(effect2->GetCurrentFrame()));
	}
	unsigned int currentTime = 0;
	currentTime = SDL_GetTicks();
	if (App->player->Invencible == false){
		if (currentTime > (lastTime + 1000)) {
			App->player->playerlife -= 1;
			lastTime = currentTime;
		}
	}
	if (effect3 != nullptr){
		if ((App->scene_gamewin->IsEnabled() == false) && (App->scene_gameover->IsEnabled() == false) && (App->scene_intro->IsEnabled() == false)){
			if (App->player->playerlife >= 0){
				App->render->Blit(background, App->render->camera.x + LIFEPOSITION, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
				if (App->player->playerlife >= 1){
					App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 2, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
					if (App->player->playerlife >= 2){
						App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 4, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
						if (App->player->playerlife >= 3){
							App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 6, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
							if (App->player->playerlife >= 4){
								App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 8, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
								if (App->player->playerlife >= 5){
									App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 10, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
									if (App->player->playerlife >= 6){
										App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 12, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
										if (App->player->playerlife >= 7){
											App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 14, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
											if (App->player->playerlife >= 8){
												App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 16, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
												if (App->player->playerlife >= 9){
													App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 18, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
													if (App->player->playerlife >= 10){
														App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 20, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
														if (App->player->playerlife >= 11){
															App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 22, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
															if (App->player->playerlife >= 12){
																App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 24, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																if (App->player->playerlife >= 13){
																	App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 26, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																	if (App->player->playerlife >= 14){
																		App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 28, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																		if (App->player->playerlife >= 15){
																			App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 30, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																			if (App->player->playerlife >= 16){
																				App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 32, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																				if (App->player->playerlife >= 17){
																					App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 34, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																					if (App->player->playerlife >= 18){
																						App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 36, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																						if (App->player->playerlife >= 19){
																							App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 38, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																							if (App->player->playerlife >= 20){
																								App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 40, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																								if (App->player->playerlife >= 21){
																									App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 42, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																									if (App->player->playerlife >= 22){
																										App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 44, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																										if (App->player->playerlife >= 23){
																											App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 46, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																											if (App->player->playerlife >= 24){
																												App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 48, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																												if (App->player->playerlife >= 25){
																													App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 50, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																													if (App->player->playerlife >= 26){
																														App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 52, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																														if (App->player->playerlife >= 27){
																															App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 54, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																															if (App->player->playerlife >= 28){
																																App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 56, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																																if (App->player->playerlife >= 29){
																																	App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 58, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																																	if (App->player->playerlife >= 30){
																																		App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 60, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																																		if (App->player->playerlife >= 31){
																																			App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 62, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																																			if (App->player->playerlife >= 32){
																																				App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 64, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																																				if (App->player->playerlife >= 33){
																																					App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 66, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																																					if (App->player->playerlife >= 34){
																																						App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 68, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																																						if (App->player->playerlife >= 35){
																																							App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 70, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																																							if (App->player->playerlife >= 36){
																																								App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 72, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																																								if (App->player->playerlife == 37){
																																									App->render->Blit(background, App->render->camera.x + LIFEPOSITION + 74, App->render->camera.y / 2 + 19, &(effect3->GetCurrentFrame()));
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	if (effect4 != nullptr){
		if ((App->scene_gamewin->IsEnabled() == false) && (App->scene_gameover->IsEnabled() == false) && (App->scene_intro->IsEnabled() == false)){
			if (App->player->playerbombsnum == 1){
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
			}
			else if (App->player->playerbombsnum == 2){
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 8, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
			}
			else if (App->player->playerbombsnum == 3){
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 8, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 16, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
			}
			else if (App->player->playerbombsnum == 4){
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 8, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 16, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 24, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
			}
			else if (App->player->playerbombsnum == 5){
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 8, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 16, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 24, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 32, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
			}
			else if (App->player->playerbombsnum == 6){
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 8, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 16, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 24, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 32, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 40, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
			}
			else if (App->player->playerbombsnum == 7){
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 8, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 16, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 24, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 32, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 40, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 48, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
			}
			else if (App->player->playerbombsnum == 8){
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 8, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 16, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 24, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 32, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 40, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 48, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 56, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
			}
			else if (App->player->playerbombsnum == 9){
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 8, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 16, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 24, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 32, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 40, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 48, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 56, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 64, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
			}
			else if (App->player->playerbombsnum == 10){
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 8, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 16, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 24, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 32, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 40, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 48, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 56, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 64, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
				App->render->Blit(background, App->render->camera.x + BOMBPOSITIONX + 72, App->render->camera.y / 2 + BOMBPOSITIONY, &(effect4->GetCurrentFrame()));
			}
		}
	}

	sprintf_s(score_text, 10, "%06i", App->enemies->pointscount);
	App->ui->Blit(32, 9, font_score, score_text);
	sprintf_s(score_text, 10, "%06i", App->enemies->maxpointsearned);
	App->ui->Blit(90, 9, font_score, score_text);

	return UPDATE_CONTINUE;
}