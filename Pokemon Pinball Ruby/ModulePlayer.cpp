#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"

#include "Box2D/Box2D/Box2D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{

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
	flipper_vertices[0].Set(412 - 402, 543 - 532);
	flipper_vertices[1].Set(423 - 402, 542 - 532);
	flipper_vertices[2].Set(432 - 402, 540 - 532);
	flipper_vertices[3].Set(431 - 402, 535 - 532);
	flipper_vertices[4].Set(421 - 402, 534 - 532);
	flipper_vertices[5].Set(406 - 402, 533 - 532);
	flipper_vertices[6].Set(402 - 402, 537 - 532);
	flipper_vertices[7].Set(405 - 402, 543 - 532);

	for (int i = 0; i < 8; i++) {
		flipper_vertices[i].x = PIXEL_TO_METERS(flipper_vertices[i].x);
		flipper_vertices[i].y = PIXEL_TO_METERS(flipper_vertices[i].y);
	}

	//Flipper
	b2BodyDef body;
	body.type = b2_dynamicBody;
	body.position.Set(0, 0);

	b2Body* b = App->physics->world->CreateBody(&body);
	b2PolygonShape flipper;
	flipper.Set(flipper_vertices, 8);

	b2FixtureDef fixture;
	fixture.density = 1.0f;
	fixture.shape = &flipper;

	b->CreateFixture(&fixture);

	flippers[0] = new PhysBody();
	flippers[0]->body = b;
	b->SetUserData(flippers[0]);
	//

	revoluteJoint = App->physics->CreateCircle(30, 30, 6, b2_staticBody);

	b2RevoluteJointDef jointDef;
	jointDef.bodyA = flippers[0]->body;
	jointDef.bodyB = revoluteJoint->body;
	jointDef.collideConnected = false;

	b2Vec2 setA = { 0.13f, 0.12f };
	b2Vec2 setB = revoluteJoint->body->GetLocalCenter();

	jointDef.localAnchorA.Set(setA.x, setA.y);
	jointDef.localAnchorB.Set(setB.x, setB.y);

	jointDef.enableLimit = true;
	jointDef.lowerAngle = -45 * DEGTORAD;
	jointDef.upperAngle = 45 * DEGTORAD;

	/*
	//Motor
	jointDef.enableMotor = true;
	jointDef.maxMotorTorque = 10.0f; 
	jointDef.motorSpeed = 0.0f; 
	*/

	flipper1RevoluteJoint = (b2RevoluteJoint*)App->physics->world->CreateJoint(&jointDef);
	App->physics->CreateRevoluteJoint(revoluteJoint->body, flippers[0]->body);
	
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

//current_animation = &ball_anim;
//r = &current_animation->GetCurrentFrame();

// Update: draw background
update_status ModulePlayer::Update()
{
	//For motors
	//flipper1RevoluteJoint->SetMotorSpeed(cosf(0.5f * 1));
	
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
		flipper1RevoluteJoint->GetBodyA()->ApplyAngularImpulse(-0.1f, true);
		//flipper1RevoluteJoint->GetBodyB()->ApplyAngularImpulse(-70.0f, true);
	// Create bullet
	if (App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_DOWN) {
		// Create class PhysBody ball
		float diameter = 13.0f;

		balls.add(App->physics->CreateCircle(App->input->GetMouseX(), App->input->GetMouseY(), diameter));
		balls.getLast()->data->body->SetBullet(true); //ball is a fast moving object, so it can be labeled as bullet

		balls.getLast()->data->listener = this; //?????

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
	//b2Vec2 a = flipper1RevoluteJoint->GetBodyB()->GetPosition();
	//float b = flipper1RevoluteJoint->GetBodyB()->GetAngle();

	//App->renderer->Blit(App->scene_intro->general, a.x, a.y, &f1, 1.0f);
	
	return UPDATE_CONTINUE;
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
		LOG("CASE1");
	}
	else if (direction * angle - (360 * loops) > 11.25f && direction * angle - (360 * loops) <= 33.75f) {
		sprite = &b2;
		LOG("CASE2");
	}
	else if (direction * angle - (360 * loops) > 33.75f && direction * angle - (360 * loops) <= 56.25f) {
		sprite = &b3;
		LOG("CASE3");
	}
	else if (direction * angle - (360 * loops) > 56.25f && direction * angle - (360 * loops) <= 78.75f) {
		sprite = &b4;
		LOG("CASE4");
	}
	else if (direction * angle - (360 * loops) > 78.75f && direction * angle - (360 * loops) <= 101.25f) {
		sprite = &b5;
		LOG("CASE5");
	}
	else if (direction * angle - (360 * loops) > 101.25f && direction * angle - (360 * loops) <= 123.75f) {
		sprite = &b6;
		LOG("CASE6");
	}
	else if (direction * angle - (360 * loops) > 123.75f && direction * angle - (360 * loops) <= 146.25f) {
		sprite = &b7;
		LOG("CASE7");
	}
	else if (direction * angle - (360 * loops) > 146.25f && direction * angle - (360 * loops) <= 168.75f) {
		sprite = &b8;
		LOG("CASE8");
	}
	else if (direction * angle - (360 * loops) > 168.75f && direction * angle - (360 * loops) <= 191.25f) {
		sprite = &b9;
		LOG("CASE9");
	}
	else if (direction * angle - (360 * loops) > 191.25f && direction * angle - (360 * loops) <= 213.75f) {
		sprite = &b10;
		LOG("CASE10");
	}
	else if (direction * angle - (360 * loops) > 213.75f && direction * angle - (360 * loops) <= 236.25f) {
		sprite = &b11;
		LOG("CASE11");
	}
	else if (direction * angle - (360 * loops) > 236.25f && direction * angle - (360 * loops) <= 258.75f) {
		sprite = &b12;
		LOG("CASE12");
	}
	else if (direction * angle - (360 * loops) > 258.75f && direction * angle - (360 * loops) <= 281.25f) {
		sprite = &b13;
		LOG("CASE13");
	}
	else if (direction * angle - (360 * loops) > 281.25f && direction * angle - (360 * loops) <= 303.75f) {
		sprite = &b14;
		LOG("CASE14");
	}
	else if (direction * angle - (360 * loops) > 303.75f && direction * angle - (360 * loops) <= 326.25f) {
		sprite = &b15;
		LOG("CASE15");
	}
	else if (direction * angle - (360 * loops) > 326.25f && direction * angle - (360 * loops) <= 348.75f) {
		sprite = &b16;
		LOG("CASE16");
	}

	ball_properties->current_sprite = sprite;

	if (direction * angle >= max_angle) {
		ball_properties->loops += 1;
		ball_properties->max_angle += 360;
	}
}
