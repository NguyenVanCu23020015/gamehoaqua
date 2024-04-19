#ifndef GAME_H_
#define GAME_H_

#include<SDL.h>
#include<string>
#include<Windows.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include <fstream>
#include <SDL_events.h>
#include<math.h>
#include <sstream>
#include <cstdarg>
#include <cwchar>
#include <iomanip>

const int SCREEN_W = 600;
const int SCREEN_H = 600;
const int SCREEN_BPP = 32;

static int count_die = 0;
static bool is_gameover = false;

static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_bkground = NULL;
static SDL_Surface* g_bgexit = NULL;
static SDL_Surface* g_bstart = NULL;
static SDL_Surface* g_icon = NULL;
static SDL_Event g_even;
static TTF_Font* gfont = NULL;
static TTF_Font* gFontTime = NULL;
static SDL_Surface* gTimeSecond = NULL;
static SDL_Surface* gMark = NULL;

namespace SDLGame
{
	SDL_Surface* LoadImage(std::string file_path);
	void ApplySurface(SDL_Surface* scr, SDL_Surface* des, int x, int y);
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
	void CleanUp();
}

#endif 
