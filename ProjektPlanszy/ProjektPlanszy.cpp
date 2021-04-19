#include <iostream>
#include <string>

using namespace std;
//Caly kod jest napisany przeze mnie
//funkcja drukuje tablice byla mi kiedys potrzebna do I etapu OI tego roku
//Piotr Rzadkowski
int wymiaryTablicy;
void drukujeTablice(char **Tablica)
{
    for (int wiersz = 0; wiersz < wymiaryTablicy; wiersz++)
    {
        for (int kolumna = 0; kolumna < wymiaryTablicy; kolumna++)
        {
            cout << Tablica[wiersz][kolumna];
        }
        cout << endl;
    }
}
void TworzyTrase(char **Tablica)
{
    for (int i = 0; i < wymiaryTablicy; i++)
        Tablica[i][0] = '.';
    for (int i = 0; i < wymiaryTablicy; i++)
        Tablica[wymiaryTablicy - 1][i] = '.';
}

void DodajeGalezie(char **Tablica, long long k)
{
    k--;
    int wzkaznik = wymiaryTablicy - 2;
    while (k > 0)
    {
        Tablica[wzkaznik][1] = '.';
        wzkaznik--;
        k--;

    }
}
int main()
{

    long long K;
    wymiaryTablicy = 100;
    cin >> K;

    char **Tablica = new char *[wymiaryTablicy];

    for (int i = 0; i < wymiaryTablicy; i++)
        Tablica[i] = new char[wymiaryTablicy];

    for (int i = 0; i < wymiaryTablicy; i++)
    {
        for (int j = 0; j < wymiaryTablicy; j++)
            Tablica[i][j] = '#';
    };

    TworzyTrase(Tablica);
    DodajeGalezie(Tablica, K);

    cout << 100 << endl;
    drukujeTablice(Tablica);

    return 0;
}