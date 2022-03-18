#include"avl.h"
/*arboles heap (moticulo):
Un heap es un arbol binario completo en el que hay un orden compuesto
en sus nodos de tal forma qque el valor de la raiz de un arbol es mayor o igual a los valores en sus dos subarboles,
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
	
*/

EsCompleto(ArBin A)=Si EsVacioA(A)
					return 1;
					sino si[(altura(izq(a))-altura(der(a)))<=1 y EsCompleto(izq(a)) y EsCompleto(der(A))]
					return 1;
					sino return 0;
					