#include<stdio.h>
#include"colacircular.h"

typedef union numselc{
	int N[15];//numeros apostados
	char pal[15];//palabra de la apuesta
}CasApostadas;
/*esttructura del jugador
se almacenara su nombre, tipo de apuesta y dependiendo del tipo de su apuesta se juagrdaran
ya se a la casilla o los numeros que aposto */
typedef struct user{
	char Nombre[25];
	int Dinero;
	int TipoApue;
	CasApostadas CApuesta;
}Jugador;
//PROTOTIPOS
ELEM Cas(int num,char clr);
Circular InicializarRul();
ELEM NumeroGanador(Circular r);
void TipoApuesta();
int Dominio(int n);
Jugador* DatosJugador();
void EscojerCasilla(Jugador *j,int n);
void ImpJugador(Jugador *j);
void ImpTipoAp(Jugador *j,int n);
void Ganadores(Jugador **j,ELEM numg,int numj);
int Gano(Jugador j,ELEM numg);
int DineroGanado(int TipoA,int Dinero);
char* PasaoFalta(int n);
char* ParoImp(int n);
char* leecad(char* r);

int main(){
	int x,i;
	ELEM g;
	srand(time(NULL));
	Circular Ruleta;
	Ruleta=InicializarRul(); //se inicializa la ruleta
	system("cls");
	fflush(stdin);
	printf("Numero de jugadores: ");
	scanf("%d",&x);
	//se crea el arreglo de jugadores
	Jugador *jugadores[x]; 
	//lee los jugadoores
	for(i=0;i<x;i++){
		printf("\n\nDatos Jugador %d:",i+1);
		jugadores[i]=DatosJugador();
	}
	//imprime lso jugadores
	//for(i=0;i<x;i++)
	//	ImpJugador(jugadores[i]);
	//gira la ruleta
	system("cls");
	printf("\n\nPulse enter para girar la ruleta ");
	g=NumeroGanador(Ruleta);
	ImpELEMC(g);
	Ganadores(jugadores,g,x);
	return 0;
}
///SE INICIALIZA LA RULETA CON LOS DATOS CORRESPONDIENTES
Circular InicializarRul(){
	Circular A,a,b,c,d,e,f;
	a=formar(formar(formar(formar(formar(formar(nuevac(),Cas(0,'V')),Cas(32,'R')),Cas(15,'N')),Cas(19,'R')),Cas(4,'N')),Cas(21,'R'));
	b=formar(formar(formar(formar(formar(formar(a,Cas(2,'N')),Cas(25,'R')),Cas(17,'N')),Cas(34,'R')),Cas(6,'N')),Cas(27,'R'));
	c=formar(formar(formar(formar(formar(formar(b,Cas(13,'N')),Cas(36,'R')),Cas(11,'N')),Cas(30,'R')),Cas(8,'N')),Cas(23,'R'));
	d=formar(formar(formar(formar(formar(formar(c,Cas(10,'N')),Cas(5,'R')),Cas(24,'N')),Cas(16,'R')),Cas(33,'N')),Cas(1,'R'));
	e=formar(formar(formar(formar(formar(formar(d,Cas(20,'N')),Cas(14,'R')),Cas(31,'N')),Cas(9,'R')),Cas(22,'N')),Cas(18,'R'));
	f=formar(formar(formar(formar(formar(formar(e,Cas(29,'N')),Cas(7,'R')),Cas(28,'N')),Cas(12,'R')),Cas(35,'N')),Cas(3,'R'));
	return A=formar(f,Cas(26,'N'));
}
///GUARDA LOS NUMEROS DE CADA CASILLA Y DEVUELVE EN UN TIPO ELEM PARA GUARDARLOS EN LA RULETA
ELEM Cas(int num,char clr){
	ELEM e;
	e.Numero=num;
	e.Color=clr;
	return e;
}
///GIRA LA RULETA Y REGRESA EL NUMERO GANADOR
ELEM NumeroGanador(Circular r){
	int n;
	n=(rand()%7249)+(rand()%2564);
	while(n--){
		r=rotar(r);
	}
	return primero(r);
}
///IMPRIME EL MENU DEL TIPO DE APUESTAS QUE EXISTEN
void TipoApuesta(){
	printf("Escoja el tipo de apuesta que guste\n\n\t1.-Rojo/Negro\n\t2.-Par/Impar\n\t3.-Pasa/Falta\n\t4.-Docena\n\t5.-Dos Docenas\n\t6.-Columna\n\t7.-Dos Columnas\n\t8.-Seisena\n\t9.-Cuadro\n\t10.-Transversal\n\t11.-Caballo\n\t12.-Pleno\n\n\n");
}
///DOMINIO DE LAS FICHAS
int Dominio(int n){
	return (n>=0)&&(n<=36);
}
///CAPTURA LOS DATOS DEL JUGADOR
Jugador* DatosJugador(){
	int x;
	Jugador *t=(Jugador*)malloc(sizeof(struct user));
	printf("\nEscriba su nombre: ");fflush(stdin);
	gets(t->Nombre);
	printf("Dinero a apostar: ");fflush(stdin);
	scanf("%d",&(t->Dinero));
	do{
		TipoApuesta();fflush(stdin);
		scanf("%d",&x);
	}while((x<0)&&(x>12));
	t->TipoApue=x;
	EscojerCasilla(t,x);
	return t;
	
}

