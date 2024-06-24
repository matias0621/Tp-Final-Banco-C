#include "alta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de constantes globales
const char ArchivoDeUsuarios[] = "usuarios";
const char ArchivoDeCuentas[] = "cuentas";
const char ArchivoDeMovimientos[] = "movimientos";
const char ArchivoDeFacturas[] = "facturas";
const char ArchivoDesactivados[] = "desactivados.bin";
const char correoAdmin[] = "admin";
const char contraAdmin[] = "admin";

int cargarArchivoDeUsuario() {
    FILE *buff;
    buff = fopen(ArchivoDeUsuarios, "a+b");
    Usuario usuario;
    Usuario aux;
    int idUsuario;

    if (buff) {
        usuario = cargarUsuario();

        while((fread(&aux, sizeof(Usuario), 1, buff)) > 0){
            if (aux.id == usuario.id){
                srand(time(NULL));
                usuario.id = rand() % 1001;
            }

            if (strcmp(aux.correo, usuario.correo) == 0){
                printf("Ese correo ya esta registrado ingrese otro\n");
                fflush(stdin);
                gets(usuario.correo);
            }
        }

        fwrite(&usuario, sizeof(Usuario), 1, buff);
        idUsuario = usuario.id;
        printf("\n Usuario creado correctamente\n");
        fclose(buff);
    }

    return idUsuario;
}

void cargarArchivoDeCuentas(int idUsuario) {
    FILE *buff;
    buff = fopen(ArchivoDeCuentas, "ab");
    CuentaBancaria cuenta;

    if (buff) {
        cuenta = cargarCuenta(idUsuario);
        fwrite(&cuenta, sizeof(CuentaBancaria), 1, buff);
        printf("\nCuenta creada correctamente\n");
        fclose(buff);
    }else{
    printf("\nNo pudo crearse la cuenta\n");
    }


}

void cargarArchivoDeMovimiento(int idUsuario) {
    FILE *buff;
    buff = fopen(ArchivoDeMovimientos, "ab");
    Movimiento mov;

    if (buff) {
        mov = cargarMovimiento(idUsuario);
        fwrite(&mov, sizeof(Movimiento), 1, buff);
        printf("\nMovimiento realizado correctamente\n");
        fclose(buff);
    }else{
    printf("\nNo se pudo realizar el movimiento\n");
    }


}

void cargarArchivoDeFactura(int idUsuario) {
    FILE *buff;
    buff = fopen(ArchivoDeFacturas, "ab");
    Factura fact;

    if (buff) {
        fact = cargarFactura(idUsuario);
        fwrite(&fact, sizeof(Factura), 1, buff);
        printf("\nFactura creada correctamente\n");
        fclose(buff);
    }else{
    printf("\nNo se pudo realizar la factura\n");
    }


}

Usuario cargarUsuario() {
    Usuario usuario;
    srand(time(NULL));
    usuario.id = rand() % 1001;
    ///Si este campo es 0 el usuario NO esta dado de baja
    usuario.dadoDeBaja = 0;

    printf("Ingrese su nombre\n");
    fflush(stdin);
    gets(usuario.nombre);

    printf("Ingrese su apellido\n");
    fflush(stdin);
    gets(usuario.apellido);

    printf("Ingrese su edad debe ser mayor a 18\n");
    fflush(stdin);
    scanf("%d", &usuario.edad);

    while(usuario.edad < 18){
        printf("Debe ser mayor de edad, ingrese una edad valida");
        fflush(stdin);
        scanf("%d", &usuario.edad);
    }

    printf("Ingrese su correo\n");
    fflush(stdin);
    gets(usuario.correo);

    printf("Ingrese su contrase%cia\n", 164);
    fflush(stdin);
    gets(usuario.contrasena);

    printf("Ingrese su nacionalidad\n");
    fflush(stdin);
    gets(usuario.nacionalidad);

    return usuario;
}

CuentaBancaria cargarCuenta(int idUsuario) {
    CuentaBancaria cuenta;
    srand(time(NULL));
    cuenta.numero_cuenta = rand() % 1000000;
    cuenta.id_usuario = idUsuario;
    printf("Ingrese el saldo\n");
    scanf("%lf", &cuenta.saldo);
    printf("Ingrese el tipo de cuenta\n");
    scanf("%s", cuenta.tipo_cuenta);
    fflush(stdin);

    return cuenta;
}

