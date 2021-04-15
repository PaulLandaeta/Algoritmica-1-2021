
import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    static Scanner read = new Scanner(System.in);
    public static void main (String[] args) throws java.lang.Exception
	{
        while(read.hasNext()) {
            String containers = read.nextLine();
            if(containers.equals("end"))
                break;
            ArrayList< Stack<Character> > pilas = new ArrayList<Stack<Character> >();            
            Stack<Character> pilaActual = new Stack<Character>();
            pilaActual.push(containers.charAt(0));
            pilas.add(pilaActual); 
            for(int i = 1; i < containers.length(); i++) {
                boolean fueAgregado = false;
                for(int j = 0; j < pilas.size(); i++) {
                    pilaActual = pilas.get(j);
                    if(containers.charAt(i) <= pilaActual.firstElement()) {
                        pilas.get(j).push(containers.charAt(i)); 
                        fueAgregado = true;
                        break;
                    }
                }
                if(!fueAgregado) {
                    Stack<Character> nuevaPila = new Stack<Character>();
                    nuevaPila.push(containers.charAt(i));
                    pilas.add(nuevaPila);
                }
            }
            System.out.println(pilas.size());
        }
    }
}
