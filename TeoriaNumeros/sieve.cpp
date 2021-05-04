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

int main() {
    input;
    output;
    sieve();
    sieve2(1000000);
    for(int i=0;i<only_primes.size();i++) {
        cout<<only_primes[i]<<endl;
    }    
    int number;
    while(cin>>number) {
        
        if(primes[number]) {
            cout<<number<<" es primo!!!!!"<<endl;
        }
        for (int i = 1 to primes2.size()) {
            if(primes2[i]>= X ){
                cont++;
            }
        }
        else {
            cout<<cont<<" no es primo!!!!!"<<endl;
        }
    }
}