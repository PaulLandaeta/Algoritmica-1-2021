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
// a y b > 0   a > b // ale 1.
int lcm(int a,int b) { 
    return a*(b/gcd(a,b));
}
int mcd(int a,int b) {
    while(b>0) {
        a = b;
        b = a%b;
    }
    return a;
}

int main() {
    input;
    output;

    cout<<gcd(12312312,12312312)<<endl;
    cout<<lcm(12312312,12312312)<<endl;
    
}