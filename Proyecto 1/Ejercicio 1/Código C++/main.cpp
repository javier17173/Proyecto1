#include <iostream>
#include <cstdlib>


using namespace std;
int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "spanish"); //Permite utilizar tildes en la consola de C++
	
	int numero= 0, divisor= 0, cantidad = 0, opcion= 0, esMayor= 0, auxiliar = 0, iterador = 1;
	bool esPrimo;
	float cantPrimos= 0, cantNoPrimos= 0, sumaPrimos= 0, sumaNoPrimos= 0;
	float promedioPrimos= 0.0, promedioNoPrimos= 0.0;
	
	do{
		printf("Digite el n�mero:\n");
		scanf("%i", &numero);
		
		for(int i = 1; i<=numero; i++){
			if(numero%i == 0){
				divisor++;
			}
		}	

		if(divisor==2){
			esPrimo = true;
			cantPrimos+=1;
			sumaPrimos+=numero;
		}else{
			esPrimo = false;
			cantNoPrimos+=1;
			sumaNoPrimos+=numero;
		}
		
		if(esPrimo){
			printf("El n�mero %i SI es primo\n", numero);
		}else{
			printf("El n�mero %i NO es primo\n", numero);
		}
			
		if(auxiliar<numero){
			auxiliar = numero;
			esMayor = iterador;	
		}
			
		iterador++;
		divisor=0;
		
		printf("\n");
		printf("�Desea ingresar otro n�mero? \n");
		printf("1. Si \n");
		printf("2. Salir\n");
		scanf("%i", &opcion);
		printf("\n");

	}while(opcion==1);
	
	iterador=1;

	promedioPrimos = sumaPrimos / cantPrimos;
	promedioNoPrimos = sumaNoPrimos / cantNoPrimos;
	
	
	printf("\n***********************************************************\n");
	printf("El n�mero Mayor ingresado es: %i y est� en la posici�n: %i\n\n", auxiliar, esMayor);
	
	printf("Cantidad de N�meros Primos: %0.0f\n", cantPrimos);
	printf("Sumatoria de N�meros Primos: %0.0f\n", sumaPrimos);
	printf("Promedio de N�meros Primos: %0.2f\n\n", promedioPrimos);
	
	printf("Cantidad de N�meros NO Primos: %0.0f\n", cantNoPrimos);
	printf("Sumatoria de N�meros NO Primos: %0.0f\n", sumaNoPrimos);
	printf("Promedio de N�meros NO Primos: %0.2f\n", promedioNoPrimos);
	printf("************************************************************\n");
	
	return 0;
}
