/*
 * validation.c
 *
 *  Created on: 24 abr. 2020
 *      Author: pocho
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LEN_ARRAY 4096

int isChar (char* cadena)
{
	int i=0;
	int ret=0 ;
	if(cadena != NULL)
	{
		for(i=0; cadena[i]!= '\0' ; i++)
		{
			if(cadena[i] >='A' && cadena[i] <='z')
			{
				continue;
			}
			if(cadena[i]>='0' && cadena[i]<='9')
			{
				break;
			}

		}
		if(cadena[i]=='\0')
		{
			ret=1;
		}


	}

	return ret;
}

int isNumber(char *cadena) {
	int ret=0;
	int i;
	if (cadena != NULL) {
		for (i = 0; cadena[i] != '\0'; i++) {
			if (i == 0 && cadena[i] == '-') {
				continue;
			}
			if(cadena[i]>='0' && cadena[i] <='9'){
				continue;
			}
			if ((cadena[i] <= '~' && cadena[i] >= ':')|| (cadena[i]<='/' && cadena[i]>='!')) //lo que hice fue poner como invalidos
			{
				break;
			}
		}
		if (cadena[i] == '\0') {
			ret = 1;
		}
	}
	return ret;
}
int getInt(int *pResultado) {
	int ret = 0;
	char buffer[LEN_ARRAY];
	if (pResultado != NULL) {
		fflush(stdin);
		buffer[LEN_ARRAY] = '\0';
		fgets(buffer, LEN_ARRAY, stdin);
		if (isNumber(buffer)) {
			*pResultado = atoi(buffer);
			ret = 1;
		}
	}

	return ret;
}

int getLong(long long int *pResultado) {
	int ret = 0;
	char buffer[LEN_ARRAY];
	if (pResultado != NULL) {
		fflush(stdin);
		buffer[LEN_ARRAY] = '\0';
		fgets(buffer, LEN_ARRAY, stdin);
		if (isNumber(buffer)) {
			*pResultado = atoll(buffer);
			ret = 1;
		}
	}

	return ret;
}
int isDecimalNumber(char *cadena) {
	int i;
	int ret = 1;
	if (cadena != NULL) {
		for (i = 0; cadena[i] != '\0'; i++) {
			if ((i == 0 && cadena[i] == '-') || cadena[i] == '.') {
				continue;
			}
			if (cadena[i] < '0' || cadena[i] > '9') {
				ret = -1;
				break;
			}
		}

	}
	return ret;
}
int getFloat(float *pResultado) {
	int ret = -1;
	char buffer[LEN_ARRAY];
	if (pResultado != NULL) {
		fflush(stdin);
		fgets(buffer, LEN_ARRAY, stdin);
		if (isDecimalNumber(buffer)) {
			*pResultado = atof(buffer);
			ret = 1;
		}
	}
	return ret;
}
