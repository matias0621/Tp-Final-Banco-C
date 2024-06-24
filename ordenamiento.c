#include "ordenamiento.h"

///Usuarios
void ordenamientoIncersionUsuario(){
    FILE * buff;
    Usuario usuarios[500];
    int validos = 0;

    buff = fopen(ArchivoDeUsuarios, "rb");
    if (buff){

        validos = pasarDelArchivoAlArray(buff, usuarios);
        ordenacionInsercion(usuarios, validos);
        imprimirUsuarios(usuarios, validos);

        fclose(buff);
    }
}

int pasarDelArchivoAlArray(FILE * buff, Usuario arrayUsuario[]){
    Usuario usuario;
    int i = 0;
    int validos = 0;
    while(fread(&usuario, sizeof(Usuario), 1, buff) > 0){
        arrayUsuario[i] = usuario;
        i++;
        validos++;
    }
    return validos;
}

// Funci�n de ordenaci�n por inserci�n para el arreglo de Usuarios
void ordenacionInsercion(Usuario A[], int validos) {
    int i = 0;
    while (i < validos - 1) {
        insertarUsuariorPorEdad(A, i, A[i + 1]);
        i++;
    }
}

// Funci�n para imprimir la lista de usuarios
void imprimirUsuarios(Usuario usuarios[], int n) {
    for (int i = 0; i < n; i++) {
        consultaUsuarioById(ArchivoDeUsuarios, usuarios[i].id);
    }
}

void insertarUsuariorPorEdad(Usuario A[], int ultPosVal, Usuario dato) {
    int i = ultPosVal;
    while (i >= 0 && dato.edad < A[i].edad) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = dato;
}

/// cuentas

void ordenamientoIncersionCuenta(){
    FILE * buff;
    CuentaBancaria cuenta[50];
    int validos = 0;

    buff = fopen(ArchivoDeCuentas, "rb");
    if (buff){

        validos = pasarDelArchivoAlArrayDeCuenta(buff, cuenta);
        ordenacionInsercionCuenta(cuenta, validos);
        imprimirCuentas(cuenta, validos);

        fclose(buff);
    }
}

int pasarDelArchivoAlArrayDeCuenta(FILE * buff, CuentaBancaria cuentaArray[]){
    CuentaBancaria cuenta;
    int i = 0;
    int validos = 0;
    while(fread(&cuenta, sizeof(CuentaBancaria), 1, buff) > 0){
        cuentaArray[i] = cuenta;
        i++;
        validos++;
    }
    return validos;
}

// Funci�n de ordenaci�n por inserci�n para el arreglo de Usuarios
void ordenacionInsercionCuenta(CuentaBancaria A[], int validos) {
    int i = 0;
    while (i < validos - 1) {
        insertarCuentaPorSaldo(A, i, A[i + 1]);
        i++;
    }
}

// Funci�n para imprimir la lista de usuarios
void imprimirCuentas(CuentaBancaria cuenta[], int n) {
    for (int i = 0; i < n; i++) {
        consultaMostrarCuentasByIdUsuario(ArchivoDeCuentas, cuenta[i].id_usuario);
    }
}

void insertarCuentaPorSaldo(CuentaBancaria A[], int ultPosVal, CuentaBancaria dato) {
    int i = ultPosVal;
    while (i >= 0 && dato.saldo < A[i].saldo) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = dato;
}

/// Facturas
void ordenamientoInsercionFacturas() {
    FILE *buff;
    Factura facturas[50];
    int validos = 0;

    buff = fopen(ArchivoDeFacturas, "rb");
    if (buff) {
        validos = pasarDelArchivoAlArrayFacturas(buff, facturas);
        ordenacionInsercionFacturas(facturas, validos);
        imprimirFacturas(facturas, validos);
        fclose(buff);
    } else {
        printf("Error al abrir el archivo de facturas.\n");
    }
}

// Función para leer facturas desde el archivo y llenar el arreglo
int pasarDelArchivoAlArrayFacturas(FILE * buff, Factura facturasArray[]) {
    Factura factura;
    int i = 0;
    int validos = 0;
    while (fread(&factura, sizeof(Factura), 1, buff) > 0) {
        facturasArray[i] = factura;
        i++;
        validos++;
    }
    return validos;
}

