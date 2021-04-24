#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

int dist(pair<int,int> p1, pair<int, int> p2) {
	return pow(p1.first - p2.first,2) + pow(p1.second - p2.second,2);
}

vector<int> grafo[1010];
bool visited[1010];
int contStations;
void dfs(int pos) {
    visited[pos] = true;
    if(!visited[grafo[pos][0]]){
        dfs(grafo[pos][0]);
    }
    if(!visited[grafo[pos][1]]){
        dfs(grafo[pos][1]);
    }
    contStations++;
}

int main() {
    input;
    output;
	int n;
	while (cin >> n && n) {
		vector<pair<int,int> > stations;
		for (int i = 0; i < n; i++){
            int x,y;
            cin>>x>>y;
            stations.push_back(make_pair(x,y));
        }
		for(int i = 0; i<1010;i++) {
            grafo[i].clear();
        }
		for (int i = 0; i < n; i++) {
			int min1 = INT_MAX, min2 = INT_MAX;
			int pos1 = -1, pos2 = -1;
			for (int j = 0; j < n; j++)
				if (i != j) {
					int distance = dist(stations[i], stations[j]);
					if (distance <= min1) {
						min2 = min1;
						min1 = distance;
						pos2 = pos1;
						pos1 = j;
					} else if (distance < min2) {
						min2 = distance;
						pos2 = j;
					}
				}
            // creamos el grafo
            grafo[i].push_back(pos1);
            grafo[i].push_back(pos2);
		}
		memset(visited, false, sizeof(visited));
		contStations = 0;
        dfs(0);
        if (contStations == n)
			cout << "All stations are reachable.\n";
		else
			cout << "There are stations that are unreachable.\n";
	}
	return 0;
}