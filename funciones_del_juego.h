/*
 * funciones del juego.h
 *
 *  Created on: 8 may. 2022
 *      Author: lp1-2022
 */

#ifndef FUNCIONES_DEL_JUEGO_H_
#define FUNCIONES_DEL_JUEGO_H_

void imprimirMenu();
int leerOpciones();
void imprimirMenu_de_Configuracion();
int menuConfiguracion_de_Partida( int * cantidad_de_Intentos, int * cantidad_de_Caracteres );
void menuInicial( int *partida_no_Terminada, int * cantidad_de_Intentos, int * cantidad_de_Caracteres );
void limpiarPantalla();
void imprimirTablero(int cantidad_de_Intentos, int cantidad_de_Caracteres);
void inicializarTablero(int cantidad_de_Intentos, int cantidad_de_Caracteres);
void empezarPartida(int cantidad_de_Intentos, int cantidad_de_Caracteres);
double evaluar(char expr[]);
char verificarNumero(char ch);
int precedencia(char ch);
double calcular(char moperator, double num1, double num2);


#endif /* FUNCIONES_DEL_JUEGO_H_ */
