#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleMenuScene.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"

#include "Box2D/Box2D/Box2D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	rotating_pokemons.PushBack({ 171, 777, 25, 20 });
	rotating_pokemons.PushBack({ 198, 775, 23, 22 });
	rotating_pokemons.speed = 0.02f;

	rotating_pokemons_hit1.PushBack({ 223, 772, 28, 25 });
	rotating_pokemons_hit1.PushBack({ 253, 772, 28, 25 });
	rotating_pokemons_hit1.speed = 0.02f;

	rotating_pokemons_hit2.PushBack({ 253, 772, 28, 25 });
	rotating_pokemons_hit2.PushBack({ 223, 772, 28, 25 });
	rotating_pokemons_hit2.speed = 0.02f;

	red_spring.PushBack({ 92, 810, 20, 40 });
	red_spring.PushBack({ 114, 810, 20, 40 });
	red_spring.PushBack({ 136, 810, 20, 40 });
	red_spring.speed = 0.3f;

	grey_spring.PushBack({ 4, 810, 20, 40 });
	grey_spring.PushBack({ 26, 810, 20, 40 });
	grey_spring.speed = 0.06f;

	start_spring.PushBack({ 48, 810, 20, 40 });
	start_spring.PushBack({ 70, 810, 20, 40 });
	start_spring.speed = 0.2f;
	start_spring.loop = false;

	end_spring.PushBack({ 70, 810, 20, 40 });
	end_spring.PushBack({ 48, 810, 20, 40 });
	end_spring.PushBack({ 4, 810, 20, 40 });
	end_spring.PushBack({ 26, 810, 20, 40 });
	end_spring.speed = 0.3f;
	end_spring.loop = false;

	//Shark
	idle_shark.PushBack({ 146, 932, 36, 42 });
	idle_shark.PushBack({ 184, 932, 36, 42 });
	idle_shark.speed = 0.05f;

	eat_shark.PushBack({ 222, 932, 36, 42 });
	eat_shark.PushBack({ 184, 932, 36, 42 });
	eat_shark.PushBack({ 146, 932, 36, 42 });
	eat_shark.speed = 0.1f;
	eat_shark.loop = false;

	go_back_shark.PushBack({ 146, 932, 36, 42 });
	go_back_shark.PushBack({ 146, 932, 36, 42 });
	go_back_shark.PushBack({ 146, 932, 36, 42 });
	go_back_shark.speed = 0.07f;
	go_back_shark.loop = false;

	spit_shark.PushBack({ 146, 932, 36, 42 });
	spit_shark.PushBack({ 184, 932, 36, 42 });
	spit_shark.PushBack({ 222, 932, 36, 42 });
	spit_shark.PushBack({ 184, 932, 36, 42 });
	spit_shark.speed = 0.1f;
	spit_shark.loop = false;

	//Cave
	idle_cave.PushBack({ 184, 867, 41, 44 });
	idle_cave.speed = 0.1f;
	idle_cave.loop = false;

	wait_cave.PushBack({ 184, 867, 41, 44 });
	wait_cave.PushBack({ 184, 867, 41, 44 });
	wait_cave.PushBack({ 184, 867, 41, 44 });
	wait_cave.PushBack({ 184, 867, 41, 44 });
	wait_cave.speed = 0.06f;
	wait_cave.loop = false;

	jump_cave.PushBack({ 227, 867, 41, 44 });
	jump_cave.PushBack({ 270, 867, 41, 44 });
	jump_cave.PushBack({ 184, 867, 41, 44 });
	jump_cave.speed = 0.1f;
	jump_cave.loop = false;

	red_cave.PushBack({ 184, 867, 41, 44 });
	red_cave.PushBack({ 319, 867, 41, 44 });
	red_cave.PushBack({ 362, 867, 41, 44 });
	red_cave.PushBack({ 405, 867, 41, 44 });
	red_cave.PushBack({ 362, 867, 41, 44 });
	red_cave.PushBack({ 319, 867, 41, 44 });
	red_cave.speed = 0.08f;

	to_idle_cave.PushBack({ 362, 867, 41, 44 });
	to_idle_cave.PushBack({ 319, 867, 41, 44 });
	to_idle_cave.PushBack({ 270, 867, 47, 44 });
	to_idle_cave.PushBack({ 227, 867, 41, 44 });
	to_idle_cave.PushBack({ 184, 867, 41, 44 });
	to_idle_cave.speed = 0.1f;
	to_idle_cave.loop = false;

	//Egg
	idle_egg.PushBack({ 327, 1438, 16, 19 });
	idle_egg.speed = 0.1f;
	idle_egg.loop = false;

	jump1_egg.PushBack({ 327, 1438, 16, 23 });
	jump1_egg.PushBack({ 327, 1438, 16, 27 });
	jump1_egg.PushBack({ 327, 1438, 16, 31 });
	jump1_egg.PushBack({ 327, 1438, 16, 35 });
	jump1_egg.speed = 0.1f;
	jump1_egg.loop = false;

	jump2_egg.PushBack({ 327, 1438, 16, 31 });
	jump2_egg.PushBack({ 327, 1438, 16, 27 });
	jump2_egg.PushBack({ 327, 1438, 16, 23 });
	jump2_egg.PushBack({ 327, 1438, 16, 19 });
	jump2_egg.speed = 0.1f;
	jump2_egg.loop = false;

	break_egg1.PushBack({ 327, 1438, 16, 19 });
	break_egg1.PushBack({ 327, 1438, 16, 19 });
	break_egg1.PushBack({ 327, 1438, 16, 19 });
	break_egg1.PushBack({ 327, 1438, 16, 19 });
	break_egg1.PushBack({ 345, 1438, 16, 19 });
	break_egg1.PushBack({ 363, 1438, 16, 19 });
	break_egg1.PushBack({ 345, 1438, 16, 19 });
	break_egg1.PushBack({ 363, 1438, 16, 19 });
	break_egg1.PushBack({ 327, 1438, 16, 19 });
	break_egg1.PushBack({ 327, 1438, 16, 19 });
	break_egg1.PushBack({ 327, 1438, 16, 19 });
	break_egg1.PushBack({ 327, 1438, 16, 19 });
	break_egg1.PushBack({ 327, 1438, 16, 19 });
	break_egg1.PushBack({ 327, 1438, 16, 19 });
	break_egg1.speed = 0.1f;
	break_egg1.loop = false;

	break_egg2.PushBack({ 345, 1438, 16, 19 });
	break_egg2.PushBack({ 363, 1438, 16, 19 });
	break_egg2.PushBack({ 345, 1438, 16, 19 });
	break_egg2.PushBack({ 363, 1438, 16, 19 });
	break_egg2.PushBack({ 327, 1438, 16, 19 });
	break_egg2.PushBack({ 327, 1438, 16, 19 });
	break_egg2.PushBack({ 327, 1438, 16, 19 });
	break_egg2.PushBack({ 327, 1438, 16, 19 });
	break_egg2.PushBack({ 381, 1438, 16, 19 });
	break_egg2.PushBack({ 381, 1438, 16, 19 });
	break_egg2.PushBack({ 399, 1438, 18, 19 });
	break_egg2.PushBack({ 399, 1438, 18, 19 });
	break_egg2.PushBack({ 399, 1438, 18, 19 });
	break_egg2.PushBack({ 399, 1438, 18, 19 });
	break_egg2.PushBack({ 419, 1438, 45, 19 });
	break_egg2.PushBack({ 419, 1438, 45, 19 });
	break_egg2.PushBack({ 419, 1438, 45, 19 });
	break_egg2.PushBack({ 419, 1438, 45, 19 });
	break_egg2.PushBack({ 419, 1438, 45, 19 });
	break_egg2.PushBack({ 466, 1438, 19, 19 });
	break_egg2.PushBack({ 466, 1438, 19, 19 });
	break_egg2.PushBack({ 466, 1438, 19, 19 });
	break_egg2.PushBack({ 466, 1438, 19, 19 });
	break_egg2.speed = 0.1f;
	break_egg2.loop = false;

	//Pokemon cave
	idle_pokemon_cave.PushBack({ 36, 873, 30, 38 });
	idle_pokemon_cave.PushBack({ 68, 873, 30, 38 });
	idle_pokemon_cave.PushBack({ 100, 873, 30, 38 });
	idle_pokemon_cave.PushBack({ 132, 873, 30, 38 });
	idle_pokemon_cave.speed = 0.1f;

	go_back_pokemon_cave.PushBack({ 36, 873, 30, 38 });
	go_back_pokemon_cave.PushBack({ 68, 873, 30, 38 });
	go_back_pokemon_cave.PushBack({ 100, 873, 30, 38 });
	go_back_pokemon_cave.PushBack({ 132, 873, 30, 38 });
	go_back_pokemon_cave.PushBack({ 36, 873, 30, 38 });
	go_back_pokemon_cave.PushBack({ 68, 873, 30, 38 });
	go_back_pokemon_cave.PushBack({ 100, 873, 30, 38 });
	go_back_pokemon_cave.PushBack({ 132, 873, 30, 38 });
	go_back_pokemon_cave.speed = 0.1f;
	go_back_pokemon_cave.loop = false;

	almost_in_pokemon_cave.PushBack({ 164, 873, 18, 38 });
	almost_in_pokemon_cave.PushBack({ 164, 873, 18, 38 });
	almost_in_pokemon_cave.PushBack({ 164, 873, 18, 38 });
	almost_in_pokemon_cave.PushBack({ 164, 873, 18, 38 });
	almost_in_pokemon_cave.PushBack({ 164, 873, 18, 38 });
	almost_in_pokemon_cave.speed = 0.05f;
	almost_in_pokemon_cave.loop = false;

	disappear_pokemon_cave.PushBack({ 164, 873, 18, 38 });
	disappear_pokemon_cave.PushBack({ 164, 873, 18, 38 });
	disappear_pokemon_cave.PushBack({ 164, 873, 18, 38 });
	disappear_pokemon_cave.PushBack({ 164, 873, 18, 38 });
	disappear_pokemon_cave.PushBack({ 164, 873, 18, 38 });
	disappear_pokemon_cave.speed = 0.05f;
	disappear_pokemon_cave.loop = false;

	in_pokemon_cave.PushBack({ 164, 873, 18, 38 });
	in_pokemon_cave.speed = 0.1f;
	in_pokemon_cave.loop = false;

	//Pokémon mart-center
	pokemon_mart_center.PushBack({ 299, 376, 64, 40 });
	pokemon_mart_center.PushBack({ 369, 376, 64, 40 });
	pokemon_mart_center.PushBack({ 446, 376, 64, 40 });
	pokemon_mart_center.PushBack({ 299, 419, 64, 40 });
	pokemon_mart_center.PushBack({ 369, 419, 64, 40 });
	pokemon_mart_center.PushBack({ 446, 419, 64, 40 });
	pokemon_mart_center.speed = 0.08f;

	//Coin
	coin_idle.PushBack({ 639, 1049, 15, 15 });
	coin_idle.PushBack({ 667, 1049, 15, 15 });
	coin_idle.PushBack({ 695, 1049, 15, 15 });
	coin_idle.speed = 0.06f;

	coin_picked.PushBack({ 639, 1049, 15, 15 });
	coin_picked.PushBack({ 667, 1049, 15, 15 });
	coin_picked.PushBack({ 695, 1049, 15, 15 });
	coin_picked.PushBack({ 667, 1049, 15, 15 });
	coin_picked.PushBack({ 639, 1049, 15, 15 });
	coin_picked.PushBack({ 667, 1049, 15, 15 });
	coin_picked.PushBack({ 695, 1049, 15, 15 });
	coin_picked.PushBack({ 639, 1049, 15, 15 });
	coin_picked.PushBack({ 667, 1049, 15, 15 });
	coin_picked.PushBack({ 695, 1049, 15, 15 });
	coin_picked.PushBack({ 639, 1049, 15, 15 });
	coin_picked.PushBack({ 667, 1049, 15, 15 });
	coin_picked.PushBack({ 695, 1049, 15, 15 });
	coin_picked.PushBack({ 639, 1049, 15, 15 });
	coin_picked.PushBack({ 667, 1049, 15, 15 });
	coin_picked.PushBack({ 695, 1049, 15, 15 });
	coin_picked.speed = 0.3f;
	coin_picked.loop = false;

	//Door
	idle_door.PushBack({ 323, 331, 24, 27 });
	idle_door.speed = 0.1f;

	opening_door.PushBack({ 323, 331, 24, 27 });
	opening_door.PushBack({ 349, 331, 24, 27 });
	opening_door.PushBack({ 375, 331, 24, 27 });
	opening_door.PushBack({ 401, 331, 24, 27 });
	opening_door.speed = 0.05f;
	opening_door.loop = false;

	closing_door.PushBack({ 401, 331, 24, 27 });
	closing_door.PushBack({ 375, 331, 24, 27 });
	closing_door.PushBack({ 349, 331, 24, 27 });
	closing_door.PushBack({ 323, 331, 24, 27 });
	closing_door.speed = 0.05f;
	closing_door.loop = false;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player...");

	pokeball = App->textures->Load("Assets/Sprites/Pokeball&more.png");

	// Player general parameters
	SetGeneralParameters();

	// Create flippers
	CreateFlippers();

	// Create rotating pokémons
	CreateRotatingPokemons();

	// Create ball
	CreateBall(ball_diameter, start_ball.x, start_ball.y);

	// Create spring
	CreateSpring();

	// Create shark
	CreateShark();

	// Create cave
	CreateCave();

	// Create pokémon that lives in the cave
	CreatePokemonCave();

	// Create above layer
	CreateAboveLayer();

	// Set above stuff
	CreateAboveStuff();

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(pokeball);

	if (ball != nullptr) {
		App->physics->world->DestroyBody(ball->body);
	}

	if (ball_properties != nullptr) {
		delete ball_properties;
	}
	ball_properties = nullptr;

	return true;
}

