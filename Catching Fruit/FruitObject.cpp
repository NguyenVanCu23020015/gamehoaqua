#include"FruitObject.h"
#include"Game.h"
#include "BaseObject.h"

FruitObject::FruitObject()
{
	rect_.x = SCREEN_W*0.2;
	rect_.y = 0;
	rect_.w = W_FRUIT;
	rect_.h = H_FRUIT;
	y_val_ = 0;
}

FruitObject::~FruitObject()
{
}

void FruitObject::HandleMove(const int& x_border, const int& y_border)
{
	rect_.y += y_val_;

	if (rect_.y > SCREEN_H + 20)
	{
		rect_.y = -10;
		int rand_x = rand() % 500;
		if (rand_x > SCREEN_W)
		{
			rand_x = (int)(SCREEN_W * 0.1);
		}
		rect_.x = rand_x;

	}

}
// hàm thiết lập vị trí hoa quả ngẫu nhiên
void FruitObject::Reset(const int& yboder)
{
	rect_.y = yboder;

	int rand_x = rand() % 500;
	if (rand_x > SCREEN_W)
	{
		rand_x = (int)(SCREEN_W * 0.5);
	}
	rect_.x = rand_x;
}

bool FruitObject::FruitExit(const int& ye)
{
	if (ye >= SCREEN_H + 2)
	{
		return true;
	}
	return false;
}

