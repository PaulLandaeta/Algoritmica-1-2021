// Factorial de forma recursiva

int factorial(int n){
    if(n == 1 || n == 0) { // Caso Base
        return 1;   // K
    }
    else {
        return n*factorial(n-1);
    }
        
}