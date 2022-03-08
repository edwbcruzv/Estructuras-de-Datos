/***** Elem ***/
//#include"cola.h"
typedef int Elem;     //esto es para archivos ya que son cadenas de caracter tipo char*

//void ImpElem(Elem e){ImpCola(e);}                    //para imprimir elementos tipo cola
  void ImpElem(Elem e){printf("%d\n",e);}              //para int
//void ImpElem(Elem e){ImpCola(e); printf("\n\n");}    //para imprimir colas
//void ImpElem(Elem e){printf("%s\n",e);}              //para cadenas


  int esmenor(Elem e1,Elem e2){ return  e1<e2;}                 //para comparar elementos tipo int
//int esmenor(Elem e1, Elem e2){ return (strcmp(e1,e2)<0);}     //para comparar cadenas

 
void ImpElemArch(Elem s, FILE *out){ fprintf(out,"%s\n",s);}   //para imprimir por archivo de salida
