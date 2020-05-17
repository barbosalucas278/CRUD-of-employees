/*
 * cliente.h
 *
 *  Created on: 16 may. 2020
 *      Author: Lucas Barbosa
 */

#ifndef CLIENT_H_
#define CLIENT_H_
typedef struct{
	int id;
	char name[51];
	char lastName[51];
	long long int cuil;
	int isEmpty;
}sClient;

#endif /* CLIENT_H_ */

int initClient(sClient* list,int len);
int printLoadedClient(sClient* list,int len,int id);
int addDataClient(sClient* list, int len, int* pId);
sClient newClient(char* name,char* lastName,long long int cuil,int id);
int modifyClient(sClient* list, int len);

