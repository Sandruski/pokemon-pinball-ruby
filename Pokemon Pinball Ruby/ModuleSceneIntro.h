#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"
#include "Animation.h"

class PhysBody;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);
	void chainpoints();

public:

	uint bonus_fx;
	p2Point<int> ray;
	bool ray_on;
	PhysBody* walls;

	SDL_Texture* general;


private:
	p2List_item<PhysBody*>* item;
	SDL_Rect background;
	PhysBody* sensor;
	PhysBody* sensorPikachu;
	bool sensed;
	PhysBody* trianglebody1;
	PhysBody* trianglebody2;
	Animation Pikachu;
	//b2Vec2 positionPikachu;

};
