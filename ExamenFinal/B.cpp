#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
vector<pair <int,int> > objetos;
// objetos.push_back(make_pair(5,100));
// objetos.push_back(make_pair(7,50));
// objetos.push_back(make_pair(8,75));
// objetos.push_back(make_pair(15,20));
// objetos.push_back(make_pair(25,39));
// sort(objetos.begin(),objetos.end())

int backpackBUP1D(int pesoTotal) {
    int sol[pesoTotal+1]; 
    memset(sol,0,sizeof(sol));
    for(int j = 0; j< objetos.size() ;j++) {
        for (int i = pesoTotal; i >= objetos[j].first; i--) {
            sol[i] = max(sol[i],objetos[j].second+sol[i-objetos[j].first]);
        }
    }
    return sol[pesoTotal];
}

int main() {
    // memset(dp,-1,sizeof dp);
    //cout<<coinChange(11)<<endl;
    input;
    int cases;
    cin>>cases;
    while(cases--) {
        int nroObjetos;
        objetos.clear();
        cin>>nroObjetos;
        for(int i = 0; i < nroObjetos; i++) {
            int c,w;
            cin>>c>>w;
            objetos.push_back(make_pair(w,c));
        }
        sort(objetos.begin(),objetos.end());
        int nroPersonas;
        cin>>nroPersonas;
        int answer = 0;
        for(int i = 0; i < nroPersonas; i++){
            int pesoPersona;
            cin>>pesoPersona;
            answer+=backpackBUP1D(pesoPersona);
        }
        cout<<answer<<endl;
        
    }
    
    return 0;
}