#pragma once
#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "Game.h"
#include "BaseObject.h"


#define W_MAIN_OBJECT 90
#define H_MAIN_OBJECT 87

class MainObject : public BaseObject
{
public:
	MainObject();
	~MainObject();
	void HandleInputAction(SDL_Event events,MainObject* obj);
	void HandleMove();


private:
	int x_val_;
	int y_val;


};

#endif //MAIN_OBJECT_H_

