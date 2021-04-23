#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
int filas, columnas, nroDepositos;
char letra;
vector<string> matriz;
int di[]={0,0,1,-1};
int dj[]={1,-1,0,0};
void dfs(int fila, int columna) {
    matriz[fila][columna] = '*';
    for(int i = 0; i < 4 ; i++) {
        int nuevafila = fila + di[i];
        int nuevacolumna = columna + dj[i];
        if( nuevafila >= 0 && nuevafila < filas && nuevacolumna >= 0 
            && nuevacolumna < columnas && 
            matriz[nuevafila][nuevacolumna] == letra) {
                dfs(nuevafila,nuevacolumna);
        }

    }
}

int main() {
    input;
    output;
    int cases; 
    cin>>cases;
    int test = 1;
    while(cases--){ 
        cin>>filas>>columnas;
        for(int i = 0;i < filas;i++) {
            string row;
            cin>>row;
            matriz.push_back(row);
        }

        int letras[27];
        memset(letras, 0, sizeof(letras));
        for(int i = 0; i < filas;i++) {
            for(int j = 0; j< columnas; j++) {
                letra = matriz[i][j];
                if( letra != '*') {
                    dfs(i,j);
                    letras[letra-'a']++;
                }
            }
        }

        vector<pair<char,int > > resultados;
        for(int i = 'a'; i <= 'z';i++) {
             if(letras[i-'a']>0) {
                resultados.push_back(make_pair((char)i,letras[i-'a']));
             }
        }
        cout<<"World #"<<test++<<endl;
        for(int i = 0; i < resultados.size();i++) {
             for(int j = i+1; j<resultados.size();j++) {
                 if(resultados[j].second>resultados[i].second){
                     swap(resultados[i],resultados[j]);// manual
                     // pair<int,int> temp = resultados[i];
                     // resultados[i] = resultados[j];
                     // resultados[j] = temp;
                 }else {
                     if(resultados[j].second == resultados[i].second) {
                         if(resultados[i].first > resultados[j].first) {
                             swap(resultados[i],resultados[j]);// manual
                            // pair<int,int> temp = resultados[i];
                            // resultados[i] = resultados[j];
                            // resultados[j] = temp;
                         }
                     }
                 }
             }
        }
        for(int i = 0; i < resultados.size();i++) {
                 cout<<resultados[i].first<<": "<<resultados[i].second<<endl;
            }

        matriz.clear();

    }
    


}