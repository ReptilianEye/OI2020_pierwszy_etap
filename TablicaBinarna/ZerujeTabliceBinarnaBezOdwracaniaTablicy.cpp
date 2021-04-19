#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int Tablica[100][100] = {0};
int TablicaPolozeniaOperacji[100][100] = {0};

void drukujeTablice(int dlugoscTablicyWDol, int dlugoscTablicyWPrawo, int Tablica[][100])
{
    for (int i = 0; i < dlugoscTablicyWDol; i++)
    {
        for (int j = 0; j < dlugoscTablicyWPrawo; j++)
        {
            cout << Tablica[i][j] << " ";
        }
        cout << endl;
    }
}
int ZwracaLiczbeZerowanTablicyBoolami(int dlugoscTablicyWDol, int dlugoscTablicyWPrawo, int Tablica[][100])
{
    bool CzyZmieniaKolumne[dlugoscTablicyWPrawo] = {false};
    int licznikObrotuTablicy = 0;
    for (int i = dlugoscTablicyWDol - 1; i >= 0; i--)
    {
        int licznikOperacjiWFragmencie = 0;
        for (int j = dlugoscTablicyWPrawo - 1; j >= 0; j--)
        {

            if (CzyZmieniaKolumne[j])
            {
                if (Tablica[i][j] == 0)
                {
                    int k = j;
                    while (k >= 0)
                    {
                        CzyZmieniaKolumne[k] = !CzyZmieniaKolumne[k];
                        k--;
                    }
                    licznikOperacjiWFragmencie++;
                    licznikObrotuTablicy++;
                    TablicaPolozeniaOperacji[i][j]++;
                }
            }
            else
            {
                if (Tablica[i][j] == 1)
                {
                    int k = j;
                    while (k >= 0)
                    {
                        CzyZmieniaKolumne[k] = !CzyZmieniaKolumne[k];
                        k--;
                    }
                    licznikOperacjiWFragmencie++;
                    licznikObrotuTablicy++;
                    TablicaPolozeniaOperacji[i][j]++;
                    continue;
                }
            }
        }
        //cout << licznikOperacjiWFragmencie << endl;
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
    drukujeTablice(dlugoscTablicyWDol, dlugoscTablicyWPrawo,Tablica);
    int wynik = ZwracaLiczbeZerowanTablicyBoolami(dlugoscTablicyWDol, dlugoscTablicyWPrawo, Tablica);
    cout << "Ilosc operacji metoda z boolami to: " << wynik << endl;
    drukujeTablice(dlugoscTablicyWDol, dlugoscTablicyWPrawo,TablicaPolozeniaOperacji);
    cout << "-------------------------" << endl;
    return 0;
}