void Ganadores(Jugador **j,ELEM numg,int numj){
	int i;
	for(i=0;i<numj;i++){
		Gano(*j[i],numg)?printf("\n %s gano:$%d",j[i]->Nombre,DineroGanado(j[i]->TipoApue,j[i]->Dinero)):printf("\n %s no gana nada :V",j[i]->Nombre);
	}
}

int Gano(Jugador j,ELEM numg){
	int i;
	switch(j.TipoApue){
		//si en la ruleta cae nogro o rojo se determinaran los ganadores
		case 1:	if(numg.Color=='N'){
					if(!strcmp(j.CApuesta.pal,"negro"))
						return 1;
				}	
				else if(numg.Color=='R'){
						if(!strcmp(j.CApuesta.pal,"rojo"))
							return 1;
					};
			break;
		//si el numero es par o impar se determinara los ganadores
		case 2:	if(!strcmp(j.CApuesta.pal,ParoImp(numg.Numero)))
						return 1;
			break;
		//si el numero es de falta o pasa se determinara al ganador
		case 3:	if(!strcmp(j.CApuesta.pal,PasaoFalta(numg.Numero)))
						return 1;
			break;
		//se determinara si se selecciono columna 1,2 o 3
		case 4: if(*j.CApuesta.N==NumDocena(numg.Numero))
						return 1;
				;
			break;
		//se determinara si una de las dos columnas seleccionadas son el 1,2 o 3
		case 5:	if(*j.CApuesta.N==NumDocena(numg.Numero))
						return 1;
				else if(*(j.CApuesta.N+1)==NumDocena(numg.Numero))
						return 1;
				;
			break;
		//se determinara si se selecciono la docena 1,2 o 3
		case 6:	if(*j.CApuesta.N==NumColum(numg.Numero))
						return 1;
			break;
		//se determinara si una de las dos docenas seleccionadas son el 1,2 o 3
		case 7:	if(*j.CApuesta.N==NumColum(numg.Numero))
						return 1;
				else if(*(j.CApuesta.N+1)==NumColum(numg.Numero))
						return 1;
			break;
		//se buscara si uno de los 6 numeros es igual al numero que salio en la ruleta
		case 8:	for(i=0;i<6;i++){
					if(*(j.CApuesta.N+i)==numg.Numero)
						return 1;
				}
			break;
		//se buscara si uno de los 4 numeros es igual al numero que salio en la ruleta 
		case 9:	for(i=0;i<4;i++){
					if(*(j.CApuesta.N+i)==numg.Numero)
						return 1;
				}
			break;
		//se buscara si uno de los 3 numeros es igual al numero que salio en la rulet
		case 10:for(i=0;i<3;i++){
					if(*(j.CApuesta.N+i)==numg.Numero)
						return 1;
				}
			break;
		//se buscara si uno de los 2 numeros es igual al numero que salio en la rulet
		case 11:for(i=0;i<2;i++){
					if(*(j.CApuesta.N+i)==numg.Numero)
						return 1;
				};
			break;
		//se determinara al ganador i el numero que escojio es igual al numero que salio en la ruleta
		case 12:return *j.CApuesta.N==numg.Numero;
			break;
	}
	
	return 0;
}