Movimiento cargarMovimiento(int idUsuario) {
    int numeroDeCuenta = 0;
    consultaMostrarCuentasByIdUsuario(ArchivoDeCuentas, idUsuario);
    printf("\nIngrese el numero de la cuenta que quiere usar\n");
    scanf("%d", &numeroDeCuenta);

    Movimiento mov;
    srand(time(NULL));
    mov.id = rand() % 1000000;
    mov.idUsuario = idUsuario;
    printf("Ingrese el tipo de movimiento\n");
    scanf("%s", mov.tipo);
    printf("Ingrese el monto\n");
    scanf("%lf", &mov.monto);
    mov.fecha = time(NULL);
    printf("Ingrese una descripcion\n");
    getchar(); // Limpiar el buffer del '\n' dejado por scanf
    gets(mov.descripcion);
    fflush(stdin);



    if (saldoSuficiente(numeroDeCuenta, mov.monto)){
        restarSaldoACuentaUsuario(numeroDeCuenta, mov.monto);
    }

    return mov;
}

Factura cargarFactura(int idUsuario) {
    Factura fact;
    srand(time(NULL));
    fact.id = rand() % 1000000;
    fact.idUsuario = idUsuario;
    printf("Ingrese el numero de factura\n");
    scanf("%s", fact.numero);
    printf("Ingrese el monto total\n");
    scanf("%lf", &fact.montoTotal);
    fact.fechaEmision = time(NULL);
    printf("Ingrese el nombre del cliente\n");
    getchar(); // Limpiar el buffer del '\n' dejado por scanf
    gets(fact.cliente);
    printf("Ingrese una descripcion\n");
    gets(fact.descripcion);
    fflush(stdin);

    return fact;
}

int logearse(){
    FILE * buff;
    int idUsuario = -1;

    char mail[50];
    char contrasenia[50];

    int correaEncontrado = 0;
    int contraEncontrada = 0;

    Usuario a;

    printf("Ingrese su mail\n");
    fflush(stdin);
    gets(mail);

    printf("Ingrese su contra%cia\n", 164);
    fflush(stdin);
    gets(contrasenia);

    if(strcmpi(mail,correoAdmin)==0)
    {
        correaEncontrado = 1;
        if(strcmpi(contrasenia,contraAdmin)==0)
        {
            contraEncontrada = 1;
            idUsuario = 0;
        }
    }
    else
    {
        buff = fopen(ArchivoDeUsuarios, "rb");
        if (buff)
        {
            while((fread(&a,sizeof(Usuario),1,buff))> 0)
            {
                if (strcmp(a.correo, mail) == 0)
                {
                    correaEncontrado = 1;

                    if (strcmp(a.contrasena, contrasenia) == 0)
                    {
                        contraEncontrada = 1;

                        idUsuario = a.id;
                    }
                }
            }
            fclose(buff);
        }
    }
    if (correaEncontrado == 0)
            {
                printf("El correo electronico no es correcto\n");
            }
    if (contraEncontrada == 0)
            {
                printf("La contrase%ca no es correcta\n",164);
            }

    return idUsuario;
}

int logOcrearCuenta()
{
    int op=0;
    while (op!=1 && op!=2)
    {
        printf("\n[1]-  Loguearse");
        printf("\n");
        printf("\n[2]-  Crear Usuario");
        printf("\n");
        printf("\nIngrese opcion (1-2): ");
        scanf(" %d",&op);
    }
    system("cls");
    return op;
}

/// Pasa a una pila los id_usuarios que sean mayor a un determinado monto
void moverToPilaMontoID(char ArchivoDeCuentas[], Pila * pilaA, int dato)/// pasarlo por parametro (main)int dato = saldo a comparar
{
    CuentaBancaria a;
    FILE * buf = fopen(ArchivoDeCuentas,"rb");
    if (buf != NULL){
            while(fread(&a,sizeof(CuentaBancaria),1,buf)>0){
                if(a.saldo > dato){
                    apilar(pilaA, a.id_usuario);
                }
            }
        fclose(buf);
    } else {
        printf("\nNo se pudo abrir el archivo...");
    }
}
///matriz que mostrara los nombres de las ID's obtenidas en la pila
 void idNombreMatriz(char ArchivoDeUsuarios[], Pila* pilaA) {
    int dimF = 30, dimC = 50;
    char matrizNombreID[dimF][dimC];
    int i = 0;

    Usuario a;
    FILE* buf = fopen(ArchivoDeUsuarios, "rb");
    if (buf != NULL) {
        while (!pilavacia(pilaA)) {
            int idActual = tope(pilaA);
            rewind(buf);
            while (fread(&a, sizeof(Usuario), 1, buf) > 0) {
                if (a.id == idActual) {
                    strcpy(matrizNombreID[i], a.nombre);
                    i++;
                    desapilar(pilaA);
                }
            }
        }
        fclose(buf);
        mostrarMatrizNombres(dimC, matrizNombreID, i);
    } else {
        printf("\nNo se pudo abrir el archivo...");
    }
}
///MostarMatriz
 void mostrarMatrizNombres(int dimC, char matrizNombreID[][dimC], int validosF) {
    for (int f = 0; f < validosF; f++) {
        printf(" %s \n", matrizNombreID[f]);
    }
}

