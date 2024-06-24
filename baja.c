#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "baja.h"

long obtieneCantDeCuentas(FILE* buffer)
{
    long espacio=0;
    fseek(buffer,0,SEEK_END);
    espacio =ftell(buffer) / sizeof(CuentaBancaria);

    return espacio;
}

///--------------------------------------------------------------------------------
///--------------------------------------------------------------------------------

void desactivarCuenta(char archivoCuentas[],char cuentasDesac[],int id)        ///MANDA CUENTA A DESACTIVADOS
{                                                                              ///Y REORDENA ARCHIVO PARA NO DEJAR ESPACIOS
    FILE* buffer;
    CuentaBancaria user;
    long total;
    CuentaBancaria* a;

    if(reafirmacion(cuentasDesac,id)==1)
    {
        buffer= fopen(archivoCuentas,"r+b");

        if(buffer)
        {
            total = obtieneCantDeCuentas(buffer);
            while(fread(&user,sizeof(CuentaBancaria),1,buffer)>0)
            {
                if (user.id_usuario == id)
                {
                    break;
                }
            }
            fclose(buffer);
            pasaCuentaToDesac(cuentasDesac, user);
            creaArregloSinEliminado(archivoCuentas,id,total,&a);
            nuevoArch(archivoCuentas,a,total);
        }
    }
}

///--------------------------------------------------------------------------------
///--------------------------------------------------------------------------------

void creaArregloSinEliminado(char archivoCuentas[], int idUsuarioELiminar, long totalCuentas, CuentaBancaria **arreglo)
{
    FILE* buf;
    CuentaBancaria cuenta;

    buf = fopen(archivoCuentas, "rb");
    if (buf)
    {
        *arreglo = malloc((totalCuentas-1) * sizeof(CuentaBancaria));
        if (*arreglo != NULL)
        {
            int indice = 0;
            while (fread(&cuenta, sizeof(CuentaBancaria), 1, buf) > 0)
            {
                if (cuenta.id_usuario != idUsuarioELiminar)
                {
                    (*arreglo)[indice++] = cuenta;
                }
            }
            fclose(buf);
        }
    }
    else
    {
        printf("Error: No se pudo abrir el archivo %s\n", archivoCuentas);
    }
}

///--------------------------------------------------------------------------------
///--------------------------------------------------------------------------------

void nuevoArch(char ArchivoDeCuentas[],CuentaBancaria arreglo[],long totalCuentas)
{
    FILE* buff;
    CuentaBancaria cuenta;

    buff=fopen(ArchivoDeCuentas,"wb");
    if (buff)
    {
        for (int i=0;i<totalCuentas;i++)
        {
            cuenta=arreglo[i];
            fwrite(&cuenta,sizeof(CuentaBancaria),1,buff);
        }
        fclose(buff);
    }
}

///--------------------------------------------------------------------------------
///--------------------------------------------------------------------------------

int confirmacion(char cuentasDesac[],int id)        ///Confirma si la cuenta NO esta desactivada
{
    FILE* buffer;
    CuentaBancaria user;
    int flag=1; ///la cuenta no esta desactivada

    buffer=fopen(cuentasDesac,"rb");
    if (buffer)
    {
        while(flag!=0 && fread(&user,sizeof(CuentaBancaria),1,buffer)>0)
        {
            if(user.id_usuario== id)
            {
                flag =0; ///la cuenta se encuentra en los desactivados
            }
        }
        fclose(buffer);
    }
    return flag;
}

///--------------------------------------------------------------------------------
///--------------------------------------------------------------------------------

int reafirmacion(char cuentasDesac[],int id) ///reafirma la eleccion del usuario
{
    int flag=0;
    char conf='j';

    if(confirmacion(cuentasDesac,id)==1)
    {
        printf("Quiere desactivar la cuenta? No podra realizar operaciones hasta volver a activarla.\n");
        while ((conf != 'n') && (conf != 's'))
        {
            printf("S / N : ");
            fflush(stdin);
            scanf(" %c",&conf);
        }
        if (conf=='s')
        {
            flag =1;
        }
    }else {
        printf("La cuenta ya se encuentra DESACTIVADA\n");
    }
    return flag;
}

///--------------------------------------------------------------------------------
///--------------------------------------------------------------------------------

void pasaCuentaToDesac(char cuentasDesac[],CuentaBancaria user)
{
    FILE* buffer;

    buffer = fopen(cuentasDesac,"ab");
    if(buffer)
    {
        fwrite(&user,sizeof(CuentaBancaria),1,buffer);

        fclose(buffer);
    }
}

///--------------------------------------------------------------------------------
///--------------------------------------------------------------------------------

long obtieneTamanioArchivoCuentas(char ArchivoDeCuentas[])
{
    FILE* buffer;
    long tamanio=0;

    buffer = fopen(ArchivoDeCuentas,"rb");
    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        tamanio= ftell(buffer);
        fclose(buffer);
    }
    return tamanio;
}

