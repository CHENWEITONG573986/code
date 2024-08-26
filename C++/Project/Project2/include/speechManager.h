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
// ����������
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
    // ��ʼ��
    void initSpeech();
    // չʾ�˵�
    void show_Menu();
    // ����ѡ��
    void createSpeaker();
    // ������ʼ
    void startSpeech();
    // ��ǩ
    void speechDraw();
    // ����
    void speechContest();
    // ��ʾ�������
    void showScore();
    // �����¼
    void saveRecord();
    // ��ȡ��¼
    void loadRecord();
    // �鿴��¼
    void showRecord();
    // ��ռ�¼
    void clearRecord();
    // �˳�ϵͳ
    void exitSystem();
    ~SpeechManager();
};