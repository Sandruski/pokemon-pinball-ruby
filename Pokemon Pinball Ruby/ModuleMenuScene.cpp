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
	menuBg.w = 257;
	menuBg.h = 257;

	subMenu.x = 284;
	subMenu.y = 132;
	subMenu.w = 96;
	subMenu.h = 83;

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
	//App->renderer->Blit(menu, 0, 0, &menuBg);

	current_animation = &pressStart;
	r = &current_animation->GetCurrentFrame();
	//App->renderer->Blit(menu, 103 - 20, 155, r);

	current_animation = &flipper;
	r = &current_animation->GetCurrentFrame();
	//App->renderer->Blit(menu, 103 - 40, 155, r);
	//App->renderer->Blit(menu, 103 + 40 + 42 - 13, 155, r, 1, 0, INT_MAX, INT_MAX, SDL_FLIP_HORIZONTAL);
		

	if (App->input->GetKey(SDL_SCANCODE_X) == KEY_DOWN)
		subMenuCheck = true;

	if(subMenuCheck)
		App->renderer->Blit(menu, 0, 0, &subMenu);

	return UPDATE_CONTINUE;
}