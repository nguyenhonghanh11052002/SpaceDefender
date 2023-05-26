
#include "Common_Function.h"
#include "TextObject.h"

//kiểm tra vị trí của chuột trên màn hình có trùng khớp với nút để bấm ở mành hình chính
bool SDLCommonFunc::CheckFocusWithRect(const int& x, const int& y, const SDL_Rect& rect)
{
    if (x >= rect.x && x < rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h)
    {
        return true;
    }
    return false;
}

//hàm khởi tạo màn hình chính
int SDLCommonFunc::ShowMenu(SDL_Surface* des, TTF_Font* font)
{
    //âm thanh nền xuyên suốt trò chơi
    Mix_PlayChannel(-1, Mix_LoadWAV("JackPot.wav"),-1);
    //load hình ảnh menu chính
    g_img_menu = LoadImage("menu_img.png");
    if (g_img_menu == NULL)
    {
        return 1;
    }

    //tạo mảng lưu các lựa chọn trong menu
    const int kMenuItemNum = 2;
    SDL_Rect pos_arr[kMenuItemNum];
    //định nghĩa vị trí các nút bấm trong menu
    pos_arr[0].x = 525;
    pos_arr[0].y = 300;

    pos_arr[1].x = 575;
    pos_arr[1].y = 350;

    TextObject text_menu[kMenuItemNum];

    //định nghĩa các dữ liệu các nút bấm trong menu
    text_menu[0].SetText("PLAY GAME");
    text_menu[0].SetColor(TextObject::WHITE_TEXT);
    text_menu[0].SetRect(pos_arr[0].x, pos_arr[0].y);

    text_menu[1].SetText("EXIT");
    text_menu[1].SetColor(TextObject::WHITE_TEXT);
    text_menu[1].SetRect(pos_arr[1].x, pos_arr[1].y);

    //hàm kiểm tra xem người chơi trỏ con trỏ chuột đến nút nào
    bool selected[kMenuItemNum] = { 0,0 };
    int xm = 0;
    int ym = 0;


    SDL_Event m_event;
    while (true)
    {
        //hàm khởi tạo hàm hình menu
        SDLCommonFunc::ApplySurface(g_img_menu, des, 0, 0);
        for (int i = 0; i < kMenuItemNum; i++)
        {
            //hàm khởi tạo chữ
            text_menu[i].CreateGameText(font, des);
        }

        //kiểm tra các thao tác của người chơi
        while (SDL_PollEvent(&m_event))
        {
            switch (m_event.type)
            {
            case SDL_QUIT:
                //kiêm tra hoạt động thoát của người chơi
                return 1;
            case SDL_MOUSEMOTION:
            {
                //lấy vị trí chuột
                xm = m_event.motion.x;
                ym = m_event.motion.y;

                for (int i = 0; i < kMenuItemNum; i++)
                {
                    //kiêm tra người chơi có trỏ con trỏ cảu chuột đến vị trí các nút bấm trong menu 
                    if (CheckFocusWithRect(xm, ym, text_menu[i].GetRect()))
                    {
                        if (selected[i] == false)
                        {
                            selected[i] = 1;
                            text_menu[i].SetColor(TextObject::YELLOW_TEXT);
                        }
                    }
                    else
                    {
                        if (selected[i] == true)
                        {
                            selected[i] = 0;
                            text_menu[i].SetColor(TextObject::WHITE_TEXT);
                        }
                    }
                }
            }
            break;
            //kiêm tra xem người chơi có bấm vào nút bấm trong menu
            case SDL_MOUSEBUTTONDOWN:
            {
                xm = m_event.button.x;
                ym = m_event.button.y;
                for (int i = 0; i < kMenuItemNum; i++)
                {
                    if (CheckFocusWithRect(xm, ym, text_menu[i].GetRect()))
                    {
                        return i;
                    }
                }
            }
            break;
            //nếu người chơi bấm Esc thì thoát
            case SDL_KEYDOWN:
                if (m_event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return 1;
                }
            default:
                break;
            }
        }

        SDL_Flip(des);
    }
    return 1;
}

