#include <stdio.h> 

int main() {
   
    int id;                     // ID del producto
    int stock;                  // Cantidad disponible en inventario
    int cantidad;               // Cantidad a vender o reabastecer
    int opcion;                 // Opción elegida en el menú
    float precio;               // Precio unitario del producto
    float total_ganancias = 0;  // Acumulador de ganancias por ventas
    float descuento;            // Porcentaje de descuento
    float precio_final;         // Precio con descuento aplicado
    char nombre[30];            // Nombre del producto

    // Registro del producto
    printf("Ingrese el ID del producto: ");
    scanf("%d", &id);           // Lee el ID
    getchar();                  // Limpia el buffer para que fgets funcione bien

    printf("Ingrese el nombre del producto: ");
    fgets(nombre, 30, stdin);   // Lee el nombre (permite espacios)

    // Validación del stock inicial
    do {
        printf("Ingrese la cantidad inicial en stock: ");
        scanf("%d", &stock);    // Lee el stock inicial
    } while (stock < 0);        // No se permite stock negativo

    // Validación del precio
    do {
        printf("Ingrese el precio unitario del producto: ");
        scanf("%f", &precio);   // Lee el precio unitario
    } while (precio < 0);       // No se permite precio negativo

    // Menú principal de opciones
    do {
        printf("\nMenu de Opciones:\n");
        printf("1. Vender producto\n");
        printf("2. Reabastecer producto\n");
        printf("3. Mostrar informacion del producto\n");
        printf("4. Mostrar total de ganancias\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);   // Lee la opción elegida

        switch(opcion) {
            case 1: // Venta del producto
                printf("Ingrese la cantidad a vender: ");
                scanf("%d", &cantidad);

                // Validación de cantidad positiva
                if (cantidad <= 0) {
                    printf("Cantidad invalida. Debe ser mayor que 0.\n");
                    break;
                }

                // Verifica si hay suficiente stock
                if (cantidad > stock) {
                    printf("No hay suficiente stock para esta venta.\n");
                } else {
                    // Solicita descuento
                    printf("Ingrese el descuento en porcentaje (0 si no hay): ");
                    scanf("%f", &descuento);

                    // Validación del descuento entre 0% y 100%
                    if (descuento < 0) descuento = 0;
                    if (descuento > 100) descuento = 100;

                    // Calcula el precio con descuento
                    precio_final = precio * (1 - descuento / 100);

                    // Actualiza el stock y las ganancias
                    stock -= cantidad;
                    total_ganancias += cantidad * precio_final;

                    // Muestra el resultado de la venta
                    printf("Venta realizada con exito.\n");
                    printf("Stock restante: %d\n", stock);
                    printf("Ganancia de esta venta: $%.2f\n", cantidad * precio_final);
                }
                break;

            case 2: // Reabastecimiento
                printf("Ingrese la cantidad a agregar al stock: ");
                scanf("%d", &cantidad);

                // Validación de cantidad positiva
                if (cantidad <= 0) {
                    printf("Cantidad invalida. Debe ser mayor que 0.\n");
                } else {
                    stock += cantidad; // Suma al stock existente
                    printf("Stock actualizado correctamente. Nuevo stock: %d\n", stock);
                }
                break;

            case 3: // Mostrar información del producto
                printf("\nInformacion del producto:\n");
                printf("ID:\t%d\n", id);
                printf("Nombre:\t%s", nombre);
                printf("Stock:\t%d\n", stock);
                printf("Precio:\t$%.2f\n", precio);
                break;

            case 4: // Mostrar ganancias totales
                printf("Total de ganancias acumuladas: $%.2f\n", total_ganancias);
                break;

            case 5: // Salida del programa
                printf("Saliendo del programa...\n");
                break;

            default: // Opción inválida
                printf("Opcion invalida. Intente nuevamente.\n");
        }

    } while (opcion != 5); // Se repite hasta que el usuario elija salir

    return 0; 
}