// Update
update_status ModulePlayer::Update()
{
	CreateDistanceJoints();

	// Update Rotating pokémons (as motors)
	pokemonsRevoluteJoint[0]->SetMotorSpeed(cosf(0.5f * 2));
	pokemonsRevoluteJoint[1]->SetMotorSpeed(cosf(0.5f * 2));
	pokemonsRevoluteJoint[2]->SetMotorSpeed(cosf(0.5f * 2));

	if (App->menu_scene->menuEnum == null_) { //player can do things

		// Update Flippers
		if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
			flipperRevoluteJoints[0]->GetBodyA()->ApplyAngularImpulse(-0.1f, true);

		if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
			flipperRevoluteJoints[1]->GetBodyA()->ApplyAngularImpulse(0.1f, true);

		if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN && App->scene_intro->impactCheck == 0) {
			if (App->scene_intro->indexPikachu == 0)
				App->scene_intro->indexPikachu = 1;
			else
				App->scene_intro->indexPikachu = 0;
		}

		if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN && App->scene_intro->impactCheck == 0) {
			if (App->scene_intro->indexPikachu == 0)
				App->scene_intro->indexPikachu = 1;
			else
				App->scene_intro->indexPikachu = 0;
		}

		// Create ball
		if (App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_DOWN && post_start > 0 && App->window->fullscreen == false) //this does not work in fullscreen mode
			CreateBall(ball_diameter, App->input->GetMouseX(), App->input->GetMouseY());

		// Create ball at start position (in case the ball gets stuck, etc.)
		if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN && post_start > 0) //respawn
			CreateBall(ball_diameter, start_ball.x, start_ball.y);

		// Destroy ball
		if (App->scene_intro->destroy_ball && ball != nullptr)
			DestroyBall();

		// Update Spring (distance joint)
		UpdateSpring();
	}

	// Update shark
	UpdateShark();

	// Update cave (+ egg, + pokémon cave)
	UpdateCave();

	// Update door
	UpdateDoor();

	// Change above layer
	ChangeAboveLayer();

	// All draw functions ------------------------------------------------------

	// Blit flippers
	BlitFlippers();

	// Blit rotating pokemons
	BlitRotatingPokemons();

	// Blit spring
	BlitSpring();

	// Blit above layer
	BlitAboveLayer();

	// Blit cave (+egg, + pokémon cave)
	BlitCave();

	// Blit shark
	BlitShark();

	// Blit coins (last thing to blit)
	BlitCoins();

	return UPDATE_CONTINUE;
}

