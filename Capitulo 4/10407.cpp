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
    vector<int> numbers;
    int number;
    while(cin>>number && number){
        numbers.push_back(number);
        while(cin>>number && number) {
            numbers.push_back(number);
        }
        sort(numbers.begin(),numbers.end());
        vector<int> a_b;
        for(int i = 1; i<numbers.size();i++) {
            int x = numbers[i] - numbers[i-1];
            a_b.push_back(x);
        }
        int gcd_result = a_b[0];
        for(int i = 1;i<a_b.size();i++) {
            gcd_result = gcd(gcd_result,a_b[i]);
        }
        cout<<gcd_result<<endl;
        numbers.clear();
    }
}