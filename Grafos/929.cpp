#include <bits/stdc++.h> // Para importar todas librerias
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define INF 100000010
using namespace std;

int maze[1001][1001];

int rows,columns;

int vis[1000][1000]; 
int dis[1000][1000];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

// j + i * columns; 
void dijkstra()
{
    // memset(distancia, INF, sizeof(distancia)); // -1 0 1
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j<1000;j++) {
            dis[i][j] = INF;    
        }
    }
    memset(vis, 0, sizeof(vis));


    dis[0][0] = maze[0][0];
    
    multiset<pair<int, pair<int,int> > > colaPrioridad;
    colaPrioridad.insert(make_pair(maze[0][0], make_pair(0,0)));

    while (!colaPrioridad.empty())
    {
        pair<int, pair<int,int> > verticeActual = *colaPrioridad.begin();
        colaPrioridad.erase(colaPrioridad.begin());
        pair<int, int > vertice = verticeActual.second;
        int peso = verticeActual.first;

        // j + i * columns; 
        if (vis[vertice.first][vertice.second])
        {
            continue;
        }
        vis[vertice.first][vertice.second] = true;

        for (int i = 0; i < 4; i++)
        {
            int x =  vertice.first + dx[i];
            int y =  vertice.second + dy[i];
            // Verificiar que x e y no salgan del maze 
            if(x>=0 && x<rows && y>=0 && y<columns) {
                int pesoVecino = maze[x][y];
                if (dis[vertice.first][vertice.second] + pesoVecino < dis[x][y])
                {
                    dis[x][y] = dis[vertice.first][vertice.second] + pesoVecino;
                    colaPrioridad.insert(make_pair(dis[x][y],make_pair(x,y)));
                }
            }
        }
    }
}

int main()
{
    input;
    output;
    int cases; 
    cin>>cases;
    while(cases--) {
        
        cin>>rows>>columns;
        for(int i=0; i < rows;i++) {
            for(int j = 0; j < columns;j++) {
                cin>>maze[i][j];
            }
        }

        dijkstra();

        cout<<dis[rows-1][columns-1]<<endl;

    }
}