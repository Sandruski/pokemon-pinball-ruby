#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"
#include "Animation.h"

#include "Box2D/Box2D/Box2D.h"

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


public:

	uint bonus_fx;
	p2Point<int> ray;
	bool ray_on;
	PhysBody* walls;
	SDL_Rect* r;
	Animation* current_anim;
	SDL_Texture* general;

	bool destroy_ball;

private:

	p2List_item<PhysBody*>* item;
	SDL_Rect background, rEvo, rEVo, rEVO, rLs10, rLS10, rLS10T, rGet, rGEt, rGET, rBall;
	PhysBody* sensor; 
	PhysBody* sensorPikachu;
	PhysBody* sensorEvo;
	PhysBody* sensorEVo;
	PhysBody* sensorEVO;
	PhysBody* sensorLs10;
	PhysBody* sensorLS10;
	PhysBody* sensorLS10T;
	PhysBody* sensorGet;
	PhysBody* sensorGEt;
	PhysBody* sensorGET;


	Animation pikachu, impactTrueno, slime, mPokemon, chikorita, topo, latiosSave;

	b2Vec2 ballSpeed;
	float time, timeEvo, timeEVo, timeEVO;
	bool checkTime, Evo, EVo, EVO, Ls10, LS10, LS10T, Get, GEt, GET;

	int font_score;
	char str1[15];

public: 
	void SensorsForBLit();
	void SetSensors();
	void CreateChains() const;
	void BlitStaticPokemonsAndLife();
};
