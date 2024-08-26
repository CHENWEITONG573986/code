#include "GUI.h"
#include <iostream>
using namespace std;
GUImanager::GUImanager()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        // 输出报错
        SDL_Log("Init failed: %s", SDL_GetError());
        // return -1;
    }
}
GUImanager::~GUImanager()
{
    SDL_Quit();
}
void GUImanager::menuShow()
{
    // 创建窗口
    win = SDL_CreateWindow("Menu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
    if (win == NULL)
    {
        // 输出报错
        SDL_Log("Create window failed: %s", SDL_GetError());
        // return -1;
    }
}