/*
 * validation.h
 *
 *  Created on: 24 abr. 2020
 *      Author: pocho
 */

#ifndef VALIDATION_H_
#define VALIDATION_H_
#define LEN_ARRAY 4096

#endif /* VALIDATION_H_ */

/*
 *\brief se utiliza para tomar un numero entero.
 *\param pResultado es el valor de la direccion de memoria en donde voy a guardar lo que voy a tranformar con atoi().
 *\return 1 si es un int -1 si no es un int
 */
int getInt (int* pResultado);
/*
 * brief se utiliza para validar si es un int positivo o negativo, sin ninguna otro caracter.
 *\param la cadena de caracteres previamente ingresada por el usuario
 *\return 1 si es un int von la validacion correspondiente -1 si no es un int
 */
int isNumber (char* cadena);
/*
 * \brief se utiliza para tomar un numero float.
 * \param pResultado es el valor de la direccion de memoria en donde voy a guardar lo que voy a tranformar con atof().
 * \return 1 si es un float -1 si no es un float
 */
int getFloat (float* pResultado);
/*
 *\brief se utiliza para validar si es un int positivo,negativo, con come y sin ninguna otro caracter invalido.
 *\param la cadena de caracteres previamente ingresada por el usuario
 *\return 1 si es un int von la validacion correspondiente -1 si no es un int.
 */
int isDecimalNumber (char* cadena);
/*
 *\brief se utiliza para validar si es un char.
 *\param la cadena de caracteres previamente ingresada por el usuario
 *\return 1 si es un int von la validacion correspondiente -1 si no es un char.
 */
int isChar (char* cadena);

int getLong(long long int *pResultado);
