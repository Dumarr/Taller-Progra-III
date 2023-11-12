#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

static int nfactores = 0;
static bool factores = false;


int numeroRomano(char[]);

void factoresPrimos(int);
void getfactores(char *mensaje);
void desmontar_factor(int number);
int primo(int number);
bool si_primo(int number);
void ingfactor(int factorp);

void nombresPropios(char [], char []);

int numerosEgolatras(int);

bool numerosAmigos(int ,int);

void fechas(char[] );

int productopunto(int[],int[],int);

int**  llenarMatriz(int, int);
int** multiplicacionMatrices(int **,int, int, int **, int, int);

void matrizMagica(int );

int main() {
    system("cls");
    int opcion;
    do {
        fflush(stdin);
        printf("\nBienvenido al programa \nSelecciones una opcion: "
           "\n1. Numero Romano \n2. Factores Primos \n3. Nombres Propios \n4. Numeros Egolatras \n5. Numeros Amigos "
           "\n6. Fechas \n7. Producto Punto \n8. Multiplicacion de Matrices \n9. Matriz Magica \n10. Salir \n");
        scanf("%d", &opcion);
        // limpiar el escaner
        fflush(stdin);
        switch (opcion) {
            case 1:
                printf("---> Menu numero romano\n"
                "Ingrese un numero romano...");
               char numRoman[10];

                scanf("%s", numRoman);
                for (int i = 0; i < strlen(numRoman); ++i) {
                numRoman[i] = toupper(numRoman[i]);
                }

                printf("El valor [ %s ] en numeros decimales es: %d\n", numRoman, numeroRomano(numRoman));

                break;
            case 2:
                getfactores("Ingrese un numero: ");
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
               printf("---> Menu numero egolatra\n"
                "Digite un numero...");
               int number;
               scanf("%d", &number);
               fflush(stdin);

               if (numerosEgolatras(number) == 1) {
                    printf("El numero %d es un numero egolatra\n\n", number);
               } else {
                    printf("El numero %d NO es un numero egolatra\n\n", number);
               }
                break;
            case 5:
                printf("Numeros amigos \n");
                int num1, num2;

                printf("Ingrese el primer número: ");
                scanf("%d", &num1);

                printf("Ingrese el segundo número: ");
                scanf("%d", &num2);

                if (numerosAmigos(num1,num2)) {
                    printf("%d y %d son números amigos.\n", num1, num2);
                } else {
                    printf("%d y %d NO son números amigos.\n", num1, num2);
                }
                break;
            case 6:
                printf("fechas \n");
                char message[] = "Introduce la fecha (formato dd/MM/yyyy): ";
                fechas(message);

                break;
            case 7:
               printf("---> Menu producto punto\n"
                       "- Ingrese el tamanho del vector A:");
                int sizeA, sizeB;
                scanf("%d", &sizeA);

                printf("- Ingrese el tamanho del vector B:");
                scanf("%d", &sizeB);

                if (sizeA == sizeB) {
                    int matrizA[sizeA], matrizB[sizeB];

                    for (int i = 0; i < sizeA; i++) {
                        printf("A [%d] =", i + 1);
                        scanf("%d", &matrizA[i]);
                        fflush(stdin);
                    }
                    for (int j = 0; j < sizeB; j++) {
                        printf("B [%d] =", j + 1);
                        scanf("%d", &matrizB[j]);
                        fflush(stdin);
                    }

                    printf("Producto punto: %d \n", productopunto(matrizA, matrizB, sizeA));

                } else {
                    printf("Ambas matrices deben ser iguales...\n");

                }

                break;
            case 8:
                printf("Multiplicacion de matrices \n");
                int alto1, ancho1,alto2, ancho2;
                printf("Ingrese el alto de la matriz 1: ");
                scanf("%d", &alto1);
                printf("Ingrese el ancho de la matriz 1: ");
                scanf("%d", &ancho1);
                int** matriz1 = llenarMatriz(alto1, ancho1);
                printf("Matriz 1: \n");
                for (int i = 0; i < alto1; ++i) {
                    for (int j = 0; j < ancho1; ++j) {
                        printf("%d ", matriz1[i][j]);
                    }
                    printf("\n");
                }
                printf("Ingrese el alto de la matriz 2: ");
                scanf("%d", &alto2);
                printf("Ingrese el ancho de la matriz 2: ");
                scanf("%d", &ancho2);
                int** matriz2 = llenarMatriz(alto2, ancho2);
                printf("Matriz 2: \n");
                for (int i = 0; i < alto2; ++i) {
                    for (int j = 0; j < ancho2; ++j) {
                        printf("%d ", matriz2[i][j]);
                    }
                    printf("\n");
                }
                int ** matriz3 = multiplicacionMatrices(matriz1, alto1, ancho1, matriz2, alto2, ancho2);
                if (matriz3 == NULL){
                    printf("No se puede realizar la multiplicacion de matrices");
                } else{
                    printf("Matriz 3: \n");
                    for (int i = 0; i < alto1; ++i) {
                        for (int j = 0; j < ancho2; ++j) {
                            printf("%d ", matriz3[i][j]);
                        }
                        printf("\n");
                    }
                }





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
void getfactores(char *mensaje) {
    int number;
    bool seguir;

    do {
        tryagain:
        seguir = false;
        printf("%s", mensaje);
        if (scanf("%d", &number) != 1) {
            printf("Inválido, debe ingresar un número\n");
            fflush(stdin);
            seguir = true;
            goto tryagain;
        }
        desmontar_factor(number);
    } while (seguir);
}

void desmontar_factor(int number) {
    int producto = 1;
    int number1 = number;

    int factorp = 2;
    do {
        int subfactor = number1 % factorp;
        if (subfactor == 0) {
            number1 /= factorp;
            producto *= factorp;
            nfactores++;
        } else {
            if (nfactores > 0) {
                ingfactor(factorp);
            }
            factorp = primo(factorp);
        }
    } while (producto != number);
    ingfactor(factorp);
}

int primo(int number) {
    do {
        number++;
    } while (!si_primo(number));
    return number;
}

bool si_primo(int number) {
    if (number <= 0) {
        return false;
    }
    int cant_divisores = 0;
    bool divisores = false;
    int rango = (int)sqrt(number);
    int i = 2;
    while (i <= rango && !divisores) {
        if (number % i == 0) {
            cant_divisores++;
            divisores = true;
        }
        i++;
    }
    if (cant_divisores > 0 || number == 1) {
        return false;
    }
    return true;
}

void ingfactor(int factorp) {
    if (factores) {
        printf(" X");
    } else {
        factores = true;
    }

    if (nfactores == 1) {
        printf(" %d", factorp);
    } else {
        printf(" %d^%d", factorp, nfactores);
    }
    nfactores = 0;
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
int sumaDivisoresPropios(int n) {
    int suma = 1;

    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            suma += i;
        }
    }

    return suma;
}

bool numerosAmigos(int num1, int num2) {

    if (sumaDivisoresPropios(num1) == num2 && sumaDivisoresPropios(num2) == num1) {
        return true;
    } else {
        return false;
    }
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
int productopunto(int matrizA[], int matrizB[], int sizeMatriz){
int sizeTotal = 0;
    for (int i = 0; i < sizeMatriz; ++i) {
        sizeTotal += matrizA[i] * matrizB[i];
    }
    return sizeTotal;
}

/* Responsable andres*/

//metodo para rellenar la matriz
//metodo para multiplicar las matrices

int**  llenarMatriz(int alto, int ancho){
    int** matriz;
    matriz = (int**) malloc(alto * sizeof(int*));
    for (int i = 0; i < alto; ++i) {
        matriz[i] = (int*) malloc(ancho * sizeof(int));
    }
    for (int i = 0; i < alto; ++i) {
        for (int j = 0; j < ancho; ++j) {
            matriz[i][j] = (rand() % 10)+1;
        }
    }
    return matriz;
}

int** multiplicacionMatrices(int** matriz1,int alto1, int ancho1, int** matriz2, int alto2, int ancho2){
if(ancho1 != alto2){
    return NULL;}
else{
    int** matriz3;
    matriz3 = (int**) malloc(alto1 * sizeof(int*));
    for (int i = 0; i < alto1; ++i) {
        matriz3[i] = (int*) malloc(ancho2 * sizeof(int));
    }
    for (int i = 0; i < alto1; ++i) {
        for (int j = 0; j < ancho2; ++j) {
            matriz3[i][j] = 0;
        }
    }
    for (int i = 0; i < alto1; ++i) {
        for (int j = 0; j < ancho2; ++j) {
            for (int k = 0; k < ancho1; ++k) {
                matriz3[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    return matriz3;
}

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

