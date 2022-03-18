#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"

/** Funciones que manipulan a la lista usando las funciones del TDA **/

 // ./a.out numeros.txt s.txt

int main(int argc, char* argv[]){
        FILE *in=fopen(*(argv+1),"r");
        FILE *out=fopen(*(argv+2),"w");
        char pal[80], *p; 

        Lista words=Vacia();

        while(fscanf(in,"%s",pal)!=EOF){
               p=(char*)malloc(80);
               strcpy(p,pal);
               words=ConsL(p,words);
        }
         
        ImpListaArch(words,out);  
   
        fclose(in); fclose(out);
	return 0;
}



