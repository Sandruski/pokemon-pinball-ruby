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
	//Ball
	SDL_Texture* pokeball;
	b2Vec2 start_ball;
	float ball_diameter;
	Ball* ball_properties;
	bool blit_ball;

	//Pokeball
	SDL_Rect pb1 = { 159, 926, 15, 15 };
	SDL_Rect pb2 = { 176, 926, 15, 15 };
	SDL_Rect pb3 = { 193, 926, 15, 15 };
	SDL_Rect pb4 = { 210, 926, 15, 15 };
	SDL_Rect pb5 = { 227, 926, 15, 15 };
	SDL_Rect pb6 = { 244, 926, 15, 15 };
	SDL_Rect pb7 = { 261, 926, 15, 15 };
	SDL_Rect pb8 = { 278, 926, 15, 15 };
	SDL_Rect pb9 = { 295, 926, 15, 15 };
	SDL_Rect pb10 = { 312, 926, 15, 15 };
	SDL_Rect pb11 = { 329, 926, 15, 15 };
	SDL_Rect pb12 = { 346, 926, 15, 15 };
	SDL_Rect pb13 = { 363, 926, 15, 15 };
	SDL_Rect pb14 = { 380, 926, 15, 15 };
	SDL_Rect pb15 = { 397, 926, 15, 15 };
	SDL_Rect pb16 = { 414, 926, 15, 15 };

	//Superball
	SDL_Rect sb1 = { 159, 954, 15, 15 };
	SDL_Rect sb2 = { 176, 954, 15, 15 };
	SDL_Rect sb3 = { 193, 954, 15, 15 };
	SDL_Rect sb4 = { 210, 954, 15, 15 };
	SDL_Rect sb5 = { 227, 954, 15, 15 };
	SDL_Rect sb6 = { 244, 954, 15, 15 };
	SDL_Rect sb7 = { 261, 954, 15, 15 };
	SDL_Rect sb8 = { 278, 954, 15, 15 };
	SDL_Rect sb9 = { 295, 954, 15, 15 };
	SDL_Rect sb10 = { 312, 954, 15, 15 };
	SDL_Rect sb11 = { 329, 954, 15, 15 };
	SDL_Rect sb12 = { 346, 954, 15, 15 };
	SDL_Rect sb13 = { 363, 954, 15, 15 };
	SDL_Rect sb14 = { 380, 954, 15, 15 };
	SDL_Rect sb15 = { 397, 954, 15, 15 };
	SDL_Rect sb16 = { 414, 954, 15, 15 };

	//Ultraball
	SDL_Rect ub1 = { 159, 982, 15, 15 };
	SDL_Rect ub2 = { 176, 982, 15, 15 };
	SDL_Rect ub3 = { 193, 982, 15, 15 };
	SDL_Rect ub4 = { 210, 982, 15, 15 };
	SDL_Rect ub5 = { 227, 982, 15, 15 };
	SDL_Rect ub6 = { 244, 982, 15, 15 };
	SDL_Rect ub7 = { 261, 982, 15, 15 };
	SDL_Rect ub8 = { 278, 982, 15, 15 };
	SDL_Rect ub9 = { 295, 982, 15, 15 };
	SDL_Rect ub10 = { 312, 982, 15, 15 };
	SDL_Rect ub11 = { 329, 982, 15, 15 };
	SDL_Rect ub12 = { 346, 982, 15, 15 };
	SDL_Rect ub13 = { 363, 982, 15, 15 };
	SDL_Rect ub14 = { 380, 982, 15, 15 };
	SDL_Rect ub15 = { 397, 982, 15, 15 };
	SDL_Rect ub16 = { 414, 982, 15, 15 };

	//Masterball
	SDL_Rect mb1 = { 159, 1010, 15, 15 };
	SDL_Rect mb2 = { 176, 1010, 15, 15 };
	SDL_Rect mb3 = { 193, 1010, 15, 15 };
	SDL_Rect mb4 = { 210, 1010, 15, 15 };
	SDL_Rect mb5 = { 227, 1010, 15, 15 };
	SDL_Rect mb6 = { 244, 1010, 15, 15 };
	SDL_Rect mb7 = { 261, 1010, 15, 15 };
	SDL_Rect mb8 = { 278, 1010, 15, 15 };
	SDL_Rect mb9 = { 295, 1010, 15, 15 };
	SDL_Rect mb10 = { 312, 1010, 15, 15 };
	SDL_Rect mb11 = { 329, 1010, 15, 15 };
	SDL_Rect mb12 = { 346, 1010, 15, 15 };
	SDL_Rect mb13 = { 363, 1010, 15, 15 };
	SDL_Rect mb14 = { 380, 1010, 15, 15 };
	SDL_Rect mb15 = { 397, 1010, 15, 15 };
	SDL_Rect mb16 = { 414, 1010, 15, 15 };

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

	//Above layer
	SDL_Rect above = { 268, 3, 256, 227 };
	SDL_Rect above_details = { 0, 3, 256, 200};
	PhysBody* left_above;
	PhysBody* right_above;
	PhysBody* left_sensor_above;
	PhysBody* right_sensor_above;
	PhysBody* not_above_left;
	PhysBody* not_above_right;
	bool enable_above;
	bool disable_above;

	//Door
	Animation idle_door;
	Animation opening_door;
	Animation closing_door;
	Animation* current_door;
	SDL_Rect* r_door;
	PhysBody* door;
	bool door_hit;

	//Pokemon mart-center
	Animation pokemon_mart_center;
	Animation* current_mart_center;
	SDL_Rect* r_mart_center;

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
	SDL_Rect* r_pokemons1;
	SDL_Rect* r_pokemons2;
	SDL_Rect* r_pokemons3;
	bool p1, p2, p3;
	uint post_start;

	//Spring
	b2DistanceJoint* springDistanceJoint;
	b2PrismaticJoint* springPrismaticJoint;
	b2Vec2 impulse = { 0,0 };
	Animation grey_spring;
	Animation red_spring;
	Animation start_spring;
	Animation end_spring;
	Animation* current_spring;
	SDL_Rect* r_spring;
	bool spring_anim;

	//Shark
	Animation idle_shark;
	Animation eat_shark;
	Animation go_back_shark;
	Animation spit_shark;
	PhysBody* shark;
	Animation* current_shark;
	SDL_Rect* r_shark;
	bool shark_hit;
	float go_back1_x;
	float go_back1_y;
	bool first_shark;

	//Cave
	PhysBody* cave;
	Animation idle_cave;
	Animation red_cave;
	Animation to_idle_cave;
	Animation jump_cave;
	Animation wait_cave;
	Animation* current_cave;
	SDL_Rect* r_cave;

	//Egg
	Animation idle_egg;
	Animation jump1_egg;
	Animation jump2_egg;
	Animation break_egg1;
	Animation break_egg2;
	Animation* current_egg;
	SDL_Rect* r_egg;
	bool blit_egg;

	//Pokémon cave
	PhysBody* pokemon_cave;
	PhysBody* pokemon_cave1;
	Animation idle_pokemon_cave;
	Animation go_back_pokemon_cave;
	Animation in_pokemon_cave;
	Animation disappear_pokemon_cave;
	Animation almost_in_pokemon_cave;
	Animation* current_pokemon_cave;
	SDL_Rect* r_pokemon_cave;

	bool destroy_pokemon_cave;
	bool destroy_pokemon_cave1;
	bool pokemon_cave_hit;
	bool pokemon_cave1_hit;
	bool go_forward;
	float go_back2_x;
	float go_back2_y;
	float go_back3_y;
	bool blit_pokemon_over_cave;
	bool blit_pokemon_cave;
	int num_cave_hits = 0;
	bool cave_hit;

	//Coin
	PhysBody* coin_left;
	PhysBody* coin_right;
	PhysBody* coin_mid;
	Animation coin_idle;
	Animation coin_picked;
	Animation* current_coin_left;
	Animation* current_coin_right;
	Animation* current_coin_mid;
	SDL_Rect* r_coin_left;
	SDL_Rect* r_coin_right;
	SDL_Rect* r_coin_mid;

private:
	void CreateBall(float diameter, int x, int y);
	void DestroyBall();
	void CreateSpring();
	void CreateFlippers();
	void CreateRotatingPokemons();
	void CreateShark();
	void CreateCave();
	void CreateAboveLayer();
	void CreateAboveStuff();
	void CreateDistanceJoints();

	void BlitRotatingPokemons();
	void BlitSpring();
	void BlitFlippers();
	void BlitShark();
	void BlitCave();
	void BlitCoins();
	void BlitAboveLayer();

	void ChangeAboveLayer();
	void UpdateSpring();
	void UpdateShark();
	void UpdateCave();
	void UpdateDoor();

	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);
	void UpdateCamera();

	//Get sprites
	void GetBallSprites(float angle, Ball* ball_properties); //Ball
	void GetFlipperSprites(float angle, SDL_Rect* &flipper_sprite, bool left); //Flipper

public:
	void CreatePokemonCave();
	void SetGeneralParameters();

public:
	PhysBody* ball;
	int life;

};