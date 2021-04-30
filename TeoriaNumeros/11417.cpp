#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

int gcd(int a, int b) {
    if(b == 0) {
        return a; 
    }
    return gcd(b, a%b);
}

int main() {
    input;
    output;
    int number;
    while(cin>>number && number){
        int G=0;
        for(int i=1;i<number;i++){
            for(int j=i+1;j<=number;j++){
                G+=gcd(i,j);
            }
        }
        cout<<G<<endl;
    }
    
    
}