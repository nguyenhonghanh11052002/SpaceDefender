
#include "BaseObject.h"

//khởi tạo một class chung cho tất cả các object trong trò chơi
//trong class này có lưu vị trí x y của vật và hình ảnh của vật
BaseObject::BaseObject()
{
    rect_.x = 0;
    rect_.y = 0;
    p_object_ = NULL;
}

//hàm deconstruct
BaseObject::~BaseObject()
{
    if (p_object_ != NULL)
    {
        SDL_FreeSurface(p_object_);
    }
}

//hàm load hình ảnh cho vật hàm LoadImage trong file common function được sử dụng nhiều lần
//tạo nên sự tối ưu hóa code
bool BaseObject::LoadImg(const char* file_name)
{
    p_object_ = SDLCommonFunc::LoadImage(file_name);
    if (p_object_ == NULL)
        return false;
    return true;
}


//hàm đưa vật hiển thị ra màn hình chính
void BaseObject::Show(SDL_Surface* des)
{
    if (p_object_ != NULL)
    {
        rect_ = SDLCommonFunc::ApplySurface(p_object_, des, rect_.x, rect_.y);
    }
}
