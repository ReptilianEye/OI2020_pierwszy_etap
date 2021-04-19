#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <bits/stdc++.h>
#include <set>

using namespace std;

class Dziura
{
public:
    int platforma = -1;
    int kolumna = -1;
};

bool PorownujeDziury(const Dziura &l, const Dziura &r)
{
    if (l.kolumna > r.kolumna)
        return true;
    else if (l.kolumna == r.kolumna)
        if (l.platforma > r.platforma)
            return true;
    return false;
}
int ZwracaMniejszaLiczbe(int liczbaA, int liczbaB)
{
    if (liczbaA <= liczbaB)
        return liczbaA;
    else
        return liczbaB;
}
int main()
{
    //********** wczytywanie wejscia
    int iloscPlatform;
    int dlugoscPlatform;
    int iloscZapytan;
    cin >> iloscPlatform >> dlugoscPlatform >> iloscZapytan;
    Dziura *listaDziur = new Dziura[2000000];
    int iloscDziur = 0;
    int wskaznikDziur = 0;
    for (int i = 0; i < iloscPlatform; i++)
    {
        int iloscDziurNaPlatformie;
        cin >> iloscDziurNaPlatformie;
        iloscDziur = iloscDziur + iloscDziurNaPlatformie;
        for (int j = 0; j < iloscDziurNaPlatformie; j++)
        {
            Dziura dziura;
            int pozycjaDziury;
            cin >> pozycjaDziury;
            pozycjaDziury--;
            dziura.kolumna = pozycjaDziury;
            dziura.platforma = i;
            listaDziur[wskaznikDziur] = dziura;
            wskaznikDziur++;
        }
    }
    sort(listaDziur, listaDziur + iloscDziur, PorownujeDziury);

    int TablicaWynikow[iloscPlatform];
    for (int i = 0; i < iloscPlatform; i++)
    {
        TablicaWynikow[i] = 0;
    }

    for (int i = 0; i < iloscDziur; i++)
    {
        Dziura dziuraNaKtorejJestesmy = listaDziur[i];
        if (dziuraNaKtorejJestesmy.platforma == iloscPlatform - 1)      //jestesmy na najnizszej platoformie
        {
            TablicaWynikow[dziuraNaKtorejJestesmy.platforma]++;
            continue;
        }
        int NowaWartoscNaPlatformie;
        NowaWartoscNaPlatformie = ZwracaMniejszaLiczbe(TablicaWynikow[dziuraNaKtorejJestesmy.platforma] + 1,
                                                          TablicaWynikow[dziuraNaKtorejJestesmy.platforma + 1]);

        TablicaWynikow[dziuraNaKtorejJestesmy.platforma] = NowaWartoscNaPlatformie;
        TablicaWynikow[dziuraNaKtorejJestesmy.platforma + 1] = NowaWartoscNaPlatformie;
    }
    for (int i = 0; i < iloscZapytan; i++)
    {
        int ZKtorejIdziemy;
        cin >> ZKtorejIdziemy;
        ZKtorejIdziemy--;
        cout << TablicaWynikow[ZKtorejIdziemy] << endl;
    }
    return 0;
}