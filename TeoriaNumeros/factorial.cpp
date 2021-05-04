#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

int factorial(int number, int x) {
    int result = 1;
    while(number>0) {
        result = (number%x * result%x)%x;
        number--;
    }
    return result;
}

int factorial(int number,int x) {
    if(number == 0) {
        return 1;
    }
    return ((number%x) *(factorial(number-1,x)%x)%x);
}


int main() {
    input;
    output;
    int n,m,x; 
    cin>>n>>m>>x;
    cout<<(factorial(n,x)/factorial(m,x))%x<<endl;
    
}