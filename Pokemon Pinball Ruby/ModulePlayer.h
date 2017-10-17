#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleTextures.h"
#include "Animation.h"

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

private:

	SDL_Texture* general;
	SDL_Texture* menu;
	SDL_Texture* pokeball;

	PhysBody* ball;
	p2List<PhysBody*> balls;

	SDL_Rect* r;
	Animation* current_animation;
	Animation ball_anim;

	PhysBody* flippers[2];

	//Left flipper
	SDL_Rect l_f1 = { 0, 1149, 29, 26 };
	SDL_Rect l_f2 = { 31, 1149, 29, 26 };
	SDL_Rect l_f3 = { 63, 1149, 29, 26 };
	SDL_Rect l_f4 = { 96, 1149, 29, 26 };
	SDL_Rect l_f5 = { 129, 1149, 29, 26 };
	SDL_Rect l_f6 = { 161, 1149, 29, 26 };

	//Right flipper
	SDL_Rect r_f1 = { 161, 1195, 29, 26 };
	SDL_Rect r_f2 = { 129, 1195, 29, 26 };
	SDL_Rect r_f3 = { 96, 1195, 29, 26 };
	SDL_Rect r_f4 = { 63, 1195, 29, 26 };
	SDL_Rect r_f5 = { 31, 1195, 29, 26 };
	SDL_Rect r_f6 = { 0, 1195, 29, 26 };

	//Spring
	SDL_Rect s1 = { 92, 815, 20, 35 };
	SDL_Rect s2 = { 114, 815, 20, 35 };
	SDL_Rect s3 = { 136, 815, 20, 35 };

public:

};