void ModulePlayer::GetFlipperSprites(float angle, SDL_Rect* &flipper_sprite, bool left) {

	SDL_Rect* sprite = &l_f1;

	if (left) {
		if		(angle > 32.0f)						{ sprite = &l_f1; }
		else if (angle <= 32.0f && angle > 22.0f)	{ sprite = &l_f2; }
		else if (angle <= 22.0f && angle > 11.0f)	{ sprite = &l_f3; }
		else if (angle <= 11.0f && angle > -5.0f)	{ sprite = &l_f4; }
		else if (angle <= -5.0f && angle > -10.0f)	{ sprite = &l_f5; }
		else if (angle <= -10.0f)					{ sprite = &l_f6; }
	}
	else {
		if (angle < 150.0f)							{ sprite = &r_f1; }
		else if (angle >= 150.0f && angle < 160.0f) { sprite = &r_f2; }
		else if (angle >= 160.0f && angle < 170.0f) { sprite = &r_f3; }
		else if (angle >= 170.0f && angle < 186.0f) { sprite = &r_f4; }		
		else if (angle >= 186.0f && angle < 191.0f) { sprite = &r_f5; }
		else if (angle >= 191.0f)					{ sprite = &r_f6; }
	}

	flipper_sprite = sprite;
}

void ModulePlayer::GetBallSprites(float angle, Ball* ball_properties) {

	SDL_Rect* sprite = &pb1;
	int direction = 1;

	if (angle < 0)
		direction = -1;

	if (App->scene_intro->points < 500) {
		if (direction * fmodf(angle, 360) > 348.75f || direction * fmodf(angle, 360) <= 11.25f) { sprite = &pb1; }
		else if (direction * fmodf(angle, 360) > 11.25f && direction * fmodf(angle, 360) <= 33.75f) { sprite = &pb2; }
		else if (direction * fmodf(angle, 360) > 33.75f && direction * fmodf(angle, 360) <= 56.25f) { sprite = &pb3; }
		else if (direction * fmodf(angle, 360) > 56.25f && direction * fmodf(angle, 360) <= 78.75f) { sprite = &pb4; }
		else if (direction * fmodf(angle, 360) > 78.75f && direction * fmodf(angle, 360) <= 101.25f) { sprite = &pb5; }
		else if (direction * fmodf(angle, 360) > 101.25f && direction * fmodf(angle, 360) <= 123.75f) { sprite = &pb6; }
		else if (direction * fmodf(angle, 360) > 123.75f && direction * fmodf(angle, 360) <= 146.25f) { sprite = &pb7; }
		else if (direction * fmodf(angle, 360) > 146.25f && direction * fmodf(angle, 360) <= 168.75f) { sprite = &pb8; }
		else if (direction * fmodf(angle, 360) > 168.75f && direction * fmodf(angle, 360) <= 191.25f) { sprite = &pb9; }
		else if (direction * fmodf(angle, 360) > 191.25f && direction * fmodf(angle, 360) <= 213.75f) { sprite = &pb10; }
		else if (direction * fmodf(angle, 360) > 213.75f && direction * fmodf(angle, 360) <= 236.25f) { sprite = &pb11; }
		else if (direction * fmodf(angle, 360) > 236.25f && direction * fmodf(angle, 360) <= 258.75f) { sprite = &pb12; }
		else if (direction * fmodf(angle, 360) > 258.75f && direction * fmodf(angle, 360) <= 281.25f) { sprite = &pb13; }
		else if (direction * fmodf(angle, 360) > 281.25f && direction * fmodf(angle, 360) <= 303.75f) { sprite = &pb14; }
		else if (direction * fmodf(angle, 360) > 303.75f && direction * fmodf(angle, 360) <= 326.25f) { sprite = &pb15; }
		else if (direction * fmodf(angle, 360) > 326.25f && direction * fmodf(angle, 360) <= 348.75f) { sprite = &pb16; }
	}
	else if (App->scene_intro->points >= 500 && App->scene_intro->points < 1000) {
		if (direction * fmodf(angle, 360) > 348.75f || direction * fmodf(angle, 360) <= 11.25f) { sprite = &sb1; }
		else if (direction * fmodf(angle, 360) > 11.25f && direction * fmodf(angle, 360) <= 33.75f) { sprite = &sb2; }
		else if (direction * fmodf(angle, 360) > 33.75f && direction * fmodf(angle, 360) <= 56.25f) { sprite = &sb3; }
		else if (direction * fmodf(angle, 360) > 56.25f && direction * fmodf(angle, 360) <= 78.75f) { sprite = &sb4; }
		else if (direction * fmodf(angle, 360) > 78.75f && direction * fmodf(angle, 360) <= 101.25f) { sprite = &sb5; }
		else if (direction * fmodf(angle, 360) > 101.25f && direction * fmodf(angle, 360) <= 123.75f) { sprite = &sb6; }
		else if (direction * fmodf(angle, 360) > 123.75f && direction * fmodf(angle, 360) <= 146.25f) { sprite = &sb7; }
		else if (direction * fmodf(angle, 360) > 146.25f && direction * fmodf(angle, 360) <= 168.75f) { sprite = &sb8; }
		else if (direction * fmodf(angle, 360) > 168.75f && direction * fmodf(angle, 360) <= 191.25f) { sprite = &sb9; }
		else if (direction * fmodf(angle, 360) > 191.25f && direction * fmodf(angle, 360) <= 213.75f) { sprite = &sb10; }
		else if (direction * fmodf(angle, 360) > 213.75f && direction * fmodf(angle, 360) <= 236.25f) { sprite = &sb11; }
		else if (direction * fmodf(angle, 360) > 236.25f && direction * fmodf(angle, 360) <= 258.75f) { sprite = &sb12; }
		else if (direction * fmodf(angle, 360) > 258.75f && direction * fmodf(angle, 360) <= 281.25f) { sprite = &sb13; }
		else if (direction * fmodf(angle, 360) > 281.25f && direction * fmodf(angle, 360) <= 303.75f) { sprite = &sb14; }
		else if (direction * fmodf(angle, 360) > 303.75f && direction * fmodf(angle, 360) <= 326.25f) { sprite = &sb15; }
		else if (direction * fmodf(angle, 360) > 326.25f && direction * fmodf(angle, 360) <= 348.75f) { sprite = &sb16; }
	}
	else if (App->scene_intro->points >= 1000 && App->scene_intro->points < 1500) {
		if (direction * fmodf(angle, 360) > 348.75f || direction * fmodf(angle, 360) <= 11.25f) { sprite = &ub1; }
		else if (direction * fmodf(angle, 360) > 11.25f && direction * fmodf(angle, 360) <= 33.75f) { sprite = &ub2; }
		else if (direction * fmodf(angle, 360) > 33.75f && direction * fmodf(angle, 360) <= 56.25f) { sprite = &ub3; }
		else if (direction * fmodf(angle, 360) > 56.25f && direction * fmodf(angle, 360) <= 78.75f) { sprite = &ub4; }
		else if (direction * fmodf(angle, 360) > 78.75f && direction * fmodf(angle, 360) <= 101.25f) { sprite = &ub5; }
		else if (direction * fmodf(angle, 360) > 101.25f && direction * fmodf(angle, 360) <= 123.75f) { sprite = &ub6; }
		else if (direction * fmodf(angle, 360) > 123.75f && direction * fmodf(angle, 360) <= 146.25f) { sprite = &ub7; }
		else if (direction * fmodf(angle, 360) > 146.25f && direction * fmodf(angle, 360) <= 168.75f) { sprite = &ub8; }
		else if (direction * fmodf(angle, 360) > 168.75f && direction * fmodf(angle, 360) <= 191.25f) { sprite = &ub9; }
		else if (direction * fmodf(angle, 360) > 191.25f && direction * fmodf(angle, 360) <= 213.75f) { sprite = &ub10; }
		else if (direction * fmodf(angle, 360) > 213.75f && direction * fmodf(angle, 360) <= 236.25f) { sprite = &ub11; }
		else if (direction * fmodf(angle, 360) > 236.25f && direction * fmodf(angle, 360) <= 258.75f) { sprite = &ub12; }
		else if (direction * fmodf(angle, 360) > 258.75f && direction * fmodf(angle, 360) <= 281.25f) { sprite = &ub13; }
		else if (direction * fmodf(angle, 360) > 281.25f && direction * fmodf(angle, 360) <= 303.75f) { sprite = &ub14; }
		else if (direction * fmodf(angle, 360) > 303.75f && direction * fmodf(angle, 360) <= 326.25f) { sprite = &ub15; }
		else if (direction * fmodf(angle, 360) > 326.25f && direction * fmodf(angle, 360) <= 348.75f) { sprite = &ub16; }
	}
	else if (App->scene_intro->points >= 1500) {
		if (direction * fmodf(angle, 360) > 348.75f || direction * fmodf(angle, 360) <= 11.25f) { sprite = &mb1; }
		else if (direction * fmodf(angle, 360) > 11.25f && direction * fmodf(angle, 360) <= 33.75f) { sprite = &mb2; }
		else if (direction * fmodf(angle, 360) > 33.75f && direction * fmodf(angle, 360) <= 56.25f) { sprite = &mb3; }
		else if (direction * fmodf(angle, 360) > 56.25f && direction * fmodf(angle, 360) <= 78.75f) { sprite = &mb4; }
		else if (direction * fmodf(angle, 360) > 78.75f && direction * fmodf(angle, 360) <= 101.25f) { sprite = &mb5; }
		else if (direction * fmodf(angle, 360) > 101.25f && direction * fmodf(angle, 360) <= 123.75f) { sprite = &mb6; }
		else if (direction * fmodf(angle, 360) > 123.75f && direction * fmodf(angle, 360) <= 146.25f) { sprite = &mb7; }
		else if (direction * fmodf(angle, 360) > 146.25f && direction * fmodf(angle, 360) <= 168.75f) { sprite = &mb8; }
		else if (direction * fmodf(angle, 360) > 168.75f && direction * fmodf(angle, 360) <= 191.25f) { sprite = &mb9; }
		else if (direction * fmodf(angle, 360) > 191.25f && direction * fmodf(angle, 360) <= 213.75f) { sprite = &mb10; }
		else if (direction * fmodf(angle, 360) > 213.75f && direction * fmodf(angle, 360) <= 236.25f) { sprite = &mb11; }
		else if (direction * fmodf(angle, 360) > 236.25f && direction * fmodf(angle, 360) <= 258.75f) { sprite = &mb12; }
		else if (direction * fmodf(angle, 360) > 258.75f && direction * fmodf(angle, 360) <= 281.25f) { sprite = &mb13; }
		else if (direction * fmodf(angle, 360) > 281.25f && direction * fmodf(angle, 360) <= 303.75f) { sprite = &mb14; }
		else if (direction * fmodf(angle, 360) > 303.75f && direction * fmodf(angle, 360) <= 326.25f) { sprite = &mb15; }
		else if (direction * fmodf(angle, 360) > 326.25f && direction * fmodf(angle, 360) <= 348.75f) { sprite = &mb16; }
	}

	if (ball_properties != nullptr)
		ball_properties->current_sprite = sprite;
}

