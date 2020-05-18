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


int main(void) {
	setbuf(stdout,NULL);
	int option;
	sClient clients[MAX_CLIENT];
	sLoan loans[MAX_LOAN];
	int idClient = 0;
	int idLoan = 0;

	initClient(clients,MAX_CLIENT);
	initLoans(loans,MAX_LOAN);
	do{
		system("CLS");
		option = menu();
		switch(option){
		case 1:
			addDataClient(clients,MAX_CLIENT,&idClient);
			break;
		case 2:
			if(idClient > 0){
				modifyClient(clients,MAX_CLIENT);
			}else{
				printf("primero debe ingresar un cliente");
			}
			break;
		case 3:
			if(idClient > 0){
				removeClient(clients,MAX_CLIENT,loans,MAX_LOAN);
			}else{
				printf("primero debe ingresar un cliente");
			}
			break;
		case 4:
			addDataLoan(loans,MAX_LOAN,&idLoan);
			for(int i=0;i<MAX_LOAN;i++){
				printf("%d\n",loans[i].status.id);
			}
			break;
		case 5:
			if(idLoan > 0){
				payOffLoan(clients,MAX_CLIENT,loans,MAX_LOAN);
			}else{
				printf("primero debe dar de alta un prestamo");
			}
			break;
		case 6:
			if(idLoan > 0){
				resumeLoan(clients,MAX_CLIENT,loans,MAX_LOAN);
			}else{
				printf("primero debe dar de alta un prestamo");
			}
			break;
		case 7:
			if(idClient > 0){
				printClientsWithLoan(clients,MAX_CLIENT,loans,MAX_LOAN);
			}else{
				printf("primero debe ingresar un cliente");
			}
			break;
		case 8:
			if(idLoan > 0){
				printLoansWithCUIL(clients,MAX_CLIENT,loans,MAX_LOAN);
			}else{
				printf("primero debe ingresar un cliente");
			}
			break;
		case 9:
			if(idClient > 0){
				reportClient(clients,MAX_CLIENT,loans,MAX_LOAN);
			}else{
				printf("primero debe ingresar un cliente");
			}
			break;
		case 10:
			if(idLoan > 0){
				reportLoans(loans,MAX_LOAN);
			}else{
				printf("primero debe ingresar un cliente");
			}
			break;
		case 11:
			break;
		}

	}while(option != 11);

	return 0;
}