///FUNCION RECURSIVA:
int contarLineasRecursivamente(FILE *archivo) {
    char c;
    int conteo = 0;

    if ((c = getc(archivo)) != EOF) {   ///EOF = end of file
        if (c == '\n') {
            conteo = 1 + contarLineasRecursivamente(archivo);
        } else {
            conteo = contarLineasRecursivamente(archivo);
        }
    }

    return conteo;
}

int contarLineas(char nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");
    int totalLineas = 0;

    if (archivo != NULL) {
        totalLineas = contarLineasRecursivamente(archivo);
        fclose(archivo);
    } else {
        printf("No se pudo abrir el archivo.\n");
    }

    return totalLineas;
}

void tranferirMain(int idUsuario){
    int idUsuarioTransferir;
    int numeroDeCuentaTransferir;
    int numeroCuentaUsuario;
    double dinero;
    printf("\nIngrese el Id de la cuenta a la que quiere transferir: ");
    scanf("%d", &idUsuarioTransferir);

    consultaMostrarCuentasByIdUsuario(ArchivoDeCuentas, idUsuarioTransferir);

    printf("\nIngrese el numero de la cuenta que vas a transferir: ");
    scanf("%d", &numeroDeCuentaTransferir);

    consultaMostrarCuentasByIdUsuario(ArchivoDeCuentas, idUsuario);

    printf("\nIngrese el numero de la cuenta de la que quieres hacer la transferencia: ");
    scanf("%d", &numeroCuentaUsuario);

    printf("\nIngrese el saldo que quiere transferir: ");
    scanf("%lf", &dinero);  // Aquí debe ser %lf para double

    if (saldoSuficiente(numeroCuentaUsuario, dinero)) {
        restarSaldoACuentaUsuario(numeroCuentaUsuario, dinero);
        sumarSaldoACuentaUsuario(numeroDeCuentaTransferir, dinero);

        printf("\nTransferencia realizada con éxito.\n");

        consultaMostrarCuentasByIdUsuario(ArchivoDeCuentas, idUsuarioTransferir);
        consultaMostrarCuentasByIdUsuario(ArchivoDeCuentas, idUsuario);
    } else {
        printf("\nError: Saldo insuficiente para realizar la transferencia.\n");
    }
}

void sumarSaldoACuentaUsuario(int numeroDeCuentaTransferir, double saldo){
    FILE * buff = fopen(ArchivoDeCuentas, "r+b");
    CuentaBancaria aux;

    if (buff){
        while(fread(&aux, sizeof(CuentaBancaria), 1, buff) > 0){
            if (numeroDeCuentaTransferir == aux.numero_cuenta){
                aux.saldo += saldo;
                fseek(buff, -sizeof(CuentaBancaria), SEEK_CUR);
                fwrite(&aux, sizeof(CuentaBancaria), 1, buff);
                break;
            }
        }
        fclose(buff);
    }
}

int saldoSuficiente(int numeroDeCuentaUsuario, double saldo) {
    FILE *buff = fopen(ArchivoDeCuentas, "rb");
    CuentaBancaria aux;
    int suficiente = 0;

    if (buff) {
        while (fread(&aux, sizeof(CuentaBancaria), 1, buff) > 0) {
            if (numeroDeCuentaUsuario == aux.numero_cuenta) {
                if (aux.saldo >= saldo) {
                    suficiente = 1;
                }
                break;
            }
        }
        fclose(buff);
    }

    return suficiente;
}

void restarSaldoACuentaUsuario(int numeroDeCuentaUsuario, double saldo){
    FILE * buff = fopen(ArchivoDeCuentas, "r+b");
    CuentaBancaria aux;

    if (buff){
        while(fread(&aux, sizeof(CuentaBancaria), 1, buff) > 0){
            if (numeroDeCuentaUsuario == aux.numero_cuenta){
                aux.saldo -= saldo;
                fseek(buff, -sizeof(CuentaBancaria), SEEK_CUR); // Mover el puntero al inicio de la estructura leída
                fwrite(&aux, sizeof(CuentaBancaria), 1, buff); // Escribir la estructura actualizada
                break; // Salir del bucle una vez que se haya encontrado y actualizado la cuenta
            }
        }
        fclose(buff);
    }
}
