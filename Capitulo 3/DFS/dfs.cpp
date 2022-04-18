#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

vector<int> grafo[15];
vector<bool> visitado(15);
int cont;
void dfs(int verticeActual) {
    cont++;
    visitado[verticeActual] = true;
    int numeroVecinos = grafo[verticeActual].size();
    for(int i = 0; i < numeroVecinos; i++) {
        int vecino = grafo[verticeActual][i];
        if(!visitado[vecino]) {
            dfs(vecino);
        }
    }
}

int main() {
input; 
int vertices, aristas;
cin>>vertices>>aristas;
for(int i = 0; i < aristas;i++) {
    int verticeOrigen, verticeDestino;
    cin>>verticeOrigen>>verticeDestino;
    grafo[verticeOrigen].push_back(verticeDestino);
    grafo[verticeDestino].push_back(verticeOrigen);
}
cont =0;
dfs(0);
if(visitado[9]) {
    cout<<"Se entrego la llave"<<endl;
} else {
    cout<<"No esta conectada"<<endl;
}

}