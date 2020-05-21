/*
 * loan.c
 *
 *  Created on: 16 may. 2020
 *      Author: Lucas Barbosa
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "informes.h"

/*
 * \brief initialize an sLoan array
 * \param list sloan* Pointer to array of sLoan.
 * \param len int Array lenght.
 * \return Return (0) if Error [Invalir lengt or NULL pointer] - (1) if Ok
 *
 * */
int initLoans(sLoan* list,int len){
	int ret = 0;
	int i;
	sStatus status = {-1,"inactivo"};

		if(list != NULL && len >0){
			for(i=0;i<len;i++){
				list[i].status = status;
				list[i].amount = 0;
				list[i].payments = 0;
			}
			ret = 1;
		}
		return ret;
}
/*
 * \brief print a sLoan based on the ID entered
 * \param list sLoan* Pointer to array of sLoan.
 * \param len int Array lenght.
 * \param id int
 * \return Return (0) if Error [Invalir lengt or NULL pointer or if can't find a client] - (1) if Ok
 *
 * */

int printLoadedLoan(sLoan* list,int len, int id){
	int ret = 0;
	int i;

	if(list != NULL && len > 0 && id >= 0){
		printf("ID		ID DEL CLIENTE		IMPORTE		COUTAS\n\n");
		for (i = 0; i < len; i++) {
			if (list[i].status.id == 1 && list[i].id == id +1 ) {
				printf("%d		%d			%.2f		%d	\n", list[i].id, list[i].idClient,
						list[i].amount, list[i].payments);
				ret = 1;
				break;
			}
		}
	}

	return ret;
}
/*
 * \brief loads a sLoan and returns it with its loaded values
 * \param list sLoan* Pointer to array of sLoan.
 * \param len int Array lenght.
 * \param id int
 * \return Return auxLoan sloan
 *
 * */
sLoan newLoan(int idClient, float amount, int payments, int id){
	sLoan auxLoan;
	sStatus status = {1,"activo"};

	auxLoan.idClient = idClient;
	auxLoan.amount = amount;
	auxLoan.payments = payments;
	auxLoan.id = id +1 ;
	auxLoan.status = status;

	return auxLoan;
}
/*
 * \brief asks the user for the data they want to upload
 * \param list sLoan* Pointer to array of sLoan.
 * \param len int Array lenght.
 * \param id int
 * \return Return (0) if Error [Invalir lengt or NULL pointer] - (1) if Ok
 *
 * */
int addDataLoan(sLoan* list,int len, int* pId){
  int ret = 0;
  int bufferIdClient;
  float bufferAmount;
  int bufferPayments;

  if(list != NULL && len > 0 && pId != NULL){
	  system("CLS");
	  getNumber(&bufferIdClient,"Ingrese el Id del cliente\n","Error, id invalido\n",1,50,2);
	  getNumberDecimal(&bufferAmount,"Ingrese el importe del prestamo\n","Error, importe invalido entre 1000 y 30000\n",1000,30000,2);
	  getNumber(&bufferPayments,"Ingrese las cuotas del rpestamos\n","Error, cuotas invalidas",3,12,2);

	  list[*pId] = newLoan(bufferIdClient, bufferAmount,bufferPayments,*pId);
	  printLoadedLoan(list,len,*pId);
	  *pId = *pId +1;
		system("PAUSE");
		system("CLS");
	  ret = 1;
  }

  return ret;
}





