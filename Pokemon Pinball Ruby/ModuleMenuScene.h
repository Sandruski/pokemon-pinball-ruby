#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"

class PhysBody;

class ModuleMenuScene : public Module
{
public:
	ModuleMenuScene(Application* app, bool start_enabled = true);
	~ModuleMenuScene();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	p2List<PhysBody*> circles;
	p2List<PhysBody*> boxes;
	p2List<PhysBody*> ricks;

	PhysBody* sensor;
	bool sensed;

	SDL_Texture* circle;
	SDL_Texture* box;
	SDL_Texture* rick;
	uint bonus_fx;
	p2Point<int> ray;
	bool ray_on;

	PhysBody* walls;

private:
	SDL_Texture* general;
	SDL_Rect background;
};

