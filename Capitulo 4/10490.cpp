#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

bool isPrime(int n){
    if(n == 1 || n == 0 ) {
        return false;
    }
    if(n == 2) {
        return true;
    } 
    if(n % 2 == 0){
        return false; 
    } 
    
    for(int i = 3; i*i<=n; i+=2) {
        if( n%i == 0) {
            return false;
        }
    }
    return true;
}


bool naivePrimeMarcos(int n) {

    if(n==1){        

      return false;
 
 }

    if(n==2) {

        return true;

    }
    if(n%2==0) {

        return false;

    }

 
    for(int i = 3; i*i<=n; i++) {  

        if(n%i == 0) { 

            return false;

        }


    }

    return true; 


}

int main( ){
    input;
    output;
    long long number; 
    while(cin>>number && number) {
        if(naivePrimeMarcos(number)) {
            long long rightNumber = (1<<number) - 1;  // pow(2,number);
            if(naivePrimeMarcos(rightNumber)) {
                long long perfectNumber = (1<<(number-1))*rightNumber;
                printf("Perfect: %lld!\n",perfectNumber);
            }
            else {
                printf("Given number is prime. But, NO perfect number is available.\n");
            }
        }
        else {
            printf("Given number is NOT prime! NO perfect number is available.\n");
        }
    }
    return 0;
}