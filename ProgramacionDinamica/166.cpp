#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
int coins[]= {1, 2, 4, 10, 20 , 40};
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
    if(value < 0 || pos > totalCoins.size()) {
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
            total += cantidadMonedas[i];
            addCoins(i);
        }
        if(total == 0 ) {
            break;
        }
        cin>>cambio;
        for(int i = 0; i < totalCoins.size();i++) {
           cout<<"["<<totalCoins[i]<<"]";
        }
         cout<<endl;
        memset(dp,-1,sizeof dp);
        int money = (int)((cambio+0.000000001)*100);
        printf("%3d\n",f(money/5,0));
    }
    
    return 0;
}