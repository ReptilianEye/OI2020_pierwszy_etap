#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
//Caly kod jest napisany przeze mnie
//funkcja drukuje tablice byla mi kiedys potrzebna do I etapu OI tego roku
//Piotr Rzadkowski

int n, m;
int *TablicaWagKrasnali;
int *Permutacje;
vector<vector<int>> listaSasiedztwa; // Tablica list sąsiedztwa
bool CzyZnalezlismyRozwiazanie = false;

//algorytm permutacyjny ze strony https://www.sanfoundry.com/cpp-program-implement-heap-algorithm-permute-n-numbers/
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// A function to implement Heap’s Algorithm for the permutation of N numbers.
void print(const int *v)
{
    int i;
    int size = n+1;

    // Loop to print the sequence.
    cout << "\t";
    for (i = 1; i < size; i++)
        cout << setw(4) << v[i];
    cout << "\n";
}

void PrzydzielaWartosci()
{
    int wskaznikKrasnala = 1;
    for (int i = 0; i < n; i++)
    {
        TablicaWagKrasnali[wskaznikKrasnala] = Permutacje[i];
        wskaznikKrasnala++;
    }
}
bool SprawdzaSasiadow()
{
    for (int i = 3; i <= n; i++)
    {
        int liczbaSasiadow = listaSasiedztwa[i].size() / 2;
        int *TablicaPotrzebychWag = new int[2];
        for (int i = 0; i < 2; i++)
            TablicaPotrzebychWag[i] = liczbaSasiadow;
        int wagaPrzegladanego = TablicaWagKrasnali[i];
        for (int j = 0; j < listaSasiedztwa[i].size(); j++)
        {

            int wagaSasiada = TablicaWagKrasnali[listaSasiedztwa[i][j]];
            if (wagaSasiada < wagaPrzegladanego)
            {
                TablicaPotrzebychWag[0]--;
                if (TablicaPotrzebychWag[0] < 0)
                    return false;
            }
            else
            {
                TablicaPotrzebychWag[1]--;
                if (TablicaPotrzebychWag[1] < 0)
                    return false;
            }
        }
    }
    return true;
}
void WykonujeZadanie()
{
    PrzydzielaWartosci();
    if (SprawdzaSasiadow())
    {
        cout << "TAK" << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << TablicaWagKrasnali[i] << " ";
        }
        cout << endl;
        CzyZnalezlismyRozwiazanie = true;
    }
}
void HeapPermute(int *v, int n)
{
    int i;
    if (CzyZnalezlismyRozwiazanie)
        return;
    // Print the sequence if the heap top reaches to the 1.
    if (n == 1)
        WykonujeZadanie();
    else
    {
        // Fix a number at the heap top until only two one element remaining and permute remaining.
        for (i = 0; i < n; i++)
        {
            HeapPermute(v, n - 1);
            // If odd then swap the value at the start index with the n-1.
            if (n % 2 == 1)
                swap(&v[0], &v[n - 1]);
            // If even then swap the value at the 'i' index with the n-1.
            else
                swap(&v[i], &v[n - 1]);
        }
    }
}
int main()
{

    int x, y, w;
    int i, j, u;

    cin >> n >> m; //wczytanie wierzcholka startowego, liczby wierzcholkow i krawedzi

    // Tworzymy tablice dynamiczne
    TablicaWagKrasnali = new int[n + 1]{0};
    Permutacje = new int[n]{0};

    int licznikWag = 1;
    for (int i = 0; i < n; i++)
    {
        Permutacje[i] = licznikWag;
        licznikWag++;
    }

    // Odczytujemy dane wejściowe
    for (i = 0; i <= n; i++)
    {
        vector<int> a;
        listaSasiedztwa.push_back(a);
    }
    for (i = 0; i < m; i++)
    {
        cin >> x >> y; // Odczytujemy krawędź z wagą

        listaSasiedztwa[x].push_back(y); // Element dołączamy do listy
        listaSasiedztwa[y].push_back(x); // Element dołączamy do listy
    }
    HeapPermute(Permutacje, n);
    if (!CzyZnalezlismyRozwiazanie)
        cout << "NIE" << endl;
    return 0;
}