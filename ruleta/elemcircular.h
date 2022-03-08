//////***elemcircular*****///////
typedef struct NyC{
	int Numero;
	char Color;
}ELEM;

void ImpELEMC(ELEM e){printf("\n\n%d %c",e.Numero,e.Color);} 

    //      q->dato    ,e
int EsMayor(ELEM e1,ELEM e2){return e1.Numero>=e2.Numero;}
