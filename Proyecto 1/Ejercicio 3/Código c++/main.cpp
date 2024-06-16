#include <stdio.h>
#include <cstdlib>

int main() {
    int numero_ingresado;
    int numero_inverso;
    char continuar;
    int auxiliar;

    do {
    	numero_inverso = 0;
        // Pedir al usuario que ingrese un número_entero de hasta 5 dígitos
        printf("Ingrese un numero (maximo 5 digitos): ");
        scanf("%d", &numero_ingresado);
		
		auxiliar = numero_ingresado;
        // Verificar que el número_ingresado está en el rango permitido
        if (numero_ingresado >= 0 && numero_ingresado <= 99999) {
            // Obtener el número inverso
            // Ciclo para invertir el número
             while (numero_ingresado > 0) {
        		numero_inverso = numero_inverso * 10 + numero_ingresado % 10;
        		numero_ingresado = numero_ingresado / 10;
    		}
            // Mostrar el número ingresado y su inverso
            printf("Numero ingresado: %d\n", auxiliar);
            printf("Numero inverso: %d\n", numero_inverso);
        } else {
            // Mensaje de error si el número está fuera del rango permitido
            printf("Error: El numero debe ser un entero positivo de hasta 5 digitos.\n");
        }
		
        // Pregunta al usuario si desea continuar?
        printf("Desea continuar? (s/n): ");
        scanf(" %c", &continuar);
        
		system("cls");
    } while (continuar == 's' || continuar == 'S');

    return 0;
}

