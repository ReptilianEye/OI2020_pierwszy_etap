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
    int numerDrogi = -1;
    int miastoWKierunkuStolicy = -1;
};

// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
    int V; // No. of vertices

    // Pointer to an array containing
    // adjacency lists
    list<int> *adj;

    // A recursive function used by DFS
    void DFSUtil(int v, bool visited[], Droga TablicaPunktowGdzieMozemyDojechac[]);

public:
    Graph(int V); // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v, Droga TablicaPunktowGdzieMozemyDojechac[]);
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

void Graph::DFSUtil(int v, bool visited[], Droga TablicaPunktowGdzieMozemyDojechac[])
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
        {
            TablicaPunktowGdzieMozemyDojechac[*i].miastoWKierunkuStolicy = v;
            DFSUtil(*i, visited, TablicaPunktowGdzieMozemyDojechac);
        }
    }
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(int v, Droga TablicaPunktowGdzieMozemyDojechac[])
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function
    // to print DFS traversal
    DFSUtil(v, visited, TablicaPunktowGdzieMozemyDojechac);
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
        tablicaDrogLaczacychMiasta[i][0]= miastoA;
        tablicaDrogLaczacychMiasta[i][1]= miastoB;
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
            set<int> zebraneTypyBiciakow;
            while (i != 0)
            {
                int numerDrogi = TablicaPunktowGdzieMozemyDojechac[i].numerDrogi;
                int zbieranyBiciak = TablicaBiciakowNadrogach[numerDrogi];
                zebraneTypyBiciakow.insert(zbieranyBiciak);
                i = TablicaPunktowGdzieMozemyDojechac[i].miastoWKierunkuStolicy;
            }
            cout << zebraneTypyBiciakow.size() << endl;
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