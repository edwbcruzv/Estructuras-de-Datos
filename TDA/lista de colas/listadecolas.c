#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"lista.h"


///cuatro cola  cola 1(1-99) 2(100-199) 3(200-299) 4(300-400)
int main(){
	srand(time(NULL));
	Cola c1,c2,c3,c4;
	c1=formar(formar(formar(formar(nueva(),cola1()),cola1()),cola1()),cola1());
	c2=formar(formar(formar(formar(nueva(),cola2()),cola2()),cola2()),cola2());
	c3=formar(formar(formar(formar(nueva(),cola3()),cola3()),cola3()),cola3());
	c4=formar(formar(formar(formar(nueva(),cola4()),cola4()),cola4()),cola4());
	Lista l=cons(c1,cons(c2,cons(c3,cons(c4,vacia()))));
	ImpLista(l);

	
	return 0;
}

int cola1(){
	return (rand()%100);
	}	

int cola2(){
	return (rand()%100)+100;
	}
	
int cola3(){
	return (rand()%100)+200;
	}

int cola4(){
	return (rand()%100)+300;
	}
	
