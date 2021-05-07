#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
int coins[]= {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

long long coinChangeBottomWays(int value) {
    
    long long dp2[12][30010];
    memset(dp2,0,sizeof dp2);
    for(int i = 0; i <= sizeof(coins)/sizeof(coins[0]) ;i++) {
        dp2[i][0] = 1LL;
    }

    for (int i = 1 ;i <= sizeof(coins)/sizeof(coins[0]); i++ ) {
        for(int j = 0; j <= value ; j++ ){
            if(j-coins[i-1]>=0) {
                dp2[i][j] = dp2[i][j-coins[i-1]] + dp2[i-1][j];
            }
            else {
                dp2[i][j] = dp2[i-1][j];
            }
        }
    }
    
    return dp2[sizeof(coins)/sizeof(coins[0])][value];
}

int main() {
    //$100, $50, $20, $10, and $5 notes and $2, $1, 50c, 20c, 10c and 5c
    // 5 10 20 50 100 200 500 1000 2000 5000 10000
    input;
    output;
    double cambio; 
    while(cin>>cambio && cambio) {
        // cout<<coinChangeBottomWays((int)(cambio*100))<<endl;
        printf("%6.2f%17lld\n",cambio,coinChangeBottomWays(int((cambio+0.001)*100)));
        // System.out.printf();
    }
    
    return 0;
}