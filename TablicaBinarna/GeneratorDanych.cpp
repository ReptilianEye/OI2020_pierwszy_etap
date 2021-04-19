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
    int dlugoscWDol = 1000;
    int dlugoscWPrawo = 1000;
    int liczbaOperacji = 15000;
    cout << dlugoscWDol << " " << dlugoscWPrawo << " " << liczbaOperacji << endl;
    for (int i = 0; i < dlugoscWDol; i++)
    {
        for (int j = 0; j < dlugoscWPrawo; j++)
        {
            int losowa = rand() & 1;
            cout << losowa << " ";
        }
        cout << endl;
    }
    return 0;
}