#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

long long fib(long long n) {
    if(n == 0) 
        return 0;
    if(n == 1) 
        return 1;
    return fib(n-1) + fib(n-2);
}
long long dp[1000000];
long long fibDP(long long n) {
    if(n == 0) 
        return 0;
    if(n == 1) 
        return 1;
    if(dp[n] == -1 ) {
        dp[n] = fibDP(n-1) + fibDP(n-2);
    }
    return dp[n];
}

long long dpbt(int n){
    int a = 0;
    int b = 1;
    for(int i = 2;i <= n;i++) {
        int c = a + b; 
        a = b; 
        b = c;
    }
    return b;
}

int main() {
    memset(dp,-1,sizeof dp);
    cout<<dpbt(5)<<endl;
    cout<<dpbt(15)<<endl;
    return 0;
}