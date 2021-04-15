package Grafos;

import java.util.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class GrafoLista
{
	static Scanner read = new Scanner(System.in);
	public static void main (String[] args) throws java.lang.Exception
	{
		int nroVertices, nroAristas; 
		
		nroVertices = read.nextInt();
		nroAristas = read.nextInt();
		
        ArrayList<ArrayList<Integer> > grafo = new ArrayList< ArrayList<Integer> >();
        for(int i = 0; i < nroVertices; i++) {
            ArrayList<Integer> aristaList = new ArrayList<Integer>();
            grafo.add(aristaList);
        }

        for(int i = 0 ;i < nroAristas ; i++) {
            int inicio, fin; 
            inicio = read.nextInt();
            fin = read.nextInt();
            // Grafo Dirigido
            grafo.get(inicio).add(fin);
            // Grafo noDirigido 
            grafo.get(fin).add(inicio);
        }
        
        for(int i = 0 ; i < nroVertices; i++) {
            System.out.println("["+i+"]");
            System.out.print(grafo.get(i));
            /*for(int j = 0; j < ; j++) {
                
            }*/
        }


	}
}

/* 
Input 
4 3
0 1 
1 2
2 3
*/
/*
Output 

*/