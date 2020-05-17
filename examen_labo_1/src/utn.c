/*
 * utn.c
 *
 *  Created on: 11 abr. 2020
 *      Author: pocho
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "validation.h"
#include "utn.h"
#define LEN_ARRAY 4096

/*
 * \brief funcion para crear un menu de opciones.
 * \return int retorna la opcion elegida.
 * */
int menu()
{
		int option;
		printf("   MENU DE OPCIONES\n\n");
		printf("1- Alta cliente\n");
		printf("2- Modificar cliente\n");
		printf("3- Baja cliente\n");
		printf("4- Alta prestamo\n");
		printf("5- Saldar prestamo\n");
		printf("6- Reanudar prestamo\n");
		printf("7- Imprimir clientes\n");
		printf("8- Imprimir prestamos\n");
		printf("9- Informes clientes\n");
		printf("10- Informes prestamos\n");
		printf("11- Salir");
		getNumber(&option,"\n\n","ERROR, opcion incorrecta",1,11,2);

		return option;

}

int printArrayStr (char* pArray, int size)
{
	int ret = 0;
	int i;
	if(pArray != NULL && size > 0)
	{
		for(i=0;i<size;i++)
		{
			printf("El indice [%d] tiene como valor %d\n",i,pArray[i]);
		}
	}
	return ret;
}

int printArrayFloat(float *pArrayFloat, int sizeFloat) {
	int i;
	int ret = -1;

	if (pArrayFloat != NULL && sizeFloat >0) {
		for (i = 0; i < sizeFloat; i++) {
			printf("El indice [%d] tiene como Valor %.2f\n", i,pArrayFloat[i]);
		}
		ret = 0;
	}

	return ret;
}

int printArrayIntFloat(int *pArray, int size, float *pArrayFloat, int sizeFloat) {
	int i;
	int ret = -1;

	if (pArray != NULL && size > 0 && pArrayFloat != NULL && sizeFloat >0) {
		for (i = 0; i < size; i++) {
			printf("El indice [%d] tiene como Edad %d y nota %.2f\n", i, pArray[i],pArrayFloat[i]);
		}
		ret = 0;
	}

	return ret;
}

int promedioArray (int* pArray,int size,int* pArray2, int size2,float* pPromedio)
{
	int ret = 0;
	int i;
	int acumulador = 0;
	float bufferPromedio;

	if(pArray != NULL && size >0 && pArray2 != NULL && size2 >0 && pPromedio != NULL)
	{
		for(i=0;	i<size;	  i++)
		{
			acumulador = pArray[i] + pArray2[i];
			bufferPromedio = acumulador / 2;
			*pPromedio=bufferPromedio;
		}
	ret = 1;
	}

	return ret;
}

int cargarArrayInt (int* pArray,int size,int indice)
{
	int ret = 0;
	int buffer;

	if(pArray != NULL && size >0)
	{
		if(getNumber(&buffer,"Ingrese un n�mero\n","ERROR\n",1,115,2))
		{
			pArray[indice] = buffer;
			ret = 1;
		}

	}

	return ret;
}

int initArrayFloat(float* pArray, int size, float pValor)
{
	int ret =0;
	int i;
	if(pArray != NULL && size>0)
	{
		for(i=0;i<size;i++)
		{
			pArray[i]= pValor;
			ret = 1;
		}
	}

	return ret;
}

int initArrayInt(int* pArray, int size, int pValor)
{
	int ret =0;
	int i;
	if(pArray != NULL && size>0)
	{
		for(i=0;i<size;i++)
		{
			pArray[i]= pValor;
			ret = 1;
		}
	}

	return ret;
}

int ordenarArrayIntFloat(int *pArrayInt, float *pArrayFloat, int size) {
	int i;
	int buffer;
	int bufferF;
	int flag = 1;
	int ret = -1;

	if (pArrayInt != NULL && pArrayFloat != NULL && size > 0) //se verifican que los valores de los arrya sno sean nulos
			{
		while (flag) {
			flag = 0; //hace que se produzcan varios ciclos de la iteración del for, asi puede ordenar varias veces hasta tener todo ordenado.
			for (i = 0; i < size - 1; i++) {
				if (pArrayInt[i] > pArrayInt[i + 1]) // realiza la comparacion con el valor del proximo indice.
				{
					//se swapea la edad si la siguiente
					buffer = pArrayInt[i];
					pArrayInt[i] = pArrayInt[i + 1];
					pArrayInt[i + 1] = buffer;
					//Se swapea el valor dle salario correspondiente al indice de la edad
					bufferF = pArrayFloat[i];
					pArrayFloat[i] = pArrayFloat[i + 1];
					pArrayFloat[i + 1] = bufferF;
					flag = 1; //esta flag me asegura que la comparacion se realice hasta que este todo ordenado.
				}
			}
			size--;
		}
		ret = 0;
	}
	return ret;
}

