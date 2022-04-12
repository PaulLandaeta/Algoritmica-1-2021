#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

int main() {
    input;
    int kids;
    cin >> kids;
    int instructions;
    cin >> instructions;
    stack<int> instructionsStack;
    for(int i = 0; i < instructions; i++) {
        string instruction;
        cin >> instruction;
        if(instruction == "undo") {
            int number; 
            cin >> number;
            while(number--) {
                instructionsStack.pop();
            }
        }
        else {
            int number = stoi(instruction); // String.parseInt("123"); -> 123
            // stoi Castear una cadena en entero
            instructionsStack.push(number);
        }
    }
    int total = 0;
    while(!instructionsStack.empty()) {
        total += instructionsStack.top();
        instructionsStack.pop();
    }
    if(total > 0) {
        cout<<total%kids<<endl;
    }else {
        cout<<kids - (total*-1)%kids<<endl;
    }
    return 0;
}