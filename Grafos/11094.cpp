#include <bits/stdc++.h>  // Para importar todas librerias
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
int rows, columns, cont;
vector<string> matriz;
void dfs(int row, int column) {
    matriz[row][column] = '@';
    if(row+1 < rows) {
        if(matriz[row+1][column] == 'l'){
            dfs(row+1,column);
        }
    }
    if(row-1 >= 0) {
        if(matriz[row-1][column] == 'l'){
            dfs(row-1,column);
        }
    }
    if(column+1 < columns) {
        if(matriz[row][column+1] == 'l'){
            dfs(row,column+1);
        }
    }
    if(column-1 >= 0) {
        if(matriz[row][column-1] == 'l'){
            dfs(row,column-1);
        }
    }
    cont++;
}


int main(){ 
    input;
    output;
    cin>>rows>>columns;               // scanf("%d %d", &vertices, &aristas)
    for(int i = 0;i < rows; i++) {
        string row;
        cin>>row;
        matriz.push_back(row);
    }
    
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
    


    // lectura del Grafo
}