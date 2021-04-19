#include <iostream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

class Droga
{
public:
    int numerDrogi = -1;
    int miastoWKierunkuStolicy = -1;
};
// An Iterative C++ program to do DFS traversal from
// a given source vertex. DFS(int s) traverses vertices
// reachable from s.

// This class represents a directed graph using adjacency
// list representation
class Graph
{
    int V;          // No. of vertices
    list<int> *adj; // adjacency lists
public:
    Graph(int V);                                               // Constructor
    void addEdge(int v, int w);                                 // to add an edge to graph
    void DFS(int s, Droga TablicaPunktowGdzieMozemyDojechac[]); // prints all vertices in DFS manner
    // from a given source.
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

// prints all not yet visited vertices reachable from s
void Graph::DFS(int s, Droga TablicaPunktowGdzieMozemyDojechac[])
{
    // Initially mark all verices as not visited
    vector<bool> visited(V, false);

    // Create a stack for DFS
    stack<int> stack;

    // Push the current source node.
    stack.push(s);

    while (!stack.empty())
    {
        // Pop a vertex from stack and print it
        s = stack.top();
        stack.pop();

        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited.
        if (!visited[s])
        {
            visited[s] = true;
        }

        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then push it
        // to the stack.
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            if (!visited[*i])
            {
                stack.push(*i);
                TablicaPunktowGdzieMozemyDojechac[*i].miastoWKierunkuStolicy = s;
            }
    }
}

int main()
{
    //********** wczytywanie wejscia
    int iloscMiast;
    int iloscRodzajowBiciakow;
    int liczbaOperacji;
    cin >> iloscMiast >> iloscRodzajowBiciakow >> liczbaOperacji;

    int tablicaDrogLaczacychMiasta[iloscMiast - 1][2];
    int TablicaBiciakowNadrogach[iloscMiast - 1];

    Graph grafMiasta(iloscMiast);
    for (int i = 0; i < iloscMiast - 1; i++)
    {
        int miastoA;
        int miastoB;
        int biciak;
        cin >> miastoA >> miastoB >> biciak;
        miastoA--;
        miastoB--;
        grafMiasta.addEdge(miastoA, miastoB);
        grafMiasta.addEdge(miastoB, miastoA);
        tablicaDrogLaczacychMiasta[i][0] = miastoA;
        tablicaDrogLaczacychMiasta[i][1] = miastoB;
        Droga droga;
        droga.numerDrogi = i;
        TablicaBiciakowNadrogach[i] = biciak;
    }

    Droga TablicaPunktowGdzieMozemyDojechac[iloscMiast];
    grafMiasta.DFS(0, TablicaPunktowGdzieMozemyDojechac);

    for (int i = 0; i < iloscMiast - 1; i++)
    {
        int MiastoA = tablicaDrogLaczacychMiasta[i][0];
        int MiastoB = tablicaDrogLaczacychMiasta[i][1];
        if (TablicaPunktowGdzieMozemyDojechac[MiastoA].miastoWKierunkuStolicy == MiastoB)
            TablicaPunktowGdzieMozemyDojechac[MiastoA].numerDrogi = i;
        else if (TablicaPunktowGdzieMozemyDojechac[MiastoB].miastoWKierunkuStolicy == MiastoA)
            TablicaPunktowGdzieMozemyDojechac[MiastoB].numerDrogi = i;
    }
    
    int *TablicaRodzajiBiciakow = new int[iloscRodzajowBiciakow];
   // int TablicaRodzajiBiciakow[iloscRodzajowBiciakow];

    int zbieranyBiciak;
    for (int i = 0; i < iloscRodzajowBiciakow; i++)
    {
        TablicaRodzajiBiciakow[i] = 0;
    }
    string operacja = "";
    for (int i = 1; i <= liczbaOperacji; i++)
    {
        cin >> operacja;
        if (operacja == "Z")
        {
            int doKtoregoMiasta;
            cin >> doKtoregoMiasta;
            doKtoregoMiasta--;
            int j = doKtoregoMiasta;
            int licznikRodzajowBiciakow = 0;
            while (j != 0)
            {
                int numerDrogi = TablicaPunktowGdzieMozemyDojechac[j].numerDrogi;
                zbieranyBiciak = TablicaBiciakowNadrogach[numerDrogi];
                int akualnaWartosc = TablicaRodzajiBiciakow[zbieranyBiciak];
                if (akualnaWartosc != i)
                {
                    TablicaRodzajiBiciakow[zbieranyBiciak] = i; //dlaczego to tak wolno dziala?
                    licznikRodzajowBiciakow++;
                } 
                j = TablicaPunktowGdzieMozemyDojechac[j].miastoWKierunkuStolicy;
            }
            cout << licznikRodzajowBiciakow << endl;
            continue;
        }
        if (operacja == "B")
        {
            int numerDrogi;
            int nowyBiciak;
            cin >> numerDrogi >> nowyBiciak;
            numerDrogi--;
            TablicaBiciakowNadrogach[numerDrogi] = nowyBiciak;
        }
    }
    return 0;
}