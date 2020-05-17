/*
 * cliente.c
 *
 *  Created on: 16 may. 2020
 *      Author: Lucas Barbosa
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "informes.h"

static int menuModify();
static int modifyName(sClient* list, int len, int id);
static int modifyLastName(sClient* list, int len, int id);
static int modifyCUIL(sClient* list, int len, int id);


int initClient(sClient* list,int len){
	int ret = 0;
	int i;
	if(list != NULL && len >0){
		for(i=0;i<len;i++){
			list[i].isEmpty = 1;
			list[i].cuil = 0;
		}
		ret = 1;
	}
	return ret;
}

static int menuModify(){
	int option;

	printf("MENU DE MODIFICACIONES\n\n");
	printf("1- Modificar nombre\n");
	printf("2- Modificar apellido\n");
	printf("3- Modificar CUIL\n");
	printf("4- Volver\n");
	getNumber(&option,"\n\n","ERROR, opcion incorrecta",1,4,2);

	return option;
}
/*
 * \brief find an client by ID  and returns the index position in array
 * \param list client* Pointer to array of clients.
 * \param len int Array lenght.
 * \param id int
 * \return Return (-1) if Error [Invalir lengt or NULL pointer or if can't find a client] - (0) if Ok
 *
 * */

int printLoadedClient(sClient* list,int len,int id){
	int ret = -1;
	int i;

	if(list != NULL && len > 0 && id >= 0){
		printf("\n\nID   NOMBRE   APELLIDO   CUIL\n");
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == 0 && list[i].id == id +1 ) {
				printf("%d%10s%10s    %I64d	\n\n", list[i].id, list[i].name,
						list[i].lastName, list[i].cuil);
				ret = 0;
				break;
			}
		}
	}

	return ret;
}


sClient newClient(char* name,char* lastName,long long int cuil,int id){
	sClient auxClient;

	auxClient.id = id +1;
	strcpy(auxClient.name,name);
	strcpy(auxClient.lastName,lastName);
	auxClient.cuil = cuil;
	auxClient.isEmpty = 0;

	return auxClient;
}

int addDataClient(sClient* list, int len, int* pId){
	int ret = 0;
	char bufferName[51];
	char bufferLastName[51];
	long long int bufferCUIL;

	if(list != NULL && len >0){
		getString(bufferName,"Ingrese el nombre del cliente\n","Error, nombre invalido\n",51,2);
		getString(bufferLastName,"Ingrese el apellido del cliente\n","Error, apellido invalido\n",51,2);
		getCuil(&bufferCUIL,"Ingrese el CUIL del cliente\n","Error, cuil incorrecto\n",11,2);

		list[*pId] = newClient(bufferName,bufferLastName,bufferCUIL,*pId);
		printLoadedClient(list,len,*pId);
		*pId = *pId +1;
		ret = 1;
	}

	return ret;
}


static int modifyName(sClient* list, int len, int id){
	int ret = 0;
	char buffername[51];
	char respuesta[10];

	if(list != NULL && len >0){
		getString(buffername,"Ingrese el nombre","Error, nombre invalido",51,2);
		getString(respuesta, "Confirma la modificacion\n [SI/NO]\n",
				"Opcion incorrecta\n", 10, 2);
		strupr(respuesta);
		if (strcmp(respuesta, "SI") == 0) {
			strcpy(list[id -1].name,buffername);
			printf("MODIFICACION hecha\n");

			ret = 1;
		} else if (strcmp(respuesta, "NO") == 0) {
			printf("MODIFICACION anulada\n");
		}

	}

	return ret;
}
static int modifyLastName(sClient* list, int len, int id){
	int ret = 0;
	char bufferLastName[51];
	char respuesta[10];

	if(list != NULL && len >0){
		getString(bufferLastName,"Ingrese el nombre","Error, nombre invalido",51,2);
		getString(respuesta, "Confirma la modificacion\n [SI/NO]\n",
				"Opcion incorrecta\n", 10, 2);
		strupr(respuesta);
		if (strcmp(respuesta, "SI") == 0) {
			strcpy(list[id -1].name,bufferLastName);
			printf("MODIFICACION hecha\n");

			ret = 1;
		} else if (strcmp(respuesta, "NO") == 0) {
			printf("MODIFICACION anulada\n");
		}

	}

	return ret;
}
static int modifyCUIL(sClient* list, int len, int id){
	int ret = 0;
	long long int bufferCuil;
	char respuesta[10];

	if(list != NULL && len >0){
		getCuil(&bufferCuil,"Ingrese el CUIL","Error, CUIL invalido",11,2);
		getString(respuesta, "Confirma la modificacion\n [SI/NO]\n",
				"Opcion incorrecta\n", 10, 2);
		strupr(respuesta);
		if (strcmp(respuesta, "SI") == 0) {
			list[id -1].cuil = bufferCuil;
			printf("MODIFICACION hecha\n");

			ret = 1;
		} else if (strcmp(respuesta, "NO") == 0) {
			printf("MODIFICACION anulada\n");
		}

	}

	return ret;
}
int modifyClient(sClient* list, int len){
	int ret = 0;
	int option;
	int bufferId;

	do{
		getNumber(&bufferId,"Ingrese el ID del cliente que desea modificar\n","Error, id invalido\n",1,50,2);
		printLoadedClient(list,len,bufferId-1);
		option = menuModify();
		switch(option){
		case 1:
			modifyName(list,len,bufferId);
			break;
		case 2:
			modifyLastName(list,len,bufferId);
			break;
		case 3:
			modifyCUIL(list,len,bufferId);
			break;
		case 4:
			break;
		}
	}while(option != 4);


	return ret;
}


