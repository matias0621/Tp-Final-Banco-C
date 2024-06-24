#ifndef MODIFICACION_H_INCLUDED
#define MODIFICACION_H_INCLUDED
#include "alta.h"
#include "consulta.h"
/// Definición de constantes globales
/*
extern const char ArchivoDeUsuarios[] = "usuarios";
extern const char ArchivoDeCuentas[] = "cuentas";
*/
/*
/// Structs
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

typedef struct {
    int numero_cuenta;
    int id_usuario;
    double saldo;
    char tipo_cuenta[20];
} CuentaBancaria;
*/

extern const char ArchivoDeUsuarios[];
extern const char ArchivoDeCuentas[];
extern const char ArchivoDeMovimientos[];
extern const char ArchivoDeFacturas[];
extern const char correoAdmin[];
extern const char contraAdmin[];
extern const char ArchivoDesactivados[];
/// Prototipado
///Case 1: Modificar Usuario
//void mostrarArregloDeUsuarios(Usuario A[], int validos);
//void mostrarUnUsuario(Usuario A);
int buscarEnUsuario(Usuario A[], int validos, int idAux);
void modificarUsuario(Usuario A[], int validos, int pos);
///////////////////////////////////////////////////////////////////////
///Case 2: Modificar CuentaBancaria
//void mostrarArregloDeCuentas(CuentaBancaria cuentas[], int validos);
//void mostrarUnaCuenta(CuentaBancaria cuenta);
int buscarEnCuenta(CuentaBancaria cuentas[], int validos, int numeroCuenta);
void modificarCuenta(CuentaBancaria cuentas[], int validos, int pos);
///////////////////////////////////////////////////////////////////////
///Case 3: Modificar ArchivoDeUsuarios
//void guardarUsuariosEnArchivo(Usuario A[], int validos);
//int cargarUsuariosDesdeArchivo(Usuario A[]);
void modificarUsuarioAeleccion(char ArchivoDeUsuarios[], int pos);
///////////////////////////////////////////////////////////////////////
///Case 4: Modificar ArchivoDeCuentas
//void guardarCuentasEnArchivo(CuentaBancaria cuentas[], int validos);
//int cargarCuentasDesdeArchivo(CuentaBancaria cuentas[]);
Usuario modificarDatosUsuario(Usuario a);
void modificarUsuarioPorID(char ArchivoDeUsuarios[], int idUsuario);
CuentaBancaria modificarDatosCuenta(char ArchivoDeCuentas[],int idUsuario);
void modificarCuentaPorNumero(char ArchivoDeCuentas[], int idUsuario);
///////////////////////////////////////////////////////////////////////

#endif // MODIFICACION_H_INCLUDED
