/***** Elem ***/
/*
typedef struct ETH{
	char* Llave;
	char* Nombre;
	float Dinero;
}Elem;  
*/
typedef struct tp{
	char *Llave;//nombre del elemento
	char *simbolo; 
	char *grupo;
	int periodo;
	int noatomico;
	int nomasa;
	int protones;
	int neutrones;
	int electrones;
	char *tipoelem;
}Elem;

void ImpElem(Elem x){printf("\n\nNombre Del Elemento: %s\nSimbolo: %s\nGrupo: %s\nPeriodo: %i\nNo.Atomico: %i\nMasa: %i\nProtones: %i\nNeutrones: %i\nElectrones: %i\nTipo De Elemento: %s\n\n",x.Llave,x.simbolo,x.grupo,x.periodo,x.noatomico,x.nomasa,x.protones,x.neutrones,x.electrones,x.tipoelem);}


//void ImpElem(Elem e){printf("Llave: %s\nNombre: %s\nDinero: %.4f\n",e.Llave,e.Nombre,e.Dinero);}              //para int



int esmenor(Elem e1,Elem e2){return strcmp(e1.Llave,e2.Llave)<=0;}     //para comparar cadenas
int esigual(char* Ll1,char* Ll2){return strcmp(Ll1,Ll2)==0;} 
void ImpElemArch(Elem s, FILE *out){ fprintf(out,"%s\n",s);}   //para imprimir por archivo de salida
