#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
int peso[]={5,7,8,15,25};
int ganancia[]={10,50,75,20,39};
// vector<pair <int,int> > objetos;
// objetos.push_back(make_pair(5,100));
// objetos.push_back(make_pair(7,50));
// objetos.push_back(make_pair(8,75));
// objetos.push_back(make_pair(15,20));
// objetos.push_back(make_pair(25,39));
// sort(objetos.begin(),objetos.end())
int dp[10][100000]; // el tamanho depende mucho del problema
int knapsack(int pesoMochila) {
    memset(dp,0,sizeof(dp));
    for(int i = 1; i<= 5; i++) {
        int pesoActual = peso[i-1];
        int gananciaActual = ganancia[i-1];
        for(int j = 1; j<= pesoMochila; j++) {
            if(j-pesoActual >=0) {
                int nuevoPeso = j - pesoActual;
                int valor = gananciaActual + dp[i-1][nuevoPeso]; 
                dp[i][j] = max(valor, dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int i=0;i<6;i++) {
        for(int j = 0; j <=pesoMochila;j++) {
            cout<<"["<<dp[i][j]<<"]";
        }
        cout<<endl;
    }
    return dp[5][pesoMochila];
}
int nroObjetos = 5;
int backpackTD(int i, int pesoMochila) {
    if(pesoMochila-peso[i]<0) {
        return 0;
    }
    if(i >= nroObjetos) {
        return 0;
    }
    if(dp[i][pesoMochila] == -1) {
        dp[i][pesoMochila] = max(ganancia[i]+backpackTD(i+1,pesoMochila-peso[i]), backpackTD(i+1,pesoMochila));
    }
    return dp[i][pesoMochila];
}


int backpackBUP1D(int pesoTotal) {
    int sol[pesoTotal+1]; 
    memset(sol,0,sizeof(sol));
    for(int j = 0; j< sizeof(peso)/sizeof(peso[0]) ;j++) {
        for (int i = pesoTotal; i >= peso[j]; i--) {
            sol[i] = max(sol[i],ganancia[j]+sol[i-peso[j]]);
        }
    }
    return sol[pesoTotal];
}

int main() {
    // memset(dp,-1,sizeof dp);
    //cout<<coinChange(11)<<endl;
    memset(dp,-1,sizeof dp);
    cout<<backpackBUP1D(59)<<endl;
    return 0;
}