#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
//Caly kod jest napisany przeze mnie
//Piotr Rzadkowski

int n;

int main()
{

    cin >> n;

    // Tworzymy tablice dynamiczne
    int *TablicaPrzedmiotow = new int[n];
    int min = 2147483647;
    for (int i = 0; i < n; i++)
    {
        cin >> TablicaPrzedmiotow[i];
        if (TablicaPrzedmiotow[i] < min)
            min = TablicaPrzedmiotow[i];
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
                if (TablicaPrzedmiotow[i] <= minimalnyBagaz)
                {
                    minimalnyBagaz = minimalnyBagaz - TablicaPrzedmiotow[i];
                    ilepotrzebujemy--;
                    if (minimalnyBagaz == 0 && ilepotrzebujemy == 0)
                    {
                        cout << aktualnyBagaz << " ";
                        CzyZnalezlismy = true;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
