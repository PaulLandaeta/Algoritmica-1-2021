#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
vector<bool> primes(1000,true);
void sieve() {
    primes[0] = primes[1] = false;
    for(int i = 2;i < n; i++) {
        if(primes[i]) {
            for(int j = i+i; j < n ; j+= i ) {
                primes[j] = false;
            }
        } 
    }
}

int  sumDigit (int n) {
    int s = 0;
    while (n>0)
    {
       s= s+ n%10;
       n = n/10;
    }
    return s;
}
int main() {
    sieve();
    int x,y;
    cin>>x>>y;
    
    int cont = 0;
    for(int i = x; i<= y; i++) {
        if(primes[i] && primes[sumDigit(i)]) {
          cont++;
        }
    }
    return 0;
}