void ModulePlayer::CreateBall(float diameter, int x, int y) {
	// Destroy last ball (in case it exists)
	if (ball != nullptr) {
		App->physics->world->DestroyBody(ball->body);

		if (ball_properties != nullptr) {
			delete ball_properties;
		}
		ball_properties = nullptr;
	}

	// Create class PhysBody ball
	ball = App->physics->CreateCircle(x, y, diameter);
	ball->body->SetBullet(true); //ball is a fast moving object, so it can be labeled as bullet
	ball->body->GetFixtureList()->SetDensity(0.4f);

	ball->listener = this;

	b2Filter f;
	f.categoryBits = BALL;
	f.maskBits = FLIPPER | WALL;
	ball->body->GetFixtureList()->SetFilterData(f);

	// Create struct Ball ball
	ball_properties = new Ball();
}

void ModulePlayer::DestroyBall() {
	App->physics->world->DestroyBody(ball->body);
	ball = nullptr;

	if (ball_properties != nullptr) {
		delete ball_properties;
	}
	ball_properties = nullptr;

	if (life > 0)
		CreateBall(ball_diameter, start_ball.x, start_ball.y);

	App->scene_intro->destroy_ball = false;
}

void ModulePlayer::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{
	// Rotating pokémons hit
	p1 = false;
	p2 = false;
	p3 = false;

	if (bodyB->body == App->player->ball->body && bodyA->body == rotatingPokemons[1]->body || bodyA->body == App->player->ball->body && bodyB->body == rotatingPokemons[1]->body)
	{
		App->scene_intro->points += 10;
		p1 = true;
	}
	if (bodyB->body == App->player->ball->body && bodyA->body == rotatingPokemons[2]->body || bodyA->body == App->player->ball->body && bodyB->body == rotatingPokemons[2]->body)
	{
		App->scene_intro->points += 10;
		p2 = true;
	}
	if (bodyB->body == App->player->ball->body && bodyA->body == rotatingPokemons[3]->body || bodyA->body == App->player->ball->body && bodyB->body == rotatingPokemons[3]->body)
	{
		App->scene_intro->points += 10;
		p3 = true;
	}

	// Cave
	if (bodyB->body == App->player->ball->body && bodyA->body == cave->body || bodyA->body == App->player->ball->body && bodyB->body == cave->body) {
		num_cave_hits++;
		cave_hit = true;
		App->scene_intro->points += 100;
	}
	// Pokémon cave
	if (pokemon_cave != nullptr) {
		if (bodyB->body == App->player->ball->body && bodyA->body == pokemon_cave->body || bodyA->body == App->player->ball->body && bodyB->body == pokemon_cave->body) {
			pokemon_cave_hit = true;
			App->scene_intro->points += 10;
		}
	}
	if (pokemon_cave1 != nullptr) {
		if (bodyB->body == App->player->ball->body && bodyA->body == pokemon_cave1->body || bodyA->body == App->player->ball->body && bodyB->body == pokemon_cave1->body) {
			pokemon_cave1_hit = true;
			App->scene_intro->points += 50;
		}
	}
	// Shark
	if (bodyB->body == App->player->ball->body && bodyA->body == shark->body || bodyA->body == App->player->ball->body && bodyB->body == shark->body) {
		shark_hit = true;
		App->scene_intro->points += 100;
	}

	//Above sensors
	if (bodyB->body == App->player->ball->body && bodyA->body == left_sensor_above->body || bodyA->body == App->player->ball->body && bodyB->body == left_sensor_above->body
		|| bodyB->body == App->player->ball->body && bodyA->body == right_sensor_above->body || bodyA->body == App->player->ball->body && bodyB->body == right_sensor_above->body) {
		enable_above = true;
	}
	if (bodyB->body == App->player->ball->body && bodyA->body == not_above_left->body || bodyA->body == App->player->ball->body && bodyB->body == not_above_left->body
		|| bodyB->body == App->player->ball->body && bodyA->body == not_above_right->body || bodyA->body == App->player->ball->body && bodyB->body == not_above_right->body) {
		disable_above = true;
	}

	//Coins
	if (bodyB->body == App->player->ball->body && bodyA->body == coin_left->body || bodyA->body == App->player->ball->body && bodyB->body == coin_left->body) {
		current_coin_left = &coin_picked;
		App->scene_intro->points += 500;
	}
	if (bodyB->body == App->player->ball->body && bodyA->body == coin_right->body || bodyA->body == App->player->ball->body && bodyB->body == coin_right->body) {
		current_coin_right = &coin_picked;
		App->scene_intro->points += 500;
	}
	if (bodyB->body == App->player->ball->body && bodyA->body == coin_mid->body || bodyA->body == App->player->ball->body && bodyB->body == coin_mid->body) {
		current_coin_mid = &coin_picked;
		App->scene_intro->points += 500;
	}

	//Door
	if (bodyB->body == App->player->ball->body && bodyA->body == door->body || bodyA->body == App->player->ball->body && bodyB->body == door->body) {
		door_hit = true;
		App->scene_intro->points += 500;
	}
}

void ModulePlayer::UpdateCamera() {

}

