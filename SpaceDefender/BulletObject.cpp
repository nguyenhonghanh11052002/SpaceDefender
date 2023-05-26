
#include "BulletObject.h"

//hàm khởi tạo ban đầu của một viên đạn
BulletObject::BulletObject()
{
    rect_.x = 0;
    rect_.y = 0;
    x_val_ = 0;
    y_val_ = 0;
    is_move_ = false;
    bullet_type_ = NONE;
}

BulletObject::~BulletObject()
{

}

//hàm thay đổi vị trí của viên đạn theo khi có kí hiệu is_move_=true
void BulletObject::HandleMove(const int& x_border, const int& y_border)
{
    if (is_move_ == true)
    {
        rect_.x += x_val_;
        //nếu viên đạn chạm vào biên của cửa sổ sẽ chuyển viên đạn về trạng thái dừng
        if (rect_.x > x_border)
        {
            is_move_ = false;
        }
    }
}

//hàm để di chuyển đạn bắn ra của kẻ địch
void BulletObject::HandleMoveRightToLeft()
{
    rect_.x -= x_val_;
    if (rect_.x < 0)
    {
        is_move_ = false;
    }
}

void BulletObject::HandleInputAction(SDL_Event events)
{
    ;
}
