#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

int main() {
    // input;
    int n; 
    cin >> n;
    int sock;
    stack<int> firstStack;
    stack<int> auxStack;
    int result = 0; 
    for(int i = 0; i < 2*n ; i++) {
        cin>>sock;
        firstStack.push(sock);
    }
    while(!firstStack.empty()) {
      if(!auxStack.empty()) {
        if(firstStack.top() ==  auxStack.top()) {
          firstStack.pop();
          auxStack.pop();
          result++;
        }
        else {
            result++;
            auxStack.push(firstStack.top());
            firstStack.pop();    
        }
      }
      else {
        result++;
        auxStack.push(firstStack.top());
        firstStack.pop();
      }
    }
    if(auxStack.empty() && firstStack.empty()) {
        cout<<result<<endl;
    } else {
        cout<<"impossible"<<endl;
    }
    

    return 0; 
}