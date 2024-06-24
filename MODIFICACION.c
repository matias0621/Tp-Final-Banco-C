#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "MODIFICACION.h"
/*/// Mostrar un usuario
void mostrarUnUsuario(Usuario A) {
    printf("-------------------------------------\n");
    printf("ID: %d\n", A.id);
    printf("Nombre: %s\n", A.nombre);
    printf("Apellido: %s\n", A.apellido);
    printf("Correo: %s\n", A.correo);
    printf("Contraseña: %s\n", A.contrasena);
    printf("Nacionalidad: %s\n", A.nacionalidad);
    printf("Dado de Baja: %d\n", A.dadoDeBaja);
    printf("-------------------------------------\n");
}
*/
/*/// Mostrar todos los usuarios
void mostrarArregloDeUsuarios(Usuario A[], int validos) {
    for(int i = 0; i < validos; i++) {
        printf("Usuario Nro %d:\n", i+1);
        mostrarUnUsuario(A[i]);
    }
}
*/
/*/// Mostrar una cuenta bancaria
void mostrarUnaCuenta(CuentaBancaria cuenta) {
    printf("-------------------------------------\n");
    printf("Número de cuenta: %d\n", cuenta.numero_cuenta);
    printf("ID de usuario: %d\n", cuenta.id_usuario);
    printf("Saldo: %.2lf\n", cuenta.saldo);
    printf("Tipo de cuenta: %s\n", cuenta.tipo_cuenta);
    printf("-------------------------------------\n");
}
*/
/*/// Mostrar todas las cuentas bancarias
void mostrarArregloDeCuentas(CuentaBancaria cuentas[], int validos) {
    for(int i = 0; i < validos; i++) {
        printf("Cuenta bancaria Nro %d:\n", i+1);
        mostrarUnaCuenta(cuentas[i]);
    }
} */
/// Buscar usuario por ID
int buscarEnUsuario (Usuario A[], int validos, int idAux) {
    int i = 0;
    int flag = 0;
    int pos = -1;

    while (i < validos && flag == 0) {
        if(idAux == A[i].id) {
            flag = 1;
            pos = i;
        }
        i++;
    }
    return pos;
}

/// Buscar cuenta bancaria por número de cuenta
int buscarEnCuenta(CuentaBancaria cuentas[], int validos, int numeroCuenta) {
    int i = 0;
    int flag = 0;
    int pos = -1;

    while (i < validos && flag == 0) {
        if(numeroCuenta == cuentas[i].numero_cuenta) {
            flag = 1;
            pos = i;
        }
        i++;
    }
    return pos;
}

/// Modificar un usuario específico
void modificarUsuario(Usuario A[], int validos, int pos) {
    printf("Se modificará el usuario con ID: [%d]\n", A[pos].id);
    int opcion;
    do {
        printf("¿Qué campo quiere modificar?\n");
        printf("\t[0] Salir...\n");
        printf("\t[1] Nombre\n");
        printf("\t[2] Apellido\n");
        printf("\t[3] Correo\n");
        printf("\t[4] Contraseña\n");
        printf("\t[5] Nacionalidad\n");
        printf("\t[6] Todos los campos\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: {
                printf("Ingrese nuevo nombre: ");
                scanf("%s", A[pos].nombre);
                break;
            }
            case 2: {
                printf("Ingrese nuevo apellido: ");
                scanf("%s", A[pos].apellido);
                break;
            }
            case 3: {
                printf("Ingrese nuevo correo: ");
                scanf("%s", A[pos].correo);
                break;
            }
            case 4: {
                printf("Ingrese nueva contraseña: ");
                scanf("%s", A[pos].contrasena);
                break;
            }
            case 5: {
                printf("Ingrese nueva nacionalidad: ");
                scanf("%s", A[pos].nacionalidad);
                break;
            }
            case 6: {
                printf("Ingrese nuevo nombre: ");
                scanf("%s", A[pos].nombre);
                printf("Ingrese nuevo apellido: ");
                scanf("%s", A[pos].apellido);
                printf("Ingrese nuevo correo: ");
                scanf("%s", A[pos].correo);
                printf("Ingrese nueva contraseña: ");
                scanf("%s", A[pos].contrasena);
                printf("Ingrese nueva nacionalidad: ");
                scanf("%s", A[pos].nacionalidad);
                break;
            }
            case 0: {
                printf("Saliendo de la modificación...\n");
                break;
            }
            default: {
                printf("Opción no válida. Intente de nuevo.\n");
                break;
            }
        }
    } while(opcion != 0);
    system("pause");
}

