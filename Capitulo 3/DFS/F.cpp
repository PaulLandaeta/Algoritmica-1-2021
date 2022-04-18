#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

vector<int> grafo[26];
vector<bool> visitado(26);
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
    int cases;
    cin>>cases;
    for(int k=0; k<cases ;k++){
        string aristas;
        cin>>aristas;
        // (A,B)
        // 01234
        while(aristas[0]!='*'){
            char origenC = aristas[1];
            char destinoC = aristas[3];
            int origen = origenC - 'A';
            int destino = destinoC - 'A';
            grafo[origen].push_back(destino);
            grafo[destino].push_back(origen);
            cin>>aristas;
        }
        string nodes;
        cin>>nodes;
        vector<int> vnodos;
        for(int i = 0;i<nodes.size();i+=2) {
            int node = nodes[i] - 'A';
            vnodos.push_back(node);
        }
        int numeroNodos = vnodos.size();
        int bellotas = 0 ;
        int arbol = 0;
        for(int i = 0; i < numeroNodos; i++) {
            if(!visitado[vnodos[i]]) {
                cont = 0;
                dfs(vnodos[i]);
                if(cont > 1) {
                    arbol++;
                } else {
                    bellotas++;
                }
            }
        }
        //There are 2 tree(s) and 1 acorn(s).
        // printf("There are %d tree(s) and %d acorn(s).\n",arbol,bellotas);
        cout<<"There are "<<arbol<<" tree(s) and "<<bellotas<<" acorn(s)."<<endl;
        // Limpiar el arbol 
        for(int i = 0; i < 26; i++) {
            grafo[i].clear();
            visitado[i] = false;
        }
        
    }
}