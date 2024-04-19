#pragma once
#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_
#include "Game.h"

class BaseObject
{
public:
	BaseObject();
	~BaseObject();
	bool LoadImg(const char* file_name);
	void Show(SDL_Surface* des);
	void SetRect(const int& x, const int& y) { rect_.x = x, rect_.y = y; }
	SDL_Rect GetRect() const { return rect_; }
	
protected:
	SDL_Rect rect_;
	SDL_Surface* p_object_;
};

#endif // !BASE_OBJECT_H_

