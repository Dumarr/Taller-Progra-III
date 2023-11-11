#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <conio.h>
#include <time.h>



int numeroRomano(char[]);

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
                getchar();

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
                printf("fechas \n");
                char message[] = "Introduce la fecha (formato dd/MM/yyyy): ";
                fechas(message);

                break;
            case 7:
                productopunto();
                break;
            case 8:
                multiplicacionMatrices();
                break;
            case 9:
                printf("Ingrese un numero impar para generar la matriz ");
                int n;
                scanf("%d", &n);

                while (n%2==0){
                    printf("Debe ingresar un numero impar");
                    scanf("%d", &n);
                }
                matrizMagica(n);
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
void nombresPropios(char cadena[], char wordToKeep[]){
    int i;
    int mayuscula = 1;

    for(i = 0; cadena[i] != '\0'; i++) {
        // Convertir a minúsculas
        cadena[i] = tolower(cadena[i]);


        if (mayuscula && (cadena[i] >= 'a' && cadena[i] <= 'z')) {
            cadena[i] = toupper(cadena[i]);
            mayuscula = 0;
        }

        else if (cadena[i] == ' ') {
            mayuscula = 1;
        }

        else if (wordToKeep[0] != '\0' && strncmp(&cadena[i], wordToKeep, strlen(wordToKeep)) == 0) {
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
void fechas(char message[]) {


    char input[20];
    struct tm tm_date;
    time_t timestamp;

    while (1) {
        printf("%s", message);
        scanf("%s", input);

        memset(&tm_date, 0, sizeof(struct tm));


        if (sscanf(input, "%d/%d/%d", &tm_date.tm_mday, &tm_date.tm_mon, &tm_date.tm_year) == 3) {

            tm_date.tm_mon--;


            tm_date.tm_year -= 1900;


            timestamp = mktime(&tm_date);


            if (timestamp != -1) {
                break;
            } else {
                printf("Fecha no valida vuelva a digitar.\n");
            }
        } else {
            printf("Formato incorrecto, vuelva a intentar.\n");
        }
    }


    struct tm *formatted_date = localtime(&timestamp);


    char formatted_output[50];
    strftime(formatted_output, sizeof(formatted_output), "%A, %d de %B de %Y", formatted_date);
    printf("%s\n", formatted_output);
}



/* Responsable alejandro*/
void productopunto(){

}

/* Responsable andres*/
void multiplicacionMatrices(){

}

/* Responsable dumar*/
void matrizMagica(int n) {


    int matriz[n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = 0;
        }
    }

    int fila = 0;
    int columna = n / 2;

    for (int numero = 1; numero <= n * n; ++numero) {
        matriz[fila][columna] = numero;

        fila--;
        columna++;

        if (fila < 0) {
            fila = n - 1;
        }

        if (columna == n) {
            columna = 0;
        }

        if (matriz[fila][columna] != 0) {
            fila += 2;
            columna--;

            if (fila >= n) {
                fila -= n;
            }
        }
    }
    printf("Matriz Magica de orden %d:\n", n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
}

