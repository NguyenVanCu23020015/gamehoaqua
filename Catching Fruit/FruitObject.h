#ifndef FRUIT_OBJECT_H_
#define  FRUIT_OBJECT_H_
#include "Game.h"
#include "BaseObject.h"

#define W_FRUIT 40
#define H_FRUIT 40

class FruitObject : public BaseObject
{
public:
	FruitObject();
	~FruitObject();

	void HandleMove(const int& x_border, const int& y_border);
	void set_y_val(const int& val) { y_val_ = val; }
	void Reset(const int& yboder);
	bool FruitExit(const int& ye);

private:
	int x_val_;
	int y_val_;

};
#endif // !FRUIT_OBJECT_H_

