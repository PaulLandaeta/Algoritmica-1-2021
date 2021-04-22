#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

bool isPrime(int n) {
    int cont = 1;
    for(int i = 2; i<=n ; i++) {
        if(n%i==0) {
            cont++;
        }
    }
    if(cont == 2){
        return true;
    }
    return false;
}


bool isPrime2(int n){
    if(n == 1 || n == 0) {
        return false;
    }
    if(n == 2) {
        return true;
    } 
    for(int i = 3; i*i<=n; i+=2) {
        if( n%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    
}