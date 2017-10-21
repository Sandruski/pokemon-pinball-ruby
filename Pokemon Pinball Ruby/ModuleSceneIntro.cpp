#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"
#include "ModulePlayer.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
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

	int GeneralSpritesheet0[14] = {
		679 - 533, 94,
		682 - 533, 93,
		684 - 533, 95,
		684 - 533, 110,
		681 - 533, 111,
		679 - 533, 109,
		678 - 533, 97
	};

	int GeneralSpritesheet1[150] = {
		632 - 533, 422,
		600 - 533, 406,
		573 - 533, 387,
		573 - 533, 399,
		557 - 533, 399,
		557 - 533, 326,
		560 - 533, 321,
		565 - 533, 318,
		574 - 533, 318,
		578 - 533, 316,
		580 - 533, 313,
		580 - 533, 288,
		571 - 533, 279,
		565 - 533, 269,
		558 - 533, 256,
		552 - 533, 243,
		548 - 533, 229,
		545 - 533, 212,
		545 - 533, 174,
		547 - 533, 155,
		551 - 533, 138,
		556 - 533, 125,
		566 - 533, 108,
		579 - 533, 94,
		592 - 533, 84,
		606 - 533, 77,
		625 - 533, 71,
		642 - 533, 68,
		667 - 533, 68,
		683 - 533, 71,
		698 - 533, 76,
		710 - 533, 82,
		722 - 533, 88,
		736 - 533, 97,
		750 - 533, 109,
		760 - 533, 120,
		769 - 533, 132,
		774 - 533, 144,
		777 - 533, 153,
		780 - 533, 164,
		782 - 533, 176,
		783 - 533, 190,
		783 - 533, 411,
		769 - 533, 411,
		768 - 533, 211,
		767 - 533, 188,
		765 - 533, 173,
		763 - 533, 163,
		759 - 533, 151,
		756 - 533, 144,
		753 - 533, 144,
		752 - 533, 148,
		756 - 533, 161,
		758 - 533, 173,
		760 - 533, 187,
		761 - 533, 209,
		757 - 533, 231,
		750 - 533, 252,
		740 - 533, 270,
		726 - 533, 289,
		726 - 533, 313,
		728 - 533, 316,
		734 - 533, 317,
		741 - 533, 318,
		747 - 533, 322,
		749 - 533, 327,
		749 - 533, 399,
		734 - 533, 399,
		734 - 533, 388,
		726 - 533, 393,
		715 - 533, 400,
		706 - 533, 406,
		696 - 533, 412,
		686 - 533, 417,
		676 - 533, 422
	};

	int GeneralSpritesheet2[14] = {
		658 - 533, 92,
		661 - 533, 90,
		663 - 533, 92,
		663 - 533, 109,
		659 - 533, 109,
		658 - 533, 107,
		658 - 533, 95
	};

	int GeneralSpritesheet3[30] = {
		583 - 533, 337,
		581 - 533, 333,
		577 - 533, 334,
		576 - 533, 338,
		576 - 533, 371,
		580 - 533, 375,
		586 - 533, 379,
		595 - 533, 384,
		609 - 533, 393,
		619 - 533, 398,
		625 - 533, 393,
		612 - 533, 384,
		598 - 533, 375,
		583 - 533, 364,
		583 - 533, 341
	};

	int GeneralSpritesheet4[58] = {
		608 - 533, 189,
		603 - 533, 160,
		603 - 533, 145,
		603 - 533, 133,
		610 - 533, 116,
		620 - 533, 104,
		630 - 533, 94,
		642 - 533, 90,
		642 - 533, 107,
		640 - 533, 111,
		640 - 533, 138,
		642 - 533, 149,
		645 - 533, 162,
		648 - 533, 169,
		653 - 533, 179,
		639 - 533, 180,
		635 - 533, 177,
		636 - 533, 162,
		637 - 533, 146,
		635 - 533, 136,
		627 - 533, 131,
		614 - 533, 131,
		609 - 533, 137,
		608 - 533, 146,
		608 - 533, 159,
		612 - 533, 176,
		614 - 533, 187,
		613 - 533, 190,
		610 - 533, 190
	};

	int GeneralSpritesheet5[58] = {
		608 - 533, 189,
		603 - 533, 160,
		603 - 533, 145,
		603 - 533, 133,
		610 - 533, 116,
		620 - 533, 104,
		630 - 533, 94,
		642 - 533, 90,
		642 - 533, 107,
		640 - 533, 111,
		640 - 533, 138,
		642 - 533, 149,
		645 - 533, 162,
		648 - 533, 169,
		653 - 533, 179,
		639 - 533, 180,
		635 - 533, 177,
		636 - 533, 162,
		637 - 533, 146,
		635 - 533, 136,
		627 - 533, 131,
		614 - 533, 131,
		609 - 533, 137,
		608 - 533, 146,
		608 - 533, 159,
		612 - 533, 176,
		614 - 533, 187,
		613 - 533, 190,
		610 - 533, 190
	};

	int GeneralSpritesheet6[28] = {
		681 - 533, 393,
		720 - 533, 367,
		723 - 533, 364,
		723 - 533, 345,
		723 - 533, 336,
		725 - 533, 334,
		728 - 533, 334,
		730 - 533, 336,
		730 - 533, 370,
		727 - 533, 373,
		721 - 533, 377,
		708 - 533, 385,
		687 - 533, 399,
		684 - 533, 396
	};

	int GeneralSpritesheet7[58] = {
		715 - 533, 111,
		701 - 533, 101,
		701 - 533, 111,
		712 - 533, 118,
		720 - 533, 126,
		721 - 533, 139,
		714 - 533, 158,
		704 - 533, 179,
		688 - 533, 208,
		694 - 533, 211,
		717 - 533, 165,
		725 - 533, 182,
		721 - 533, 200,
		707 - 533, 228,
		707 - 533, 231,
		712 - 533, 223,
		722 - 533, 204,
		728 - 533, 200,
		735 - 533, 202,
		736 - 533, 208,
		731 - 533, 228,
		725 - 533, 249,
		725 - 533, 251,
		730 - 533, 242,
		741 - 533, 214,
		744 - 533, 199,
		742 - 533, 161,
		736 - 533, 137,
		718 - 533, 114
	};

	int GeneralSpritesheet8[22] = {
		590 - 533, 112,
		590 - 533, 120,
		583 - 533, 141,
		582 - 533, 169,
		586 - 533, 194,
		578 - 533, 187,
		569 - 533, 174,
		566 - 533, 162,
		569 - 533, 146,
		577 - 533, 126,
		586 - 533, 113
	};

	App->physics->CreateChain(0, 0, GeneralSpritesheet0, 14, b2_staticBody);
	App->physics->CreateChain(0, 0, GeneralSpritesheet1, 150, b2_staticBody);
	App->physics->CreateChain(0, 0, GeneralSpritesheet2, 14, b2_staticBody);
	App->physics->CreateChain(0, 0, GeneralSpritesheet3, 30, b2_staticBody);
	App->physics->CreateChain(0, 0, GeneralSpritesheet4, 58, b2_staticBody);
	App->physics->CreateChain(0, 0, GeneralSpritesheet5, 58, b2_staticBody);
	App->physics->CreateChain(0, 0, GeneralSpritesheet6, 28, b2_staticBody);
	App->physics->CreateChain(0, 0, GeneralSpritesheet7, 58, b2_staticBody);
	App->physics->CreateChain(0, 0, GeneralSpritesheet8, 22, b2_staticBody);

	

	general = App->textures->Load("Assets/Sprites/GeneralSpritesheet.png");


	sensor = App->physics->CreateRectangleSensor(0, 100, 135, 15);
	sensor->listener = this;

	

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


	App->renderer->Blit(general, 0, 0, &background);

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{
	item = App->player->balls.getFirst();
		if (bodyB->body == item->data->body && bodyA->body == sensor->body)
		{
			item->data->body->DestroyFixture(item->data->body->GetFixtureList());
			//sensed = true;
		}
}

void ModuleSceneIntro::chainpoints() {
	

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