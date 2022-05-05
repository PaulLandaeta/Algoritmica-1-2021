#include <bits/stdc++.h> // Para importar todas librerias
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define INF 100000010 // 1e9 
using namespace std;

int coins[] = {2, 3, 5, 6};

int f(int n) {
    if (n == 0) {
        return 0;
    }
    int answer = INF;    
    for(int i = 0; i < 4; i++) {
        if(n >= coins[i]) {
            answer = min(answer, f(n - coins[i]) + 1);
        }
    }
    return answer;
}
int dp[1000]; 

int dpTopDown(int n) {
    if(dp[n] == -1) {
        if (n == 0) {
            return 0;
        }
        int answer = INF;    
        for(int i = 0; i < 4; i++) {
            if(n >= coins[i]) {
                answer = min(answer, dpTopDown(n - coins[i]) + 1);
            }
        }
        dp[n] = answer;
    } 
    return dp[n];
}
int main() {
    int n = 1;
    memset(dp,-1,sizeof(dp));
    int result =  dpTopDown(n);
    if(result< INF){
        cout<<result <<endl;
    }else {
        cout<<"-1"<<endl;
    }
        
    return 0;
}
