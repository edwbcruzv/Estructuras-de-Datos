#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"bicola.h"

typedef ELEMB Casilla;
int main();
int Dado1();
int Dado2();
BiCola Inicializando();
void InicioBK(BiCola B);
ApNodoB ApCasilla(BiCola bq,int n);
int NumFichas(BiCola bq,int cas);
void MeteFichas(BiCola bq,int cas,int n);
void SacaFicha(BiCola bq,int cas);
void ImpTablero(BiCola B,int barra1,int barra2);
int EsVacioBarra(int brr);
int CondicionCas(BiCola bq,int cas,char tipof);
int EsVacioCas(ApNodoB ap);
int EsSuCas(ApNodoB ap,char tipof);
int OneFichaContra(ApNodoB ap,char tipof);

void Jugador1(BiCola B,int *brr1,int *brr2);
void Jugador2(BiCola B,int *brr1,int *brr2);
int EsPosibleCasillas(BiCola bq,int casO,int casD,int d1,int d2,char tipof);
int CasillaD(BiCola bq,int casO,int dado,char tipof);

int main(){
	int l=2;
	srand(time(NULL));
	BiCola B=Inicializando();
	InicioBK(B);
	while(l--){
		printf("Enter para tirar dados ");
		getchar();
		int d1=Dado1(),d2=Dado2();
		printf("\nDado 1: %d\nDado 2: %d\n\n",d1,d2);
	}getchar();
	int barra1=0,barra2=0;
	while(NumFichas(B,1)!=-15||NumFichas(B,26)!=15){
		system("cls");
		ImpTablero(B,barra1,barra2);
		Jugador1(B,&barra1,&barra2);
		system("cls");
		ImpTablero(B,barra1,barra2);
		Jugador2(B,&barra1,&barra2);
	}
	if(NumFichas(B,1)!=-15)
		printf("\nEl ganador es el jugador 2");
	else if(NumFichas(B,26)!=15)
			printf("\nEl ganador es el jugador 1");
	return 0;
}

