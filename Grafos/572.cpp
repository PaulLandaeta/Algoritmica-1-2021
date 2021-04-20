#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
int filas, columnas, nroDepositos;
vector<string> matriz;
int di[]={0,1,1,1,0,-1,-1,-1};
int dj[]={1,1,0,-1,-1,-1,0,1}; 
void dfs(int fila, int columna) {
    matriz[fila][columna] = 'A';
    for(int i = 0; i < 8 ; i++) {
        int nuevafila = fila + di[i];
        int nuevacolumna = columna + dj[i];
        if( nuevafila >= 0 && nuevafila < filas && nuevacolumna >= 0 
            && nuevacolumna < columnas && 
            matriz[nuevafila][nuevacolumna] == '@') {
                dfs(nuevafila,nuevacolumna);
        }

    }
}

int main(){ 
    input;
    output;
    while(cin>>filas>>columnas && filas && columnas){

        for(int i = 0;i < filas; i++) {
            string fila;
            cin>>fila;
            matriz.push_back(fila);
        }
        // cout<<"---------"<<endl;
        /* for(int i=0;i<matriz.size();i++) {
            cout<<matriz[i]<<endl;
        }*/
        nroDepositos = 0;
        for(int i = 0; i < filas ; i++) {
            for(int j = 0; j < columnas; j++) {
                if(matriz[i][j] == '@') {
                    dfs(i,j);
                    nroDepositos++;
                    cout<<"---------"<<endl;
                    for(int i=0;i<matriz.size();i++) {
                        cout<<matriz[i]<<endl;
                    }
                }
            }
        }
        cout<<nroDepositos<<endl;
        matriz.clear();
    }             
    

/*
    
    int contadorIslas = 0;
    int islaMaxima = 0;
    for(int i = 0; i < rows ; i++) {
        for(int j = 0; j < columns; j++) {
            if(matriz[i][j] == 'l') {
                cont = 0;
                dfs(i,j);
                contadorIslas++;
                islaMaxima = max(cont,islaMaxima);
            }
        }
    }

    for(int i = 0; i < rows ; i++) {
        for(int j = 0; j < columns; j++) {
            cout<<"["<<matriz[i][j]<<"]";
        }
        cout<<endl;
    }
    cout<<contadorIslas<<endl;
    cout<<"islaMaxima "<<islaMaxima<<endl;
    
*/

    // lectura del Grafo
}