#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <conio.h>

int numeroRomano( char[]);

void factoresPrimos();

void nombresPropios();

int numerosEgolatras(int);

void numerosAmigos();

void fechas();

void productopunto();

void multiplicacionMatrices();

void matrizMagica();

int main() {
    system("cls");
    int opcion;
    do {
        printf("Bienvenido al programa \nSelecciones una opcion: "
           "\n1. Numero Romano \n2. Factores Primos \n3. Nombres Propios \n4. Numeros Egolatras \n5. Numeros Amigos "
           "\n6. Fechas \n7. Producto Punto \n8. Multiplicacion de Matrices \n9. Matriz Magica \n10. Salir \n");
        scanf("%d", &opcion);
        // limpiar el escaner
        fflush(stdin);
        switch (opcion) {
            case 1:
                char numRoman[10];
                printf("---> Menu numero romano\n"
                "Ingrese un numero romano...");

                scanf("%s", numRoman);
                for (int i = 0; i < strlen(numRoman); ++i) {
                numRoman[i] = toupper(numRoman[i]);
                }

                printf("El valor [ %s ] en numeros decimales es: %d\n", numRoman, numeroRomano(numRoman));

                break;
            case 2:
                factoresPrimos();
                break;
            case 3:
                printf("Nombres propios \n");

                char cadena[100];
                char palabraAMantenerEnMinusculas[100];

                printf("Ingrese la cadena de texto: ");
                scanf("%[^\n]s", cadena);
                getchar();  // Consumir el carácter de nueva línea en el búfer

                printf("Ingrese la palabra a mantener en minusculas: ");
                scanf("%[^\n]s", palabraAMantenerEnMinusculas);

                nombresPropios(cadena, palabraAMantenerEnMinusculas);

                printf("Nombre propio en minuscula: %s\n", cadena);

                break;
            case 4:
               int number;
               printf("---> Menu numero egolatra\n"
                "Digite un numero...");
               scanf("%d", &number);
               fflush(stdin);

               if (numerosEgolatras(number) == 1) {
                    printf("El numero %d es un numero egolatra\n\n", number);
               } else {
                    printf("El numero %d NO es un numero egolatra\n\n", number);
               }
                break;
            case 5:
                numerosAmigos();
                break;
            case 6:
                fechas();
                break;
            case 7:
                productopunto();
                break;
            case 8:
                multiplicacionMatrices();
                break;
            case 9:
                matrizMagica();
                break;
            case 10:
                printf("Gracias por usar el programa");
                break;
            default:
                printf("Opcion no valida\n");
                break;
    }
    } while (opcion != 10);
    return 0;
}

/* Responsable alejandro*/
int numeroRomano(char num[10]){
    int number[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int addition = 0;

    for (int i = 0; i < strlen(num); ++i) {
        switch (num[i]) {

            case 'M':
                number[i] = 1000;
                break;
            case 'D':
                number[i] = 500;
                break;
            case 'C':
                number[i] = 100;
                break;
            case 'L':
                number[i] = 50;
                break;
            case 'X':
                number[i] = 10;
                break;
            case 'V':
                number[i] = 5;
                break;
            case 'I':
                number[i] = 1;
                break;

            default:
                printf("\n Has introducido caracteres invalidos");
                number[i] = 0;
                break;
        }
    }
    for (int i = 0; i < strlen(num); ++i) {
        if (number[i] >= number[i + 1]) {
            addition += number[i];
        } else {
            addition -= number[i];
        }
    }
    return addition;


}

/* Responsable andres*/
void factoresPrimos(){

}

/* Responsable dumar*/
void nombresPropios(char cadena[], char palabraAMantenerEnMinusculas[]){
    int i;
    int mayuscula = 1;

    for(i = 0; cadena[i] != '\0'; i++) {
        // Convertir a minúsculas
        cadena[i] = tolower(cadena[i]);

        // Capitalizar el primer carácter de cada palabra
        if (mayuscula && (cadena[i] >= 'a' && cadena[i] <= 'z')) {
            cadena[i] = toupper(cadena[i]);
            mayuscula = 0;
        }
            // Restablecer la bandera de mayúscula al encontrar un espacio
        else if (cadena[i] == ' ') {
            mayuscula = 1;
        }
            // Mantener la palabra especificada en minúsculas
        else if (palabraAMantenerEnMinusculas[0] != '\0' && strncmp(&cadena[i], palabraAMantenerEnMinusculas, strlen(palabraAMantenerEnMinusculas)) == 0) {
            mayuscula = 1;
        }
    }

}

/* Responsable alejandro*/
int numerosEgolatras(int number){
int adittion = 0;
    int size = floor(log10(number)) + 1;
    char numberString[size + 1];

    sprintf(numberString, "%d", number);

    for (int i = 0; i < size; ++i) {
        int now = numberString[i] - '0';
        int potency = pow(now, size);
        adittion += potency;
    }

    if (adittion == number) {
        return 1;
    } else {
        return 0;
    }
}

/* Responsable andres*/
void numerosAmigos(){

}

/* Responsable dumar*/
void fechas(){

}

/* Responsable alejandro*/
void productopunto(){

}

/* Responsable andres*/
void multiplicacionMatrices(){

}

/* Responsable dumar*/
void matrizMagica(){

}

