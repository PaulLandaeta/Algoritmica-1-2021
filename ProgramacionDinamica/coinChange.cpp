#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

int coins[]= {1,5,6,9};
int dp[1000000];
int coinChange(int value) {
    if(value == 0)
        return 0;
    if(dp[value] == -1){
        int minValue = 1e9; // INF
        for(int i = 0; i < sizeof(coins)/sizeof(coins[0]); i++) {
            if(value-coins[i]>=0) {
                minValue = min(minValue, 1 + coinChange(value-coins[i]) );
            }
            
        }  
        dp[value] = minValue;  
    }
    return dp[value];
}

int coinChangeBottom(int value) {
    int dp2[5][100];
    memset(dp2,0,sizeof dp2);
    for(int i = 1; i <= value ;i++) {
        dp2[0][i] = 1e9;
    }

    for (int i = 1 ;i <= sizeof(coins)/sizeof(coins[0]); i++ ) {
        for(int j = 0; j <= value ; j++ ){
            if(j-coins[i-1]>=0) {
                int valor = 1 + dp2[i][j-coins[i-1]];
                dp2[i][j] = min (valor, dp2[i-1][j]);
            }
            else {
                dp2[i][j] = dp2[i-1][j];
            }
        }
    }
    
    return dp2[sizeof(coins)/sizeof(coins[0])][value];
}

int main() {
    memset(dp,-1,sizeof dp);
    //cout<<coinChange(11)<<endl;
    cout<<coinChangeBottom(11)<<endl;
    return 0;
}