/// Modificar una cuenta bancaria específica
void modificarCuenta(CuentaBancaria cuentas[], int validos, int pos) {
    printf("Se modificará la cuenta con número: [%d]\n", cuentas[pos].numero_cuenta);
    int opcion;
    do {
        printf("¿Qué campo quiere modificar?\n");
        printf("\t[0] Salir...\n");
        ///printf("\t[1] ID de usuario\n"); consultar
        printf("\t[1] Saldo\n");
        printf("\t[2] Tipo de cuenta\n");
        printf("\t[3] Todos los campos\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            /*case 1: {
                printf("Ingrese nuevo ID de usuario: ");
                scanf("%d", &cuentas[pos].id_usuario);
                break;
                }*/
            case 1: {
                printf("Ingrese nuevo saldo: ");
                scanf("%lf", &cuentas[pos].saldo);
                break;
            }
            case 2: {
                printf("Ingrese nuevo tipo de cuenta: ");
                scanf("%s", cuentas[pos].tipo_cuenta);
                break;
            }
            case 3: {
                printf("Ingrese nuevo ID de usuario: ");
                scanf("%d", &cuentas[pos].id_usuario);
                printf("Ingrese nuevo saldo: ");
                scanf("%lf", &cuentas[pos].saldo);
                printf("Ingrese nuevo tipo de cuenta: ");
                scanf("%s", cuentas[pos].tipo_cuenta);
                break;
            }
            case 0: {
                printf("Saliendo de la modificación...\n");
                break;
            }
            default: {
                printf("Opción no válida. Intente de nuevo.\n");
                break;
            }
        }
    } while(opcion != 0);
    system("pause");
}

/// Guardar usuarios en archivo
void guardarUsuariosEnArchivo(Usuario A[], int validos) {
    FILE *archivo;
    archivo = fopen(ArchivoDeUsuarios, "r+b");
    if (archivo != NULL) {
        fwrite(A, sizeof(Usuario), validos, archivo);
        fclose(archivo);
    } else {
        printf("Error al abrir el archivo %s\n", ArchivoDeUsuarios);
    }
}

/// Guardar cuentas bancarias en archivo
void guardarCuentasEnArchivo(CuentaBancaria cuentas[], int validos)
{
    FILE *archivo;
    archivo = fopen(ArchivoDeCuentas, "r+b");
    if (archivo != NULL)
    {
        fwrite(cuentas, sizeof(CuentaBancaria), validos, archivo);
        fclose(archivo);
    }
    else
    {
        printf("Error al abrir el archivo %s\n", ArchivoDeCuentas);
    }
}
/*
/// Cargar usuarios desde archivo
int cargarUsuariosDesdeArchivo(Usuario A[])
{
    FILE *archivo;
    int leidos = 0;
    archivo = fopen(ArchivoDeUsuarios, "r+b");
    if (archivo != NULL)
    {
        while (fread(&A[leidos], sizeof(Usuario), 1, archivo) == 1)
        {
            leidos++;
        }
        fclose(archivo);
    } else
    {
        printf("Error al abrir el archivo %s\n", ArchivoDeUsuarios);
    }
    return leidos;
}

/// Cargar cuentas bancarias desde archivo
int cargarCuentasDesdeArchivo(CuentaBancaria cuentas[])
{
    FILE *archivo;
    int leidos = 0;
    archivo = fopen(ArchivoDeCuentas, "r+b");
    if (archivo != NULL)
    {
        while (fread(&cuentas[leidos], sizeof(CuentaBancaria), 1, archivo) == 1)
        {
            leidos++;
        }
        fclose(archivo);
    } else
    {
        printf("Error al abrir el archivo %s\n", ArchivoDeCuentas);
    }
    return leidos;
}
*/
void modificarUsuarioPorID(char ArchivoDeUsuarios[], int idUsuario)
{
    FILE* archi = fopen(ArchivoDeUsuarios, "r+b");

    if (archi != NULL) {
        Usuario a;
        int encontrado = 0;

        while (encontrado!=1 && fread(&a, sizeof(Usuario), 1, archi) > 0) {
            if (a.id == idUsuario) {
                printf("\nEstos son los datos actuales del usuario con ID %d:\n", idUsuario);
                mostrarUsuario(a);

                a = modificarDatosUsuario(a);

                fseek(archi,sizeof(Usuario)*(-1), SEEK_CUR);
                fwrite(&a, sizeof(Usuario), 1, archi);

                encontrado = 1;
            }
        }

        if (!encontrado) {
            printf("Usuario con ID %d no encontrado.\n", idUsuario);
        }

        fclose(archi);
    } else {
        printf("Error al abrir el archivo %s\n", ArchivoDeUsuarios);
    }
}
Usuario modificarDatosUsuario(Usuario a)
{
        printf("\nEstos son los datos actuales del usuario\n");
        mostrarUsuario(a);

        char control = 'n';

        printf("\n Desea modificar el nombre? SI = s. El nombre actual es: %s\n", a.nombre);
        fflush(stdin);
        scanf("%c",&control);
        if (control == 's'){
            printf("Ingrese el nuevo nombre:\n");
            fflush(stdin);
            gets(a.nombre);
        }
        control = 'n';

        printf("\n Desea modificar el apellido? SI = s. El apellido actual es: %s\n", a.apellido);
        fflush(stdin);
        scanf("%c",&control);
        if (control == 's'){
            printf("Ingrese el nuevo apellido:\n");
            fflush(stdin);
            gets(a.apellido);
        }
        control = 'n';

        printf("\n Desea modificar la edad? SI = s. La acutal es: %d\n", a.edad);
        fflush(stdin);
        scanf("%c",&control);
        if (control == 's'){
            printf("Ingrese la nueva edad:\n");
            scanf("%d", &a.edad);
        }
        control = 'n';

        printf("\n Desea modificar el correo? SI = s. El correo actual es: %s\n", a.correo);
        fflush(stdin);
        scanf("%c",&control);
        if (control == 's'){
            printf("Ingrese el nuevo correo:\n");
            fflush(stdin);
            gets(a.correo);
        }
        control = 'n';

        printf("\n Desea modificar la contrase%ca? SI = s. La contrasenia actual es: %s\n", 164 ,a.contrasena);
        fflush(stdin);
        scanf("%c",&control);
        if (control == 's'){
            printf("Ingrese la nueva contrasen%ca:\n", 164);
            fflush(stdin);
            gets(a.contrasena);
        }
        control = 'n';

        printf("\n Desea modificar la nacionalidad? SI = s. La nacionalidad actual es: %s\n", a.nacionalidad);
        fflush(stdin);
        scanf("%c",&control);
        if (control == 's'){
            printf("Ingrese la nueva nacionalidad:\n");
            fflush(stdin);
            gets(a.nacionalidad);
        }
        control = 'n';

        printf("\nAsi quedo modificado el usuario\n");
        mostrarUsuario(a);

    return a;
}



