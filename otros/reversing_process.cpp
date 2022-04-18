#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

map<int,int> code;
vector<int> counter(30);
int number;
string word;
void encode() {
    // 12 * 6015 % 26 = 4,    4  --> e
    for(int i = 'a' ; i <= 'z';i++) {
        int newNumber = ((i-'a')%26*number%26)%26;
        int oldNumber = i-'a';
        code[newNumber] = oldNumber;
        counter[newNumber]++;
    }
}

void splitCad(string cad){
    number = 0;
    word = "";
    for(int i=0;i<cad.size();i++) {
        if(isdigit(cad[i])) {
            number = number*10 + (cad[i]-'0');
        } 
        else{
            word += cad[i]; 
        }
    }
    
}

int main() {
    input;
    output;
    string cad;
    cin>>cad;
    splitCad(cad);
    cout<<number<<endl;
    cout<<word<<endl;
    encode();
    for(int i = 0; i<27;i++) {
        cout<<"["<<counter[i]<<"]";
    }
    return 0;
}