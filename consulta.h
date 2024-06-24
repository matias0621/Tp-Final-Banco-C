
#ifndef CONSULTA_H_INCLUDED
#define CONSULTA_H_INCLUDED
#include "alta.h"
/*
//Todo (alta, baja, modificacion, consulta, listado)
typedef struct {
    int id;
    char nombre[50];
    char apellido[50];
    char correo[50];
    char contrasena[20];
    int dadoDeBaja;
    char nacionalidad[50];
} Usuario;


//Alta, baja, modificacion, consulta y listado
typedef struct {
    int numero_cuenta;
    int id_usuario;
    double saldo;
    char tipo_cuenta[20];
} CuentaBancaria;

//Estructura de movimiento
//Consulta, alta, baja
typedef struct {
    int id;                // Identificador único del movimiento
    char tipo[20];         // Tipo de movimiento (e.g., "Depósito", "Retiro", "Transferencia")
    double monto;          // Monto del movimiento
    time_t fecha;          // Fecha y hora del movimiento
    char descripcion[100]; // Descripción del movimiento
} Movimiento;


//Estructura de factura
//Consulta, alta
typedef struct {
    int id;                 // Identificador único de la factura
    char numero[20];        // Número de factura
    double montoTotal;      // Monto total de la factura
    time_t fechaEmision;    // Fecha de emisión de la factura
    char cliente[100];      // Nombre del cliente
    char descripcion[200];  // Descripción de la factura
} Factura;
*/
extern const char ArchivoDeUsuarios[];
extern const char ArchivoDeCuentas[];
extern const char ArchivoDeMovimientos[];
extern const char ArchivoDeFacturas[];
extern const char correoAdmin[];
extern const char contraAdmin[];
extern const char ArchivoDesactivados[];

void consultaUsuarioById(char ArchivoDeUsuarios[], int id);
void consultaMostrarUsuarioGeneral(char ArchivoDeUsuarios[]);
void mostrarUsuario(Usuario a);

void consultaMostrarCuentasByIdUsuario(char ArchivoDeCuentas[], int idUsuario);
void consultaMostrarCuentasGeneral(char ArchivoDeCuentas[]);
void mostrarCuentaBancaria(CuentaBancaria a);

void consultaMostrarMovimientosById(char ArchivoDeMovimientos[], int id);
void consultaMostrarMovimientosGeneral(char ArchivoDeMovimientos[]);
void mostrarMovimiento(Movimiento a);

void consultaMostrarFacturaById(char ArchivoDeFacturas[], int id);
void consultaMostrarFacturaGeneral(char ArchivoDeFacturas[]);
void mostrarFactura(Factura a);


#endif // CONSULTA_H_INCLUDED
