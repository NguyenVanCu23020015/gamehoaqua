#include "MainObject.h"
#include "BaseObject.h"

MainObject::MainObject()
{
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = W_MAIN_OBJECT;
	rect_.h = H_MAIN_OBJECT;
	x_val_ = 0;

}

MainObject::~MainObject()
{
	if (p_object_ != NULL)
	{
	
		SDL_FreeSurface(p_object_);
	};
}
// hàm xử lí di chuyển ếch ăn hoa quả
void MainObject::HandleInputAction(SDL_Event events, MainObject* p_obj)
{
	if (events.type == SDL_KEYDOWN)
	{
		p_obj->LoadImg("object.png");
		p_obj->Show(g_screen);
		switch (events.key.keysym.sym)
		{
		case SDLK_RIGHT:
			x_val_ += H_MAIN_OBJECT / 16;
			break;
		case SDLK_LEFT:
			x_val_ -= W_MAIN_OBJECT / 16;
			break;

		default:
			break;
		}
	}
	else if (events.type == SDL_KEYUP)
	{
		p_obj->LoadImg("object1.png");
		p_obj->Show(g_screen);
		switch (events.key.keysym.sym)
		{
		case SDLK_RIGHT:
			x_val_ -= H_MAIN_OBJECT / 16;
			break;
		case SDLK_LEFT:
			x_val_ += W_MAIN_OBJECT / 16;
			break;

		}

	}

}
void MainObject::HandleMove()
{
	rect_.x += x_val_;
	if (rect_.x < 0 || rect_.x + W_MAIN_OBJECT > SCREEN_W)
	{
		rect_.x -= x_val_;
	}

}