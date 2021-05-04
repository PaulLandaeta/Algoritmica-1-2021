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

int main() {
    memset(dp,-1,sizeof dp);
    cout<<coinChange(11)<<endl;
    return 0;
}