
#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_
#include "Common_Function.h"

//khai báo một hàm class làm nền tảng cho mọi object trong game sau này
class BaseObject
{
public:
	BaseObject();
	~BaseObject();
	void Show(SDL_Surface* des);
	bool LoadImg(const char* file_name);

	//hàm nhằm thay đổi vị trí x, y của vật
	void SetRect(const int& x, const int& y) { rect_.x = x, rect_.y = y; }
	//hàm trả về vị trí x y được lưu trong biến rect_
	SDL_Rect GetRect() const { return rect_; }
	//hàm trả về hình ảnh đồ vật
	SDL_Surface* GetObject() { return p_object_; }
protected:
	//các biến dữ liệu có thể kế thừa cho các cấu trúc class được xây dựng từ BaseObject
	SDL_Rect rect_;
	SDL_Surface* p_object_;
};

#endif 