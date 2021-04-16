#include <bits/stdc++.h>  // Para importar todas librerias
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
int visitados[100000];
vector<int> grafo[100000];

void dfs(int inicio) {
    visitados[inicio] = 1;
    for( int i = 0; i < grafo[inicio].size(); i++) {
        if(!visitados[grafo[inicio][i]]) {              // grafo.get(inicio).get(i)
            dfs(grafo[inicio][i]);
        }   
    }
}

int main(){ 
    input;
    output;
    int vertices, aristas; 
    cin>>vertices>>aristas;               // scanf("%d %d", &vertices, &aristas)

    // lectura del Grafo
    for(int i = 0; i < aristas; i++) {
        int inicio, fin; 
        cin>> inicio >> fin;
        grafo[inicio].push_back(fin);
        grafo[fin].push_back(inicio);
    }
    int contadorGrupos = 0;
    for(int i = 0; i < vertices ; i++) {
        if(!visitados[i]) {
            dfs(i);
            contadorGrupos++;
            for(int j = 0; j < vertices ; j++) {
                cout<<"["<< visitados[j]<<"]";
            }
            cout<<endl;
        }
    }
    cout<<"En total hay "<< contadorGrupos<< " grupos"<<endl;
}