#include "BossObject.h"

//gán các giá trị chiều dài chiều rộng của trùm và vị trí
BossObject::BossObject()
{
    rect_.x = SCREEN_WIDTH;
    rect_.y = SCREEN_HEIGHT;
    rect_.w = WIDTH_BOSS;
    rect_.h = HEIGHT_BOSS;

    x_val_ = 0;
    y_val_ = 0;
}

//hàm deconstruct đạn trùm
BossObject::~BossObject()
{
    if (p_bullet_list_.size() > 0)
    {
        for (int i = 0; i < p_bullet_list_.size(); i++)
        {
            BulletObject* p_bullet = p_bullet_list_.at(i);
            if (p_bullet != NULL)
            {
                delete p_bullet;
                p_bullet = NULL;
            }
        }
        p_bullet_list_.clear();
    }
}
//khởi tạo đạn của trùm
void BossObject::InitBullet(BulletObject* p_bullet)
{
    if (p_bullet)
    {
        //kiểm tra load file ảnh đạn trùm
        bool ret = p_bullet->LoadImg(g_name_boss_bullet);
        if (ret)
        {
            p_bullet->set_is_move(true);
            p_bullet->SetWidthHeight(WIDTH_BOSS_BULLET, HEIGHT_BOSS_BULLET);
            p_bullet->set_type(BulletObject::BOSS);
            p_bullet->SetRect(rect_.x, rect_.y + WIDTH_BOSS * 0.32);
            p_bullet->set_x_val(2);
            p_bullet_list_.push_back(p_bullet);
        }
    }
}

void BossObject::MakeBullet(SDL_Surface* des, const int& x_limit, const int& y_limit)
{
    for (int i = 0; i < p_bullet_list_.size(); i++)
    {
        BulletObject* p_bullet = p_bullet_list_.at(i);
        if (p_bullet)
        {
            //các hàm kiểm tra cũng giống như các hàm đạn bắn ra của người chơi chính
            //chỉ khác ở đây là các viên đạn sẽ được sử dụng hàm HandleMoveRightToLeft
            //để đạn của trùm bắn về phía người chơi
            if (p_bullet->get_is_move())
            {
                p_bullet->Show(des);
                p_bullet->HandleMoveRightToLeft();
            }
            else
            {
                //nếu như viên đạn đang không di chuyển thì đặt lại cho nó thành di chuyển
                p_bullet->set_is_move(true);
                //và truyền vào dữ liệu xuất hiện viên đạn sao cho trùng khớp với vị trí trùm
                p_bullet->SetRect(rect_.x, rect_.y + WIDTH_BOSS * 0.32);
            }
        }
    }
}

//hàm xử lý di chuyển của trùm
void BossObject::HandleMove(const int& x_bordr, const int& y_border)
{
    rect_.x -= x_val_;
    if (rect_.x < 0)
    {
        x_val_ = 0;
    }
}
//đặt lại ví trí viên đạn cho đúng
void BossObject::ResetBullet(BulletObject* p_bullet)
{
    p_bullet->SetRect(rect_.x, rect_.y + WIDTH_BOSS * 0.32);
}