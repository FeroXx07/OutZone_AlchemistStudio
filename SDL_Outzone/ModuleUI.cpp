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

#include "SDL/include/SDL_timer.h"
#include<string.h>
#include <stdio.h>

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
	f->char_w = 11;
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
	UI.PushBack({ 25, 3, 93, 10 });
	effect1 = &UI;
	UI2.PushBack({ 0, 85, 110, 7 });
	effect2 = &UI2;
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
	App->render->Blit(background, App->render->camera.x+2, App->render->camera.y / 2+16, &(effect1->GetCurrentFrame()));
	App->render->Blit(background, App->render->camera.x+19, App->render->camera.y / 2+1, &(effect2->GetCurrentFrame()));
	//sprintf_s(score_text, 10, "1", score);
	//App->ui->Blit(0, 0, font_score, score_text);
	/*
	if (App->player->position.y <= -3160){
	App->fade->FadeToBlack(this, (Module*)App->scene_gamewin);
	}
	
	// Draw everything --------------------------------------
	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT){
		if (App->player->position.y == (160 + (App->render->camera.y / 2))){
			if (firstimeblit == true){
				App->render->Blit(background, 0, -5253, NULL);
				firstimeblit = false;
			}
			else{
				App->render->Blit(background, 0, -5255, NULL);
			}
		}
		else{
			App->render->Blit(background, 0, -5253, NULL);
		}
	}
	else{
		App->render->Blit(background, 0, -5253, NULL);
	}
	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT){
		firstimeblit = true;
	}*/
	return UPDATE_CONTINUE;
}