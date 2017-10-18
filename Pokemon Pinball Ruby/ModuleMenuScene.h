#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"
#include "Animation.h"

class PhysBody;

class ModuleMenuScene : public Module
{
public:
	ModuleMenuScene(Application* app, bool start_enabled = true);
	~ModuleMenuScene();

	bool Start();
	update_status Update();
	bool CleanUp();

private:
	SDL_Texture* menu;
	SDL_Rect* r;

	SDL_Rect menuBg, subMenu;
	Animation* current_animation;
	Animation pressStart, flipper;
	int positionFlipper1, positionFlipper2;

	bool subMenuCheck;
};

