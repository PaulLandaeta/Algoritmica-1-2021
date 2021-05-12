#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
int coins[]= {5, 10, 20, 50, 100, 200};
int cantidadMonedas[6];
int dp[10010][10010];
vector<int> totalCoins;

void addCoins(int pos){
    while(cantidadMonedas[pos]--) {
        totalCoins.push_back(coins[pos]);
    }
}


int f(int value, int pos) {
    if(value == 0) {
        return 0;
    }
    if(value < 0 || pos == totalCoins.size()) {
        return 1e9;
    }
    if(dp[value][pos] == -1) {
        dp[value][pos] = min(f(value,pos+1),1+f(value-totalCoins[pos],pos+1));
    }
    return dp[value][pos];
}

int main() {
    input;
    output;
    double cambio; 
    while(true) {
        totalCoins.clear();   
        int total = 0;
        for(int i = 0; i < 6 ; i++) {
            cin>>cantidadMonedas[i];
            addCoins(i);
            total += cantidadMonedas[i];
        }
        if(total == 0 ) {
            break;
        }
        cin>>cambio;

        memset(dp,-1,sizeof dp);
        printf("%3d\n",f(int((cambio+0.000000001)*100),0));
    }
    
    return 0;
}