///Modificar Cuenta
void modificarCuentaPorNumero(char ArchivoDeCuentas[], int idUsuario)
{
    consultaMostrarCuentasByIdUsuario(ArchivoDeCuentas, idUsuario);
    int numeroCuenta;
    printf("Ingrese el numero de la cuenta que quiere modificar...\n");
    scanf("%d", &numeroCuenta);

    FILE* archi = fopen(ArchivoDeCuentas, "r+b");

    if (archi != NULL) {
        CuentaBancaria a;
        int encontrado = 0;

        while (encontrado !=1 && fread(&a, sizeof(CuentaBancaria), 1, archi) > 0) {
            if (a.numero_cuenta == numeroCuenta) {

                a = modificarDatosCuenta(ArchivoDeCuentas, numeroCuenta);

                fseek(archi,(-1)*sizeof(CuentaBancaria), SEEK_CUR);
                fwrite(&a, sizeof(CuentaBancaria), 1, archi);

                encontrado = 1;
            }
        }

        if (!encontrado) {
            printf("Cuenta bancaria con número %d no encontrada.\n", numeroCuenta);
        }

        fclose(archi);
    } else {
        printf("Error al abrir el archivo %s\n", ArchivoDeCuentas);
    }
}
CuentaBancaria modificarDatosCuenta(char ArchivoDeCuentas[],int numeroCuenta)
{
    FILE* archi;
    CuentaBancaria a;
    int flag=0;
    int op;
    int saldoIngresado = 0;

    archi = fopen(ArchivoDeCuentas, "r+b");
    if(archi)
    {
        while(flag!=1 && fread(&a,sizeof(CuentaBancaria),1,archi)>0)
        {
            if(numeroCuenta==a.numero_cuenta)
            {
                flag=1;
                char control = 'n';
                printf("\n Desea modificar el tipo de cuenta? SI = s. El actual es: %s\n", a.tipo_cuenta);
                fflush(stdin);
                scanf("%c",&control);
                if (control == 's')
                {
                    printf("Ingrese el nuevo tipo de cuenta:\n");
                    fflush(stdin);
                    gets(a.tipo_cuenta);
                    control = 'n';
                }

                printf("\n Desea modificar el saldo de la cuenta? SI = s. El actual es: %.2lf\n", a.saldo);
                fflush(stdin);
                scanf("%c",&control);

                while(control == 's'){


                printf("\nIngresar(1)");
                printf("\nSacar(2)\n");
                scanf("%d",&op);
                switch(op){
                case 1:
                    {
                        printf("Ingrese el monto que desea cargar a su saldo actual:\n");
                        scanf("%d", &saldoIngresado);
                        a.saldo = a.saldo + saldoIngresado;
                        break;
                    }
                case 2:
                    {
                        printf("Ingrese el monto que desea sacar de la cuenta:\n");
                        scanf("%d", &saldoIngresado);
                        a.saldo = a.saldo - saldoIngresado;
                        break;
                    }
                }
                printf("Desea realizar otra accion?: SI = s. \n");
                fflush(stdin);
                scanf("%c",&control);
                }
            }
        }
        printf("\nAsi quedo modificado el usuario\n");
        mostrarCuentaBancaria(a);
    }
        else
        {
            printf("\nNo pudo modificarse la cuenta\n");
        }

    return a;
}






