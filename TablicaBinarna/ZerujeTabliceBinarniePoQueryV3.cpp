#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int wynikOgolny = 0;

void drukujeTablice(int dlugoscTablicyWDol, int dlugoscTablicyWPrawo, int Tablica[][100])
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
void drukujeTablice(int dlugoscTablicyWDol, int dlugoscTablicyWPrawo, bool **Tablica, bool **TablicaOperacji)
{
    for (int wiersz = 0; wiersz < dlugoscTablicyWDol; wiersz++)
    {
        for (int kolumna = 0; kolumna < dlugoscTablicyWPrawo; kolumna++)
        {
            cout << (Tablica[wiersz][kolumna] ? "1" : "0") << " ";
        }
        cout << "     ";
        for (int kolumna = 0; kolumna < dlugoscTablicyWPrawo; kolumna++)
        {
            cout << (TablicaOperacji[wiersz][kolumna] ? "X" : "O") << " ";
        }
        cout << endl;
    }
}

void obracaTablice(int dlugoscTablicyWDolOdKtorejZmieniamy, int dlugoscTablicyWPrawoOdKtorejZmieniamy, bool **Tablica)
{
    for (int i = dlugoscTablicyWDolOdKtorejZmieniamy; i >= 0; i--)
    {
        for (int j = dlugoscTablicyWPrawoOdKtorejZmieniamy; j >= 0; j--)
        {
            if (Tablica[i][j])
                Tablica[i][j] = false;
            else
                Tablica[i][j] = true;
        }
    }
}

void obracaTablice(int wspXLewegoRogu, int wspYLewegoRogu, int wspXPrawegoRogu, int wspYPrawegoRogu, bool **Tablica)
{
    for (int i = wspYLewegoRogu; i <= wspYPrawegoRogu; i++)
    {
        for (int j = wspXLewegoRogu; j <= wspXPrawegoRogu; j++)
        {
            Tablica[i][j] = !Tablica[i][j];
        }
    }
}
int ZwracaLiczbeZerowanTablicyCzolgowo(int dlugoscTablicyWDol, int dlugoscTablicyWPrawo, bool **Tablica)
{
    int licznikObrotuTablicy = 0;
    for (int i = dlugoscTablicyWDol - 1; i >= 0; i--)
    {
        for (int j = dlugoscTablicyWPrawo - 1; j >= 0; j--)
        {
            if (Tablica[i][j])
            {
                obracaTablice(i, j, Tablica);
                licznikObrotuTablicy++;
            }
        }
    }
    return licznikObrotuTablicy;
}

