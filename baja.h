#ifndef BAJA_H_INCLUDED
#define BAJA_H_INCLUDED
#include "alta.h"
#include "consulta.h"
#include "MODIFICACION.h"
/*
typedef struct {
    int id;
    char nombre[50];
    char apellido[50];
    char correo[50];
    char contrasena[20];
    int dadoDeBaja;
    char nacionalidad[50];
} Usuario;

typedef struct {
    int numero_cuenta;
    int id_usuario;
    double saldo;
    char tipo_cuenta[20];
} CuentaBancaria;

typedef struct {
    int id;                // Identificador único del movimiento
    char tipo[20];         // Tipo de movimiento (e.g., "Depósito", "Retiro", "Transferencia")
    double monto;          // Monto del movimiento
    time_t fecha;          // Fecha y hora del movimiento
    char descripcion[100]; // Descripción del movimiento
} Movimiento;
*/
extern const char ArchivoDeUsuarios[];
extern const char ArchivoDeCuentas[];
extern const char ArchivoDeMovimientos[];
extern const char ArchivoDeFacturas[];
extern const char correoAdmin[];
extern const char contraAdmin[];
extern const char ArchivoDesactivados[];

long obtieneCantDeCuentas(FILE* buffer);
void desactivarCuenta(char archivoCuentas[],char cuentasDesac[],int id);
void creaArregloSinEliminado(char archivoCuentas[], int idUsuarioELiminar, long totalCuentas, CuentaBancaria **arreglo);
void nuevoArch(char ArchivoDeCuentas[],CuentaBancaria arreglo[],long totalCuentas);
int confirmacion(char cuentasDesac[],int id);
int reafirmacion(char cuentasDesac[],int id);
void pasaCuentaToDesac(char cuentasDesac[],CuentaBancaria user);
long obtieneTamanioArchivoCuentas(char ArchivoDeCuentas[]);
void eliminaCuenta(char archivoCuentas[], char cuentasDesac[], int id);
int eliminaUsuario(char archivoUsuarios[], int id);
void eliminaCuentaRoot(char archivoCuentas[], char cuentasDesac[]);
int eliminaUsuarioRoot(char archivoUsuarios[]);

#endif // BAJA_H_INCLUDED
