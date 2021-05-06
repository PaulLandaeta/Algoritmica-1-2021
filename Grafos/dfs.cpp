#include <bits/stdc++.h>  // Para importar todas librerias
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
int visitados[100000];
vector<int> grafo[100000];
int cont;
void dfs(int inicio) {
    visitados[inicio] = 1;
    for( int i = 0; i < grafo[inicio].size(); i++) {
        if(!visitados[grafo[inicio][i]]) {       
            cont++;
            dfs(grafo[inicio][i]);
        }   
    }
}


int main(){ 
    input;
    output;
    int vertices, aristas; 
    cin>>vertices>>aristas;               // scanf("%d %d", &vertices, &aristas)
    cont = 0;
    // lectura del Grafo
    dfs(0);
    cout<<cont+1<<endl;
}