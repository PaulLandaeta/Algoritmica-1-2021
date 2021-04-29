#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define INF 100000010
using namespace std;
vector < pair < int, int > > grafo[20010];
int distancia[100010];
int visitados[100010];
int cases;
int vertices, aristas, S, T;
int cont = 1;

void dijkstra(int verticeInicial){
    for (int i = 0; i < 100010; i++){
        distancia[i] = INF;
    }
    memset(visitados, 0, sizeof(visitados));
    multiset < pair < int, int > > colaPrioridad;
    distancia[verticeInicial] = 0;
    colaPrioridad.insert(make_pair(0, verticeInicial));
    while (!colaPrioridad.empty()){
        pair < int, int > verticeActual = *colaPrioridad.begin();
        colaPrioridad.erase(colaPrioridad.begin());
        int vertice = verticeActual.second;
        int peso = verticeActual.first;
        if(visitados[vertice]){
            continue;
        }
        visitados[vertice] = true;
        for (int i = 0; i < grafo[vertice].size(); i++){
            int verticeVecino = grafo[vertice][i].second;
            int pesoVecino = grafo[vertice][i].first;
            if(distancia[vertice] + pesoVecino < distancia[verticeVecino]){
                distancia[verticeVecino] = distancia[vertice] + pesoVecino;
                colaPrioridad.insert(make_pair(distancia[verticeVecino], verticeVecino));
            }
        } 
    }
}

int main(){ 
    input;
    output;
    cin >> cases;
    while (cases--) {
        cin >> vertices >> aristas >> S >> T;
        for (int i = 0; i < aristas; i++){
            int inicio, fin, peso;
            cin >> inicio >> fin >> peso;
            grafo[inicio].push_back(make_pair(peso, fin));
            grafo[fin].push_back(make_pair(peso, inicio));
        }
        dijkstra(S);
        
        printf("Case #%d: ", cont++);
        if(distancia[T] != INF){
            printf("%d\n", distancia[T]);
        } else {
            printf("unreachable\n");
        }
        for (int i = 0; i < 20010; i++){
            grafo[i].clear();
        }
    }
}