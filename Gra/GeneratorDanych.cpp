#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <fcntl.h>

using namespace std;

int main()
{
    _setmode(_fileno(stdout), _O_TEXT);
    srand((unsigned)time(NULL));
    int iloscPlatform = 100000;
    int iloscDziurNaPlatformie = 2000000 / iloscPlatform;
    int liczbaOperacji = 100000;
    cout << iloscPlatform << " " << 1000000000 << " " << liczbaOperacji << endl;
    for (int i = 0; i < iloscPlatform; i++)
    {
        cout << iloscDziurNaPlatformie << " ";
        for (int j = 0; j < iloscDziurNaPlatformie; j++)
        {
            cout << rand() % 1000000000 << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < liczbaOperacji; i++)
    {
        cout << i << " ";
    }
    return 0;
}