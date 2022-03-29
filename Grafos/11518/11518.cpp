#include <bits/stdc++.h> // Para importar todas librerias
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

vector<int> graph[10010];
bool visited[10010];
int fallTiles = 0;
void dfs(int firstTile){
    visited[firstTile] = true;
    for(int i = 0; i < graph[firstTile].size(); i++){
        if(!visited[graph[firstTile][i]]){
            dfs(graph[firstTile][i]);
        }
    }
    fallTiles++;
}

void cleanGraph()
{
    fallTiles = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < 10010; i++)
        graph[i].clear();
}

int main()
{
    input;
    output;
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        cleanGraph();
        int numberTiles, connection, hands;
        cin >> numberTiles >> connection >> hands;
        // Leer las conexiones
        for (int i = 0; i < connection; i++)
        {
            int firstTile, secondTile;
            cin >> firstTile >> secondTile;
            graph[firstTile].push_back(secondTile);
        }
        // Leer las caidas
        for (int i = 0; i < hands; i++)
        {
            int tile;
            cin >> tile;
            if(!visited[tile]){
                dfs(tile);
            }
        }
        cout << fallTiles << endl;
    }
}