#include "Game.h"
#include "MainObject.h"
#include "BaseObject.h"
#include "FruitObject.h"
#include <SDL_ttf.h>
#pragma warning(disable:4996)
#undef main

SDL_Color gTextColor = { 0x00, 0x00, 0x00 };
SDL_Color gTextColormark = { 0xFF, 0x00, 0x00 };

int ShowMenu(SDL_Surface* gscreen, TTF_Font* font) {
	int time = 0;
	int x = 0;
	int y = 0;
	const int kMenuNum = 2;
	const char* labels[kMenuNum] = { "Start Game", "Exit" };
	SDL_Surface* menu[kMenuNum];
	bool selected[kMenuNum] = { 0, 0 };
	SDL_Color color[2] = { { 255, 255, 255 },{ 255, 0, 0 } };
	menu[0] = TTF_RenderText_Solid(font, labels[0], color[0]);
	menu[1] = TTF_RenderText_Solid(font, labels[1], color[0]);
	SDL_Rect pos[kMenuNum];
	pos[0].x = (gscreen->clip_rect.w / 2) - (menu[0]->clip_rect.w / 2);
	pos[0].y = (gscreen->clip_rect.h / 2) - (menu[0]->clip_rect.h);
	pos[1].x = (gscreen->clip_rect.w / 2) - (menu[0]->clip_rect.w / 2);
	pos[1].y = (gscreen->clip_rect.h / 2) + (menu[0]->clip_rect.h);

	SDL_FillRect(gscreen, &gscreen->clip_rect, SDL_MapRGB(gscreen->format, 0x00, 0x00, 0x00));
	SDL_Event event;
	while (1) {
		time = SDL_GetTicks();
		SDLGame::ApplySurface(g_bstart, g_screen, 0, 0);
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				SDL_FreeSurface(menu[0]);
				SDL_FreeSurface(menu[1]);
				return 1;
			case SDL_MOUSEMOTION:
				x = event.motion.x;
				y = event.motion.y;
				for (int i = 0; i < kMenuNum; ++i)
				{
					if (x >= pos[i].x && x <= pos[i].x + pos[i].w &&
						y >= pos[i].y && y <= pos[i].y + pos[i].h) {
						if (!selected[i]) {
							selected[i] = 1;
							SDL_FreeSurface(menu[i]);
							menu[i] = TTF_RenderText_Solid(font, labels[i], color[1]);
						}
					}
					else {
						if (selected[i]) {
							selected[i] = 0;
							SDL_FreeSurface(menu[i]);
							menu[i] = TTF_RenderText_Solid(font, labels[i], color[0]);
						}
					}
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				x = event.button.x;
				y = event.button.y;
				for (int i = 0; i < kMenuNum; ++i) {
					if (x >= pos[i].x && x <= pos[i].x + pos[i].w &&
						y >= pos[i].y && y <= pos[i].y + pos[i].h) {
						SDL_FreeSurface(menu[0]);
						SDL_FreeSurface(menu[1]);
						return i;
					}
				}
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym = SDLK_ESCAPE) {
					SDL_FreeSurface(menu[0]);
					SDL_FreeSurface(menu[1]);
					return 0;
				}
			}
		}
		for (int i = 0; i < kMenuNum; ++i) {
			SDL_BlitSurface(menu[i], NULL, gscreen, &pos[i]);
		}
		SDL_Flip(gscreen);
		if (1000 / 30 > (SDL_GetTicks() - time))
			SDL_Delay(1000 / 30 - (SDL_GetTicks() - time));
	}
}

bool Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}
	g_screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, SCREEN_BPP, SDL_SWSURFACE);
	if (g_screen == NULL)
	{
		return false;
	}

	if (TTF_Init() == -1)
	{
		return false;
	}
	gfont = TTF_OpenFont("XeroxBold.ttf", 40);
	gFontTime = TTF_OpenFont("XeroxBold.ttf", 20);
	if (gfont == NULL || gFontTime == NULL)
	{
		return false;
	}
	return true;
}

