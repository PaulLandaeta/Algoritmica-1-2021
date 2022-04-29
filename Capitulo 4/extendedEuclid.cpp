#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
// TAREA ITERATIVO 
int gcd_extended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int temp1,temp2; // temp1 -> x  temp2 -> y 
    int gcd = gcd_extended(b%a, a, &temp1, &temp2); 
    *x = temp2 -  (b/a)*temp1;
    *y = temp1;

    return gcd;
}

int main() {
    input;
    // output;
    int a,b;
    cin>>a>>b;
    int x,y;
    int z = gcd_extended( a, b, &x, &y);    

    cout<<a<<"x + "<<b<<"y = gcd("<<a<<","<<b<<")" <<endl;
    cout<<"x = "<< x<<endl;
    cout<<"y = "<< y<<endl;
}