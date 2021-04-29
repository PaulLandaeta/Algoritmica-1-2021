#include <bits/stdc++.h> // Para importar todas librerias
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define INF 100000010
using namespace std;
int rows, columns;
int maze[1000][1000];
int forRow[] = {0, 1, 0, -1};
int forColumn[] = {1, 0, -1, 0};
int vis[1000][1000];
int dis[1000][1000];
int newColumn, newRow;

void dijkstra2()
{
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            dis[i][j] = INF;

    memset(vis, 0, sizeof(vis));

    multiset<pair<int, pair<int, int> > > colaPrioridad;
    dis[0][0] = maze[0][0];

    colaPrioridad.insert(make_pair(maze[0][0], make_pair(0, 0)));
    while (!colaPrioridad.empty())
    {
        pair<int, pair<int, int> > verticeActual = *colaPrioridad.begin();
        colaPrioridad.erase(colaPrioridad.begin());
        pair<int, int> vertice = verticeActual.second;
        int peso = verticeActual.first;
        if (vis[vertice.first][vertice.second])
        {
            continue;
        }
        vis[vertice.first][vertice.second] = true;

        for (int i = 0; i < 4; i++)
        {
            newColumn = vertice.second + forColumn[i];
            newRow = vertice.first + forRow[i];

            if ((newRow >= 0) && (newRow < rows) && (newColumn >= 0) && (newColumn < columns))
            {
                pair<int, int> verticeVecino = make_pair(newRow, newColumn);
                // verticeVecino.first = newRow;
                // verticeVecino.second = newColumn;

                int pesoVecino = maze[newRow][newColumn];
                if (dis[vertice.first][vertice.second] + pesoVecino < dis[verticeVecino.first][verticeVecino.second])
                {
                    dis[verticeVecino.first][verticeVecino.second] = dis[vertice.first][vertice.second] + pesoVecino;
                    pair<int, pair<int, int> > newVertice = make_pair(dis[verticeVecino.first][verticeVecino.second], make_pair(verticeVecino.first, verticeVecino.second));
                    colaPrioridad.insert(newVertice);
                    //
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
    cin >> cases;
    //    cout<<endl;
    for (int c = 0; c < cases; c++)
    {

        cin >> rows >> columns;
        for (int i = 0; i < rows; i++)
        {

            for (int j = 0; j < columns; j++)
            {

                int peso;
                cin >> peso;
                maze[i][j] = peso;
            }
        }

        dijkstra2();
        cout << dis[rows - 1][columns - 1] << endl;
        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < 1000; j++)
            {
                maze[i][j] = 0;
            }
        }
    }
}