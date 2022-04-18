// Elaborar el algoritmo para la siguiente serie y calcular 
// la complejidad algoritmica 
// 2, 4, 6, 10, 16, 26,...... 

// si n = 1 imprime 2
// si n = 2 imprime 2, 4
// si n = 6 imprime 2, 4, 6, 10, 16, 26
#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

int main() {
    int n; //1
    cin>>n; // 1
    int firstNumber = 0; // 1
    int secondNumber = 2;//1
    for(int i=0;i<n;i++){ // n
        print(firstNumber+secondNumber); // 2
        int aux = firstNumber+secondNumber;//2
        firstNumber = secondNumber;// 1
        secondNumber = aux; //1
    }

    // T(n) = 4+6*n+1 = T(n) = 5+6n = O(n)= n;
    // 2, 4, 6, 10
    return 0;
}