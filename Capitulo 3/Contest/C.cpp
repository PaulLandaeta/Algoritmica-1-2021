#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
vector<string> grafo;
int fila,columna;
int dx[]={-1,0,1,0,-1,1,1,-1};
int dy[]={0,1,0,-1,1,1,-1,-1};

void dfs(int x,int y) {
    grafo[x][y] = '*';
    for(int i=0;i<8;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<fila && ny>=0 && ny<columna && grafo[nx][ny]=='@') {
            dfs(nx,ny);
        }
    }
}


int main() {
    while(cin>>fila>>columna) {
        if(fila == 0 && columna == 0){
            break; // return 0;
        }
        grafo.clear();
        for(int i=0;i<fila;i++) {
            string temp;
            cin>>temp;
            grafo.push_back(temp);
        }
        int contador = 0;
        for(int i=0;i<fila;i++) {
            for(int j=0;j<columna;j++) {
                if(grafo[i][j] == '@') {
                    contador++;
                    dfs(i,j);
                }
            }
        }
    }
    return 0;
}