#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

int[] bubbleSort(int arr[]){ // recibiendo un array
    int numbers = arr.length; // obteniendo el tamaño del array
    for(int p1 = 0; p1 < n-1; p1++) {
        for(int p2 = p1+1; p2 < n; p2++) {
            if(arr[p1] > arr[p2]) {
                int temp = arr[p1];
                arr[p1] = arr[p2];
                arr[p2] = temp;
            }
        }
    }
    return arr;
}







int main() {
    return 0;
}