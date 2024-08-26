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
    cout << "1.������ʼ" << endl;
    cout << "2.�鿴��¼" << endl;
    cout << "3.��ռ�¼" << endl;
    cout << "0.�˳�ϵͳ" << endl;
    cout << endl;
}

void SpeechManager::createSpeaker()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++)
    {
        string name = "ѡ��";
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
    // ����
    this->initSpeech();
    this->createSpeaker();
    this->loadRecord();
    cout << "�����������лĻ������" << endl;
    system("pause");
    system("cls");
}

void SpeechManager::speechDraw()
{
    cout << "��" << this->m_Index << "�ֱ���" << endl;
    cout << "------------------------------" << endl;
    cout << "��ǩ�������:" << endl;
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
    cout << "��" << this->m_Index << "�ֱ�����ʼ" << endl;
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
        // cout << "��ţ�" << c << " ����:" << this->m_Speaker[c].m_Name << " �÷֣�" << avg << endl;
        this->m_Speaker[c].m_Sorce[this->m_Index - 1] = avg;
        groupScore.insert(make_pair(avg, c));
        if (num % 6 == 0)
        {
            cout << "��" << num / 6 << "С������������£�" << endl;
            for (auto g : groupScore)
            {
                cout << "��ţ�" << g.second
                     << " ������" << this->m_Speaker[g.second].m_Name
                     << " �÷֣�" << g.first
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
    cout << "��" << this->m_Index << "�ֱ�������" << endl;
    system("pause");
    cout << endl;
}

void SpeechManager::showScore()
{
    cout << "��" << this->m_Index << "�ֽ���ѡ�����£�" << endl;
    cout << "------------------------------" << endl;
    vector<int> V;
    if (this->m_Index == 1)
        V = this->V2;
    else
        V = this->Winner;
    for (auto c : V)
    {
        cout << "��ţ�" << c
             << " ����:" << this->m_Speaker[c].m_Name
             << " �÷֣�" << this->m_Speaker[c].m_Sorce[this->m_Index - 1]
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
    cout << "��¼����ɹ�������" << endl;
    this->fileEmpty = false;
}

void SpeechManager::loadRecord()
{
    ifstream ifs("speech.csv", ios::in);
    if (!ifs.is_open())
    {
        this->fileEmpty = true;
        cout << "�ļ������ڣ�����" << endl;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        this->fileEmpty = true;
        cout << "�ļ�Ϊ�գ�����" << endl;
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
        cout << "�ļ�Ϊ�գ�����" << endl;
    }
    else
    {
        for (auto c : m_Record)
        {
            cout << "��" << c.first << "�����" << endl;
            cout << "�ھ���ţ�" << c.second[0] << " �÷֣�" << c.second[1] << endl;
            cout << "�Ǿ���ţ�" << c.second[2] << " �÷֣�" << c.second[3] << endl;
            cout << "������ţ�" << c.second[4] << " �÷֣�" << c.second[5] << endl;
            cout << endl;
        }
    }

    system("pause");
    system("cls");
}

void SpeechManager::clearRecord()
{
    cout << "ȷ����գ�" << endl;
    cout << "1.ȷ��" << endl;
    cout << "2.����" << endl;
    int select;
    cin >> select;
    if (select == 1)
    {
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();
        this->initSpeech();
        this->createSpeaker();
        this->loadRecord();
        cout << "��ճɹ�������" << endl;
    }
    system("pause");
    system("cls");
}

void SpeechManager::exitSystem()
{
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);
}

SpeechManager::~SpeechManager()
{
}
