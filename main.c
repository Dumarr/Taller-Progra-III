#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void numeroRomano();

void factoresPrimos();

void nombresPropios();

void numerosEgolatras();

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
                numeroRomano();
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
                numerosEgolatras();
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
void numeroRomano(){

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
void numerosEgolatras(){

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

