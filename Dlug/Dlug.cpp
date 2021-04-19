#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    //********** wczytywanie wejscia
    int dlugoscWyswietlacza;
    int liczbaOperacji;
    cin >> dlugoscWyswietlacza >> liczbaOperacji;

    //int *DlugWewnetrzny = new int[dlugoscWyswietlacza - 1];
    //int *DlugZewnetrzny = new int[dlugoscWyswietlacza - 1];
    //int *DlugCalkowity = new int[dlugoscWyswietlacza];

    int DlugWewnetrzny[dlugoscWyswietlacza - 1];
    int DlugZewnetrzny[dlugoscWyswietlacza - 1];
    int DlugCalkowity[dlugoscWyswietlacza];

    string tymczasowyDW;
    string tymczasowyDZ;
    cin >> tymczasowyDW >> tymczasowyDZ;
    int j = 0;
    for (int i = dlugoscWyswietlacza - 2; i >= 0; i--)
    {
        DlugWewnetrzny[j] = tymczasowyDW[i] - '0';
        DlugZewnetrzny[j] = tymczasowyDZ[i] - '0';
        j++;
    }
    for (int i = 0; i < dlugoscWyswietlacza; i++)
        DlugCalkowity[i] = 0;
    // przeliczenie dlugu calkowitego na poczatku
    int reszta = 0;
    for (int i = 0; i < dlugoscWyswietlacza - 1; i++)
    {
        if (DlugWewnetrzny[i] + DlugZewnetrzny[i] + reszta > 9)
        {
            DlugCalkowity[i] = (DlugWewnetrzny[i] + DlugZewnetrzny[i] + reszta) % 10;
            reszta = 1;
        }
        else
        {
            DlugCalkowity[i] = DlugWewnetrzny[i] + DlugZewnetrzny[i] + reszta;
            reszta = 0;
        }
    }
    string operacja = "";
    int naKtorymMiejscu;
    int naJakaCyfre;
    for (int i = 0; i < liczbaOperacji; i++)
    {
        cin >> operacja;
        cin >> naKtorymMiejscu;
        naKtorymMiejscu--;
        if (operacja == "S")
        {
            cout << DlugCalkowity[naKtorymMiejscu] << endl;
            continue;
        }
        cin >> naJakaCyfre;
        if (operacja == "W") //zmiana wewnetrznego
        {
            DlugWewnetrzny[naKtorymMiejscu] = naJakaCyfre;
        }
        if (operacja == "Z") //zmiana zewnetrznego
        {
            DlugZewnetrzny[naKtorymMiejscu] = naJakaCyfre;
        }
        reszta = 0;
        bool czyZmieniaWartosci = true;
        int tymczasowa;
        for (int i = 0; i < dlugoscWyswietlacza - 1; i++)
        {
            if (DlugWewnetrzny[i] + DlugZewnetrzny[i] + reszta > 9)
            {
                DlugCalkowity[i] = (DlugWewnetrzny[i] + DlugZewnetrzny[i] + reszta) % 10;
                reszta = 1;
            }
            else
            {
                tymczasowa = DlugCalkowity[i];
                DlugCalkowity[i] = DlugWewnetrzny[i] + DlugZewnetrzny[i] + reszta;
                reszta = 0;
                if (tymczasowa == DlugCalkowity[i])
                    czyZmieniaWartosci = false;
            }
            if (!czyZmieniaWartosci)
                break;
        }
    }
    return 0;
}