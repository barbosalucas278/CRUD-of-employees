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
static int menuReportsLoans();

/*
 * \brief function to create a menu of options.
 * \return int returns the chosen option.
 * */
static int menuReportsLoans(){
	int option;

	printf("INFORMES DE PRESTAMOS\n\n");
	printf("1- Cantidad de préstamos de importe mayor a :(monto ingresado)\n");
	printf("2- Préstamos de 12 cuotas saldados\n");
	printf("3- Préstamos por cuotas \n");
	printf("4- volver\n");
	getNumber(&option,"\n","Error, opcion invalida\n",1,4,2);
	return option;
}

/*
 * \brief function to create a menu of options.
 * \return int returns the chosen option.
 * */
static int menuReportsClient(){
	int option;

	printf("INFORMES DE CLIENTES\n\n");
	printf("1- Clientes con mas prestamos activos\n");
	printf("2- Clientes con mas prestamos saldados\n");
	printf("3- Clientes con mas prestamos \n");
	printf("4- volver\n");
	getNumber(&option,"\n","Error, opcion invalida\n",1,4,2);
	return option;
}

/*
 * \brief print active loans with the client's cuil
 * \param listCli sClient*
 * \param lenCli int
 * \param listLoan sLoan*
 * \param lenLoan int
 * \return Return (0) if Error [Invalir lengt or NULL pointer] - (1) if Ok
 *
 * */
int printLoansWithCUIL(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan){
	int ret = 0;


	if(listCli != NULL && lenCli >0 && listLoan != NULL && lenLoan > 0){
		system("CLS");
		printf("ID		CUIL DEL CLIENTE		IMPORTE		COUTAS\n\n");
		for(int i=0;i<lenCli;i++){
			if(listCli[i].isEmpty == 0){
				for(int j=0;j<lenLoan;j++){
					if(listLoan[j].idClient == listCli[i].id && listLoan[j].status.id == 1){
						printf("%d		%10s			%8.2f	%d	\n", listLoan[j].id, listCli[i].cuil,
												listLoan[j].amount, listLoan[j].payments);
						printf("_____________________________________________________________________\n");
						ret = 1;
					}
				}
			}
		}
		system("PAUSE");
		system("CLS");
	}

	return ret;
}

/*
 * \brief print active clients with yours loans active
 * \param listCli sClient*
 * \param lenCli int
 * \param listLoan sLoan*
 * \param lenLoan int
 * \return Return (0) if Error [Invalir lengt or NULL pointer] - (1) if Ok
 *
 * */
int printClientsWithLoan(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan){
	int ret = 0;
	int i;
	int j;

	if(listCli != NULL && lenCli >0 && listLoan != NULL && lenLoan > 0){
		system("CLS");
			for(i=0;i<lenCli;i++){
				if(listCli[i].isEmpty == 0){
					printLoadedClient(listCli,lenCli,i);
					printf("--------------------PRESTAMOS ACTIVOS DEL CLIENTE--------------------\n");
					printf("ID		IMPORTE		COUTAS		ESTADO\n\n");
					for(j=0;j<lenLoan;j++){
						if(listLoan[j].idClient == listCli[i].id && listLoan[j].status.id == 1){
							printf("%d		%.2f		%d		%s	\n", listLoan[j].id, listLoan[j].amount, listLoan[j].payments,listLoan[j].status.typeStatus);
							ret = 1;
						}
					}printf("_____________________________________________________________________\n");
				}
			}
			system("PAUSE");
			system("CLS");
		}

	return ret;
}
/*
 * \brief print active clients with yours loans.
 * \param listCli sClient*
 * \param lenCli int
 * \param listLoan sLoan*
 * \param lenLoan int
 * \param id int
 * \return Return (0) if Error [Invalir lengt or NULL pointer] - (1) if Ok
 *
 * */
int printLoanByClient(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan, int id){
	int ret = 0;
	int i;
	int j;

	if(listCli != NULL && lenCli >0 && listLoan != NULL && lenLoan > 0 && id >=0){
		for(i=0;i<lenCli;i++){
			if(listCli[i].isEmpty == 0 && listCli[i].id == id){
				printf("ID		IMPORTE		COUTAS		ESTADO\n\n");
				for(j=0;j<lenLoan;j++){
					if(listLoan[j].idClient == listCli[i].id && listLoan[j].status.id == 1){
						printf("%d		%.2f		%d		%s	\n", listLoan[j].id, listLoan[j].amount, listLoan[j].payments,listLoan[j].status.typeStatus);
						ret = 1;
					}
				}
			}
		}
	}

	return ret;
}
/*
 * \brief remove an client by Id
 * \param listCli sClient*
 * \param lenCli int
 * \param listLoan sLoan*
 * \param lenLoan int
 * \return Return (0) if Error [Invalir lengt or NULL pointer] - (1) if Ok
 *
 * */
