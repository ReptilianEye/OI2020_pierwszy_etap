#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class DaneOWypieku
{
public:
    int ilosc = 0;
    bool czyWygral = false;
    bool czyWygral2raz = false;
};
class Roznica
{
public:
    int najmniejszaRoznica = INT32_MAX;
    int pozycjaRoznicy = -1;
    int drugaNajmniejszaRoznica = INT32_MAX;
};

int main()
{
    //********** wczytywanie wejscia
    int liczbaGablot;
    cin >> liczbaGablot;

    int SumaOperacji = 0;
    int lider = 0;

    DaneOWypieku drozdzowka;
    DaneOWypieku paczek;
    DaneOWypieku rogalik;

    Roznica drozdzowki;
    Roznica paczki;
    Roznica rogaliki;

    for (int i = 0; i < liczbaGablot; i++)
    {
        cin >> drozdzowka.ilosc >> paczek.ilosc >> rogalik.ilosc;
        if (drozdzowka.ilosc == paczek.ilosc && paczek.ilosc == rogalik.ilosc)
        {
            SumaOperacji = SumaOperacji + drozdzowka.ilosc * 2;
            continue;
        }
        if (drozdzowka.ilosc >= paczek.ilosc && drozdzowka.ilosc >= rogalik.ilosc)
        {
            if (drozdzowka.ilosc == paczek.ilosc)
                if (paczek.czyWygral)
                    lider = drozdzowka.ilosc;
                else
                {
                    lider = paczek.ilosc;
                    paczek.czyWygral = true;
                }
            if (drozdzowka.ilosc == rogalik.ilosc)
                if (rogalik.czyWygral)
                    lider = drozdzowka.ilosc;
                else
                {
                    lider = rogalik.ilosc;
                    rogalik.czyWygral = true;
                }

                /////////////////////////////////////////////////
            if (drozdzowka.czyWygral)
            {
                drozdzowka.czyWygral2raz = true;
                if (paczki.najmniejszaRoznica > lider - paczek.ilosc)
                {
                    paczki.najmniejszaRoznica = lider - paczek.ilosc;
                    paczki.pozycjaRoznicy = i;
                }
                if (paczki.drugaNajmniejszaRoznica > lider - paczek.ilosc && paczki.pozycjaRoznicy != i)
                {
                    paczki.drugaNajmniejszaRoznica = lider - paczek.ilosc;
                }
                if (rogaliki.najmniejszaRoznica > lider - rogalik.ilosc)
                {
                    rogaliki.najmniejszaRoznica = lider - rogalik.ilosc;
                    rogaliki.pozycjaRoznicy = i;
                }
                if (rogaliki.drugaNajmniejszaRoznica > lider - rogalik.ilosc && rogaliki.pozycjaRoznicy != i)
                {
                    rogaliki.drugaNajmniejszaRoznica = lider - rogalik.ilosc;
                }
            }
            else
            {
                drozdzowka.czyWygral = true;
            }
            SumaOperacji = SumaOperacji + paczek.ilosc + rogalik.ilosc;
            continue;
        }
        if (paczek.ilosc >= drozdzowka.ilosc && paczek.ilosc >= rogalik.ilosc)
        {
            lider = paczek.ilosc;
            if (paczek.czyWygral)
            {
                paczek.czyWygral2raz = true;
                if (drozdzowki.najmniejszaRoznica > lider - drozdzowka.ilosc)
                {
                    drozdzowki.najmniejszaRoznica = lider - drozdzowka.ilosc;
                    drozdzowki.pozycjaRoznicy = i;
                }
                if (drozdzowki.drugaNajmniejszaRoznica > lider - drozdzowka.ilosc && drozdzowki.pozycjaRoznicy != i)
                {
                    drozdzowki.drugaNajmniejszaRoznica = lider - drozdzowka.ilosc;
                }
                if (rogaliki.najmniejszaRoznica > lider - rogalik.ilosc)
                {
                    rogaliki.najmniejszaRoznica = lider - rogalik.ilosc;
                    rogaliki.pozycjaRoznicy = i;
                }
                if (rogaliki.drugaNajmniejszaRoznica > lider - rogalik.ilosc && rogaliki.pozycjaRoznicy != i)
                {
                    rogaliki.drugaNajmniejszaRoznica = lider - rogalik.ilosc;
                }
            }
            else
            {
                paczek.czyWygral = true;
            }
            SumaOperacji = SumaOperacji + drozdzowka.ilosc + rogalik.ilosc;
            continue;
        }
        if (rogalik.ilosc >= drozdzowka.ilosc && rogalik.ilosc >= paczek.ilosc)
        {
            lider = rogalik.ilosc;
            if (rogalik.czyWygral)
            {
                rogalik.czyWygral2raz = true;
                if (drozdzowki.najmniejszaRoznica > lider - drozdzowka.ilosc)
                {
                    drozdzowki.najmniejszaRoznica = lider - drozdzowka.ilosc;
                    drozdzowki.pozycjaRoznicy = i;
                }
                if (drozdzowki.drugaNajmniejszaRoznica > lider - drozdzowka.ilosc && drozdzowki.pozycjaRoznicy != i)
                {
                    drozdzowki.drugaNajmniejszaRoznica = lider - drozdzowka.ilosc;
                }
                if (paczki.najmniejszaRoznica > lider - paczek.ilosc)
                {
                    paczki.najmniejszaRoznica = lider - paczek.ilosc;
                    paczki.pozycjaRoznicy = i;
                }
                if (paczki.drugaNajmniejszaRoznica > lider - paczek.ilosc && paczki.pozycjaRoznicy != i)
                {
                    paczki.drugaNajmniejszaRoznica = lider - paczek.ilosc;
                }
            }
            else
            {
                rogalik.czyWygral = true;
            }
            SumaOperacji = SumaOperacji + drozdzowka.ilosc + paczek.ilosc;
            continue;
        }
    }

    if (!drozdzowka.czyWygral && !paczek.czyWygral && !rogalik.czyWygral)
    {
        cout << SumaOperacji;
        return 0;
    }
    if (!drozdzowka.czyWygral)
        if (rogalik.czyWygral && paczek.czyWygral)
            SumaOperacji = SumaOperacji + drozdzowki.najmniejszaRoznica;
        else
        {
            if (!rogalik.czyWygral)
            {
                if (drozdzowki.pozycjaRoznicy == rogaliki.pozycjaRoznicy)
                {
                    if (drozdzowki.najmniejszaRoznica + rogaliki.drugaNajmniejszaRoznica < drozdzowki.drugaNajmniejszaRoznica + rogaliki.najmniejszaRoznica)
                    {
                        SumaOperacji = SumaOperacji + drozdzowki.najmniejszaRoznica + rogaliki.drugaNajmniejszaRoznica;
                    }
                    else
                    {
                        SumaOperacji = SumaOperacji + drozdzowki.drugaNajmniejszaRoznica + rogaliki.najmniejszaRoznica;
                    }
                    cout << SumaOperacji;
                    return 0;
                }
                else
                {
                    SumaOperacji = SumaOperacji + drozdzowki.najmniejszaRoznica + rogaliki.najmniejszaRoznica;
                }
            }
            if (!paczek.czyWygral)
            {
                if (drozdzowki.pozycjaRoznicy == paczki.pozycjaRoznicy)
                {
                    if (drozdzowki.najmniejszaRoznica + paczki.drugaNajmniejszaRoznica < drozdzowki.drugaNajmniejszaRoznica + paczki.najmniejszaRoznica)
                    {
                        SumaOperacji = SumaOperacji + drozdzowki.najmniejszaRoznica + paczki.drugaNajmniejszaRoznica;
                    }
                    else
                    {
                        SumaOperacji = SumaOperacji + drozdzowki.drugaNajmniejszaRoznica + paczki.najmniejszaRoznica;
                    }
                    cout << SumaOperacji;
                    return 0;
                }
                else
                {
                    SumaOperacji = SumaOperacji + drozdzowki.najmniejszaRoznica + paczki.najmniejszaRoznica;
                }
            }
        }

    if (!paczek.czyWygral)
        if (rogalik.czyWygral && drozdzowka.czyWygral)
        {
            SumaOperacji = SumaOperacji + paczki.najmniejszaRoznica;
        }
        else
        {
            if (!rogalik.czyWygral)
            {
                if (paczki.pozycjaRoznicy == rogaliki.pozycjaRoznicy)
                {
                    if (paczki.najmniejszaRoznica + rogaliki.drugaNajmniejszaRoznica < paczki.drugaNajmniejszaRoznica + rogaliki.najmniejszaRoznica)
                    {
                        SumaOperacji = SumaOperacji + paczki.najmniejszaRoznica + rogaliki.drugaNajmniejszaRoznica;
                    }
                    else
                    {
                        SumaOperacji = SumaOperacji + paczki.drugaNajmniejszaRoznica + rogaliki.najmniejszaRoznica;
                    }
                    cout << SumaOperacji;
                    return 0;
                }
                else
                {
                    SumaOperacji = SumaOperacji + paczki.najmniejszaRoznica + rogaliki.najmniejszaRoznica;
                }
            }
            if (!drozdzowka.czyWygral)
            {
                if (drozdzowki.pozycjaRoznicy == paczki.pozycjaRoznicy)
                {
                    if (drozdzowki.najmniejszaRoznica + paczki.drugaNajmniejszaRoznica < drozdzowki.drugaNajmniejszaRoznica + paczki.najmniejszaRoznica)
                    {
                        SumaOperacji = SumaOperacji + drozdzowki.najmniejszaRoznica + paczki.drugaNajmniejszaRoznica;
                    }
                    else
                    {
                        SumaOperacji = SumaOperacji + drozdzowki.drugaNajmniejszaRoznica + paczki.najmniejszaRoznica;
                    }
                    cout << SumaOperacji;
                    return 0;
                }
                else
                {
                    SumaOperacji = SumaOperacji + drozdzowki.najmniejszaRoznica + paczki.najmniejszaRoznica;
                }
            }
        }
    if (!rogalik.czyWygral)
        if (drozdzowka.czyWygral && paczek.czyWygral)
            SumaOperacji = SumaOperacji + paczki.najmniejszaRoznica;
        else
        {
            if (!paczek.czyWygral)
            {
                if (paczki.pozycjaRoznicy == rogaliki.pozycjaRoznicy)
                {
                    if (paczki.najmniejszaRoznica + rogaliki.drugaNajmniejszaRoznica < paczki.drugaNajmniejszaRoznica + rogaliki.najmniejszaRoznica)
                    {
                        SumaOperacji = SumaOperacji + paczki.najmniejszaRoznica + rogaliki.drugaNajmniejszaRoznica;
                    }
                    else
                    {
                        SumaOperacji = SumaOperacji + paczki.drugaNajmniejszaRoznica + rogaliki.najmniejszaRoznica;
                    }
                    cout << SumaOperacji;
                    return 0;
                }
                else
                {
                    SumaOperacji = SumaOperacji + paczki.najmniejszaRoznica + rogaliki.najmniejszaRoznica;
                }
            }
            if (!drozdzowka.czyWygral)
            {
                if (drozdzowki.pozycjaRoznicy == rogaliki.pozycjaRoznicy)
                {
                    if (drozdzowki.najmniejszaRoznica + rogaliki.drugaNajmniejszaRoznica < drozdzowki.drugaNajmniejszaRoznica + rogaliki.najmniejszaRoznica)
                    {
                        SumaOperacji = SumaOperacji + drozdzowki.najmniejszaRoznica + rogaliki.drugaNajmniejszaRoznica;
                    }
                    else
                    {
                        SumaOperacji = SumaOperacji + drozdzowki.drugaNajmniejszaRoznica + rogaliki.najmniejszaRoznica;
                    }
                    cout << SumaOperacji;
                    return 0;
                }
                else
                {
                    SumaOperacji = SumaOperacji + drozdzowki.najmniejszaRoznica + rogaliki.najmniejszaRoznica;
                }
            }
        }
    cout << SumaOperacji;
    return 0;
}