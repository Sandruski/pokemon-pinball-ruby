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
	bool LoadScore();
	bool SaveScore() const;


public:

	uint bonus_fx;
	p2Point<int> ray;
	bool ray_on;
	PhysBody* walls;
	SDL_Rect* r;
	Animation* current_anim;
	SDL_Texture* general;

	uint indexPikachu;
	uint impactCheck;

	bool destroy_ball;
	int points, highscore;

	int font_score;
	char str1[15];

	PhysBody* map_chain1;
	PhysBody* map_chain2;
	PhysBody* map_chain3;
	PhysBody* map_chain4;
	PhysBody* map_chain5;
	PhysBody* map_chain6;
	PhysBody* map_chain7;
	PhysBody* map_chain8;
	PhysBody* map_chain9;
	PhysBody* map_chain10;
	PhysBody* map_chain11;
	PhysBody* map_chain12;
	PhysBody* map_chain13;

private:

	p2List_item<PhysBody*>* item;
	SDL_Rect background, rEvo, rEVo, rEVO, rLs10, rLS10, rLS10T, rGet, rGEt, rGET, rBall, trianglesOnCollision, rCircle1, rCircle2, rChargePikachu;

	PhysBody* sensor; 
	PhysBody* sensorPikachu;
	PhysBody* sensorPikachuCharge;
	PhysBody* sensorEvo;
	PhysBody* sensorEVo;
	PhysBody* sensorEVO;
	PhysBody* sensorLs10;
	PhysBody* sensorLS10;
	PhysBody* sensorLS10T;
	PhysBody* sensorGet;
	PhysBody* sensorGEt;
	PhysBody* sensorGET;
	PhysBody* sensorCircle1;
	PhysBody* sensorCircle2;
	PhysBody* sensorCircle3;
	PhysBody* sensorCircle4;
	PhysBody* sensorCircle5;
	PhysBody* sensorCircle6;
	PhysBody* sensorCircle7;

	PhysBody* trianglebody1;
	PhysBody* trianglebody2;
	PhysBody* trianglebody3;
	PhysBody* trianglebody4;

	b2Filter f;

	Animation pikachu, impactTrueno, impactTrueno2, chargePikachu, slime, mPokemon, chikorita, topo, latiosSave, hatch, bumper, catchvar, hart;

	b2Vec2 ballSpeed;
	float timeEvo, timeEVo, timeEVO, timeTriangle1, timeTriangle2, timeCircle1, timeCircle2, timeCircle3, timeCircle4, timeCircle5, timeCircle6, timeCircle7;
	bool  Evo, EVo, EVO, Ls10, LS10, LS10T, Get, GEt, GET, trianglesBlit1, trianglesBlit2, circle1, circle2, circle3, circle4, circle5, circle6, circle7, pikachuChargeCheck, pika;

public: 
	void SensorsForBLit();
	void SetSensors();
	void CreateChains();
	void BlitStaticPokemonsAndLife();
	void Pikachu();
};
