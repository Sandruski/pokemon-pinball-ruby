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
	b2Vec2 start_ball;
	float ball_diameter;

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

	SDL_Rect* r_pokemons1;
	SDL_Rect* r_pokemons2;
	SDL_Rect* r_pokemons3;
	SDL_Rect* r_spring;
	SDL_Rect* r_shark;
	SDL_Rect* r_cave;
	SDL_Rect* r_pokemon_cave;
	SDL_Rect* r_egg;

	//Rotating pokemons hit


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
	Animation rotating_pokemons_hit1;
	Animation rotating_pokemons_hit2;
	Animation* current_rotating_pokemons1;
	Animation* current_rotating_pokemons2;
	Animation* current_rotating_pokemons3;
	bool p1, p2, p3;

	Ball* ball_properties;

	//Spring
	b2DistanceJoint* springDistanceJoint;
	b2PrismaticJoint* springPrismaticJoint;
	b2Vec2 impulse = { 0,0 };
	Animation grey_spring;
	Animation red_spring;
	Animation start_spring;
	Animation end_spring;
	Animation* current_spring;
	bool spring_anim;

	//I think this should go to scene_intro...
	//Shark
	Animation idle_shark;
	Animation eat_shark;
	Animation go_back_shark;
	Animation spit_shark;
	PhysBody* shark;
	Animation* current_shark;

	//Cave (+ egg, + pokémon)
	Animation idle_cave;
	Animation to_red_cave;
	Animation red_cave;
	Animation to_idle_cave;

	Animation idle_egg;
	Animation jump_egg;
	Animation break_egg;

	Animation idle_pokemon_cave;
	Animation enter_pokemon_cave;
	Animation in_pokemon_cave;

	Animation* current_cave;
	Animation* current_pokemon_cave;
	Animation* current_egg;

	PhysBody* pokemon_cave;
	PhysBody* cave;

	int num_cave_hits = 0;
	bool cave_hit;
	bool pokemon_cave_hit;
	bool shark_hit;

	void CreateBall(float diameter, int x, int y);
	void DestroyBall();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);
	void UpdateCamera();

public:
	PhysBody* ball;
	int life = 0;

};