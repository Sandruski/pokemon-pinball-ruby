#ifndef __ModuleFadeToBlack_H__
#define __ModuleFadeToBlack_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_rect.h"

#define MIN( a, b ) ( ((a) < (b)) ? (a) : (b) )

struct SDL_Texture;

class ModuleFadeToBlack : public Module
{
public:
	ModuleFadeToBlack(Application* app, bool start_enabled = true);
	~ModuleFadeToBlack();

	bool Start();
	update_status Update();
	bool FadeToBlack(Module* module_off, Module* module_on, float time = 2.0f);

	bool IsFading() const;

	Module* off;
	Module* on;
	bool black = true;

	int start_x = 130;
	int start_y = 110;

private:

	enum fade_step
	{
		none,
		fade_to_black,
		fade_from_black
	} current_step = fade_step::none;

	Uint32 start_time = 0;
	Uint32 total_time = 0;
	SDL_Rect screen;

};

#endif //__ModuleFadeToBlack_H__