void ModulePlayer::CreatePokemonCave() {
	float diameter = 22.0f;
	b2Filter f;
	f.categoryBits = FLIPPER;
	f.maskBits = BALL;

	if (pokemon_cave == nullptr) {
		pokemon_cave = App->physics->CreateCircle(92, 180, diameter, b2_staticBody);
		pokemon_cave->body->GetFixtureList()->SetRestitution(2.0f);
		pokemon_cave->listener = this;

		pokemon_cave->body->GetFixtureList()->SetFilterData(f);
	}
	if (pokemon_cave1 == nullptr) {
		diameter = 26.0f;
		pokemon_cave1 = App->physics->CreateCircle(90, 150, diameter, b2_staticBody);
		pokemon_cave1->body->GetFixtureList()->SetRestitution(2.0f);
		pokemon_cave1->listener = this;

		pokemon_cave1->body->GetFixtureList()->SetFilterData(f);
	}
}

void ModulePlayer::CreateSpring() {
	PhysBody* spring_anchor = App->physics->CreateRectangle(243, 392, 10, 10, b2_staticBody);
	PhysBody* spring = App->physics->CreateRectangle(243, 375, 10, 10);

	b2Filter f;
	f.categoryBits = FLIPPER;
	f.maskBits = BALL | WALL | FLIPPER;
	spring->body->GetFixtureList()->SetFilterData(f);
	spring_anchor->body->GetFixtureList()->SetFilterData(f);

	springDistanceJoint = App->physics->CreateDistanceJoint(spring->body, spring_anchor->body);
	springPrismaticJoint = App->physics->CreateSpringPrismaticJoint(spring->body, spring_anchor->body);
	springDistanceJoint->SetDampingRatio(0.5f);
	springDistanceJoint->SetFrequency(4.0f);
}

void ModulePlayer::CreateFlippers() {
	b2Vec2 flipper_vertices[8];
	flipper_vertices[0].Set(10, 11);
	flipper_vertices[1].Set(21, 10);
	flipper_vertices[2].Set(30, 8);
	flipper_vertices[3].Set(29, 3);
	flipper_vertices[4].Set(19, 2);
	flipper_vertices[5].Set(4, 1);
	flipper_vertices[6].Set(0, 5);
	flipper_vertices[7].Set(3, 11);

	for (int i = 0; i < 8; i++) {
		flipper_vertices[i].x = PIXEL_TO_METERS(flipper_vertices[i].x);
		flipper_vertices[i].y = PIXEL_TO_METERS(flipper_vertices[i].y);
	}

	flippers[0] = App->physics->CreateFlipper(flipper_vertices, 8, 32); //Left flipper 45
	flippers[1] = App->physics->CreateFlipper(flipper_vertices, 8, 192); //Right flipper 205

	flipperCircles[0] = App->physics->CreateCircle(90, 396, 6, b2_staticBody); //Left circle
	flipperCircles[1] = App->physics->CreateCircle(151, 396, 6, b2_staticBody); //Right circle

	flipperRevoluteJoints[0] = App->physics->CreateFlipperRevoluteJoint(flippers[0]->body, flipperCircles[0]->body, { 0.13f,0.12f }, 20, -32); //Left flipper revolute joint
	flipperRevoluteJoints[1] = App->physics->CreateFlipperRevoluteJoint(flippers[1]->body, flipperCircles[1]->body, { 0.13f,0.12f }, -150, -192); //Right flipper revolute joint

	flipper_sprite[0] = &l_f1; //Left
	flipper_sprite[1] = &r_f1; //Right

	b2Filter f;
	f.categoryBits = FLIPPER;
	f.maskBits = BALL;
	flippers[0]->body->GetFixtureList()->SetFilterData(f);
	flippers[1]->body->GetFixtureList()->SetFilterData(f);
}

void ModulePlayer::CreateRotatingPokemons() {
	rotatingPokemons[0] = App->physics->CreateCircle(147, 146, 40, b2_staticBody);
	rotatingPokemons[1] = App->physics->CreateCircle(0, 0, 15, b2_dynamicBody);
	rotatingPokemons[2] = App->physics->CreateCircle(0, 0, 15, b2_dynamicBody);
	rotatingPokemons[3] = App->physics->CreateCircle(0, 0, 15, b2_dynamicBody);

	rotatingPokemons[1]->body->SetLinearVelocity({ 0,0 });
	rotatingPokemons[2]->body->SetLinearVelocity({ 0,0 });
	rotatingPokemons[3]->body->SetLinearVelocity({ 0,0 });
	rotatingPokemons[1]->body->GetFixtureList()->SetRestitution(3.0f);
	rotatingPokemons[2]->body->GetFixtureList()->SetRestitution(3.0f);
	rotatingPokemons[3]->body->GetFixtureList()->SetRestitution(3.0f);

	pokemonsRevoluteJoint[0] = App->physics->CreatePokemonRevoluteJoint(rotatingPokemons[0]->body, rotatingPokemons[1]->body, { PIXEL_TO_METERS(20 * cosf(25 * DEGTORAD)), PIXEL_TO_METERS(20 * sinf(25 * DEGTORAD)) }); //Up
	pokemonsRevoluteJoint[1] = App->physics->CreatePokemonRevoluteJoint(rotatingPokemons[0]->body, rotatingPokemons[2]->body, { PIXEL_TO_METERS(20 * cosf(-50 * DEGTORAD)), PIXEL_TO_METERS(20 * sinf(-50 * DEGTORAD)) }); //Left
	pokemonsRevoluteJoint[2] = App->physics->CreatePokemonRevoluteJoint(rotatingPokemons[0]->body, rotatingPokemons[3]->body, { PIXEL_TO_METERS(20 * cosf(-130 * DEGTORAD)), PIXEL_TO_METERS(20 * sinf(-130 * DEGTORAD)) }); //Right

	b2Filter f;
	f.categoryBits = WALL;
	f.maskBits = BALL;
	rotatingPokemons[1]->body->GetFixtureList()->SetFilterData(f);
	rotatingPokemons[2]->body->GetFixtureList()->SetFilterData(f);
	rotatingPokemons[3]->body->GetFixtureList()->SetFilterData(f);
}

void ModulePlayer::CreateShark() {
	float diameter = 19.0f;
	shark = App->physics->CreateCircle(198, 206, diameter, b2_staticBody);
	shark->body->GetFixtureList()->SetSensor(true);

	shark->listener = this;

	b2Filter f;
	f.categoryBits = FLIPPER;
	f.maskBits = BALL;
	shark->body->GetFixtureList()->SetFilterData(f);
}

void ModulePlayer::CreateCave() {
	cave = App->physics->CreateRectangleSensor(90, 135, 30, 20);

	cave->listener = this;

	b2Filter f;
	f.categoryBits = FLIPPER;
	f.maskBits = BALL;
	cave->body->GetFixtureList()->SetFilterData(f);
}

