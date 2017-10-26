#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleTextures.h"
#include "Animation.h"
#include "ModulePhysics.h"

enum map_stuff {
	NEUTRAL = 0x0001,
	FLIPPER = 0x0002,
	WALL = 0x0004,
	BALL = 0x0008,
	//ENEMY_AIRCRAFT = 0x0010,
};

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

	//Flipper (left)
	SDL_Rect l_f1 = { 0, 1316, 31, 26 };
	SDL_Rect l_f2 = { 31, 1316, 31, 26 };
	SDL_Rect l_f3 = { 63, 1316, 31, 26 };
	SDL_Rect l_f4 = { 96, 1316, 31, 26 };
	SDL_Rect l_f5 = { 129, 1316, 31, 26 };
	SDL_Rect l_f6 = { 161, 1316, 31, 26 };

	//Flipper (right)
	SDL_Rect r_f1 = { 425, 1316, 31, 26 };
	SDL_Rect r_f2 = { 384, 1316, 31, 26 };
	SDL_Rect r_f3 = { 343, 1316, 31, 26 };
	SDL_Rect r_f4 = { 300, 1316, 31, 26 };
	SDL_Rect r_f5 = { 249, 1316, 31, 26 };
	SDL_Rect r_f6 = { 203, 1316, 31, 26 };

	//Spring
	//Grey part
	SDL_Rect g1 = { 48, 813, 20, 37 };
	SDL_Rect g2 = { 70, 815, 20, 35 };

	SDL_Rect* r;

	//Get sprites
	void GetBallSprites(float angle, Ball* ball_properties); //Ball
	void GetFlipperSprites(float angle, SDL_Rect* &flipper_sprite, bool left); //Flipper

	//Flippers
	PhysBody* flippers[2];
	PhysBody* flipperCircles[2];
	b2RevoluteJoint* flipperRevoluteJoints[2];
	SDL_Rect* flipper_sprite[2];

	//Rotating pokémons
	PhysBody* rotatingPokemons[4];
	b2RevoluteJoint* pokemonsRevoluteJoint[3];
	Animation rotating_pokemons;
	Animation* current_rotating_pokemons;

	Ball* ball_properties;

	//Spring
	b2DistanceJoint* springDistanceJoint;
	b2PrismaticJoint* springPrismaticJoint;
	b2Vec2 impulse = { 0,0 };
	Animation grey_spring;
	Animation red_spring;
	Animation* current_spring;

public:
	PhysBody* ball;

};