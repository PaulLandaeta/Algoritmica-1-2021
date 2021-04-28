#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std;
vector<string> matriz;
int di[]={0,1,1,1,0,-1,-1,-1};
int dj[]={1,1,0,-1,-1,-1,0,1};
int filas, columnas, grupo, star;
 
void dfs(int fila, int columna){
    matriz[fila][columna] = 'A';
    grupo++;
    for(int i = 0; i < 8 ; i++) {
        int nuevafila = fila + di[i];
        int nuevacolumna = columna + dj[i];
        if( nuevafila >= 0 && nuevafila < filas && nuevacolumna >= 0 
            && nuevacolumna < columnas && 
            matriz[nuevafila][nuevacolumna] == '*') {
                dfs(nuevafila,nuevacolumna);
        }
    }
}
 
int main(){
    input;
    output;
    while (cin >> filas >> columnas && filas && columnas){
        for(int i = 0; i < filas; i++) {
            string fila;
            cin >> fila;
            matriz.push_back(fila);
        }
        grupo = 0;
        star = 0;
        for(int i = 0; i < filas ; i++) {
            for(int j = 0; j < columnas; j++) {
                if(matriz[i][j] == '*') {
                    dfs(i,j);
                    cout<<"grupo"<<grupo<<endl;

                    if(grupo == 1){
                        star++;
                        
                    }
                    grupo = 0;
                }
            }
        }
        matriz.clear();
        cout << star << endl;
    }
}