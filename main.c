#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Funcion extra para selecionar las cadenas
const char* seleccionarCadena(const char *cad1, const char *cad2) {
    int eleccion;
    printf("¿Con qué cadena deseas operar?\n1. Primera cadena\n2. Segunda cadena\nSelecciona una opción: ");
    scanf("%d", &eleccion);
    if (eleccion == 1) return cad1;
    return cad2;
}

//Funcion para concatenar las dos cadenas
void concatenarCadenas(const char *cad1, const char *cad2, char *resultado) {
    strcpy(resultado, cad1);
    strcat(resultado, cad2);
}

//Funcion para invertir la cadena
void invertirCadena(const char *cad1, char *invertida) {
    int len = strlen(cad1);
    const char *finCadena = cad1 + len - 1;
    for (int i = 0; i < len; i++) {
        *(invertida + i) = *(finCadena - i);
    }
    *(invertida + len) = '\0';
}

//Funcion para calcular la potencia de la cadena seleccionada
void calcularPotencia(const char *cad1, char *resultado) {
    char *invertida = (char *)malloc(50 * sizeof(char));
    int n;
    printf("Numero de potencia de la cadeana deseada: ");
    scanf("%d", &n);
    resultado[0] = '\0'; // Asegurarse de que el resultado esté vacío

    if ( n == 0 ) {
        printf("\u03BB\n");
    } else if ( n > 0 ) {
        for (int i = 0; i < n; i++) {
            strcat(resultado, cad1);
        }
        printf("Cadena resultante: %s\n", resultado);
    } else {
        invertirCadena(cad1, invertida);
        for (int i = 0; i < -n; i++) {
            strcat(resultado, invertida);
        }
        printf("Resultado: %s\n", resultado);
    }
    free(invertida);
}

// Funcion para calcular la longitud de la cadena seleccionada
void calcularLongitud(const char *cadena) {
    int longitud = strlen(cadena);
    printf("Longitud de la cadeana: %d", longitud);
}

//Mostrar los prefijos
void mostrarPrefijos(const char *cadena) {
    int longitud = strlen(cadena);
    printf("Prefijos de la cadena:\n");
    printf("\u03BB\n"); // Cadena vacio (lambda)
    for (int i = 1; i <= longitud; i++) {
        char *prefijo = (char *)malloc((i + 1) * sizeof(char));
        strncpy(prefijo, cadena, i);
        prefijo[i] = '\0';
        printf("%s\n", prefijo);
        free(prefijo);
    }
}

//Mostrar los sufijos
void mostrarSufijos(const char *cadena) {
    int longitud = strlen(cadena);
    printf("Sufijos de la cadena:\n");
    printf("\u03BB\n"); // Cadena vacio (lambda)
    for (int i = longitud -1 ; i >= 0; i--) {
        char *sufijo = (char *)malloc((longitud - i + 1) * sizeof(char));
        strcpy(sufijo, cadena + i);
        printf("%s\n", sufijo);
        free(sufijo);
    }
}
//Funcion para mostrar las subcadenas
void mostrarSubcadenas(const char *cadena) {
    int longitud = strlen(cadena);

    printf("Subcadenas en orden creciente de longitud:\n");
    printf("\u03BB\n");
    for (int i = 1; i <= longitud; i++) {
        for (const char *ini = cadena; ini + i <= cadena + longitud; ++ini) {
            printf("%.*s\n", i, ini);
        }
    }
}

//Funcion para mostrar las subsecuencias
void mostrarSubsecuencias(const char *cadena) {
    int longitud = strlen(cadena);
    if (longitud > 14) {
        printf("Solo se permiten cadenas de longitud 14");
        return;
    }
    int totalSubsecuencias = (int)pow(2, longitud);
    printf("\u03BB\n");

    for (int i = 1; i < totalSubsecuencias; ++i) {
        char sub[longitud + 1];
        int idx = 0;
        for (int j = 0; j < longitud; ++j) {
            if (i & (1 << j)) {
                sub[idx++] = cadena[j];
            }
        }
        sub[idx] = '\0';
        printf("%s\n", sub);
    }
}

//mostrar menu del programa
void menu(int *opcion, const char *cad1, const char *cad2, char *resultado) {
    printf("\n--- MENU ---\n");
    printf("1. Concatenar\n");
    printf("2. Potencia\n");
    printf("3. Longitud\n");
    printf("4. Prefijos\n");
    printf("5. Sufijos\n");
    printf("6. Subcadenas\n");
    printf("7. Subsecuencias\n");
    printf("8. Salir\n");
    printf("Selecciona una opcion: ");
    scanf("%d", opcion);

    switch (*opcion) {
        case 1:
            concatenarCadenas(cad1, cad2, resultado);
            printf("Concatenacion de las dos cadenas: %s\n", resultado);
            break;
        case 2: calcularPotencia(seleccionarCadena(cad1, cad1), resultado); break;
        case 3: calcularLongitud(seleccionarCadena(cad1, cad2)); break;
        case 4: mostrarPrefijos(seleccionarCadena(cad1, cad2)); break;
        case 5: mostrarSufijos(seleccionarCadena(cad1, cad2)); break;
        case 6: mostrarSubcadenas(seleccionarCadena(cad1, cad2)); break;
        case 7: mostrarSubsecuencias(seleccionarCadena(cad1, cad2)); break;
        case 8: printf("Saliendo del programa...\n"); break;
        default: printf("Opcion no valida. Intenta de nuevo.\n"); break;
    }
}

void iniciarPrograma() {
    //definicion de variables con memoria dinamica
    char *cad1 = (char *)malloc(50* sizeof(char));
    char *cad2 = (char *)malloc(50* sizeof(char));
    char *resultado = (char *)malloc(150* sizeof(char));
    int *opcion = (int *)malloc(sizeof(int));

    //ingresar las cadenas
    printf("Ingresa la primera cadena:\n");
    scanf("%49s", cad1);
    printf("Ingresa la segunda cadena:\n");
    scanf("%49s", cad2);

    //mostrar repetitivamente el menu
    do {
        menu(opcion, cad1, cad2, resultado);
    } while(*opcion != 8);

    //liberar memoria
    free(cad1);
    free(cad2);
    free(resultado);
    free(opcion);
}

int main(int argc, char *argv[]) {
    //iniciar Programa
    iniciarPrograma();
    return 0;
}