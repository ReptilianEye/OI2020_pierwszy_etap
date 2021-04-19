#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <math.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <list>

using namespace std;
//Caly kod jest napisany przeze mnie
//Piotr Rzadkowski
int n;
int dlugoscPlazy;
int liczbaZapytan;
int maksymalnaIloscTurystow;

class Przedzial
{
public:
    long double dlugoscPrzedzialu;
    int ilosc;
    int numerDrzewa;
    int poczatek;
    int poziom = 0;
    long long sumaKroczaca = 0;
};
vector<Przedzial> listaPrzedzialow;

class Drzewo
{
public:
    long long start;
    long long koniec;
    //zwraca ulamek pokazujacy miejsce dla turysty
    //funkcja posluguje sie drzewem binarnym
    void ZwracaMiejsceWDrzewie(long long poziom, long long pozycja)
    {

        long long miejsceMianownik = pow(2, poziom + 1);
        long long miejsceLicznik = start * miejsceMianownik + (2 * pozycja + 1) * (koniec - start);

        int podzielnik = __gcd(miejsceLicznik, miejsceMianownik);       //znajduje najwiekszy dzielnik, aby skrocic ulamek
        miejsceLicznik /= podzielnik;
        miejsceMianownik /= podzielnik;
        cout << miejsceLicznik << "/" << miejsceMianownik << endl;      //zwraca wynik
    }
};
//funkcja porownujaca - potrzeba do porownywania obiektow
bool PorownujePrzedzialy(const Przedzial &l, const Przedzial &r)
{
    if (l.dlugoscPrzedzialu > r.dlugoscPrzedzialu)
        return true;
    else if (l.dlugoscPrzedzialu == r.dlugoscPrzedzialu)
        if (l.poczatek < r.poczatek)
            return true;
    return false;
}
//funkcja wypisujaca przedzialy
void WypisujePrzedzialy(vector<Przedzial> listaPrzedzialow)
{
    for (int i = 0; i < listaPrzedzialow.size(); i++)
        cout << i << " " << listaPrzedzialow[i].dlugoscPrzedzialu << " " << listaPrzedzialow[i].poczatek << " " << listaPrzedzialow[i].sumaKroczaca << endl;
}
//Rozbija na przedzialy, dzielac je dzielac na pol, az do momentu kiedy ilosc turytow ktorzy sie tam zmieszcza bedzie wieksza od maksymalnej liczby turystow
void RozbijaNaPrzedzialy(vector<Przedzial> &listaPrzedzialow)
{
    int sumaPrzedzialow = 0;
    list<Przedzial> Przedzialy;
    for (int i = 0; i < listaPrzedzialow.size(); i++)
    {
        Przedzialy.push_back(listaPrzedzialow[i]); //kopujemy przedzialy z vectora do listy, poniewaz ona bedzie dzialala szybciej
    }                                              //wstawianie do list ma zlozonosc (1) kiedy do vectora zlozonosc (n)

    auto i = Przedzialy.begin();                          //deklarujemy dwa wskazniki - 'i' ktory bedzie chodzil po przedzialach
    auto j = i;                                           //'j' po miejscach gdzie podzielone przedzialy bedziemy wstawiac
    while (sumaPrzedzialow < maksymalnaIloscTurystow + 3) //TODO
    {
        Przedzial aktualnyPrzedzial;
        aktualnyPrzedzial = *i;
        Przedzial PodzielonyPrzedzial; //tworzymy nowy przedzial
        PodzielonyPrzedzial = aktualnyPrzedzial;
        PodzielonyPrzedzial.dlugoscPrzedzialu = (long double)aktualnyPrzedzial.dlugoscPrzedzialu / 2; //dlugosc bedzie podzielona na pol
        PodzielonyPrzedzial.ilosc = aktualnyPrzedzial.ilosc * 2;                                      //ilosc przedzialow sie dwuktotnie zwiekszy
        PodzielonyPrzedzial.poziom++;                                                                 //zmienna wskazujaca na poziom naszego drzewa zwieksza sie o 1
        bool czyDodalismy = false;                                                                    //jestesmy o poziom glebiej
        while (j != Przedzialy.end())
        {
            if (PorownujePrzedzialy(PodzielonyPrzedzial, *j)) //znajdujemy miejsce dla nowego przedzialu porownujac dlugosc
            {                                                 //jesli dlugosc jest ta sama porownujemy poczatek przedzialu
                break;
            }
            sumaPrzedzialow += (*j).ilosc;
            ++j;
        }
        Przedzialy.insert(j, PodzielonyPrzedzial);    //wstawiamy posortowany przedzial
        sumaPrzedzialow += PodzielonyPrzedzial.ilosc; //zwiekszamy licznik wskazujacy na ilosc turystow ktorzy juz sie zmieszcza
        i++;
    }
    int wielkosci = Przedzialy.size();
    listaPrzedzialow.clear();                           
    long long SumaKroczacaDotychczasowa = 0;
    for (auto i = Przedzialy.begin(); i != Przedzialy.end(); ++i)
    {
        SumaKroczacaDotychczasowa += (*i).ilosc;
        (*i).sumaKroczaca = SumaKroczacaDotychczasowa;              //sumujemy rosnaca sume turystow ktorzy sie zmiesza
        listaPrzedzialow.push_back(*i);
    }
}
//wyszukiwanie binarne znajdujace najwieksza liczbe mniejsza od szukanej
int greatestlesser(int low, int high, int key)
{
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low + 1) / 2;
        int midVal = listaPrzedzialow[mid].sumaKroczaca;

        if (midVal < key)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (midVal > key)
        {

            high = mid - 1;
        }
        else if (midVal == key)
        {

            high = mid - 1;
        }
    }

    return ans;
}

