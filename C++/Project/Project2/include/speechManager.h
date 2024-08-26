#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include "speaker.h"
using namespace std;
// 比赛管理类
class SpeechManager
{
public:
    vector<int> V1, V2, Winner;
    map<int, Speaker> m_Speaker;
    int m_Index;
    bool fileEmpty;
    map<int, vector<string>> m_Record;

public:
    SpeechManager();
    // 初始化
    void initSpeech();
    // 展示菜单
    void show_Menu();
    // 创建选手
    void createSpeaker();
    // 比赛开始
    void startSpeech();
    // 抽签
    void speechDraw();
    // 比赛
    void speechContest();
    // 显示比赛结果
    void showScore();
    // 保存记录
    void saveRecord();
    // 读取记录
    void loadRecord();
    // 查看记录
    void showRecord();
    // 清空记录
    void clearRecord();
    // 退出系统
    void exitSystem();
    ~SpeechManager();
};