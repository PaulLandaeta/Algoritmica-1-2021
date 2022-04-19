#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
int  grafo[1010][1010]; // Grafo de Matriz
int  nivel[1010][1010]; // Nivel en Matriz
int fila, columna; // filas y columnas del grafo
// Pair (int, int)
void bfs(int nodoX, int nodoY) {
    queue<pair<int,int> > cola; // Java Tupla
    cola.push(make_pair(nodoX, nodoY));
    grafo[nodoX][nodoY] = 1;
    nivel[nodoX][nodoY] = 0;
    while(!cola.empty()) {
        pair<int,int> actual = cola.front();
        cola.pop();
        int x = actual.first;
        int y = actual.second;
        // // visitar el nodo de Izq
        if(x-1 >= 0 && grafo[x-1][y] == 0) {
            grafo[x-1][y] = 1;
            cola.push(make_pair(x-1, y));
            nivel[x-1][y] = nivel[x][y] + 1;
        }
        // visitar el nodo de derecha
        if(x+1 <= columna && grafo[x+1][y] == 0) {
            grafo[x+1][y] = 1;
            cola.push(make_pair(x+1, y));
            nivel[x+1][y] = nivel[x][y] + 1;
        }
        // visitar el nodo de Arriba
        if(y-1 >= 0 && grafo[x][y-1] == 0) {
            grafo[x][y-1] = 1;
            cola.push(make_pair(x, y-1));
            nivel[x][y-1] = nivel[x][y] + 1;
        }
        // visitar el nodo de Abajo
        if(y+1 <= fila && grafo[x][y+1] == 0) {
            grafo[x][y+1] = 1;
            cola.push(make_pair(x, y+1));
            nivel[x][y+1] = nivel[x][y] + 1;
        }
    }
}


int main() {
    //input;
    while(cin>>fila>>columna) {
        if(fila==0 && columna==0) {
            break;
        }
        // Clear Grafo
        memset(grafo,0,sizeof(grafo));// poner todo en 0;
        memset(nivel,0,sizeof(nivel));// limpiar Niveles
        int filas;
        cin>>filas;
        for(int i=0;i<filas;i++) {
           int row; cin>>row;
           int bombs; cin>>bombs;
           for(int j=0;j<bombs;j++) {
               int col; cin>>col;
               grafo[row][col] = 1; // Lo marcamos como visitado si existe una bomba
           }
        }
        int xinicio, yinicio, xfinal, yfinal;
        cin>>xinicio>>yinicio>>xfinal>>yfinal;
        bfs(xinicio, yinicio);
        cout<<nivel[xfinal][yfinal]<<endl;
    }
}