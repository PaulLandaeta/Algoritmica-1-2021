#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
vector<long long> divisores;
void getDivisores(long long number) {
    divisores.clear();
    int sqrtNumber = sqrt(number);
    for(long long i = 1; i <= sqrtNumber; i++) {
        if(number%i == 0) {
            divisores.push_back(i);
            if(i != number/i) {
                divisores.push_back(number/i);
            }
        }
    }
}

long long gcd(long long a, long long b) {
    if(b == 0) {
        return a; 
    }
    return gcd(b, a%b);
}

int lcm(long long a,long long b) { 
    return a*(b/gcd(a,b));
}

int main() {
    input;
    output;
    long long number;
    while(cin>>number && number){
       getDivisores(number);
       int cont = 0;
       for(int i = 0; i < divisores.size();i++) {
           for( int j = i+1; j < divisores.size();j++) {
               if(lcm(divisores[i],divisores[j]) == number) {
                   // cout<<divisores[i]<<" "<<divisores[j]<<endl;
                   cont++;
               }
           }
       }
       printf("%lld %d\n",number,cont+1);
    }
}