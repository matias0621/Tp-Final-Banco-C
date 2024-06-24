#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "consulta.h"
#define PRINTF_USER(label,format,value)printf("\n%-20s " format, label, value)
#define PRINTF_ACCOUNT(label,format,value)printf("\n%-20s " format, label, value)

///------------------CONSULTAS USUARIOS----------------////
///POR ID///
void consultaUsuarioById(char ArchivoDeUsuarios[], int id)
{
    int flag=0;
    Usuario a;
    FILE * buf;
    buf = fopen(ArchivoDeUsuarios,"rb");
    printf("\n\t\tCONSULTA USUARIO\n");
    if(buf != NULL)
    {
        while((fread(&a,sizeof(Usuario),1,buf)!=0)&&(flag==0))
        {
            if(id==a.id)
            {
                /// printf("\n\n\tConsulta Usuario por ID");
                if(a.dadoDeBaja!=1)
                {
                    mostrarUsuario(a);
                    flag=1;
                }

            }
        }
        fclose(buf);
    }
    else
    {
        printf("No se pudo abrir el archivo...");
    }
}

///USUARIO GENERAL///
void consultaMostrarUsuarioGeneral(char ArchivoDeUsuarios[])
{
    Usuario a;
    FILE * buf;
    buf = fopen(ArchivoDeUsuarios,"rb");
    printf("\n\t\tUSUARIOS");
    printf("\n\t\t--------\n");
    if(buf != NULL){
            while(fread(&a,sizeof(Usuario),1,buf)!=0){
                if(a.dadoDeBaja==0)
                {
                    mostrarUsuario(a);
                }
            }
        fclose(buf);
    } else{
        printf("No se pudo abrir el archivo...");
    }

}
void mostrarUsuario(Usuario a)
{
    PRINTF_USER("ID:","%d",a.id);
    PRINTF_USER("Nombre:","%s",a.nombre);
    PRINTF_USER("Apellido:","%s",a.apellido);
    PRINTF_USER("Edad:","%d",a.edad);
    PRINTF_USER("Correo:","%s",a.correo);
    PRINTF_USER("Contrasenia:","%s",a.contrasena);
    PRINTF_USER("Nacionalidad:","%s",a.nacionalidad);
    printf("\n--------------------------------------\n");
   /* printf("\n%-30s %d","ID:",a.id);
    printf("\n%-30s %s","Nombre:",a.nombre);
    printf("\n%-30s %s","Apellido:",a.apellido);
    printf("\n%-30s %s","Correo:",a.correo);
    printf("\n%-30s %s","Contrasenia:",a.contrasena);
    printf("\n%-30s %s","Nacionalidad:",a.nacionalidad);
    printf("\n--------------------------------\n");
    */
}
///****************************************************************************************************///



///-------------------CONSULTAS CUENTAS BANCARIAS-----------------///
///POR ID USUARIO///
void consultaMostrarCuentasByIdUsuario(char ArchivoDeCuentas[], int idUsuario)
{
    CuentaBancaria a;
    FILE * buf;
    buf = fopen(ArchivoDeCuentas,"rb");

    printf("\n\t\tCONSULTA CUENTA BANCARIA");
    if(buf != NULL){
            while((fread(&a,sizeof(CuentaBancaria),1,buf)!=0)){
                    if(idUsuario == a.id_usuario){
                        mostrarCuentaBancaria(a);
                    }

            }
        fclose(buf);
    } else{
        printf("No se pudo abrir el archivo...");
    }

}
///CUENTAS BANCARIAS GENERAL///
void consultaMostrarCuentasGeneral(char ArchivoDeCuentas[])
{
    CuentaBancaria a;
    FILE * buf;
    buf = fopen(ArchivoDeCuentas,"rb");

    printf("\n\tCUENTAS BANCARIAS");
    printf("\n\t-----------------\n");
    if(buf != NULL){
            while(fread(&a,sizeof(CuentaBancaria),1,buf)!=0){
                mostrarCuentaBancaria(a);
            }
        fclose(buf);
    } else{
        printf("No se pudo abrir el archivo...");
    }

}
void mostrarCuentaBancaria(CuentaBancaria a)
{
    PRINTF_ACCOUNT("Numero de cuenta:","%d",a.numero_cuenta);
    PRINTF_ACCOUNT("ID Usuario:","%d",a.id_usuario);
    PRINTF_ACCOUNT("Saldo:","%.2lf",a.saldo);
    PRINTF_ACCOUNT("Tipo de cuenta:","%s",a.tipo_cuenta);
    printf("\n-----------------------------\n");
    /*
    printf("\n%-30s %d","Numero de Cuenta:",a.numero_cuenta);
    printf("\n%-30s %d","ID Usuario:",a.id_usuario);
    printf("\n%-30s %.2lf","Saldo:",a.saldo);
    printf("\n%-30s %s","Tipo de cuenta:",a.tipo_cuenta);
    printf("\n----------------------------------------\n");
    */
}
///*****************************************************************************************************///



