#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
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

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
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

	int GeneralSpritesheet[112] = {
		573 - 533, 400,
		556 - 533, 400,
		556 - 533, 323,
		560 - 533, 318,
		567 - 533, 316,
		577 - 533, 316,
		579 - 533, 313,
		579 - 533, 288,
		569 - 533, 277,
		557 - 533, 255,
		547 - 533, 229,
		545 - 533, 198,
		547 - 533, 159,
		556 - 533, 127,
		568 - 533, 104,
		588 - 533, 88,
		609 - 533, 76,
		632 - 533, 70,
		659 - 533, 69,
		684 - 533, 73,
		702 - 533, 80,
		720 - 533, 88,
		736 - 533, 99,
		750 - 533, 112,
		760 - 533, 122,
		769 - 533, 138,
		777 - 533, 158,
		780 - 533, 175,
		782 - 533, 192,
		784 - 533, 410,
		768 - 533, 410,
		768 - 533, 194,
		764 - 533, 165,
		758 - 533, 147,
		753 - 533, 143,
		752 - 533, 148,
		755 - 533, 156,
		758 - 533, 175,
		760 - 533, 193,
		759 - 533, 219,
		750 - 533, 250,
		738 - 533, 273,
		725 - 533, 288,
		725 - 533, 312,
		729 - 533, 316,
		741 - 533, 319,
		748 - 533, 325,
		750 - 533, 335,
		750 - 533, 400,
		733 - 533, 400,
		732 - 533, 388,
		675 - 533, 420,
		675 - 533, 426,
		631 - 533, 426,
		632 - 533, 421,
		572 - 533, 386
	};

	walls = App->physics->CreateChain(0, 0, GeneralSpritesheet, 112, b2_staticBody);

	general = App->textures->Load("Assets/Sprites/GeneralSpritesheet.png");

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");
	App->textures->Unload(general);

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{

	if(App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		circles.add(App->physics->CreateCircle(App->input->GetMouseX(), App->input->GetMouseY(), 25));
		circles.getLast()->data->listener = this;
	}

	App->renderer->Blit(general, 0, 0, &background);

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{
}

int* ModuleSceneIntro::chainpoints() {

	int GeneralSpritesheet[112] = {
		573, 400,
		556, 400,
		556, 323,
		560, 318,
		567, 316,
		577, 316,
		579, 313,
		579, 288,
		569, 277,
		557, 255,
		547, 229,
		545, 198,
		547, 159,
		556, 127,
		568, 104,
		588, 88,
		609, 76,
		632, 70,
		659, 69,
		684, 73,
		702, 80,
		720, 88,
		736, 99,
		750, 112,
		760, 122,
		769, 138,
		777, 158,
		780, 175,
		782, 192,
		784, 410,
		768, 410,
		768, 194,
		764, 165,
		758, 147,
		753, 143,
		752, 148,
		755, 156,
		758, 175,
		760, 193,
		759, 219,
		750, 250,
		738, 273,
		725, 288,
		725, 312,
		729, 316,
		741, 319,
		748, 325,
		750, 335,
		750, 400,
		733, 400,
		732, 388,
		675, 420,
		675, 426,
		631, 426,
		632, 421,
		572, 386
	};

	return GeneralSpritesheet;
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