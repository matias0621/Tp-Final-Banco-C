#ifndef ORDENAMIENTO_H_INCLUDED
#define ORDENAMIENTO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "alta.h"

// Prototipos para usuarios
void ordenamientoIncersionUsuario();
int pasarDelArchivoAlArray(FILE *buff, Usuario arrayUsuario[]);
void ordenacionInsercion(Usuario A[], int validos);
void imprimirUsuarios(Usuario usuarios[], int n);
void insertarUsuariorPorEdad(Usuario A[], int ultPosVal, Usuario dato);

// Prototipos para cuentas
void ordenamientoIncersionCuenta();
int pasarDelArchivoAlArrayDeCuenta(FILE *buff, CuentaBancaria cuentaArray[]);
void ordenacionInsercionCuenta(CuentaBancaria A[], int validos);
void imprimirCuentas(CuentaBancaria cuenta[], int n);
void insertarCuentaPorSaldo(CuentaBancaria A[], int ultPosVal, CuentaBancaria dato);

// Prototipos para facturas
void ordenamientoInsercionFacturas();
int pasarDelArchivoAlArrayDeFacturas(FILE *buff, Factura facturasArray[]);
void ordenacionInsercionFactura(Factura A[], int validos);
void imprimirFactura(Factura factura[], int n);
void insertarFacturaPorMontoTotal(Factura A[], int ultPosVal, Factura dato);

// Prototipos para movimientos
void ordenamientoIncersionMovimientos();
int pasarDelArchivoAlArrayDeMovimientos(FILE *buff, Movimiento movimentoArray[]);
void ordenacionInsercionMovimiento(Movimiento A[], int validos);
void imprimirMovimiento(Movimiento movimiento[], int n);
void insertarMovimientoPorMonto(Movimiento A[], int ultPosVal, Movimiento dato);

//Seleccion
void obtenerUsuariosDeArchivoYPasarlosAUnArreglo();
int sacarLosUsuariosdelArchivo(FILE *buff, Usuario usuarios[50]);

void obtenerCuentasDeArchivoYPasarlosAUnArreglo();
int sacarLasCuentasDelArchivo(FILE *buff, CuentaBancaria cuentas[50]);

void obtenerFacturasDeArchivoYPasarlosAUnArreglo();
int sacarLasFacturasDelArchivo(FILE *buff, Factura facturas[50]);

void obtenerMovimientosDeArchivoYPasarlosAUnArreglo();
int sacarLosMovimientosDelArchivo(FILE *buff, Movimiento movimientos[]);

//void imprimirStrings(char arr[][100], int size);

void ordenamientoPorSeleccionUsuarios(Usuario usuarios[], int size);
void ordenamientoPorSeleccionCuentas(CuentaBancaria cuentas[], int size);
void ordenamientoPorSeleccionFacturas(Factura facturas[], int size);
void ordenamientoPorSeleccionMovimientos(Movimiento movimientos[], int n);
void imprimirUsuariosArray(Usuario usuarios[], int tamanio);
void imprimirCuentasArray(CuentaBancaria cuentas[], int tamanio);
void imprimirFacturasArray(Factura facturas[], int size);
void imprimirMovimientosArray(Movimiento movimientos[], int n);


#endif // ORDENAMIENTO_H_INCLUDED
