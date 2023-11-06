#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <conio.h>

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
            case '1':
                numeroRomano();
                break;
            case '2':
                factoresPrimos();
                break;
            case '3':
                nombresPropios();
                break;
            case '4':
                numerosEgolatras();
                break;
            case '5':
                numerosAmigos();
                break;
            case '6':
                fechas();
                break;
            case '7':
                productopunto();
                break;
            case '8':
                multiplicacionMatrices();
                break;
            case '9':
                matrizMagica();
                break;
            case '10':
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

/* Responsable andres*/
void nombresPropios(){

}

/* Responsable alejandro*/
void numerosEgolatras(){

}

/* Responsable andres*/
void numerosAmigos(){

}

/* Responsable andres*/
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

