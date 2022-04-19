#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
int  grafo[1010][1010];
int fila, columna;

void bfs() {

}


int main() {
    while(cin>>fila>>columna) {
        if(fila==0 && columna==0) {
            break;
        }
        memset(grafo,0,sizeof(grafo));// poner todo en 0;
        int filas;
        cin>>filas;
        for(int i=0;i<filas;i++) {
           int row; cin>>row;
           int bombs; cin>>bombs;
           for(int j=0;j<bombs;j++) {
               int col; cin>>col;
               grafo[row][col] = 1;
           }
        }
        int xinicio, yinicio, xfinal, yfinal;
        bfs(xinicio, yinicio);
        cout<<nivel[xfinal][yfinal]<<endl;
    }
}