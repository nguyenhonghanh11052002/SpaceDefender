
#ifndef BULLET_OBJECT_H_
#define BULLET_OBJECT_H_
#include "BaseObject.h"

#define WIDTH_LASER 35
#define HEIGHT_LASER 5

#define WIDTH_SPHERE 10
#define HEIGHT_SPHERE 10

#define WIDTH_BOSS_BULLET 178
#define HEIGHT_BOSS_BULLET 178

//các viên đạn được kế thừa các đặc tính của BaseObject
class BulletObject : public BaseObject
{
public:
    //khởi tạo tên các loại đạn
    enum BulletType
    {
        NONE = 0,
        LASER = 1,
        SPHERE = 2,
        BOSS = 3
    };

    //tên các hàm cần sử dụng
    BulletObject();
    ~BulletObject();
    void HandleInputAction(SDL_Event events);
    void HandleMove(const int& x_border, const int& y_border);
    void HandleMoveRightToLeft();

    //hàm trả về loại đạn
    int get_type() const { return bullet_type_; }
    //hàm truyền dữ liệu loại đạn vào class
    void set_type(const int& type) { bullet_type_ = type; }

    //kiểm tra đạn đang di chuyển hay không
    bool get_is_move() const { return is_move_; }
    //hàm chuyển trạng thái cho đạn di chuyển
    void set_is_move(bool is_move) { is_move_ = is_move; }
    //hàm đặt chiều dài chiều rộng của đạn
    void SetWidthHeight(const int& widht, const int& height) { rect_.w = widht; rect_.h = height; };

    //đặt vị trí x cho đạn
    void set_x_val(const int& val) { x_val_ = val; }
    //đặt vị trí y cho đạn
    void set_y_val(const int& val) { y_val_ = val; }

    //hàm trả về vị trí x,y của đạn
    int get_x_val() const { return x_val_; }
    int get_y_val() const { return y_val_; }
private:
    int x_val_;
    int y_val_;
    int bullet_type_;

    bool is_move_;
};


#endif