int DineroGanado(int TipoA,int Dinero){
	switch(TipoA){
		case 1:case 2:case 3:return 2*Dinero; //1 ves lo apostado + lo apostado
			break;
		case 4:case 6:return 3*Dinero; //2 veces lo apostado + lo apostado
			break;
		case 5:case 7:return (Dinero/2)+Dinero; //1/2 de lo apostado + lo apostado
			break;
		case 8:	return 6*Dinero; //5 veces lo apostado + lo apostado
			break;
		case 9:	return 9*Dinero; //8 veces lo apostado + lo apostado
			break;
		case 10:return 12*Dinero; //11 veces lo apostado + lo apostado
			break;
		case 11:return 18*Dinero; //17 veces lo apostado + lo apostado
			break;
		case 12:return 36*Dinero; //25 veces lo apostado + lo apostado
			break;
	}
}
///CAPTURA SOLO LAS APUESTAS DEL JUGADOR DEPENDIANDO DEL TIPO DE APUESTA
void EscojerCasilla(Jugador *j,int n){
	int i;fflush(stdin);
	switch(n){
		case 1:	printf("Escoja el color: rojo o negro: ");
				gets(j->CApuesta.pal);
			break;
		case 2:	printf("Escoja par o impar: ");
				gets(j->CApuesta.pal);
			break;
		case 3:	printf("Escriba pasa o falta: ");
				gets(j->CApuesta.pal);
			break;
		case 4:	printf("Escriba Numero de docena:");
				scanf("%d",j->CApuesta.N);
			break;
		case 5:	printf("Escriba primera docena:");
				scanf("%d",j->CApuesta.N);
				printf("Escriba segunda docena:");
				scanf("%d",j->CApuesta.N+1);
			break;
		case 6:	printf("Escriba numero de columna:");
				scanf("%d",j->CApuesta.N);
			break;
		case 7:	printf("Escriba primera columna:");
				scanf("%d",j->CApuesta.N);
				printf("Escriba segunda columna:");
				scanf("%d",j->CApuesta.N+1);
			break;
		case 8:	printf("Escriba los seis numeros uno por uno separados por un enter:");
				for(i=0;i<6;i++)
					scanf("%d",j->CApuesta.N+i);
			break;
		case 9:	printf("Escriba los cuatro numeros uno por uno separados por un enter:");
				for(i=0;i<4;i++)
					scanf("%d",j->CApuesta.N+i);
			break;
		case 10:printf("Escriba los tres numeros uno por uno separados por un enter:");
				for(i=0;i<3;i++)
					scanf("%d",j->CApuesta.N+i);
			break;
		case 11:printf("Escriba los dos numeros uno por uno separados por un enter:");
				for(i=0;i<2;i++)
					scanf("%d",j->CApuesta.N+i);
			break;
		case 12:printf("Escriba el numero a apostar:");
				scanf("%d",j->CApuesta.N+0);
			break;
	}
	
}
///IMPRIME LOS DATOS DE LOS JUGADORES
void ImpJugador(Jugador *j){
	printf("\nNombre: %s\nDinero a apostar: %d",j->Nombre,j->Dinero);
	ImpTipoAp(j,j->TipoApue);
}
void ImpTipoAp(Jugador *j,int n){
	int i;
	switch(n){
		case 1:	printf("\nAposto por: %s",j->CApuesta.pal);
			break;
		case 2:	printf("\nAposto por: %s",j->CApuesta.pal);
			break;
		case 3:	printf("\nAposto por: %s",j->CApuesta.pal);
			break;
		case 4:	printf("\nAposto por docena: %d",*j->CApuesta.N);
			break;
		case 5:	printf("\nAposto por docena %d y %d ",*(j->CApuesta.N),*(j->CApuesta.N+1));
			break;
		case 6:	printf("\nAposto por columna: %d",*j->CApuesta.N);
			break;
		case 7:	printf("\nAposto por columna %d y %d ",*(j->CApuesta.N),*(j->CApuesta.N+1));
			break;
		case 8:	printf("\nAposto por la seisena:  ");
				for(i=0;i<6;i++)
					printf("%d ",*(j->CApuesta.N+i));
			break;
		case 9:	printf("\nAposto por el cuadro: ");
				for(i=0;i<4;i++)
					printf("%d ",*(j->CApuesta.N+i));
			break;
		case 10:printf("\nAposto por la transversal:");
				for(i=0;i<3;i++)
					printf("%d ",*(j->CApuesta.N+i));
			break;
		case 11:printf("\nAposto por el caballo: ");
				for(i=0;i<2;i++)
					printf("%d",*(j->CApuesta.N+i));
			break;
		case 12:printf("\nAposto por el pleno: ");
				printf("%d",*j->CApuesta.N);
			break;
	}
	
}
///REGRESA EL NUMERO DE DOCENA EN LA QUE PERTENECE EL NUMERO MANDADO
int NumDocena(int n){
	if((n>=0)&&(n<=12))
		return 1;
	else if((n>=13)&&(n<=24))
			return 2;
		else if((n>=25)&&(n<=36))
				return 3;
}
///REGRESA EL NUMERO DE LA COLUMNA EN LA CUAL ESTA UBICADO
int NumColum(int n){
	//n pertenece a la columna 3
	if(n%3==0)
		return 3;
	//n pertenece a la columna 2
	else if(n%3==2)
		return 2;
		//n pertenece a la columna 1
			else if(n%3==1)
				return 1;
}
///REGRESARA LA CADENA "pasa"o"falta" DEPENDIENDO DEL CASO
char* PasaoFalta(int n){
	if((n>=0)&&(n<=18))
		return leecad("pasa");
	else return leecad("falta");	
}
///REGRESA LA CADENA "par"o "impar" DEPENDIENDO DEL NUMERO
char* ParoImp(int n){
	if(n%2)
		return leecad("impar");
	else return leecad("par");
}
///RESERVA MEMORIA DINAMICA A UNA CADENA
char* leecad(char* r){
	char *c=(char*)malloc(strlen(r)+1);
	strcpy(c,r);
	return c;
}