void Jugador1(BiCola B,int *brr1,int *brr2){
	int casO,casD,ds,t=1;
	char tipof='P';  //ficha positiva
		printf("Jugador 1: fichas positivas\nEnter para tirar dados ");
		getchar();
		int d1=Dado1(),d2=Dado2();
		
	if(d1==d2)
		ds=(d1+d2)*2;
	else ds=d1+d2;
	
	if(!EsVacioBarra(*brr1)){
		casO=1;
		do{	printf("\nDado 1: %d\nDado 2: %d\nTirada %d\n\n",d1,d2,t++);
			do{
				do{ fflush(stdin);
					printf("casilla de destino?: ");
					scanf("%d",&casD);
					if(!CondicionCas(B,casD,tipof))
						printf("Digite otra ");
				}while(!CondicionCas(B,casD,tipof));
					if(!EsPosibleCasillas(B,casO,casD,d1,d2,tipof))
						printf("Digite otra ");
			}while(!EsPosibleCasillas(B,casO,casD,d1,d2,tipof));
				*brr1=*brr1-1;  		 	//sacando una ficha de la barra
				if(OneFichaContra(ApCasilla(B,casD),tipof)){
					*brr2=*brr2-1;
					SacaFicha(B,casD);
					MeteFichas(B,casD,1);
				}
				else MeteFichas(B,casD,1); 		 //agregando la ficha del jugador
				system("cls");
				ImpTablero(B,*brr1,*brr2);
				ds=ds-abs(casO-casD);
				if((EsVacioBarra(*brr1))&&(ds!=0)){
					
					do{printf("\nDado 1: %d\nDado 2: %d\nTirada %d\n\n",d1,d2,t++);
						do{
							do{ 
								fflush(stdin);
								printf("casilla origen?: ");
								scanf("%d",&casO);
								if(!EsSuCas(ApCasilla(B,casO),tipof))
									printf("Esa no es su casilla \nDigite otra ");
							}while(!EsSuCas(ApCasilla(B,casO),tipof));
							do{ fflush(stdin);
								printf("casilla de destino?: ");
								scanf("%d",&casD);
								if(!CondicionCas(B,casD,tipof))
									printf("Digite otra ");
							}while(!CondicionCas(B,casD,tipof));
								if(!EsPosibleCasillas(B,casO,casD,d1,d2,tipof))
									printf("Digite otra ");
						}while(!EsPosibleCasillas(B,casO,casD,d1,d2,tipof));
							SacaFicha(B,casO);  //sacando una ficha de la casilla de origen
							if(OneFichaContra(ApCasilla(B,casD),tipof)){
								*brr2=*brr2-1;
								SacaFicha(B,casD);
								MeteFichas(B,casD,1);
							}
							else MeteFichas(B,casD,1); //agregando la ficha del jugador
							system("cls");
							ImpTablero(B,*brr1,*brr2);
							ds=ds-abs(casO-casD);
					}while(ds);
				}
				
		}while(ds);
	}
	else{
		do{ printf("\nDado 1: %d\nDado 2: %d\nTirada %d\n\n",d1,d2,t++);
			do{
				do{ 
					fflush(stdin);
					printf("casilla origen?: ");
					scanf("%d",&casO);
					if(!EsSuCas(ApCasilla(B,casO),tipof))
						printf("Esa no es su casilla \nDigite otra ");
				}while(!EsSuCas(ApCasilla(B,casO),tipof));
				do{ fflush(stdin);
					printf("casilla de destino?: ");
					scanf("%d",&casD);
					if(!CondicionCas(B,casD,tipof))
						printf("Digite otra ");
				}while(!CondicionCas(B,casD,tipof));
					if(!EsPosibleCasillas(B,casO,casD,d1,d2,tipof))
						printf("Digite otra ");
			}while(!EsPosibleCasillas(B,casO,casD,d1,d2,tipof));
				SacaFicha(B,casO);  //sacando una ficha de la casilla de origen
				if(OneFichaContra(ApCasilla(B,casD),tipof)){
					*brr2=*brr2-1;
					SacaFicha(B,casD);
					MeteFichas(B,casD,1);
				}
				else MeteFichas(B,casD,1); //agregando la ficha del jugador
				system("cls");
				ImpTablero(B,*brr1,*brr2);
				ds=ds-abs(casO-casD);
		}while(ds);
	}
}
void Jugador2(BiCola B,int *brr1,int *brr2){
	int casO,casD,ds,t=1;
	char tipof='N';  //ficha negativa
		printf("Jugador 1: fichas negativas\nEnter para tirar dados ");
		getchar();
		int d1=Dado1(),d2=Dado2();
		
	if(d1==d2)
		ds=(d1+d2)*2;
	else ds=d1+d2;
	
	if(!EsVacioBarra(*brr2)){
		casO=26;
		do{	printf("\nDado 1: %d\nDado 2: %d\nTirada %d\n\n",d1,d2,t++);
			do{
				do{ fflush(stdin);
					printf("casilla de destino?: ");
					scanf("%d",&casD);
					if(!CondicionCas(B,casD,tipof))
						printf("Digite otra ");
				}while(!CondicionCas(B,casD,tipof));
					if(!EsPosibleCasillas(B,casO,casD,d1,d2,tipof))
						printf("Digite otra ");
			}while(!EsPosibleCasillas(B,casO,casD,d1,d2,tipof));
				*brr2=*brr2+1;  		 	//sacando una ficha de la barra
				if(OneFichaContra(ApCasilla(B,casD),tipof)){
					*brr1=*brr1+1;
					SacaFicha(B,casD);
					MeteFichas(B,casD,-1);
				}
				else MeteFichas(B,casD,-1); 		 //agregando la ficha del jugador
				system("cls");
				ImpTablero(B,*brr1,*brr2);
				ds=ds-abs(casO-casD);
				if(EsVacioBarra(*brr1)&&ds!=0){
					do{ printf("\nDado 1: %d\nDado 2: %d\nTirada %d\n\n",d1,d2,t++);
						do{
							do{ 
								fflush(stdin);
								printf("casilla origen?: ");
								scanf("%d",&casO);
								if(!EsSuCas(ApCasilla(B,casO),tipof))
									printf("Esa no es su casilla \nDigite otra ");
							}while(!EsSuCas(ApCasilla(B,casO),tipof));
							do{ fflush(stdin);
								printf("casilla de destino?: ");
								scanf("%d",&casD);
								if(!CondicionCas(B,casD,tipof))
									printf("Digite otra ");
							}while(!CondicionCas(B,casD,tipof));
								if(!EsPosibleCasillas(B,casO,casD,d1,d2,tipof))
									printf("Digite otra ");
						}while(!EsPosibleCasillas(B,casO,casD,d1,d2,tipof));
							SacaFicha(B,casO);  //sacando una ficha de la casilla de origen
							if(OneFichaContra(ApCasilla(B,casD),tipof)){
								*brr1=*brr1+1;
								SacaFicha(B,casD);
								MeteFichas(B,casD,-1);
							}
							else MeteFichas(B,casD,-1); //agregando la ficha del jugador
							system("cls");
							ImpTablero(B,*brr1,*brr2);
							ds=ds-abs(casO-casD);
					}while(ds);
				}
		}while(ds);
	}
	else{
		do{ printf("\nDado 1: %d\nDado 2: %d\nTirada %d\n\n",d1,d2,t++);
			do{
				do{ 
					fflush(stdin);
					printf("casilla origen?: ");
					scanf("%d",&casO);
					if(!EsSuCas(ApCasilla(B,casO),tipof))
						printf("Esa no es su casilla \nDigite otra ");
				}while(!EsSuCas(ApCasilla(B,casO),tipof));
				do{ fflush(stdin);
					printf("casilla de destino?: ");
					scanf("%d",&casD);
					if(!CondicionCas(B,casD,tipof))
						printf("Digite otra ");
				}while(!CondicionCas(B,casD,tipof));
					if(!EsPosibleCasillas(B,casO,casD,d1,d2,tipof))
						printf("Digite otra ");
			}while(!EsPosibleCasillas(B,casO,casD,d1,d2,tipof));
				SacaFicha(B,casO);  //sacando una ficha de la casilla de origen
				if(OneFichaContra(ApCasilla(B,casD),tipof)){
					*brr1=*brr1+1;
					SacaFicha(B,casD);
					MeteFichas(B,casD,-1);
				}
				else MeteFichas(B,casD,-1); //agregando la ficha del jugador
				system("cls");
				ImpTablero(B,*brr1,*brr2);
				ds=ds-abs(casO-casD);
		}while(ds);
	}
}
//REGRESA LAS POSIBLES CASILLAS DESTINO RESPECTO A LOS DADOS---------------------------
int EsPosibleCasillas(BiCola bq,int casO,int casD,int d1,int d2,char tipof){
	int casd1,casd2,casd3;
	casd1=CasillaD(bq,casO,d1+d2,tipof);
	casd2=CasillaD(bq,casO,d1,tipof);
	casd3=CasillaD(bq,casO,d2,tipof);
	
	//printf("\nposibles casillas:%d %d %d",casd1,casd2,casd2);
	if(casD==casd1)
		return 1;
	else if(casD==casd2)
		return 1;
		else if(casD==casd3)
			return 1;
			else return 0;
}
//REGRESA UNA CASILLA DESTINO-----------------------------------------------------------
/*usando los valores del dado recibido va a devolver la casilla a dinde va a llegar*/
int CasillaD(BiCola bq,int casO,int dado,char tipof){
	ApNodoB ap=ApCasilla(bq,casO);
	int i;
	if(tipof=='N'){
		for(i=1;i<=dado;i++){
			if(ap->ant!=NULL)
				ap=ap->ant;
		}
	}
	else if(tipof=='P'){
			for(i=1;i<=dado;i++){
				if(ap->sig!=NULL)
					ap=ap->sig;
			}
		}
	return ap->dato.NumCas;
}
//REGRESA EL APUNTADOR A LA CASILLA n  sintaxis: tablero-num de casilla------------------
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
///METE FICHAS EN LA CASILLA DADA -----------------------------------------------------
/*mete n fichas en una casilla dependiendo si es positivo o negativo 
sintaxis: tablero----num de casilaa--num de fichas - O +*/
void MeteFichas(BiCola bq,int cas,int n){
	ApNodoB ap=ApCasilla(bq,cas);
	int x=abs(n);
	if(n>0){
		while(x--)
		ap->dato.fichas=(ap->dato.fichas)+1;
	}
	else if(n<0){
			while(x--)
			ap->dato.fichas=(ap->dato.fichas)-1;
		}
		else ap->dato.fichas=0;
}
///SACA SOLO UNA FICHA DE LA CASILLA DADA----------------------------------------------
/*saca solo una ficha de la casilla recibida dependiendo de 
si el numero de fichas es positivo o negativo
sintaxis: tablero---numero de casilla*/
void SacaFicha(BiCola bq,int cas){
	ApNodoB ap=ApCasilla(bq,cas);
	if((NumFichas(bq,cas))!=0){
		if((NumFichas(bq,cas))>0){
			ap->dato.fichas=ap->dato.fichas-1;
		}
		else if((NumFichas(bq,cas))<0){
				ap->dato.fichas=ap->dato.fichas+1;
			}
	}
	else ap->dato.fichas=0;
}
///REGRESA CUANTAS FICHAS TIENE LA CASILLA ENVIADA------------------------------------
int NumFichas(BiCola bq,int cas){
	ApNodoB ap=ApCasilla(bq,cas);
	return ap->dato.fichas;
}
/*////////////////////CONDICIONES DE CASILLA PARA INSERTAR FICHA//////////////////////////////////////
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
///VERIFICA SI SU CASILLA ES VACIA-----------------------------------------------------
int EsVacioCas(ApNodoB ap){
	return ap->dato.fichas==0;
}
///VERIFICA SI LA CASILLA ES DEL JUGADOR-----------------------------------------------
int EsSuCas(ApNodoB ap,char tipof){
	if((ap->dato.fichas<0)&&(tipof=='N'))
		return 1;
		else if((ap->dato.fichas>0)&&(tipof=='P'))
			return 1;
			else return 0;
}
///VERIFICA SI EXISTE SOLO UNA FICHA DEL JUGADOR CONTRARIO-----------------------------
int OneFichaContra(ApNodoB ap,char tipof){
	if(tipof=='N')
		return ap->dato.fichas==1;
		else if(tipof=='P')
			return ap->dato.fichas==-1;
}
///SE VERIFICA SI NO TIENE FICHAS COMIDAS EL JUGADOR----------------------------------
int EsVacioBarra(int brr){
	return (brr==0);
}
///IMPRIME EL TABLERO------------------------------------------------------------------
void ImpTablero(BiCola B,int barra1,int barra2){
	printf("\n\n");
	int i;
	//system("cls");
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
	
	printf("\n");
	printf("\t\t     %d",barra1);
	printf("\n\n\n");
	printf("\t\t     %d",barra2);
	printf("\n");
	
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
}
///ACOMODA LAS FICHAS EN EL TABLERO PARA INICIAR EL JUEGO---------------------------
/*la funcion acomoda las fichas como vienen las reglas para empezar la jugada*/
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
int Dado1(){return rand()%6+1;}

int Dado2(){return rand()%6+1;}
//SE CREA LA BICOLA CON LOS NUMEROS DE CASILLA DE LA TABLA--------------------------
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
///REGRESA EL NUMERO DE LA CASILLA--------------------------------------------------
int NumCasilla(BiCola bq,int cas){
	ApNodoB ap=ApCasilla(bq,cas);
	return ap->dato.NumCas;
}
