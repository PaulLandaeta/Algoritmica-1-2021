#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

string patron; // cadena del patron
int m;         // tamaño del patron
string texto;  // texto donde se buscara el patron
int n;          // tamaño del texto;

//TODO: verificar el tamaño de acuerdo al problema
vector<int> b(250005);

void kmpProcess() {
    int i = 0, j = -1;
    b[0] = -1;
    while(i < m) {
        while((j>=0) && (patron[i] != patron[j])) {
            j = b[j];
        }
        i++; j++;
        b[i] = j;
    }


    // for(int i = 0 ; i< m; i++) {
    //    cout<<"["<<b[i]<<"]";
    //}
    // cout<<endl;
}

int kmpSearch() {                               
  int i = 0, j = 0;                              
  while (i < n) {                                
    while ((j >= 0) && (texto[i] != patron[j])) {
        j = b[j];                        
    }                                      
    ++i; ++j;                                    
    if (j == m) {                                
      // printf("P is found at index %d in T\n", i-j);
      if(i == m) 
        return 0;
      return n-i; 
    }
  }
  return -1;
}


int main() {
    // input; 
    //output;
    cin>>n;
    cin>>texto;
    texto +=texto;
    n *=2;
    cin>>patron;
    m = patron.size();
    kmpProcess();
    cout<<kmpSearch()<<endl;
}