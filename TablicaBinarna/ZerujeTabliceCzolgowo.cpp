#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int Tablica[100][100] = {0};
int TablicaPolozeniaOperacji[100][100] = {0};

void drukujeTablice(int dlugoscTablicyWDol, int dlugoscTablicyWPrawo, int Tablica[][100], int Tablica2[][100])
{
    for (int i = 0; i < dlugoscTablicyWDol; i++)
    {
        for (int j = 0; j < dlugoscTablicyWPrawo; j++)
        {
            cout << Tablica[i][j] << " ";
        }
        cout << "      ";
        for (int j = 0; j < dlugoscTablicyWPrawo; j++)
        {
            cout << Tablica2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void obracaTablice(int dlugoscTablicyWDolOdKtorejZmieniamy, int dlugoscTablicyWPrawoOdKtorejZmieniamy, int Tablica[][100])
{
    for (int i = dlugoscTablicyWDolOdKtorejZmieniamy; i >= 0; i--)
    {
        for (int j = dlugoscTablicyWPrawoOdKtorejZmieniamy; j >= 0; j--)
        {
            if (Tablica[i][j] == 1)
                Tablica[i][j] = 0;
            else
                Tablica[i][j] = 1;
        }
    }
}
int ZwracaLiczbeZerowanTablicyCzolgowo(int dlugoscTablicyWDol, int dlugoscTablicyWPrawo, int Tablica[][100])
{
    int licznikObrotuTablicy = 0;
    for (int i = dlugoscTablicyWDol - 1; i >= 0; i--)
    {
        for (int j = dlugoscTablicyWPrawo - 1; j >= 0; j--)
        {
            if (Tablica[i][j] == 1)
            {
                TablicaPolozeniaOperacji[i][j] = 1;
                obracaTablice(i, j, Tablica);
                drukujeTablice(dlugoscTablicyWDol,dlugoscTablicyWPrawo,Tablica,TablicaPolozeniaOperacji);
                licznikObrotuTablicy++;
            }
        }
    }
    return licznikObrotuTablicy;
}
int main()
{
    //********** wczytywanie wejscia
    int dlugoscTablicyWDol;
    int dlugoscTablicyWPrawo;
    int iloscOperacji;
    cin >> dlugoscTablicyWDol >> dlugoscTablicyWPrawo >> iloscOperacji;

    for (int i = 0; i < dlugoscTablicyWDol; i++)
    {
        for (int j = 0; j < dlugoscTablicyWPrawo; j++)
        {
            cin >> Tablica[i][j]; //Wczytywanie tablicy
        }
    }
    drukujeTablice(dlugoscTablicyWDol,dlugoscTablicyWPrawo,Tablica,TablicaPolozeniaOperacji);
    int wynik = ZwracaLiczbeZerowanTablicyCzolgowo(dlugoscTablicyWDol, dlugoscTablicyWPrawo, Tablica);
    cout << wynik << endl;
}