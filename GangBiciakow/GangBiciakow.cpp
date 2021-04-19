#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <bits/stdc++.h>
#include <set>

using namespace std;

class Droga
{
public:
    int numerDrogi = 0;
    int miastoDoKtoregoProwadzi = 0;
};

int main()
{
    //********** wczytywanie wejscia
    int iloscMiast;
    int iloscRodzajiBiciakow;
    int liczbaOperacji;
    cin >> iloscMiast >> iloscRodzajiBiciakow >> liczbaOperacji;

    vector<vector<Droga>> listaPuntowGdzieMozemyDojechac;
    int listaBiciakowNadrogach[iloscMiast - 1];

    for (int i = 0; i < iloscMiast - 1; i++)
    {
        int miastoA;
        int miastoB;
        int biciak;
        cin >> miastoA >> miastoB >> biciak;
        Droga droga;
        droga.numerDrogi = i;
        if (miastoA < miastoB)
        {
            droga.miastoDoKtoregoProwadzi = miastoB;
            listaPuntowGdzieMozemyDojechac[miastoA].push_back(droga);
        }
        else
        {
            droga.miastoDoKtoregoProwadzi = miastoA;
            listaPuntowGdzieMozemyDojechac[miastoB].push_back(droga);
        }
        listaBiciakowNadrogach[i] = biciak;
    }

//chodznie po grafie - znjadywanie drogi miedzy punktami







    Droga tablicaDrog[iloscMiast];

    string operacja = "";
    for (int i = 0; i < liczbaOperacji; i++)
    {
        cin >> operacja;
        if (operacja == "Z")
        {
            int doKtoregoMiasta;
            cin >> doKtoregoMiasta;
            doKtoregoMiasta--;
            int i = doKtoregoMiasta;
            set<int> zebraneBiciaki;
            while (i != 0)
            {
                int numerDrogi = tablicaDrog[i].numerDrogi;
                int zbieranyBiciak = listaBiciakowNadrogach[numerDrogi];
                zebraneBiciaki.insert(zbieranyBiciak);
                i = tablicaDrog[i].miastoDoKtoregoProwadzi;
            }
            cout << zebraneBiciaki.size();
        }
        if (operacja == "B")
        {
            int numerDrogi;
            int nowyBiciak;
            cin >> numerDrogi >> nowyBiciak;
            numerDrogi--;
            listaBiciakowNadrogach[numerDrogi] = nowyBiciak;
        }
    }
    return 0;
}