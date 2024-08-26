#include <iostream>
#include <ctime>
#include "speechManager.h"
using namespace std;
int main()
{
    srand((unsigned int)time(NULL));
    SpeechManager SM;
    int choice = 0;
    while (true)
    {
        SM.show_Menu();
        cout << "ÇëÊäÈëÄãµÄÑ¡Ôñ£º";
        cin >> choice;
        switch (choice)
        {
        case 1:
            SM.startSpeech();
            break;
        case 2:
            SM.showRecord();
            break;
        case 3:
            SM.clearRecord();
            break;
        case 0:
            SM.exitSystem();
            break;
        default:
            system("cls");
            break;
        }
    }
    system("pause");
    return 0;
}
