#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
using namespace std;
void draw()
{
}
int main(int, char **)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        // 输出报错
        SDL_Log("Init failed: %s", SDL_GetError());
        return -1;
    }
    // 2.创建窗口
    SDL_Window *win = SDL_CreateWindow("消消乐", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                       900, 600, SDL_WINDOW_RESIZABLE);
    if (win == NULL)
    {
        // 输出报错
        SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
        return -1;
    }
    // 3.创建渲染器
    SDL_Renderer *rdr = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (rdr == NULL)
    {
        // 输出报错
        SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
        return -1;
    }
    SDL_Texture *tex = IMG_LoadTexture(rdr, "cs2.jpeg");
    if (tex == NULL)
    {
        // 输出报错
        SDL_Log("IMG_LoadTexture failed: %s", SDL_GetError());
        return -1;
    }
    // 渲染图片
    SDL_Surface *img_surf = SDL_LoadBMP("cs2.bmp");
    SDL_SetWindowSize(win, img_surf->w, img_surf->h);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(rdr, img_surf);
    SDL_FreeSurface(img_surf);
    // 渲染图片
    SDL_RenderCopy(rdr, tex, NULL, NULL);
    SDL_SetRenderDrawColor(rdr, 0, 255, 0, 255);
    SDL_Rect rect = {200, 200, 100, 100};
    SDL_RenderDrawRect(rdr, &rect);
    SDL_RenderFillRect(rdr, &rect);
    // 更新渲染器
    SDL_RenderPresent(rdr);
    // 事件监听与响应
    SDL_Event event;
    while (true)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                return 0;
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
                {

                    SDL_RenderCopy(rdr, tex, NULL, NULL);
                    SDL_RenderPresent(rdr);
                }
                break;
            case SDL_MOUSEMOTION:
                SDL_Log("x=%d,y=%d", event.motion.x, event.motion.y);
                break;
            case SDL_MOUSEBUTTONDOWN:
                SDL_Log("x=%d,y=%d", event.button.x, event.button.y);
                break;
            case SDL_MOUSEBUTTONUP:
                SDL_Log("x=%d,y=%d", event.button.x, event.button.y);
                break;
            case SDL_KEYDOWN:
                SDL_Log("keydown");
                break;
            case SDL_KEYUP:
                SDL_Log("keyup");
                break;
            case SDL_TEXTINPUT:
                SDL_Log("textinput");
                break;
            case SDL_TEXTEDITING:
                SDL_Log("textediting");
                break;
            default:
                break;
            }
        }
    }
    // 等待退出
    SDL_DestroyRenderer(rdr);
    // 5.关闭窗口
    SDL_DestroyWindow(win);
    // 6.退出
    SDL_Quit();
    system("pause");
    return 0;
}