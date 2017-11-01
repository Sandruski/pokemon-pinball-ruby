#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"
#include "Animation.h"

class PhysBody;
class SDL_Texture;

enum menuStates {
	null_,
	menu_,
	subMenu_,
	mapSelector_,
	score_,
};

class ModuleMenuScene : public Module
{
public:
	ModuleMenuScene(Application* app, bool start_enabled = true);
	~ModuleMenuScene();

	bool Start();
	update_status Update();
	bool CleanUp();

	menuStates menuEnum;

private:
	SDL_Texture* menu; 
	SDL_Rect* r;

	SDL_Rect menuBg, subMenu, mapSelector, scoreMenu, scorePrint;
	Animation* current_animation;
	Animation pressStart, flipper, mapSelection;
	int positionFlipper1, positionFlipper2;

};

