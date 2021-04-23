#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
int filas, columnas, nroInstrucciones,stickers;
string instrucciones;
vector<string> matriz;
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
void dfs(int fila, int columna, int i, int direccion) {
    if(i >= nroInstrucciones) {
        return;
    }
    if(fila < 0 || fila >= filas || columna <0 || columna>= columnas) {
        return;
    }
    if(matriz[fila][columna] == '#') {
        return;
    }
    if(matriz[fila][columna] == '*') {
        stickers++;
        matriz[fila][columna] = '.';
    }

    if( instrucciones[i] == 'F') {
        int nuevaFila = fila+dy[direccion];
        int nuevaColumna = columna+dx[direccion];
        if(nuevaFila >= 0 && nuevaFila < filas && nuevaColumna >= 0 && nuevaColumna < columnas && matriz[nuevaFila][nuevaColumna] != '#') {
            dfs(fila+dy[direccion],columna+dx[direccion],i+1,direccion);
        }else {
            dfs(fila,columna,i+1,direccion);
        }
    }else if (instrucciones[i] == 'D')
    {
        // giro a derecha
        // direccion = (direccion+1)%4;
        direccion++;
        if(direccion == 4) {
            direccion = 0;
        }
        
    }else {
        // giro a la izquierda
        direccion--;
        if(direccion == -1) {
            direccion = 3;
        }
    }
     dfs(fila,columna,i+1,direccion); 
     
}

int main() {
    input;
    output;
    while(cin>>filas>>columnas>>nroInstrucciones && filas && columnas && nroInstrucciones){ 
        for(int i = 0;i < filas;i++) {
            string row;
            cin>>row;
            matriz.push_back(row);
        }
        cin>>instrucciones;
        int fila, columna;
        for(int i = 0;i < filas;i++) {
          for(int j = 0; j < columnas; j++){
              if(matriz[i][j] != '*' && matriz[i][j] != '#' && matriz[i][j] != '.'){
                  fila = i;
                  columna = j;
              }
          }
        }
        int direccion;
        if(matriz[fila][columna] == 'N'){
            direccion = 0;
        }else if(matriz[fila][columna] == 'L') {
            direccion = 1;
        }else if(matriz[fila][columna] == 'S') {
            direccion = 2;
        }else {
            direccion = 3;
        }
        stickers = 0;
        dfs(fila,columna,0,direccion);
        cout<<stickers<<endl;
        matriz.clear();

    }
    


}