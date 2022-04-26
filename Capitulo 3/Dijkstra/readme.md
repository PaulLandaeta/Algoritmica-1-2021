# ¡Encontrando el camino más corto, con un poco de ayuda de Dijkstra!

![¡Encontrando el camino más corto, con un poco de ayuda de Dijkstra!](https://miro.medium.com/max/1400/1*49LYe8afsfWMxhagLTr9AQ.jpeg)


Si pasas suficiente tiempo leyendo sobre programación o informática, es muy probable que te encuentres con las mismas ideas, términos, conceptos y nombres, una y otra vez. Algunos de ellos empiezan a ser más familiares con el tiempo. De forma natural, orgánica, y a veces sin demasiado esfuerzo por tu parte, empiezas a aprender lo que significan todas estas cosas. Esto sucede porque, o bien has empezado a captar lentamente el concepto, o bien has leído sobre una frase las suficientes veces como para empezar a entender realmente su significado.

Sin embargo, hay algunas ideas y definiciones que son mucho más difíciles de entender. Estas son las que sientes que debes conocer, pero no te has topado con ellas lo suficiente como para comprenderlas realmente.

Los temas que creemos que debemos conocer, pero que nunca llegamos a aprender, son los más intimidantes de todos. La barrera de entrada es muy alta, y puede parecer imposible entender algo para lo que se tiene poco o ningún contexto. Para mí, ese tema intimidante es el algoritmo de Dijkstra. Siempre esuchaba como lo mencionaban de pasada, pero nunca lo había visto, así que nunca tuve el contexto ni las herramientas para intentar entenderlo.

Afortunadamente, en el transcurso de la redacción de esta serie, todo eso ha cambiado. Después de años de miedo y ansiedad por el algoritmo de Dijkstra, finalmente he llegado a entenderlo. Y espero que, al final de este post, tú también lo hagas.

## Gráfos que pesan en la mente

Antes de que podamos adentrarnos realmente en el superfamoso algoritmo de Dijkstra, tenemos que recoger primero algunas semillas de información importante que necesitaremos en el camino.

A lo largo de esta serie, hemos ido construyendo poco a poco nuestra base de conocimientos sobre diferentes estructuras de datos. No sólo hemos aprendido sobre varios algoritmos de recorrido de grafos, sino que también hemos aprendido los fundamentos de la teoría de grafos, así como los aspectos prácticos de la representación de grafos en nuestro código. Ya sabemos que los grafos pueden ser dirigidos o no dirigidos, e incluso pueden contener ciclos. También hemos aprendido cómo podemos utilizar la búsqueda de amplitud (**BFS**) y la búsqueda de profundidad (**DFS**) para recorrerlos, utilizando dos estrategias muy diferentes.

En nuestro viaje para entender los grafos y los diferentes tipos de estructuras de grafos que existen, hay un tipo de grafo que nos hemos saltado, hasta ahora. Es hora de que nos enfrentemos por fin al grafo ponderado.

![Gráfico ponderado: una definición](https://miro.medium.com/max/1400/1*McOYSTKvabPuag2XZzw6_g.jpeg)
> Un grafo ponderado es un grafo cuyas aristas tienen asociado algún valor, los cuales también se llaman **pesos**.


Un grafo ponderado es interesante porque no tiene mucho que ver con si el grafo es dirigido, no dirigido o contiene ciclos. En esencia, un grafo ponderado es un grafo cuyas aristas tienen algún tipo de valor asociado. El valor que se asigna a una arista es lo que le da su "peso".

![El peso de una arista representa el coste o la distancia entre dos nodos.](https://miro.medium.com/max/1400/1*bsmfwBs6adgzZao_3QNdgw.jpeg)
Una forma común de referirse al "peso" de una arista es pensar en ella como el coste o la distancia entre dos nodos. En otras palabras, ir del nodo a al nodo b tiene algún tipo de coste.

O, si pensamos en los nodos como si fueran ubicaciones en un mapa, entonces el peso podría ser la distancia entre los nodos **a** y **b**. Siguiendo con la metáfora del mapa, el "peso" de una arista también puede representar la capacidad de lo que se puede transportar, o lo que se puede mover entre dos nodos, **a** y **b**.

Por ejemplo, en el ejemplo anterior, podríamos determinar que el coste, la distancia o la capacidad entre los nodos **c** y **b** tiene un peso de 8.

![Podemos representar los grafos ponderados mediante una lista de adyacencia.](https://miro.medium.com/max/1400/1*puMy8EU5aCj4mv960M8v_Q.jpeg)

La ponderación de las aristas es lo único que diferencia a los grafos ponderados de los no ponderados con los que hemos trabajado hasta ahora en esta serie.
De hecho, probablemente ya podemos imaginar cómo representaríamos uno de estos grafos ponderados. Un grafo ponderado se puede representar con una lista de adyacencia, con una propiedad añadida: un campo para almacenar el coste/peso/distancia de cada arista del grafo. Basándonos en nuestra investigación anterior sobre la representación de grafos, recordaremos que las aristas de un grafo en una **lista de adyacencia** viven en la parte de la "lista".
Para cada arista de nuestro grafo, modificaremos la definición de la lista enlazada que contiene las aristas de modo que cada elemento de la lista enlazada pueda contener dos valores, en lugar de uno solo. Estos dos valores serán el índice del nodo opuesto, que es como sabemos dónde se conecta esta arista, así como el peso que se asocia con la arista.


Este es el aspecto de ese mismo ejemplo de grafo ponderado en formato de lista de adyacencia.

![Gráfico ponderado como una lista de adyacencia.](https://miro.medium.com/max/1400/1*c1myQEwNTF8crkwIEmnAsg.jpeg)

En primer lugar, dado que se trata de un grafo no dirigido, la arista entre los nodos **a** y **b** aparecerá dos veces: una en la lista de aristas del nodo a y otra en la lista de aristas del nodo b. En segundo lugar, en los dos casos en que esta arista está representada en la lista de aristas de cualquiera de los nodos, hay un coste/peso que se almacena en el elemento de la lista enlazada que contiene la referencia al nodo vecino (en este caso, **a** o **b**).
De acuerdo, no hay nada demasiado descabellado que tengamos que entender todavía, ¿verdad?
Aquí es donde el peso de un gráfico empieza a complicar las cosas ligeramente:
> encontrar el camino más corto entre dos nodos se vuelve mucho más complicado cuando tenemos que tener en cuenta los pesos de las aristas que atravesamos.

Veamos un ejemplo y esto empezará a quedar más claro. En el siguiente grafo dirigido y ponderado, tenemos un grafo con tres nodos (**a**, **b** y **c**), con tres aristas dirigidas y ponderadas.

![¿Cuál es el camino más corto entre los nodos A y B?](https://miro.medium.com/max/1400/1*PUQiFFYPVIkdbjBFH3o2RA.jpeg)
Observando este grafo, podríamos determinar rápidamente -sin dudarlo mucho- el camino más rápido para ir del nodo **a** al nodo **b**. Hay una arista entre **a** y **b**, así que ése debe ser el camino más rápido, ¿no?
Pues no exactamente. Teniendo en cuenta los pesos de estas aristas, echemos un segundo vistazo más profundo. Si tomamos la ruta del nodo **a** al nodo **b**, nos "costará" 5. Sin embargo, si tomamos la ruta del nodo **a** al nodo **c** al nodo **b**, entonces nos costará sólo 3.
Pero, ¿por qué 3? Bueno, aunque intuitivamente parezca un camino más largo, si sumamos las aristas de ir del nodo **a** al **c** y luego del nodo **c** al **b**, veremos que el coste total acaba siendo 2 + 1, es decir, 3. Puede que signifique que estamos viajando a través de dos aristas, ¡pero un coste de 3 es ciertamente preferible a un coste de 5!
En nuestro grafo de ejemplo de tres nodos, podríamos ver fácilmente las dos rutas posibles entre nuestros nodos de origen y destino. Sin embargo, ¿qué pasaría si nuestro grafo fuera mucho más grande, digamos veinte nodos? No nos resultaría tan fácil encontrar el camino más corto, teniendo en cuenta los pesos de nuestro grafo ponderado. ¿Y si estuviéramos hablando de un grafo aún más grande? De hecho, la mayoría de los grafos que tratamos son mucho más grandes que veinte nodos. ¿Hasta qué punto sería factible, escalable y eficiente utilizar un enfoque de fuerza bruta para resolver este problema?
La respuesta es que no es tan factible. Y tampoco es divertido. Y ahí es donde Dijkstra viene al rescate.


## Reglas del juego de Dijkstra
El algoritmo de Dijkstra es único por muchas razones, que pronto veremos cuando empecemos a entender cómo funciona. Pero la que siempre nos ha sorprendido un poco es el hecho de que este algoritmo no sólo se utiliza para encontrar el camino más corto entre dos nodos concretos de una estructura de datos de un gráfico. **El algoritmo de Dijkstra puede utilizarse para determinar el camino más corto desde un nodo de un grafo hasta cualquier otro nodo de la misma estructura de datos del grafo, siempre que los nodos sean alcanzables desde el nodo de partida.**

![El algoritmo de Dijkstra puede utilizarse para encontrar el camino más corto.](https://miro.medium.com/max/1400/1*lGU6Eh6s7RL23_LZlzb5yg.jpeg)
Este algoritmo continuará ejecutándose hasta que se hayan visitado todos los vértices alcanzables de un gráfico, lo que significa que podríamos ejecutar el algoritmo de Dijkstra, encontrar el camino más corto entre dos nodos alcanzables cualesquiera, y luego guardar los resultados en algún lugar. Una vez que ejecutamos el algoritmo de Dijkstra una sola vez, podemos consultar los resultados de nuestro algoritmo una y otra vez, ¡sin tener que ejecutar el propio algoritmo! La única vez que tendríamos que volver a ejecutar el algoritmo de Dijkstra es si algo de nuestra estructura de datos del grafo cambiara, en cuyo caso tendríamos que volver a ejecutar el algoritmo para asegurarnos de que seguimos teniendo los caminos más cortos más actualizados para nuestra estructura de datos particular.
Entonces, ¿cómo funciona realmente el algoritmo de Dijkstra? Es hora de averiguarlo por fin.

![Hay muchos caminos posibles entre el nodo A y el nodo E.](https://miro.medium.com/max/1400/1*DcCsQRtkOCusXQFodZ7IhA.jpeg)
Consideremos el grafo ponderado y no dirigido de arriba. Digamos que queremos encontrar el camino más corto desde el nodo a hasta el nodo e. Sabemos que vamos a empezar en el nodo a, pero no sabemos si hay un camino para llegar a él, ¡o si hay muchos caminos para llegar a él! En cualquier caso, no sabemos qué camino será el más corto para llegar al nodo e, si es que ese camino existe.
El algoritmo de Dijkstra requiere un poco de configuración inicial. Pero, antes de llegar a eso, echemos un vistazo rápido a los pasos y reglas para ejecutar el algoritmo de Dijkstra. En nuestro gráfico de ejemplo, comenzaremos con el nodo a como nodo inicial. Sin embargo, las reglas para ejecutar el algoritmo de Dijkstra se pueden abstraer para que se puedan aplicar a cada uno de los nodos que recorreremos y visitaremos en un esfuerzo por encontrar el camino más corto.

![Pasos y reglas para ejecutar el algoritmo de Dijkstra.](https://miro.medium.com/max/1400/1*XLP7wmt3mCdb-d0fS0VTbQ.jpeg)
Las reglas abstractas son las siguientes:

1. Cada vez que nos dispongamos a visitar un nuevo nodo, elegiremos el nodo con la menor distancia/coste conocido para visitarlo primero.
 
2. Una vez que nos hemos desplazado al nodo que vamos a visitar, comprobaremos cada uno de sus nodos vecinos.

3. Para cada nodo vecino, calcularemos la distancia/coste de los nodos vecinos sumando el coste de las aristas que llevan al nodo que estamos comprobando desde el vértice inicial.

4. Por último, si la distancia/coste a un nodo es menor que una distancia conocida, actualizaremos la distancia más corta que tenemos archivada para ese vértice.

Estas instrucciones son nuestras reglas de oro que siempre seguiremos, hasta que nuestro algoritmo termine de ejecutarse. Así que, ¡manos a la obra!

Lo primero es lo primero: tenemos que inicializar algunas cosas para hacer un seguimiento de cierta información importante mientras se ejecuta este algoritmo.

![Algoritmo de Dijkstra, parte 1](https://miro.medium.com/max/1400/1*nXlEmHAnu3dVBOnJAfPaAg.jpeg)
Crearemos una tabla para llevar la cuenta de la distancia más corta conocida a cada vértice de nuestro grafo. También llevaremos la cuenta del vértice anterior del que venimos, antes de "comprobar" el vértice que estamos viendo actualmente.
Una vez que tengamos nuestra tabla preparada, tendremos que darle algunos valores. Cuando empezamos el algoritmo de Dijkstra, ¡no sabemos nada en absoluto! Ni siquiera sabemos si todos los demás vértices que hemos enumerado (**b**, **c**, **d** y **e**) son alcanzables desde nuestro nodo inicial a.
Esto significa que, cuando empezamos inicialmente, el "camino más corto desde el nodo **a**" va a ser infinito (**∞**). Sin embargo, cuando empezamos, conocemos el camino más corto para un nodo, y un solo nodo: por qué, el nodo a, nuestro nodo de partida, por supuesto. Como empezamos en el nodo a, ya estamos allí para empezar. ¡Por lo tanto, la distancia más corta del nodo a al nodo a es en realidad sólo 0!
Ahora que hemos inicializado nuestra tabla, necesitaremos otra cosa antes de poder ejecutar este algoritmo: ¡una forma de llevar la cuenta de los nodos que hemos visitado o no! Podemos hacerlo de forma bastante sencilla con dos estructuras de array: un array de visitados y un array de no visitados.

![Algoritmo de Dijkstra: preparando las cosas.](https://miro.medium.com/max/1400/1*4uv6Kq3hga8RLSUQWpQLAQ.jpeg)
Cuando empezamos, aún no hemos visitado ningún nodo, así que todos nuestros nodos viven dentro de nuestro array de no visitados.

![Algoritmo de Dijkstra, parte 2](https://miro.medium.com/max/1400/1*1lrE19y01X5a16cfz8tXBA.jpeg)
Bien, ¡ahora estamos en buena forma! Empecemos. ¿Recuerdas nuestras cuatro reglas de antes? Vamos a seguirlas, paso a paso, mientras recorremos cada vértice de este grafo.
Primero, visitaremos el vértice con el menor coste/distancia conocido. Podemos mirar la columna que nos dice la distancia más corta desde **a**. Ahora mismo, todos los vértices tienen una distancia infinita (**∞**), ¡excepto el propio **a**! Así que visitaremos el nodo **a**.
A continuación, examinaremos sus nodos vecinos, y calcularemos la distancia a ellos desde el vértice que estamos mirando actualmente (que es **a**). La distancia al nodo **b** es el coste de **a** más el coste de llegar al nodo **b**: en este caso, 7. Del mismo modo, la distancia al nodo **c** es el coste de a más el coste de llegar al nodo **c**: en este caso, 3.
Por último, si la distancia calculada es menor que la distancia más corta que conocemos actualmente para estos nodos vecinos, actualizaremos los valores de nuestras tablas con nuestra nueva "distancia más corta". Bien, actualmente, nuestra tabla dice que la distancia más corta de **a** a **b** es **∞**, y lo mismo ocurre con la distancia más corta de **a** a **c**. Como 7 es menor que el infinito, y 3 es menor que el infinito, actualizaremos la distancia más corta del nodo **b** a 7, y la distancia más corta del nodo **c** a 3. También necesitaremos actualizar el vértice anterior de **b** y **c**, ¡ya que necesitamos mantener un registro de dónde venimos para obtener estas rutas! Actualizaremos el vértice anterior de **b** y **c** a **a**, ya que es de donde venimos.

Ahora, hemos terminado de comprobar los vecinos del nodo **a**, lo que significa que podemos marcarlo como visitado. Pasamos al siguiente nodo.

![Algoritmo de Dijkstra, parte 3](https://miro.medium.com/max/1400/1*7eo3aWZUtCdbUH3lHMxEIQ.jpeg)

Una vez más, nos fijaremos en el nodo con el menor coste que aún no ha sido visitado. En este caso, el nodo **c** tiene un coste de 3, que es el menor coste de todos los nodos no visitados. Por lo tanto, el nodo **c** se convierte en nuestro vértice actual.

Vamos a repetir el mismo procedimiento que antes: comprobar los vecinos no visitados del nodo **c** y calcular sus caminos más cortos desde nuestro nodo de origen, el nodo **a**. Los dos vecinos del nodo **c** que aún no han sido visitados son el nodo **b** y el nodo **d**. La distancia al nodo **b** es el coste de **a** más el coste de ir del nodo **c** a **b**: en este caso, 4. La distancia al nodo **d** es el coste de **a** más el coste de ir del nodo **c** a **d**: en este caso, 5.
Ahora, comparemos estas dos "distancias más cortas" con los valores que tenemos en nuestra tabla. En este momento, la distancia a **d** es infinita, por lo que ciertamente hemos encontrado un camino de coste más corto aquí, con un valor de 5. ¿Pero qué pasa con la distancia al nodo **b**? Bueno, la distancia al nodo **b** está actualmente marcada como 7 en nuestra tabla. Pero hemos encontrado un camino más corto a **b**, que pasa por **c**, y tiene un coste de sólo 4. Así que actualizaremos nuestra tabla con nuestros caminos más cortos.
También tendremos que añadir el vértice **c** como vértice anterior del nodo **d**. Fíjate en que el nodo **b** ya tiene un vértice anterior, ya que hemos encontrado un camino antes, que ahora sabemos que no es realmente el más corto. No te preocupes, simplemente tacharemos el vértice anterior del nodo b y lo sustituiremos por el vértice que, como sabemos ahora, tiene el camino más corto: el nodo **c**.

![Algoritmo de Dijkstra, parte 4](https://miro.medium.com/max/1400/1*K3yWhgjshcexOQMh_LTWDg.jpeg)
Muy bien, ahora hemos visitado tanto el nodo **a** como el **c**. Entonces, ¿qué nodo visitamos a continuación?
De nuevo, visitaremos el nodo que tenga el menor coste; en este caso, parece ser el nodo **b**, con un coste de 4.
Comprobaremos su vecino no visitado (sólo tiene uno, el nodo **e**), y calcularemos la distancia a **e**, desde el nodo origen, a través de nuestro vértice actual, **b**.
Si sumamos el coste de **b**, que es 4, con el coste que supone ir de **b** a **e**, veremos que nos cuesta 6. Por lo tanto, terminamos con un coste total de 10 como la distancia más corta conocida a **e**, desde el vértice inicial, a través de nuestro nodo actual.

![Pero, ¿cómo hemos llegado a ese número?](https://miro.medium.com/max/1400/1*Xg1OVLT9sXnP_AsYngXnAg.jpeg)

Pero, ¿cómo hemos llegado a ese número? Puede parecer confuso al principio, pero podemos dividirlo en partes. Recuerda que, independientemente del vértice en el que nos fijemos, siempre queremos sumar la distancia más corta conocida desde nuestro inicio hasta el vértice actual. En términos más simples, vamos a mirar el valor de la "distancia más corta" en nuestra tabla, que nos dará, en este ejemplo, el valor 4. Luego, miraremos el coste desde nuestro vértice actual hasta el vecino que estamos examinando. En este caso, el coste de **b** a **e** es 6, así que lo sumaremos a 4.
Así, 6 + 4 = 10 es nuestra distancia más corta conocida al nodo e desde nuestro vértice inicial.

## Detras de escenas de la magia de Dijkstra
Seguiremos haciendo los mismos pasos para cada vértice que quede sin visitar. El siguiente nodo que comprobaríamos en este grafo sería **d**, ya que tiene la distancia más corta de los nodos no visitados. Sólo uno de los vecinos del nodo **d** está sin visitar, que es el nodo **e**, por lo que es el único que tendremos que examinar.

![Algoritmo de Dijkstra, parte 5](https://miro.medium.com/max/1400/1*aJfwaqVN6vKvObqFDLE0ig.jpeg)

Cuando sumamos la distancia del nodo **d** y el coste para llegar del nodo **d** al **e**, veremos que acabamos con un valor de 9, que es menor que 10, el camino más corto actual al nodo **e**. Actualizaremos nuestro valor del camino más corto y el valor del vértice anterior para el nodo **e** en nuestra tabla.

![Algoritmo de Dijkstra, parte 6](https://miro.medium.com/max/1400/1*Xfpj5ABWEnTs4JSqjQ7GNw.jpeg)
Finalmente, sólo nos queda un nodo por visitar: el nodo **e**.
Sin embargo, es bastante obvio que no hay nada que hacer aquí. No es necesario examinar ninguno de los vecinos del nodo **e**, ya que todos los demás vértices ya han sido visitados.
Todo lo que tenemos que hacer es marcar el nodo **e** como visitado. Ahora ya hemos terminado de ejecutar el algoritmo de Dijkstra en este grafo.
Hemos tachado mucha información a lo largo del camino, ya que hemos actualizado y cambiado los valores de nuestra tabla. Veamos una versión más bonita y limpia de esta tabla, con sólo los resultados finales de este algoritmo.

![Los valores finales del algoritmo de Dijkstra.](https://miro.medium.com/max/1400/1*5aDxt3Hi1jrhx-sy9JvKkA.jpeg)
Si miramos esta tabla, puede que no sea del todo obvio, pero en realidad tenemos todos los caminos más cortos que parten de nuestro nodo inicial a disponibles aquí, al alcance de la mano. Recordemos que antes aprendimos que el algoritmo de Dijkstra puede ejecutarse una vez y podemos reutilizar todos los valores una y otra vez, siempre que nuestro gráfico no cambie. Así es exactamente como esa característica se vuelve muy poderosa. Empezamos queriendo encontrar el camino más corto de **a** a **e**. Pero, ¡esta tabla nos permitirá buscar todos los caminos más cortos!

![Volviendo sobre nuestros pasos para encontrar el camino más corto.](https://miro.medium.com/max/1400/1*mbzCf5z7_6ajsOC7BfxsXg.jpeg)
La forma de buscar cualquier camino más corto en esta tabla es volviendo sobre nuestros pasos y siguiendo el "vértice anterior" de cualquier nodo, hasta el nodo inicial.
Por ejemplo, digamos que de repente decidimos que queremos encontrar el camino más corto de **a** a **d**. No hace falta volver a ejecutar el algoritmo de Dijkstra: ¡ya tenemos toda la información que necesitamos, justo aquí!
Usando una estructura de datos de pila, empezaremos con el nodo **d**, y lo empujaremos "push()" a nuestra pila. A continuación, miraremos el vértice anterior del nodo **d**, que resulta ser el nodo **b**. Empujaremos "push()" el nodo **b** a la pila. Del mismo modo, miraremos el vértice anterior del nodo **b** (nodo **c**), y lo añadiremos a nuestra pila, y luego miraremos el vértice anterior del nodo **c**, que es el nodo **a**, ¡nuestro vértice inicial!
Una vez que trazamos nuestros pasos hasta nuestro vértice inicial, removemos cada vertice de la pila "pop()", lo que resulta en este orden: **a** - **c** - **b** - **d**. Resulta que este es el camino exacto que nos dará el menor coste/distancia desde el nodo a hasta el nodo **d**. Muy bueno, ¿verdad?

![Algoritmo de Dijkstra visualizado, © Wikimedia Foundation](https://miro.medium.com/max/420/1*2jRCHqAbTCY7W7oG5ntMOQ.gif)
En muchos sentidos, el algoritmo de Dijkstra es una versión sofisticada de la forma típica de recorrer el grafo primero en amplitud con la que ya estamos familiarizados. Las principales diferencias son el hecho de que es un poco más inteligente y puede manejar muy bien los grafos ponderados. Pero, si observamos el algoritmo de Dijkstra visualizado, como la animación que se muestra aquí, veremos que básicamente funciona como una búsqueda BFS, extendiéndose a lo ancho en lugar de perseguir un camino específico en profundidad.
El ejemplo más común del algoritmo de Dijkstra en la naturaleza es en los problemas de búsqueda de caminos, como determinar direcciones o encontrar una ruta en Google Maps.

![El algoritmo de Dijkstra implementado para la búsqueda de rutas en un mapa.](https://miro.medium.com/max/1400/1*XiDkY_1HQzWQAtwquz7M9g.jpeg)
Sin embargo, para encontrar una ruta en Google Maps, una implementación del algoritmo de Dijkstra tiene que ser aún más inteligente que la que hemos creado hoy. La versión del algoritmo de Dijkstra que hemos implementado aquí todavía no es tan inteligente como la mayoría de las formas que se utilizan a nivel práctico. Imagina no sólo un gráfico ponderado, sino también tener que calcular cosas como el tráfico, el estado de las carreteras, los cierres de carreteras y las obras.
Si todo esto te parece mucho, no te preocupes: ¡es algo complicado! De hecho, es un problema difícil que incluso Dijkstra se esforzó por ejemplificar bien. Resulta que cuando Edsger W. Dijkstra pensó por primera vez en el problema de encontrar el camino más corto, allá por 1956, le costó encontrar un problema (y su solución) que fuera fácil de entender para las personas que no procedían del mundo de la informática. Al final se le ocurrió un buen problema de ejemplo para mostrar la importancia de ser capaz de encontrar un camino más corto. Eligió -¡lo has adivinado! - un mapa como ejemplo. De hecho, cuando diseñó su algoritmo originalmente, lo implementó para un ordenador llamado ARMAC. Utilizó el ejemplo de un mapa de transporte, que contenía ciudades de toda Holanda, para mostrar cómo funcionaba su algoritmo.
Hacia el final de su vida, Dijkstra se sentó para una entrevista y reveló toda la historia de cómo llegó a su ahora famoso algoritmo:
> ¿Cuál es el camino más corto para ir de Rotterdam a Groningen? Es el algoritmo del camino más corto que diseñé en unos 20 minutos. Una mañana estaba de compras con mi joven prometida, y cansados, nos sentamos en la terraza de la cafetería a tomar un café y me puse a pensar si podría hacerlo, y entonces diseñé el algoritmo del camino más corto.


References: 
[Finding The Shortest Path, With A Little Help From Dijkstra](https://medium.com/basecs/finding-the-shortest-path-with-a-little-help-from-dijkstra-613149fbdc8e)

Contributors: 
- Paul Landaeta Flores 
- Dylan Chambi 