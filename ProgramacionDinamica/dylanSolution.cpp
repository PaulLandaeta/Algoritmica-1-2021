#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;


int cantObjetos[25];
int Total = 0;
vector<int> peso = {25, 15, 8, 7, 5};
vector<int> ganancia = {29, 20, 75, 50, 10};

void contarMonedas(){
    int pesoActual = peso.back();
    peso.pop_back();
    int gananciaActual = ganancia.back();
    ganancia.pop_back();
    for(int i = Total; i >= pesoActual; i--){        
         cantObjetos[i] = max(cantObjetos[i], cantObjetos[i-pesoActual]+gananciaActual);
    }
    
    for(int x: cantObjetos){
        cout << "[" << x << "]";
    }
    cout << endl;
    if(peso.size() != 0){
        contarMonedas();
    }
    
}
int main(){
    /*
    cin >> Total;
    int temp = 0;
    while (cin >> temp && temp != 0){
        objetosNoOrdenados.push_back(temp);
    }
    */
    Total = 12;
    for(int i = 0; i < Total; i++){
        cantObjetos[i] = 0;
    }
    contarMonedas();
    cout << cantObjetos[Total] << endl;
}