void ModulePlayer::CreateAboveLayer() {
	int leftAb[66] = {
		318 - 275, 190,
		305 - 275, 176,
		298 - 275, 156,
		295 - 275, 128,
		301 - 275, 101,
		316 - 275, 84,
		334 - 275, 72,
		350 - 275, 66,
		358 - 275, 62,
		359 - 275, 47,
		349 - 275, 42,
		335 - 275, 45,
		316 - 275, 52,
		305 - 275, 60,
		288 - 275, 76,
		278 - 275, 98,
		272 - 275, 115,
		274 - 275, 150,
		280 - 275, 176,
		288 - 275, 192,
		298 - 275, 203,
		281 - 275, 212,
		257 - 275, 168,
		258 - 275, 80,
		318 - 275, 24,
		367 - 275, 29,
		366 - 275, 68,
		340 - 275, 83,
		317 - 275, 101,
		309 - 275, 136,
		322 - 275, 171,
		327 - 275, 183,
		320 - 275, 189
	};

	int rightAb[82] = {
		438 - 275, 225,
		466 - 275, 174,
		479 - 275, 150,
		488 - 275, 130,
		497 - 275, 100,
		502 - 275, 83,
		474 - 275, 79,
		474 - 275, 95,
		469 - 275, 116,
		466 - 275, 123,
		464 - 275, 110,
		458 - 275, 92,
		449 - 275, 76,
		433 - 275, 60,
		404 - 275, 45,
		389 - 275, 44,
		384 - 275, 52,
		384 - 275, 60,
		389 - 275, 65,
		398 - 275, 68,
		414 - 275, 75,
		429 - 275, 89,
		438 - 275, 102,
		444 - 275, 114,
		447 - 275, 131,
		448 - 275, 144,
		447 - 275, 159,
		436 - 275, 184,
		425 - 275, 206,
		417 - 275, 202,
		427 - 275, 141,
		411 - 275, 104,
		388 - 275, 75,
		378 - 275, 65,
		381 - 275, 38,
		403 - 275, 37,
		518 - 275, 70,
		507 - 275, 121,
		478 - 275, 204,
		448 - 275, 229,
		439 - 275, 226
	};

	left_above = App->physics->CreateChain(12, 2, leftAb, 66, b2_staticBody);
	right_above = App->physics->CreateChain(12, 2, rightAb, 82, b2_staticBody);
	left_sensor_above = App->physics->CreateRectangleSensor(37, 195, 10, 10);
	right_sensor_above = App->physics->CreateRectangleSensor(180, 200, 10, 10);
	not_above_left = App->physics->CreateRectangleSensor(63, 215, 10, 10);
	not_above_right = App->physics->CreateRectangleSensor(163, 230, 10, 10);

	left_above->listener = this;
	right_above->listener = this;
	left_sensor_above->listener = this;
	right_sensor_above->listener = this;
	not_above_left->listener = this;
	not_above_right->listener = this;

	b2Filter f;
	f.categoryBits = NEUTRAL;
	f.maskBits = BALL;

	left_above->body->GetFixtureList()->SetFilterData(f);
	right_above->body->GetFixtureList()->SetFilterData(f);

	f.categoryBits = FLIPPER;

	left_sensor_above->body->GetFixtureList()->SetFilterData(f);
	right_sensor_above->body->GetFixtureList()->SetFilterData(f);
	not_above_left->body->GetFixtureList()->SetFilterData(f);
	not_above_right->body->GetFixtureList()->SetFilterData(f);
}

void ModulePlayer::CreateAboveStuff() {
	//Coin
	float diameter = 13.0f;
	coin_left = App->physics->CreateCircle(74, 60, diameter, b2_staticBody);
	coin_right = App->physics->CreateCircle(140, 60, diameter, b2_staticBody);
	coin_mid = App->physics->CreateCircle(198, 150, diameter, b2_staticBody);
	coin_left->body->GetFixtureList()->SetSensor(true);
	coin_right->body->GetFixtureList()->SetSensor(true);
	coin_mid->body->GetFixtureList()->SetSensor(true);
	coin_left->listener = this;
	coin_right->listener = this;
	coin_mid->listener = this;

	b2Filter f;
	f.categoryBits = WALL;
	f.maskBits = BALL;
	coin_left->body->GetFixtureList()->SetFilterData(f);
	coin_right->body->GetFixtureList()->SetFilterData(f);
	coin_mid->body->GetFixtureList()->SetFilterData(f);

	//Door
	door = App->physics->CreateRectangleSensor(223, 90, 20, 25);
	door->listener = this;
	door->body->GetFixtureList()->SetFilterData(f);
}

void ModulePlayer::SetGeneralParameters() {
	// General parameters
	start_ball.x = 242;
	start_ball.y = 355;
	ball_diameter = 15.0f;
	life = 3;
	enable_above = false;
	disable_above = false;

	current_rotating_pokemons1 = &rotating_pokemons;
	current_rotating_pokemons2 = &rotating_pokemons;
	current_rotating_pokemons3 = &rotating_pokemons;
	current_mart_center = &pokemon_mart_center;
	current_door = &idle_door;
	current_pokemon_cave = &idle_pokemon_cave;
	current_egg = &idle_egg;
	current_cave = &idle_cave;
	current_shark = &idle_shark;
	current_coin_left = &coin_idle;
	current_coin_right = &coin_idle;
	current_coin_mid = &coin_idle;
	current_spring = &grey_spring;

	// Shark
	go_back1_x = 0;
	go_back1_y = 0;
	first_shark = true;

	// Cave (+ egg, + pokémon cave)
	go_back2_x = 0;
	go_back2_y = 0;
	go_back3_y = 0;
	num_cave_hits = 0;
	cave_hit = false;
	blit_ball = true;
	destroy_pokemon_cave = false;
	destroy_pokemon_cave1 = false;
	pokemon_cave_hit = false;
	pokemon_cave1_hit = false;
	go_forward = false;
	blit_pokemon_over_cave = true;
	blit_egg = true;
	blit_pokemon_cave = true;
	post_start = 0;

	//
	jump1_egg.Reset();
	jump2_egg.Reset();
	break_egg1.Reset();
	break_egg2.Reset();

	go_back_pokemon_cave.Reset();
	in_pokemon_cave.Reset();
	disappear_pokemon_cave.Reset();
	almost_in_pokemon_cave.Reset();
}

void ModulePlayer::BlitRotatingPokemons() {
	if (p1) {
		if (r_pokemons1->x == 171)
			current_rotating_pokemons1 = &rotating_pokemons_hit1;
		else if (r_pokemons1->x == 198)
			current_rotating_pokemons1 = &rotating_pokemons_hit2;
	}
	else {
		current_rotating_pokemons1 = &rotating_pokemons;
	}
	if (p2) {
		if (r_pokemons2->x == 171)
			current_rotating_pokemons2 = &rotating_pokemons_hit1;
		else if (r_pokemons2->x == 198)
			current_rotating_pokemons2 = &rotating_pokemons_hit2;
	}
	else {
		current_rotating_pokemons2 = &rotating_pokemons;
	}
	if (p3) {
		if (r_pokemons3->x == 171)
			current_rotating_pokemons3 = &rotating_pokemons_hit1;
		else if (r_pokemons3->x == 198)
			current_rotating_pokemons3 = &rotating_pokemons_hit2;
	}
	else {
		current_rotating_pokemons3 = &rotating_pokemons;
	}

	r_pokemons1 = &current_rotating_pokemons1->GetCurrentFrame();
	r_pokemons2 = &current_rotating_pokemons2->GetCurrentFrame();
	r_pokemons3 = &current_rotating_pokemons3->GetCurrentFrame();

	b2Vec2 pos_p1 = rotatingPokemons[1]->body->GetPosition();
	App->renderer->Blit(App->scene_intro->general, METERS_TO_PIXELS(pos_p1.x) - 12, METERS_TO_PIXELS(pos_p1.y) - 12, r_pokemons1);
	pos_p1 = rotatingPokemons[2]->body->GetPosition();
	App->renderer->Blit(App->scene_intro->general, METERS_TO_PIXELS(pos_p1.x) - 12, METERS_TO_PIXELS(pos_p1.y) - 12, r_pokemons2);
	pos_p1 = rotatingPokemons[3]->body->GetPosition();
	App->renderer->Blit(App->scene_intro->general, METERS_TO_PIXELS(pos_p1.x) - 12, METERS_TO_PIXELS(pos_p1.y) - 12, r_pokemons3);
}

void ModulePlayer::BlitSpring() {
	// Spring animation change
	if (end_spring.Finished() && spring_anim) {
		current_spring = &grey_spring;
		end_spring.Reset();
		spring_anim = false;
	}

	// Blit spring
	r_spring = &current_spring->GetCurrentFrame();
	b2Vec2 pos_spring = springDistanceJoint->GetBodyB()->GetPosition();
	App->renderer->Blit(App->scene_intro->general, 233, 370, r_spring);

	// Change spring position
	if (r_spring->x == 4)
		springDistanceJoint->GetBodyA()->ApplyForce({ 0, 0.0f }, { 0, 0 }, true);
	else if (r_spring->x == 26)
		springDistanceJoint->GetBodyA()->ApplyForce({ 0, -0.4f }, { 0, 0 }, true);
}

void ModulePlayer::BlitFlippers() {
	// Left
	b2Vec2 pos_l = flipperRevoluteJoints[0]->GetAnchorB();
	pos_l -= { 0.13f, 0.12f };
	double angle_l = flippers[0]->GetRotation();

	// Get sprite for the flipper
	GetFlipperSprites(angle_l, flipper_sprite[0], true);
	App->renderer->Blit(App->scene_intro->general, METERS_TO_PIXELS(pos_l.x), METERS_TO_PIXELS(pos_l.y) - 4, flipper_sprite[0]);

	// Right
	b2Vec2 pos_r = flipperRevoluteJoints[1]->GetAnchorB();
	pos_r -= { 0.13f, 0.12f };
	double angle_r = flippers[1]->GetRotation();

	// Get sprite for the flipper
	GetFlipperSprites(angle_r, flipper_sprite[1], false);
	App->renderer->Blit(App->scene_intro->general, METERS_TO_PIXELS(pos_r.x) - 18, METERS_TO_PIXELS(pos_r.y) - 4, flipper_sprite[1]);
}

