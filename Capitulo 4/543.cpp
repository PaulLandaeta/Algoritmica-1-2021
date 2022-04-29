#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

int n = 1000000;
vector<bool> primes(n,true);
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
    int number; 
    
    while(cin>>number && number) {
        bool printed = false;
        for(int i = 2; i < 1000000 && !printed; i++) {
            if(primes[i]) // i es primo
            {
                int x = i; 
                int y = number - x;
                if(primes[y])// si y es primo debo parar el programa
                {
                    printf("%d = %d + %d\n",number,x,y);
                    printed = true;
                }
            }
        }
        if(!printed) { // No se encontro solucion
            cout<<"Goldbach's conjecture is wrong."<<endl;
        }
    }
}