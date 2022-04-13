#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std;

int main() {
    input;
    int N; 
    cin>>N;
    vector<int> v(N);
    for(int i=0;i<N;i++)
        cin>>v[i];
    for(int i = 1; i<N; i++){
        int j = i-1;
        while(j>=0 && v[j]>=v[i]){
            j--;
        }
        if(j==-1){
            cout<<j<<" ";
        }
        else{
            cout<<v[j]<<" ";
        }
            
    }
    return 0;
}