void ModulePlayer::BlitShark() {
	r_shark = &current_shark->GetCurrentFrame();
	b2Vec2 pos_shark = shark->body->GetPosition();
	App->renderer->Blit(App->scene_intro->general, METERS_TO_PIXELS(pos_shark.x) - 18 + go_back1_x, METERS_TO_PIXELS(pos_shark.y) - 34 + go_back1_y, r_shark);
}

void ModulePlayer::BlitCave() {
	// Blit cave + pokémon cave
	r_cave = &current_cave->GetCurrentFrame();
	r_pokemon_cave = &current_pokemon_cave->GetCurrentFrame();
	b2Vec2 pos_cave = cave->body->GetPosition();

	if (blit_pokemon_over_cave) {
		App->renderer->Blit(App->scene_intro->general, METERS_TO_PIXELS(pos_cave.x) - 22, METERS_TO_PIXELS(pos_cave.y) - 36 + 5, r_cave);
		if (blit_pokemon_cave)
			App->renderer->Blit(App->scene_intro->general, 91 - 17 - 2 + go_back2_x, 180 - 15 - 15 + go_back2_y, r_pokemon_cave);
	}
	else {
		if (blit_pokemon_cave)
			App->renderer->Blit(App->scene_intro->general, 91 - 17 - 2 + go_back2_x, 180 - 15 - 15 + go_back2_y, r_pokemon_cave);
		App->renderer->Blit(App->scene_intro->general, METERS_TO_PIXELS(pos_cave.x) - 22, METERS_TO_PIXELS(pos_cave.y) - 36 + 5, r_cave);
	}

	// Blit egg
	r_egg = &current_egg->GetCurrentFrame();
	if (blit_egg) {
		if (r_egg->x == 419)
			App->renderer->Blit(App->scene_intro->general, METERS_TO_PIXELS(pos_cave.x) - 10 - 14, METERS_TO_PIXELS(pos_cave.y) - 41 + 5 + go_back3_y, r_egg);
		else if (r_egg->x == 399)
			App->renderer->Blit(App->scene_intro->general, METERS_TO_PIXELS(pos_cave.x) - 10 - 1, METERS_TO_PIXELS(pos_cave.y) - 41 + 5 + go_back3_y, r_egg);
		else
			App->renderer->Blit(App->scene_intro->general, METERS_TO_PIXELS(pos_cave.x) - 10, METERS_TO_PIXELS(pos_cave.y) - 41 + 5 + go_back3_y, r_egg);
	}
}

void ModulePlayer::BlitCoins() {
	if (coin_picked.Finished()) {
		current_coin_left = &coin_idle;
		current_coin_right = &coin_idle;
		current_coin_mid = &coin_idle;
		coin_picked.Reset();
	}

	//Blit coins
	r_coin_left = &current_coin_left->GetCurrentFrame();
	r_coin_right = &current_coin_right->GetCurrentFrame();
	r_coin_mid = &current_coin_mid->GetCurrentFrame();
	b2Vec2 pos_coin_left = coin_left->body->GetPosition();
	b2Vec2 pos_coin_right = coin_right->body->GetPosition();
	b2Vec2 pos_coin_mid = coin_mid->body->GetPosition();

	App->renderer->Blit(App->scene_intro->general, METERS_TO_PIXELS(pos_coin_left.x) - 8, METERS_TO_PIXELS(pos_coin_left.y) - 7, r_coin_left);
	App->renderer->Blit(App->scene_intro->general, METERS_TO_PIXELS(pos_coin_right.x) - 8, METERS_TO_PIXELS(pos_coin_right.y) - 7, r_coin_right);
	App->renderer->Blit(App->scene_intro->general, METERS_TO_PIXELS(pos_coin_mid.x) - 8, METERS_TO_PIXELS(pos_coin_mid.y) - 7, r_coin_mid);
}

void ModulePlayer::BlitAboveLayer() {
	if (enable_above) {
		// Blit above
		r_door = &current_door->GetCurrentFrame();
		App->renderer->Blit(App->scene_intro->general, 4, 4, &above);
		App->renderer->Blit(App->scene_intro->general, -5, 3, &above_details);
		// Blit ball
		if (ball != nullptr && ball_properties != nullptr && blit_ball) {
			int x, y;
			ball->GetPosition(x, y);
			float angle = ball->GetRotation();

			// Get sprite for the ball
			GetBallSprites(angle, ball_properties);

			// Blit bullet sprite
			if (angle < 0)
				App->renderer->Blit(pokeball, x, y, ball_properties->current_sprite);
			else
				App->renderer->Blit(pokeball, x, y, ball_properties->current_sprite, 1.0f, 0, INT_MAX, INT_MAX, SDL_FLIP_HORIZONTAL);
		}
	}
	else {
		// Blit ball
		if (ball != nullptr && ball_properties != nullptr && blit_ball) {
			int x, y;
			ball->GetPosition(x, y);
			float angle = ball->GetRotation();

			// Get sprite for the ball
			GetBallSprites(angle, ball_properties);

			// Blit bullet sprite
			if (angle < 0)
				App->renderer->Blit(pokeball, x, y, ball_properties->current_sprite);
			else
				App->renderer->Blit(pokeball, x, y, ball_properties->current_sprite, 1.0f, 0, INT_MAX, INT_MAX, SDL_FLIP_HORIZONTAL);
		}
		// Blit above
		r_door = &current_door->GetCurrentFrame();
		App->renderer->Blit(App->scene_intro->general, 4, 4, &above);
		App->renderer->Blit(App->scene_intro->general, -5, 3, &above_details);
	}

	// Blit pokémon mart-center
	App->renderer->Blit(App->scene_intro->general, 208, 72, r_door);

	r_mart_center = &current_mart_center->GetCurrentFrame();
	App->renderer->Blit(App->scene_intro->general, 181, 39, r_mart_center);
}

void ModulePlayer::ChangeAboveLayer() {
	if (enable_above) {
		b2Filter f;
		f.categoryBits = WALL;
		f.maskBits = BALL;
		left_above->body->GetFixtureList()->SetFilterData(f);
		right_above->body->GetFixtureList()->SetFilterData(f);

		//Change the collision of the rest of the walls
		f.categoryBits = NEUTRAL;

		App->scene_intro->map_chain1->body->GetFixtureList()->SetFilterData(f);
		App->scene_intro->map_chain2->body->GetFixtureList()->SetFilterData(f);
		App->scene_intro->map_chain3->body->GetFixtureList()->SetFilterData(f);
		App->scene_intro->map_chain4->body->GetFixtureList()->SetFilterData(f);
		App->scene_intro->map_chain5->body->GetFixtureList()->SetFilterData(f);
		App->scene_intro->map_chain6->body->GetFixtureList()->SetFilterData(f);
		App->scene_intro->map_chain7->body->GetFixtureList()->SetFilterData(f);
		App->scene_intro->map_chain8->body->GetFixtureList()->SetFilterData(f);
		//App->scene_intro->map_chain9->body->GetFixtureList()->SetFilterData(f);
		App->scene_intro->map_chain10->body->GetFixtureList()->SetFilterData(f);
		App->scene_intro->map_chain11->body->GetFixtureList()->SetFilterData(f);
	}
	if (disable_above) {
		b2Filter f;
		f.categoryBits = NEUTRAL;
		f.maskBits = BALL;
		left_above->body->GetFixtureList()->SetFilterData(f);
		right_above->body->GetFixtureList()->SetFilterData(f);

		//Rest of the walls back to normal collision
		f.categoryBits = WALL;

		App->scene_intro->map_chain1->body->GetFixtureList()->SetFilterData(f);
		App->scene_intro->map_chain2->body->GetFixtureList()->SetFilterData(f);
		App->scene_intro->map_chain3->body->GetFixtureList()->SetFilterData(f);
		App->scene_intro->map_chain4->body->GetFixtureList()->SetFilterData(f);
		App->scene_intro->map_chain5->body->GetFixtureList()->SetFilterData(f);
		App->scene_intro->map_chain6->body->GetFixtureList()->SetFilterData(f);
		App->scene_intro->map_chain7->body->GetFixtureList()->SetFilterData(f);
		App->scene_intro->map_chain8->body->GetFixtureList()->SetFilterData(f);
		//App->scene_intro->map_chain9->body->GetFixtureList()->SetFilterData(f);
		App->scene_intro->map_chain10->body->GetFixtureList()->SetFilterData(f);
		App->scene_intro->map_chain11->body->GetFixtureList()->SetFilterData(f);

		enable_above = false;
		disable_above = false;
	}
}

