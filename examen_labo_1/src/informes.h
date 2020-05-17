/*
 * informes.h
 *
 *  Created on: 16 may. 2020
 *      Author: pocho
 */
#include "loan.h"
#include "client.h"
#include <string.h>
#ifndef INFORMES_H_
#define INFORMES_H_



#endif /* INFORMES_H_ */
int removeClient(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan);
int payOffLoan(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan);
int printLoanByClient(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan, int id);
int resumeLoan(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan);
int printClientsWithLoan(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan);
int printLoansWithCUIL(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan);
int clientWithMoreLoansActive(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan);
int clientWithMoreLoansPayOff(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan);
int reportClient(sClient* listCli,int lenCli, sLoan* listLoan, int lenLoan);
int reportLoans(sLoan* list, int len);
