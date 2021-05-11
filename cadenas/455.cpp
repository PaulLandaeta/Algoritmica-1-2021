#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

string patron; // cadena del patron
int m;         // tamaño del patron
string texto;  // texto donde se buscara el patron
int n;          // tamaño del texto;

//TODO: verificar el tamaño de acuerdo al problema
vector<int> b(10000);
int fin;
void kmpProcess() {
    int i = 0, j = -1;
    b[0] = -1;
    while(i < m) {
        while((j>=0) && (patron[i] != patron[j])) {
            j = b[j];
        }
        i++; j++;
        /// crear el pequeño patron Ho * freq = n   2 * 3 = 6 = 6 imprimes  2 
        b[i] = j;
    }
}
int kmpSearch() {    
    fin = false;                          
  int freq = 0;                                     // contar cuantas veces se encuentra el patron dentro del texto
  int i = 0, j = 0;                              
  while (i < n) {                                
    while ((j >= 0) && (texto[i] != patron[j])) {
        j = b[j];                        
    }                                      
    ++i; ++j;                                    
    if (j == m) {                                
      ++freq;
      if(i == n) {
          fin = true;
      }
      //printf("P is found at index %d in T\n", i-j);
      j = b[j];                                  
    }
  }
  return freq;
}
int main() {
    input; 
    output;
    int cases; 
    cin>>cases; 
    while(cases--) {
        cin>>texto;
        patron = texto[0];
        n = texto.size();
        m = patron.size();
        kmpProcess();
        int freq = kmpSearch();
        if(freq * m == n && fin) {
            cout<<m<<endl;
        }else {
            for(int i = 1; i<n;i++) {
                patron+=texto[i];
                m = patron.size();
                kmpProcess();
                freq = kmpSearch();
                if(freq * m == n && fin) {
                    cout<<m<<endl;
                    break;
                }
            }
        }
        if(cases!=0)
            cout<<endl;
    }
}