#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
int filas, columnas, nroDepositos;
vector<string> matriz;
int di[]={0,1,1,1,0,-1,-1,-1};
int dj[]={1,1,0,-1,-1,-1,0,1}; 
char pintado = '0';
char target = '1'
void dfs(int fila, int columna) {
    matriz[fila][columna] = pintado;
    for(int i = 0; i < 8 ; i++) {
        int nuevafila = fila + di[i];
        int nuevacolumna = columna + dj[i];
        if( nuevafila >= 0 && nuevafila < filas && nuevacolumna >= 0 
            && nuevacolumna < filas && 
            matriz[nuevafila][nuevacolumna] == target) {
                dfs(nuevafila,nuevacolumna);
        }

    }
}

int main(){ 
    input;
    output;
    while(cin>>filas && filas){

        for(int i = 0;i < filas; i++) {
            string fila;
            cin>>fila;
            matriz.push_back(fila);
        }
        nroDepositos = 0;
        for(int i = 0; i < filas ; i++) {
            for(int j = 0; j < filas; j++) {
                if(matriz[i][j] == target) {
                    dfs(i,j);
                    nroIslas++;
                }
            }
        }
        cout<<nroDepositos<<endl;
        matriz.clear();
    }             
    
}