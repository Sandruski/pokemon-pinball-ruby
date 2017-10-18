#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModulePhysics.h"
#include "ModuleRender.h"

#include "Box2D/Box2D/Box2D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	
	ball_anim.PushBack({ 159, 926, 15, 15 });
	ball_anim.PushBack({ 176, 926, 15, 15 });
	ball_anim.PushBack({ 193, 926, 15, 15 });
	ball_anim.PushBack({ 210, 926, 15, 15 });
	ball_anim.PushBack({ 227, 926, 15, 15 });
	ball_anim.PushBack({ 244, 926, 15, 15 });
	ball_anim.PushBack({ 261, 926, 15, 15 });
	ball_anim.PushBack({ 278, 926, 15, 15 });
	ball_anim.PushBack({ 295, 926, 15, 15 });
	ball_anim.PushBack({ 312, 926, 15, 15 });
	ball_anim.PushBack({ 329, 926, 15, 15 });
	ball_anim.PushBack({ 346, 926, 15, 15 });
	ball_anim.PushBack({ 363, 926, 15, 15 });
	ball_anim.PushBack({ 380, 926, 15, 15 });
	ball_anim.PushBack({ 397, 926, 15, 15 });
	ball_anim.PushBack({ 414, 926, 15, 15 });

	ball_anim.speed = 0.05f;
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

	general = App->textures->Load("Assets/Sprites/GeneralSpritesheet.png");
	menu = App->textures->Load("Assets/Sprites/Menu&more.png");
	pokeball = App->textures->Load("Assets/Sprites/Pokeball&more.png");

	// Create flippers

	// Pivot 0, 0
	int GeneralSpritesheet[18] = {
		7, 1155,
		14, 1159,
		29, 1169,
		28, 1173,
		25, 1174,
		11, 1169,
		0, 1164,
		0, 1156,
		6, 1154
	};

	flippers[0] = App->physics->CreateChain(100, 100, GeneralSpritesheet, 18);
	PhysBody* revoluteJoint = App->physics->CreateCircle(102, 102, 25);


	b2RevoluteJointDef jointDef = App->physics->CreateRevoluteJoint(flippers[0]->body, revoluteJoint->body);

	float lowerAngle = -10;
	float upperAngle = 90;

	//jointDef.lowerAngle = DEGTORAD * lowerAngle * b2_pi;
	//jointDef.upperAngle = DEGTORAD * upperAngle * b2_pi;
	//

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(general);
	App->textures->Unload(menu);
	App->textures->Unload(pokeball);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	if (App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_DOWN) {
		// Create ball
		float diameter = 15.0f;

		balls.add(App->physics->CreateCircle(App->input->GetMouseX(), App->input->GetMouseY(), diameter));
		balls.getLast()->data->body->SetBullet(true); //ball is a fast moving object, so it can be labeled as bullet

		balls.getLast()->data->listener = this; //?????
	}

	// All draw functions ------------------------------------------------------
	p2List_item<PhysBody*>* b = balls.getFirst();

	current_animation = &ball_anim;
	r = &current_animation->GetCurrentFrame();

	// Blit bullet position
	while (b != NULL)
	{
		int x, y;
		b->data->GetPosition(x, y);
		float angle = b->data->GetRotation();

		// Blit bullet sprites
		App->renderer->Blit(pokeball, x, y, r, 1.0f, b->data->GetRotation());

		//if (angle % )


		b = b->next;
	}

	//float ball_angle = b->data->GetRotation();

	//if (ball_angle > 348.75 && ball_angle < 11.25) {

	//}


	int x, y;
	flippers[0]->GetPosition(x, y);
	App->renderer->Blit(general, x, y, &l_f1, 1.0f, flippers[0]->GetRotation());

	return UPDATE_CONTINUE;
}



