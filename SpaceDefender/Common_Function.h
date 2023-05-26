
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <Windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

//định nghĩa các dữ liệu khi khởi tạo không thành công
#define GA_FAILED -1
#define GA_SUCCESS 0;


//các thông số về cửa sổ
const int WIDTH_BACKGROUND = 4800;
const int HEIGHT_BACKGROUND = 600;
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;
const int SPEED_SCREEN = 2;

//định nghĩa các giá trị của người chơi chính
const int POS_X_START_MAIN_OBJ = 100;
const int POS_Y_START_MAIN_OBJ = 200;
const int SPEED_MAIN_OBJECT = 10;
const int SPEED_BULLET_MAIN = 20;

//định nghĩa các giá trị của kẻ địch

const int SPEED_THREAT = 5;
const int NUM_THREATS = 3;
const int SPEED_BULLET_THREATS = 10;
const int VAL_OFFSET_START_POST_THREATS = 400;
const int UNDER_LIMIT_THREAT = 200;

//khởi tạo các biến cần thiết để tạo cửa sổ chính và màn hình chính
static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_bkground = NULL;
static SDL_Surface* g_img_menu = NULL;
static SDL_Surface* g_img_end = NULL;
static SDL_Event g_even;

//tạo mảng các file âm thanh của đạn và các file âm thanh vụ nổ
static Mix_Chunk* g_sound_bullet[2];
static Mix_Chunk* g_sound_exp[2];

//nơi định nghĩa các file hình ảnh png và file âm thanh cần phải chạy
//định nghĩa hết ở cùng một nơi để dễ cho việc thay đổi
static char g_name_bk_ground[] = { "newbg.png" };

static char g_name_boss[] = { "Boss.png" };
static char g_name_boss_bullet[] = { "BossBullet.png" };
static char g_name_main_obj[] = { "mainplayer.png" };
static char g_name_exp_main[] = { "exp_main.png" };
static char g_name_bullet_main_laser[] = { "laser.png" };
static char g_name_bullet_main_fire[] = { "sphere.png" };
static char g_name_audio_bullet_main[] = { "Laser.wav" };
static char g_name_audio_bullet_main2[] = { "Fire1.wav" };
static char g_name_audio_exp_main[] = { "Bomb1.wav" };

static char g_name_exp_threats[] = { "exp.png" };
static char g_name_threats[] = { "enemy.png" };
static char g_name_bullet_threats[] = { "sphere2.png" };
static char g_name_audio_exp_threats[] = { "Explosion+1.wav" };

//đặt tên các hàm
namespace SDLCommonFunc
{
	SDL_Surface* LoadImage(std::string file_path);
	void CleanUp();
	SDL_Rect ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void ApplySurfaceClip(SDL_Surface* src, SDL_Surface* des, SDL_Rect* clip, int x, int y);
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
	int MakeRandValue(const int& div_val = 500);
	int ShowMenu(SDL_Surface* des, TTF_Font* font);
	int ShowEnding(SDL_Surface* des, TTF_Font* font, int exit_code, int score);
	bool CheckFocusWithRect(const int& x, const int& y, const SDL_Rect& rect);
}


#endif