void ModulePlayer::UpdateSpring() {
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT) {
		if (post_start == 0)
			post_start = 1;

		// Animation change
		if (start_spring.Finished()) {
			current_spring = &red_spring;
		}
		else
			current_spring = &start_spring;
		//

		if (impulse.y < 15.0f)
			impulse.y += 0.5f;

		springDistanceJoint->GetBodyA()->ApplyForce(impulse, { 0, 0 }, true);
	}
	else if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_UP) {
		// Animation change
		current_spring = &end_spring;
		spring_anim = true;

		start_spring.Reset();
		red_spring.Reset();
		grey_spring.Reset();
		//

		impulse.y += 70.0f; //minimum impulse
		springDistanceJoint->GetBodyA()->ApplyForce(-impulse, { 0, 0 }, true);
		impulse = { 0,0 };
	}
}

void ModulePlayer::UpdateShark() {
	if (shark_hit) {
		//The shark goes back and spits out the ball
		blit_ball = false;
		ball->body->SetLinearVelocity({ 0,0 });
		ball->body->SetGravityScale(0);

		if (first_shark)
			current_shark = &eat_shark;

		if (eat_shark.Finished()) {
			first_shark = false;
			current_shark = &go_back_shark;

			go_back1_x += 0.1f;
			go_back1_y -= 0.2f;
		}
		if (go_back_shark.Finished()) {
			eat_shark.Reset();
			current_shark = &spit_shark;

			if (go_back1_x != 0)
				go_back1_x -= 0.2f;
			if (go_back1_y != 0)
				go_back1_y += 0.4f;
		}
		if (spit_shark.Finished()) {
			go_back_shark.Reset();
			current_shark = &idle_shark;

			ball->body->SetGravityScale(1);
			ball->body->ApplyForceToCenter({ -10, 10 }, true);
			blit_ball = true;

			spit_shark.Reset();
			shark_hit = false;
			first_shark = true;
		}
	}

	if (!shark_hit) {
		if (go_back1_x <= 0)
			go_back1_x += 0.1f;
		if (go_back1_y >= 0)
			go_back1_y -= 0.1f;
	}
}

void ModulePlayer::UpdateCave() {
	if (destroy_pokemon_cave) {
		if (pokemon_cave != nullptr)
			App->physics->world->DestroyBody(pokemon_cave->body);
		pokemon_cave = nullptr;
		destroy_pokemon_cave = false;
	}
	if (destroy_pokemon_cave1) {
		if (pokemon_cave1 != nullptr)
			App->physics->world->DestroyBody(pokemon_cave1->body);
		pokemon_cave1 = nullptr;
		destroy_pokemon_cave1 = false;
	}

	if (pokemon_cave_hit) {
		//Pokémon goes back
		current_pokemon_cave = &go_back_pokemon_cave;

		go_back2_x -= 0.02f;
		go_back2_y -= 0.3f;
	}
	if (go_back_pokemon_cave.Finished()) {
		go_back_pokemon_cave.Reset();
		destroy_pokemon_cave = true;
		pokemon_cave_hit = false;
	}
	//
	if (pokemon_cave1_hit) {
		//Pokémon goes inside the cave
		current_pokemon_cave = &almost_in_pokemon_cave;

		if (jump_cave.Finished())
			current_cave = &idle_cave;
		else
			current_cave = &jump_cave;

		if (jump2_egg.Finished())
			current_egg = &idle_egg;
		else {
			if (jump1_egg.Finished()) {
				current_egg = &jump2_egg;
				go_back3_y += 0.3f;
			}
			else {
				current_egg = &jump1_egg;
				go_back3_y -= 0.3f;
			}
		}

		blit_pokemon_over_cave = false;

		if (!go_forward) {
			go_back2_x += 10.0f;
			go_back2_y -= 16.0f;
			go_forward = true;
		}
		else {
			go_back2_y += 0.08f;
		}
	}
	if (almost_in_pokemon_cave.Finished()) {
		destroy_pokemon_cave1 = true;
		go_forward = false;
		pokemon_cave1_hit = false;
		current_pokemon_cave = &in_pokemon_cave;
		current_cave = &red_cave;

		almost_in_pokemon_cave.Reset();
		jump_cave.Reset();
		jump1_egg.Reset();
		jump2_egg.Reset();
	}
	//
	if ((num_cave_hits == 1 || num_cave_hits == 2) && cave_hit) {
		//The egg breaks and the player recieves some points
		current_cave = &to_idle_cave;
		current_pokemon_cave = &disappear_pokemon_cave;
		go_back2_y -= 0.3f;

		blit_ball = false;
		ball->body->SetLinearVelocity({ 0,0 });
		ball->body->SetGravityScale(0);

		if (jump2_egg.Finished())
			current_egg = &idle_egg;
		else {
			if (jump1_egg.Finished()) {
				current_egg = &jump2_egg;
				go_back3_y += 0.3f;
			}
			else {
				current_egg = &jump1_egg;
				go_back3_y -= 0.3f;
			}
		}
	}
	if (disappear_pokemon_cave.Finished()) {
		current_cave = &idle_cave;
		current_egg = &break_egg1;
		blit_pokemon_cave = false;

		to_idle_cave.Reset();
		disappear_pokemon_cave.Reset();
		jump1_egg.Reset();
		jump2_egg.Reset();
		cave_hit = false;
	}
	if (break_egg1.Finished()) {
		current_egg = &break_egg2;
	}
	if (break_egg2.Finished()) {
		current_egg = &idle_egg;
		break_egg1.Reset();
		break_egg2.Reset();
		blit_egg = false;

		if (ball != nullptr) {
			ball->body->SetGravityScale(1);
			ball->body->ApplyForceToCenter({ 10, 10 }, true);
			blit_ball = true;
		}
	}
	//
	if (num_cave_hits > 2 && cave_hit) {
		//The cave acts like the shark
		current_cave = &wait_cave;

		blit_ball = false;
		ball->body->SetLinearVelocity({ 0,0 });
		ball->body->SetGravityScale(0);
	}
	if (wait_cave.Finished()) {
		wait_cave.Reset();

		if (ball != nullptr) {
			ball->body->SetGravityScale(1);
			ball->body->ApplyForceToCenter({ 10, 10 }, true);
			blit_ball = true;
		}
		cave_hit = false;
	}
}

void ModulePlayer::UpdateDoor() {
	if (door_hit) {
		//The door acts like the shark
		current_door = &opening_door;

		blit_ball = false;
		ball->body->SetLinearVelocity({ 0,0 });
		ball->body->SetGravityScale(0);
	}
	if (opening_door.Finished()) {
		opening_door.Reset();
		current_door = &closing_door;

		if (ball != nullptr) {
			ball->body->SetGravityScale(1);
			ball->body->ApplyForceToCenter({ 10, 10 }, true);
			blit_ball = true;
		}
		door_hit = false;
	}
	if (closing_door.Finished()) {
		current_door = &idle_door;
		closing_door.Reset();
	}
}

void ModulePlayer::CreateDistanceJoints() {
	if (post_start == 1) {
		App->physics->CreateDistanceJoint(rotatingPokemons[1]->body, rotatingPokemons[2]->body);
		App->physics->CreateDistanceJoint(rotatingPokemons[2]->body, rotatingPokemons[3]->body);
		App->physics->CreateDistanceJoint(rotatingPokemons[3]->body, rotatingPokemons[1]->body);
		post_start = 2;
	}
}

