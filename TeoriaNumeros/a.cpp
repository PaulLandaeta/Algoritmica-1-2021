#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

int n = 1000;
vector<bool> primes(n+1,true);
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

long long sieve_size;
bitset<10000010> bs;
vector<long long> only_primes;  

void sieve2(long long number) {
    sieve_size = number + 1;
    bs.set();               // poner todos los bits en 1
    bs[0] = bs[1] = 0;
    for(long long i = 2; i < sieve_size; i++) {
        if(bs[i]) {
            for(long long j = i*i; j < sieve_size; j +=i) {
                bs[j] = 0;
            }
            only_primes.push_back(i);
        }
    }
}

int sumDigit(int x) {
    int sumTotal = 0;
    while(x>0) {
        sumTotal += x%10;
        x /=10;
    }
    return sumTotal;

}

int main() {
    input;
    output;
    sieve();
    int x,y;
    cin>>x>>y;
    int cont = 0;
    for(int i = x; i<= y; i++) {
        if(primes[i] && primes[sumDigit(i)]) {
          cont++;
        }
    }
    cout<<cont<<endl;
}