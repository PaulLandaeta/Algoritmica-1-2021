#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

int main(){
    //input;
    //output;
    int cases; 
    cin>>cases;
    int ncase = 1;
    while(cases--){
        int students;
        cin>>students;
        int middle = students/2;
        for(int i=0;i<students;i++){
          int ages;
          cin>>ages;
          if(i == middle){
              cout<<"Case "<<ncase<<": "<<ages<<endl;
              ncase++;
          }
        }
    }
    return 0; 
}