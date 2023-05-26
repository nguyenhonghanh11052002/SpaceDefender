
#ifndef EXPLOSION_H_
#define EXPLOSION_H_

#include "BaseObject.h"
#include "Common_Function.h"

//khởi tạo các biến toàn bộ
const int EXP_WIDTH = 165;
const int EXP_HEIGHT = 165;

//các vật như vụ nổ cũng được kế thừa đặc tính của BaseObject tiện lợi cho việc lập trình
class ExplosionObject : public BaseObject
{
public:
	ExplosionObject();
	~ExplosionObject();
	void set_clip();
	void set_frame(const int& fr) { frame_ = fr; }
	void ShowEx(SDL_Surface* des);

private:
	int frame_;
	SDL_Rect clip_[4];
};

#endif