///--------------------------------------------------------------------------------
///--------------------------------------------------------------------------------

void eliminaCuenta(char archivoCuentas[], char cuentasDesac[], int id)      ///pasa la cuenta  al archivo cuenstasDesactivadas
{                                                                           ///y reordena el archivo de cuentas para no dejar espacios
    FILE* buffer;
    CuentaBancaria user;
    CuentaBancaria* a;
    char op = 'j';
    long total;

    printf("Seguro/a quiere ELIMINAR la cuenta?\n");
    while (op != 'n' && op != 's')
    {
        printf("S / N : ");
        fflush(stdin);
        scanf("%c", &op);
    }
    if (op == 's')
    {
        buffer = fopen(archivoCuentas, "r+b");
        if (buffer)
        {
            total = obtieneCantDeCuentas(buffer);
            a = malloc((total - 1) * sizeof(CuentaBancaria));
            while (fread(&user, sizeof(CuentaBancaria), 1, buffer)>0)
            {
                if (user.id_usuario == id)
                {
                    break;
                }
            }
            fclose(buffer);
            pasaCuentaToDesac(cuentasDesac, user);
            creaArregloSinEliminado(archivoCuentas,id,total,&a);
            nuevoArch(archivoCuentas,a,total);
        }
    }
}

///--------------------------------------------------------------------------------
///--------------------------------------------------------------------------------

int eliminaUsuario(char archivoUsuarios[], int id)        ///cambia valor user.dadodebaja a 1
{
    FILE* buffer;
    Usuario user;
    char op = 'j';
    int flag=0;

    printf("Seguro/a quiere ELIMINAR usuario?\n");
    while (op != 'n' && op != 's')
    {
        printf("S / N : ");
        fflush(stdin);
        scanf("%c", &op);
    }
    if (op == 's')
    {
        buffer = fopen(archivoUsuarios, "r+b");
        if (buffer)
        {
            while (flag!=1 && fread(&user, sizeof(Usuario), 1, buffer)>0)
            {
                if (user.id == id)
                {
                    user.dadoDeBaja=1;
                    fseek(buffer,-sizeof(Usuario),SEEK_CUR);
                    fwrite(&user,sizeof(Usuario),1,buffer);
                    flag=1;
                    printf("\nCuenta eliminada correctamente.\n");
                }
            }
            fclose(buffer);
        }
    }
    return flag;
}

///--------------------------------------------------------------------------------
///--------------------------------------------------------------------------------

int eliminaUsuarioRoot(char archivoUsuarios[])
{
    FILE* buffer;
    Usuario user;
    char op = 'j';
    int flag=0;
    int id;

    consultaMostrarUsuarioGeneral(archivoUsuarios);
    printf("\nIngrese ID de usuario a eliminar: \n");
    scanf(" %d",&id);
    while (op != 'n' && op != 's')
    {
        printf("S / N : ");
        fflush(stdin);
        scanf("%c", &op);
    }
    if (op == 's')
    {
        buffer = fopen(archivoUsuarios, "r+b");
        if (buffer)
        {
            while (flag!=1 && fread(&user, sizeof(Usuario), 1, buffer)>0)
            {
                if (user.id == id)
                {
                    user.dadoDeBaja=1;
                    fseek(buffer,-sizeof(Usuario),SEEK_CUR);
                    fwrite(&user,sizeof(Usuario),1,buffer);
                    flag=1;
                    printf("\nCuenta eliminada correctamente.\n");
                }
            }
            fclose(buffer);
        }
    }
    return flag;
}

///--------------------------------------------------------------------------------
///--------------------------------------------------------------------------------

void eliminaCuentaRoot(char archivoCuentas[], char cuentasDesac[])
{
    FILE* buffer;
    CuentaBancaria user;
    char op = 'j';
    long total;
    int id;
    CuentaBancaria* a;

    consultaMostrarCuentasGeneral(archivoCuentas);
    printf("\nIngrese ID de usuario a eliminar: \n");
    scanf(" %d",&id);
    while (op != 'n' && op != 's')
    {
        printf("S / N : ");
        fflush(stdin);
        scanf("%c", &op);
    }
    if (op == 's')
    {
        buffer = fopen(archivoCuentas, "r+b");
        if (buffer)
        {
            total = obtieneCantDeCuentas(buffer);
            while (fread(&user, sizeof(CuentaBancaria), 1, buffer)>0)
            {
                if (user.id_usuario == id)
                {
                    break;
                }
            }
            fclose(buffer);
            pasaCuentaToDesac(cuentasDesac, user);
            creaArregloSinEliminado(archivoCuentas,id,total,&a);
            nuevoArch(archivoCuentas,a,total);
        }
    }
}
