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
	menuBg.x = 20;
	menuBg.y = 7;
	menuBg.w = 256;
	menuBg.h = 160;

	subMenu.x = 284;
	subMenu.y = 132;
	subMenu.w = 96;
	subMenu.h = 83;

	mapSelector.x = 18;
	mapSelector.y = 270;
	mapSelector.w = 240;
	mapSelector.h = 160;

	pressStart.PushBack({319, 19, 84, 8});
	pressStart.PushBack({319, 29, 84, 8});
	pressStart.speed = 0.02f;

	flipper.PushBack({ 406, 24, 13, 8 });
	flipper.PushBack({ 406, 24, 13, 8 });
	flipper.PushBack({ 406, 24, 13, 8 });
	flipper.PushBack({ 406, 24, 13, 8 });
	flipper.PushBack({ 421, 24, 13, 8 });
	flipper.PushBack({ 436, 24, 13, 8 });
	flipper.PushBack({ 436, 24, 13, 8 });
	flipper.PushBack({ 436, 24, 13, 8 });
	flipper.PushBack({ 436, 24, 13, 8 });
	flipper.PushBack({ 421, 24, 13, 8 });
	flipper.speed = 0.1f;
}

ModuleMenuScene::~ModuleMenuScene()
{}

// Load assets
bool ModuleMenuScene::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;

	menu = App->textures->Load("Assets/Sprites/Menu&more.png");

	menuEnum = menu_;
	return ret;
}

// Load assets
bool ModuleMenuScene::CleanUp()
{
	LOG("Unloading Intro scene");
	App->textures->Unload(menu);

	return true;
}

// Update: draw background
update_status ModuleMenuScene::Update()
{	

	switch (menuEnum)
	{
	case menu_:
		App->renderer->Blit(menu, 0, 0, &menuBg);

		current_animation = &pressStart;
		r = &current_animation->GetCurrentFrame();
		App->renderer->Blit(menu, 256 / 2 - 84 / 2, 145, r);

		current_animation = &flipper;
		r = &current_animation->GetCurrentFrame();
		App->renderer->Blit(menu, (256 / 2 - 84 / 2) - 20, 145, r);
		App->renderer->Blit(menu, (256 / 2 - 84 / 2) + 84 + 13, 145, r, 1, 0, INT_MAX, INT_MAX, SDL_FLIP_HORIZONTAL);
		if (App->input->GetKey(SDL_SCANCODE_X) == KEY_DOWN) {
			menuEnum = subMenu_;
			break;
		}
		break;

	case subMenu_:
		App->renderer->Blit(menu, 0, 0, &menuBg);

		App->renderer->Blit(menu, 256 / 2 - 96 / 2, 160 / 2 - 83 / 2, &subMenu);
		if (App->input->GetKey(SDL_SCANCODE_X) == KEY_DOWN) {
			menuEnum = mapSelector_;
			break;
		}
		else if (App->input->GetKey(SDL_SCANCODE_Z) == KEY_DOWN) {
			menuEnum = menu_;
			break;
		}
		break;

	case mapSelector_:
		App->renderer->Blit(menu, 0, 0, &mapSelector);

		if (App->input->GetKey(SDL_SCANCODE_X) == KEY_DOWN) {
			menuEnum = null_;
			break;
		}
		else if (App->input->GetKey(SDL_SCANCODE_Z) == KEY_DOWN) {
			menuEnum = subMenu_;
			break;
		}
		break;

	case null_:
		if (App->input->GetKey(SDL_SCANCODE_Z) == KEY_DOWN) {
			menuEnum = mapSelector_;
			break;
		}
		break;
	}

	return UPDATE_CONTINUE;
}