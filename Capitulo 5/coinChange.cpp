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

int coinChangeBottomUP(int value) {
    int dp2[5][1000];
    memset(dp2,0,sizeof dp2);
    for(int i = 1; i <= value ;i++) {
        dp2[0][i] = 1e9;
    }

    for (int i = 1 ;i <= 4; i++ ) {
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
    
    return dp2[4][value];
}

int main() {
    int n = 100;
    memset(dp,-1,sizeof(dp)); // -1 0 1 
    // sizeof(dp) el tamaño del vector
    // for (int i = 0; i < sizeof(dp); i++) {
    //     dp[i] = -1;
    // }
    // int grafo[100][100];
    // memset(grafo, 0, sizeof(grafo));
    // for (int i =0 ;i< 100;i++) {
    //     for(int j=0;j<100;j++) {
    //         grafo[i][j] = 0;
    //     }
    // }
    cout<<"Top Down "<<endl;
    int result =  dpTopDown(n);
    if(result< INF){
        cout<<result <<endl;
    }else {
        cout<<"-1"<<endl;
    }


    cout<<"bottom up"<<endl;
    int result2 = coinChangeBottomUP(n);
    if(result2 < INF){
        cout<<result2 <<endl;
    }
        
    return 0;
}
