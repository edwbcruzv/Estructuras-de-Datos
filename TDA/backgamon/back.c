#include<stdio.h>
#include"bicola.h"

typedef ELEMB Casilla;
int Dado1();
int Dado2();
BiCola Inicializando();
void InicioBK(BiCola B);
ApNodoB ApCasilla(BiCola bq,int n);
int NumFichas(BiCola bq,int cas);
int NumCasilla(BiCola bq,int cas);
void MeteFichas(BiCola bq,int cas,int n);
void SacaFicha(BiCola bq,int cas);
void ImpTablero(BiCola B);
void Jugador1(BiCola B,int *brr);
int EsVacioBarra(int *brr);
int CondicionCas(BiCola bq,int cas,char tipof);
int EsVacioCas(ApNodoB ap);
int EsSuCas(ApNodoB ap,char tipof);
int OneFichaContra(ApNodoB ap,char tipof);

int main(){
	srand(time(NULL));
	BiCola PF=Inicializando();
	//ImpTablero(PF);
	InicioBK(PF);
	int barra1=0,barra2=0;
	while(NumFichas(PF,1)!=15||NumFichas(PF,26)!=-15){
		ImpTablero(PF);
		Jugador1(PF,&barra1);
		//Jugador2(PF,&barra2);
	}
	//ImpTablero(PF);
	return 0;
}
///ACOMODA LAS FICHAS EN EL TABLERO PARA INICIAR EL JUEGO
void InicioBK(BiCola B){
	MeteFichas(B,2,2);
	MeteFichas(B,7,-5);
	MeteFichas(B,9,-3);
	MeteFichas(B,13,5);
	MeteFichas(B,14,-5);
	MeteFichas(B,18,3);
	MeteFichas(B,20,5);
	MeteFichas(B,25,-2);
}
///DADOS----------------------
int Dado1(){return rand()%6+1;}
int Dado2(){return rand()%6+1;}
///REGRESA CUANTAS FICHAS TIENE LA CASILLA ENVIADA
int NumFichas(BiCola bq,int cas){
	ApNodoB ap=ApCasilla(bq,cas);
	return ap->dato.fichas;
}
///REGRESA EL NUMERO DE CASILLA ENVIADA
int NumCasilla(BiCola bq,int cas){
	ApNodoB ap=ApCasilla(bq,cas);
	return ap->dato.NumCas;
}
///METE FICHAS EN LA CASILLA DADA STX:tablero----num de casilaa--num de fichas
void MeteFichas(BiCola bq,int cas,int n){
	ApNodoB ap=ApCasilla(bq,cas);
	int x=abs(n);
	if(n>0){
		while(x--)
		ap->dato.fichas=(ap->dato.fichas)+1;
	}
	if(n<0){
		while(x--)
		ap->dato.fichas=(ap->dato.fichas)-1;
	}
}
///SACA SOLO UNA FICHA DE LA CASILLA DADA STX:TABLERO---NUM CASILLA
void SacaFicha(BiCola bq,int cas){
	ApNodoB ap=ApCasilla(bq,cas);
	if((NumFichas(bq,cas))!=0){
		if((NumFichas(bq,cas))>0){
			ap->dato.fichas=(ap->dato.fichas)-1;
		}
		else if((NumFichas(bq,cas))<0){
				ap->dato.fichas=(ap->dato.fichas)+1;
			}
	}
}

