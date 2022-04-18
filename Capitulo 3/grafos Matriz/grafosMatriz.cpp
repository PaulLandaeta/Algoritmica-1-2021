#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 


int main(){
 input; // Porque los casos de ejemplo son mas grandes
 int vertices,aristas;
 cin>>vertices>>aristas;
 int grafoMatriz[vertices][vertices];
 // memset setea todos los valores de un array en 0, -1 o 1
 // OJO siempre usaremos memset
 memset(grafoMatriz,0,sizeof(grafoMatriz));
 for(int i = 0;i<aristas;i++) {
  int a,b;
  cin>>a>>b; // Leemos las aristas del grafo
  grafoMatriz[a][b] = 1;
  // Si el grafo es dirigido comentar la linea de abajo
  grafoMatriz[b][a] = 1;
 }
 // Mostramos el Grafo
 for(int i = 0;i<vertices;i++) {
  for(int j = 0;j<vertices;j++) {
   cout<<"["<<grafoMatriz[i][j]<<"]";
  }
  cout<<endl;
 }

 return 0;   
}