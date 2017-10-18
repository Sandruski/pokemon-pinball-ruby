#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleMenuScene.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"

ModuleMenuScene::ModuleMenuScene(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	circle = box = rick = NULL;
	general = NULL;
	ray_on = false;
	sensed = false;

	background.x = 533;
	background.y = 3;
	background.w = 257;
	background.h = 425;

}

ModuleMenuScene::~ModuleMenuScene()
{}

// Load assets
bool ModuleMenuScene::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;

	/*
	TODOS
	-Muchos edges.
	-Crear bonus (cuando pasa la bola, se tienen que activar.Tipo sensores : isSensor = true), bouncers(cuerpos estáticos).
	-Que llame a una función de AddBody de ModulePhysics.
	*/

	return ret;
}

// Load assets
bool ModuleMenuScene::CleanUp()
{
	LOG("Unloading Intro scene");
	

	return true;
}

// Update: draw background
update_status ModuleMenuScene::Update()
{	

	return UPDATE_CONTINUE;
}




/*
Module Physics
Class PhysBody:
- Con GetUserData y SetUserData podemos acceder a nuestro cuerpo con punteros.
- AddBody: con parámetros de densidad, restitución, masa, etc.Para que los objetos reboten más o menos.
·Bouncers : mucha restitución.
·Bola : mucha densidad, poca restitución.
- b2ContactListener
- b2Body*; = puntero al b2Body
- Module* listener; //qué módulo está interesado para detectar una colisión. Cada módulo debe tener un OnCollision()

-NO HACE FALTA CREAR CUERPOS CINEMÁTICOS.

Detección de colisiones y gestión de las mismas:
-Detectar cuando la bola cae más abajo del pinball. Detección con un sensor muy grande.
-SetListener al world. BeginContact. Para los sensores no nos llama al BeginContact: solución: a cada vuelta, iterar por todos los contactos del b2World y si alguno
de los contactos es una colisión, gestionar dicha colisión.
*/