///REGRESA EL APUNTADOR A LA CASILLA n  STX:tablero-num de casilla
ApNodoB ApCasilla(BiCola bq,int n){
	ApNodoB ap;
	ap=bq->izq;
	if((n>0)&&(n<27)){
		while((ap->dato.NumCas)!=n){
			ap=ap->sig;
		}
		return ap;
	}	
}
///CREA EL TABLERO DE JUEGO
BiCola Inicializando(){
	BiCola B=NuevaBC();
	Casilla c;
	
	int i;
	for(i=1;i<=26;i++){
		c.NumCas=i;
		c.fichas=0;
		B=FormarD(B,c);
	}
	return B;
}
///PROCESO DEL JUEGO
void Jugador1(BiCola B,int *brr){
	char casO,casD,tipof='N';  //ficha negativa
	printf("Jugador 1: fichas negativas\nEnter para tirar dados ");
	getchar();
	int d1=Dado1(),d2=Dado2();
	printf("Dado 1: %d\nDado 2: %d\n\n",d1,d2);
		/*si se tiene una o mas fichas en la barra las cuales fueron comidas
	se sacara la(s) ficha(s) de barra y se metera en el lugar que marquen los dados
	empezando desdel inicio de su casilla correspondiente y que la casilla destino
	cumpla con las *CONDICIONES DE CASILLA*
	*/
	if(!EsVacioBarra(brr))
		printf("Casilla destino?: ");
		scanf("%d",&casD);
		if(CondicionCas(B,casD,tipof))
			scanf("%d",&casD);
		
	/*//////////////////////////SE TERMINA EL TURNO///////////////////////////////////*/
		else { /* si el jugador no tiene fichas comidas puede mover cualquier fichas*/
		printf("Casilla origen?: ");
		scanf("%d",&casO);
		printf("Casilla destino?: ");
		scanf("%d",&casD);
		if(CondicionCas(B,casD,tipof))
		scanf("%d",&casD);
	/*//////////////////////////SE TERMINA EL TURNO///////////////////////////////////*/		
	}
}
///SE VERIFICA SI NO TIENE FICHAS COMIDAS EL JUGADOR
int EsVacioBarra(int *brr){
	return (*brr==0);
}
/*////////////////////CONDICIONES DE CASILLA//////////////////////////////////////
	*	SI la casilla esta vacia
	*		sino SI la casilla tiene fichas de su color
	*			sino SI-tiene solamente una ficha del jugador contrario
	*					entonces comerficha y meter la ficha
	*				sino se cumple ninguna no puede meterlo y terminara su turno
////////////////////////////////////////////////////////////////////////////////*/
int CondicionCas(BiCola bq,int cas,char tipof){
	ApNodoB ap=ApCasilla(bq,cas);
	if(EsVacioCas(ap))
		return 1;
		else if(EsSuCas(ap,tipof))
			return 1;
			else if(OneFichaContra(ap,tipof))
				return 1;
				else return 0;
}
///VERIFICA SI SU CASILLA ES VACIA
int EsVacioCas(ApNodoB ap){
	return ap->dato.fichas==0;
}
///VERIFICA SI LA CASILLA ES DEL JUGADOR
int EsSuCas(ApNodoB ap,char tipof){
	if((ap->dato.fichas<0)&&(tipof=='N'))
		return 1;
		else if((ap->dato.fichas>0)&&(tipof=='P'))
			return 1;
			else return 0;
}
///VERIFICA SI EXISTE SOLO UNA FICHA DEL JUGADOR CONTRARIO
int OneFichaContra(ApNodoB ap,char tipof){
	if(tipof=='N')
		return ap->dato.fichas==-1;
		else if(tipof=='P')
			return ap->dato.fichas==1;
}
//MOVER FICHA DE CASILLAS
void MoverFicha(BiCola bq,int casO,int casD){
	
} 
///IMPRIME EL TABLERO
void ImpTablero(BiCola B){
	printf("\n\n");
	int i;
	fflush(stdin);
	for(i=13;i>=8;i--)
		printf(" %d",NumCasilla(B,i));
	printf("       ");
	for(i=7;i>=2;i--)
		printf(" 0%d",NumCasilla(B,i));
	printf("    01");
	printf("\n-------------------------------------------------\n");
	for(i=13;i>=8;i--)
		printf(" %d ",NumFichas(B,i));
	printf("    ");
	for(i=7;i>=2;i--)
		printf(" %d ",NumFichas(B,i));
	printf("    %d",NumFichas(B,1));
	
	printf("\n\n\n\n\n");
	
	for(i=14;i<=19;i++)
		printf(" %d ",NumFichas(B,i));
	printf("    ");
	for(i=20;i<=25;i++)
		printf(" %d ",NumFichas(B,i));
	printf("    %d",NumFichas(B,26));
	printf("\n-------------------------------------------------\n");
	for(i=14;i<=19;i++)
		printf(" %d",NumCasilla(B,i));
	printf("     ");
	for(i=20;i<=25;i++)
		printf(" %d",NumCasilla(B,i));
	printf("    26");
	printf("\n\n");
/*	int *tabla[15][20];                  para programarlo en matrices (incompleto)
	///se guardan las casillas en la tabla
	for(i=0;i<15;i++)
		if(((i>=1)&&(i<=6))||((i>=10)&&(i<=15))||(i==18))
		tabla[2][i]=NumCasilla(ApCasilla(B,i))-1;
	
	for(i=0;i<15;i++)
		if(((i>=1)&&(i<=6))||((i>=10)&&(i<=15))||(i==18))
		tabla[2][i]=NumCasilla(ApCasilla(B,i))-1;
	*/
}
