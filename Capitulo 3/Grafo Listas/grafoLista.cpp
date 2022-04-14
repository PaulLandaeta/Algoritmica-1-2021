#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

int main(){
    input;
    int vertices, aristas;
    cin>>vertices>>aristas;
    vector<int> grafo[vertices];
    for(int i = 0;i<aristas;i++) {
        int a,b;
        cin>>a>>b;
        grafo[a].push_back(b);
        // Comentar la linea de abajo si el grafo es dirigido
        // grafo[b].push_back(a);
    }

    for(int i = 0;i<vertices;i++) {
        cout<<"["<<i<<"] -> ";
        for(int j = 0;j<grafo[i].size();j++) {
            cout<<"["<<grafo[i][j]<<"]";
        }
        cout<<endl;
    }

    return 0;
}