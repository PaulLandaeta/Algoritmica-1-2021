#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

int main() {
    string parentesis; 
    // cin >> parentesis;
    parentesis = "]]][[[";
    stack<char> pila;
    for(int i=0 ;i< parentesis.size() ;i++){
        if(parentesis[i] == ']' || parentesis[i] == '}' || parentesis[i] == ')'){
            if(pila.empty()){
                cout << "NO" << endl;
                return 0;
            }
            if((parentesis[i] == ']' && pila.top() == '[') || (parentesis[i] == '}' && pila.top() == '{') || (parentesis[i] == ')' && pila.top() == '(')){
                pila.pop();
            }
            else{
                cout << "NO" << endl;
                return 0;
            }
        }
        else {
            pila.push(parentesis[i]);
        }
    }
    if(pila.empty()){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}

