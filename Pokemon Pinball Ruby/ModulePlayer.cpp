#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleMenuScene.h"
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
	break_egg2.PushBack({ 345, 1438, 16, 19 });
	break_egg2.PushBack({ 363, 1438, 16, 19 });
	break_egg2.PushBack({ 345, 1438, 16, 19 });
	break_egg2.PushBack({ 363, 1438, 16, 19 });
	break_egg1.speed = 0.1f;
	break_egg1.loop = false;

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
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	/*
	TODOS:
	-Crear flippers(revolute joints), bola(HACER QUE bullet = true, para que chequee las colisiones más rápido.Solo usar esta función para la bola) (cuerpos dinámicos)
	·Función para los flippers: b2Body::ApplyAngularInputs(). TIENE QUE SER UN IMPULSO MUY FUERTE. Con 2 teclas.

	-Final de partida y puntuación. Que aparezca la score.

	-Taco que empuja la bola: crear objete con un muelle (con un joint). Hacer función de b2Body::ApplyForceToCenter (es una función del b2Body): se la puede llamar varias veces
	para que el objeto vaya tirando hacia atrás. TIENE QUE SER UN IMPULSO MÁS MODERADO. Con una tecla.
	*/

	LOG("Loading player...");
	LOG("Loading ball");
	LOG("Loading flippers");

	pokeball = App->textures->Load("Assets/Sprites/Pokeball&more.png");

	// Ball (player) general parameters
	start_ball.x = 242;
	start_ball.y = 355;
	ball_diameter = 15.0f;
	life = 3;
	num_cave_hits = 0;
	cave_hit = false;
	blit_ball = true;

	go_back1_x = 0;
	go_back1_y = 0;
	go_back2_x = 0;
	go_back2_y = 0;
	first_shark = true;
	destroy_pokemon_cave = false;
	destroy_pokemon_cave1 = false;
	pokemon_cave_hit = false;
	pokemon_cave1_hit = false;
	go_forward = false;
	blit_pokemon_over_cave = true;
	blit_egg = true;
	blit_pokemon_cave = true;

	// Create flippers
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

	flipperCircles[0] = App->physics->CreateCircle(90, 392, 6, b2_staticBody); //Left circle
	flipperCircles[1] = App->physics->CreateCircle(151, 392, 6, b2_staticBody); //Right circle

	flipperRevoluteJoints[0] = App->physics->CreateFlipperRevoluteJoint(flippers[0]->body, flipperCircles[0]->body, { 0.13f,0.12f }, 20, -32); //Left flipper revolute joint
	flipperRevoluteJoints[1] = App->physics->CreateFlipperRevoluteJoint(flippers[1]->body, flipperCircles[1]->body, { 0.13f,0.12f }, -150, -192); //Right flipper revolute joint

	flipper_sprite[0] = &l_f1; //Left
	flipper_sprite[1] = &r_f1; //Right

	b2Filter f;

	f.categoryBits = FLIPPER;
	f.maskBits = BALL;
	flippers[0]->body->GetFixtureList()->SetFilterData(f);
	flippers[1]->body->GetFixtureList()->SetFilterData(f);

	// Create rotating pokémons
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
	
	f.categoryBits = WALL;
	f.maskBits = BALL;
	rotatingPokemons[1]->body->GetFixtureList()->SetFilterData(f);
	rotatingPokemons[2]->body->GetFixtureList()->SetFilterData(f);
	rotatingPokemons[3]->body->GetFixtureList()->SetFilterData(f);

	current_rotating_pokemons1 = &rotating_pokemons;
	current_rotating_pokemons2 = &rotating_pokemons;
	current_rotating_pokemons3 = &rotating_pokemons;

	// Create ball
	CreateBall(ball_diameter, start_ball.x, start_ball.y);

	// Create spring
	PhysBody* spring_anchor = App->physics->CreateRectangle(243, 392, 10, 10, b2_staticBody);
	PhysBody* spring = App->physics->CreateRectangle(243, 375, 10, 10);
	
	f.categoryBits = FLIPPER;
	f.maskBits = BALL | WALL | FLIPPER;
	spring->body->GetFixtureList()->SetFilterData(f);
	spring_anchor->body->GetFixtureList()->SetFilterData(f);

	springDistanceJoint = App->physics->CreateDistanceJoint(spring->body, spring_anchor->body);
	springPrismaticJoint = App->physics->CreateSpringPrismaticJoint(spring->body, spring_anchor->body);
	springDistanceJoint->SetDampingRatio(0.5f);
	springDistanceJoint->SetFrequency(4.0f);

	current_spring = &grey_spring;

	// Create shark
	float diameter = 19.0f;
	shark = App->physics->CreateCircle(198, 206, diameter, b2_staticBody);
	shark->body->GetFixtureList()->SetSensor(true);
	//ball->body->GetFixtureList()->SetDensity(0.7f);

	shark->listener = this;

	f.categoryBits = FLIPPER;
	f.maskBits = BALL;
	shark->body->GetFixtureList()->SetFilterData(f);

	current_shark = &idle_shark;

	// Create cave
	cave = App->physics->CreateRectangleSensor(90, 135, 30, 20);
	//ball->body->GetFixtureList()->SetDensity(0.7f);

	cave->listener = this;

	f.categoryBits = FLIPPER;
	f.maskBits = BALL;
	cave->body->GetFixtureList()->SetFilterData(f);

	current_cave = &idle_cave;

	// Create pokémon that lives in the cave
	diameter = 22.0f;
	pokemon_cave = App->physics->CreateCircle(92, 180, diameter, b2_staticBody);
	diameter = 26.0f;
	pokemon_cave1 = App->physics->CreateCircle(90, 150, diameter, b2_staticBody);
	pokemon_cave->body->GetFixtureList()->SetRestitution(2.0f);
	pokemon_cave1->body->GetFixtureList()->SetRestitution(2.0f);
	//pokemon_cave->body->GetFixtureList()->SetSensor(true);
	//ball->body->GetFixtureList()->SetDensity(0.7f);

	pokemon_cave->listener = this;
	pokemon_cave1->listener = this;

	f.categoryBits = FLIPPER;
	f.maskBits = BALL;
	pokemon_cave->body->GetFixtureList()->SetFilterData(f);
	pokemon_cave1->body->GetFixtureList()->SetFilterData(f);

	current_pokemon_cave = &idle_pokemon_cave;

	current_egg = &idle_egg;

	post_start = 0;

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

