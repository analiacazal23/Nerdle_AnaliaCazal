#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones_del_juego.h"

#define TRUE 1

char tablero[10][10];
char ecuacion[10];

int main(){

  int partida_no_Terminada = 1;
  int cantidad_de_Intentos = 0;
  int cantidad_de_Caracteres = 0;


  while(partida_no_Terminada){
    limpiarPantalla();
    menuInicial(&partida_no_Terminada, &cantidad_de_Intentos, &cantidad_de_Caracteres);
    empezarPartida( cantidad_de_Intentos, cantidad_de_Caracteres);
  }

  return 0;
}

// funcion que recibe como parametro una expresion matematica en forma de string y
// retorna el resultado de la misma
double evaluar(char expr[])
{
    double numbers[5]; int nsi = 0;
    char operators[5]; int osi = 0;
    char numbuf[16]; int nbi = 0;
    char ch; int  i = 0;

    while ((ch = expr[i]) != 0) {
        if (verificarNumero(ch))
        {
            numbuf[nbi++] = ch;
            if (!verificarNumero(expr[i + 1]))
            {
                numbuf[nbi] = 0; nbi = 0;
                sscanf(numbuf, "%lf", &numbers[nsi++]);
            }
        }
        else
        {
            while ((osi > 0) && (precedencia(ch) <= precedencia(operators[osi - 1])))
            {
                numbers[nsi - 2] = calcular(operators[osi - 1], numbers[nsi - 2], numbers[nsi - 1]);
                osi--; nsi--;
            }
            operators[osi++] = ch;
        }
        i++;
    }
    while (osi > 0) {
        numbers[nsi - 2] = calcular(operators[osi - 1], numbers[nsi - 2], numbers[nsi - 1]);
        osi--; nsi--;
    }
    return numbers[0];
}

// funcion que revisa si un caracter es un numero
char verificarNumero(char ch)
{
    if ((ch >= '0' && ch <= '9') || ch == '.') return 1; else return 0;
}

// funcion que recibe como parametro un caracte y retorna
// un entero que representa la precedencia de las operaciones
int precedencia(char ch)
{
    int precedencia;
    switch (ch)
    {
    case '+':
    case '-':
        precedencia = 0;
        break;
    case '*':
    case '/':
        precedencia = 1;
        break;
    case '^':
        precedencia = 2;
    }
    return precedencia;
}

// funcion calcular, recibe como parametro 2 numeros y un operador y retorna
// el resultado de la operacion matematica que corresponde al operador
double calcular(char moperator, double num1, double num2)
{
    double result;
    switch (moperator)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    case '^':
        result = pow(num1, num2);
        break;
    default:
        printf("Invalid Operator\n");
        exit(-1);
    }
    return result;
}

// Funcion que empieza el juego
void empezarPartida(int cantidad_de_Intentos, int cantidad_de_Caracteres){

  imprimirTablero( cantidad_de_Intentos, cantidad_de_Caracteres);
  while(TRUE){
  printf("Por favor ingrese la ecuacion que desea usar:\n");
  scanf("%s",ecuacion);
  printf("La ecuacion elegida es: %s\n", ecuacion);
  printf("El resultado es: %.0f\n",evaluar(ecuacion));
  }

}

// Funcion que limpia la pantalla
void limpiarPantalla(){
  system("clear");
}

// funcion que inicializa el tablero
void inicializarTablero(int cantidad_de_Intentos, int cantidad_de_Caracteres){
    for (int i =0; i < cantidad_de_Intentos; i++){
      for (int j = 0; j < cantidad_de_Caracteres; j++){
        tablero[i][j]='#';
      }
    }

}

// funcion para imprimir el tablero
void imprimirTablero(int cantidad_de_Intentos, int cantidad_de_Caracteres){

    for (int i =0; i < cantidad_de_Intentos; i++){
      for (int j = 0; j < cantidad_de_Caracteres; j++){
       printf("%c",tablero[i][j]);
      }
      printf("\n");
    }

}


// funcion que imprime el menu inicial y gestiona las opciones
void menuInicial( int *partida_no_Terminada, int * cantidad_de_Intentos, int * cantidad_de_Caracteres ){

  int opcion = 0;

    imprimirMenu();
    opcion = leerOpciones();

    switch(opcion){

      case 1:
        limpiarPantalla();

        while(!(*cantidad_de_Intentos) || !(*cantidad_de_Caracteres)){
          menuConfiguracion_de_Partida(cantidad_de_Intentos, cantidad_de_Caracteres );
        }

        inicializarTablero( *cantidad_de_Intentos, *cantidad_de_Caracteres);

        empezarPartida( *cantidad_de_Intentos, *cantidad_de_Caracteres);
        return;
        break;

      case 2:
        limpiarPantalla();
        return;
        break;

      case 3:
        while(TRUE){
          printf("Por favor ingrese la ecuacion que desea usar:\n");
          scanf("%s",ecuacion);
          printf("La ecuacion elegida es: %s\n", ecuacion);
          printf("El resultado es: %.0f\n",evaluar(ecuacion));
        }
      case 4:
        limpiarPantalla();
        *partida_no_Terminada = 0;
        return;
        break;

      default:
        limpiarPantalla();
        printf("\nError, por favor elija una opcion valida!\n");

    }
}

// funcion que impirime el menu de configuracion de partida y gestiona las opciones
int menuConfiguracion_de_Partida( int * cantidad_de_Intentos, int * cantidad_de_Caracteres ){

  int opcion = 0;

    imprimirMenu_de_Configuracion();
    opcion = leerOpciones();

    switch(opcion){

      case 1:
        limpiarPantalla();
        printf("Por favor ingrese un numero entre 5 y 10:\n");
        scanf("%i",cantidad_de_Caracteres);
        break;

      case 2:
        limpiarPantalla();
        printf("Por favor ingrese un numero entre 5 y 10:\n");
        scanf("%i",cantidad_de_Intentos);
        break;

      case 3:
        limpiarPantalla();
        break;

      default:
        limpiarPantalla();
        printf("\nError, por favor elija una opcion valida!\n");
        menuConfiguracion_de_Partida(cantidad_de_Intentos,cantidad_de_Caracteres);
    }
}

void imprimirMenu_de_Configuracion(){
  printf("\tConfiguracion de Partida\n");
  printf("\n Seleccione una de las opciones:\n");
  printf("\n1. Seleccionar cantidad de caracteres de la ecuacion:\n");
  printf("\n2. Seleccionar cantidad de intentos:\n");
  printf("\n3. Salir.\n");
}

// funcion para leer las opciones
int leerOpciones(){
  int opcion;
  scanf("%i",&opcion);
  return opcion;
}

void imprimirMenu(){
  printf("\tBienvenido a Nerdle\n");
  printf("\n Seleccione una de las opciones:\n");
  printf("\n1. Configurar partida nueva:\n");
  printf("\n2. Iniciar partida aleatoria:\n");
  printf("\n3. Resolver una ecuacion.\n");
  printf("\n4. Salir.\n");
}
