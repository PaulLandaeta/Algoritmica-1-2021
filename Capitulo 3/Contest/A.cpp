#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
int  grafo[1010][1010]; // Grafo de Matriz
int  nivel[1010][1010]; // Nivel en Matriz
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
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
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < fila && ny >= 0 && ny < columna && grafo[nx][ny] == '@') {
                grafo[nx][ny] = '*';
                nivel[nx][ny] = nivel[x][y] + 1;
                cola.push(make_pair(nx, ny));
            }
        }
    }
}


int main() {
    input;
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