// Función de ordenación por inserción para las facturas
void ordenacionInsercionFacturas(Factura A[], int validos) {
    int i, j;
    Factura temp;
    for (i = 1; i < validos; i++) {
        temp = A[i];
        j = i - 1;
        while (j >= 0 && temp.montoTotal < A[j].montoTotal) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}

void imprimirFacturas(Factura facturas[], int n) {
    printf("Lista de Facturas:\n");
    for (int i = 0; i < n; i++) {
        printf("---------------------------------------------------------------------\n");
        printf("Factura ID: %d\n", facturas[i].id);
        printf("Numero: %s\n", facturas[i].numero);
        printf("Monto Total: %.2f\n", facturas[i].montoTotal);
        printf("Fecha Emision: %s", asctime(localtime(&facturas[i].fechaEmision)));
        printf("Cliente: %s\n", facturas[i].cliente);
        printf("Descripcion: %s\n", facturas[i].descripcion);
        printf("\n");
    }
}

/// Movimientos

// Función principal de ordenamiento e impresión de movimientos
void ordenamientoIncersionMovimientos(){
    FILE * buff;
    Movimiento movimientos[50];
    int validos = 0;

    buff = fopen(ArchivoDeMovimientos, "rb");
    if (buff){
        validos = pasarDelArchivoAlArrayMovimientos(buff, movimientos);
        ordenacionInsercionMovimientos(movimientos, validos);
        imprimirMovimientos(movimientos, validos);
        fclose(buff);
    } else {
        printf("Error al abrir el archivo de movimientos.\n");
    }
}

// Función para leer movimientos desde el archivo y llenar el arreglo
int pasarDelArchivoAlArrayMovimientos(FILE * buff, Movimiento movimientoArray[]){
    Movimiento movimiento;
    int i = 0;
    int validos = 0;
    while(fread(&movimiento, sizeof(Movimiento), 1, buff) > 0){
        movimientoArray[i] = movimiento;
        i++;
        validos++;
    }
    return validos;
}

// Función de ordenación por inserción para los movimientos
void ordenacionInsercionMovimientos(Movimiento A[], int validos) {
    int i, j;
    Movimiento temp;
    for (i = 1; i < validos; i++) {
        temp = A[i];
        j = i - 1;
        while (j >= 0 && temp.monto < A[j].monto) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}

void imprimirMovimientos(Movimiento movimientos[], int n) {
    printf("Lista de Movimientos:\n");
    for (int i = 0; i < n; i++) {
        printf("Movimiento ID: %d\n", movimientos[i].id);
        printf("Tipo: %s\n", movimientos[i].tipo);
        printf("Monto: %.2f\n", movimientos[i].monto);
        printf("Fecha: %s", asctime(localtime(&movimientos[i].fecha)));
        printf("Descripcion: %s\n", movimientos[i].descripcion);
        printf("\n");
    }
}


///-------------------------------------------------------------Seleccion------------------------------------------------------///
///-------------------------------------------------------------Seleccion------------------------------------------------------///
///-------------------------------------------------------------Seleccion------------------------------------------------------///
///-------------------------------------------------------------Seleccion------------------------------------------------------///
///-------------------------------------------------------------Seleccion------------------------------------------------------///
///-------------------------------------------------------------Seleccion------------------------------------------------------///

///-----------------------------------------------SELECCION------------------------------------------------///

void obtenerUsuariosDeArchivoYPasarlosAUnArreglo() {
    FILE *buff;
    int cantidadUsuarios = 0;
    Usuario usuarios[50];

    buff = fopen(ArchivoDeUsuarios, "rb");

    if (buff) {
        cantidadUsuarios = sacarLosUsuariosdelArchivo(buff, usuarios);
        ordenamientoPorSeleccionUsuarios(usuarios, cantidadUsuarios);
        imprimirUsuariosArray(usuarios, cantidadUsuarios);
    } else {
        printf("No se pudo abrir el archivo.\n");
    }

    fclose(buff);
}


int sacarLosUsuariosdelArchivo(FILE *buff, Usuario usuarios[50]) {
    int cantidadUsuarios = 0;
    Usuario usuario;
    // Leer cada estructura Usuario del archivo
    while (fread(&usuario, sizeof(Usuario), 1, buff) > 0) {
        // Copiar la estructura completa al arreglo de usuarios
        usuarios[cantidadUsuarios] = usuario;
        cantidadUsuarios++;

        // Verificar si se supera la cantidad máxima de usuarios
        if (cantidadUsuarios >= 50) {
            printf("Advertencia: Se ha alcanzado el límite máximo de usuarios a leer (%d).\n", 50);
            break;
        }
    }
    return cantidadUsuarios;
}

void ordenamientoPorSeleccionUsuarios(Usuario usuarios[], int size) {
    int i, j, minIndex;
    Usuario temp;
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (strcmp(usuarios[j].nombre, usuarios[minIndex].nombre) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = usuarios[i];
            usuarios[i] = usuarios[minIndex];
            usuarios[minIndex] = temp;
        }
    }
}


///Cuentas

void obtenerCuentasDeArchivoYPasarlosAUnArreglo() {
    FILE *buff;
    int cantidadCuentas = 0;
    CuentaBancaria cuentas[50];

    buff = fopen(ArchivoDeCuentas, "rb");

    if (buff) {
        cantidadCuentas = sacarLasCuentasDelArchivo(buff, cuentas);
        ordenamientoPorSeleccionCuentas(cuentas, cantidadCuentas);
        imprimirCuentas(cuentas, cantidadCuentas);
    } else {
        printf("No se pudo abrir el archivo.\n");
    }

    fclose(buff);
}

int sacarLasCuentasDelArchivo(FILE *buff, CuentaBancaria cuentas[50]) {
    int cantidadCuentas = 0;
    CuentaBancaria cuenta;
    // Leer cada estructura CuentaBancaria del archivo
    while (fread(&cuenta, sizeof(CuentaBancaria), 1, buff) > 0) {
        // Copiar la estructura completa al arreglo de cuentas
        cuentas[cantidadCuentas] = cuenta;
        cantidadCuentas++;

        // Verificar si se supera la cantidad máxima de cuentas
        if (cantidadCuentas >= 50) {
            printf("Advertencia: Se ha alcanzado el límite máximo de cuentas a leer (%d).\n", 50);
            break;
        }
    }
    return cantidadCuentas;
}

void ordenamientoPorSeleccionCuentas(CuentaBancaria cuentas[], int size) {
    int i, j, minIndex;
    CuentaBancaria temp;
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (strcmp(cuentas[j].tipo_cuenta, cuentas[minIndex].tipo_cuenta) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = cuentas[i];
            cuentas[i] = cuentas[minIndex];
            cuentas[minIndex] = temp;
        }
    }
}

