#ifndef ALTA_H_INCLUDED
#define ALTA_H_INCLUDED
#include <time.h>
#include "pila.h"

// Constantes globales para los nombres de los archivos
extern const char ArchivoDeUsuarios[];
extern const char ArchivoDeCuentas[];
extern const char ArchivoDeMovimientos[];
extern const char ArchivoDeFacturas[];
extern const char correoAdmin[];
extern const char contraAdmin[];
extern const char ArchivoDesactivados[];

// Estructura de CuentaBancaria
typedef struct {
    int numero_cuenta;
    int id_usuario;
    double saldo;
    char tipo_cuenta[20];
} CuentaBancaria;

// Estructura de Usuario
typedef struct {
    int id;
    char nombre[50];
    char apellido[50];
    int edad;
    char correo[50];
    char contrasena[20];
    int dadoDeBaja;
    char nacionalidad[50];
} Usuario;

// Estructura de Movimiento
typedef struct {
    int id;
    int idUsuario;
    char tipo[20];
    double monto;
    time_t fecha;
    char descripcion[100];
} Movimiento;

// Estructura de Factura
typedef struct {
    int id;
    int idUsuario;
    char numero[20];
    double montoTotal;
    time_t fechaEmision;
    char cliente[100];
    char descripcion[200];
} Factura;

Usuario cargarUsuario();
Usuario admin;
CuentaBancaria cargarCuenta(int idUsuario);
Movimiento cargarMovimiento(int idUsuario);
Factura cargarFactura(int idUsuario);


int cargarArchivoDeUsuario();
void cargarArchivoDeCuentas(int idUsuario);
void cargarArchivoDeMovimiento(int idUsuario);
void cargarArchivoDeFactura(int idUsuario);
int logearse();
int logOcrearCuenta();
void menuUser(int idUsuario);
void menuRoot(int idUsuario);
void mostrarMatrizNombres(int dimC, char matrizNombreID[][dimC], int validosF);
void idNombreMatriz(char ArchivoDeUsuarios[], Pila* pilaA);
void moverToPilaMontoID(char ArchivoDeCuentas[], Pila * pilaA, int dato);
int contarLineas(char nombreArchivo);
int contarLineasRecursivamente(FILE *archivo);

void tranferirMain(int idUsuario);
void sumarSaldoACuentaUsuario(int numeroDeCuentaTransferir, double saldo);
void restarSaldoACuentaUsuario(int numeroDeCuentaUsuario, double saldo);

#endif // ALTA_H_INCLUDED
