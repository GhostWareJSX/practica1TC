#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Funcion para pedir una cadena
void pedirCadena(char *cadena, const char *mensaje) {
    while (1) {
        printf("%s", mensaje);
        scanf("%s", cadena);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        if (strlen(cadena) > 50) {
            printf("La cadena excede 49 caracteres. Intenta de nuevo.\n");
        } else {
            break;
        }
    }
}

//Funcion extra para selecionar las cadenas
const char* seleccionarCadena(const char *cad1, const char *cad2, const char *resultado) {
    int eleccion;
    printf("Seleccione la cadena con que deseas operar:\n");
    printf("1. Primera cadena (%s)\n", cad1);
    printf("2. Segunda cadena (%s)\n", cad2);
    if (resultado[0] == '\0') {
        printf("3. Tercera cadena (resultado) (vacía)\n");
    } else {
        printf("3. Tercera cadena (resultado) (%s)\n", resultado);
    }
    printf("Selecciona una opción: ");
    scanf("%d", &eleccion);

    if (eleccion == 1) return cad1;
    if (eleccion == 2) return cad2;
    if (eleccion == 3) {
        if (resultado[0] == '\0') {
            printf("La cadena seleccionada está vacía. Regresando al menú.\n");
            return NULL;
        }
        return resultado;
    }
    // Opción no válida: por defecto regresar a la segunda
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
void calcularPotencia(const char *cad1, char *temp) {
    char *invertida = (char *)malloc(51 * sizeof(char));
    int n;
    printf("Numero de potencia de la cadena deseada: ");
    scanf("%d", &n);
    temp[0] = '\0'; // Asegurarse de que el resultado esté vacío

    if ( n == 0 ) {
        printf("\u03BB\n");
    } else if ( n > 0 ) {
        for (int i = 0; i < n; i++) {
            strcat(temp, cad1);
        }
        printf("Cadena resultante: %s\n", temp);
    } else {
        invertirCadena(cad1, invertida);
        for (int i = 0; i < -n; i++) {
            strcat(temp, invertida);
        }
        printf("Resultado: %s\n", temp);
    }
    free(invertida);
}

// Funcion para calcular la longitud de la cadena seleccionada
void calcularLongitud(const char *cadena) {
    int longitud = strlen(cadena);
    printf("Longitud de la cadena: %d", longitud);
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
void menu(int *opcion, const char *cad1, const char *cad2, char *resultado, char *temp) {
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
        case 2: {
            const char *sel = seleccionarCadena(cad1, cad2, resultado);
            if (sel == NULL) break;
            calcularPotencia(sel, temp);
            strcpy(resultado, temp); // Copia el resultado a la variable resultado
            break;
        }
        case 3: {
            const char *sel = seleccionarCadena(cad1, cad2, resultado);
            if (sel == NULL) break;
            calcularLongitud(sel);
            break;
        }
        case 4: {
            const char *sel = seleccionarCadena(cad1, cad2, resultado);
            if (sel == NULL) break;
            mostrarPrefijos(sel);
            break;
        }
        case 5: {
            const char *sel = seleccionarCadena(cad1, cad2, resultado);
            if (sel == NULL) break;
            mostrarSufijos(sel);
            break;
        }
        case 6: {
            const char *sel = seleccionarCadena(cad1, cad2, resultado);
            if (sel == NULL) break;
            mostrarSubcadenas(sel);
            break;
        }
        case 7: {
            const char *sel = seleccionarCadena(cad1, cad2, resultado);
            if (sel == NULL) break;
            mostrarSubsecuencias(sel);
            break;
        }
        case 8: printf("Saliendo del programa...\n"); break;
        default: printf("Opcion no valida. Intenta de nuevo.\n"); break;
    }
}

void iniciarPrograma() {
    //definicion de variables con memoria dinamica
    char *cad1 = (char *)malloc(51 * sizeof(char));
    char *cad2 = (char *)malloc(51 * sizeof(char));
    char *resultado = (char *)malloc(150 * sizeof(char));
    char *temp = (char *)malloc(150 * sizeof(char));
    int *opcion = (int *)malloc(sizeof(int));

    // Inicializar resultado como cadena vacía (tercera cadena)
    resultado[0] = '\0';

    //ingresar las cadenas
    pedirCadena(cad1, "Ingresa la primera cadena:\n");
    pedirCadena(cad2, "Ingresa la segunda cadena:\n");

    //mostrar repetitivamente el menu
    do {
        menu(opcion, cad1, cad2, resultado, temp);
    } while(*opcion != 8);

    //liberar memoria
    free(cad1);
    free(cad2);
    free(resultado);
    free(temp);
    free(opcion);
}

int main(int argc, char *argv[]) {
    //iniciar Programa
    iniciarPrograma();
    return 0;
}