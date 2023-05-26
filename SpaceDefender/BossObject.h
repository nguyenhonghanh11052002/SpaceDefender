#ifndef BOSS_OBJECT_H_
#define BOSS_OBJECT_H_
#include "Common_Function.h"
#include "BaseObject.h"
#include "BulletObject.h"
#include <vector>

//định nghĩa các gia trị dài và rộng của trùm
#define WIDTH_BOSS 649
#define HEIGHT_BOSS 600

//hàm class trùm cũng được kế thừa BaseObject
class BossObject :public BaseObject
{
public:
	BossObject();
	~BossObject();

	//xử lý vị trí của trùm
	void HandleMove(const int& x_bordr, const int& y_border);
	//đặt vị trí x của trùm và trả về vị trí x của trùm
	void set_x_val(const int& val) { x_val_ = val; }
	int get_x_val() const { return x_val_; }
	//hàm giảm máu của trùm và hàm trả về số máu của trùm
	void decreaseHealth() { boss_health--; }
	int get_health() { return boss_health; }

	//khởi tạo danh sách đạn của trùm và trả về danh sách đạn
	void SetBulletList(std::vector<BulletObject*> bullet_list) { p_bullet_list_ = bullet_list; }
	std::vector<BulletObject*> GetBulletList() const { return p_bullet_list_; }

	//khởi tạo từng viên đạn một và đặt lại vị trí các viên đạn
	void InitBullet(BulletObject* p_bullet);
	void MakeBullet(SDL_Surface* des, const int& x_limit, const int& y_limit);
	void ResetBullet(BulletObject* p_bullet);
private:
	int x_val_;
	int y_val_;
	int boss_health = 1000;

	std::vector<BulletObject*> p_bullet_list_;
};

#endif 
