#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleTextures.h"
#include "Animation.h"

enum ball_type {
	pokeball,
	superball,
	ultraball,
	masterball
};

struct Ball {

	ball_type type = pokeball;

	SDL_Rect* current_sprite;
	int loops = 0;
	int max_angle = 360;
};

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

private:

	SDL_Texture* pokeball;



	SDL_Rect* r;

	SDL_Rect* ball_sprite;
	float loops;
	int number;

	//Animation* current_animation;
	Animation ball_anim;

	PhysBody* flippers[2];

	//Ball
	SDL_Rect b1 = { 159, 926, 15, 15 };
	SDL_Rect b2 = { 176, 926, 15, 15 };
	SDL_Rect b3 = { 193, 926, 15, 15 };
	SDL_Rect b4 = { 210, 926, 15, 15 };
	SDL_Rect b5 = { 227, 926, 15, 15 };
	SDL_Rect b6 = { 244, 926, 15, 15 };
	SDL_Rect b7 = { 261, 926, 15, 15 };
	SDL_Rect b8 = { 278, 926, 15, 15 };
	SDL_Rect b9 = { 295, 926, 15, 15 };
	SDL_Rect b10 = { 312, 926, 15, 15 };
	SDL_Rect b11 = { 329, 926, 15, 15 };
	SDL_Rect b12 = { 346, 926, 15, 15 };
	SDL_Rect b13 = { 363, 926, 15, 15 };
	SDL_Rect b14 = { 380, 926, 15, 15 };
	SDL_Rect b15 = { 397, 926, 15, 15 };
	SDL_Rect b16 = { 414, 926, 15, 15 };

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

	//Get ball sprites
	void GetBallSprites(float angle, Ball* ball_properties);

	PhysBody* ball;
	p2List<PhysBody*> balls;
	Ball* ball_properties;
	p2List<Ball*> balls_properties;

public:

};