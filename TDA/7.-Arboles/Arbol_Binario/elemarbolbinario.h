////******elemarbolbinario********

typedef int ElemA;

void ImpElemA(ElemA e){printf("%d \n",e);} ///para int

//void ImpElemA(ElemA e){printf("%s ",e);}///para char*
void ImpElemAVL(ElemA e,int i){printf("%d  %d\n",e,i);}

void ImpElemAArch(ElemA e,FILE *out){fprintf(out,"%s \n",e);}//para imprimir por un archivo de salida


//////////////////////////////////////////INT\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

int EsMAoIA(ElemA v1,ElemA v2){return v1>=v2;}
int EsMoIA(ElemA v1,ElemA v2){return v1<=v2;} 
int EsMenor(ElemA v1,ElemA v2){return v1<v2;}
int EsMayor(ElemA v1,ElemA v2){return v1>v2;}
int EsIgual(ElemA v1,ElemA v2){return v1=v2;}
////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

//int EsMoIA(ElemA v1,ElemA v2){return (strcasecmp(v1,v2)<=0);}  //para comparar cadenas lexicograficamente