/// Facturas

void obtenerFacturasDeArchivoYPasarlosAUnArreglo() {
    FILE *buff;
    int cantidadFacturas = 0;
    Factura facturas[50];

    buff = fopen(ArchivoDeFacturas, "rb");

    if (buff) {
        cantidadFacturas = sacarLasFacturasDelArchivo(buff, facturas);
        ordenamientoPorSeleccionFacturas(facturas, cantidadFacturas);
        imprimirFacturasArray(facturas, cantidadFacturas);
    } else {
        printf("No se pudo abrir el archivo.\n");
    }

    fclose(buff);
}


int sacarLasFacturasDelArchivo(FILE *buff, Factura facturas[50]) {
    int cantidadFacturas = 0;
    Factura factura;
    // Leer cada estructura Factura del archivo
    while (fread(&factura, sizeof(Factura), 1, buff) > 0) {
        // Copiar la estructura completa al arreglo de facturas
        facturas[cantidadFacturas] = factura;
        cantidadFacturas++;

        // Verificar si se supera la cantidad máxima de facturas
        if (cantidadFacturas >= 50) {
            printf("Advertencia: Se ha alcanzado el límite máximo de facturas a leer (%d).\n", 50);
            break;
        }
    }
    return cantidadFacturas;
}

void ordenamientoPorSeleccionFacturas(Factura facturas[], int size) {
    int i, j, minIndex;
    Factura temp;
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (strcmp(facturas[j].cliente, facturas[minIndex].cliente) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = facturas[i];
            facturas[i] = facturas[minIndex];
            facturas[minIndex] = temp;
        }
    }
}


///Movimientos

void obtenerMovimientosDeArchivoYPasarlosAUnArreglo() {
    FILE *buff;
    int cantidadMovimientos = 0;
    Movimiento movimientos[50];

    buff = fopen(ArchivoDeMovimientos, "rb");

    if (buff) {
        cantidadMovimientos = sacarLosMovimientosDelArchivo(buff, movimientos);
        ordenamientoPorSeleccionMovimientos(movimientos, cantidadMovimientos);
        imprimirMovimientos(movimientos, cantidadMovimientos);
    } else {
        printf("Error al abrir el archivo de movimientos.\n");
    }

    fclose(buff);
}



