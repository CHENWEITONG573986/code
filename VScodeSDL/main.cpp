#include <iostream>
#include <string>
#include "class.h"
#include "SDL.h"
#include "SDL_image.h"
using namespace std;
int main(int, char **)
{
    // 1.初始化 视频和音频
    // 成功返回0，失败返回负数
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
    // 在窗口绘制一个矩形
    // 获得和与窗口关联的Surface
    // SDL_Surface *surf = SDL_GetWindowSurface(win);
    // if (surf == NULL)
    // {
    //     // 输出报错
    //     SDL_Log("SDL_GetWindowSurface failed: %s", SDL_GetError());
    //     return -1;
    // }
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
    // 渲染点，线
    SDL_SetRenderDrawColor(rdr, 0, 0, 0, 255);
    SDL_RenderDrawPoint(rdr,200,200);
    for(int i=20;i<200;i+=5)
    {
        SDL_RenderDrawPoint(rdr, i, 200);
    }
    // (0,0)到(200,200)的直线
    SDL_RenderDrawLine(rdr,0,0,200,200);
    // 4.渲染呈现
    SDL_RenderPresent(rdr);
    
    // // 修改像素点颜色值
    // Uint32 *px = (Uint32 *)surf->pixels;
    // for(int i=2000;i<20000;i+=5)
    // {
    //     px[i]=0xffffffff;
    // }
    // 定义一个区域
    // SDL_Rect rect = {0, 0, 100, 100};
    // // 在Surface上绘制
    // SDL_FillRect(surf, &rect, 0xff0000);
    // // 将绘制的类容绘制到屏幕上
    // SDL_UpdateWindowSurface(win);
    // 显示图片
    // 导入图片
    // SDL_Surface *bmp_surf = SDL_LoadBMP("cs2.bmp");
    // if (bmp_surf == NULL)
    // {
    //     // 输出报错
    //     SDL_Log("SDL_LoadBMP failed: %s", SDL_GetError());
    //     return -1;
    // }
    // // 将图片Surface复制到窗口Surface上
    // SDL_BlitSurface(bmp_surf,NULL,surf,NULL);
    // 将绘制的类容绘制到屏幕上
    SDL_UpdateWindowSurface(win);
    // 3.窗口停留时间
    // SDL_Delay(3000);
    // 事件监听与响应
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
    }
    // 释放BMP图片
    // SDL_FreeSurface(bmp_surf);
    // 释放surface
    //SDL_FreeSurface(surf);
    SDL_DestroyRenderer(rdr);
    // 5.关闭窗口
    SDL_DestroyWindow(win);
    // 6.退出
    SDL_Quit();
    system("pause");
    return 0;
}