int removeClient(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan){
	int ret = 0;
	int bufferId;
	char respuesta[10];
	if(listCli != NULL && lenCli >0 && listLoan != NULL && lenLoan > 0){
		system("CLS");
		getNumber(&bufferId,"Ingrese el id del cliente","Error, id invalido",1,50,2);
		printLoanByClient(listCli,lenCli,listLoan,lenLoan,bufferId);

		getString(respuesta, "Confirma dar de BAJA?\n [SI/NO]\n",
							"Opcion incorrecta\n", 10, 2);
				strupr(respuesta);
				if (strcmp(respuesta, "SI") == 0) {
					listCli[bufferId-1].isEmpty = 1;
					for(int i=0;i<lenLoan;i++){
						if(listLoan[i].idClient == listCli[bufferId -1].id && listLoan[i].status.id==1){
							listLoan[i].status.id = -1;
						}
					}
					printf("BAJA hecha\n");
					ret = 1;
				} else if (strcmp(respuesta, "NO") == 0) {
					printf("BAJA anulada\n");
				}
		system("PAUSE");
		system("CLS");
	}
	return ret;
}

/*
 * \brief establish a loan by id in "paid" status
 * \param listCli sClient*
 * \param lenCli int
 * \param listLoan sLoan*
 * \param lenLoan int
 * \return Return (0) if Error [Invalir lengt or NULL pointer] - (1) if Ok
 *
 * */
int payOffLoan(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan){
	int ret = 0;
	int bufferId;
	char answer[10];
	int i;
	if(listCli != NULL && lenCli >0 && listLoan != NULL && lenLoan > 0){
		system("CLS");
		getNumber(&bufferId,"Ingrese el id del prestamo\n","Error, id invalido",1,50,2);
		for(i=0;i<lenLoan;i++){
			if(listLoan[i].id == bufferId && listLoan[i].status.id == 1){
				printLoadedClient(listCli,lenCli,listLoan[i].idClient-1);

			}
		}
		getString(answer, "Confirma dar como saldado?\n [SI/NO]\n",
									"Opcion incorrecta\n", 10, 2);
		strupr(answer);
		if (strcmp(answer, "SI") == 0) {
			listLoan[bufferId-1].status.id = 0;
			printf("modificacion hecha\n");
			ret = 1;
		} else if (strcmp(answer, "NO") == 0) {
			printf("modificacion anulada\n");
		}
	}
	system("PAUSE");

	return ret;
}

/*
 * \brief establish a loan by id in "active" status
 * \param listCli sClient*
 * \param lenCli int
 * \param listLoan sLoan*
 * \param lenLoan int
 * \return Return (0) if Error [Invalir lengt or NULL pointer] - (1) if Ok
 *
 * */
int resumeLoan(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan){
	int ret = 0;
	int bufferId;
	char answer[10];
	int i;
	if(listCli != NULL && lenCli >0 && listLoan != NULL && lenLoan > 0){
		system("CLS");
		getNumber(&bufferId,"Ingrese el id del prestamo","Error, id invalido",1,50,2);
		for(i=0;i<lenLoan;i++){
					if(listLoan[i].id == bufferId && listLoan[i].status.id == 0){
						printLoadedClient(listCli,lenCli,listLoan[i].idClient-1);

					}
				}

		getString(answer, "Confirma reanudar el prestamo?\n [SI/NO]\n",
									"Opcion incorrecta\n", 10, 2);
		strupr(answer);
		if (strcmp(answer, "SI") == 0) {
			listLoan[bufferId-1].status.id = 1;
			printf("modificacion hecha\n");
			ret = 1;
		} else if (strcmp(answer, "NO") == 0) {
			printf("modificacion anulada\n");
		}
		system("PAUSE");

	}

	return ret;
}

/*
 * \brief customer reporting section
 * \param listCli sClient*
 * \param lenCli int
 * \param listLoan sLoan*
 * \param lenLoan int
 * \return Return (0) if Error [Invalir lengt or NULL pointer] - (1) if Ok
 *
 * */
int reportClient(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan){
	int ret = 0;
	int option;

	if(listCli != NULL && lenCli >0 && listLoan != NULL && lenLoan > 0){
		do{
			system("CLS");
			option= menuReportsClient();
			switch(option){
				case 1:
					clientWithMoreLoansActive(listCli,lenCli,listLoan,lenLoan);
					break;
				case 2:
					clientWithMoreLoansPayOff(listCli,lenCli,listLoan,lenLoan);
					break;
				case 3:
					clientWithMoreLoan(listCli,lenCli,listLoan,lenLoan);
					break;
				case 4:
					break;
			}
		}while(option!= 4);
	}


	return ret;
}

int clientWithMoreLoan(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan){
	int ret = 0;
	int i,j;
	int idMax;
	int countMax;
	int countLoan = 0;
	if(listCli != NULL && lenCli >0 && listLoan != NULL && lenLoan > 0){
		system("CLS");
		for(i=0;i<lenCli;i++){
			if(listCli[i].isEmpty == 0){
				for(j=0;j<lenLoan;j++){
					if(i==0 || (countLoan > countMax)){
						idMax = listCli[i].id;
						countMax = countLoan;
					}
					if(listLoan[j].idClient == listCli[i].id){
						countLoan++;
					}
				}
				countLoan = 0;
			}
		}

		printLoadedClient(listCli,lenCli,idMax-1);
		ret = 1;
	}
	system("PAUSE");


	return ret;
}

