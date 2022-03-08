#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pila.h"



int EsDigito(char);      //si es digito
int EsLetra(char);     //si es letra
int EsParIzq(char);   //si es es parentisis izquierdo
int EsOperador(char);   // se pregunta si es operando
int Prec(char);  //presedencia del operador
int EsParDer(char);      //si es parentesis derecho

int main(){
	FILE*out=fopen("operacion.txt","r");
	char c[50];
	int i=0;
	fscanf(out,"%s",&c);  ////lee el archivo de texto y lo guarda en el aeerglo
	Pila op=empty();   //se declara un un elemento tipo PILA y se indica que es vacia
	
    while(c[i]){
	{	
       if((EsLetra(c[i]))||(EsDigito(c[i]))){putchar(c[i]);} //si es letra o digito la imprime
	   
	   else if(EsOperador(c[i])){   //Se pregunta si es + - / *
                if((Prec(c[i]))>(Prec(tope(op))))
                    op=push(c[i],op);         //si es operador la mete a la pila
                else {while((Prec(c[i]))<=(Prec(tope(op)))){ //se utiliza para sacar los operadores de acuerdo a su precedencia
                            putchar(tope(op)); 
				            op=pop(op);             
                    } 
					        op=push(c[i],op);
	            }
				}         
           else if(EsParIzq(c[i])){    //se pregunta si es parentesis izquierdo
                     op=push(c[i],op);  
		    }					                //para meterlo a la pila
                else if(EsParDer(c[i])){
                        {						//se pregunta si es parentesis derecho para sacar los operandos de la pila
                        while(tope(op)!='('/*!(EsParIzq(tope(op)))*/){ // hasta que se encuentre el parentesis izq se acaba el bucle
                         putchar(tope(op)); 
				         op=pop(op);         //resto de la pila
						 } 
						 //op=pop(op); 
						}						 //resto de la pila(en caso de que abajo de parentesis izq esistan mas operandos)
                    }
                       else if(isempty(op)){
                            op=push(c[i],op);
				            }   
	}				          
    i++;
}
    while(!(isempty(op))){ 
	fprintf(stdout,"%c",putchar(tope(op))); 
	       op=pop(op);   //imprime lo que hay en la pila
		   }
	
    return 0;
}

int EsOperador(char a){ 
	switch(a){
		case '+':case '-':case '*':case '/':case '^':return 1;default:return 0; break;
	}
}
int EsDigito(char a){return((a>='0')&&(a<='9'));}

int EsLetra(char a){return(((a>='a')&&(a<='z'))||(a>='A')&&(a<='Z'));}

int EsParIzq(char a){return (a=='(');}

int EsParDer(char a){return (a==')');}

int Prec(char a){   //prioridad o precedencia de los operadores (aritmetica de operadores)
	switch(a){
		case '^':return 3;break;
		case '/':case '*':return 2;break;
		case '+':case '-':return 1;break;
		default:return 0;break;
	}
}

////http://es.ccm.net/faq/2885-las-pilas-en-lenguaje-c

////https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/

