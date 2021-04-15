package Grafos;

import java.util.*;
import java.io.*;
class Ideone
{
	static Scanner read = new Scanner(System.in);
	public static void main (String[] args) throws java.lang.Exception
	{
		
		int nroVertices, nroAristas;
		nroVertices = read.nextInt();
		nroAristas = read.nextInt();
		ArrayList<ArrayList<Integer>> grafo = new ArrayList<ArrayList<Integer>>();
		for(int i = 0; i< nroVertices; i++) {
			grafo.add(new ArrayList<Integer>());
		}
		while( nroAristas > 0) {
			nroAristas--;
			int a,b; 
			a = read.nextInt();
			b = read.nextInt();
			grafo.get(a).add(b);
			grafo.get(b).add(a);
		}		
		for(int i = 0; i< nroVertices; i++) {
			System.out.println(grafo.get(i));
			// grafo.add(new ArrayList<Integer>());
		}
		
		int[] nivel = new int[nroVertices]; 
		int[] padres = new int[nroVertices];
		boolean[] visitados = new boolean[nroVertices];
		int inicio = 2, fin = 5;
		Queue<Integer> cola = new LinkedList<Integer>();
		cola.offer(inicio);
		visitados[inicio] = true;
		nivel[inicio] = 1;
		while(!cola.isEmpty()) {
			int actual = cola.poll();
			for(int i = 0;i< grafo.get(actual).size();i++) {
				int vecino = grafo.get(actual).get(i); 
				if(!visitados[vecino]) {
					cola.offer(vecino); 
					padres[vecino] = actual;
					visitados[vecino] = true;
					nivel[vecino] = nivel[actual] + 1;
				}
			}
		}
		for(int i = 0; i< nroVertices; i++) {
			System.out.print("["+padres[i]+"]");
			// grafo.add(new ArrayList<Integer>());
		}
		System.out.println();
		for(int i = 0; i< nroVertices; i++) {
			System.out.print("["+i+"]");
			// grafo.add(new ArrayList<Integer>());
		}
		System.out.println();
		
	}
}