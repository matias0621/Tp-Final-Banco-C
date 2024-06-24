#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alta.h"
#include "baja.h"
#include "MODIFICACION.h"
#include "consulta.h"
#include "ordenamiento.h"

int main() {
    strcpy(admin.correo,correoAdmin);
    strcpy(admin.contrasena,contraAdmin);
    int idUsuario;
    int op;


    printf("|--------------------------------------|");
    printf("\n|%-14sBIENVENIDO%-14s|"," "," ");
    printf("\n|--------------------------------------|\n");

    op = logOcrearCuenta();

    switch(op) {
        case 1:
            idUsuario = logearse();
            break;
        case 2:
            idUsuario = cargarArchivoDeUsuario();
            break;
    }

    if (idUsuario != -1)
    {
        if (idUsuario != 0)
        {
            menuUser(idUsuario);
        }
        else
        {
            menuRoot(idUsuario);
        }
    }
    printf("\nSaliendo..\n");

    return 0;
}

void menuRoot(int idUsuario) {
    char control = 'n';
    int lineas;
    int dato;
    Pila pilaA;
    inicpila(&pilaA);

    do {
        int funcion;
        printf("|--------------------------MENU PRINCIPAL--------------------------|");
        printf("\n[1]-  Crear nuevo usuario");
        printf("\n[2]-  Crear nueva cuenta bancaria");
        printf("\n[3]-  Crear nueva factura");
        printf("\n[4]-  Crear nuevo movimiento");
        printf("\n[5]-  Mostrar archivo de usuarios");
        printf("\n[6]-  Buscar usuario por ID");
        printf("\n[7]-  Mostrar archivo de cuentas bancarias");
        printf("\n[8]-  Buscar cuenta bancaria por ID");
        printf("\n[9]-  Mostrar archivo de facturas");
        printf("\n[10]- Buscar facturas por ID");
        printf("\n[11]- Mostrar archivo de movimientos");
        printf("\n[12]- Buscar movimientos por ID");
        printf("\n[13]- Mostrar los nombres de los usuarios con monto mayor al elegido");
        printf("\n[14]- Eliminar cuenta por ID");
        printf("\n[15]- Eliminar usuario por ID");
        printf("\n[0]-  Salir");
        printf("\n\nIngrese su opcion: ");
        fflush(stdin);
        scanf("%d",&funcion);

        switch(funcion) {
            case 1:
                printf("\n");
                idUsuario = cargarArchivoDeUsuario();
                printf("%d", idUsuario);
                break;
            case 2:
                cargarArchivoDeCuentas(idUsuario);
                break;
            case 3:
                cargarArchivoDeFactura(idUsuario);
                break;
            case 4:
                cargarArchivoDeMovimiento(idUsuario);
                break;
            case 5:
                consultaMostrarUsuarioGeneral(ArchivoDeUsuarios);
                lineas = contarLineas(ArchivoDeUsuarios);
                printf("El archivo tiene %d líneas.\n", lineas);

                printf("\nMostrar en orden? s/n");
                fflush(stdin);
                scanf(" %c",&control);
                if(control=='s') {
                    do {
                        printf("\nPor Insercion o Seleccion? I / S");
                        fflush(stdin);
                        scanf(" %c",&control);
                    } while (control != 'i' && control != 's');

                    if(control == 'i') {
                        ordenamientoIncersionUsuario();
                    } else {
                        obtenerUsuariosDeArchivoYPasarlosAUnArreglo();
                    }
                }
                break;
            case 6:
                consultaUsuarioById(ArchivoDeUsuarios, idUsuario);
                break;
            case 7:
                fflush(stdin);
                consultaMostrarCuentasGeneral(ArchivoDeCuentas);


                printf("\nMostrar en orden? s/n");
                fflush(stdin);
                scanf(" %c",&control);
                if(control=='s') {
                    system("cls");
                    do {
                        printf("\nPor Insercion o Seleccion? I / S");
                        fflush(stdin);
                        scanf(" %c",&control);
                    } while (control != 'i' && control != 's');

                    if(control == 'i') {
                        ordenamientoIncersionCuenta();
                    } else {
                        obtenerCuentasDeArchivoYPasarlosAUnArreglo();
                    }
                }
                lineas = contarLineas(ArchivoDeCuentas);
                printf("El archivo tiene %d líneas.\n", lineas);
                break;
            case 8:
                consultaMostrarCuentasByIdUsuario(ArchivoDeCuentas, idUsuario);
                break;
            case 9:
                consultaMostrarFacturaGeneral(ArchivoDeFacturas);

                printf("\nMostrar en orden? s/n");
                fflush(stdin);
                scanf(" %c",&control);
                if(control=='s') {
                    system("cls");
                    do {
                        printf("\nPor Insercion o Seleccion? I / S");
                        fflush(stdin);
                        scanf(" %c",&control);
                    } while (control != 'i' && control != 's');

                    if(control == 'i') {
                        ordenamientoInsercionFacturas();
                    } else {
                        obtenerFacturasDeArchivoYPasarlosAUnArreglo();
                    }
                }
                lineas = contarLineas(ArchivoDeFacturas);
                printf("El archivo tiene %d líneas.\n", lineas);
                break;
            case 10:
                consultaMostrarFacturaById(ArchivoDeFacturas, idUsuario);
                break;
            case 11:
                consultaMostrarMovimientosGeneral(ArchivoDeMovimientos);

                printf("\nMostrar en orden? s/n");
                fflush(stdin);
                scanf(" %c",&control);
                if(control=='s') {
                    do {
                        printf("\nPor Insercion o Seleccion? I / S");
                        fflush(stdin);
                        scanf(" %c",&control);
                    } while (control != 'i' && control != 's');

                    if(control == 'i') {
                        ordenamientoIncersionMovimientos();
                    } else {
                        obtenerMovimientosDeArchivoYPasarlosAUnArreglo();
                    }
                }
                lineas = contarLineas(ArchivoDeMovimientos);
                printf("El archivo tiene %d líneas.\n", lineas);
                break;
            case 12:
                consultaMostrarMovimientosById(ArchivoDeMovimientos, idUsuario);
                break;
            case 13:
                printf("\nIngresar saldo a comparar:\n");
                scanf(" %d",&dato);
                moverToPilaMontoID(ArchivoDeCuentas, &pilaA, dato);
                idNombreMatriz(ArchivoDeUsuarios, &pilaA);
                break;
            case 14:
                eliminaCuentaRoot(ArchivoDeCuentas, ArchivoDesactivados);
                break;
            case 15:
                eliminaUsuarioRoot(ArchivoDeUsuarios);
                break;
            case 0:
                printf("\nDesea Salir? S/N:");
                scanf(" %c", &control);
                fflush(stdin);
                return;
            default:
                printf("Opción inválida. Por favor, ingrese una opción válida.\n");
        }
        printf("\n");
        system("pause");
        system("cls");
    } while(control == 'n' || control == 'N');
}

