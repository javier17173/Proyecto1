#include <iostream>


using namespace std;
int main(int argc, char** argv) {
	setlocale(LC_ALL, "spanish"); //Permite utilizar tildes en la consola de C++
	
	//Declaración de variables
	const float IVA = 0.13;
	
	int opcionMenu;
	int cedula=0, precioTiquete=0, tipoCliente=0, tipoTiquete=0, cantidadTiquetes=0, numFactura = 1, montoDeVenta=0; 
	float impuestoVenta=0, descuento=0, subTotal=0, totalAPagar=0, promedioVentasTotal=0;
	string nomTipoCliente, nomTipoTiquete;
	char nombre[100];
	float cantTiquetesTipo1=0, cantTiquetesTipo2=0, acumuladoTiquetes1=0, acumuladoTiquetes2=0, cantTotalTiquetes=0, acumuladoTotalTiquetes=0;
	
	do{
		//Se solicitan los datos al usuario
		printf("Digite el número de cédula: \n");
		scanf("%i", &cedula);
	
		printf("Digite el nombre del cliente: \n");
		scanf(" %[^\n]", &nombre);

		printf("Digite el tipo de cliente: \n");
		printf("1. Niño o adulto mayor \n");
		printf("2. Adulto \n");
		scanf("%i", &tipoCliente);
	
		printf("Digite el tipo de tiquete: \n");
		printf("1. Tiquete Galería \n");
		printf("2. Tiquete Palco \n");
		scanf("%i", &tipoTiquete);
	
		printf("Digite la cantidad de tiquetes: \n");
		scanf("%i", &cantidadTiquetes);
		
		//Se verifica el tipo de tiquete
		if(tipoTiquete == 1){
			precioTiquete = 6000;
			nomTipoTiquete = "Galería"; //Se guarda el nombre del tipo de Tiquete
			
			montoDeVenta = cantidadTiquetes * precioTiquete;
			
			if(tipoCliente == 1){
				descuento = montoDeVenta * 0.30;
				nomTipoCliente = "Niño o adulto mayor"; //Se guarda el nombre del tipo de Cliente
			}else{
				descuento = 0;
				nomTipoCliente = "Adulto";
			}
			
			//Se hacen los calculos segun el tipo de cliente y tipo de tiquete 
			subTotal = montoDeVenta - descuento;
			impuestoVenta = subTotal * IVA;
			totalAPagar = subTotal + impuestoVenta;
			
			//Se calcula la cantidad de tiquetes tipo 1 y la suma de las ventas de estas entradas
			cantTiquetesTipo1+=cantidadTiquetes; //estadísticas
			acumuladoTiquetes1 +=totalAPagar;
			
		}else{
			precioTiquete = 12000;
			nomTipoTiquete = "Palco";
			
			montoDeVenta = cantidadTiquetes * precioTiquete;
			
			if(tipoCliente == 1){
				descuento = montoDeVenta * 0.30;
				nomTipoCliente = "Niño o adulto mayor"; 
			}else{
				descuento = 0;
				nomTipoCliente = "Adulto";
			}
		
			//Se hacen los calculos segun el tipo de cliente y tipo de tiquete 
			subTotal = montoDeVenta - descuento;
			impuestoVenta = subTotal * IVA;
			totalAPagar = subTotal + impuestoVenta;
			
			//Se calcula la cantidad de tiquetes tipo 2 y la suma de las ventas de estas entradas
			cantTiquetesTipo2+=cantidadTiquetes;
			acumuladoTiquetes2+=totalAPagar;
	
		}
		
		//Se calcula la cantidad total, el acumulado total y el promedio de todas las entradas
		cantTotalTiquetes+=cantidadTiquetes;
		acumuladoTotalTiquetes+=totalAPagar;
		promedioVentasTotal = acumuladoTotalTiquetes/cantTotalTiquetes;
		
		
		//Se imprimen los datos de la venta
		printf("\n");
		printf("****************************************************\n");
		printf("Número de Factura: %i\n", numFactura);
		printf("Cédula: %i\n", cedula);
		printf("Nombre: %s\n", &nombre);
		printf("Tipo del Cliente: %s\n", nomTipoCliente.c_str());
		printf("Tipo de Tiquete: %s\n", nomTipoTiquete.c_str());
		printf("Cantidad de Tiquetes: %i\n", cantidadTiquetes);
		printf("Monto Unitario: %i\n", precioTiquete);
		printf("Monto de Venta: %i\n", montoDeVenta);
		printf("Descuento: %0.2f\n", descuento);
		printf("Subtotal de Venta: %0.2f\n", subTotal);
		printf("Impuesto: %0.2f\n", impuestoVenta);
		printf("Total a Pagar: %0.2f\n", totalAPagar);
		printf("****************************************************\n");
		
		numFactura +=1; //Número de factura se incrementa en 1 como auto numérico
		
		printf("\n"); //SE solicita si desea continuar, si la respuesta es no, se finaliza el ciclo
		printf("¿Desea realizar otra compra? \n");
		printf("1. Si \n");
		printf("2. Salir\n");
		scanf("%i", &opcionMenu);
		printf("\n");
	}while(opcionMenu==1);
	
	
	//Se imprimen las estadísticas
	printf("\n");
	printf("****************************************************\n");
	printf("Cantidad de entradas Tiquetes Galería: %0.0f\n", cantTiquetesTipo1);
	printf("Acumulado Dinero por Tiquetes Galería: %0.2f\n\n", acumuladoTiquetes1);
	printf("Cantidad de entradas Tiquetes Palco: %0.0f\n", cantTiquetesTipo2);
	printf("Acumulado Dinero por Tiquetes Palco: %0.2f\n\n", acumuladoTiquetes2);
	printf("Cantidad General de Entradas: %0.0f\n", cantTotalTiquetes);
	printf("Acumulado General Dinero por Entradas: %0.2f\n", acumuladoTotalTiquetes);
	printf("Promedio General por Ventas: %0.2f\n", promedioVentasTotal);
	printf("****************************************************\n");
	
	
	return 0;
}
