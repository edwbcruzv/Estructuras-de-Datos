

/*arboles heap (moticulo):
Un heap es un arbol binario completo en el que hay un orden compuesto
en sus nodos de tal forma que el valor de la raiz de un arbol es mayor o igual a los valores en sus dos subarboles,
y ambos sub arboles tambien son heaps, junto con un numero de procedimientos de acceso

Especificacion algebraica:
	la especificacion algebraica de un heap es identica a la del arbol binario con la excepcion de que la 
	constructora ConsA(.....) no esta disponible para el usuario en su lugar necesitamos funciones para construir los heaps
	Un arbol binario es completo si tiene una altura "h" y esta lleno hasta el nivel "h-1" con el nivel "h" llenado de 
	izquierda y derecha 
	esta definicion se especificam de esta manera
	completo!=lleno
	
	para 
	completo:para construir un arbol completo, debemos de crear un arbol que este lleno hasta el penultimo nivel, y
	llenado de izquierda a derecha en el ultimo nivel para tal efecto necesitamos un predicado que nos diga si el arbol esta lleno.
	
	lleno: un arbol esta lleno si es vacio o si las alturas de sus subarboles son iguales y ambos esta llenos. esto es
	Debemos de proporcionar un procedimiento que inserte un elemento en un arbol binario completo de tal forma que er 
	arbol resultante sea completo 
	
	
	Dado el procedimiento anterior necesitamos un procedimiento que reciva un arbol completo y regrese un heap osea un consheap
	
	antes de escribir este procedimiento escribamos otro que toma un elemento y dos heaps y debuelba un heap
	
	
*/

EsCompleto(ArBin A)=Si EsVacioA(A)
					return 1;
					sino si[(altura(izq(a))-altura(der(a)))<=1 y EsCompleto(izq(a)) y EsCompleto(der(A))]
					return 1;
					sino return 0;
					