void menuUser(int idUsuario) {
    char control = 'n';

    do {
        int funcion;
        printf("|--------------------------MENU PRINCIPAL--------------------------|");
        printf("\n[1]-  Crear nueva cuenta bancarias");
        printf("\n[2]-  Crear nuevo movimientos");
        printf("\n[3]-  Crear nueva factura");
        printf("\n[4]-  Mostrar mi usuario");
        printf("\n[5]-  Mostrar mi/s cuenta/s bancaria/s");
        printf("\n[6]-  Mostrar mis facturas");
        printf("\n[7]-  Mostrar mis movimientos");
        printf("\n[8]-  Modificar mi usuario");
        printf("\n[9]-  Modificar mi cuenta");
        printf("\n[10]- Desactivar cuenta");
        printf("\n[11]- Eliminar cuenta");
        printf("\n[12]- Eliminar mi usuario");
        printf("\n[13]- Transferir");
        printf("\n[0]-  Salir");
        printf("\n\nIngrese su opcion: ");
        fflush(stdin);
        scanf("%d",&funcion);

        switch(funcion) {
            case 1:
                printf("\n");
                cargarArchivoDeCuentas(idUsuario);
                break;
            case 2:
                printf("\n");
                cargarArchivoDeMovimiento(idUsuario);
                break;
            case 3:
                printf("\n");
                cargarArchivoDeFactura(idUsuario);
                break;
            case 4:
                printf("\n");
                consultaUsuarioById(ArchivoDeUsuarios, idUsuario);
                break;
            case 5:
                printf("\n");
                consultaMostrarCuentasByIdUsuario(ArchivoDeCuentas, idUsuario);
                break;
            case 6:
                printf("\n");
                consultaMostrarFacturaById(ArchivoDeFacturas,idUsuario);
                break;
            case 7:
                printf("\n");
                consultaMostrarMovimientosById(ArchivoDeMovimientos,idUsuario);
                break;
            case 8:
                printf("\n");
                modificarUsuarioPorID(ArchivoDeUsuarios,idUsuario);
                break;
            case 9:
                printf("\n");
                modificarCuentaPorNumero(ArchivoDeCuentas,idUsuario);
                break;
            case 10:
                printf("\n");
                desactivarCuenta(ArchivoDeCuentas,ArchivoDesactivados,idUsuario);
                break;
            case 11:
                printf("\n");
                eliminaCuenta(ArchivoDeCuentas,ArchivoDesactivados,idUsuario);
                break;
            case 12:
                printf("\n");
                eliminaUsuario(ArchivoDeUsuarios,idUsuario);
                break;
            case 13:
                printf("\n");
                tranferirMain(idUsuario);
                break;
            case 0:
                printf("\nDesea Salir? S/N:");
                scanf(" %c", &control);
                return;
            default:
                printf("Opción inválida. Por favor, ingrese una opción válida.\n");
        }
        printf("\n");
        system("pause");
        system("cls");
    } while(control == 'n' || control == 'N');
}

