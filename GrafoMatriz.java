
import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
	static Scanner read = new Scanner(System.in);
	public static void main (String[] args) throws java.lang.Exception
	{
		int nroVertices, nroAristas; 
		
		nroVertices = read.nextInt();
		nroAristas = read.nextInt();

		int[][] grafo = new int[nroVertices][nroVertices];

		for(int i = 0; i < nroAristas; i++) {
			int inicio, fin; 
			inicio = read.nextInt();
			fin = read.nextInt();
			// grafo dirigido 
			grafo[inicio][fin] = 1;
			// grafo no dirigido 
			grafo[fin][inicio] = 1;
		}

		for(int i = 0; i < nroVertices ; i++ ) {
			for(int j = 0; j < nroVertices ; j++ ) {
				System.out.print("["+grafo[i][j]+"]");				
			}
			System.out.println();
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
[0][1][0][0]
[1][0][1][0]
[0][1][0][1]
[0][0][1][0]
*/