int ordenarArrayInt_2(int *pArray1, int *pArray2, int size) {
	int i;
	int buffer;
	int buffer2;
	int flag = 1;
	int ret = -1;

	if (pArray2 != NULL && pArray2 != NULL && size > 0) //se verifican que los valores de los arrya sno sean nulos
			{
		while (flag) {
			flag = 0; //hace que se produzcan varios ciclos de la iteración del for, asi puede ordenar varias veces hasta tener todo ordenado.
			for (i = 0; i < size - 1; i++) {
				if (pArray1[i] > pArray1[i + 1]) // realiza la comparacion con el valor del proximo indice.
				{
					//se swapea la edad si la siguiente
					buffer = pArray1[i];
					pArray1[i] = pArray1[i + 1];
					pArray1[i + 1] = buffer;
					//Se swapea el valor dle salario correspondiente al indice de la edad
					buffer2 = pArray2[i];
					pArray2[i] = pArray2[i + 1];
					pArray2[i + 1] = buffer2;
					flag = 1; //esta flag me asegura que la comparacion se realice hasta que este todo ordenado.
				}
			}
			size--;
		}
		ret = 0;
	}
	return ret;
}


int printArrayInt(int *pArray, int size) {
	int i;
	int ret = -1;

	if (pArray != NULL && size > 0) {
		for (i = 0; i < size; i++) {
			printf("El indice [%d] tiene como valor %d \n", i, pArray[i]);
		}
		ret = 0;
	}

	return ret;
}

int getNumber(int *pResultado, char *mensaje, char *mensajeError, int min,
		int max, int reintentos) {
	int ret=0;
	int num;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& min <= max && reintentos >= 0) {
		while (reintentos > 0) {
			printf("%s", mensaje);
			if (getInt(&num))  // si scanf =1 es porque pudo abrir la variable
			{
				if (num <= max && num >= min)
				{
					break;
				}
			}
			reintentos--;
			printf("%s", mensajeError);
		}
		if (reintentos > 0) {
			*pResultado = num; //se asigna en la direccion de memoria del parametro el valor del numero ingresado.
			ret = 1;
		}

	}
	return ret;
}

int getNumberDecimal(float *pResultado, char *mensaje, char *mensajeError,
		int min, int max, int reintentos) {
	int ret;
	float num;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& min <= max && reintentos >= 0) {
		while (reintentos > 0) {
			printf("%s", mensaje);
			if (getFloat(&num))  // si scanf =1 es porque pudo abrir la variable
					{
				if (num <= max && num >= min) {
					break;
				}
			}
			reintentos--;
			printf("%s", mensajeError);
		}
		if (reintentos == 0) {
			ret = -1;
		} else {
			*pResultado = num; //se asigna en la direccion de memoria del parametro el valor del numero ingresado.
			ret = 1;
		}
	}
	return ret;
}



int getChar(char *pResultado, char *mensaje, char *mensajeError, char min,
		char max, int reintentos) {
	int ret = -1;
	char bufferChar;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& min <= max && reintentos >= 0) {
		while (reintentos > 0) {
			printf("%s", mensaje);
			fflush(stdin);
			if (scanf("%c", &bufferChar)) {
				if (bufferChar >= min && bufferChar <= max) {
					break;
				}
				reintentos--;
				printf("%s", mensajeError);
			}
		}
		if (reintentos == 0) {
			printf("%s", mensajeError);
		} else {
			*pResultado = bufferChar;
			ret = 1;
		}
	}
	return ret;
}

int getString (char* cadena, char* mensaje, char* mensajeError, int len, int reintentos)
{
	int ret =0;
	char buffer [LEN_ARRAY];
	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && len >0 && reintentos >=0)
	{
		while(reintentos > 0)
		{
			printf("%s",mensaje);
			fflush(stdin);
			fgets(buffer,LEN_ARRAY,stdin);
			buffer[strlen(buffer)-1] = '\0';
			if(isChar(buffer))
			{
				if(strlen(buffer) == 1)
				{
					reintentos--;
					printf("%s",mensajeError);
					continue;
				}
				if(strlen(buffer) == 0)
				{
					reintentos--;
					printf("%s",mensajeError);
					continue;
				}
				if(strlen(buffer) <= len)
				{
					break;
				}
			}
			else
			{
				reintentos--;
				printf("%s",mensajeError);
			}
		}
		if(reintentos > 0)
		{
			strcpy(cadena , buffer);
			ret = 1;
		}
	}

	return ret;
}

int getCuil(long long int *pResultado, char *mensaje, char *mensajeError,
		int len, int reintentos) {
	int ret=0;
	long long int num;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& len >0 && reintentos >= 0) {
		while (reintentos > 0) {
			printf("%s", mensaje);
			if (getLong(&num))  // si scanf =1 es porque pudo abrir la variable
			{

				break;

			}
			reintentos--;
			printf("%s", mensajeError);
		}
		if (reintentos > 0) {
			*pResultado = num; //se asigna en la direccion de memoria del parametro el valor del numero ingresado.
			ret = 1;
		}

	}
	return ret;
}
