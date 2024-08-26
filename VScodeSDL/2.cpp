#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
using namespace std;
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
    // 创建渲染器与清屏
    // 1.创建与窗口关联的渲染器
    SDL_Renderer *rdr = SDL_CreateRenderer(win, -1, 0);
    if (rdr == NULL)
    {
        // 输出报错
        SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
        return -1;
    }
    // 2.设置渲染颜色
    SDL_SetRenderDrawColor(rdr, 0, 255, 0, 255);
    // 3.清除屏幕
    SDL_RenderClear(rdr);
    SDL_SetRenderDrawBlendMode(rdr, SDL_BLENDMODE_BLEND);
    // 绘制
    // 1.设置渲染颜色
    SDL_SetRenderDrawColor(rdr, 0, 0, 0, 100);
    // SDL_Point pt[6] = {{0, 0}, {100, 100}, {100, 300}, {200, 100}, {250, 190}, {500, 500}};
    // SDL_RenderDrawLines(rdr, pt, 6);
    SDL_Rect rect = {200,200,100,100};
    SDL_RenderDrawRect(rdr, &rect);
    SDL_RenderFillRect(rdr, &rect);
    // 4.渲染呈现
    SDL_RenderPresent(rdr);
    SDL_Event event;
    while (true)
    {
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                break;
            }
        }
        SDL_SetRenderDrawColor(rdr, 0, 255, 0, 255);
        // 3.清除屏幕
        SDL_RenderClear(rdr);
        rect.x++;
        rect.y++;
        // 绘制
        // 1.设置渲染颜色   
        SDL_SetRenderDrawColor(rdr, 0, 0, 0, 100);
        SDL_RenderFillRect(rdr, &rect);
        // 4.渲染呈现
        SDL_RenderPresent(rdr);
        SDL_Delay(10);
    }
    // 关闭渲染器
    SDL_DestroyRenderer(rdr);
    // 5.关闭窗口
    SDL_DestroyWindow(win);
    // 6.退出
    SDL_Quit();
    system("pause");
    return 0;
}