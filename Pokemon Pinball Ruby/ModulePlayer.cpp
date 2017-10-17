#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"

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

	/*
	idle.PushBack({ 1, 454, 48, 48 });
	idle.PushBack({ 50, 454, 48, 48 });
	idle.PushBack({ 99, 454, 48, 48 });
	idle.PushBack({ 148, 454, 48, 48 });
	idle.PushBack({ 197, 454, 48, 48 });
	idle.PushBack({ 246, 454, 48, 48 });
	idle.speed = 0.2f;
	*/

	LOG("Loading player");
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	//r = &current_animation->GetCurrentFrame();
	//App->render->Blit(App->player->player, App->player->position.x, App->player->position.y, App->player->r);


	return UPDATE_CONTINUE;
}



