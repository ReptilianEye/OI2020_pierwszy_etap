#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int wynikOgolny = 0;

void drukujeTablice(int dlugoscTablicyWDol, int dlugoscTablicyWPrawo, int **Tablica)
{
    for (int wiersz = 0; wiersz < dlugoscTablicyWDol; wiersz++)
    {
        for (int kolumna = 0; kolumna < dlugoscTablicyWPrawo; kolumna++)
        {
            cout << Tablica[wiersz][kolumna] << " ";
        }
        cout << endl;
    }
}
void drukujeTablice(int dlugoscTablicyWDol, int dlugoscTablicyWPrawo, bool **Tablica)
{
    for (int wiersz = 0; wiersz < dlugoscTablicyWDol; wiersz++)
    {
        for (int kolumna = 0; kolumna < dlugoscTablicyWPrawo; kolumna++)
        {
            cout << (Tablica[wiersz][kolumna] ? "T" : "F") << " ";
        }
        cout << endl;
    }
}
void obracaTablice(int dlugoscTablicyWDolOdKtorejZmieniamy, int dlugoscTablicyWPrawoOdKtorejZmieniamy, int **Tablica)
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

void obracaTablice(int wspXLewegoRogu, int wspYLewegoRogu, int wspXPrawegoRogu, int wspYPrawegoRogu, int **Tablica)
{
    for (int i = wspYLewegoRogu; i <= wspYPrawegoRogu; i++)
    {
        for (int j = wspXLewegoRogu; j <= wspXPrawegoRogu; j++)
        {
                Tablica[i][j] = 1 - Tablica[i][j];
        }
    }
}
int ZwracaLiczbeZerowanTablicyCzolgowo(int dlugoscTablicyWDol, int dlugoscTablicyWPrawo, int **Tablica)
{
    int licznikObrotuTablicy = 0;
    for (int i = dlugoscTablicyWDol - 1; i >= 0; i--)
    {
        for (int j = dlugoscTablicyWPrawo - 1; j >= 0; j--)
        {
            if (Tablica[i][j] == 1)
            {
                obracaTablice(i, j, Tablica);
                licznikObrotuTablicy++;
            }
        }
    }
    return licznikObrotuTablicy;
}

void WyliczaLiczbeZerowanFragmentuTablicyV3(int iloscKolum, int wspXLewegoRogu, int wspYLewegoRogu, int wspXPrawegoRogu, int wspYPrawegoRogu,
                                            bool **CzyZamieniaKolumne, int **TablicaPolozeniaOperacji,
                                            int **Tablica)
{
    for (int wiersz = wspYPrawegoRogu; wiersz >= wspYLewegoRogu - 1; wiersz--)
    {
        bool czyZmieniaWiersz = false;
        if (wiersz < 0)
            break;
        for (int kolumna = iloscKolum - 1; kolumna >= wspXLewegoRogu - 1; kolumna--)
        {
            if (kolumna < 0)
                break;

            if (CzyZamieniaKolumne[wiersz][kolumna] ^ Tablica[wiersz][kolumna] == 1 ^ czyZmieniaWiersz)
            {
                if (wiersz > 0)
                {
                    bool nowaWartosc = false;
                    if (czyZmieniaWiersz)
                    {
                        nowaWartosc = CzyZamieniaKolumne[wiersz][kolumna];
                    }
                    else
                    {
                        nowaWartosc = !CzyZamieniaKolumne[wiersz][kolumna];
                    }
                    CzyZamieniaKolumne[wiersz - 1][kolumna] = nowaWartosc;
                }
                czyZmieniaWiersz = !czyZmieniaWiersz;
                if (TablicaPolozeniaOperacji[wiersz][kolumna] == 0)
                {
                    TablicaPolozeniaOperacji[wiersz][kolumna] = 1;
                    wynikOgolny++;
                }
            }
            else
            {
                if (wiersz > 0)
                {
                    bool nowaWartosc = false;
                    if (!czyZmieniaWiersz)
                    {
                        nowaWartosc = CzyZamieniaKolumne[wiersz][kolumna];
                    }
                    else
                    {
                        nowaWartosc = !CzyZamieniaKolumne[wiersz][kolumna];
                    }
                    CzyZamieniaKolumne[wiersz - 1][kolumna] = nowaWartosc;
                }
                if (TablicaPolozeniaOperacji[wiersz][kolumna] == 1)
                {
                    TablicaPolozeniaOperacji[wiersz][kolumna] = 0;
                    wynikOgolny--;
                }
            }
        }
    }
}

int main()
{
    //********** wczytywanie wejscia
    int dlugoscTablicyWDol;
    int dlugoscTablicyWPrawo;
    int iloscOperacji;
    cin >> dlugoscTablicyWDol >> dlugoscTablicyWPrawo >> iloscOperacji;

    int **Tablica = new int *[dlugoscTablicyWDol];
    for (int i = 0; i < dlugoscTablicyWDol; i++)
        Tablica[i] = new int[dlugoscTablicyWPrawo]{};

    int **TablicaPolozeniaOperacji = new int *[dlugoscTablicyWDol];
    for (int i = 0; i < dlugoscTablicyWDol; i++)
        TablicaPolozeniaOperacji[i] = new int[dlugoscTablicyWPrawo]{};

    bool **CzyZmieniaKomorke = new bool *[dlugoscTablicyWDol];
    for (int i = 0; i < dlugoscTablicyWDol; i++)
        CzyZmieniaKomorke[i] = new bool[dlugoscTablicyWPrawo]{};

    for (int wiersz = 0; wiersz < iloscOperacji; wiersz++)
    {
        int wspolrzednaXLewegoRogu;
        int wspolrzednaYLewegoRogu;
        int wspolrzednaXPrawegoRogu;
        int wspolrzednaYPrawegoRogu;
        cin >> wspolrzednaYLewegoRogu >> wspolrzednaXLewegoRogu >> wspolrzednaYPrawegoRogu >> wspolrzednaXPrawegoRogu;
        wspolrzednaXLewegoRogu--;
        wspolrzednaYLewegoRogu--;
        wspolrzednaXPrawegoRogu--;
        wspolrzednaYPrawegoRogu--;
        obracaTablice(wspolrzednaXLewegoRogu, wspolrzednaYLewegoRogu, wspolrzednaXPrawegoRogu, wspolrzednaYPrawegoRogu, Tablica);
        WyliczaLiczbeZerowanFragmentuTablicyV3(dlugoscTablicyWPrawo, wspolrzednaXLewegoRogu, wspolrzednaYLewegoRogu, wspolrzednaXPrawegoRogu, wspolrzednaYPrawegoRogu,
                                               CzyZmieniaKomorke, TablicaPolozeniaOperacji, Tablica);
        cout << wynikOgolny << endl;
    }
    return 0;
}