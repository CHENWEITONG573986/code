#include "SDL.h"
// GUI类
class GUI
{private:
    int weight;
    int height;
    SDL_Rect rect;
public:
    //GUI(int x, int y);
    void draw();
    void update();
    void close();
};
// GUI管理类
class GUImanager
{
private:
    SDL_Window *win = NULL;
    //GUI menu;

public:
    GUImanager();
    void menuShow();
    ~GUImanager();
};