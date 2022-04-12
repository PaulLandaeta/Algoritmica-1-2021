#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

int main() {
input;
  int n;
  cin>>n;
  stack<int> pilita;
  int number;
  cin>>number;
  pilita.push(number);
  for(int i=1;i<n;i++) {
      cin>>number;
      if(!pilita.empty()){
          if((pilita.top() + number)%2==0) {
              pilita.pop();
          }
          else {
              pilita.push(number);
          }
      } else{
            pilita.push(number);
      }
  }
  cout<<pilita.size()<<endl;
}