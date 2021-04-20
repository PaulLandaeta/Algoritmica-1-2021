#include <bits/stdc++.h> // Para importar todas librerias
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define INF 100000010
using namespace std;

vector<pair<int, int> > grafo[100000];
int visitados[100000]; 
int distancia[100000];

void dijkstra(int verticeInicial)
{
    // memset(distancia, INF, sizeof(distancia)); // -1 0 1
    for(int i = 0; i < 100000; i++)
        distancia[i] = INF;


    memset(visitados, 0, sizeof(visitados));

    multiset<pair<int, int> > colaPrioridad;
    distancia[verticeInicial] = 0;
    colaPrioridad.insert(make_pair(0, verticeInicial));
    while (!colaPrioridad.empty())
    {
        pair<int, int> verticeActual = *colaPrioridad.begin();
        colaPrioridad.erase(colaPrioridad.begin());
        int vertice = verticeActual.second;
        int peso = verticeActual.first;

        if (visitados[vertice])
        {
            continue;
        }
        visitados[vertice] = true;

        for (int i = 0; i < grafo[vertice].size(); i++)
        {
            int verticeVecino = grafo[vertice][i].second;
            int pesoVecino = grafo[vertice][i].first;
            if (distancia[vertice] + pesoVecino < distancia[verticeVecino])
            {
                distancia[verticeVecino] = distancia[vertice] + pesoVecino;
                colaPrioridad.insert(make_pair(distancia[verticeVecino], verticeVecino));
            }
        }
    }
}

int main()
{
    input;
    output;
    int vertices, aristas;
    cin >> vertices >> aristas;
    for (int i = 0; i < aristas; i++)
    {
        int ini,fin,peso; 
        cin>>ini>>fin>>peso;
        grafo[ini].push_back(make_pair(peso,fin));
        grafo[fin].push_back(make_pair(peso,ini));
    }
    dijkstra(0);
    for(int i = 0;i<4;i++) {
        cout<<distancia[i]<<endl;
    }
}