void WyliczaLiczbeZerowanFragmentuTablicyV3(int iloscKolum, int wspXLewegoRogu, int wspYLewegoRogu, int wspXPrawegoRogu, int wspYPrawegoRogu,
                                            bool CzyZamieniaKolumne[][100], int TablicaPolozeniaOperacji[][100],
                                            int Tablica[][100])
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
void WyliczaLiczbeZerowanFragmentuTablicyV4(int wspXLewegoRogu, int wspYLewegoRogu, int wspXPrawegoRogu, int wspYPrawegoRogu,
                                            bool **CzyZamieniaKolumne, bool **CzyZmieniaWiersz, bool **TablicaPolozeniaOperacji,
                                            bool **Tablica)
{
    for (int wiersz = wspYPrawegoRogu; wiersz >= wspYLewegoRogu - 1; wiersz--)
    {
        if (wiersz < 0)
            break;
        bool czyOdwroconyWiersz = CzyZmieniaWiersz[wiersz][wspXPrawegoRogu];
        for (int kolumna = wspXPrawegoRogu; kolumna >= wspXLewegoRogu - 1; kolumna--)
        {
            if (kolumna < 0)
                break;

            if (CzyZamieniaKolumne[wiersz][kolumna] ^ Tablica[wiersz][kolumna] ^ czyOdwroconyWiersz)
            {
                if (wiersz > 0)
                {
                    bool nowaWartosc = false;
                    if (czyOdwroconyWiersz)
                    {
                        nowaWartosc = CzyZamieniaKolumne[wiersz][kolumna];
                    }
                    else
                    {
                        nowaWartosc = !CzyZamieniaKolumne[wiersz][kolumna];
                    }
                    CzyZamieniaKolumne[wiersz - 1][kolumna] = nowaWartosc;
                }
                czyOdwroconyWiersz = !czyOdwroconyWiersz;
                if (!TablicaPolozeniaOperacji[wiersz][kolumna])
                {
                    TablicaPolozeniaOperacji[wiersz][kolumna] = true;
                    wynikOgolny++;
                }
            }
            else
            {
                if (wiersz > 0)
                {
                    bool nowaWartosc = false;
                    if (!czyOdwroconyWiersz)
                    {
                        nowaWartosc = CzyZamieniaKolumne[wiersz][kolumna];
                    }
                    else
                    {
                        nowaWartosc = !CzyZamieniaKolumne[wiersz][kolumna];
                    }
                    CzyZamieniaKolumne[wiersz - 1][kolumna] = nowaWartosc;
                }
                if (TablicaPolozeniaOperacji[wiersz][kolumna])
                {
                    TablicaPolozeniaOperacji[wiersz][kolumna] = false;
                    wynikOgolny--;
                }
            }
            if (kolumna > 0)
                CzyZmieniaWiersz[wiersz][kolumna - 1] = czyOdwroconyWiersz;
        }
    }
}
int main()
{
    //********** wczytywanie wejscia
    int dlugoscTablicyWDol = 100;
    int dlugoscTablicyWPrawo = 100;
    int iloscOperacji = 1000;
    cin >> dlugoscTablicyWDol >> dlugoscTablicyWPrawo >> iloscOperacji;

    bool **Tablica = new bool *[dlugoscTablicyWDol];
    for (int i = 0; i < dlugoscTablicyWDol; i++)
        Tablica[i] = new bool[dlugoscTablicyWPrawo]{};

    bool **TablicaPolozeniaOperacji = new bool *[dlugoscTablicyWDol];
    for (int i = 0; i < dlugoscTablicyWDol; i++)
        TablicaPolozeniaOperacji[i] = new bool[dlugoscTablicyWPrawo]{};

    bool **CzyZmieniaKolumne = new bool *[dlugoscTablicyWDol];
    for (int i = 0; i < dlugoscTablicyWDol; i++)
        CzyZmieniaKolumne[i] = new bool[dlugoscTablicyWPrawo]{};

    bool **CzyZmieniaWiersz = new bool *[dlugoscTablicyWDol];
    for (int i = 0; i < dlugoscTablicyWDol; i++)
        CzyZmieniaWiersz[i] = new bool[dlugoscTablicyWPrawo]{};

    //    int TablicaPolozeniaOperacji[100][100] = {0};
    //   bool CzyZmieniaKolumne[100][100] = {false};
    //  bool CzyZmieniaWiersz[100][100] = {false};

    bool **Tablica2 = new bool*[dlugoscTablicyWDol];
    for(int i = 0; i < dlugoscTablicyWDol; i++)
        Tablica2[i] = new bool[dlugoscTablicyWPrawo];

    for (int wiersz = 0; wiersz < iloscOperacji; wiersz++)
    {
        int wspolrzednaXLewegoRogu = rand() % 50;
        int wspolrzednaYLewegoRogu = rand() % 50;
        int wspolrzednaXPrawegoRogu = rand() % 50 + 50-1;
        int wspolrzednaYPrawegoRogu = rand() % 50 + 50-1;
        cin >> wspolrzednaYLewegoRogu >> wspolrzednaXLewegoRogu >> wspolrzednaYPrawegoRogu >> wspolrzednaXPrawegoRogu;
        wspolrzednaXLewegoRogu--;
        wspolrzednaYLewegoRogu--;
        wspolrzednaXPrawegoRogu--;
        wspolrzednaYPrawegoRogu--;
        obracaTablice(wspolrzednaXLewegoRogu, wspolrzednaYLewegoRogu, wspolrzednaXPrawegoRogu, wspolrzednaYPrawegoRogu, Tablica);
        for (int wiersz = 0; wiersz < dlugoscTablicyWDol; wiersz++)
        {
            for (int kolumna = 0; kolumna < dlugoscTablicyWPrawo; kolumna++)
            {
               Tablica2[wiersz][kolumna] = Tablica[wiersz][kolumna];
           }
         }
         int wynikCzolgowo = ZwracaLiczbeZerowanTablicyCzolgowo(dlugoscTablicyWDol, dlugoscTablicyWPrawo, Tablica2);
        // cout << " Tablica do przeliczenia: " << endl;
        WyliczaLiczbeZerowanFragmentuTablicyV4(wspolrzednaXLewegoRogu, wspolrzednaYLewegoRogu, wspolrzednaXPrawegoRogu, wspolrzednaYPrawegoRogu,
                                               CzyZmieniaKolumne, CzyZmieniaWiersz, TablicaPolozeniaOperacji, Tablica);
        //drukujeTablice(dlugoscTablicyWDol, dlugoscTablicyWPrawo, Tablica,TablicaPolozeniaOperacji);
        //cout << endl;
        cout << wynikOgolny << endl;
        if (wynikCzolgowo != wynikOgolny)
        {
            cout << "Wynik po query numer " << wiersz + 1 << " to: "
                 << " wynik ogolny: " << wynikOgolny << " wynik czolgowo: " << wynikCzolgowo << endl;
        }
        //cout << "tablica odwrocen: " << endl;
        //drukujeTablice(4, 5, CzyZmieniaKolumne);
        //cout << " Podtrzebne operacje: " << endl;
        //drukujeTablice(4, 5, TablicaPolozeniaOperacji);
        //cout << endl;
    }
    return 0;
}