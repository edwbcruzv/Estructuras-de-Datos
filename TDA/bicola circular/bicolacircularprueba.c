#include<stdio.h>
#include"bicolacircular.h"

int main(){
	int i;
	BiColaC bcc=FormarBCC(FormarBCC(FormarBCC(FormarBCC(FormarBCC(FormarBCC(FormarBCC(FormarBCC(FormarBCC(NuevaBCC(),2),4),6),11),15),19),22),23),49);
	ImpBiColaC(bcc);
	printf("\n\n\n");
	/*
	for(i=0;i<8;i++){
	bcc=DesformarBCCI(bcc);
	ImpBiColaC(bcc);
	printf("\n\n");
	}
	*/
	
	//rotacion derecha---------------------
	/*
	for(i=0;i<9;i++){
	bcc=RotarBCCDer(bcc);
	ImpBiColaC(bcc);
	printf("\n\n");
	}  */
	printf("------------------------------------------------------------------------------------\n\n");
	//rotacion izquierda------------------
	for(i=0;i<15;i++){
	bcc=RotarBCCIzq(bcc);
	ImpBiColaC(bcc);
	printf("\n\n");
	}
	
	return 0;
}