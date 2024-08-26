#include <speechManager.h>

SpeechManager::SpeechManager()
{
    this->initSpeech();
    this->createSpeaker();
    this->loadRecord();
}

void SpeechManager::initSpeech()
{
    this->V1.clear();
    this->V2.clear();
    this->Winner.clear();
    this->m_Speaker.clear();
    this->m_Record.clear();
    this->m_Index = 1;
}

void SpeechManager::show_Menu()
{
    cout << "1.比赛开始" << endl;
    cout << "2.查看记录" << endl;
    cout << "3.清空记录" << endl;
    cout << "0.退出系统" << endl;
    cout << endl;
}

void SpeechManager::createSpeaker()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++)
    {
        string name = "选手";
        name += nameSeed[i];
        Speaker sp(name);
        this->V1.push_back(i + 10001);
        this->m_Speaker.insert(pair<int, Speaker>(i + 10001, sp));
    }
}

void SpeechManager::startSpeech()
{
    this->speechDraw();
    this->speechContest();
    this->showScore();
    this->m_Index++;
    this->speechDraw();
    this->speechContest();
    this->showScore();
    this->saveRecord();
    // 重置
    this->initSpeech();
    this->createSpeaker();
    this->loadRecord();
    cout << "本届比赛完美谢幕！！！" << endl;
    system("pause");
    system("cls");
}

void SpeechManager::speechDraw()
{
    cout << "第" << this->m_Index << "轮比赛" << endl;
    cout << "------------------------------" << endl;
    cout << "抽签结果如下:" << endl;
    if (this->m_Index == 1)
    {
        random_shuffle(V1.begin(), V1.end());
        for (auto c : V1)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    else
    {
        random_shuffle(V2.begin(), V2.end());
        for (auto c : V2)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << "------------------------------" << endl;
    system("pause");
    cout << endl;
}

void SpeechManager::speechContest()
{
    cout << "第" << this->m_Index << "轮比赛开始" << endl;
    cout << "------------------------------" << endl;
    multimap<double, int, greater<double>> groupScore;
    int num = 0;
    vector<int> V;
    if (this->m_Index == 1)
        V = this->V1;
    else
        V = this->V2;
    for (int c : V)
    {
        num++;
        deque<double> d;
        for (int i = 0; i < 10; i++)
        {
            double score = rand() % 401 + 600 / 10.f;
            // cout << score << " ";
            d.push_back(score);
        }
        // cout << endl;
        sort(d.begin(), d.end(), greater<double>());
        d.pop_back();
        d.pop_front();
        double sum = accumulate(d.begin(), d.end(), 0.0f);
        double avg = sum / (double)d.size();
        // cout << "编号：" << c << " 姓名:" << this->m_Speaker[c].m_Name << " 得分：" << avg << endl;
        this->m_Speaker[c].m_Sorce[this->m_Index - 1] = avg;
        groupScore.insert(make_pair(avg, c));
        if (num % 6 == 0)
        {
            cout << "第" << num / 6 << "小组比赛名次如下：" << endl;
            for (auto g : groupScore)
            {
                cout << "编号：" << g.second
                     << " 姓名：" << this->m_Speaker[g.second].m_Name
                     << " 得分：" << g.first
                     << endl;
            }
            int count = 0;
            for (auto g : groupScore)
            {
                if (this->m_Index == 1)
                {
                    this->V2.push_back(g.second);
                }
                else
                {
                    this->Winner.push_back(g.second);
                }
                count++;
                if (count == 3)
                    break;
            }
            groupScore.clear();
        }
    }
    cout << "第" << this->m_Index << "轮比赛结束" << endl;
    system("pause");
    cout << endl;
}

void SpeechManager::showScore()
{
    cout << "第" << this->m_Index << "轮晋级选手如下：" << endl;
    cout << "------------------------------" << endl;
    vector<int> V;
    if (this->m_Index == 1)
        V = this->V2;
    else
        V = this->Winner;
    for (auto c : V)
    {
        cout << "编号：" << c
             << " 姓名:" << this->m_Speaker[c].m_Name
             << " 得分：" << this->m_Speaker[c].m_Sorce[this->m_Index - 1]
             << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
    this->show_Menu();
}

void SpeechManager::saveRecord()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);
    for (auto c : Winner)
    {
        ofs << c << "," << this->m_Speaker[c].m_Sorce[1] << ",";
    }
    ofs << endl;
    ofs.close();
    cout << "记录保存成功！！！" << endl;
    this->fileEmpty = false;
}

void SpeechManager::loadRecord()
{
    ifstream ifs("speech.csv", ios::in);
    if (!ifs.is_open())
    {
        this->fileEmpty = true;
        cout << "文件不存在！！！" << endl;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        this->fileEmpty = true;
        cout << "文件为空！！！" << endl;
        ifs.close();
        return;
    }
    this->fileEmpty = false;
    ifs.putback(ch);
    string data;
    int index = 0;
    while (ifs >> data)
    {
        vector<string> V;
        int pos = -1;
        int start = 0;
        while (true)
        {
            pos = data.find(",", start);
            if (pos == -1)
                break;
            string tmp = data.substr(start, pos - start);
            V.push_back(tmp);
            start = pos + 1;
        }
        index++;
        this->m_Record.insert(make_pair(index, V));
    }
    ifs.close();
}

void SpeechManager::showRecord()
{
    if (this->fileEmpty)
    {
        cout << "文件为空！！！" << endl;
    }
    else
    {
        for (auto c : m_Record)
        {
            cout << "第" << c.first << "届比赛" << endl;
            cout << "冠军编号：" << c.second[0] << " 得分：" << c.second[1] << endl;
            cout << "亚军编号：" << c.second[2] << " 得分：" << c.second[3] << endl;
            cout << "季军编号：" << c.second[4] << " 得分：" << c.second[5] << endl;
            cout << endl;
        }
    }

    system("pause");
    system("cls");
}

void SpeechManager::clearRecord()
{
    cout << "确定清空？" << endl;
    cout << "1.确认" << endl;
    cout << "2.返回" << endl;
    int select;
    cin >> select;
    if (select == 1)
    {
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();
        this->initSpeech();
        this->createSpeaker();
        this->loadRecord();
        cout << "清空成功！！！" << endl;
    }
    system("pause");
    system("cls");
}

void SpeechManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

SpeechManager::~SpeechManager()
{
}
