/*
 * informes.c
 *
 *  Created on: 16 may. 2020
 *      Author: pocho
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "informes.h"
static int menuReportsClient();

static int menuReportsClient(){
	int option;

	printf("INFORMES DE CLIENTES\n\n");
	printf("1- Clientes con mas prestamos activos\n");
	printf("2- Clientes con mas prestamos saldados\n");
	printf("3- volver\n");
	getNumber(&option,"\n","Error, opcion invalida\n",1,3,2);
	return option;
}


int printLoansWithCUIL(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan){
	int ret = 0;


	if(listCli != NULL && lenCli >0 && listLoan != NULL && lenLoan > 0){
		printf("ID		CUIL DEL CLIENTE		IMPORTE		COUTAS\n\n");
		for(int i=0;i<lenCli;i++){
			if(listCli[i].isEmpty == 0){
				for(int j=0;j<lenLoan;j++){
					if(listLoan[j].idClient == listCli[i].id && listLoan[j].status == 1){
						printf("%d		%I64d			%8.2f	%d	\n", listLoan[j].id, listCli[i].cuil,
												listLoan[j].amount, listLoan[j].payments);
						printf("_____________________________________________________________________\n");
						ret = 1;
					}
				}
			}
		}

	}

	return ret;
}


int printClientsWithLoan(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan){
	int ret = 0;
	int i;
	int j;
	if(listCli != NULL && lenCli >0 && listLoan != NULL && lenLoan > 0){
			for(i=0;i<lenCli;i++){
				if(listCli[i].isEmpty == 0){
					printLoadedClient(listCli,lenCli,i);
					printf("--------------------PRESTAMOS ACTIVOS DEL CLIENTE--------------------\n");
					printf("ID		IMPORTE		COUTAS		ESTADO\n\n");
					for(j=0;j<lenLoan;j++){
						if(listLoan[j].idClient == listCli[i].id && listLoan[j].status == 1){
							printf("%d		%.2f		%d		%d	\n", listLoan[j].id, listLoan[j].amount, listLoan[j].payments,listLoan[j].status);
							ret = 1;
						}
					}printf("_____________________________________________________________________\n");
				}
			}
		}

	return ret;
}
int printLoanByClient(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan, int id){
	int ret = 0;
	int i;
	int j;

	if(listCli != NULL && lenCli >0 && listLoan != NULL && lenLoan > 0){
		for(i=0;i<lenCli;i++){
			if(listCli[i].isEmpty == 0 && listCli[i].id == id){
				printf("ID		IMPORTE		COUTAS		ESTADO\n\n");
				for(j=0;j<lenLoan;j++){
					if(listLoan[j].idClient == listCli[i].id && listLoan[j].status == 1){
						printf("%d		%.2f		%d		%d	\n", listLoan[j].id, listLoan[j].amount, listLoan[j].payments,listLoan[j].status);
						ret = 1;
					}
				}
			}
		}
	}

	return ret;
}

int removeClient(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan){
	int ret = 0;
	int bufferId;
	char respuesta[10];
	if(listCli != NULL && lenCli >0 && listLoan != NULL && lenLoan > 0){
		getNumber(&bufferId,"Ingrese el id del cliente","Error, id invalido",1,50,2);
		printLoanByClient(listCli,lenCli,listLoan,lenLoan,bufferId);

		getString(respuesta, "Confirma dar de BAJA?\n [SI/NO]\n",
							"Opcion incorrecta\n", 10, 2);
				strupr(respuesta);
				if (strcmp(respuesta, "SI") == 0) {
					listCli[bufferId-1].isEmpty = 1;
					printf("BAJA hecha\n");
					ret = 1;
				} else if (strcmp(respuesta, "NO") == 0) {
					printf("BAJA anulada\n");
				}

	}
	return ret;
}

int payOffLoan(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan){
	int ret = 0;
	int bufferId;
	char answer[10];
	if(listCli != NULL && lenCli >0 && listLoan != NULL && lenLoan > 0){
		getNumber(&bufferId,"Ingrese el id del prestamo","Error, id invalido",1,50,2);
		printLoadedClient(listCli,lenCli,bufferId-1);

		getString(answer, "Confirma dar como saldado?\n [SI/NO]\n",
									"Opcion incorrecta\n", 10, 2);
		strupr(answer);
		if (strcmp(answer, "SI") == 0) {
			listLoan[bufferId-1].status = 0;
			printf("modificacion hecha\n");
			ret = 1;
		} else if (strcmp(answer, "NO") == 0) {
			printf("modificacion anulada\n");
		}


	}

	return ret;
}

int resumeLoan(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan){
	int ret = 0;
	int bufferId;
	char answer[10];
	if(listCli != NULL && lenCli >0 && listLoan != NULL && lenLoan > 0){
		getNumber(&bufferId,"Ingrese el id del prestamo","Error, id invalido",1,50,2);
		printLoadedClient(listCli,lenCli,bufferId-1);

		getString(answer, "Confirma reanudar el prestamo?\n [SI/NO]\n",
									"Opcion incorrecta\n", 10, 2);
		strupr(answer);
		if (strcmp(answer, "SI") == 0) {
			listLoan[bufferId-1].status = 1;
			printf("modificacion hecha\n");
			ret = 1;
		} else if (strcmp(answer, "NO") == 0) {
			printf("modificacion anulada\n");
		}


	}

	return ret;
}

int reportClient(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan){
	int ret = 0;
	int option;

	if(listCli != NULL && lenCli >0 && listLoan != NULL && lenLoan > 0){
		do{
			option= menuReportsClient();
			switch(option){
				case 1:
					clientWithMoreLoansActive(listCli,lenCli,listLoan,lenLoan);
					break;
				case 2:
					clientWithMoreLoansPayOff(listCli,lenCli,listLoan,lenLoan);
					break;
				case 3:
					break;
			}
		}while(option!= 3);
	}


	return ret;
}

int clientWithMoreLoansActive(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan){
	int ret = 0;
	int i,j;
	int idMax;
	int countMax;
	int countLoan = 0;
	if(listCli != NULL && lenCli >0 && listLoan != NULL && lenLoan > 0){
		for(i=0;i<lenCli;i++){
			if(listCli[i].isEmpty == 0){
				for(j=0;j<lenLoan;j++){
					if(i==0 || (countLoan > countMax)){
						idMax = listCli[i].id;
						countMax = countLoan;
					}
					if(listLoan[j].idClient == listCli[i].id && listLoan[j].status == 1){
						countLoan++;
					}
				}
				countLoan = 0;
			}
		}

		printLoadedClient(listCli,lenCli,idMax-1);
		ret = 1;
	}

	return ret;

}

int clientWithMoreLoansPayOff(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan){
	int ret = 0;
	int i,j;
	int idMax;
	int countMax;
	int countLoan = 0;
	if(listCli != NULL && lenCli >0 && listLoan != NULL && lenLoan > 0){
		for(i=0;i<lenCli;i++){
			if(listCli[i].isEmpty == 0){
				for(j=0;j<lenLoan;j++){
					if(i==0 || (countLoan > countMax)){
						idMax = listCli[i].id;
						countMax = countLoan;
					}
					if(listLoan[j].idClient == listCli[i].id && listLoan[j].status == 0){
						countLoan++;
					}
				}
				countLoan = 0;
			}
		}

		printLoadedClient(listCli,lenCli,idMax-1);
		ret = 1;
	}

	return ret;
}

int reportLoans(sLoan* list, int len){
	int ret = 0;
	int i;
	printf("ID		ID DEL CLIENTE		IMPORTE		COUTAS\n\n");
	for(i=0;i<len;i++){
		if(list[i].amount > 1000 && list[i].status == 1){
				printf("%d		%d			%10.2f	%d	\n", list[i].id, list[i].idClient,
									list[i].amount, list[i].payments);
				printf("_____________________________________________________________________\n");
		}
	}


	return ret;
}
