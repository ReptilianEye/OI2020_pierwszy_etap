#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
//Caly kod jest napisany przeze mnie
//Piotr Rzadkowski

int n;

class Przedmiot
{
public:
    long long sumaWagi;
    int licznikK = 1;
    bool CzyWziety = false;
};

int main()
{

    cin >> n;
    vector<Przedmiot> ListaPrzedmiotow;

    // Tworzymy tablice dynamiczne
    //int *TablicaPrzedmiotow = new int[n];
    int min = 2147483647;
    for (int i = 0; i < n; i++)
    {
        Przedmiot nowy;
        cin >> nowy.sumaWagi;
        ListaPrzedmiotow.push_back(nowy);
        if (nowy.sumaWagi < min)
            min = nowy.sumaWagi;
    }
    int aktualnyBagaz = min - 1;
    for (int k = 1; k <= n; k++)
    {
        bool CzyZnalezlismy = false;

        while (!CzyZnalezlismy)
        {
            aktualnyBagaz++;
            int ilepotrzebujemy = k;
            int minimalnyBagaz = aktualnyBagaz;
            for (int i = 0; i < n; i++)
            {
                Przedmiot aktualnyPrzedmiot = ListaPrzedmiotow[i];
                if (aktualnyPrzedmiot.CzyWziety == false)
                {
                    if (aktualnyPrzedmiot.sumaWagi <= minimalnyBagaz)
                    {
                        minimalnyBagaz = minimalnyBagaz - aktualnyPrzedmiot.sumaWagi;

                        ilepotrzebujemy = ilepotrzebujemy - aktualnyPrzedmiot.licznikK;

                        if ( i > 0 && ListaPrzedmiotow[i - 1].CzyWziety)
                        {
                            ListaPrzedmiotow[i - 1].licznikK = ListaPrzedmiotow[i - 1].licznikK + aktualnyPrzedmiot.licznikK;
                            ListaPrzedmiotow[i - 1].sumaWagi = ListaPrzedmiotow[i - 1].sumaWagi + aktualnyPrzedmiot.sumaWagi;
                            ListaPrzedmiotow.erase(ListaPrzedmiotow.begin() + i);
                            if (ListaPrzedmiotow[i].CzyWziety)
                            {
                                ListaPrzedmiotow[i - 1].licznikK = ListaPrzedmiotow[i - 1].licznikK + ListaPrzedmiotow[i].licznikK;
                                ListaPrzedmiotow[i - 1].sumaWagi = ListaPrzedmiotow[i - 1].sumaWagi + ListaPrzedmiotow[i].sumaWagi;
                                ListaPrzedmiotow.erase(ListaPrzedmiotow.begin() + i);
                            }
                        }
                        if (i < n -1&& ListaPrzedmiotow[i + 1].CzyWziety)
                        {
                            ListaPrzedmiotow[i + 1].licznikK = ListaPrzedmiotow[i + 1].licznikK + ListaPrzedmiotow[i].licznikK;
                            ListaPrzedmiotow[i + 1].sumaWagi = ListaPrzedmiotow[i + 1].sumaWagi + ListaPrzedmiotow[i].sumaWagi;
                            ListaPrzedmiotow.erase(ListaPrzedmiotow.begin() + i);
                        }
                        ListaPrzedmiotow[i].CzyWziety = true;
                        if (minimalnyBagaz == 0 && ilepotrzebujemy == 0)
                        {
                            cout << aktualnyBagaz << " ";
                            CzyZnalezlismy = true;
                            break;
                        }
                        if (minimalnyBagaz == 0)
                            break;
                    }
                }
            }
        }
    }

    return 0;
}