/*
 * \brief print the client with more loans active
 * \param listCli sClient*
 * \param lenCli int
 * \param listLoan sLoan*
 * \param lenLoan int
 * \return Return (0) if Error [Invalir lengt or NULL pointer] - (1) if Ok
 *
 * */
int clientWithMoreLoansActive(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan){
	int ret = 0;
	int i,j;
	int idMax;
	int countMax;
	int countLoan = 0;
	if(listCli != NULL && lenCli >0 && listLoan != NULL && lenLoan > 0){
		system("CLS");
		for(i=0;i<lenCli;i++){
			if(listCli[i].isEmpty == 0){
				for(j=0;j<lenLoan;j++){
					if(i==0 || (countLoan > countMax)){
						idMax = listCli[i].id;
						countMax = countLoan;
					}
					if(listLoan[j].idClient == listCli[i].id && listLoan[j].status.id == 1){
						countLoan++;
					}
				}
				countLoan = 0;
			}
		}

		printLoadedClient(listCli,lenCli,idMax-1);
		ret = 1;
	}
	system("PAUSE");
	return ret;

}
/*
 * \brief print the client with more loans paid
 * \param listCli sClient*
 * \param lenCli int
 * \param listLoan sLoan*
 * \param lenLoan int
 * \return Return (0) if Error [Invalir lengt or NULL pointer] - (1) if Ok
 *
 * */
int clientWithMoreLoansPayOff(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan){
	int ret = 0;
	int i,j;
	int idMax;
	int countMax;
	int countLoan = 0;
	if(listCli != NULL && lenCli >0 && listLoan != NULL && lenLoan > 0){
		system("CLS");
		for(i=0;i<lenCli;i++){
			if(listCli[i].isEmpty == 0){
				for(j=0;j<lenLoan;j++){
					if(listLoan[j].idClient == listCli[i].id && listLoan[j].status.id == 0){
						countLoan++;
						if(i==0 || (countLoan > countMax)){
							idMax = listCli[i].id;
							countMax = countLoan;
						}
					}
				}
				countLoan = 0;
			}
		}

		printLoadedClient(listCli,lenCli,idMax-1);
		ret = 1;
	}
	system("PAUSE");

	return ret;
}

/*
 * \brief customer reporting section
 * \param listLoan sLoan*
 * \param lenLoan int
 * \return Return (0) if Error [Invalir lengt or NULL pointer] - (1) if Ok
 *
 * */
int reportLoans(sLoan* list, int len){
	int ret = 0;
	int option;
	if(list != NULL && len >0){
		do{
			option = menuReportsLoans();
			switch(option){
			case 1:
				reportLoanA(list,len);
				break;
			case 2:
				reportLoanB(list,len);
				break;
			case 3:
				reportLoanC(list,len);
				break;
			case 4:
				break;
			}
		}while(option != 4);

	}
	return ret;
}

int reportLoanA(sLoan* list, int len){
	int ret = 0;
	int i;
	int bufferAmount;

	if(list != NULL && len>0){
		system("CLS");
		getNumber(&bufferAmount,"Ingrese el monto","Error, monto invalido entre 1000 y 30000\n",1000,30000,2);
		printf("ID		ID DEL CLIENTE		IMPORTE		COUTAS\n\n");
		for(i=0;i<len;i++){
			if(list[i].amount > bufferAmount && list[i].status.id == 1){
					printf("%d		%d			%10.2f	%d	\n", list[i].id, list[i].idClient,
										list[i].amount, list[i].payments);
					printf("_____________________________________________________________________\n");
			}
		}
		ret = 1;
		system("PAUSE");

	}
	return ret;
}

int reportLoanB(sLoan* list, int len){
	int ret = 0;
	int i;

	if(list != NULL && len>0){
		system("CLS");
		printf("ID		ID DEL CLIENTE		IMPORTE		COUTAS\n\n");
		for(i=0;i<len;i++){
			if(list[i].payments == 12 && list[i].status.id == 0){
					printf("%d		%d			%10.2f	%d	\n", list[i].id, list[i].idClient,
										list[i].amount, list[i].payments);
					printf("_____________________________________________________________________\n");
			}
		}
		ret = 1;
		system("PAUSE");

	}
	return ret;
}


int reportLoanC(sLoan* list, int len){
	int ret = 0;
	int i;
	int bufferPayments;
	if(list != NULL && len>0){
		system("CLS");
		getNumber(&bufferPayments,"Ingrese la cantidad de cuotas","Error, cantidad invalida entre 3 y 12\n",3,12,2);
		printf("ID		ID DEL CLIENTE		IMPORTE		COUTAS\n\n");
		for(i=0;i<len;i++){
			if(list[i].payments == bufferPayments && list[i].status.id == 1){
					printf("%d		%d			%10.2f	%d	\n", list[i].id, list[i].idClient,
										list[i].amount, list[i].payments);
					printf("_____________________________________________________________________\n");
			}
		}
		ret = 1;
		system("PAUSE");

	}
	return ret;
}
