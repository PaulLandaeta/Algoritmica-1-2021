#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

void printMenu() {
    cout<<"====================================================="<<endl;
    cout<<"1. Ejecutar el Primer Ejemplo"<<endl;
    cout<<"2. Ejecutar el Segundo Ejemplo"<<endl;
    cout<<"3. Ejecutar el Tercer Ejemplo"<<endl;
    cout<<"4. Ejecutar el Cuarto Ejemplo"<<endl;
    cout<<"5. Ejecutar el Tu propio Ejemplo"<<endl;
    cout<<"X. Salir del programa"<<endl;
    cout<<"====================================================="<<endl;
}

void ejemplo1() {
    cout<<"Imprimiendo el Primer Ejemplo"<<endl;
}

void ejemplo2() {
    cout<<"Imprimiendo el Segundo Ejemplo"<<endl;
}
void ejemplo3() {
    cout<<"Imprimiendo el Tercer Ejemplo"<<endl;
}
void ejemplo4() {
    cout<<"Imprimiendo el Cuarto Ejemplo"<<endl;
}
void ejemploPropio() {
    cout<<"Imprimiendo el propio Ejemplo"<<endl;
}
void salir() {
    cout<<"Saliendo del Programa"<<endl;
}

int main() {
    input;
    int option; 
    cin>>option;
    printMenu();
    do{
        switch(option) {
        case 1:
            ejemplo1();
            break;
        case 2:
            ejemplo2();
            break;
        case 3:
            ejemplo3();
            break;
        case 4:
            ejemplo4();
            break;
        case 5:
            ejemploPropio();
            break;
        default:
            cout<<"No existe esa opcion"<<endl;
        }
        printMenu();
    }while(cin>>option && option);
    salir();

}