#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"

#include "Box2D/Box2D/Box2D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	rotating_pokemons.PushBack({ 171, 777, 25, 20 });
	rotating_pokemons.PushBack({ 198, 775, 23, 22 });
	rotating_pokemons.speed = 0.02f;
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
	f.categoryBits = NEUTRAL;
	flipperCircles[0]->body->GetFixtureList()->SetFilterData(f);
	flipperCircles[1]->body->GetFixtureList()->SetFilterData(f);

	f.categoryBits = FLIPPER;
	f.maskBits = BALL;
	flippers[0]->body->GetFixtureList()->SetFilterData(f);
	flippers[1]->body->GetFixtureList()->SetFilterData(f);

	//Create rotating pokémons
	rotatingPokemons[0] = App->physics->CreateCircle(100, 30, 50, b2_staticBody);
	rotatingPokemons[1] = App->physics->CreateCircle(0, 0, 20, b2_dynamicBody);
	rotatingPokemons[2] = App->physics->CreateCircle(0, 0, 20, b2_dynamicBody);
	rotatingPokemons[3] = App->physics->CreateCircle(0, 0, 20, b2_dynamicBody);

	rotatingPokemons[1]->body->SetLinearVelocity({ 0,0 });
	rotatingPokemons[2]->body->SetLinearVelocity({ 0,0 });
	rotatingPokemons[3]->body->SetLinearVelocity({ 0,0 });
	rotatingPokemons[1]->body->GetFixtureList()->SetRestitution(2.0f);
	rotatingPokemons[2]->body->GetFixtureList()->SetRestitution(2.0f);
	rotatingPokemons[3]->body->GetFixtureList()->SetRestitution(2.0f);

	pokemonsRevoluteJoint[0] = App->physics->CreatePokemonRevoluteJoint(rotatingPokemons[0]->body, rotatingPokemons[1]->body, { PIXEL_TO_METERS(25 * cosf(190 * DEGTORAD)), PIXEL_TO_METERS(25 * sinf(190 * DEGTORAD)) }); //Up
	pokemonsRevoluteJoint[1] = App->physics->CreatePokemonRevoluteJoint(rotatingPokemons[0]->body, rotatingPokemons[2]->body, { PIXEL_TO_METERS(25 * cosf(-40 * DEGTORAD)), PIXEL_TO_METERS(25 * sinf(-40 * DEGTORAD)) }); //Left
	pokemonsRevoluteJoint[2] = App->physics->CreatePokemonRevoluteJoint(rotatingPokemons[0]->body, rotatingPokemons[3]->body, { PIXEL_TO_METERS(25 * cosf(-130 * DEGTORAD)), PIXEL_TO_METERS(25 * sinf(-130 * DEGTORAD)) }); //Right

	current_rotating_pokemons = &rotating_pokemons;

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(pokeball);

	if (balls.getFirst() != NULL) {
		balls.clear();
	}

	if (balls_properties.getFirst() != NULL) {
		balls_properties.clear();
	}

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	//For motors
	pokemonsRevoluteJoint[0]->SetMotorSpeed(cosf(0.5f * 2));
	pokemonsRevoluteJoint[1]->SetMotorSpeed(cosf(0.5f * 2));
	pokemonsRevoluteJoint[2]->SetMotorSpeed(cosf(0.5f * 2));

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN)
		flipperRevoluteJoints[0]->GetBodyA()->ApplyAngularImpulse(-0.1f, true);
	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN)
		flipperRevoluteJoints[1]->GetBodyA()->ApplyAngularImpulse(0.1f, true);
	
	// Create bullet
	if (App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_DOWN) {
		// Create class PhysBody ball
		float diameter = 13.0f;

		balls.add(App->physics->CreateCircle(App->input->GetMouseX(), App->input->GetMouseY(), diameter));
		balls.getLast()->data->body->SetBullet(true); //ball is a fast moving object, so it can be labeled as bullet

		balls.getLast()->data->listener = this; //?????

		b2Filter f;
		f.categoryBits = BALL;
		f.maskBits = FLIPPER;

		balls.getLast()->data->body->GetFixtureList()->SetFilterData(f);

		// Create struct Ball ball
		ball_properties = new Ball();
		balls_properties.add(ball_properties);
	}

	// All draw functions ------------------------------------------------------
	p2List_item<PhysBody*>* b = balls.getFirst();
	p2List_item<Ball*>* bp = balls_properties.getFirst();

	// Blit bullet
	while (b != NULL && bp != NULL)
	{
		int x, y;
		b->data->GetPosition(x, y);
		float angle = b->data->GetRotation();

		// Get sprite for the ball
		GetBallSprites(angle, bp->data);

		// Blit bullet sprite
		if (angle < 0)
			App->renderer->Blit(pokeball, x, y, bp->data->current_sprite);
		else
			App->renderer->Blit(pokeball, x, y, bp->data->current_sprite, 1.0f, 0, INT_MAX, INT_MAX, SDL_FLIP_HORIZONTAL);

		b = b->next;
		bp = bp->next;
	}

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
	
	// Blit rotating pokemons
	r = &current_rotating_pokemons->GetCurrentFrame();
	b2Vec2 pos_p1 = rotatingPokemons[1]->body->GetPosition();
	App->renderer->Blit(App->scene_intro->general, METERS_TO_PIXELS(pos_p1.x) - 12, METERS_TO_PIXELS(pos_p1.y) - 12, r);
	pos_p1 = rotatingPokemons[2]->body->GetPosition();
	App->renderer->Blit(App->scene_intro->general, METERS_TO_PIXELS(pos_p1.x) - 12, METERS_TO_PIXELS(pos_p1.y) - 12, r);
	pos_p1 = rotatingPokemons[3]->body->GetPosition();
	App->renderer->Blit(App->scene_intro->general, METERS_TO_PIXELS(pos_p1.x) - 12, METERS_TO_PIXELS(pos_p1.y) - 12, r);

	return UPDATE_CONTINUE;
}

