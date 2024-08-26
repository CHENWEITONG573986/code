#include "SDL.h"
Uint8 *audio_buf;
Uint32 audio_len;
Uint32 audio_pos = 0;
SDL_AudioDeviceID device_id;
void callback(void *userdata, Uint8 *stream, int len)
{
    int remain = audio_len - audio_pos;
    if (remain > len)
    {
        SDL_memcmp(stream, audio_buf + audio_pos, len);
        audio_pos += len;
    }
    else
    {
        SDL_memcpy(stream, audio_buf + audio_pos, remain);
        audio_pos = 0;
    }
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
    SDL_AudioSpec audio_spec;
    // 导入wav文件
    if(SDL_LoadWAV("1.wav", &audio_spec, &audio_buf, &audio_len)==NULL)
    {
        SDL_Log("SDL_LoadWAV failed: %s", SDL_GetError());
        return -1;
    }
    audio_spec.callback = callback;
    audio_spec.userdata = (void *)"这是外部传进来的数据";
    // 打开音频设备
    device_id = SDL_OpenAudioDevice(NULL, 0, &audio_spec, NULL, 0);
    // 播放音频
    SDL_PauseAudioDevice(device_id, 0);
    
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
    // 关闭音频设备
    SDL_CloseAudioDevice(device_id);
    SDL_FreeWAV(audio_buf);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}