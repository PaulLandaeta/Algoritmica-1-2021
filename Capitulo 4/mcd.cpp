#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

long long gcd(long  a, long b) {
    if(b == 0) {
        return a; 
    }
    return gcd(b, a%b);
}
// a y b > 0   a > b 
long long lcm(long long a,long long b) { 
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
    if(b>a) {
        temp = b;
        b = a;
        a = temp;
        swap(a,b);
    }
    cout<<gcd(12312312,12312312)<<endl;
    cout<<lcm(12312312,12312312)<<endl;


    /// que pasa si quiero el gcd de 3 o mas numeros
    int a,b,c; 
    cin>>a>>b>>c; 
    cout<<gcd(a,gcd(b,c))<<endl;
    cout<<gcd(c,gcd(a,b))<<endl;
    cout<<gcd(b,gcd(a,c))<<endl;
    cout<<gcd(gcd(a,b),c)<<endl;
    cout<<gcd(gcd(a,c),b)<<endl;
   
    int gcd_temp = gcd(a,b);
    int numeros;
    cin>>numeros;
    for(int i = 2; i < numeros;i++) {
        int x;
        cin >> x;
        if(x > gcd_temp) {
            gcd_temp = gcd(x,gcd_temp);
        }else {
            gcd_temp = gcd(gcd_temp,x);
        }
        
    }   
}