int sacarLosMovimientosDelArchivo(FILE *buff, Movimiento movimientos[]) {
    int cantidadMovimientos = 0;
    Movimiento movimiento;

    while (fread(&movimiento, sizeof(Movimiento), 1, buff) > 0) {
        movimientos[cantidadMovimientos] = movimiento;
        cantidadMovimientos++;

        if (cantidadMovimientos >= 50) {  // Límite máximo de movimientos
            printf("Advertencia: Se ha alcanzado el límite máximo de movimientos a leer (%d).\n", 50);
            break;
        }
    }

    return cantidadMovimientos;
}

void ordenamientoPorSeleccionMovimientos(Movimiento movimientos[], int n) {
    int i, j, min_idx;
    Movimiento temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            // Comparar por tipo (cadena de caracteres)
            if (strcmp(movimientos[j].tipo, movimientos[min_idx].tipo) < 0) {
                min_idx = j;
            }
        }
        // Intercambiar los movimientos
        temp = movimientos[min_idx];
        movimientos[min_idx] = movimientos[i];
        movimientos[i] = temp;
    }
}


// Función para intercambiar dos strings
void intercambiarStrings(char *str1, char *str2) {
    char temp[100]; // Tamaño temporal suficiente para almacenar una cadena

    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

// Función para realizar el ordenamiento por selección de strings
void ordenamientoPorSeleccionStrings(char arr[][100], int n) {
    int i, j, indiceMinimo;

    // Mover el límite del subarreglo no ordenado
    for (i = 0; i < n-1; i++) {
        // Encontrar el elemento mínimo en el subarreglo no ordenado
        indiceMinimo = i;
        for (j = i+1; j < n; j++) {
            if (strcmp(arr[j], arr[indiceMinimo]) < 0) {
                indiceMinimo = j;
            }
        }

        // Intercambiar el elemento mínimo con el primer elemento
        if (indiceMinimo != i) {
            intercambiarStrings(arr[i], arr[indiceMinimo]);
        }
    }
}

void imprimirUsuariosArray(Usuario usuarios[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        printf("ID: %d\n", usuarios[i].id);
        printf("Nombre: %s\n", usuarios[i].nombre);
        printf("Apellido: %s\n", usuarios[i].apellido);
        printf("Edad: %d\n", usuarios[i].edad);
        printf("Correo: %s\n", usuarios[i].correo);
        printf("Contraseña: %s\n", usuarios[i].contrasena);
        printf("Dado de Baja: %d\n", usuarios[i].dadoDeBaja);
        printf("Nacionalidad: %s\n", usuarios[i].nacionalidad);
        printf("\n");
    }
}

void imprimirCuentasArray(CuentaBancaria cuentas[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        printf("Número de Cuenta: %d\n", cuentas[i].numero_cuenta);
        printf("ID de Usuario: %d\n", cuentas[i].id_usuario);
        printf("Saldo: %.2f\n", cuentas[i].saldo);
        printf("Tipo de Cuenta: %s\n", cuentas[i].tipo_cuenta);
        printf("\n");
    }
}

void imprimirFacturasArray(Factura facturas[], int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d\n", facturas[i].id);
        printf("ID Usuario: %d\n", facturas[i].idUsuario);
        printf("Numero: %s\n", facturas[i].numero);
        printf("Monto Total: %.2f\n", facturas[i].montoTotal);
        printf("Fecha de Emision: %s", ctime(&facturas[i].fechaEmision));
        printf("Cliente: %s\n", facturas[i].cliente);
        printf("Descripcion: %s\n", facturas[i].descripcion);
        printf("\n");
    }
}

void imprimirMovimientosArray(Movimiento movimientos[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Movimiento %d:\n", i + 1);
        printf("  ID: %d\n", movimientos[i].id);
        printf("  ID Usuario: %d\n", movimientos[i].idUsuario);
        printf("  Tipo: %s\n", movimientos[i].tipo);
        printf("  Monto: %.2f\n", movimientos[i].monto);
        printf("  Fecha: %s", asctime(localtime(&movimientos[i].fecha)));
        printf("  Descripcion: %s\n", movimientos[i].descripcion);
        printf("\n");
    }
}

