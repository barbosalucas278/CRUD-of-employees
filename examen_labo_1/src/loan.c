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

int initLoans(sLoan* list,int len){
	int ret = 0;
		int i;
		if(list != NULL && len >0){
			for(i=0;i<len;i++){
				list[i].status = -1;
				list[i].amount = 0;
				list[i].payments = 0;
			}
			ret = 1;
		}
		return ret;
}

int printLoadedLoan(sLoan* list,int len, int id){
	int ret = 0;
	int i;

	if(list != NULL && len > 0 && id >= 0){
		printf("ID		ID DEL CLIENTE		IMPORTE		COUTAS\n\n");
		for (i = 0; i < len; i++) {
			if (list[i].status == 1 && list[i].id == id +1 ) {
				printf("%d		%d			%.2f		%d	\n", list[i].id, list[i].idClient,
						list[i].amount, list[i].payments);
				ret = 1;
				break;
			}
		}
	}

	return ret;
}

sLoan newLoan(int idClient, float amount, int payments, int id){
	sLoan auxLoan;

	auxLoan.idClient = idClient;
	auxLoan.amount = amount;
	auxLoan.payments = payments;
	auxLoan.id = id +1 ;
	auxLoan.status = 1;

	return auxLoan;
}

int addDataLoan(sLoan* list,int len, int* pId){
  int ret = 0;
  int bufferIdClient;
  float bufferAmount;
  int bufferPayments;

  if(list != NULL && len > 0){
	  getNumber(&bufferIdClient,"Ingrese el Id del cliente","Error, id invalido\n",1,50,2);
	  getNumberDecimal(&bufferAmount,"Ingrese el importe del prestamo","Error, importe invalido",1000,30000,2);
	  getNumber(&bufferPayments,"Ingrese las cuotas del rpestamos","Error, cuotas invalidas",3,12,2);

	  list[*pId] = newLoan(bufferIdClient, bufferAmount,bufferPayments,*pId);
	  printLoadedLoan(list,len,*pId);
	  *pId = *pId +1;
	  ret = 1;
  }

  return ret;
}