int main()
{

    cin >> n >> dlugoscPlazy >> liczbaZapytan;

    vector<Drzewo> ListaDrzew;
    int startPrzedzialu; //wczytujemy dane
    cin >> startPrzedzialu;
    for (int i = 0; i < n - 1; i++)
    {
        int koniecPrzedzialu;
        cin >> koniecPrzedzialu;
        Przedzial NowyPrzedzial;
        NowyPrzedzial.poczatek = startPrzedzialu;
        NowyPrzedzial.dlugoscPrzedzialu = koniecPrzedzialu - startPrzedzialu;
        NowyPrzedzial.ilosc = 1;
        NowyPrzedzial.numerDrzewa = i;
        listaPrzedzialow.push_back(NowyPrzedzial);
        Drzewo NoweDrzewo;
        NoweDrzewo.start = startPrzedzialu;
        NoweDrzewo.koniec = koniecPrzedzialu;
        ListaDrzew.push_back(NoweDrzewo);
        startPrzedzialu = koniecPrzedzialu;
    }
    sort(listaPrzedzialow.begin(), listaPrzedzialow.end(), PorownujePrzedzialy); //sortujemy przedzialy od najwiekszego do najmniejszego
    vector<int> ListaZapytan;
    for (int i = 0; i < liczbaZapytan; i++)
    {
        int zapytanie;
        cin >> zapytanie;
        if (maksymalnaIloscTurystow < zapytanie) //wczytujemy zapytania
            maksymalnaIloscTurystow = zapytanie; //i znajdujemy maksymalna liczbe turystow ktorych bedziemy musieli zmiescic na plazy
        ListaZapytan.push_back(zapytanie);       //ta informacja powie nam jak duzo przedzialow bedziemy musieli stworzyc
    }
    RozbijaNaPrzedzialy(listaPrzedzialow);
    int size = listaPrzedzialow.size();
    //WypisujePrzedzialy(listaPrzedzialow);
    for (int i = 0; i < ListaZapytan.size(); i++)
    {
        int wartoscZapytania = ListaZapytan[i];

        int j = greatestlesser(0, listaPrzedzialow.size() - 1, wartoscZapytania);
        if (j > -1)
            wartoscZapytania -= listaPrzedzialow[j].sumaKroczaca;
        j++;
        //cout << wartoscZapytania << " " << listaPrzedzialow[j].poziom << " " << listaPrzedzialow[j].numerDrzewa << endl;
        ListaDrzew[listaPrzedzialow[j].numerDrzewa].ZwracaMiejsceWDrzewie(listaPrzedzialow[j].poziom, wartoscZapytania - 1);
        //cout << endl;
    }
    return 0;
}