// Update: draw background
update_status ModulePlayer::Update()
{
	if (post_start == 1) {
		App->physics->CreateDistanceJoint(rotatingPokemons[1]->body, rotatingPokemons[2]->body);
		App->physics->CreateDistanceJoint(rotatingPokemons[2]->body, rotatingPokemons[3]->body);
		App->physics->CreateDistanceJoint(rotatingPokemons[3]->body, rotatingPokemons[1]->body);
		post_start = 2;
	}

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

		// Create ball
		if (App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_DOWN && post_start > 0)
			CreateBall(ball_diameter, App->input->GetMouseX(), App->input->GetMouseY());

		// Destroy ball
		if (App->scene_intro->destroy_ball && ball != nullptr)
			DestroyBall();

		// Update Spring (distance joint)
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

	// Spring animation change
	if (end_spring.Finished() && spring_anim) {
		current_spring = &grey_spring;
		end_spring.Reset();
		spring_anim = false;
	}

	// All draw functions ------------------------------------------------------

	// Blit ball
	if (ball != nullptr && blit_ball) {
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
	//

	// Blit flippers
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
	//

	// Blit rotating pokemons
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
	//

	// Blit spring
	r_spring = &current_spring->GetCurrentFrame();
	b2Vec2 pos_spring = springDistanceJoint->GetBodyB()->GetPosition();
	App->renderer->Blit(App->scene_intro->general, 233, 370, r_spring);

	// Change spring position
	if (r_spring->x == 4)
		springDistanceJoint->GetBodyA()->ApplyForce({ 0, 0.0f }, { 0, 0 }, true);
	else if (r_spring->x == 26)
		springDistanceJoint->GetBodyA()->ApplyForce({ 0, -0.4f }, { 0, 0 }, true);
	//

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
			//go_back2_x += 0.01f;
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
		//almost_in_pokemon_cave.Reset();
	}
	//
	if ((num_cave_hits == 1  || num_cave_hits == 2) && cave_hit) {
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
		break_egg2.Reset();
		break_egg1.Reset();
		blit_egg = false;

		ball->body->SetGravityScale(1);
		ball->body->ApplyForceToCenter({ 10, 10 }, true);
		blit_ball = true;
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

		ball->body->SetGravityScale(1);
		ball->body->ApplyForceToCenter({ 10, 10 }, true);
		blit_ball = true;
		cave_hit = false;
	}

	// Blit shark
	r_shark = &current_shark->GetCurrentFrame();
	b2Vec2 pos_shark = shark->body->GetPosition();
	App->renderer->Blit(App->scene_intro->general, METERS_TO_PIXELS(pos_shark.x) - 18 + go_back1_x, METERS_TO_PIXELS(pos_shark.y) - 34 + go_back1_y, r_shark);
	//

	// Blit cave	// Blit pokemon cave
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

	return UPDATE_CONTINUE;
}

// Get flipper sprites
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

// Get ball sprites
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

	ball_properties->current_sprite = sprite;

	LOG("%f", fmodf(angle, 360));
	//LOG("%f", angle);
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
}

void ModulePlayer::UpdateCamera() {
	//if (ball != nullptr) {
		//int x, y;
		//ball->GetPosition(x, y);


	//}
}