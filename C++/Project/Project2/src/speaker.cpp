#include "speaker.h"

Speaker::Speaker()
{
}

Speaker::Speaker(string name)
{
    this->m_Name = name;
    m_Sorce[0] = 0;
    m_Sorce[1] = 0;
}

Speaker::~Speaker()
{
}