int main(int acr, char*argv[])
{
	int mark = 0;
	if (Init() == false)
	{
		return 0;
	}

	//load image
	g_bkground = SDLGame::LoadImage("background1.png");
	if (g_bkground == NULL)
	{
		return 0;
	}

	g_bgexit = SDLGame::LoadImage("backgroundexit.png");
	if (g_bgexit == NULL)
	{
		return 0;
	}

	g_bstart = SDLGame::LoadImage("bkopen.png");
	if (g_bstart == NULL)
	{
		return 0;
	}
 
	MainObject human_object;
	bool ret = human_object.LoadImg("object1.png");
	if (ret == false)
	{
		return 0;
	}
	human_object.SetRect(0, 510);
	human_object.Show(g_screen);

	g_icon = SDLGame::LoadImage("iconx.png");
	if (g_icon == NULL)
	{
		return 0;
	}

	FruitObject* p_fruit = new FruitObject();
	ret = p_fruit->LoadImg("melon.png");
	if (ret == false)
	{
		return 0;
	}
	p_fruit->SetRect(rand() % 80, -50);

	FruitObject* p_fruit1 = new FruitObject();
	ret = p_fruit1->LoadImg("nho.png");
	if (ret == false)
	{
		return 0;
	}
	p_fruit1->SetRect(120 + rand() % 80, -100);

	FruitObject* p_fruit2 = new FruitObject();
	ret = p_fruit2->LoadImg("cherry.png");
	if (ret == false)
	{
		return 0;
	}
	p_fruit2->SetRect(240 + rand() % 80, -200);

	FruitObject* p_star = new FruitObject();
	ret = p_star->LoadImg("star.png");
	if (ret == false)
	{
		return 0;
	}
	p_star->SetRect(360 + rand() % 80, -5000);

	FruitObject* p_bomb = new FruitObject();
	ret = p_bomb->LoadImg("bom.png");
	if (ret == false)
	{
		return 0;
	}
	p_bomb->SetRect(480 + rand() % 80, -300);

	//Show menu
	bool is_quit = false;
	int ret1 = ShowMenu(g_screen, gfont);
	if (ret1 == 1)
	{
		is_quit = true;
	}
	//Run
	while (!is_quit)
	{
		if (is_gameover == false)
		{
			while (SDL_PollEvent(&g_even))
			{
				if (g_even.type == SDL_QUIT)
				{
					is_quit = true;
					break;
				}

				human_object.HandleInputAction(g_even, &human_object);
			}
			SDLGame::ApplySurface(g_bkground, g_screen, 0, 0);
			human_object.Show(g_screen);
			human_object.HandleMove();

			//run fruit
			p_fruit->set_y_val(1);		
			p_fruit->HandleMove(SCREEN_W, SCREEN_H);
			p_fruit->Show(g_screen);

			p_fruit1->set_y_val(2);
			p_fruit1->HandleMove(SCREEN_W, SCREEN_H);
			p_fruit1->Show(g_screen);

			p_fruit2->set_y_val(1);
			p_fruit2->HandleMove(SCREEN_W, SCREEN_H);
			p_fruit2->Show(g_screen);

			p_star->set_y_val(5);
			p_star->HandleMove(SCREEN_W, SCREEN_H);
			p_star->Show(g_screen);

			p_bomb->set_y_val(2);
			p_bomb->HandleMove(SCREEN_W, SCREEN_H);
			p_bomb->Show(g_screen);

			// kiểm tra va chạm 
			bool is_col = SDLGame::CheckCollision(human_object.GetRect(), p_fruit->GetRect());
			bool is_col1 = SDLGame::CheckCollision(human_object.GetRect(), p_fruit1->GetRect());
			bool is_col2 = SDLGame::CheckCollision(human_object.GetRect(), p_fruit2->GetRect());
			bool is_col3 = SDLGame::CheckCollision(human_object.GetRect(), p_star->GetRect());

			if (is_col || is_col1 || is_col2 || is_col3)
			{
				if (is_col3)
				{
					mark = mark + 5;
				}
				else
				{
					mark = mark + 1;
				}

				if (is_col)
				{
					p_fruit->Reset(-50);
				}

				if (is_col1)
				{
					p_fruit1->Reset(-100);
				}

				if (is_col2)
				{
					p_fruit2->Reset(-20);
				}

				if (is_col3)
				{
					p_star->Reset(-5000);
				}
			}

			// hiện thị điểm
			char str[10];
			itoa(mark, str, 10);
			std::string strMark("Score : ");
			strMark += (std::string)str;
			gMark = TTF_RenderText_Solid(gFontTime, strMark.c_str(), gTextColormark);
			SDLGame::ApplySurface(gMark, g_screen, 20, 10);


			// kiểm tra hoa quả không ăn được
			bool is_die = p_fruit->FruitExit(p_fruit->GetRect().y);
			bool is_die1 = p_fruit1->FruitExit(p_fruit1->GetRect().y);
			bool is_die2 = p_fruit2->FruitExit(p_fruit2->GetRect().y);

			if (is_die1 || is_die || is_die2)
			{
				count_die++;
				SDLGame::ApplySurface(g_icon, g_bkground, 400 + 30 * count_die, 10);
				if (is_die1)
				{
					p_fruit1->Reset(-100);
				}
				if (is_die)
				{
					p_fruit->Reset(-50);
				}
				if (is_die2)
				{
					p_fruit2->Reset(-200);
				}
			}

		}

		//game over
		bool is_bomb = SDLGame::CheckCollision(human_object.GetRect(), p_bomb->GetRect());
		if (count_die >= 3 || is_bomb)
		{
			SDL_Delay(1000);
			is_gameover = true;
			SDLGame::CleanUp();
			SDLGame::ApplySurface(g_bgexit, g_screen, 0, 0);
			SDLGame::ApplySurface(gMark, g_screen, 250, 250);
		}

		if (SDL_Flip(g_screen) == -1)
		{
			return 0;
		}
	}
	SDLGame::CleanUp();
	SDL_Quit();
	TTF_Quit();
	return 1;
}