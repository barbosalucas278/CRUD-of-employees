/*
 ============================================================================
 Name        : examen_labo_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "validation.h"
#include "informes.h"
#define MAX_CLIENT 50
#define MAX_LOAN 50

void hardcodeClientes(sClient* list,int len);
void hardcodePrestamos(sLoan* list,int len);

int main(void) {
	setbuf(stdout,NULL);
	int option;
	sClient clients[MAX_CLIENT];
	sLoan loans[MAX_LOAN];
	int idClient = 0;
	int idLoan = 0;

	initClient(clients,MAX_CLIENT);
	initLoans(loans,MAX_LOAN);
	hardcodeClientes(clients,MAX_CLIENT);
	hardcodePrestamos(loans,MAX_LOAN);
	do{
		option = menu();
		switch(option){
		case 1:
			addDataClient(clients,MAX_CLIENT,&idClient);
			break;
		case 2:
			modifyClient(clients,MAX_CLIENT);
			break;
		case 3:
			removeClient(clients,MAX_CLIENT,loans,MAX_LOAN);
			break;
		case 4:
			addDataLoan(loans,MAX_LOAN,&idLoan);
			break;
		case 5:
			payOffLoan(clients,MAX_CLIENT,loans,MAX_LOAN);
			break;
		case 6:
			resumeLoan(clients,MAX_CLIENT,loans,MAX_LOAN);
			break;
		case 7:
			printClientsWithLoan(clients,MAX_CLIENT,loans,MAX_LOAN);
			break;
		case 8:
			printLoansWithCUIL(clients,MAX_CLIENT,loans,MAX_LOAN);
			break;
		case 9:
			reportClient(clients,MAX_CLIENT,loans,MAX_LOAN);
			break;
		case 10:
			reportLoans(loans,MAX_LOAN);
			break;
		case 11:
			break;
		}

	}while(option != 11);

	return 0;
}

void hardcodeClientes(sClient* list,int len){
	sClient aux[5] = {{1,"Lucas","Barbosa",20111111115,0}
					 ,{2,"Nahuel","Barbosa",2022222225,0}
					 ,{3,"Victoria","Garavano",20333333335,0}
					 ,{4,"Martina","Barbosa",20444444445,0}
					 ,{5,"Analia","Garcia",20555555557,0}};
	int i;
	for(i=0;i<5;i++){
		list[i] = aux[i];
	}
}

void hardcodePrestamos(sLoan* list,int len){
	sLoan aux[10] =   {{1,1,500,3,1}
					 ,{2,1,21000,6,1}
					 ,{3,2,12000,6,1}
					 ,{4,3,28000,9,1}
					 ,{5,4,5000,3,1}
	 	 	 	 	 ,{6,5,29000,9,0}
					 ,{7,5,15000,12,0}
					 ,{8,3,28000,6,1}
					 ,{9,2,15000,3,1}
					 ,{10,1,24000,3,1}};
	int i;
	for(i=0;i<10;i++){
		list[i] = aux[i];
	}
}
