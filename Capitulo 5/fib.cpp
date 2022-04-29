#include <bits/stdc++.h> // Para importar todas librerias
#include <chrono>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define INF 100000010 // 1e9 
using namespace std;
using namespace std::chrono;

long long fib(long long n) {
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }
    return fib(n-1) + fib(n-2);
}
// fib DP top down 
long long dp[100];

long long fibDPTP(long long n) {
    if(dp[n] == -1) { // Todavia no calcule el valor de dp[n]
        dp[n] = fibDPTP(n-1) + fibDPTP(n-2);
    } 
    return dp[n];
}
int main() {
    // 1,1,2,3,5,8,13
    // 1 2 3 4 5 6 7 
    int n = 50; // 1 
    memset(dp,-1,sizeof(dp)); // n
    dp[0] = 0; // 1
    dp[1] = 1;// 1
    auto start = high_resolution_clock::now(); //1 
    cout<<fibDPTP(n)<<endl; // n
    auto stop = high_resolution_clock::now();//1
    auto duration = duration_cast<microseconds>(stop - start);//1
    cout << duration.count() << endl;//1 
    // T(n) = 8 + 2n;
    // O(n) = n; 
    // O(N) = fib() = 2^n
    return 0;
}