///---------------------CONSULTAS MOVIMIENTOS---------------------///
///POR ID///
void consultaMostrarMovimientosById(char ArchivoDeMovimientos[], int id)
{
    int flag=0;
    Movimiento a;
    FILE * buf;
    buf = fopen(ArchivoDeMovimientos,"rb");
    printf("\n\t\tCONSULTA MOVIMIENTO");
    if(buf != NULL){
            while((fread(&a,sizeof(Movimiento),1,buf)!=0) && (flag==0)){
                    if(id == a.idUsuario){
                        mostrarMovimiento(a);
                        flag=1;
                    }
            }
        fclose(buf);
    } else{
        printf("No se pudo abrir el archivo...");
    }

}
///MOVIMIENTO GENERAL///
void consultaMostrarMovimientosGeneral(char ArchivoDeMovimientos[])
{
    Movimiento a;
    FILE * buf;
    buf = fopen(ArchivoDeMovimientos,"rb");
    printf("\n\t\tMOVIMIENTOS");
    printf("\n\t\t-----------\n");
    if(buf != NULL){
            while(fread(&a,sizeof(Movimiento),1,buf)!=0){
                mostrarMovimiento(a);
            }
        fclose(buf);
    } else{
        printf("No se pudo abrir el archivo...");
    }

}
void mostrarMovimiento(Movimiento a)
{
    printf("\n%-20s %d","ID:",a.id);
    printf("\n%-20s %s","Tipo:",a.tipo);
    printf("\n%-20s %.2lf","Monto:",a.monto);
    printf("\n%-20s %s","Fecha de emision:",ctime(&a.fecha));///*****FALTA TIPO DE DATO PARA MOSTRAR FECHA******///
    printf("%-20s %s","Descripcion:",a.descripcion);
    printf("\n---------------------------------------------\n");
}
///*****************************************************************************************************************///



///--------------CONSULTAS FACTURAS---------------///
///POR ID///
void consultaMostrarFacturaById(char ArchivoDeFacturas[], int id)
{
    int flag=0;
    Factura a;
    FILE * buf;
    buf = fopen(ArchivoDeFacturas,"rb");
    printf("\n\t\tCONSULTA FACTURA");
    if(buf != NULL){
            while((fread(&a,sizeof(Factura),1,buf)!=0) && (flag==0)){
                    if(id == a.idUsuario){
                           mostrarFactura(a);
                           flag=1;
                    }
            }
        fclose(buf);
    } else{
        printf("No se pudo abrir el archivo...");
    }

}
///FACTURA GENERAL///
void consultaMostrarFacturaGeneral(char ArchivoDeFacturas[])
{
    Factura a;
    FILE * buf;
    buf = fopen(ArchivoDeFacturas,"rb");
    printf("\n\t\tFACTURAS");
    printf("\n\t\t--------\n");
    if(buf != NULL){
            while(fread(&a,sizeof(Factura),1,buf)!=0){
                mostrarFactura(a);
            }
        fclose(buf);
    } else{
        printf("No se pudo abrir el archivo...");
    }

}
void mostrarFactura(Factura a)
{
    printf("\n%-20s %d","ID:",a.id);
    printf("\n%-20s %s","Numero:",a.numero);
    printf("\n%-20s %.2lf","Monto Total:",a.montoTotal);
    printf("\n%-20s %s","Fecha de emision:",ctime(&a.fechaEmision));///*****FALTA TIPO DE DATO PARA MOSTRAR FECHA******///
    printf("%-20s %s","Cliente:",a.cliente);
    printf("\n%-20s %s","Descripcion:",a.descripcion);
    printf("\n---------------------------------------------\n");
}
