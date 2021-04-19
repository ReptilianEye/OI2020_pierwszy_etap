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

    int *DlugWewnetrzny = new int[dlugoscWyswietlacza - 1];
    int *DlugZewnetrzny = new int[dlugoscWyswietlacza - 1];
    int *DlugCalkowity = new int[dlugoscWyswietlacza];

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
    DlugCalkowity[dlugoscWyswietlacza-1] = reszta;
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
        int oIleZmieniamy;
        if (operacja == "W") //zmiana wewnetrznego
        {
            oIleZmieniamy = naJakaCyfre - DlugWewnetrzny[naKtorymMiejscu];
            DlugWewnetrzny[naKtorymMiejscu] = naJakaCyfre;
        }
        if (operacja == "Z") //zmiana zewnetrznego
        {
            oIleZmieniamy = naJakaCyfre - DlugZewnetrzny[naKtorymMiejscu];
            DlugZewnetrzny[naKtorymMiejscu] = naJakaCyfre;
        }
        if (DlugCalkowity[naKtorymMiejscu] + oIleZmieniamy > 9)
        {
            DlugCalkowity[naKtorymMiejscu] = (DlugCalkowity[naKtorymMiejscu] + oIleZmieniamy) % 10;
            int i = naKtorymMiejscu + 1;
            while (DlugCalkowity[i] + 1 > 9)
            {
                DlugCalkowity[i] = (DlugCalkowity[i] + 1) % 10;
                i++;
            }
            DlugCalkowity[i]++;
        }
        else if (DlugCalkowity[naKtorymMiejscu] + oIleZmieniamy < 0)
        {
            DlugCalkowity[naKtorymMiejscu] = DlugCalkowity[naKtorymMiejscu] + 10 + oIleZmieniamy;
            int i = naKtorymMiejscu + 1;
            while (DlugCalkowity[i] == 0)
            {
                DlugCalkowity[i] = 9;
                i++;
            }
            DlugCalkowity[i]--;
        }
        else
            DlugCalkowity[naKtorymMiejscu] = DlugCalkowity[naKtorymMiejscu] + oIleZmieniamy;
    }
    return 0;
}