// Get flipper sprites
void ModulePlayer::GetFlipperSprites(float angle, SDL_Rect* &flipper_sprite, bool left) {

	SDL_Rect* sprite = &l_f1;

	if (left) {

		if (angle > 32.0f) {
			sprite = &l_f1;
		}
		else if (angle <= 32.0f && angle > 22.0f) {
			sprite = &l_f2;
		}
		else if (angle <= 22.0f && angle > 11.0f) {
			sprite = &l_f3;
		}
		else if (angle <= 11.0f && angle > -5.0f) {
			sprite = &l_f4;
		}
		else if (angle <= -5.0f && angle > -10.0f) {
			sprite = &l_f5;
		}
		else if (angle <= -10.0f) {
			sprite = &l_f6;
		}
	}
	else {

		if (angle < 150.0f) {
			sprite = &r_f1;
		}
		else if (angle >= 150.0f && angle < 160.0f) {
			sprite = &r_f2;
		}
		else if (angle >= 160.0f && angle < 170.0f) {
			sprite = &r_f3;
		}
		else if (angle >= 170.0f && angle < 186.0f) {
			sprite = &r_f4;
		}
		else if (angle >= 186.0f && angle < 191.0f) {
			sprite = &r_f5;
		}
		else if (angle >= 191.0f) {
			sprite = &r_f6;
		}
	}

	flipper_sprite = sprite;
}


// Get ball sprites
void ModulePlayer::GetBallSprites(float angle, Ball* ball_properties) {
	
	int direction = 1;
	int loops = ball_properties->loops;
	int max_angle = ball_properties->max_angle;
	SDL_Rect* sprite = &b1;

	if (angle < 0)
		direction = -1;

	if (direction * angle - (360 * loops) > 348.75f || direction * angle - (360 * loops) <= 11.25f) {
		sprite = &b1;
	}
	else if (direction * angle - (360 * loops) > 11.25f && direction * angle - (360 * loops) <= 33.75f) {
		sprite = &b2;
	}
	else if (direction * angle - (360 * loops) > 33.75f && direction * angle - (360 * loops) <= 56.25f) {
		sprite = &b3;
	}
	else if (direction * angle - (360 * loops) > 56.25f && direction * angle - (360 * loops) <= 78.75f) {
		sprite = &b4;
	}
	else if (direction * angle - (360 * loops) > 78.75f && direction * angle - (360 * loops) <= 101.25f) {
		sprite = &b5;
	}
	else if (direction * angle - (360 * loops) > 101.25f && direction * angle - (360 * loops) <= 123.75f) {
		sprite = &b6;
	}
	else if (direction * angle - (360 * loops) > 123.75f && direction * angle - (360 * loops) <= 146.25f) {
		sprite = &b7;
	}
	else if (direction * angle - (360 * loops) > 146.25f && direction * angle - (360 * loops) <= 168.75f) {
		sprite = &b8;
	}
	else if (direction * angle - (360 * loops) > 168.75f && direction * angle - (360 * loops) <= 191.25f) {
		sprite = &b9;
	}
	else if (direction * angle - (360 * loops) > 191.25f && direction * angle - (360 * loops) <= 213.75f) {
		sprite = &b10;
	}
	else if (direction * angle - (360 * loops) > 213.75f && direction * angle - (360 * loops) <= 236.25f) {
		sprite = &b11;
	}
	else if (direction * angle - (360 * loops) > 236.25f && direction * angle - (360 * loops) <= 258.75f) {
		sprite = &b12;
	}
	else if (direction * angle - (360 * loops) > 258.75f && direction * angle - (360 * loops) <= 281.25f) {
		sprite = &b13;
	}
	else if (direction * angle - (360 * loops) > 281.25f && direction * angle - (360 * loops) <= 303.75f) {
		sprite = &b14;
	}
	else if (direction * angle - (360 * loops) > 303.75f && direction * angle - (360 * loops) <= 326.25f) {
		sprite = &b15;
	}
	else if (direction * angle - (360 * loops) > 326.25f && direction * angle - (360 * loops) <= 348.75f) {
		sprite = &b16;
	}

	ball_properties->current_sprite = sprite;

	if (direction * angle >= max_angle) {
		ball_properties->loops += 1;
		ball_properties->max_angle += 360;
	}
}
