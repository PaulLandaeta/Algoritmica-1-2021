#include <bits/stdc++.h> // Para importar todas librerias
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int filas, columnas, cont;
vector<string> matriz;
char land = '@';
int di[] = {0, 1, -1, 0};
int dj[] = {1, 0, 0, -1};
void dfs(int fila, int columna)
{
    matriz[fila][columna] = '.';
    cont++;
    for (int i = 0; i < 4; i++)
    {
        int nuevafila = fila + di[i];
        int nuevacolumna = columna + dj[i];
        if(nuevacolumna < 0)   nuevacolumna = columnas - 1;
        if(nuevacolumna >= columnas)  nuevacolumna = 0;
        if (nuevafila >= 0 && nuevafila < filas && nuevacolumna >= 0 && nuevacolumna < columnas &&
            matriz[nuevafila][nuevacolumna] == land)
        {
            dfs(nuevafila, nuevacolumna);
        }
    }
 
}

int main()
{
    input;
    output;
    while (cin >> filas >> columnas)
    {
        for (int i = 0; i < filas; i++)
        {
            string row;
            cin >> row;
            matriz.push_back(row);
        }
        int x, y;
        cin >> x >> y;
        land = matriz[x][y];
        dfs(x, y);
        int islaMaxima = 0;
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                if (matriz[i][j] == land)
                {
                    cont = 0;
                    dfs(i, j);
                    islaMaxima = max(cont, islaMaxima);
                }
            }
        }
        cout << islaMaxima << endl;
        matriz.clear();
    }
}