int SDLCommonFunc::ShowEnding(SDL_Surface* des, TTF_Font* font, int exit_code, int score)
{
    if (exit_code == 2)
        g_img_end = LoadImage("Victory.png");
    else if (exit_code == 1)
        g_img_end = LoadImage("Defeated.png");

    const int kMenuItemNum = 2;
    SDL_Rect pos_arr[kMenuItemNum];

    pos_arr[0].x = 560;
    pos_arr[0].y = 300;

    pos_arr[1].x = 575;
    pos_arr[1].y = 350;

    TextObject player_score;
    TextObject text_menu[kMenuItemNum];
    std::string string_score = std::to_string(score);
    std::string final_score("YOUR FINAL SCORE IS : ");
    final_score += string_score;
    player_score.SetText(final_score);
    if (exit_code == 1)
        player_score.SetColor(TextObject::RED_TEXT);
    else
        player_score.SetColor(TextObject::YELLOW_TEXT);
    player_score.SetRect(425, 250);

    text_menu[0].SetText("RETRY");
    text_menu[0].SetColor(TextObject::WHITE_TEXT);
    text_menu[0].SetRect(pos_arr[0].x, pos_arr[0].y);

    text_menu[1].SetText("EXIT");
    text_menu[1].SetColor(TextObject::WHITE_TEXT);
    text_menu[1].SetRect(pos_arr[1].x, pos_arr[1].y);

    bool selected[kMenuItemNum] = { 0,0 };
    int xm = 0;
    int ym = 0;

    SDL_Event m_event;
    while (true)
    {
        //hàm khởi tạo hàm hình menu
        SDLCommonFunc::ApplySurface(g_img_end, des, 0, 0);
        player_score.CreateGameText(font, des);
        for (int i = 0; i < kMenuItemNum; i++)
        {
            //hàm khởi tạo chữ
            text_menu[i].CreateGameText(font, des);
        }

        //kiểm tra các thao tác của người chơi
        while (SDL_PollEvent(&m_event))
        {
            switch (m_event.type)
            {
            case SDL_QUIT:
                //kiêm tra hoạt động thoát của người chơi
                return 1;
            case SDL_MOUSEMOTION:
            {
                //lấy vị trí chuột
                xm = m_event.motion.x;
                ym = m_event.motion.y;

                for (int i = 0; i < kMenuItemNum; i++)
                {
                    //kiêm tra người chơi có trỏ con trỏ cảu chuột đến vị trí các nút bấm trong menu 
                    if (CheckFocusWithRect(xm, ym, text_menu[i].GetRect()))
                    {
                        if (selected[i] == false)
                        {
                            selected[i] = 1;
                            text_menu[i].SetColor(TextObject::YELLOW_TEXT);
                        }
                    }
                    else
                    {
                        if (selected[i] == true)
                        {
                            selected[i] = 0;
                            text_menu[i].SetColor(TextObject::WHITE_TEXT);
                        }
                    }
                }
            }
            break;
            //kiêm tra xem người chơi có bấm vào nút bấm trong menu
            case SDL_MOUSEBUTTONDOWN:
            {
                xm = m_event.button.x;
                ym = m_event.button.y;
                for (int i = 0; i < kMenuItemNum; i++)
                {
                    if (CheckFocusWithRect(xm, ym, text_menu[i].GetRect()))
                    {
                        Mix_HaltChannel(-1);
                        return i;
                    }
                }
            }
            break;
            //nếu người chơi bấm Esc thì thoát
            case SDL_KEYDOWN:
                if (m_event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return 1;
                }
            default:
                break;
            }
        }
        SDL_Flip(des);
    }
    return 1;
}


//hàm khởi tạo để load các hình ảnh
SDL_Surface* SDLCommonFunc::LoadImage(std::string file_path)
{
    SDL_Surface* load_image = NULL;
    SDL_Surface* optimize_image = NULL;
    //load file ảnh
    load_image = IMG_Load(file_path.c_str());
    //nếu không load được sẽ thửu tối ưu hóa file ảnh đó
    if (load_image != NULL)
    {
        optimize_image = SDL_DisplayFormat(load_image);
        SDL_FreeSurface(load_image);
        //nếu vẫn ko thể tối ưu hóa ảnh đó thì sẽ loại bỏ các màu thừa
        if (optimize_image != NULL)
        {
            UINT32 color_key = SDL_MapRGB(optimize_image->format, 0, 0xFF, 0xFF);
            SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, color_key);
        }
    }
    //trả lại hình ảnh load được
    return optimize_image;
}

//hàm dùng để đưa hình ảnh cần load kèm theo vị trí và màn hình để hiện hình ảnh
SDL_Rect SDLCommonFunc::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    //xuất hình ảnh ra màn hình
    SDL_BlitSurface(src, NULL, des, &offset);

    return offset;
}

//hàm dùng để tạo hiệu ứng chuyển động cho vụ nổ
void SDLCommonFunc::ApplySurfaceClip(SDL_Surface* src, SDL_Surface* des, SDL_Rect* clip, int x, int y)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(src, clip, des, &offset);
}


//hàm kiểm tra va chạm được truền vào vị trí của vật 1 và vật 2
bool SDLCommonFunc::CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2)
{
    int left_a = object1.x;
    int right_a = object1.x + object1.w;
    int top_a = object1.y;
    int bottom_a = object1.y + object1.h;

    int left_b = object2.x;
    int right_b = object2.x + object2.w;
    int top_b = object2.y;
    int bottom_b = object2.y + object2.h;

    // trường hợp 1 vật 1 nhỏ hơn vật 2
    if (left_a > left_b && left_a < right_b)
    {
        if (top_a > top_b && top_a < bottom_b)
        {
            return true;
        }
    }

    if (left_a > left_b && left_a < right_b)
    {
        if (bottom_a > top_b && bottom_a < bottom_b)
        {
            return true;
        }
    }

    if (right_a > left_b && right_a < right_b)
    {
        if (top_a > top_b && top_a < bottom_b)
        {
            return true;
        }
    }

    if (right_a > left_b && right_a < right_b)
    {
        if (bottom_a > top_b && bottom_a < bottom_b)
        {
            return true;
        }
    }

    // TH2: vật 2 nhỏ hơn vật 1
    if (left_b > left_a && left_b < right_a)
    {
        if (top_b > top_a && top_b < bottom_a)
        {
            return true;
        }
    }

    if (left_b > left_a && left_b < right_a)
    {
        if (bottom_b > top_a && bottom_b < bottom_a)
        {
            return true;
        }
    }

    if (right_b > left_a && right_b < right_a)
    {
        if (top_b > top_a && top_b < bottom_a)
        {
            return true;
        }
    }

    if (right_b > left_a && right_b < right_a)
    {
        if (bottom_b > top_a && bottom_b < bottom_a)
        {
            return true;
        }
    }

    // TH3 cả 2 vật bằng nhau
    if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
    {
        return true;
    }

    return false;
}

//hàm tạo giá trị ngẫu nhiên để tạo kẻ địch ngẫu nhiên trên màn hình 
int SDLCommonFunc::MakeRandValue(const int& div_val /*600*/)
{
    int rand_y = rand() % div_val;
    return rand_y;
}

//hàm dọn dẹp
void SDLCommonFunc::CleanUp()
{
    SDL_FreeSurface(g_screen);
    SDL_FreeSurface(g_bkground);
}