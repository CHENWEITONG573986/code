#include "orderFile.h"

OrderFile::OrderFile()
{
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);
    string data;
    string interval;
    string id;
    string name;
    string room;
    string status;
    this->m_Size = 0;
    while (ifs >> data && ifs >> interval && ifs >> id && ifs >> name && ifs >> room && ifs >> status)
    {
        string key;
        string value;
        map<string, string> m;
        int pos = data.find(":");
        if (pos != -1)
        {
            key = data.substr(0, pos);
            value = data.substr(pos + 1, data.size());
            m.insert(make_pair(key, value));
        }
        pos = interval.find(":");
        if (pos != -1)
        {
            key = interval.substr(0, pos);
            value = interval.substr(pos + 1, interval.size());
            m.insert(make_pair(key, value));
        }
        pos = id.find(":");
        if (pos != -1)
        {
            key = id.substr(0, pos);
            value = id.substr(pos + 1, id.size());
            m.insert(make_pair(key, value));
        }
        pos = name.find(":");
        if (pos != -1)
        {
            key = name.substr(0, pos);
            value = name.substr(pos + 1, name.size());
            m.insert(make_pair(key, value));
        }
        pos = room.find(":");
        if (pos != -1)
        {
            key = room.substr(0, pos);
            value = room.substr(pos + 1, room.size());
            m.insert(make_pair(key, value));
        }
        pos = status.find(":");
        if (pos != -1)
        {
            key = status.substr(0, pos);
            value = status.substr(pos + 1, status.size());
            m.insert(make_pair(key, value));
        }
        m_orderData.insert(make_pair(m_Size, m));
        m_Size++;
    }
    ifs.close();
}
void OrderFile::updataOrder()
{
    if (!m_Size)
        return;
    ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
    for (int i = 0; i < m_Size; i++)
    {
        ofs << "Data:" << m_orderData[i]["Data"] << " ";
        ofs << "Interval:" << m_orderData[i]["Interval"] << " ";
        ofs << "Id:" << m_orderData[i]["Id"] << " ";
        ofs << "Name:" << m_orderData[i]["Name"] << " ";
        ofs << "Room:" << m_orderData[i]["Room"] << " ";
        ofs << "Status:" << m_orderData[i]["Status"] << endl;
    }
    ofs.close();
}