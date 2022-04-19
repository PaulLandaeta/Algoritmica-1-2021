#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

vector<int> grafo[100];
vector<bool> visitados(100);
vector<int> nivel(100);

void bfs(int nodoInicial) {
    queue<int> colaNodos;
    colaNodos.push(nodoInicial);
    visitados[nodoInicial] = true;
    nivel[nodoInicial] = 0;
    while(!colaNodos.empty()) { // Java isEmpty
        int nodoActual = colaNodos.front(); 
        colaNodos.pop();
        for(int i = 0; i < grafo[nodoActual].size(); i++) {
            int vecino = grafo[nodoActual][i];
            if(!visitados[vecino]) {
                colaNodos.push(vecino);
                visitados[vecino] = true;
                nivel[vecino] = nivel[nodoActual] + 1;
            }
        }
    }
}

void dfs(int nodoInicial) {
    stack<int> pilaNodos;
    colaNodos.push(nodoInicial);
    visitados[nodoInicial] = true;
    while(!pilaNodos.empty()) { // Java isEmpty
        int nodoActual = pilaNodos.top();
        pilaNodos.pop();
        for(int i = 0; i < grafo[nodoActual].size(); i++) {
            int vecino = grafo[nodoActual][i];
            if(!visitados[vecino]) {
                pilaNodos.push(vecino);
                visitados[vecino] = true;
            }
        }
    }
}


int main() {
    return 0;

}