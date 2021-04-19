#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const int iloscRodzajowWypiekow = 3;

class Roznica
{
public:
    int roznica = INT32_MAX;
    int pozycjaRoznicy = -1;
};
int ZwracaLidera(int TablicaIlosci[iloscRodzajowWypiekow])
{
    int lider = -1;
    for (int i = 0; i < iloscRodzajowWypiekow; i++)
    {
        if (TablicaIlosci[i] > lider)
            lider = TablicaIlosci[i];
    }
    return lider;
}

int main()
{
    //********** wczytywanie wejscia
    int liczbaGablot;
    cin >> liczbaGablot;

    int SumaOperacji = 0;

    Roznica TabelaDanych[iloscRodzajowWypiekow][iloscRodzajowWypiekow];
    bool CzyWystapily[iloscRodzajowWypiekow] = {false};

    for (int i = 0; i < liczbaGablot; i++)
    {
        int IloscWGablocie[iloscRodzajowWypiekow];
        cin >> IloscWGablocie[0] >> IloscWGablocie[1] >> IloscWGablocie[2];
        int lider = ZwracaLidera(IloscWGablocie);
        Roznica RozniceWTejGablocie[iloscRodzajowWypiekow];
        for (int j = 0; j < iloscRodzajowWypiekow; j++)
        {
            RozniceWTejGablocie[j].roznica = lider - IloscWGablocie[j];
            RozniceWTejGablocie[j].pozycjaRoznicy = i;
            SumaOperacji = SumaOperacji + IloscWGablocie[j];
        }
        SumaOperacji = SumaOperacji - lider;
        for (int j = 0; j < iloscRodzajowWypiekow; j++)
        {
            if (IloscWGablocie[j] > 0)
                CzyWystapily[j] = true;
            for (int k = 0; k < iloscRodzajowWypiekow; k++)
            {
                if (RozniceWTejGablocie[j].roznica < TabelaDanych[j][k].roznica)
                {
                    Roznica wyciagnieta = TabelaDanych[j][k];
                    TabelaDanych[j][k] = RozniceWTejGablocie[j];
                    RozniceWTejGablocie[j] = wyciagnieta;
                }
            }
        }
    }
    for(int i = 0; i < iloscRodzajowWypiekow;i++)       //Ubsluga przypadku w ktorym wypiek nie wystapil => jego roznica nie ma znaczenia
    {
        if(!CzyWystapily[i])
        {
            for(int j = 0; j < iloscRodzajowWypiekow; j++)
            TabelaDanych[i][j].roznica = 0; 
        }
    }
    int najmniejszaSumaRoznic = INT32_MAX;
    
    for (int i = 0; i < iloscRodzajowWypiekow; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (TabelaDanych[0][i].pozycjaRoznicy != TabelaDanych[1][j].pozycjaRoznicy
                 && TabelaDanych[1][j].pozycjaRoznicy != TabelaDanych[2][k].pozycjaRoznicy
                 && TabelaDanych[2][k].pozycjaRoznicy != TabelaDanych[0][i].pozycjaRoznicy)
                {
                    int sumaRoznic = TabelaDanych[0][i].roznica + TabelaDanych[1][j].roznica + TabelaDanych[2][k].roznica;
                    if (sumaRoznic < najmniejszaSumaRoznic)
                        najmniejszaSumaRoznic = sumaRoznic;
                }
            }
        }
    }
    SumaOperacji = SumaOperacji + najmniejszaSumaRoznic;
    cout << SumaOperacji << '\n';
    return 0;
}