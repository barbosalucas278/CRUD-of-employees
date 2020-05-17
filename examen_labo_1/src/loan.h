/*
 * loan.h
 *
 *  Created on: 16 may. 2020
 *      Author: Lucas Barbosa
 */

#ifndef LOAN_H_
#define LOAN_H_
typedef struct{
	int id;
	int idClient;
	float amount;
	int payments;
	int status;
}sLoan;


#endif /* LOAN_H_ */
int initLoans(sLoan* list,int len);
int printLoadedLoan(sLoan* list,int len, int id);
int addDataLoan(sLoan* list,int len, int* pId);
sLoan newLoan(int idClient, float amount, int payments, int id);
