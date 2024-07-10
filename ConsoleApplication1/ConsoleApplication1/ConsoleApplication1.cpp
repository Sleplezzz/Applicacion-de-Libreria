#include "pch.h"
#include <iostream>
#include <stdlib.h>//toupper
#include <stdio.h>//new y delete
#include <cstdlib>
#include <algorithm>
#include <chrono>// Para la funcion tiempo
#include <ctime>//Para inicializar el random
#include <string>//Para usar string 
#include <conio.h> // Para Console::Clear() que sirve para limpiar la consola y getch()
#include <iomanip> // para setw, sirve para poder digitar cuanto espacio de separacion tendran los datos

using namespace System;
using namespace std;

struct VentaLibroTotal {
    int Annio;
    int CantidadLibrosTotal2022;
    int CantidadLibrosTotal2023;
    int CantidadLibrosTotal2024;
};

struct LibroCliente {
    char CategoriaLibro;
    char LocalLibro;
    int CantidadLibros;
    float IGV;
    float Subtotal;
    float PrecioTotal;
    string CodigoLibroElegido;
};

struct Dirección
{
    string Departamento;
    string Provincia;
    string Distrito;
    string Direcion;
};
struct Persona
{
    string DNI;
    string Nombres;
    string Apellido;
    char Sexo;
    string Correo;

};

struct PersonalEmpresa
{
    Persona DatosTrabajador;
    string Rol;
    string Contrasenia;

};
struct Registro {
    Persona DatosPersona;
    char Modalidad;
    int Anio;
    char MedioPago;
    char OpcionComprobante;
    LibroCliente DatosLibroCliente;
    Dirección DireccionCliente;
};

struct RegistroLibro {
    string codigo;
    string titulo;
    float precio;
    string local;
    string tipo;

};

void MenuRegistro(Registro* Clientes, int& CantidadClientes, VentaLibroTotal* DatosVentaTotal);
void RegistroCliente(Registro* Clientes, int& CantidadClientes, VentaLibroTotal* DatosVentaTotal);
void MostrarCuenta(Registro* Clientes, int& CantidadCliente, VentaLibroTotal* DatosVentaTotal);
void Menu(Registro* Clientes, int& CantidadClientes, VentaLibroTotal* DatosVentaTotal);
void ProcesoVenta(RegistroLibro* DatosLibro, Registro* Clientes, int& CantidadClientes, int& CantidadLibroFinal, VentaLibroTotal* DatosVentaTotal);
void ContinueFuction(Registro* Clientes, int& CantidadClientes, RegistroLibro* DatosLibro, VentaLibroTotal* DatosVentaTotal);
void ReporteClientesRegistrados(Registro* Clientes, int& CantidadCliente, VentaLibroTotal* DatosVentaTotal);
void ReporteGanancias(VentaLibroTotal* DatosVentaTotal);
void ReporteClientesSexo(int& CantidadClientes, Registro* Cliente);
void ReporteClientesModalidad(int& CantidadClientes, Registro* Clientes);
void ReporteClientesPorMedioPago(int& CantidadClientes, Registro* Clientes);
void ReporteComprobantes(int& CantidadClientes, Registro* Clientes);
void ReporteVentasAnio2024(int& CantidadClientes, Registro* Clientes);
void FuncionFecha();
void Menu2();
void ProcesoCompra(PersonalEmpresa* DatosTrabajador,PersonalEmpresa*DatosCajeros,PersonalEmpresa*DatosRepartidores, int& CantidadLibrosFinal, float& PrecioFinal, float& IGVFinal, float& SubtotalFinal);
void ContinueFunction2(PersonalEmpresa* DatosTrabajador,PersonalEmpresa*DatosCajeros,PersonalEmpresa*DatosRepartidores, int CantidadLibrosFinal, float PrecioFinal, float IGVFinal, float SubtotalFinal);



int main() {

    Registro* Clientes;
    Clientes = new Registro[100]; //100 SE REFIERE AL LIMITE MAXIMO DE CLIENTES (ES UNA CANTIDAD SUPUESTA YA QUE YO PODRIA PONER 100000000000000 E IGUAL FUNCIONARIA
    int cantidadClientes = 0;
    VentaLibroTotal* DatosVentaTotal;
    DatosVentaTotal = new VentaLibroTotal[3];

    for (int i = 0; i < 3; i++)
    {
        DatosVentaTotal[i].Annio = 0;
        DatosVentaTotal[i].CantidadLibrosTotal2022 = 0;
        DatosVentaTotal[i].CantidadLibrosTotal2023 = 0;
        DatosVentaTotal[i].CantidadLibrosTotal2024 = 0;
    }
    for (int i = 0; i < 3; i++)
    {
        DatosVentaTotal[i].Annio = 2022 + i;
    }
     cout << "\t======================================" << endl;
     cout << "\t\t\t Libreria " << endl;
     cout << "\t\t #####    ##      \n" ;
     cout << "\t\t ##   ##  ##       \n";
     cout << "\t\t ##    ## ##       \n";
     cout << "\t\t ##    ## ##       \n";
     cout << "\t\t ##    ## ##       \n";
     cout << "\t\t ##   ##  ##       \n";
     cout << "\t\t #####    ########\n" ;
     cout << "\t======================================" << endl;
     cout << "\tCreditos: Matheo Zavala" << endl;
     cout << "\t======================================" << endl;
    MenuRegistro(Clientes, cantidadClientes, DatosVentaTotal);
    Menu2();  //ESTE PROCESO ES RESTRINGIDO POR LO CUAL NO SE MUESTRA EN EL MENÚ VISIBLE AL PUBLICO SE ACTIVA DESPUES DE LOS REPORTES DE FORMA MANUAL PERO PARA LA PRESENTACION,
              // PARA UNA DEPURACION CONTINUA SE EJECUTARA AMBOS PROCESOS :)

    delete[]Clientes;
    delete[]DatosVentaTotal;
    return 0;
}

void MenuRegistro(Registro* Clientes, int& CantidadClientes, VentaLibroTotal* DatosVentaTotal) {
    char OpcionRegistro;
    cout << "\t ----------------------------------------------------" << endl;
    cout << "\t|www.DigitalLecture.com.pe                          |" << endl;
    cout << "\t ----------------------------------------------------" << endl;
    cout << "\t| Hola! Somos Digital Lecture, para poder acceder   |" << endl;
    cout << "\t| a nuestra plataforma debes registrarte primero.   |" << endl;
    cout << "\t| Opcion R: Registrarme                             |" << endl;
    cout << "\t| Opcion S: Salir                                   |" << endl;
    cout << "\t|                                                   |" << endl;
    cout << "\t ----------------------------------------------------" << endl;
    do {
        cout << "\t Digite la opcion que desees realizar -> "; cin >> OpcionRegistro;
        OpcionRegistro = toupper(OpcionRegistro);

        switch (OpcionRegistro) {
        case 'R': RegistroCliente(Clientes, CantidadClientes, DatosVentaTotal);

            break;
        case 'S': cout << "Apreciamos tu visita! " << endl;
            cout << "Presione cualquier tecla para continuar . . ." << endl;
            getch();
            system("cls");
            MenuRegistro(Clientes, CantidadClientes, DatosVentaTotal);

            break;
        default: cout << "\033[31mOpcion " << OpcionRegistro << " invalida\033[0m" << endl;
            break;
        }
    } while (!(OpcionRegistro == 'R' || OpcionRegistro == 'S') && OpcionRegistro != 'S');

}

void RegistroCliente(Registro* Clientes, int& CantidadClientes, VentaLibroTotal* DatosVentaTotal) {

    cout << "Ingrese su(s) nombre(s): ";
    cin.ignore();
    getline(cin, Clientes[CantidadClientes].DatosPersona.Nombres);

    cout << "Ingrese su(s) apellido(s): ";
    getline(cin, Clientes[CantidadClientes].DatosPersona.Apellido);

    do {
        cout << "Ingrese su DNI (8 digitos): ";
        cin >> Clientes[CantidadClientes].DatosPersona.DNI;
        if (Clientes[CantidadClientes].DatosPersona.DNI.size() > 8)
        {
            cout << "\033[31m El DNI solo debe contar con 8 digitos intentelo de nuevo \033[0m" << endl;
        }
    } while (Clientes[CantidadClientes].DatosPersona.DNI.size() > 8);

    do {
        cout << "Ingrese su sexo (M: Masculino , F: Femenino): ";
        cin >> Clientes[CantidadClientes].DatosPersona.Sexo;
        Clientes[CantidadClientes].DatosPersona.Sexo = toupper(Clientes[CantidadClientes].DatosPersona.Sexo);

    } while (Clientes[CantidadClientes].DatosPersona.Sexo != 'M' && Clientes[CantidadClientes].DatosPersona.Sexo != 'F');

    cout << "Ingrese su correo electronico: "; cin >> Clientes[CantidadClientes].DatosPersona.Correo;


    cout << endl;
    do
    {
        cout << "Elija el tipo de modalidad en el cual se efectuara la compra del libro: " << endl;
        cout << "Opcion A: Prescencial" << endl;
        cout << "Opcion B: Whatsapp" << endl;
        cout << "Opcion -> "; cin >> Clientes[CantidadClientes].Modalidad;
        Clientes[CantidadClientes].Modalidad = toupper(Clientes[CantidadClientes].Modalidad);
        switch (Clientes[CantidadClientes].Modalidad)
        {
        case 'A':
            break;
        case 'B':
            cout << "\n ================================================================================================" << endl;
            cout << "Nuestros servicios de entrega a domicilio solicitan su ubicacion para poder entregarle el pedido" << endl;
            cout << " ================================================================================================" << endl;
            cout << "Direccion -> ";
            cin.ignore();
            getline(cin, Clientes[CantidadClientes].DireccionCliente.Direcion);
            cout << "Departamento -> ";
            cin.ignore();
            getline(cin, Clientes[CantidadClientes].DireccionCliente.Departamento);
            cout << "Distrito -> ";
            cin.ignore();
            getline(cin, Clientes[CantidadClientes].DireccionCliente.Distrito);
            cout << "Provincia -> ";
            cin.ignore();
            getline(cin, Clientes[CantidadClientes].DireccionCliente.Provincia);
            break;

        default:
            cout << "\033[31mOpcion " << Clientes[CantidadClientes].Modalidad << " invalida\033[0m" << endl;
            break;
        }
    } while (!(Clientes[CantidadClientes].Modalidad == 'A' || Clientes[CantidadClientes].Modalidad == 'B'));

    cout << "\n\033[32mRegistro exitoso! Ahora puede acceder a nuestra plataforma :D \033[0m" << endl;
    cout << "\n ====================Cuenta=========================" << endl;
    MostrarCuenta(Clientes, CantidadClientes, DatosVentaTotal);

}
void MostrarCuenta(Registro* Clientes, int& CantidadCliente, VentaLibroTotal* DatosVentaTotal) {


    cout << "\tCliente " << CantidadCliente + 1 << ":\n";
    cout << "\tNombres: " << Clientes[CantidadCliente].DatosPersona.Nombres << endl;
    cout << "\tApellidos: " << Clientes[CantidadCliente].DatosPersona.Apellido << endl;
    cout << "\tDNI: " << Clientes[CantidadCliente].DatosPersona.DNI << endl;
    cout << "\tSexo: " << Clientes[CantidadCliente].DatosPersona.Sexo << endl;
    cout << "\tCorreo: " << Clientes[CantidadCliente].DatosPersona.Correo << endl;
    cout << "\n ===================================================" << endl;


    Menu(Clientes, CantidadCliente, DatosVentaTotal);
}



void Menu(Registro* Clientes, int& CantidadClientes, VentaLibroTotal* DatosVentaTotal) {


    int CantidadLibroFinal = 0;
    //Arreglo Estatico
    RegistroLibro DatosLibro[6] = {
        {"C1001", "Spider-Man", 24.8, "San Miguel", "Comic"},
        {"C1002", "Batman", 22.5, "Miraflores", "Comic"},
        {"C1003", "Hulk", 20.0, "San Miguel", "Comic"},
        {"M1001", "Bleach", 25.9, "San Miguel", "Manga"},
        {"M1002", "Naruto", 23.5, "Miraflores", "Manga"},
        {"M1003", "OnePiece", 20.8, "Miraflores", "Manga"}
    };

    cout << "\n\t\033[093m Bienvenido a 'Digital Lecture'" << endl;
    cout << "\n\t " << endl;
    cout << "\t  Tenemos diversidad de libros para ti!\n" << endl;
    cout << "\t |-------------------------------------|  " << endl;
    cout << "\t |             CATEGORIAS              |  " << endl;
    cout << "\t |-------------------------------------|  " << endl;
    cout << "\t |             Comics   (C)            |  " << endl;
    cout << "\t |             Manga    (M)            |  " << endl;
    cout << "\t |-------------------------------------|\n" << endl;

    ProcesoVenta(DatosLibro, Clientes, CantidadClientes, CantidadLibroFinal, DatosVentaTotal);
}

void ProcesoVenta(RegistroLibro* DatosLibro, Registro* Clientes, int& CantidadClientes, int& CantidadLibroFinal, VentaLibroTotal* DatosVentaTotal) {
    int Dia, Mes, Hora, Minuto, CostoDelivery;
    float ValorIGV = 0.18;
    float GananciaTotal2022 = 0;
    string NumeroTarjeta, CVV, RUC;
    int MesVencimiento, AnioVencimiento;
    float  MontoPago, Vuelto = 0;
    char OpcionEnvio;

    CostoDelivery = 5;
    PersonalEmpresa DatosCajeros[3] = {
        {"93476213","Alex Aaron","Hernandez Soliz",'M',"alexx_AA18@gmail.com"," Cajero "," DobleAAron18"},
        {"29870345","Ruth Samira","Torres Wong",'F',"RuthTW_306@gmail.com"," Cajera "," RuthConH&102"},
        {"09128709","Camilo Armando","Lopez Estrada",'M',"CamiloLoEs_24@gmail.com"," Cajero "," CALE_2202"},
    };
    PersonalEmpresa DatosRepartidores[3] = {
        {"98712891","Alondra Maddian","Arriaran Gomez",'F',"aloM_D20@gmail.com"," Repartidora "," Canelita!1416"},
        {"07389472","Paola Mariana","Sutta Pariona",'F',"PaxMar_PM@gmail.com"," Repartidora "," PMSP&AAAA"},
        {"64891263","Ramiro Ernesto","Lopez Estrada",'M',"Coppo14RAERN_@gmail.com"," Repartidor "," R123_E987"},
    };

    do {
        cout << "Elegir categoria: ";
        cin >> Clientes[CantidadClientes].DatosLibroCliente.CategoriaLibro;
        Clientes[CantidadClientes].DatosLibroCliente.CategoriaLibro = toupper(Clientes[CantidadClientes].DatosLibroCliente.CategoriaLibro);
        switch (Clientes[CantidadClientes].DatosLibroCliente.CategoriaLibro) {
        case 'C':
            cout << "\n\t -----------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t| Has elegido la categoria de comics, esperamos tener tu comic favorito!                                    |" << endl;
            cout << "\t.-----------------------------------------------------------------------------------------------------------." << endl;
            cout << "\t|        Elige el local de tu preferencia, de esta forma podemos mostrarte los comics disponibles:          |" << endl;
            cout << "\t|     Opcion S: San Miguel                                                                                  |" << endl;
            cout << "\t|     Opcion M: Miraflores                                                                                  |" << endl;
            cout << "\t -----------------------------------------------------------------------------------------------------------" << endl;
            do {
                cout << "\nEscriba aqui su opcion -> "; cin >> Clientes[CantidadClientes].DatosLibroCliente.LocalLibro;
                Clientes[CantidadClientes].DatosLibroCliente.LocalLibro = toupper(Clientes[CantidadClientes].DatosLibroCliente.LocalLibro);
            } while (Clientes[CantidadClientes].DatosLibroCliente.LocalLibro != 'S' && Clientes[CantidadClientes].DatosLibroCliente.LocalLibro != 'M');
            switch (Clientes[CantidadClientes].DatosLibroCliente.LocalLibro) {
            case 'S':
                cout << "\n\t -------------------------------------------------------------------------------" << endl;
                cout << "\t|Has elegido San Miguel, estos son los libros de la categoria comic disponibles  |" << endl;
                cout << "\t.--------------------------------------------------------------------------------." << endl;
                cout << " " << endl;

                for (int i = 0; i < 6; i++) {
                    if (DatosLibro[i].tipo == "Comic" && DatosLibro[i].local == "San Miguel") {

                        cout << setw(15) << DatosLibro[i].codigo
                            << setw(25) << DatosLibro[i].titulo
                            << setw(15) << DatosLibro[i].precio << " soles "
                            << setw(20) << DatosLibro[i].local << endl;

                    }

                }
                cout << "\t ------------------------------------------------------------------------------- " << endl;
                do
                {
                    cout << "\nEscriba el codigo del libro que quiera adquirir (La letra va en mayuscula) -> "; cin >> Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido;

                } while (!(Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido == "C1001" || Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido == "C1003"));


                for (int i = 0; i < 6; i++)
                {
                    if (DatosLibro[i].codigo == Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido && DatosLibro[i].local == "San Miguel" && Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido == "C1001") {
                        cout << "Usted eligio: " << DatosLibro[i].titulo << " , que buena eleccion :D" << endl;
                        do
                        {
                            cout << "\n\tIngrese la cantidad de libros de este codigo que desee adquirir -> "; cin >> Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros;
                        } while (Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros <= 0);
                        cout << "\n\t\t***********************************************" << endl;
                        cout << "\t\t* SISTEMA DE CALENDARIZACION DIGITAL LECTURE  *" << endl;
                        cout << "\t\t***********************************************" << endl;

                        do
                        {
                            cout << "\n\t Ingrese el mes en que se esta realizando la compra (Numero entero del 1->12): "; cin >> Mes;
                        } while (!(Mes <= 12 && Mes > 0));
                        do
                        {
                            do
                            {
                                cout << "\n\t Ingrese el dia en que se esta realizando la compra (Numero entero del 1->31 excepto en febrero): "; cin >> Dia;
                            } while (Dia > 31 || Dia <= 0);

                            if (Mes == 2 && Dia > 28)
                            {
                                cout << "\n\033[31m Febrero solo tiene 28 dias, intentelo de nuevo\033[0m" << endl;
                            }
                        } while (Mes == 2 && (Dia > 28 || Dia <= 0));
                        do
                        {

                            cout << "\n\t Ingrese el anio en que se esta realizando la compra (Numero entero del 2022->2024): "; cin >> Clientes[CantidadClientes].Anio;

                        } while (Clientes[CantidadClientes].Anio < 2022 || Clientes[CantidadClientes].Anio > 2024);
                        do
                        {
                            cout << "\n\t Ingrese la hora en la cual se esta realizando la compra: " << endl;
                            cout << "\n\tHora (1-24)-> "; cin >> Hora;

                        } while (!(Hora < 25 && Hora >= 1));
                        do
                        {
                            cout << "\n\tMinuto(s) (0-59) -> "; cin >> Minuto;
                        } while (!(Minuto < 60 && Minuto >= 0));
                        Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal = DatosLibro[i].precio * Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros;
                        Clientes[CantidadClientes].DatosLibroCliente.IGV = Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal * ValorIGV;
                        Clientes[CantidadClientes].DatosLibroCliente.Subtotal = Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal - Clientes[CantidadClientes].DatosLibroCliente.IGV;
                        if (Clientes[CantidadClientes].Modalidad == 'B')
                        {
                            do
                            {

                                cout << "\t |-------------------------------------|  " << endl;
                                cout << "\t |           MODO DE ENTREGA           |  " << endl;
                                cout << "\t |-------------------------------------|  " << endl;
                                cout << "\t |   Recojo en tienda   (R)            |  " << endl;
                                cout << "\t |   Delivery           (D)            |  " << endl;
                                cout << "\t |-------------------------------------|\n" << endl;
                                cout << "\tOpcion -> "; cin >> OpcionEnvio;
                                OpcionEnvio = toupper(OpcionEnvio);
                                if (OpcionEnvio == 'D')
                                {
                                    cout << "El costo adicional por delivery es : " << CostoDelivery << " soles" << endl;
                                }

                                if (OpcionEnvio != 'R' && OpcionEnvio != 'D')
                                {
                                    cout << "\n\033[31m Opcion Invalida \033[0m" << endl;
                                }
                            } while (OpcionEnvio != 'R' && OpcionEnvio != 'D');

                        }
                        cout << "\n\t\t***********************************************" << endl;
                        cout << "\t\t*                Sistema de Pagos             *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t* Opcion A: Credito                           *" << endl;
                        cout << "\t\t* Opcion B: Yape/Plin                         *" << endl;
                        cout << "\t\t* Opcion C: Al Contado                        *" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        do
                        {
                            cout << "\n\t\t Opcion -> ";
                            cin >> Clientes[CantidadClientes].MedioPago;
                            Clientes[CantidadClientes].MedioPago = toupper(Clientes[CantidadClientes].MedioPago);
                            switch (Clientes[CantidadClientes].MedioPago)
                            {
                            case 'A':
                                do
                                {
                                    do
                                    {
                                        cout << "\t Ingrese su numero de tarjeta (13 digitos) -> ";
                                        cin >> NumeroTarjeta;
                                        if (NumeroTarjeta.length() > 13)
                                        {
                                            cout << "\n\033[31m La tarjeta debe contar solo con 13 digitos, intentelo otra vez\033[0m" << endl;
                                        }
                                    } while (NumeroTarjeta.length() > 13);
                                    do
                                    {
                                        cout << "\t Ingrese su CVV (3 digitos) -> ";
                                        cin >> CVV;
                                        if (CVV.length() > 3)
                                        {
                                            cout << "\n\033[31m El CVV solo debe contar con 3 digitos, intentelo otra vez \033[0m" << endl;
                                        }
                                    } while (CVV.length() > 3);
                                    do
                                    {
                                        cout << "\t Ingrese el mes de vencimiento -> ";
                                        cin >> MesVencimiento;
                                    } while (MesVencimiento > 12 || MesVencimiento <= 0);
                                    do
                                    {
                                        cout << "\t Ingrese el anio de vencimiento -> ";
                                        cin >> AnioVencimiento;
                                    } while (AnioVencimiento <= 0);

                                    if (((MesVencimiento < Mes) && (Clientes[CantidadClientes].Anio < AnioVencimiento)) || ((MesVencimiento > Mes) && (Clientes[CantidadClientes].Anio > AnioVencimiento)))
                                    {
                                        cout << "\n\033[31m Esta tarjeta esta vencida, pruebe con otra tarjeta, por favor :c \033[0m" << endl;
                                    }

                                } while (((MesVencimiento < Mes) && (Clientes[CantidadClientes].Anio < AnioVencimiento)) || ((MesVencimiento < Mes) && (Clientes[CantidadClientes].Anio >= AnioVencimiento)));
                                cout << "\n Procesando . . ." << endl;

                                break;
                            case 'B':
                                cout << endl;
                                cout << "\t\t ...............       .....  .............    .....  ...   ..... ..........................    " << endl;
                                cout << "\t\t ..%%%%%%%%%%%%%%%=........*%=....%%%%%%%%%%*....*%%%+..%%:...=%*....%%%%%%+..%%%%%%%%%%%%%%%-.   " << endl;
                                cout << "\t\t ..%%-..........#%=...:%%..*%=....%#:...+%*....#%%%=.-%%..#%:.=%%%%%%%%-.=#+..%#:..........%%-..  " << endl;
                                cout << "\t\t ..%%-.=******..#%=.:**%%..*%=.-**%#**..=%#*+..%%%%#**%%**--+*=-::::::-+*=-:..%#:.+*****+..%%-..  " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%#==..-===*%%%%%%:.-====..%%%%*====%#:.====-..==..-===-..%#:.*%%%%%*..%%-..  " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%#::....+%%%%####-:...::..%%%%=::::%#:...=#*:-#*::::+%+..%#:.*%%%%%*..%%-..  " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%%%%....+%%%%....#%=.-%*..%%%%%%%%%%#:.....:%*..%%%%%%+..%#:.*%%%%%*..%%-..  " << endl;
                                cout << "\t\t  .%%-..........#%=.:%*..%%%%=.-%%......=%%%*..%%-.+%+..%%%%:.=%*.:#%%%-.=%+..%#:..........%%-..  " << endl;
                                cout << "\t\t  .%%%%%%%%%%%%%#%=.:%*..%%-.+%+..%#:.#%=.-%*..%%-.+%+..%%:.#%=.:%#..%#-.=%+..%%%%%%%%%%%%%%%-.   " << endl;
                                cout << "\t\t  ..................:%#%#.........%%%#%%%#*.:%#..+%=.-%%....#%=.:%*....+#=.....................   " << endl;
                                cout << "\t\t ..--:.:----------:.:+*%%....:-:..+*#%%%#++-=*+..=+-.:++----+*=-=%*..--+*-....-----------.....    " << endl;
                                cout << "\t\t ..%#-.+%%%%%%%%%%=...:%%....+#+....*%%#=.-%*...........%%#%:.=##%*..%#-......%%%%%%%%%%*......   " << endl;
                                cout << "\t\t   .........%%%%:.+#*.:%%......-%%..#%:..........*%=.-#%....#%%%*...............*%%%%%*.:#%##-.   " << endl;
                                cout << "\t\t ..%%#%=....%%%%%%=......#%-........#%%%%%%%*..%%-.+%+..%%%%:.=%*....%%-.=%%#%....*%:.=%*........   " << endl;
                                cout << "\t\t ..%%-.+%+............:%%%%-......%#:.......:#%..*%=.-#%....#%=......%%%%=.-%%....*%%%%%*..%%-.   " << endl;
                                cout << "\t\t  .::..::=**....****+.:%%%##*-.-*#::*********::#*###*+::****-:=***+..::::=*+::****#%%%%%#**::.    " << endl;
                                cout << "\t\t . .+++++*+--++..--*%*.:%%%%%%=.-%%+*#%%%+-=%#*%%%%%%%%#=----++#%#--..++:.:-=*+----#%%%#----...    " << endl;
                                cout << "\t\t  .###%%%+..%#:.::=#*:-##%%%#=:=%%###%%%=.:#%%#*+==+*#%%#:::*###*:..:%%-...-%%..::*###*:......    " << endl;
                                cout << "\t\t  ...*%%%+..%#:.##=.-%*..%%%%%%%%%..*%%%=.+%%#+==+====*%%#%%:...:%%#%#%-...-%%..*%:...:%*......   " << endl;
                                cout << "\t\t   ......-#%........-%%%%%%%%%%+..##:.#%=:%%#==***+=*+=#%%-.#%=........+%%%+..%#:.*%=......##-.   " << endl;
                                cout << "\t\t ..%%%%=....%%%%%%%%%%*..%%-........*%%%=:%%#==++*+*+==#%%%%:.=%*....%%-.=%%#%....*#%%#.:%%...    " << endl;
                                cout << "\t\t ..#%-......%#:.......:#%......-%%%#:.....+%%*+=+*++==*%%#....=%*....%%%%=.-%%##:.*%=......%%-.   " << endl;
                                cout << "\t\t ..++:.:-:..++=---:..-=*+--....-++%#=---:.:#%%+++==++#%%#%%%%=-++----#%*+=-+%%+*--+*=------**:.   " << endl;
                                cout << "\t\t   ....=*+....#%#*=.:**::#*-::::::*##%*#+-=%%%%%%%%%%%%%%###%%#.:******=:=**##::**-:+%#****::..   " << endl;
                                cout << "\t\t   ...........#%:.....:%#..+#%%%##..*#%%%%%###%**=+-...*+.=.#%#:.......+%=....%#:.*%##*....#%-.   " << endl;
                                cout << "\t\t   ....+%+..%%%%%%=......%%-.+%+..%#:-%#*:#*.+:-#.#:=%:=...+%%%%*.:%%%%-.=%+......*%=.:%##%...    " << endl;
                                cout << "\t\t  ...+%%%%##......+%%%%%%%%-........*#%#.=#::--%-:+.%+.-:%#-###.:%*........-%%..*%%%=...:#%...    " << endl;
                                cout << "\t\t  .###%%%%%###:.*#=:::-%%::+###+....#%%+.*-.=.:=....:.*#..:#%%##############%%..*%-:=###*::...    " << endl;
                                cout << "\t\t ..%%%%%%*-:::..::=*+..:-..*%+:=****+#%*.::.##+*#*.*##+-::*%%#=::::::::*%+::--**--+*=:::-****-.   " << endl;
                                cout << "\t\t ..%%%%%%+........=%*......*%=.-%%%#+##%%+.:::.....-+***##%%%%=........+%=....##:.*%=...:#%%%-..  " << endl;
                                cout << "\t\t   ..*#=.-%%%%%%%%=.-%*..%%%%%#+..:#%%#:..:+*#%%%#%%%%%%%%#+..=%%%*..%%-.=%%#%..*#%%=...:#%%%-..  " << endl;
                                cout << "\t\t  ...*%#%+..%#:...+#*......*%=.-##%%%-.*+.*%%##+*%%*:-%%%#:.#%%%*....%%-......##:.*%=......%%-.   " << endl;
                                cout << "\t\t  .%%#%=.-%%%#%%%%=.-%%%#%%%%=...=%%=:#=.*%##......+%+....*%:.=%%%%%%....=%+....*%:.=#%%*..%%-.   " << endl;
                                cout << "\t\t  .......-%%%#:.......-%%........-%%*..-#%%+-######=.-####:.*#=......####=.-####:.*#=...:##....   " << endl;
                                cout << "\t\t  .==:...-%%+=..======+%%......:==+%%%%%%#-==+++=#%*==++%#:.=+==-....=+++==+%%##+=#%=....=+...    " << endl;
                                cout << "\t\t  .%%-...-**-:..+*#%%%#**::....-%%---+**-.:%*..::*%%%+..%#:.:-+%#-:..:-..=%#****#%%%=....:-...    " << endl;
                                cout << "\t\t  .%%-......%#:...+%%%*..#%-...-%%%#:.....-%*..%%%%%%+..%#:.#%%%%%*..%%-.=%+....*%##=...:#%....   " << endl;
                                cout << "\t\t  .%%-...-%%....##=.-%%#%%%%%%%%%%%%%%:.....:%#.........%#:.#%%%%%%#%#%%%=.-#%..*%:.=##%*......   " << endl;
                                cout << "\t\t  .%%-.+%+..%#:.....-%*....+%=.-%%..#%#%=...:%%%%%%%%+..%#:.#%=........+%%%+..%%:.*#%%*....%%-.   " << endl;
                                cout << "\t\t ..%%-.+%+..%#:.#%%%%%%%%......-%%%#:.##%%%%%#%%%-.+%+........=%%%#......=%%%%##%%%%%%%%%%%....   " << endl;
                                cout << "\t\t  .:-..:-:..::..:---=%%%%******+--%#:.:-+%###--:-+*=-:........=%%%*..**-.=%*-----:#%+------....   " << endl;
                                cout << "\t\t   .................:%%%%####%%+..%#:...=#%#*....+#=..........=%%%*..#%-.=%+......*%=.........    " << endl;
                                cout << "\t\t ..#%%%%%%%%%%%%#%=...:%%....+%+..%#:...+%*.:%%%%%%=....%%%%:.=%%%%%%%%-.=%+..%%:.*%#%%%*.....    " << endl;
                                cout << "\t\t  .%%-..........#%=.:%#%%%%-.+%%%%%#:.#%%%%%*..#%%%%%+......#%=..........=%+......*%=......%%-.   " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:#*....*%=.-%%%%%%%%=........*%=....%%%%:.=%%%*..%%-.=%%%%%%%%%%#%*.:#%....   " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%###..*%##+::%#-:::=######..+%#####::::..=%#:...%%###%%%%::::*%+:...::...    " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%#==..*%%%+..%#++++*%#====++=======..=+..=%#++++#%+===+%%....*%*++++++...    " << endl;
                                cout << "\t\t  .%%-.-++++++..#%=.:*+..--*%*++--***++*+*=..--*+=--------+*--=+******+-...-%%..--++++++++*--.    " << endl;
                                cout << "\t\t  .%%-..........#%=......%#%%=.-%%..........:%#..*%%%%%%%#:.#%=............-%%..*%:........#%-.   " << endl;
                                cout << "\t\t  .#%%%%%%%%%%%%%%=.:%*..%%%%=.-%%..#%%%=......%%-........*%:.=%*.:%%%%-......%#:.*%=..........   " << endl;
                                cout << "\t\t                                ....    ...     ...         ...  ......         ......               " << endl;
                                cout << "\n\n\t Escanea el codigo QR para continuar : " << endl;
                                getch(); // Presionar cualquier tecla 
                                cout << "\n\t Procesando pago . . ." << endl;
                                getch(); // Presionar cualquier tecla
                                break;
                            case 'C':
                                do
                                {
                                    cout << "\t\t Ingrese el monto con el que pagara -> ";
                                    cin >> MontoPago;
                                    if (MontoPago < Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal && OpcionEnvio == 'D')
                                    {
                                        cout << "\n\033[31m El monto ingresado es insuficiente, el precio es: \033[0m" << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << "\033[31m ingrese otro monto, por favor \033[0m" << endl;
                                    }
                                    if (MontoPago < Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal && OpcionEnvio != 'D')
                                    {
                                        cout << "\n\033[31m El monto ingresado es insuficiente, el precio es: \033[0m" << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << "\033[31m ingrese otro monto, por favor \033[0m" << endl;
                                    }
                                } while (MontoPago < Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal);
                                if (OpcionEnvio != 'D')
                                {
                                    Vuelto = MontoPago - Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal;
                                }
                                else
                                {
                                    Vuelto = MontoPago - Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + 5;
                                }
                                cout << " Su vuelto sera de: " << Vuelto;
                                break;
                            default: cout << "\n\033[31m Ingrese una opcion valida\033[0m" << endl;
                                break;
                            }
                        } while (!(Clientes[CantidadClientes].MedioPago == 'A' || Clientes[CantidadClientes].MedioPago == 'B' || Clientes[CantidadClientes].MedioPago == 'C'));

                        cout << "\n\t\t***********************************************" << endl;
                        cout << "\t\t*                Opcion de Comprobantes        *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t* Opcion A: Boleta Electronica                *" << endl;
                        cout << "\t\t* Opcion B: Factura                           *" << endl;
                        cout << "\t\t* Opcion C: Nota de venta                     *" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        do
                        {
                            cout << "\n\t\t Opcion -> "; cin >> Clientes[CantidadClientes].OpcionComprobante;
                            Clientes[CantidadClientes].OpcionComprobante = toupper(Clientes[CantidadClientes].OpcionComprobante);
                            switch (Clientes[CantidadClientes].OpcionComprobante)
                            {
                            case 'A':
                                cout << "\n\t------------------------------" << endl;
                                cout << "\tBOLETA DE VENTA ELECTRONICA \n" << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Fecha                  : " << Dia << "/" << Mes << "/" << Clientes[CantidadClientes].Anio << endl;
                                cout << "\t Hora                   : " << " (";
                                if (Hora < 10)
                                {
                                    cout << "0";
                                }
                                cout << Hora << ":";
                                if (Minuto < 10) {
                                    cout << "0";
                                }
                               
                                cout << Minuto << ") " << endl;
                                //COMO LOS CAJEROS TIENEN HORARIOS ROTATIVOS SU TURNO ES DE 8 HORAS 
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 0 && Hora <= 8))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[0].DatosTrabajador.Nombres << " " << DatosCajeros[0].DatosTrabajador.Apellido<<endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                if (( OpcionEnvio == 'R'|| Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 8 && Hora <= 16))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[1].DatosTrabajador.Nombres << " " << DatosCajeros[1].DatosTrabajador.Apellido << endl;;
                                    cout << "\t------------------------------" << endl;
                                }
                                if (( OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 16 && Hora <= 24))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[2].DatosTrabajador.Nombres << " " << DatosCajeros[2].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\t DNI                    : " << Clientes[CantidadClientes].DatosPersona.DNI << endl;
                                cout << "\t Nombre                 : " << Clientes[CantidadClientes].DatosPersona.Nombres << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Codigo de libro        : " << DatosLibro[i].codigo << endl;
                                cout << "\t Titulo de libro        : " << DatosLibro[i].titulo << endl;
                                cout << "\t Tipo   de libro        : " << DatosLibro[i].tipo << endl;
                                cout << "\t Local                  : " << DatosLibro[i].local << endl;
                                cout << "\t Valor Unitario         : " << DatosLibro[i].precio << endl;
                                cout << "\t Cantidad de libros     : " << Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros << endl;
                                cout << "\t Valor IGV              : " << ValorIGV * 100 << "%" << endl;
                                cout << "\t IGV                    : " << Clientes[CantidadClientes].DatosLibroCliente.IGV << endl;
                                cout << "\t Base Imponible         : " << Clientes[CantidadClientes].DatosLibroCliente.Subtotal << endl;
                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Delivery               : " << CostoDelivery << endl;
                                }

                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << endl;
                                    if (Hora>0&&Hora<=8)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[0].DatosTrabajador.Nombres << " " << DatosRepartidores[0].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al"<<endl;
                                        cout<<  "\t  938712748" << endl; 
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 8 && Hora <= 16)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[1].DatosTrabajador.Nombres << " " << DatosRepartidores[1].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  902843093" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 16 && Hora <= 24)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[2].DatosTrabajador.Nombres << " " << DatosRepartidores[2].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  989371278" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                   
                                }
                                else
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << endl;
       
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\tBoleta de venta, valido para Sunat" << endl;
                                cout << "\tGracias por su preferencia..." << endl;
                                cout << "\t------------------------------" << endl;
                                break;
                            case 'B':
                                do
                                {
                                    cout << "\n\t Ingrese su numero de RUC (8 digitos sin digitar 10 al inicio y 4 al final) -> "; cin >> RUC;
                                    if (RUC.size() < 8 || RUC.size() > 8)
                                    {
                                        cout << "\n\033[31m Solo debe digitar 8 digitos sin contar 10 al inicio y 4 al final, intentelo de nuevo\033[0m" << endl;
                                    }
                                } while (RUC.size() < 8 || RUC.size() > 8);


                                cout << "\n\t------------------------------" << endl;
                                cout << "\tFACTURA DE VENTA ELECTRONICA \n" << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Fecha                  : " << Dia << "/" << Mes << "/" << Clientes[CantidadClientes].Anio << endl;
                                cout << "\t Hora                   : " << " (";
                                if (Hora < 10)
                                {
                                    cout << "0";
                                }
                                cout << Hora << ":";
                                if (Minuto < 10) {
                                    cout << "0";
                                }
                                cout << Minuto << ") " << endl;
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 0 && Hora <= 8))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[0].DatosTrabajador.Nombres << " " << DatosCajeros[0].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 8 && Hora <= 16))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[1].DatosTrabajador.Nombres << " " << DatosCajeros[1].DatosTrabajador.Apellido << endl;;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 16 && Hora <= 24))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[2].DatosTrabajador.Nombres << " " << DatosCajeros[2].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\t RUC                    : " << " 10" << RUC << "4 " << endl;
                                cout << "\t Razon Social           : " << " Libreria 'Digital Lecture' " << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Codigo de libro        : " << DatosLibro[i].codigo << endl;
                                cout << "\t Titulo de libro        : " << DatosLibro[i].titulo << endl;
                                cout << "\t Tipo   de libro        : " << DatosLibro[i].tipo << endl;
                                cout << "\t Local                  : " << DatosLibro[i].local << endl;
                                cout << "\t Valor Unitario         : " << DatosLibro[i].precio << endl;
                                cout << "\t Cantidad de libros     : " << Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros << endl;
                                cout << "\t Valor IGV              : " << ValorIGV * 100 << "%" << endl;
                                cout << "\t IGV                    : " << Clientes[CantidadClientes].DatosLibroCliente.IGV << endl;
                                cout << "\t Base Imponible         : " << Clientes[CantidadClientes].DatosLibroCliente.Subtotal << endl;
                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Delivery               : " << CostoDelivery << endl;
                                }

                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << endl;
                                    if (Hora > 0 && Hora <= 8)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[0].DatosTrabajador.Nombres << " " << DatosRepartidores[0].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  938712748" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 8 && Hora <= 16)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[1].DatosTrabajador.Nombres << " " << DatosRepartidores[1].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  902843093" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 16 && Hora <= 24)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[2].DatosTrabajador.Nombres << " " << DatosRepartidores[2].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  989371278" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                }
                                else
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << endl;
                                    
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\tFactura de venta, valido para Sunat" << endl;
                                cout << "\tGracias por su preferencia..." << endl;
                                cout << "\t------------------------------" << endl;
                                break;
                            case 'C':
                                cout << "\n\t------------------------------" << endl;
                                cout << "\tNOTA DE VENTA ELECTRONICA \n" << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Fecha                  : " << Dia << "/" << Mes << "/" << Clientes[CantidadClientes].Anio << endl;
                                cout << "\t Hora                   : " << " (";
                                if (Hora < 10)
                                {
                                    cout << "0";
                                }
                                cout << Hora << ":";
                                if (Minuto < 10) {
                                    cout << "0";
                                }
                                cout << Minuto << ") " << endl;
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 0 && Hora <= 8))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[0].DatosTrabajador.Nombres << " " << DatosCajeros[0].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 8 && Hora <= 16))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[1].DatosTrabajador.Nombres << " " << DatosCajeros[1].DatosTrabajador.Apellido << endl;;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 16 && Hora <= 24))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[2].DatosTrabajador.Nombres << " " << DatosCajeros[2].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\t Codigo de libro        : " << DatosLibro[i].codigo << endl;
                                cout << "\t Titulo de libro        : " << DatosLibro[i].titulo << endl;
                                cout << "\t Tipo   de libro        : " << DatosLibro[i].tipo << endl;
                                cout << "\t Local                  : " << DatosLibro[i].local << endl;
                                cout << "\t Valor Unitario         : " << DatosLibro[i].precio << endl;
                                cout << "\t Cantidad de libros     : " << Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros << endl;
                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Delivery               : " << CostoDelivery << endl;
                                }

                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << endl;
                                    if (Hora > 0 && Hora <= 8)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[0].DatosTrabajador.Nombres << " " << DatosRepartidores[0].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  938712748" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 8 && Hora <= 16)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[1].DatosTrabajador.Nombres << " " << DatosRepartidores[1].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  902843093" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 16 && Hora <= 24)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[2].DatosTrabajador.Nombres << " " << DatosRepartidores[2].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  989371278" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                }
                                else
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\tNota de venta, no valido para Sunat" << endl;
                                cout << "\tGracias por su preferencia..." << endl;
                                cout << "\t------------------------------" << endl;
                                break;
                            default:
                                cout << "\n\033[31m Ingrese una opcion valida\033[0m" << endl;
                                break;
                            }
                        } while (Clientes[CantidadClientes].OpcionComprobante != 'A' && Clientes[CantidadClientes].OpcionComprobante != 'B' && Clientes[CantidadClientes].OpcionComprobante != 'C');

                        if (Clientes[CantidadClientes].Modalidad == 'A')
                        {
                            cout << "\n\033[32mPago realizado, gracias por su compra! :D \033[0m" << endl;
                        }
                        if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                        {
                            cout << "\n\033[32mVenta Exitosa! :D \033[0m" << endl;
                            cout << "\n\t El envio sera enviado a la siguiente direccion: " << endl;
                            cout << "\t\t Direccion: " << Clientes[CantidadClientes].DireccionCliente.Direcion << endl;
                            cout << "\t\t Departamento: " << Clientes[CantidadClientes].DireccionCliente.Departamento << endl;
                            cout << "\t\t Distrito: " << Clientes[CantidadClientes].DireccionCliente.Distrito << endl;
                            cout << "\t\t Provincia: " << Clientes[CantidadClientes].DireccionCliente.Provincia << endl;
                        }
                        else if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'R')
                        {
                            cout << "\n\033[32mVenta Exitosa! :D \033[0m" << endl;
                        }



                    }
                    if (DatosLibro[i].codigo == Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido && DatosLibro[i].local == "San Miguel" && Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido == "C1003") {
                        cout << "Usted eligio: " << DatosLibro[i].titulo << " , que buena eleccion :D" << endl;
                        do
                        {
                            cout << "\n\tIngrese la cantidad de libros de este codigo que desee adquirir -> "; cin >> Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros;
                        } while (Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros <= 0);
                        cout << "\n\t\t***********************************************" << endl;
                        cout << "\t\t* SISTEMA DE CALENDARIZACION DIGITAL LECTURE  *" << endl;
                        cout << "\t\t***********************************************" << endl;

                        do
                        {
                            cout << "\n\t Ingrese el mes en que se esta realizando la compra (Numero entero del 1->12): "; cin >> Mes;
                        } while (!(Mes <= 12 && Mes > 0));
                        do
                        {
                            do
                            {
                                cout << "\n\t Ingrese el dia en que se esta realizando la compra (Numero entero del 1->31 excepto en febrero): "; cin >> Dia;
                            } while (Dia > 31 || Dia <= 0);

                            if (Mes == 2 && Dia > 28)
                            {
                                cout << "\n\033[31m Febrero solo tiene 28 dias, intentelo de nuevo\033[0m" << endl;
                            }
                        } while (Mes == 2 && (Dia > 28 || Dia <= 0));
                        do
                        {

                            cout << "\n\t Ingrese el anio en que se esta realizando la compra (Numero entero del 2022->2024): "; cin >> Clientes[CantidadClientes].Anio;

                        } while (Clientes[CantidadClientes].Anio < 2022 || Clientes[CantidadClientes].Anio > 2024);
                        do
                        {
                            cout << "\n\t Ingrese la hora en la cual se esta realizando la compra: " << endl;
                            cout << "\n\tHora (1-24)-> "; cin >> Hora;

                        } while (!(Hora < 25 && Hora >= 1));
                        do
                        {
                            cout << "\n\tMinuto(s) (0-59) -> "; cin >> Minuto;
                        } while (!(Minuto < 60 && Minuto >= 0));

                        Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal = DatosLibro[i].precio * Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros;
                        Clientes[CantidadClientes].DatosLibroCliente.IGV = Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal * ValorIGV;
                        Clientes[CantidadClientes].DatosLibroCliente.Subtotal = Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal - Clientes[CantidadClientes].DatosLibroCliente.IGV;
                        if (Clientes[CantidadClientes].Modalidad == 'B')
                        {
                            do
                            {

                                cout << "\t |-------------------------------------|  " << endl;
                                cout << "\t |           MODO DE ENTREGA           |  " << endl;
                                cout << "\t |-------------------------------------|  " << endl;
                                cout << "\t |   Recojo en tienda   (R)            |  " << endl;
                                cout << "\t |   Delivery           (D)            |  " << endl;
                                cout << "\t |-------------------------------------|\n" << endl;
                                cout << "\tOpcion -> "; cin >> OpcionEnvio;
                                OpcionEnvio = toupper(OpcionEnvio);
                                if (OpcionEnvio == 'D')
                                {
                                    cout << "El costo adicional por delivery es : " << CostoDelivery << " soles" << endl;
                                }

                                if (OpcionEnvio != 'R' && OpcionEnvio != 'D')
                                {
                                    cout << "\n\033[31m Opcion Invalida \033[0m" << endl;
                                }
                            } while (OpcionEnvio != 'R' && OpcionEnvio != 'D');

                        }

                        cout << "\n\t\t***********************************************" << endl;
                        cout << "\t\t*                Sistema de Pagos             *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t* Opcion A: Credito                           *" << endl;
                        cout << "\t\t* Opcion B: Yape/Plin                         *" << endl;
                        cout << "\t\t* Opcion C: Al Contado                        *" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        do
                        {
                            cout << "\n\t\t Opcion -> ";
                            cin >> Clientes[CantidadClientes].MedioPago;
                            Clientes[CantidadClientes].MedioPago = toupper(Clientes[CantidadClientes].MedioPago);
                            switch (Clientes[CantidadClientes].MedioPago)
                            {
                            case 'A':
                                do
                                {
                                    do
                                    {
                                        cout << "\t Ingrese su numero de tarjeta (13 digitos) -> ";
                                        cin >> NumeroTarjeta;
                                        if (NumeroTarjeta.length() > 13)
                                        {
                                            cout << "\n\033[31m La tarjeta debe contar solo con 13 digitos, intentelo otra vez\033[0m" << endl;
                                        }
                                    } while (NumeroTarjeta.length() > 13);
                                    do
                                    {
                                        cout << "\t Ingrese su CVV (3 digitos) -> ";
                                        cin >> CVV;
                                        if (CVV.length() > 3)
                                        {
                                            cout << "\n\033[31m El CVV solo debe contar con 3 digitos, intentelo otra vez \033[0m" << endl;
                                        }
                                    } while (CVV.length() > 3);

                                    do
                                    {
                                        cout << "\t Ingrese el mes de vencimiento -> ";
                                        cin >> MesVencimiento;
                                    } while (MesVencimiento > 12 || MesVencimiento <= 0);
                                    do
                                    {
                                        cout << "\t Ingrese el anio de vencimiento -> ";
                                        cin >> AnioVencimiento;
                                    } while (AnioVencimiento <= 0);

                                    if (((MesVencimiento < Mes) && (Clientes[CantidadClientes].Anio < AnioVencimiento)) || ((MesVencimiento > Mes) && (Clientes[CantidadClientes].Anio > AnioVencimiento)))
                                    {
                                        cout << "\n\033[31m Esta tarjeta esta vencida, pruebe con otra tarjeta, por favor :c \033[0m" << endl;
                                    }


                                } while (((MesVencimiento < Mes) && (Clientes[CantidadClientes].Anio < AnioVencimiento)) || ((MesVencimiento < Mes) && (Clientes[CantidadClientes].Anio >= AnioVencimiento)));
                                cout << "\n Procesando . . ." << endl;

                                break;
                            case 'B':
                                cout << endl;
                                cout << "\t\t ...............       .....  .............    .....  ...   ..... ..........................    " << endl;
                                cout << "\t\t ..%%%%%%%%%%%%%%%=........*%=....%%%%%%%%%%*....*%%%+..%%:...=%*....%%%%%%+..%%%%%%%%%%%%%%%-.   " << endl;
                                cout << "\t\t ..%%-..........#%=...:%%..*%=....%#:...+%*....#%%%=.-%%..#%:.=%%%%%%%%-.=#+..%#:..........%%-..  " << endl;
                                cout << "\t\t ..%%-.=******..#%=.:**%%..*%=.-**%#**..=%#*+..%%%%#**%%**--+*=-::::::-+*=-:..%#:.+*****+..%%-..  " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%#==..-===*%%%%%%:.-====..%%%%*====%#:.====-..==..-===-..%#:.*%%%%%*..%%-..  " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%#::....+%%%%####-:...::..%%%%=::::%#:...=#*:-#*::::+%+..%#:.*%%%%%*..%%-..  " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%%%%....+%%%%....#%=.-%*..%%%%%%%%%%#:.....:%*..%%%%%%+..%#:.*%%%%%*..%%-..  " << endl;
                                cout << "\t\t  .%%-..........#%=.:%*..%%%%=.-%%......=%%%*..%%-.+%+..%%%%:.=%*.:#%%%-.=%+..%#:..........%%-..  " << endl;
                                cout << "\t\t  .%%%%%%%%%%%%%#%=.:%*..%%-.+%+..%#:.#%=.-%*..%%-.+%+..%%:.#%=.:%#..%#-.=%+..%%%%%%%%%%%%%%%-.   " << endl;
                                cout << "\t\t  ..................:%#%#.........%%%#%%%#*.:%#..+%=.-%%....#%=.:%*....+#=.....................   " << endl;
                                cout << "\t\t ..--:.:----------:.:+*%%....:-:..+*#%%%#++-=*+..=+-.:++----+*=-=%*..--+*-....-----------.....    " << endl;
                                cout << "\t\t ..%#-.+%%%%%%%%%%=...:%%....+#+....*%%#=.-%*...........%%#%:.=##%*..%#-......%%%%%%%%%%*......   " << endl;
                                cout << "\t\t   .........%%%%:.+#*.:%%......-%%..#%:..........*%=.-#%....#%%%*...............*%%%%%*.:#%##-.   " << endl;
                                cout << "\t\t ..%%#%=....%%%%%%=......#%-........#%%%%%%%*..%%-.+%+..%%%%:.=%*....%%-.=%%#%....*%:.=%*........   " << endl;
                                cout << "\t\t ..%%-.+%+............:%%%%-......%#:.......:#%..*%=.-#%....#%=......%%%%=.-%%....*%%%%%*..%%-.   " << endl;
                                cout << "\t\t  .::..::=**....****+.:%%%##*-.-*#::*********::#*###*+::****-:=***+..::::=*+::****#%%%%%#**::.    " << endl;
                                cout << "\t\t . .+++++*+--++..--*%*.:%%%%%%=.-%%+*#%%%+-=%#*%%%%%%%%#=----++#%#--..++:.:-=*+----#%%%#----...    " << endl;
                                cout << "\t\t  .###%%%+..%#:.::=#*:-##%%%#=:=%%###%%%=.:#%%#*+==+*#%%#:::*###*:..:%%-...-%%..::*###*:......    " << endl;
                                cout << "\t\t  ...*%%%+..%#:.##=.-%*..%%%%%%%%%..*%%%=.+%%#+==+====*%%#%%:...:%%#%#%-...-%%..*%:...:%*......   " << endl;
                                cout << "\t\t   ......-#%........-%%%%%%%%%%+..##:.#%=:%%#==***+=*+=#%%-.#%=........+%%%+..%#:.*%=......##-.   " << endl;
                                cout << "\t\t ..%%%%=....%%%%%%%%%%*..%%-........*%%%=:%%#==++*+*+==#%%%%:.=%*....%%-.=%%#%....*#%%#.:%%...    " << endl;
                                cout << "\t\t ..#%-......%#:.......:#%......-%%%#:.....+%%*+=+*++==*%%#....=%*....%%%%=.-%%##:.*%=......%%-.   " << endl;
                                cout << "\t\t ..++:.:-:..++=---:..-=*+--....-++%#=---:.:#%%+++==++#%%#%%%%=-++----#%*+=-+%%+*--+*=------**:.   " << endl;
                                cout << "\t\t   ....=*+....#%#*=.:**::#*-::::::*##%*#+-=%%%%%%%%%%%%%%###%%#.:******=:=**##::**-:+%#****::..   " << endl;
                                cout << "\t\t   ...........#%:.....:%#..+#%%%##..*#%%%%%###%**=+-...*+.=.#%#:.......+%=....%#:.*%##*....#%-.   " << endl;
                                cout << "\t\t   ....+%+..%%%%%%=......%%-.+%+..%#:-%#*:#*.+:-#.#:=%:=...+%%%%*.:%%%%-.=%+......*%=.:%##%...    " << endl;
                                cout << "\t\t  ...+%%%%##......+%%%%%%%%-........*#%#.=#::--%-:+.%+.-:%#-###.:%*........-%%..*%%%=...:#%...    " << endl;
                                cout << "\t\t  .###%%%%%###:.*#=:::-%%::+###+....#%%+.*-.=.:=....:.*#..:#%%##############%%..*%-:=###*::...    " << endl;
                                cout << "\t\t ..%%%%%%*-:::..::=*+..:-..*%+:=****+#%*.::.##+*#*.*##+-::*%%#=::::::::*%+::--**--+*=:::-****-.   " << endl;
                                cout << "\t\t ..%%%%%%+........=%*......*%=.-%%%#+##%%+.:::.....-+***##%%%%=........+%=....##:.*%=...:#%%%-..  " << endl;
                                cout << "\t\t   ..*#=.-%%%%%%%%=.-%*..%%%%%#+..:#%%#:..:+*#%%%#%%%%%%%%#+..=%%%*..%%-.=%%#%..*#%%=...:#%%%-..  " << endl;
                                cout << "\t\t  ...*%#%+..%#:...+#*......*%=.-##%%%-.*+.*%%##+*%%*:-%%%#:.#%%%*....%%-......##:.*%=......%%-.   " << endl;
                                cout << "\t\t  .%%#%=.-%%%#%%%%=.-%%%#%%%%=...=%%=:#=.*%##......+%+....*%:.=%%%%%%....=%+....*%:.=#%%*..%%-.   " << endl;
                                cout << "\t\t  .......-%%%#:.......-%%........-%%*..-#%%+-######=.-####:.*#=......####=.-####:.*#=...:##....   " << endl;
                                cout << "\t\t  .==:...-%%+=..======+%%......:==+%%%%%%#-==+++=#%*==++%#:.=+==-....=+++==+%%##+=#%=....=+...    " << endl;
                                cout << "\t\t  .%%-...-**-:..+*#%%%#**::....-%%---+**-.:%*..::*%%%+..%#:.:-+%#-:..:-..=%#****#%%%=....:-...    " << endl;
                                cout << "\t\t  .%%-......%#:...+%%%*..#%-...-%%%#:.....-%*..%%%%%%+..%#:.#%%%%%*..%%-.=%+....*%##=...:#%....   " << endl;
                                cout << "\t\t  .%%-...-%%....##=.-%%#%%%%%%%%%%%%%%:.....:%#.........%#:.#%%%%%%#%#%%%=.-#%..*%:.=##%*......   " << endl;
                                cout << "\t\t  .%%-.+%+..%#:.....-%*....+%=.-%%..#%#%=...:%%%%%%%%+..%#:.#%=........+%%%+..%%:.*#%%*....%%-.   " << endl;
                                cout << "\t\t ..%%-.+%+..%#:.#%%%%%%%%......-%%%#:.##%%%%%#%%%-.+%+........=%%%#......=%%%%##%%%%%%%%%%%....   " << endl;
                                cout << "\t\t  .:-..:-:..::..:---=%%%%******+--%#:.:-+%###--:-+*=-:........=%%%*..**-.=%*-----:#%+------....   " << endl;
                                cout << "\t\t   .................:%%%%####%%+..%#:...=#%#*....+#=..........=%%%*..#%-.=%+......*%=.........    " << endl;
                                cout << "\t\t ..#%%%%%%%%%%%%#%=...:%%....+%+..%#:...+%*.:%%%%%%=....%%%%:.=%%%%%%%%-.=%+..%%:.*%#%%%*.....    " << endl;
                                cout << "\t\t  .%%-..........#%=.:%#%%%%-.+%%%%%#:.#%%%%%*..#%%%%%+......#%=..........=%+......*%=......%%-.   " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:#*....*%=.-%%%%%%%%=........*%=....%%%%:.=%%%*..%%-.=%%%%%%%%%%#%*.:#%....   " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%###..*%##+::%#-:::=######..+%#####::::..=%#:...%%###%%%%::::*%+:...::...    " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%#==..*%%%+..%#++++*%#====++=======..=+..=%#++++#%+===+%%....*%*++++++...    " << endl;
                                cout << "\t\t  .%%-.-++++++..#%=.:*+..--*%*++--***++*+*=..--*+=--------+*--=+******+-...-%%..--++++++++*--.    " << endl;
                                cout << "\t\t  .%%-..........#%=......%#%%=.-%%..........:%#..*%%%%%%%#:.#%=............-%%..*%:........#%-.   " << endl;
                                cout << "\t\t  .#%%%%%%%%%%%%%%=.:%*..%%%%=.-%%..#%%%=......%%-........*%:.=%*.:%%%%-......%#:.*%=..........   " << endl;
                                cout << "\t\t                                ....    ...     ...         ...  ......         ......               " << endl;
                                cout << "\n\n\t Escanea el codigo QR para continuar : " << endl;
                                getch(); // Presionar cualquier tecla 
                                cout << "\n\t Procesando pago . . ." << endl;
                                getch(); // Presionar cualquier tecla
                                break;
                            case 'C':
                                do
                                {
                                    cout << "\t\t Ingrese el monto con el que pagara -> ";
                                    cin >> MontoPago;
                                    if (MontoPago < Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal && OpcionEnvio == 'D')
                                    {
                                        cout << "\n\033[31m El monto ingresado es insuficiente, el precio es: \033[0m" << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << "\033[31m ingrese otro monto, por favor \033[0m" << endl;
                                    }
                                    if (MontoPago < Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal && OpcionEnvio != 'D')
                                    {
                                        cout << "\n\033[31m El monto ingresado es insuficiente, el precio es: \033[0m" << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << "\033[31m ingrese otro monto, por favor \033[0m" << endl;
                                    }
                                } while (MontoPago < Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal);
                                if (OpcionEnvio != 'D')
                                {
                                    Vuelto = MontoPago - Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal;
                                }
                                else
                                {
                                    Vuelto = MontoPago - Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + 5;
                                }
                                cout << " Su vuelto sera de: " << Vuelto;
                                break;
                            default: cout << "\n\033[31m Ingrese una opcion valida\033[0m" << endl;
                                break;
                            }
                        } while (!(Clientes[CantidadClientes].MedioPago == 'A' || Clientes[CantidadClientes].MedioPago == 'B' || Clientes[CantidadClientes].MedioPago == 'C'));

                        cout << "\n\t\t***********************************************" << endl;
                        cout << "\t\t*                Opcion de Comprobantes        *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t* Opcion A: Boleta Electronica                *" << endl;
                        cout << "\t\t* Opcion B: Factura                           *" << endl;
                        cout << "\t\t* Opcion C: Nota de venta                     *" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        do
                        {
                            cout << "\n\t\t Opcion -> "; cin >> Clientes[CantidadClientes].OpcionComprobante;
                            Clientes[CantidadClientes].OpcionComprobante = toupper(Clientes[CantidadClientes].OpcionComprobante);
                            switch (Clientes[CantidadClientes].OpcionComprobante)
                            {
                            case 'A':
                                cout << "\n\t------------------------------" << endl;
                                cout << "\tBOLETA DE VENTA ELECTRONICA \n" << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Fecha                  : " << Dia << "/" << Mes << "/" << Clientes[CantidadClientes].Anio << endl;
                                cout << "\t Hora                   : " << " (";
                                if (Hora < 10)
                                {
                                    cout << "0";
                                }
                                cout << Hora << ":";
                                if (Minuto < 10) {
                                    cout << "0";
                                }
                                cout << Minuto << ") " << endl;
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 0 && Hora <= 8))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[0].DatosTrabajador.Nombres << " " << DatosCajeros[0].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 8 && Hora <= 16))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[1].DatosTrabajador.Nombres << " " << DatosCajeros[1].DatosTrabajador.Apellido << endl;;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 16 && Hora <= 24))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[2].DatosTrabajador.Nombres << " " << DatosCajeros[2].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\t DNI                    : " << Clientes[CantidadClientes].DatosPersona.DNI << endl;
                                cout << "\t Nombre                 : " << Clientes[CantidadClientes].DatosPersona.Nombres << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Codigo de libro        : " << DatosLibro[i].codigo << endl;
                                cout << "\t Titulo de libro        : " << DatosLibro[i].titulo << endl;
                                cout << "\t Tipo   de libro        : " << DatosLibro[i].tipo << endl;
                                cout << "\t Local                  : " << DatosLibro[i].local << endl;
                                cout << "\t Valor Unitario         : " << DatosLibro[i].precio << endl;
                                cout << "\t Cantidad de libros     : " << Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros << endl;
                                cout << "\t Valor IGV              : " << ValorIGV * 100 << "%" << endl;
                                cout << "\t IGV                    : " << Clientes[CantidadClientes].DatosLibroCliente.IGV << endl;
                                cout << "\t Base Imponible         : " << Clientes[CantidadClientes].DatosLibroCliente.Subtotal << endl;
                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Delivery               : " << CostoDelivery << endl;
                                }

                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << endl;
                                }
                                else
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\tBoleta de venta, valido para Sunat" << endl;
                                cout << "\tGracias por su preferencia..." << endl;
                                cout << "\t------------------------------" << endl;
                                break;
                            case 'B':
                                do
                                {
                                    cout << "\n\t Ingrese su numero de RUC (8 digitos sin digitar 10 al inicio y 4 al final) -> "; cin >> RUC;
                                    if (RUC.size() < 8 || RUC.size() > 8)
                                    {
                                        cout << "\n\033[31m Solo debe digitar 8 digitos sin contar 10 al inicio y 4 al final, intentelo de nuevo\033[0m" << endl;
                                    }
                                } while (RUC.size() < 8 || RUC.size() > 8);


                                cout << "\n\t------------------------------" << endl;
                                cout << "\tFACTURA DE VENTA ELECTRONICA \n" << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Fecha                  : " << Dia << "/" << Mes << "/" << Clientes[CantidadClientes].Anio << endl;
                                cout << "\t Hora                   : " << " (";
                                if (Hora < 10)
                                {
                                    cout << "0";
                                }
                                cout << Hora << ":";
                                if (Minuto < 10) {
                                    cout << "0";
                                }
                                cout << Minuto << ") " << endl;
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 0 && Hora <= 8))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[0].DatosTrabajador.Nombres << " " << DatosCajeros[0].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 8 && Hora <= 16))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[1].DatosTrabajador.Nombres << " " << DatosCajeros[1].DatosTrabajador.Apellido << endl;;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 16 && Hora <= 24))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[2].DatosTrabajador.Nombres << " " << DatosCajeros[2].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\t RUC                    : " << " 10" << RUC << "4 " << endl;
                                cout << "\t Razon Social           : " << " Libreria 'Digital Lecture' " << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Codigo de libro        : " << DatosLibro[i].codigo << endl;
                                cout << "\t Titulo de libro        : " << DatosLibro[i].titulo << endl;
                                cout << "\t Tipo   de libro        : " << DatosLibro[i].tipo << endl;
                                cout << "\t Local                  : " << DatosLibro[i].local << endl;
                                cout << "\t Valor Unitario         : " << DatosLibro[i].precio << endl;
                                cout << "\t Cantidad de libros     : " << Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros << endl;
                                cout << "\t Valor IGV              : " << ValorIGV * 100 << "%" << endl;
                                cout << "\t IGV                    : " << Clientes[CantidadClientes].DatosLibroCliente.IGV << endl;
                                cout << "\t Base Imponible         : " << Clientes[CantidadClientes].DatosLibroCliente.Subtotal << endl;
                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Delivery               : " << CostoDelivery << endl;
                                }

                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << endl;
                                    if (Hora > 0 && Hora <= 8)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[0].DatosTrabajador.Nombres << " " << DatosRepartidores[0].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  938712748" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 8 && Hora <= 16)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[1].DatosTrabajador.Nombres << " " << DatosRepartidores[1].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  902843093" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 16 && Hora <= 24)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[2].DatosTrabajador.Nombres << " " << DatosRepartidores[2].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  989371278" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                }
                                else
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\tFactura de venta, valido para Sunat" << endl;
                                cout << "\tGracias por su preferencia..." << endl;
                                cout << "\t------------------------------" << endl;
                                break;
                            case 'C':
                                cout << "\n\t------------------------------" << endl;
                                cout << "\tNOTA DE VENTA ELECTRONICA \n" << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Fecha                  : " << Dia << "/" << Mes << "/" << Clientes[CantidadClientes].Anio << endl;
                                cout << "\t Hora                   : " << " (";
                                if (Hora < 10)
                                {
                                    cout << "0";
                                }
                                cout << Hora << ":";
                                if (Minuto < 10) {
                                    cout << "0";
                                }
                                cout << Minuto << ") " << endl;
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 0 && Hora <= 8))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[0].DatosTrabajador.Nombres << " " << DatosCajeros[0].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 8 && Hora <= 16))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[1].DatosTrabajador.Nombres << " " << DatosCajeros[1].DatosTrabajador.Apellido << endl;;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 16 && Hora <= 24))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[2].DatosTrabajador.Nombres << " " << DatosCajeros[2].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\t Codigo de libro        : " << DatosLibro[i].codigo << endl;
                                cout << "\t Titulo de libro        : " << DatosLibro[i].titulo << endl;
                                cout << "\t Tipo   de libro        : " << DatosLibro[i].tipo << endl;
                                cout << "\t Local                  : " << DatosLibro[i].local << endl;
                                cout << "\t Valor Unitario         : " << DatosLibro[i].precio << endl;
                                cout << "\t Cantidad de libros     : " << Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros << endl;
                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Delivery               : " << CostoDelivery << endl;
                                }

                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << endl;
                                    if (Hora > 0 && Hora <= 8)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[0].DatosTrabajador.Nombres << " " << DatosRepartidores[0].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  938712748" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 8 && Hora <= 16)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[1].DatosTrabajador.Nombres << " " << DatosRepartidores[1].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  902843093" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 16 && Hora <= 24)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[2].DatosTrabajador.Nombres << " " << DatosRepartidores[2].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  989371278" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                }
                                else
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\tNota de venta, no valido para Sunat" << endl;
                                cout << "\tGracias por su preferencia..." << endl;
                                cout << "\t------------------------------" << endl;
                                break;
                            default:
                                cout << "\n\033[31m Ingrese una opcion valida\033[0m" << endl;
                                break;
                            }
                        } while (Clientes[CantidadClientes].OpcionComprobante != 'A' && Clientes[CantidadClientes].OpcionComprobante != 'B' && Clientes[CantidadClientes].OpcionComprobante != 'C');


                        if (Clientes[CantidadClientes].Modalidad == 'A')
                        {
                            cout << "\n\033[32mPago realizado, gracias por su compra! :D \033[0m" << endl;
                        }
                        if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                        {
                            cout << "\n\033[32mVenta Exitosa! :D \033[0m" << endl;
                            cout << "\n\t El envio sera enviado a la siguiente direccion: " << endl;
                            cout << "\t\t Direccion: " << Clientes[CantidadClientes].DireccionCliente.Direcion << endl;
                            cout << "\t\t Departamento: " << Clientes[CantidadClientes].DireccionCliente.Departamento << endl;
                            cout << "\t\t Distrito: " << Clientes[CantidadClientes].DireccionCliente.Distrito << endl;
                            cout << "\t\t Provincia: " << Clientes[CantidadClientes].DireccionCliente.Provincia << endl;
                        }
                        else if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'R')
                        {
                            cout << "\n\033[32mVenta Exitosa! :D \033[0m" << endl;
                        }


                    }
                }

                break;
            case 'M':
                cout << "\n\t -------------------------------------------------------------------------------" << endl;
                cout << "\t| Has elegido Miraflores, estos son los libros de la categoria comic disponibles |" << endl;
                cout << "\t.--------------------------------------------------------------------------------." << endl;
                cout << " " << endl;

                for (int i = 0; i < 6; i++) {
                    if (DatosLibro[i].tipo == "Comic" && DatosLibro[i].local == "Miraflores") {

                        cout << setw(15) << DatosLibro[i].codigo
                            << setw(25) << DatosLibro[i].titulo
                            << setw(15) << DatosLibro[i].precio << " soles "
                            << setw(20) << DatosLibro[i].local << endl;

                    }

                }
                cout << "\t ------------------------------------------------------------------------------- " << endl;
                do
                {
                    cout << "\nEscriba el codigo del libro que quiera adquirir (La letra va en mayuscula) -> "; cin >> Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido;

                } while (!(Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido == "C1002"));

                for (int i = 0; i < 6; i++)
                {
                    if (DatosLibro[i].codigo == Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido && DatosLibro[i].local == "Miraflores" && Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido == "C1002") {
                        cout << "Usted eligio: " << DatosLibro[i].titulo << " , que buena eleccion :D" << endl;
                        do
                        {
                            cout << "\n\tIngrese la cantidad de libros de este codigo que desee adquirir -> "; cin >> Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros;
                        } while (Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros <= 0);
                        cout << "\n\t\t***********************************************" << endl;
                        cout << "\t\t* SISTEMA DE CALENDARIZACION DIGITAL LECTURE  *" << endl;
                        cout << "\t\t***********************************************" << endl;

                        do
                        {
                            cout << "\n\t Ingrese el mes en que se esta realizando la compra (Numero entero del 1->12): "; cin >> Mes;
                        } while (!(Mes <= 12 && Mes > 0));
                        do
                        {
                            do
                            {
                                cout << "\n\t Ingrese el dia en que se esta realizando la compra (Numero entero del 1->31 excepto en febrero): "; cin >> Dia;
                            } while (Dia > 31 || Dia <= 0);

                            if (Mes == 2 && Dia > 28)
                            {
                                cout << "\n\033[31m Febrero solo tiene 28 dias, intentelo de nuevo\033[0m" << endl;
                            }
                        } while (Mes == 2 && (Dia > 28 || Dia <= 0));
                        do
                        {

                            cout << "\n\t Ingrese el anio en que se esta realizando la compra (Numero entero del 2022->2024): "; cin >> Clientes[CantidadClientes].Anio;

                        } while (Clientes[CantidadClientes].Anio < 2022 || Clientes[CantidadClientes].Anio > 2024);
                        do
                        {
                            cout << "\n\t Ingrese la hora en la cual se esta realizando la compra: " << endl;
                            cout << "\n\tHora (1-24)-> "; cin >> Hora;

                        } while (!(Hora < 25 && Hora >= 1));
                        do
                        {
                            cout << "\n\tMinuto(s) (0-59) -> "; cin >> Minuto;
                        } while (!(Minuto < 60 && Minuto >= 0));

                        Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal = DatosLibro[i].precio * Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros;
                        Clientes[CantidadClientes].DatosLibroCliente.IGV = Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal * ValorIGV;
                        Clientes[CantidadClientes].DatosLibroCliente.Subtotal = Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal - Clientes[CantidadClientes].DatosLibroCliente.IGV;
                        if (Clientes[CantidadClientes].Modalidad == 'B')
                        {
                            do
                            {

                                cout << "\t |-------------------------------------|  " << endl;
                                cout << "\t |           MODO DE ENTREGA           |  " << endl;
                                cout << "\t |-------------------------------------|  " << endl;
                                cout << "\t |   Recojo en tienda   (R)            |  " << endl;
                                cout << "\t |   Delivery           (D)            |  " << endl;
                                cout << "\t |-------------------------------------|\n" << endl;
                                cout << "\tOpcion -> "; cin >> OpcionEnvio;
                                OpcionEnvio = toupper(OpcionEnvio);
                                if (OpcionEnvio == 'D')
                                {
                                    cout << "El costo adicional por delivery es : " << CostoDelivery << " soles" << endl;
                                }

                                if (OpcionEnvio != 'R' && OpcionEnvio != 'D')
                                {
                                    cout << "\n\033[31m Opcion Invalida \033[0m" << endl;
                                }
                            } while (OpcionEnvio != 'R' && OpcionEnvio != 'D');

                        }


                        cout << "\n\t\t***********************************************" << endl;
                        cout << "\t\t*                Sistema de Pagos             *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t* Opcion A: Credito                           *" << endl;
                        cout << "\t\t* Opcion B: Yape/Plin                         *" << endl;
                        cout << "\t\t* Opcion C: Al Contado                        *" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        do
                        {
                            cout << "\n\t\t Opcion -> ";
                            cin >> Clientes[CantidadClientes].MedioPago;
                            Clientes[CantidadClientes].MedioPago = toupper(Clientes[CantidadClientes].MedioPago);
                            switch (Clientes[CantidadClientes].MedioPago)
                            {
                            case 'A':
                                do
                                {
                                    do
                                    {
                                        cout << "\t Ingrese su numero de tarjeta (13 digitos) -> ";
                                        cin >> NumeroTarjeta;
                                        if (NumeroTarjeta.length() > 13)
                                        {
                                            cout << "\n\033[31m La tarjeta debe contar solo con 13 digitos, intentelo otra vez\033[0m" << endl;
                                        }
                                    } while (NumeroTarjeta.length() > 13);
                                    do
                                    {
                                        cout << "\t Ingrese su CVV (3 digitos) -> ";
                                        cin >> CVV;
                                        if (CVV.length() > 3)
                                        {
                                            cout << "\n\033[31m El CVV solo debe contar con 3 digitos, intentelo otra vez \033[0m" << endl;
                                        }
                                    } while (CVV.length() > 3);

                                    do
                                    {
                                        cout << "\t Ingrese el mes de vencimiento -> ";
                                        cin >> MesVencimiento;
                                    } while (MesVencimiento > 12 || MesVencimiento <= 0);
                                    do
                                    {
                                        cout << "\t Ingrese el anio de vencimiento -> ";
                                        cin >> AnioVencimiento;
                                    } while (AnioVencimiento <= 0);

                                    if (((MesVencimiento < Mes) && (Clientes[CantidadClientes].Anio < AnioVencimiento)) || ((MesVencimiento > Mes) && (Clientes[CantidadClientes].Anio > AnioVencimiento)))
                                    {
                                        cout << "\n\033[31m Esta tarjeta esta vencida, pruebe con otra tarjeta, por favor :c \033[0m" << endl;
                                    }


                                } while (((MesVencimiento < Mes) && (Clientes[CantidadClientes].Anio < AnioVencimiento)) || ((MesVencimiento < Mes) && (Clientes[CantidadClientes].Anio >= AnioVencimiento)));
                                cout << "\n Procesando . . ." << endl;

                                break;
                            case 'B':
                                cout << endl;
                                cout << "\t\t ...............       .....  .............    .....  ...   ..... ..........................    " << endl;
                                cout << "\t\t ..%%%%%%%%%%%%%%%=........*%=....%%%%%%%%%%*....*%%%+..%%:...=%*....%%%%%%+..%%%%%%%%%%%%%%%-.   " << endl;
                                cout << "\t\t ..%%-..........#%=...:%%..*%=....%#:...+%*....#%%%=.-%%..#%:.=%%%%%%%%-.=#+..%#:..........%%-..  " << endl;
                                cout << "\t\t ..%%-.=******..#%=.:**%%..*%=.-**%#**..=%#*+..%%%%#**%%**--+*=-::::::-+*=-:..%#:.+*****+..%%-..  " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%#==..-===*%%%%%%:.-====..%%%%*====%#:.====-..==..-===-..%#:.*%%%%%*..%%-..  " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%#::....+%%%%####-:...::..%%%%=::::%#:...=#*:-#*::::+%+..%#:.*%%%%%*..%%-..  " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%%%%....+%%%%....#%=.-%*..%%%%%%%%%%#:.....:%*..%%%%%%+..%#:.*%%%%%*..%%-..  " << endl;
                                cout << "\t\t  .%%-..........#%=.:%*..%%%%=.-%%......=%%%*..%%-.+%+..%%%%:.=%*.:#%%%-.=%+..%#:..........%%-..  " << endl;
                                cout << "\t\t  .%%%%%%%%%%%%%#%=.:%*..%%-.+%+..%#:.#%=.-%*..%%-.+%+..%%:.#%=.:%#..%#-.=%+..%%%%%%%%%%%%%%%-.   " << endl;
                                cout << "\t\t  ..................:%#%#.........%%%#%%%#*.:%#..+%=.-%%....#%=.:%*....+#=.....................   " << endl;
                                cout << "\t\t ..--:.:----------:.:+*%%....:-:..+*#%%%#++-=*+..=+-.:++----+*=-=%*..--+*-....-----------.....    " << endl;
                                cout << "\t\t ..%#-.+%%%%%%%%%%=...:%%....+#+....*%%#=.-%*...........%%#%:.=##%*..%#-......%%%%%%%%%%*......   " << endl;
                                cout << "\t\t   .........%%%%:.+#*.:%%......-%%..#%:..........*%=.-#%....#%%%*...............*%%%%%*.:#%##-.   " << endl;
                                cout << "\t\t ..%%#%=....%%%%%%=......#%-........#%%%%%%%*..%%-.+%+..%%%%:.=%*....%%-.=%%#%....*%:.=%*........   " << endl;
                                cout << "\t\t ..%%-.+%+............:%%%%-......%#:.......:#%..*%=.-#%....#%=......%%%%=.-%%....*%%%%%*..%%-.   " << endl;
                                cout << "\t\t  .::..::=**....****+.:%%%##*-.-*#::*********::#*###*+::****-:=***+..::::=*+::****#%%%%%#**::.    " << endl;
                                cout << "\t\t . .+++++*+--++..--*%*.:%%%%%%=.-%%+*#%%%+-=%#*%%%%%%%%#=----++#%#--..++:.:-=*+----#%%%#----...    " << endl;
                                cout << "\t\t  .###%%%+..%#:.::=#*:-##%%%#=:=%%###%%%=.:#%%#*+==+*#%%#:::*###*:..:%%-...-%%..::*###*:......    " << endl;
                                cout << "\t\t  ...*%%%+..%#:.##=.-%*..%%%%%%%%%..*%%%=.+%%#+==+====*%%#%%:...:%%#%#%-...-%%..*%:...:%*......   " << endl;
                                cout << "\t\t   ......-#%........-%%%%%%%%%%+..##:.#%=:%%#==***+=*+=#%%-.#%=........+%%%+..%#:.*%=......##-.   " << endl;
                                cout << "\t\t ..%%%%=....%%%%%%%%%%*..%%-........*%%%=:%%#==++*+*+==#%%%%:.=%*....%%-.=%%#%....*#%%#.:%%...    " << endl;
                                cout << "\t\t ..#%-......%#:.......:#%......-%%%#:.....+%%*+=+*++==*%%#....=%*....%%%%=.-%%##:.*%=......%%-.   " << endl;
                                cout << "\t\t ..++:.:-:..++=---:..-=*+--....-++%#=---:.:#%%+++==++#%%#%%%%=-++----#%*+=-+%%+*--+*=------**:.   " << endl;
                                cout << "\t\t   ....=*+....#%#*=.:**::#*-::::::*##%*#+-=%%%%%%%%%%%%%%###%%#.:******=:=**##::**-:+%#****::..   " << endl;
                                cout << "\t\t   ...........#%:.....:%#..+#%%%##..*#%%%%%###%**=+-...*+.=.#%#:.......+%=....%#:.*%##*....#%-.   " << endl;
                                cout << "\t\t   ....+%+..%%%%%%=......%%-.+%+..%#:-%#*:#*.+:-#.#:=%:=...+%%%%*.:%%%%-.=%+......*%=.:%##%...    " << endl;
                                cout << "\t\t  ...+%%%%##......+%%%%%%%%-........*#%#.=#::--%-:+.%+.-:%#-###.:%*........-%%..*%%%=...:#%...    " << endl;
                                cout << "\t\t  .###%%%%%###:.*#=:::-%%::+###+....#%%+.*-.=.:=....:.*#..:#%%##############%%..*%-:=###*::...    " << endl;
                                cout << "\t\t ..%%%%%%*-:::..::=*+..:-..*%+:=****+#%*.::.##+*#*.*##+-::*%%#=::::::::*%+::--**--+*=:::-****-.   " << endl;
                                cout << "\t\t ..%%%%%%+........=%*......*%=.-%%%#+##%%+.:::.....-+***##%%%%=........+%=....##:.*%=...:#%%%-..  " << endl;
                                cout << "\t\t   ..*#=.-%%%%%%%%=.-%*..%%%%%#+..:#%%#:..:+*#%%%#%%%%%%%%#+..=%%%*..%%-.=%%#%..*#%%=...:#%%%-..  " << endl;
                                cout << "\t\t  ...*%#%+..%#:...+#*......*%=.-##%%%-.*+.*%%##+*%%*:-%%%#:.#%%%*....%%-......##:.*%=......%%-.   " << endl;
                                cout << "\t\t  .%%#%=.-%%%#%%%%=.-%%%#%%%%=...=%%=:#=.*%##......+%+....*%:.=%%%%%%....=%+....*%:.=#%%*..%%-.   " << endl;
                                cout << "\t\t  .......-%%%#:.......-%%........-%%*..-#%%+-######=.-####:.*#=......####=.-####:.*#=...:##....   " << endl;
                                cout << "\t\t  .==:...-%%+=..======+%%......:==+%%%%%%#-==+++=#%*==++%#:.=+==-....=+++==+%%##+=#%=....=+...    " << endl;
                                cout << "\t\t  .%%-...-**-:..+*#%%%#**::....-%%---+**-.:%*..::*%%%+..%#:.:-+%#-:..:-..=%#****#%%%=....:-...    " << endl;
                                cout << "\t\t  .%%-......%#:...+%%%*..#%-...-%%%#:.....-%*..%%%%%%+..%#:.#%%%%%*..%%-.=%+....*%##=...:#%....   " << endl;
                                cout << "\t\t  .%%-...-%%....##=.-%%#%%%%%%%%%%%%%%:.....:%#.........%#:.#%%%%%%#%#%%%=.-#%..*%:.=##%*......   " << endl;
                                cout << "\t\t  .%%-.+%+..%#:.....-%*....+%=.-%%..#%#%=...:%%%%%%%%+..%#:.#%=........+%%%+..%%:.*#%%*....%%-.   " << endl;
                                cout << "\t\t ..%%-.+%+..%#:.#%%%%%%%%......-%%%#:.##%%%%%#%%%-.+%+........=%%%#......=%%%%##%%%%%%%%%%%....   " << endl;
                                cout << "\t\t  .:-..:-:..::..:---=%%%%******+--%#:.:-+%###--:-+*=-:........=%%%*..**-.=%*-----:#%+------....   " << endl;
                                cout << "\t\t   .................:%%%%####%%+..%#:...=#%#*....+#=..........=%%%*..#%-.=%+......*%=.........    " << endl;
                                cout << "\t\t ..#%%%%%%%%%%%%#%=...:%%....+%+..%#:...+%*.:%%%%%%=....%%%%:.=%%%%%%%%-.=%+..%%:.*%#%%%*.....    " << endl;
                                cout << "\t\t  .%%-..........#%=.:%#%%%%-.+%%%%%#:.#%%%%%*..#%%%%%+......#%=..........=%+......*%=......%%-.   " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:#*....*%=.-%%%%%%%%=........*%=....%%%%:.=%%%*..%%-.=%%%%%%%%%%#%*.:#%....   " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%###..*%##+::%#-:::=######..+%#####::::..=%#:...%%###%%%%::::*%+:...::...    " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%#==..*%%%+..%#++++*%#====++=======..=+..=%#++++#%+===+%%....*%*++++++...    " << endl;
                                cout << "\t\t  .%%-.-++++++..#%=.:*+..--*%*++--***++*+*=..--*+=--------+*--=+******+-...-%%..--++++++++*--.    " << endl;
                                cout << "\t\t  .%%-..........#%=......%#%%=.-%%..........:%#..*%%%%%%%#:.#%=............-%%..*%:........#%-.   " << endl;
                                cout << "\t\t  .#%%%%%%%%%%%%%%=.:%*..%%%%=.-%%..#%%%=......%%-........*%:.=%*.:%%%%-......%#:.*%=..........   " << endl;
                                cout << "\t\t                                ....    ...     ...         ...  ......         ......               " << endl;
                                cout << "\n\n\t Escanea el codigo QR para continuar : " << endl;
                                getch(); // Presionar cualquier tecla 
                                cout << "\n\t Procesando pago . . ." << endl;
                                getch(); // Presionar cualquier tecla
                                break;
                            case 'C':
                                do
                                {
                                    cout << "\t\t Ingrese el monto con el que pagara -> ";
                                    cin >> MontoPago;
                                    if (MontoPago < Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal && OpcionEnvio == 'D')
                                    {
                                        cout << "\n\033[31m El monto ingresado es insuficiente, el precio es: \033[0m" << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << "\033[31m ingrese otro monto, por favor \033[0m" << endl;
                                    }
                                    if (MontoPago < Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal && OpcionEnvio != 'D')
                                    {
                                        cout << "\n\033[31m El monto ingresado es insuficiente, el precio es: \033[0m" << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << "\033[31m ingrese otro monto, por favor \033[0m" << endl;
                                    }
                                } while (MontoPago < Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal);
                                if (OpcionEnvio != 'D')
                                {
                                    Vuelto = MontoPago - Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal;
                                }
                                else
                                {
                                    Vuelto = MontoPago - Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + 5;
                                }
                                cout << " Su vuelto sera de: " << Vuelto;
                                break;
                            default: cout << "\n\033[31m Ingrese una opcion valida\033[0m" << endl;
                                break;
                            }
                        } while (!(Clientes[CantidadClientes].MedioPago == 'A' || Clientes[CantidadClientes].MedioPago == 'B' || Clientes[CantidadClientes].MedioPago == 'C'));

                        cout << "\n\t\t***********************************************" << endl;
                        cout << "\t\t*                Opcion de Comprobantes        *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t* Opcion A: Boleta Electronica                *" << endl;
                        cout << "\t\t* Opcion B: Factura                           *" << endl;
                        cout << "\t\t* Opcion C: Nota de venta                     *" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        do
                        {
                            cout << "\n\t\t Opcion -> "; cin >> Clientes[CantidadClientes].OpcionComprobante;
                            Clientes[CantidadClientes].OpcionComprobante = toupper(Clientes[CantidadClientes].OpcionComprobante);
                            switch (Clientes[CantidadClientes].OpcionComprobante)
                            {
                            case 'A':
                                cout << "\n\t------------------------------" << endl;
                                cout << "\tBOLETA DE VENTA ELECTRONICA \n" << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Fecha                  : " << Dia << "/" << Mes << "/" << Clientes[CantidadClientes].Anio << endl;
                                cout << "\t Hora                   : " << " (";
                                if (Hora < 10)
                                {
                                    cout << "0";
                                }
                                cout << Hora << ":";
                                if (Minuto < 10) {
                                    cout << "0";
                                }
                                cout << Minuto << ") " << endl;
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 0 && Hora <= 8))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[0].DatosTrabajador.Nombres << " " << DatosCajeros[0].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 8 && Hora <= 16))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[1].DatosTrabajador.Nombres << " " << DatosCajeros[1].DatosTrabajador.Apellido << endl;;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 16 && Hora <= 24))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[2].DatosTrabajador.Nombres << " " << DatosCajeros[2].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\t DNI                    : " << Clientes[CantidadClientes].DatosPersona.DNI << endl;
                                cout << "\t Nombre                 : " << Clientes[CantidadClientes].DatosPersona.Nombres << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Codigo de libro        : " << DatosLibro[i].codigo << endl;
                                cout << "\t Titulo de libro        : " << DatosLibro[i].titulo << endl;
                                cout << "\t Tipo   de libro        : " << DatosLibro[i].tipo << endl;
                                cout << "\t Local                  : " << DatosLibro[i].local << endl;
                                cout << "\t Valor Unitario         : " << DatosLibro[i].precio << endl;
                                cout << "\t Cantidad de libros     : " << Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros << endl;
                                cout << "\t Valor IGV              : " << ValorIGV * 100 << "%" << endl;
                                cout << "\t IGV                    : " << Clientes[CantidadClientes].DatosLibroCliente.IGV << endl;
                                cout << "\t Base Imponible         : " << Clientes[CantidadClientes].DatosLibroCliente.Subtotal << endl;
                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Delivery               : " << CostoDelivery << endl;
                                }

                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << endl;
                                    if (Hora > 0 && Hora <= 8)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[0].DatosTrabajador.Nombres << " " << DatosRepartidores[0].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  938712748" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 8 && Hora <= 16)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[1].DatosTrabajador.Nombres << " " << DatosRepartidores[1].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  902843093" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 16 && Hora <= 24)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[2].DatosTrabajador.Nombres << " " << DatosRepartidores[2].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  989371278" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                }
                                else
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\tBoleta de venta, valido para Sunat" << endl;
                                cout << "\tGracias por su preferencia..." << endl;
                                cout << "\t------------------------------" << endl;
                                break;
                            case 'B':
                                do
                                {
                                    cout << "\n\t Ingrese su numero de RUC (8 digitos sin digitar 10 al inicio y 4 al final) -> "; cin >> RUC;
                                    if (RUC.size() < 8 || RUC.size() > 8)
                                    {
                                        cout << "\n\033[31m Solo debe digitar 8 digitos sin contar 10 al inicio y 4 al final, intentelo de nuevo\033[0m" << endl;
                                    }
                                } while (RUC.size() < 8 || RUC.size() > 8);


                                cout << "\n\t------------------------------" << endl;
                                cout << "\tFACTURA DE VENTA ELECTRONICA \n" << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Fecha                  : " << Dia << "/" << Mes << "/" << Clientes[CantidadClientes].Anio << endl;
                                cout << "\t Hora                   : " << " (";
                                if (Hora < 10)
                                {
                                    cout << "0";
                                }
                                cout << Hora << ":";
                                if (Minuto < 10) {
                                    cout << "0";
                                }
                                cout << Minuto << ") " << endl;
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 0 && Hora <= 8))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[0].DatosTrabajador.Nombres << " " << DatosCajeros[0].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 8 && Hora <= 16))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[1].DatosTrabajador.Nombres << " " << DatosCajeros[1].DatosTrabajador.Apellido << endl;;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 16 && Hora <= 24))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[2].DatosTrabajador.Nombres << " " << DatosCajeros[2].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\t RUC                    : " << " 10" << RUC << "4 " << endl;
                                cout << "\t Razon Social           : " << " Libreria 'Digital Lecture' " << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Codigo de libro        : " << DatosLibro[i].codigo << endl;
                                cout << "\t Titulo de libro        : " << DatosLibro[i].titulo << endl;
                                cout << "\t Tipo   de libro        : " << DatosLibro[i].tipo << endl;
                                cout << "\t Local                  : " << DatosLibro[i].local << endl;
                                cout << "\t Valor Unitario         : " << DatosLibro[i].precio << endl;
                                cout << "\t Cantidad de libros     : " << Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros << endl;
                                cout << "\t Valor IGV              : " << ValorIGV * 100 << "%" << endl;
                                cout << "\t IGV                    : " << Clientes[CantidadClientes].DatosLibroCliente.IGV << endl;
                                cout << "\t Base Imponible         : " << Clientes[CantidadClientes].DatosLibroCliente.Subtotal << endl;
                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Delivery               : " << CostoDelivery << endl;
                                }

                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << endl;
                                    if (Hora > 0 && Hora <= 8)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[0].DatosTrabajador.Nombres << " " << DatosRepartidores[0].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  938712748" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 8 && Hora <= 16)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[1].DatosTrabajador.Nombres << " " << DatosRepartidores[1].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  902843093" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 16 && Hora <= 24)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[2].DatosTrabajador.Nombres << " " << DatosRepartidores[2].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  989371278" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                }
                                else
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\tFactura de venta, valido para Sunat" << endl;
                                cout << "\tGracias por su preferencia..." << endl;
                                cout << "\t------------------------------" << endl;
                                break;
                            case 'C':
                                cout << "\n\t------------------------------" << endl;
                                cout << "\tNOTA DE VENTA ELECTRONICA \n" << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Fecha                  : " << Dia << "/" << Mes << "/" << Clientes[CantidadClientes].Anio << endl;
                                cout << "\t Hora                   : " << " (";
                                if (Hora < 10)
                                {
                                    cout << "0";
                                }
                                cout << Hora << ":";
                                if (Minuto < 10) {
                                    cout << "0";
                                }
                                cout << Minuto << ") " << endl;
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 0 && Hora <= 8))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[0].DatosTrabajador.Nombres << " " << DatosCajeros[0].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 8 && Hora <= 16))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[1].DatosTrabajador.Nombres << " " << DatosCajeros[1].DatosTrabajador.Apellido << endl;;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 16 && Hora <= 24))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[2].DatosTrabajador.Nombres << " " << DatosCajeros[2].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\t Codigo de libro        : " << DatosLibro[i].codigo << endl;
                                cout << "\t Titulo de libro        : " << DatosLibro[i].titulo << endl;
                                cout << "\t Tipo   de libro        : " << DatosLibro[i].tipo << endl;
                                cout << "\t Local                  : " << DatosLibro[i].local << endl;
                                cout << "\t Valor Unitario         : " << DatosLibro[i].precio << endl;
                                cout << "\t Cantidad de libros     : " << Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros << endl;
                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Delivery               : " << CostoDelivery << endl;
                                }

                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << endl;
                                    if (Hora > 0 && Hora <= 8)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[0].DatosTrabajador.Nombres << " " << DatosRepartidores[0].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  938712748" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 8 && Hora <= 16)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[1].DatosTrabajador.Nombres << " " << DatosRepartidores[1].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  902843093" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 16 && Hora <= 24)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[2].DatosTrabajador.Nombres << " " << DatosRepartidores[2].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  989371278" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                }
                                else
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\tNota de venta, no valido para Sunat" << endl;
                                cout << "\tGracias por su preferencia..." << endl;
                                cout << "\t------------------------------" << endl;
                                break;
                            default:
                                cout << "\n\033[31m Ingrese una opcion valida\033[0m" << endl;
                                break;
                            }
                        } while (Clientes[CantidadClientes].OpcionComprobante != 'A' && Clientes[CantidadClientes].OpcionComprobante != 'B' && Clientes[CantidadClientes].OpcionComprobante != 'C');

                        if (Clientes[CantidadClientes].Modalidad == 'A')
                        {
                            cout << "\n\033[32mPago realizado, gracias por su compra! :D \033[0m" << endl;
                        }
                        if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                        {
                            cout << "\n\033[32mVenta Exitosa! :D \033[0m" << endl;
                            cout << "\n\t El envio sera enviado a la siguiente direccion: " << endl;
                            cout << "\t\t Direccion: " << Clientes[CantidadClientes].DireccionCliente.Direcion << endl;
                            cout << "\t\t Departamento: " << Clientes[CantidadClientes].DireccionCliente.Departamento << endl;
                            cout << "\t\t Distrito: " << Clientes[CantidadClientes].DireccionCliente.Distrito << endl;
                            cout << "\t\t Provincia: " << Clientes[CantidadClientes].DireccionCliente.Provincia << endl;
                        }
                        else if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'R')
                        {
                            cout << "\n\033[32mVenta Exitosa! :D \033[0m" << endl;
                        }

                    }
                }
                break;

            default:
                cout << "Opcion " << Clientes[CantidadClientes].DatosLibroCliente.LocalLibro << " invalida" << endl;
                break;
            }


            break;
        case 'M':
            cout << "\t -----------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t| Has elegido la categoria de mangas, estos son los libros disponibles, esperamos tener tu comic favorito!  |" << endl;
            cout << "\t.-----------------------------------------------------------------------------------------------------------." << endl;
            cout << "\t|        Elige el local de tu preferencia, de esta forma podemos mostrarte los mangas disponibles:          |" << endl;
            cout << "\t|     Opcion S: San Miguel                                                                                  |" << endl;
            cout << "\t|     Opcion M: Miraflores                                                                                  |" << endl;
            cout << "\t -----------------------------------------------------------------------------------------------------------" << endl;
            do {
                cout << "\nEscriba aqui su opcion -> "; cin >> Clientes[CantidadClientes].DatosLibroCliente.LocalLibro;
                Clientes[CantidadClientes].DatosLibroCliente.LocalLibro = toupper(Clientes[CantidadClientes].DatosLibroCliente.LocalLibro);
            } while (Clientes[CantidadClientes].DatosLibroCliente.LocalLibro != 'S' && Clientes[CantidadClientes].DatosLibroCliente.LocalLibro != 'M');
            switch (Clientes[CantidadClientes].DatosLibroCliente.LocalLibro) {
            case 'S':
                cout << "\n\t -------------------------------------------------------------------------------" << endl;
                cout << "\t|Has elegido San Miguel, estos son los libros de la categoria manga  disponibles  |" << endl;
                cout << "\t.--------------------------------------------------------------------------------." << endl;
                cout << " " << endl;

                for (int i = 0; i < 6; i++) {
                    if (DatosLibro[i].tipo == "Manga" && DatosLibro[i].local == "San Miguel") {

                        cout << setw(15) << DatosLibro[i].codigo
                            << setw(25) << DatosLibro[i].titulo
                            << setw(15) << DatosLibro[i].precio << " soles "
                            << setw(20) << DatosLibro[i].local << endl;

                    }

                }
                cout << "\t ------------------------------------------------------------------------------- " << endl;
                do
                {
                    cout << "\nEscriba el codigo del libro que quiera adquirir (La letra va en mayuscula) -> "; cin >> Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido;

                } while (!(Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido == "M1001"));

                for (int i = 0; i < 6; i++)
                {
                    if (DatosLibro[i].codigo == Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido && DatosLibro[i].local == "San Miguel" && Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido == "M1001") {
                        cout << "Usted eligio: " << DatosLibro[i].titulo << " , que buena eleccion :D" << endl;

                        do
                        {
                            cout << "\n\tIngrese la cantidad de libros de este codigo que desee adquirir -> "; cin >> Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros;
                        } while (Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros <= 0);
                        cout << "\n\t\t***********************************************" << endl;
                        cout << "\t\t* SISTEMA DE CALENDARIZACION DIGITAL LECTURE  *" << endl;
                        cout << "\t\t***********************************************" << endl;

                        do
                        {
                            cout << "\n\t Ingrese el mes en que se esta realizando la compra (Numero entero del 1->12): "; cin >> Mes;
                        } while (!(Mes <= 12 && Mes > 0));
                        do
                        {
                            do
                            {
                                cout << "\n\t Ingrese el dia en que se esta realizando la compra (Numero entero del 1->31 excepto en febrero): "; cin >> Dia;
                            } while (Dia > 31 || Dia <= 0);

                            if (Mes == 2 && Dia > 28)
                            {
                                cout << "\n\033[31m Febrero solo tiene 28 dias, intentelo de nuevo\033[0m" << endl;
                            }
                        } while (Mes == 2 && (Dia > 28 || Dia <= 0));
                        do
                        {

                            cout << "\n\t Ingrese el anio en que se esta realizando la compra (Numero entero del 2022->2024): "; cin >> Clientes[CantidadClientes].Anio;

                        } while (Clientes[CantidadClientes].Anio < 2022 || Clientes[CantidadClientes].Anio > 2024);
                        do
                        {
                            cout << "\n\t Ingrese la hora en la cual se esta realizando la compra: " << endl;
                            cout << "\n\tHora (1-24)-> "; cin >> Hora;

                        } while (!(Hora < 25 && Hora >= 1));
                        do
                        {
                            cout << "\n\tMinuto(s) (0-59) -> "; cin >> Minuto;
                        } while (!(Minuto < 60 && Minuto >= 0));

                        Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal = DatosLibro[i].precio * Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros;
                        Clientes[CantidadClientes].DatosLibroCliente.IGV = Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal * ValorIGV;
                        Clientes[CantidadClientes].DatosLibroCliente.Subtotal = Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal - Clientes[CantidadClientes].DatosLibroCliente.IGV;
                        if (Clientes[CantidadClientes].Modalidad == 'B')
                        {
                            do
                            {

                                cout << "\t |-------------------------------------|  " << endl;
                                cout << "\t |           MODO DE ENTREGA           |  " << endl;
                                cout << "\t |-------------------------------------|  " << endl;
                                cout << "\t |   Recojo en tienda   (R)            |  " << endl;
                                cout << "\t |   Delivery           (D)            |  " << endl;
                                cout << "\t |-------------------------------------|\n" << endl;
                                cout << "\tOpcion -> "; cin >> OpcionEnvio;
                                OpcionEnvio = toupper(OpcionEnvio);
                                if (OpcionEnvio == 'D')
                                {
                                    cout << "El costo adicional por delivery es : " << CostoDelivery << " soles" << endl;
                                }

                                if (OpcionEnvio != 'R' && OpcionEnvio != 'D')
                                {
                                    cout << "\n\033[31m Opcion Invalida \033[0m" << endl;
                                }
                            } while (OpcionEnvio != 'R' && OpcionEnvio != 'D');

                        }


                        cout << "\n\t\t***********************************************" << endl;
                        cout << "\t\t*                Sistema de Pagos             *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t* Opcion A: Credito                           *" << endl;
                        cout << "\t\t* Opcion B: Yape/Plin                         *" << endl;
                        cout << "\t\t* Opcion C: Al Contado                        *" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        do
                        {
                            cout << "\n\t\t Opcion -> ";
                            cin >> Clientes[CantidadClientes].MedioPago;
                            Clientes[CantidadClientes].MedioPago = toupper(Clientes[CantidadClientes].MedioPago);
                            switch (Clientes[CantidadClientes].MedioPago)
                            {
                            case 'A':
                                do
                                {
                                    do
                                    {
                                        cout << "\t Ingrese su numero de tarjeta (13 digitos) -> ";
                                        cin >> NumeroTarjeta;
                                        if (NumeroTarjeta.length() > 13)
                                        {
                                            cout << "\n\033[31m La tarjeta debe contar solo con 13 digitos, intentelo otra vez\033[0m" << endl;
                                        }
                                    } while (NumeroTarjeta.length() > 13);
                                    do
                                    {
                                        cout << "\t Ingrese su CVV (3 digitos) -> ";
                                        cin >> CVV;
                                        if (CVV.length() > 3)
                                        {
                                            cout << "\n\033[31m El CVV solo debe contar con 3 digitos, intentelo otra vez \033[0m" << endl;
                                        }
                                    } while (CVV.length() > 3);

                                    do
                                    {
                                        cout << "\t Ingrese el mes de vencimiento -> ";
                                        cin >> MesVencimiento;
                                    } while (MesVencimiento > 12 || MesVencimiento <= 0);
                                    do
                                    {
                                        cout << "\t Ingrese el anio de vencimiento -> ";
                                        cin >> AnioVencimiento;
                                    } while (AnioVencimiento <= 0);

                                    if (((MesVencimiento < Mes) && (Clientes[CantidadClientes].Anio < AnioVencimiento)) || ((MesVencimiento > Mes) && (Clientes[CantidadClientes].Anio > AnioVencimiento)))
                                    {
                                        cout << "\n\033[31m Esta tarjeta esta vencida, pruebe con otra tarjeta, por favor :c \033[0m" << endl;
                                    }


                                } while (((MesVencimiento < Mes) && (Clientes[CantidadClientes].Anio < AnioVencimiento)) || ((MesVencimiento < Mes) && (Clientes[CantidadClientes].Anio >= AnioVencimiento)));
                                cout << "\n Procesando . . ." << endl;

                                break;
                            case 'B':
                                cout << endl;
                                cout << "\t\t ...............       .....  .............    .....  ...   ..... ..........................    " << endl;
                                cout << "\t\t ..%%%%%%%%%%%%%%%=........*%=....%%%%%%%%%%*....*%%%+..%%:...=%*....%%%%%%+..%%%%%%%%%%%%%%%-.   " << endl;
                                cout << "\t\t ..%%-..........#%=...:%%..*%=....%#:...+%*....#%%%=.-%%..#%:.=%%%%%%%%-.=#+..%#:..........%%-..  " << endl;
                                cout << "\t\t ..%%-.=******..#%=.:**%%..*%=.-**%#**..=%#*+..%%%%#**%%**--+*=-::::::-+*=-:..%#:.+*****+..%%-..  " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%#==..-===*%%%%%%:.-====..%%%%*====%#:.====-..==..-===-..%#:.*%%%%%*..%%-..  " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%#::....+%%%%####-:...::..%%%%=::::%#:...=#*:-#*::::+%+..%#:.*%%%%%*..%%-..  " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%%%%....+%%%%....#%=.-%*..%%%%%%%%%%#:.....:%*..%%%%%%+..%#:.*%%%%%*..%%-..  " << endl;
                                cout << "\t\t  .%%-..........#%=.:%*..%%%%=.-%%......=%%%*..%%-.+%+..%%%%:.=%*.:#%%%-.=%+..%#:..........%%-..  " << endl;
                                cout << "\t\t  .%%%%%%%%%%%%%#%=.:%*..%%-.+%+..%#:.#%=.-%*..%%-.+%+..%%:.#%=.:%#..%#-.=%+..%%%%%%%%%%%%%%%-.   " << endl;
                                cout << "\t\t  ..................:%#%#.........%%%#%%%#*.:%#..+%=.-%%....#%=.:%*....+#=.....................   " << endl;
                                cout << "\t\t ..--:.:----------:.:+*%%....:-:..+*#%%%#++-=*+..=+-.:++----+*=-=%*..--+*-....-----------.....    " << endl;
                                cout << "\t\t ..%#-.+%%%%%%%%%%=...:%%....+#+....*%%#=.-%*...........%%#%:.=##%*..%#-......%%%%%%%%%%*......   " << endl;
                                cout << "\t\t   .........%%%%:.+#*.:%%......-%%..#%:..........*%=.-#%....#%%%*...............*%%%%%*.:#%##-.   " << endl;
                                cout << "\t\t ..%%#%=....%%%%%%=......#%-........#%%%%%%%*..%%-.+%+..%%%%:.=%*....%%-.=%%#%....*%:.=%*........   " << endl;
                                cout << "\t\t ..%%-.+%+............:%%%%-......%#:.......:#%..*%=.-#%....#%=......%%%%=.-%%....*%%%%%*..%%-.   " << endl;
                                cout << "\t\t  .::..::=**....****+.:%%%##*-.-*#::*********::#*###*+::****-:=***+..::::=*+::****#%%%%%#**::.    " << endl;
                                cout << "\t\t . .+++++*+--++..--*%*.:%%%%%%=.-%%+*#%%%+-=%#*%%%%%%%%#=----++#%#--..++:.:-=*+----#%%%#----...    " << endl;
                                cout << "\t\t  .###%%%+..%#:.::=#*:-##%%%#=:=%%###%%%=.:#%%#*+==+*#%%#:::*###*:..:%%-...-%%..::*###*:......    " << endl;
                                cout << "\t\t  ...*%%%+..%#:.##=.-%*..%%%%%%%%%..*%%%=.+%%#+==+====*%%#%%:...:%%#%#%-...-%%..*%:...:%*......   " << endl;
                                cout << "\t\t   ......-#%........-%%%%%%%%%%+..##:.#%=:%%#==***+=*+=#%%-.#%=........+%%%+..%#:.*%=......##-.   " << endl;
                                cout << "\t\t ..%%%%=....%%%%%%%%%%*..%%-........*%%%=:%%#==++*+*+==#%%%%:.=%*....%%-.=%%#%....*#%%#.:%%...    " << endl;
                                cout << "\t\t ..#%-......%#:.......:#%......-%%%#:.....+%%*+=+*++==*%%#....=%*....%%%%=.-%%##:.*%=......%%-.   " << endl;
                                cout << "\t\t ..++:.:-:..++=---:..-=*+--....-++%#=---:.:#%%+++==++#%%#%%%%=-++----#%*+=-+%%+*--+*=------**:.   " << endl;
                                cout << "\t\t   ....=*+....#%#*=.:**::#*-::::::*##%*#+-=%%%%%%%%%%%%%%###%%#.:******=:=**##::**-:+%#****::..   " << endl;
                                cout << "\t\t   ...........#%:.....:%#..+#%%%##..*#%%%%%###%**=+-...*+.=.#%#:.......+%=....%#:.*%##*....#%-.   " << endl;
                                cout << "\t\t   ....+%+..%%%%%%=......%%-.+%+..%#:-%#*:#*.+:-#.#:=%:=...+%%%%*.:%%%%-.=%+......*%=.:%##%...    " << endl;
                                cout << "\t\t  ...+%%%%##......+%%%%%%%%-........*#%#.=#::--%-:+.%+.-:%#-###.:%*........-%%..*%%%=...:#%...    " << endl;
                                cout << "\t\t  .###%%%%%###:.*#=:::-%%::+###+....#%%+.*-.=.:=....:.*#..:#%%##############%%..*%-:=###*::...    " << endl;
                                cout << "\t\t ..%%%%%%*-:::..::=*+..:-..*%+:=****+#%*.::.##+*#*.*##+-::*%%#=::::::::*%+::--**--+*=:::-****-.   " << endl;
                                cout << "\t\t ..%%%%%%+........=%*......*%=.-%%%#+##%%+.:::.....-+***##%%%%=........+%=....##:.*%=...:#%%%-..  " << endl;
                                cout << "\t\t   ..*#=.-%%%%%%%%=.-%*..%%%%%#+..:#%%#:..:+*#%%%#%%%%%%%%#+..=%%%*..%%-.=%%#%..*#%%=...:#%%%-..  " << endl;
                                cout << "\t\t  ...*%#%+..%#:...+#*......*%=.-##%%%-.*+.*%%##+*%%*:-%%%#:.#%%%*....%%-......##:.*%=......%%-.   " << endl;
                                cout << "\t\t  .%%#%=.-%%%#%%%%=.-%%%#%%%%=...=%%=:#=.*%##......+%+....*%:.=%%%%%%....=%+....*%:.=#%%*..%%-.   " << endl;
                                cout << "\t\t  .......-%%%#:.......-%%........-%%*..-#%%+-######=.-####:.*#=......####=.-####:.*#=...:##....   " << endl;
                                cout << "\t\t  .==:...-%%+=..======+%%......:==+%%%%%%#-==+++=#%*==++%#:.=+==-....=+++==+%%##+=#%=....=+...    " << endl;
                                cout << "\t\t  .%%-...-**-:..+*#%%%#**::....-%%---+**-.:%*..::*%%%+..%#:.:-+%#-:..:-..=%#****#%%%=....:-...    " << endl;
                                cout << "\t\t  .%%-......%#:...+%%%*..#%-...-%%%#:.....-%*..%%%%%%+..%#:.#%%%%%*..%%-.=%+....*%##=...:#%....   " << endl;
                                cout << "\t\t  .%%-...-%%....##=.-%%#%%%%%%%%%%%%%%:.....:%#.........%#:.#%%%%%%#%#%%%=.-#%..*%:.=##%*......   " << endl;
                                cout << "\t\t  .%%-.+%+..%#:.....-%*....+%=.-%%..#%#%=...:%%%%%%%%+..%#:.#%=........+%%%+..%%:.*#%%*....%%-.   " << endl;
                                cout << "\t\t ..%%-.+%+..%#:.#%%%%%%%%......-%%%#:.##%%%%%#%%%-.+%+........=%%%#......=%%%%##%%%%%%%%%%%....   " << endl;
                                cout << "\t\t  .:-..:-:..::..:---=%%%%******+--%#:.:-+%###--:-+*=-:........=%%%*..**-.=%*-----:#%+------....   " << endl;
                                cout << "\t\t   .................:%%%%####%%+..%#:...=#%#*....+#=..........=%%%*..#%-.=%+......*%=.........    " << endl;
                                cout << "\t\t ..#%%%%%%%%%%%%#%=...:%%....+%+..%#:...+%*.:%%%%%%=....%%%%:.=%%%%%%%%-.=%+..%%:.*%#%%%*.....    " << endl;
                                cout << "\t\t  .%%-..........#%=.:%#%%%%-.+%%%%%#:.#%%%%%*..#%%%%%+......#%=..........=%+......*%=......%%-.   " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:#*....*%=.-%%%%%%%%=........*%=....%%%%:.=%%%*..%%-.=%%%%%%%%%%#%*.:#%....   " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%###..*%##+::%#-:::=######..+%#####::::..=%#:...%%###%%%%::::*%+:...::...    " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%#==..*%%%+..%#++++*%#====++=======..=+..=%#++++#%+===+%%....*%*++++++...    " << endl;
                                cout << "\t\t  .%%-.-++++++..#%=.:*+..--*%*++--***++*+*=..--*+=--------+*--=+******+-...-%%..--++++++++*--.    " << endl;
                                cout << "\t\t  .%%-..........#%=......%#%%=.-%%..........:%#..*%%%%%%%#:.#%=............-%%..*%:........#%-.   " << endl;
                                cout << "\t\t  .#%%%%%%%%%%%%%%=.:%*..%%%%=.-%%..#%%%=......%%-........*%:.=%*.:%%%%-......%#:.*%=..........   " << endl;
                                cout << "\t\t                                ....    ...     ...         ...  ......         ......               " << endl;
                                cout << "\n\n\t Escanea el codigo QR para continuar : " << endl;
                                getch(); // Presionar cualquier tecla 
                                cout << "\n\t Procesando pago . . ." << endl;
                                getch(); // Presionar cualquier tecla
                                break;
                            case 'C':
                                do
                                {
                                    cout << "\t\t Ingrese el monto con el que pagara -> ";
                                    cin >> MontoPago;
                                    if (MontoPago < Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal && OpcionEnvio == 'D')
                                    {
                                        cout << "\n\033[31m El monto ingresado es insuficiente, el precio es: \033[0m" << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << "\033[31m ingrese otro monto, por favor \033[0m" << endl;
                                    }
                                    if (MontoPago < Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal && OpcionEnvio != 'D')
                                    {
                                        cout << "\n\033[31m El monto ingresado es insuficiente, el precio es: \033[0m" << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << "\033[31m ingrese otro monto, por favor \033[0m" << endl;
                                    }
                                } while (MontoPago < Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal);
                                if (OpcionEnvio != 'D')
                                {
                                    Vuelto = MontoPago - Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal;
                                }
                                else
                                {
                                    Vuelto = MontoPago - Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + 5;
                                }
                                cout << " Su vuelto sera de: " << Vuelto;
                                break;
                            default: cout << "\n\033[31m Ingrese una opcion valida\033[0m" << endl;
                                break;
                            }
                        } while (!(Clientes[CantidadClientes].MedioPago == 'A' || Clientes[CantidadClientes].MedioPago == 'B' || Clientes[CantidadClientes].MedioPago == 'C'));
                        cout << "\n\t\t***********************************************" << endl;
                        cout << "\t\t*                Opcion de Comprobantes        *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t* Opcion A: Boleta Electronica                *" << endl;
                        cout << "\t\t* Opcion B: Factura                           *" << endl;
                        cout << "\t\t* Opcion C: Nota de venta                     *" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        do
                        {
                            cout << "\n\t\t Opcion -> "; cin >> Clientes[CantidadClientes].OpcionComprobante;
                            Clientes[CantidadClientes].OpcionComprobante = toupper(Clientes[CantidadClientes].OpcionComprobante);
                            switch (Clientes[CantidadClientes].OpcionComprobante)
                            {
                            case 'A':
                                cout << "\n\t------------------------------" << endl;
                                cout << "\tBOLETA DE VENTA ELECTRONICA \n" << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Fecha                  : " << Dia << "/" << Mes << "/" << Clientes[CantidadClientes].Anio << endl;
                                cout << "\t Hora                   : " << " (";
                                if (Hora < 10)
                                {
                                    cout << "0";
                                }
                                cout << Hora << ":";
                                if (Minuto < 10) {
                                    cout << "0";
                                }
                                cout << Minuto << ") " << endl;
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 0 && Hora <= 8))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[0].DatosTrabajador.Nombres << " " << DatosCajeros[0].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 8 && Hora <= 16))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[1].DatosTrabajador.Nombres << " " << DatosCajeros[1].DatosTrabajador.Apellido << endl;;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 16 && Hora <= 24))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[2].DatosTrabajador.Nombres << " " << DatosCajeros[2].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\t DNI                    : " << Clientes[CantidadClientes].DatosPersona.DNI << endl;
                                cout << "\t Nombre                 : " << Clientes[CantidadClientes].DatosPersona.Nombres << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Codigo de libro        : " << DatosLibro[i].codigo << endl;
                                cout << "\t Titulo de libro        : " << DatosLibro[i].titulo << endl;
                                cout << "\t Tipo   de libro        : " << DatosLibro[i].tipo << endl;
                                cout << "\t Local                  : " << DatosLibro[i].local << endl;
                                cout << "\t Valor Unitario         : " << DatosLibro[i].precio << endl;
                                cout << "\t Cantidad de libros     : " << Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros << endl;
                                cout << "\t Valor IGV              : " << ValorIGV * 100 << "%" << endl;
                                cout << "\t IGV                    : " << Clientes[CantidadClientes].DatosLibroCliente.IGV << endl;
                                cout << "\t Base Imponible         : " << Clientes[CantidadClientes].DatosLibroCliente.Subtotal << endl;
                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Delivery               : " << CostoDelivery << endl;
                                }

                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << endl;
                                    if (Hora > 0 && Hora <= 8)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[0].DatosTrabajador.Nombres << " " << DatosRepartidores[0].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  938712748" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 8 && Hora <= 16)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[1].DatosTrabajador.Nombres << " " << DatosRepartidores[1].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  902843093" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 16 && Hora <= 24)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[2].DatosTrabajador.Nombres << " " << DatosRepartidores[2].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  989371278" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                }
                                else
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\tBoleta de venta, valido para Sunat" << endl;
                                cout << "\tGracias por su preferencia..." << endl;
                                cout << "\t------------------------------" << endl;
                                break;
                            case 'B':
                                do
                                {
                                    cout << "\n\t Ingrese su numero de RUC (8 digitos sin digitar 10 al inicio y 4 al final) -> "; cin >> RUC;
                                    if (RUC.size() < 8 || RUC.size() > 8)
                                    {
                                        cout << "\n\033[31m Solo debe digitar 8 digitos sin contar 10 al inicio y 4 al final, intentelo de nuevo\033[0m" << endl;
                                    }
                                } while (RUC.size() < 8 || RUC.size() > 8);


                                cout << "\n\t------------------------------" << endl;
                                cout << "\tFACTURA DE VENTA ELECTRONICA \n" << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Fecha                  : " << Dia << "/" << Mes << "/" << Clientes[CantidadClientes].Anio << endl;
                                cout << "\t Hora                   : " << " (";
                                if (Hora < 10)
                                {
                                    cout << "0";
                                }
                                cout << Hora << ":";
                                if (Minuto < 10) {
                                    cout << "0";
                                }
                                cout << Minuto << ") " << endl;
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 0 && Hora <= 8))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[0].DatosTrabajador.Nombres << " " << DatosCajeros[0].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 8 && Hora <= 16))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[1].DatosTrabajador.Nombres << " " << DatosCajeros[1].DatosTrabajador.Apellido << endl;;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 16 && Hora <= 24))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[2].DatosTrabajador.Nombres << " " << DatosCajeros[2].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\t RUC                    : " << " 10" << RUC << "4 " << endl;
                                cout << "\t Razon Social           : " << " Libreria 'Digital Lecture' " << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Codigo de libro        : " << DatosLibro[i].codigo << endl;
                                cout << "\t Titulo de libro        : " << DatosLibro[i].titulo << endl;
                                cout << "\t Tipo   de libro        : " << DatosLibro[i].tipo << endl;
                                cout << "\t Local                  : " << DatosLibro[i].local << endl;
                                cout << "\t Valor Unitario         : " << DatosLibro[i].precio << endl;
                                cout << "\t Cantidad de libros     : " << Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros << endl;
                                cout << "\t Valor IGV              : " << ValorIGV * 100 << "%" << endl;
                                cout << "\t IGV                    : " << Clientes[CantidadClientes].DatosLibroCliente.IGV << endl;
                                cout << "\t Base Imponible         : " << Clientes[CantidadClientes].DatosLibroCliente.Subtotal << endl;
                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Delivery               : " << CostoDelivery << endl;
                                }

                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << endl;
                                    if (Hora > 0 && Hora <= 8)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[0].DatosTrabajador.Nombres << " " << DatosRepartidores[0].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  938712748" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 8 && Hora <= 16)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[1].DatosTrabajador.Nombres << " " << DatosRepartidores[1].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  902843093" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 16 && Hora <= 24)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[2].DatosTrabajador.Nombres << " " << DatosRepartidores[2].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  989371278" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                }
                                else
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\tFactura de venta, valido para Sunat" << endl;
                                cout << "\tGracias por su preferencia..." << endl;
                                cout << "\t------------------------------" << endl;
                                break;
                            case 'C':
                                cout << "\n\t------------------------------" << endl;
                                cout << "\tNOTA DE VENTA ELECTRONICA \n" << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Fecha                  : " << Dia << "/" << Mes << "/" << Clientes[CantidadClientes].Anio << endl;
                                cout << "\t Hora                   : " << " (";
                                if (Hora < 10)
                                {
                                    cout << "0";
                                }
                                cout << Hora << ":";
                                if (Minuto < 10) {
                                    cout << "0";
                                }
                                cout << Minuto << ") " << endl;
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 0 && Hora <= 8))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[0].DatosTrabajador.Nombres << " " << DatosCajeros[0].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 8 && Hora <= 16))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[1].DatosTrabajador.Nombres << " " << DatosCajeros[1].DatosTrabajador.Apellido << endl;;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 16 && Hora <= 24))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[2].DatosTrabajador.Nombres << " " << DatosCajeros[2].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\t Codigo de libro        : " << DatosLibro[i].codigo << endl;
                                cout << "\t Titulo de libro        : " << DatosLibro[i].titulo << endl;
                                cout << "\t Tipo   de libro        : " << DatosLibro[i].tipo << endl;
                                cout << "\t Local                  : " << DatosLibro[i].local << endl;
                                cout << "\t Valor Unitario         : " << DatosLibro[i].precio << endl;
                                cout << "\t Cantidad de libros     : " << Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros << endl;
                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Delivery               : " << CostoDelivery << endl;
                                }

                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << endl;
                                    if (Hora > 0 && Hora <= 8)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[0].DatosTrabajador.Nombres << " " << DatosRepartidores[0].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  938712748" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 8 && Hora <= 16)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[1].DatosTrabajador.Nombres << " " << DatosRepartidores[1].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  902843093" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 16 && Hora <= 24)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[2].DatosTrabajador.Nombres << " " << DatosRepartidores[2].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  989371278" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                }
                                else
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\tNota de venta, no valido para Sunat" << endl;
                                cout << "\tGracias por su preferencia..." << endl;
                                cout << "\t------------------------------" << endl;
                                break;
                            default:
                                cout << "\n\033[31m Ingrese una opcion valida\033[0m" << endl;
                                break;
                            }
                        } while (Clientes[CantidadClientes].OpcionComprobante != 'A' && Clientes[CantidadClientes].OpcionComprobante != 'B' && Clientes[CantidadClientes].OpcionComprobante != 'C');


                        if (Clientes[CantidadClientes].Modalidad == 'A')
                        {
                            cout << "\n\033[32mPago realizado, gracias por su compra! :D \033[0m" << endl;
                        }
                        if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                        {
                            cout << "\n\033[32mVenta Exitosa! :D \033[0m" << endl;
                            cout << "\n\t El envio sera enviado a la siguiente direccion: " << endl;
                            cout << "\t\t Direccion: " << Clientes[CantidadClientes].DireccionCliente.Direcion << endl;
                            cout << "\t\t Departamento: " << Clientes[CantidadClientes].DireccionCliente.Departamento << endl;
                            cout << "\t\t Distrito: " << Clientes[CantidadClientes].DireccionCliente.Distrito << endl;
                            cout << "\t\t Provincia: " << Clientes[CantidadClientes].DireccionCliente.Provincia << endl;
                        }
                        else if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'R')
                        {
                            cout << "\n\033[32mVenta Exitosa! :D \033[0m" << endl;
                        }

                    }
                }
                break;
            case 'M':
                cout << "\n\t -------------------------------------------------------------------------------" << endl;
                cout << "\t| Has elegido Miraflores, estos son los libros de la categoria manga disponibles  |" << endl;
                cout << "\t.--------------------------------------------------------------------------------." << endl;
                cout << " " << endl;

                for (int i = 0; i < 6; i++) {
                    if (DatosLibro[i].tipo == "Manga" && DatosLibro[i].local == "Miraflores") {

                        cout << setw(15) << DatosLibro[i].codigo
                            << setw(25) << DatosLibro[i].titulo
                            << setw(15) << DatosLibro[i].precio << " soles "
                            << setw(20) << DatosLibro[i].local << endl;

                    }

                }
                cout << "\t ------------------------------------------------------------------------------- " << endl;
                do
                {
                    cout << "\nEscriba el codigo del libro que quiera adquirir (La letra va en mayuscula) -> "; cin >> Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido;

                } while (!(Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido == "M1002" || Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido == "M1003"));

                for (int i = 0; i < 6; i++)
                {
                    if (DatosLibro[i].codigo == Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido && DatosLibro[i].local == "Miraflores" && Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido == "M1002") {



                        cout << "Usted eligio: " << DatosLibro[i].titulo << " , que buena eleccion :D" << endl;
                        do
                        {
                            cout << "\n\tIngrese la cantidad de libros de este codigo que desee adquirir -> "; cin >> Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros;
                        } while (Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros <= 0);
                        cout << "\n\t\t***********************************************" << endl;
                        cout << "\t\t* SISTEMA DE CALENDARIZACION DIGITAL LECTURE  *" << endl;
                        cout << "\t\t***********************************************" << endl;

                        do
                        {
                            cout << "\n\t Ingrese el mes en que se esta realizando la compra (Numero entero del 1->12): "; cin >> Mes;
                        } while (!(Mes <= 12 && Mes > 0));
                        do
                        {
                            do
                            {
                                cout << "\n\t Ingrese el dia en que se esta realizando la compra (Numero entero del 1->31 excepto en febrero): "; cin >> Dia;
                            } while (Dia > 31 || Dia <= 0);

                            if (Mes == 2 && Dia > 28)
                            {
                                cout << "\n\033[31m Febrero solo tiene 28 dias, intentelo de nuevo\033[0m" << endl;
                            }
                        } while (Mes == 2 && (Dia > 28 || Dia <= 0));
                        do
                        {

                            cout << "\n\t Ingrese el anio en que se esta realizando la compra (Numero entero del 2022->2024): "; cin >> Clientes[CantidadClientes].Anio;

                        } while (Clientes[CantidadClientes].Anio < 2022 || Clientes[CantidadClientes].Anio > 2024);
                        do
                        {
                            cout << "\n\t Ingrese la hora en la cual se esta realizando la compra: " << endl;
                            cout << "\n\tHora (1-24)-> "; cin >> Hora;

                        } while (!(Hora < 25 && Hora >= 1));
                        do
                        {
                            cout << "\n\tMinuto(s) (0-59) -> "; cin >> Minuto;
                        } while (!(Minuto < 60 && Minuto >= 0));

                        Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal = DatosLibro[i].precio * Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros;
                        Clientes[CantidadClientes].DatosLibroCliente.IGV = Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal * ValorIGV;
                        Clientes[CantidadClientes].DatosLibroCliente.Subtotal = Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal - Clientes[CantidadClientes].DatosLibroCliente.IGV;
                        if (Clientes[CantidadClientes].Modalidad == 'B')
                        {
                            do
                            {

                                cout << "\t |-------------------------------------|  " << endl;
                                cout << "\t |           MODO DE ENTREGA           |  " << endl;
                                cout << "\t |-------------------------------------|  " << endl;
                                cout << "\t |   Recojo en tienda   (R)            |  " << endl;
                                cout << "\t |   Delivery           (D)            |  " << endl;
                                cout << "\t |-------------------------------------|\n" << endl;
                                cout << "\tOpcion -> "; cin >> OpcionEnvio;
                                OpcionEnvio = toupper(OpcionEnvio);
                                if (OpcionEnvio == 'D')
                                {
                                    cout << "El costo adicional por delivery es : " << CostoDelivery << " soles" << endl;
                                }

                                if (OpcionEnvio != 'R' && OpcionEnvio != 'D')
                                {
                                    cout << "\n\033[31m Opcion Invalida \033[0m" << endl;
                                }
                            } while (OpcionEnvio != 'R' && OpcionEnvio != 'D');

                        }


                        cout << "\n\t\t***********************************************" << endl;
                        cout << "\t\t*                Sistema de Pagos             *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t* Opcion A: Credito                           *" << endl;
                        cout << "\t\t* Opcion B: Yape/Plin                         *" << endl;
                        cout << "\t\t* Opcion C: Al Contado                        *" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        do
                        {
                            cout << "\n\t\t Opcion -> ";
                            cin >> Clientes[CantidadClientes].MedioPago;
                            Clientes[CantidadClientes].MedioPago = toupper(Clientes[CantidadClientes].MedioPago);
                            switch (Clientes[CantidadClientes].MedioPago)
                            {
                            case 'A':
                                do
                                {
                                    do
                                    {
                                        cout << "\t Ingrese su numero de tarjeta (13 digitos) -> ";
                                        cin >> NumeroTarjeta;
                                        if (NumeroTarjeta.length() > 13)
                                        {
                                            cout << "\n\033[31m La tarjeta debe contar solo con 13 digitos, intentelo otra vez\033[0m" << endl;
                                        }
                                    } while (NumeroTarjeta.length() > 13);
                                    do
                                    {
                                        cout << "\t Ingrese su CVV (3 digitos) -> ";
                                        cin >> CVV;
                                        if (CVV.length() > 3)
                                        {
                                            cout << "\n\033[31m El CVV solo debe contar con 3 digitos, intentelo otra vez \033[0m" << endl;
                                        }
                                    } while (CVV.length() > 3);

                                    do
                                    {
                                        cout << "\t Ingrese el mes de vencimiento -> ";
                                        cin >> MesVencimiento;
                                    } while (MesVencimiento > 12 || MesVencimiento <= 0);
                                    do
                                    {
                                        cout << "\t Ingrese el anio de vencimiento -> ";
                                        cin >> AnioVencimiento;
                                    } while (AnioVencimiento <= 0);

                                    if (((MesVencimiento < Mes) && (Clientes[CantidadClientes].Anio < AnioVencimiento)) || ((MesVencimiento > Mes) && (Clientes[CantidadClientes].Anio > AnioVencimiento)))
                                    {
                                        cout << "\n\033[31m Esta tarjeta esta vencida, pruebe con otra tarjeta, por favor :c \033[0m" << endl;
                                    }


                                } while (((MesVencimiento < Mes) && (Clientes[CantidadClientes].Anio < AnioVencimiento)) || ((MesVencimiento < Mes) && (Clientes[CantidadClientes].Anio >= AnioVencimiento)));
                                cout << "\n Procesando . . ." << endl;

                                break;
                            case 'B':
                                cout << endl;
                                cout << "\t\t ...............       .....  .............    .....  ...   ..... ..........................    " << endl;
                                cout << "\t\t ..%%%%%%%%%%%%%%%=........*%=....%%%%%%%%%%*....*%%%+..%%:...=%*....%%%%%%+..%%%%%%%%%%%%%%%-.   " << endl;
                                cout << "\t\t ..%%-..........#%=...:%%..*%=....%#:...+%*....#%%%=.-%%..#%:.=%%%%%%%%-.=#+..%#:..........%%-..  " << endl;
                                cout << "\t\t ..%%-.=******..#%=.:**%%..*%=.-**%#**..=%#*+..%%%%#**%%**--+*=-::::::-+*=-:..%#:.+*****+..%%-..  " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%#==..-===*%%%%%%:.-====..%%%%*====%#:.====-..==..-===-..%#:.*%%%%%*..%%-..  " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%#::....+%%%%####-:...::..%%%%=::::%#:...=#*:-#*::::+%+..%#:.*%%%%%*..%%-..  " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%%%%....+%%%%....#%=.-%*..%%%%%%%%%%#:.....:%*..%%%%%%+..%#:.*%%%%%*..%%-..  " << endl;
                                cout << "\t\t  .%%-..........#%=.:%*..%%%%=.-%%......=%%%*..%%-.+%+..%%%%:.=%*.:#%%%-.=%+..%#:..........%%-..  " << endl;
                                cout << "\t\t  .%%%%%%%%%%%%%#%=.:%*..%%-.+%+..%#:.#%=.-%*..%%-.+%+..%%:.#%=.:%#..%#-.=%+..%%%%%%%%%%%%%%%-.   " << endl;
                                cout << "\t\t  ..................:%#%#.........%%%#%%%#*.:%#..+%=.-%%....#%=.:%*....+#=.....................   " << endl;
                                cout << "\t\t ..--:.:----------:.:+*%%....:-:..+*#%%%#++-=*+..=+-.:++----+*=-=%*..--+*-....-----------.....    " << endl;
                                cout << "\t\t ..%#-.+%%%%%%%%%%=...:%%....+#+....*%%#=.-%*...........%%#%:.=##%*..%#-......%%%%%%%%%%*......   " << endl;
                                cout << "\t\t   .........%%%%:.+#*.:%%......-%%..#%:..........*%=.-#%....#%%%*...............*%%%%%*.:#%##-.   " << endl;
                                cout << "\t\t ..%%#%=....%%%%%%=......#%-........#%%%%%%%*..%%-.+%+..%%%%:.=%*....%%-.=%%#%....*%:.=%*........   " << endl;
                                cout << "\t\t ..%%-.+%+............:%%%%-......%#:.......:#%..*%=.-#%....#%=......%%%%=.-%%....*%%%%%*..%%-.   " << endl;
                                cout << "\t\t  .::..::=**....****+.:%%%##*-.-*#::*********::#*###*+::****-:=***+..::::=*+::****#%%%%%#**::.    " << endl;
                                cout << "\t\t . .+++++*+--++..--*%*.:%%%%%%=.-%%+*#%%%+-=%#*%%%%%%%%#=----++#%#--..++:.:-=*+----#%%%#----...    " << endl;
                                cout << "\t\t  .###%%%+..%#:.::=#*:-##%%%#=:=%%###%%%=.:#%%#*+==+*#%%#:::*###*:..:%%-...-%%..::*###*:......    " << endl;
                                cout << "\t\t  ...*%%%+..%#:.##=.-%*..%%%%%%%%%..*%%%=.+%%#+==+====*%%#%%:...:%%#%#%-...-%%..*%:...:%*......   " << endl;
                                cout << "\t\t   ......-#%........-%%%%%%%%%%+..##:.#%=:%%#==***+=*+=#%%-.#%=........+%%%+..%#:.*%=......##-.   " << endl;
                                cout << "\t\t ..%%%%=....%%%%%%%%%%*..%%-........*%%%=:%%#==++*+*+==#%%%%:.=%*....%%-.=%%#%....*#%%#.:%%...    " << endl;
                                cout << "\t\t ..#%-......%#:.......:#%......-%%%#:.....+%%*+=+*++==*%%#....=%*....%%%%=.-%%##:.*%=......%%-.   " << endl;
                                cout << "\t\t ..++:.:-:..++=---:..-=*+--....-++%#=---:.:#%%+++==++#%%#%%%%=-++----#%*+=-+%%+*--+*=------**:.   " << endl;
                                cout << "\t\t   ....=*+....#%#*=.:**::#*-::::::*##%*#+-=%%%%%%%%%%%%%%###%%#.:******=:=**##::**-:+%#****::..   " << endl;
                                cout << "\t\t   ...........#%:.....:%#..+#%%%##..*#%%%%%###%**=+-...*+.=.#%#:.......+%=....%#:.*%##*....#%-.   " << endl;
                                cout << "\t\t   ....+%+..%%%%%%=......%%-.+%+..%#:-%#*:#*.+:-#.#:=%:=...+%%%%*.:%%%%-.=%+......*%=.:%##%...    " << endl;
                                cout << "\t\t  ...+%%%%##......+%%%%%%%%-........*#%#.=#::--%-:+.%+.-:%#-###.:%*........-%%..*%%%=...:#%...    " << endl;
                                cout << "\t\t  .###%%%%%###:.*#=:::-%%::+###+....#%%+.*-.=.:=....:.*#..:#%%##############%%..*%-:=###*::...    " << endl;
                                cout << "\t\t ..%%%%%%*-:::..::=*+..:-..*%+:=****+#%*.::.##+*#*.*##+-::*%%#=::::::::*%+::--**--+*=:::-****-.   " << endl;
                                cout << "\t\t ..%%%%%%+........=%*......*%=.-%%%#+##%%+.:::.....-+***##%%%%=........+%=....##:.*%=...:#%%%-..  " << endl;
                                cout << "\t\t   ..*#=.-%%%%%%%%=.-%*..%%%%%#+..:#%%#:..:+*#%%%#%%%%%%%%#+..=%%%*..%%-.=%%#%..*#%%=...:#%%%-..  " << endl;
                                cout << "\t\t  ...*%#%+..%#:...+#*......*%=.-##%%%-.*+.*%%##+*%%*:-%%%#:.#%%%*....%%-......##:.*%=......%%-.   " << endl;
                                cout << "\t\t  .%%#%=.-%%%#%%%%=.-%%%#%%%%=...=%%=:#=.*%##......+%+....*%:.=%%%%%%....=%+....*%:.=#%%*..%%-.   " << endl;
                                cout << "\t\t  .......-%%%#:.......-%%........-%%*..-#%%+-######=.-####:.*#=......####=.-####:.*#=...:##....   " << endl;
                                cout << "\t\t  .==:...-%%+=..======+%%......:==+%%%%%%#-==+++=#%*==++%#:.=+==-....=+++==+%%##+=#%=....=+...    " << endl;
                                cout << "\t\t  .%%-...-**-:..+*#%%%#**::....-%%---+**-.:%*..::*%%%+..%#:.:-+%#-:..:-..=%#****#%%%=....:-...    " << endl;
                                cout << "\t\t  .%%-......%#:...+%%%*..#%-...-%%%#:.....-%*..%%%%%%+..%#:.#%%%%%*..%%-.=%+....*%##=...:#%....   " << endl;
                                cout << "\t\t  .%%-...-%%....##=.-%%#%%%%%%%%%%%%%%:.....:%#.........%#:.#%%%%%%#%#%%%=.-#%..*%:.=##%*......   " << endl;
                                cout << "\t\t  .%%-.+%+..%#:.....-%*....+%=.-%%..#%#%=...:%%%%%%%%+..%#:.#%=........+%%%+..%%:.*#%%*....%%-.   " << endl;
                                cout << "\t\t ..%%-.+%+..%#:.#%%%%%%%%......-%%%#:.##%%%%%#%%%-.+%+........=%%%#......=%%%%##%%%%%%%%%%%....   " << endl;
                                cout << "\t\t  .:-..:-:..::..:---=%%%%******+--%#:.:-+%###--:-+*=-:........=%%%*..**-.=%*-----:#%+------....   " << endl;
                                cout << "\t\t   .................:%%%%####%%+..%#:...=#%#*....+#=..........=%%%*..#%-.=%+......*%=.........    " << endl;
                                cout << "\t\t ..#%%%%%%%%%%%%#%=...:%%....+%+..%#:...+%*.:%%%%%%=....%%%%:.=%%%%%%%%-.=%+..%%:.*%#%%%*.....    " << endl;
                                cout << "\t\t  .%%-..........#%=.:%#%%%%-.+%%%%%#:.#%%%%%*..#%%%%%+......#%=..........=%+......*%=......%%-.   " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:#*....*%=.-%%%%%%%%=........*%=....%%%%:.=%%%*..%%-.=%%%%%%%%%%#%*.:#%....   " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%###..*%##+::%#-:::=######..+%#####::::..=%#:...%%###%%%%::::*%+:...::...    " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%#==..*%%%+..%#++++*%#====++=======..=+..=%#++++#%+===+%%....*%*++++++...    " << endl;
                                cout << "\t\t  .%%-.-++++++..#%=.:*+..--*%*++--***++*+*=..--*+=--------+*--=+******+-...-%%..--++++++++*--.    " << endl;
                                cout << "\t\t  .%%-..........#%=......%#%%=.-%%..........:%#..*%%%%%%%#:.#%=............-%%..*%:........#%-.   " << endl;
                                cout << "\t\t  .#%%%%%%%%%%%%%%=.:%*..%%%%=.-%%..#%%%=......%%-........*%:.=%*.:%%%%-......%#:.*%=..........   " << endl;
                                cout << "\t\t                                ....    ...     ...         ...  ......         ......               " << endl;
                                cout << "\n\n\t Escanea el codigo QR para continuar : " << endl;
                                getch(); // Presionar cualquier tecla 
                                cout << "\n\t Procesando pago . . ." << endl;
                                getch(); // Presionar cualquier tecla
                                break;
                            case 'C':
                                do
                                {
                                    cout << "\t\t Ingrese el monto con el que pagara -> ";
                                    cin >> MontoPago;
                                    if (MontoPago < Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal && OpcionEnvio == 'D')
                                    {
                                        cout << "\n\033[31m El monto ingresado es insuficiente, el precio es: \033[0m" << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << "\033[31m ingrese otro monto, por favor \033[0m" << endl;
                                    }
                                    if (MontoPago < Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal && OpcionEnvio != 'D')
                                    {
                                        cout << "\n\033[31m El monto ingresado es insuficiente, el precio es: \033[0m" << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << "\033[31m ingrese otro monto, por favor \033[0m" << endl;
                                    }
                                } while (MontoPago < Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal);
                                if (OpcionEnvio != 'D')
                                {
                                    Vuelto = MontoPago - Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal;
                                }
                                else
                                {
                                    Vuelto = MontoPago - Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + 5;
                                }
                                cout << " Su vuelto sera de: " << Vuelto;
                                break;
                            default: cout << "\n\033[31m Ingrese una opcion valida\033[0m" << endl;
                                break;
                            }
                        } while (!(Clientes[CantidadClientes].MedioPago == 'A' || Clientes[CantidadClientes].MedioPago == 'B' || Clientes[CantidadClientes].MedioPago == 'C'));
                        cout << "\n\t\t***********************************************" << endl;
                        cout << "\t\t*                Opcion de Comprobantes        *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t* Opcion A: Boleta Electronica                *" << endl;
                        cout << "\t\t* Opcion B: Factura                           *" << endl;
                        cout << "\t\t* Opcion C: Nota de venta                     *" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        do
                        {
                            cout << "\n\t\t Opcion -> "; cin >> Clientes[CantidadClientes].OpcionComprobante;
                            Clientes[CantidadClientes].OpcionComprobante = toupper(Clientes[CantidadClientes].OpcionComprobante);
                            switch (Clientes[CantidadClientes].OpcionComprobante)
                            {
                            case 'A':
                                cout << "\n\t------------------------------" << endl;
                                cout << "\tBOLETA DE VENTA ELECTRONICA \n" << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Fecha                  : " << Dia << "/" << Mes << "/" << Clientes[CantidadClientes].Anio << endl;
                                cout << "\t Hora                   : " << " (";
                                if (Hora < 10)
                                {
                                    cout << "0";
                                }
                                cout << Hora << ":";
                                if (Minuto < 10) {
                                    cout << "0";
                                }
                                cout << Minuto << ") " << endl;
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 0 && Hora <= 8))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[0].DatosTrabajador.Nombres << " " << DatosCajeros[0].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 8 && Hora <= 16))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[1].DatosTrabajador.Nombres << " " << DatosCajeros[1].DatosTrabajador.Apellido << endl;;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 16 && Hora <= 24))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[2].DatosTrabajador.Nombres << " " << DatosCajeros[2].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\t DNI                    : " << Clientes[CantidadClientes].DatosPersona.DNI << endl;
                                cout << "\t Nombre                 : " << Clientes[CantidadClientes].DatosPersona.Nombres << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Codigo de libro        : " << DatosLibro[i].codigo << endl;
                                cout << "\t Titulo de libro        : " << DatosLibro[i].titulo << endl;
                                cout << "\t Tipo   de libro        : " << DatosLibro[i].tipo << endl;
                                cout << "\t Local                  : " << DatosLibro[i].local << endl;
                                cout << "\t Valor Unitario         : " << DatosLibro[i].precio << endl;
                                cout << "\t Cantidad de libros     : " << Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros << endl;
                                cout << "\t Valor IGV              : " << ValorIGV * 100 << "%" << endl;
                                cout << "\t IGV                    : " << Clientes[CantidadClientes].DatosLibroCliente.IGV << endl;
                                cout << "\t Base Imponible         : " << Clientes[CantidadClientes].DatosLibroCliente.Subtotal << endl;
                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Delivery               : " << CostoDelivery << endl;
                                }

                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << endl;
                                    if (Hora > 0 && Hora <= 8)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[0].DatosTrabajador.Nombres << " " << DatosRepartidores[0].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  938712748" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 8 && Hora <= 16)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[1].DatosTrabajador.Nombres << " " << DatosRepartidores[1].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  902843093" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 16 && Hora <= 24)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[2].DatosTrabajador.Nombres << " " << DatosRepartidores[2].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  989371278" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                }
                                else
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\tBoleta de venta, valido para Sunat" << endl;
                                cout << "\tGracias por su preferencia..." << endl;
                                cout << "\t------------------------------" << endl;
                                break;
                            case 'B':
                                do
                                {
                                    cout << "\n\t Ingrese su numero de RUC (8 digitos sin digitar 10 al inicio y 4 al final) -> "; cin >> RUC;
                                    if (RUC.size() < 8 || RUC.size() > 8)
                                    {
                                        cout << "\n\033[31m Solo debe digitar 8 digitos sin contar 10 al inicio y 4 al final, intentelo de nuevo\033[0m" << endl;
                                    }
                                } while (RUC.size() < 8 || RUC.size() > 8);


                                cout << "\n\t------------------------------" << endl;
                                cout << "\tFACTURA DE VENTA ELECTRONICA \n" << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Fecha                  : " << Dia << "/" << Mes << "/" << Clientes[CantidadClientes].Anio << endl;
                                cout << "\t Hora                   : " << " (";
                                if (Hora < 10)
                                {
                                    cout << "0";
                                }
                                cout << Hora << ":";
                                if (Minuto < 10) {
                                    cout << "0";
                                }
                                cout << Minuto << ") " << endl;
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 0 && Hora <= 8))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[0].DatosTrabajador.Nombres << " " << DatosCajeros[0].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 8 && Hora <= 16))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[1].DatosTrabajador.Nombres << " " << DatosCajeros[1].DatosTrabajador.Apellido << endl;;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 16 && Hora <= 24))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[2].DatosTrabajador.Nombres << " " << DatosCajeros[2].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\t RUC                    : " << " 10" << RUC << "4 " << endl;
                                cout << "\t Razon Social           : " << " Libreria 'Digital Lecture' " << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Codigo de libro        : " << DatosLibro[i].codigo << endl;
                                cout << "\t Titulo de libro        : " << DatosLibro[i].titulo << endl;
                                cout << "\t Tipo   de libro        : " << DatosLibro[i].tipo << endl;
                                cout << "\t Local                  : " << DatosLibro[i].local << endl;
                                cout << "\t Valor Unitario         : " << DatosLibro[i].precio << endl;
                                cout << "\t Cantidad de libros     : " << Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros << endl;
                                cout << "\t Valor IGV              : " << ValorIGV * 100 << "%" << endl;
                                cout << "\t IGV                    : " << Clientes[CantidadClientes].DatosLibroCliente.IGV << endl;
                                cout << "\t Base Imponible         : " << Clientes[CantidadClientes].DatosLibroCliente.Subtotal << endl;
                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Delivery               : " << CostoDelivery << endl;
                                }

                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << endl;
                                    if (Hora > 0 && Hora <= 8)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[0].DatosTrabajador.Nombres << " " << DatosRepartidores[0].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  938712748" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 8 && Hora <= 16)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[1].DatosTrabajador.Nombres << " " << DatosRepartidores[1].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  902843093" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 16 && Hora <= 24)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[2].DatosTrabajador.Nombres << " " << DatosRepartidores[2].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  989371278" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                }
                                else
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\tFactura de venta, valido para Sunat" << endl;
                                cout << "\tGracias por su preferencia..." << endl;
                                cout << "\t------------------------------" << endl;
                                break;
                            case 'C':
                                cout << "\n\t------------------------------" << endl;
                                cout << "\tNOTA DE VENTA ELECTRONICA \n" << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Fecha                  : " << Dia << "/" << Mes << "/" << Clientes[CantidadClientes].Anio << endl;
                                cout << "\t Hora                   : " << " (";
                                if (Hora < 10)
                                {
                                    cout << "0";
                                }
                                cout << Hora << ":";
                                if (Minuto < 10) {
                                    cout << "0";
                                }
                                cout << Minuto << ") " << endl;
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 0 && Hora <= 8))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[0].DatosTrabajador.Nombres << " " << DatosCajeros[0].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 8 && Hora <= 16))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[1].DatosTrabajador.Nombres << " " << DatosCajeros[1].DatosTrabajador.Apellido << endl;;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 16 && Hora <= 24))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[2].DatosTrabajador.Nombres << " " << DatosCajeros[2].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\t Codigo de libro        : " << DatosLibro[i].codigo << endl;
                                cout << "\t Titulo de libro        : " << DatosLibro[i].titulo << endl;
                                cout << "\t Tipo   de libro        : " << DatosLibro[i].tipo << endl;
                                cout << "\t Local                  : " << DatosLibro[i].local << endl;
                                cout << "\t Valor Unitario         : " << DatosLibro[i].precio << endl;
                                cout << "\t Cantidad de libros     : " << Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros << endl;
                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Delivery               : " << CostoDelivery << endl;
                                }

                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << endl;
                                    if (Hora > 0 && Hora <= 8)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[0].DatosTrabajador.Nombres << " " << DatosRepartidores[0].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  938712748" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 8 && Hora <= 16)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[1].DatosTrabajador.Nombres << " " << DatosRepartidores[1].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  902843093" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 16 && Hora <= 24)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[2].DatosTrabajador.Nombres << " " << DatosRepartidores[2].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  989371278" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                }
                                else
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\tNota de venta, no valido para Sunat" << endl;
                                cout << "\tGracias por su preferencia..." << endl;
                                cout << "\t------------------------------" << endl;
                                break;
                            default:
                                cout << "\n\033[31m Ingrese una opcion valida\033[0m" << endl;
                                break;
                            }
                        } while (Clientes[CantidadClientes].OpcionComprobante != 'A' && Clientes[CantidadClientes].OpcionComprobante != 'B' && Clientes[CantidadClientes].OpcionComprobante != 'C');



                        if (Clientes[CantidadClientes].Modalidad == 'A')
                        {
                            cout << "\n\033[32mPago realizado, gracias por su compra! :D \033[0m" << endl;
                        }
                        if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                        {
                            cout << "\n\033[32mVenta Exitosa! :D \033[0m" << endl;
                            cout << "\n\t El envio sera enviado a la siguiente direccion: " << endl;
                            cout << "\t\t Direccion: " << Clientes[CantidadClientes].DireccionCliente.Direcion << endl;
                            cout << "\t\t Departamento: " << Clientes[CantidadClientes].DireccionCliente.Departamento << endl;
                            cout << "\t\t Distrito: " << Clientes[CantidadClientes].DireccionCliente.Distrito << endl;
                            cout << "\t\t Provincia: " << Clientes[CantidadClientes].DireccionCliente.Provincia << endl;
                        }
                        else if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'R')
                        {
                            cout << "\n\033[32mVenta Exitosa! :D \033[0m" << endl;
                        }

                    }
                    if (DatosLibro[i].codigo == Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido && DatosLibro[i].local == "Miraflores" && Clientes[CantidadClientes].DatosLibroCliente.CodigoLibroElegido == "M1003") {
                        cout << "Usted eligio: " << DatosLibro[i].titulo << " , que buena eleccion :D" << endl;
                        do
                        {
                            cout << "Ingrese la cantidad de libros de este codigo que desee adquirir -> "; cin >> Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros;
                        } while (Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros <= 0);

                        do
                        {
                            cout << "\n Ingrese el mes en que se esta realizando la compra (Numero entero del 1->12): "; cin >> Mes;
                        } while (!(Mes <= 12 && Mes > 0));
                        do
                        {
                            do
                            {
                                cout << "\n Ingrese el dia en que se esta realizando la compra (Numero entero del 1->31 excepto en febrero): "; cin >> Dia;
                            } while (Dia > 31 || Dia <= 0);

                            if (Mes == 2 && Dia > 28)
                            {
                                cout << "\n\033[31m Febrero solo tiene 28 dias, intentelo de nuevo\033[0m" << endl;
                            }
                        } while (Mes == 2 && (Dia > 28 || Dia <= 0));
                        do
                        {

                            cout << "\n Ingrese el anio en que se esta realizando la compra (Numero entero del 2022->2024): "; cin >> Clientes[CantidadClientes].Anio;

                        } while (Clientes[CantidadClientes].Anio < 2022 || Clientes[CantidadClientes].Anio > 2024);
                        do
                        {
                            cout << "\n Ingrese la hora en la cual se esta realizando la compra: " << endl;
                            cout << "Hora (1-24)-> "; cin >> Hora;

                        } while (!(Hora < 25 && Hora >= 1));
                        do
                        {
                            cout << "Minuto(s) (0-59) -> "; cin >> Minuto;
                        } while (!(Minuto < 60 && Minuto >= 0));

                        Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal = DatosLibro[i].precio * Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros;
                        Clientes[CantidadClientes].DatosLibroCliente.IGV = Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal * ValorIGV;
                        Clientes[CantidadClientes].DatosLibroCliente.Subtotal = Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal - Clientes[CantidadClientes].DatosLibroCliente.IGV;
                        if (Clientes[CantidadClientes].Modalidad == 'B')
                        {
                            do
                            {

                                cout << "\t |-------------------------------------|  " << endl;
                                cout << "\t |           MODO DE ENTREGA           |  " << endl;
                                cout << "\t |-------------------------------------|  " << endl;
                                cout << "\t |   Recojo en tienda   (R)            |  " << endl;
                                cout << "\t |   Delivery           (D)            |  " << endl;
                                cout << "\t |-------------------------------------|\n" << endl;
                                cout << "\tOpcion -> "; cin >> OpcionEnvio;
                                OpcionEnvio = toupper(OpcionEnvio);
                                if (OpcionEnvio == 'D')
                                {
                                    cout << "El costo adicional por delivery es : " << CostoDelivery << " soles" << endl;
                                }

                                if (OpcionEnvio != 'R' && OpcionEnvio != 'D')
                                {
                                    cout << "\n\033[31m Opcion Invalida \033[0m" << endl;
                                }
                            } while (OpcionEnvio != 'R' && OpcionEnvio != 'D');

                        }


                        cout << "\n\t\t***********************************************" << endl;
                        cout << "\t\t*                Sistema de Pagos             *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t* Opcion A: Credito                           *" << endl;
                        cout << "\t\t* Opcion B: Yape/Plin                         *" << endl;
                        cout << "\t\t* Opcion C: Al Contado                        *" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        do
                        {
                            cout << "\n\t\t Opcion -> ";
                            cin >> Clientes[CantidadClientes].MedioPago;
                            Clientes[CantidadClientes].MedioPago = toupper(Clientes[CantidadClientes].MedioPago);
                            switch (Clientes[CantidadClientes].MedioPago)
                            {
                            case 'A':
                                do
                                {
                                    do
                                    {
                                        cout << "\t Ingrese su numero de tarjeta (13 digitos) -> ";
                                        cin >> NumeroTarjeta;
                                        if (NumeroTarjeta.length() > 13)
                                        {
                                            cout << "\n\033[31m La tarjeta debe contar solo con 13 digitos, intentelo otra vez\033[0m" << endl;
                                        }
                                    } while (NumeroTarjeta.length() > 13);
                                    do
                                    {
                                        cout << "\t Ingrese su CVV (3 digitos) -> ";
                                        cin >> CVV;
                                        if (CVV.length() > 3)
                                        {
                                            cout << "\n\033[31m El CVV solo debe contar con 3 digitos, intentelo otra vez \033[0m" << endl;
                                        }
                                    } while (CVV.length() > 3);

                                    do
                                    {
                                        cout << "\t Ingrese el mes de vencimiento -> ";
                                        cin >> MesVencimiento;
                                    } while (MesVencimiento > 12 || MesVencimiento <= 0);
                                    do
                                    {
                                        cout << "\t Ingrese el anio de vencimiento -> ";
                                        cin >> AnioVencimiento;
                                    } while (AnioVencimiento <= 0);

                                    if (((MesVencimiento < Mes) && (Clientes[CantidadClientes].Anio < AnioVencimiento)) || ((MesVencimiento > Mes) && (Clientes[CantidadClientes].Anio > AnioVencimiento)))
                                    {
                                        cout << "\n\033[31m Esta tarjeta esta vencida, pruebe con otra tarjeta, por favor :c \033[0m" << endl;
                                    }


                                } while (((MesVencimiento < Mes) && (Clientes[CantidadClientes].Anio < AnioVencimiento)) || ((MesVencimiento < Mes) && (Clientes[CantidadClientes].Anio >= AnioVencimiento)));
                                cout << "\n Procesando . . ." << endl;

                                break;
                            case 'B':
                                cout << endl;
                                cout << "\t\t ...............       .....  .............    .....  ...   ..... ..........................    " << endl;
                                cout << "\t\t ..%%%%%%%%%%%%%%%=........*%=....%%%%%%%%%%*....*%%%+..%%:...=%*....%%%%%%+..%%%%%%%%%%%%%%%-.   " << endl;
                                cout << "\t\t ..%%-..........#%=...:%%..*%=....%#:...+%*....#%%%=.-%%..#%:.=%%%%%%%%-.=#+..%#:..........%%-..  " << endl;
                                cout << "\t\t ..%%-.=******..#%=.:**%%..*%=.-**%#**..=%#*+..%%%%#**%%**--+*=-::::::-+*=-:..%#:.+*****+..%%-..  " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%#==..-===*%%%%%%:.-====..%%%%*====%#:.====-..==..-===-..%#:.*%%%%%*..%%-..  " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%#::....+%%%%####-:...::..%%%%=::::%#:...=#*:-#*::::+%+..%#:.*%%%%%*..%%-..  " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%%%%....+%%%%....#%=.-%*..%%%%%%%%%%#:.....:%*..%%%%%%+..%#:.*%%%%%*..%%-..  " << endl;
                                cout << "\t\t  .%%-..........#%=.:%*..%%%%=.-%%......=%%%*..%%-.+%+..%%%%:.=%*.:#%%%-.=%+..%#:..........%%-..  " << endl;
                                cout << "\t\t  .%%%%%%%%%%%%%#%=.:%*..%%-.+%+..%#:.#%=.-%*..%%-.+%+..%%:.#%=.:%#..%#-.=%+..%%%%%%%%%%%%%%%-.   " << endl;
                                cout << "\t\t  ..................:%#%#.........%%%#%%%#*.:%#..+%=.-%%....#%=.:%*....+#=.....................   " << endl;
                                cout << "\t\t ..--:.:----------:.:+*%%....:-:..+*#%%%#++-=*+..=+-.:++----+*=-=%*..--+*-....-----------.....    " << endl;
                                cout << "\t\t ..%#-.+%%%%%%%%%%=...:%%....+#+....*%%#=.-%*...........%%#%:.=##%*..%#-......%%%%%%%%%%*......   " << endl;
                                cout << "\t\t   .........%%%%:.+#*.:%%......-%%..#%:..........*%=.-#%....#%%%*...............*%%%%%*.:#%##-.   " << endl;
                                cout << "\t\t ..%%#%=....%%%%%%=......#%-........#%%%%%%%*..%%-.+%+..%%%%:.=%*....%%-.=%%#%....*%:.=%*........   " << endl;
                                cout << "\t\t ..%%-.+%+............:%%%%-......%#:.......:#%..*%=.-#%....#%=......%%%%=.-%%....*%%%%%*..%%-.   " << endl;
                                cout << "\t\t  .::..::=**....****+.:%%%##*-.-*#::*********::#*###*+::****-:=***+..::::=*+::****#%%%%%#**::.    " << endl;
                                cout << "\t\t . .+++++*+--++..--*%*.:%%%%%%=.-%%+*#%%%+-=%#*%%%%%%%%#=----++#%#--..++:.:-=*+----#%%%#----...    " << endl;
                                cout << "\t\t  .###%%%+..%#:.::=#*:-##%%%#=:=%%###%%%=.:#%%#*+==+*#%%#:::*###*:..:%%-...-%%..::*###*:......    " << endl;
                                cout << "\t\t  ...*%%%+..%#:.##=.-%*..%%%%%%%%%..*%%%=.+%%#+==+====*%%#%%:...:%%#%#%-...-%%..*%:...:%*......   " << endl;
                                cout << "\t\t   ......-#%........-%%%%%%%%%%+..##:.#%=:%%#==***+=*+=#%%-.#%=........+%%%+..%#:.*%=......##-.   " << endl;
                                cout << "\t\t ..%%%%=....%%%%%%%%%%*..%%-........*%%%=:%%#==++*+*+==#%%%%:.=%*....%%-.=%%#%....*#%%#.:%%...    " << endl;
                                cout << "\t\t ..#%-......%#:.......:#%......-%%%#:.....+%%*+=+*++==*%%#....=%*....%%%%=.-%%##:.*%=......%%-.   " << endl;
                                cout << "\t\t ..++:.:-:..++=---:..-=*+--....-++%#=---:.:#%%+++==++#%%#%%%%=-++----#%*+=-+%%+*--+*=------**:.   " << endl;
                                cout << "\t\t   ....=*+....#%#*=.:**::#*-::::::*##%*#+-=%%%%%%%%%%%%%%###%%#.:******=:=**##::**-:+%#****::..   " << endl;
                                cout << "\t\t   ...........#%:.....:%#..+#%%%##..*#%%%%%###%**=+-...*+.=.#%#:.......+%=....%#:.*%##*....#%-.   " << endl;
                                cout << "\t\t   ....+%+..%%%%%%=......%%-.+%+..%#:-%#*:#*.+:-#.#:=%:=...+%%%%*.:%%%%-.=%+......*%=.:%##%...    " << endl;
                                cout << "\t\t  ...+%%%%##......+%%%%%%%%-........*#%#.=#::--%-:+.%+.-:%#-###.:%*........-%%..*%%%=...:#%...    " << endl;
                                cout << "\t\t  .###%%%%%###:.*#=:::-%%::+###+....#%%+.*-.=.:=....:.*#..:#%%##############%%..*%-:=###*::...    " << endl;
                                cout << "\t\t ..%%%%%%*-:::..::=*+..:-..*%+:=****+#%*.::.##+*#*.*##+-::*%%#=::::::::*%+::--**--+*=:::-****-.   " << endl;
                                cout << "\t\t ..%%%%%%+........=%*......*%=.-%%%#+##%%+.:::.....-+***##%%%%=........+%=....##:.*%=...:#%%%-..  " << endl;
                                cout << "\t\t   ..*#=.-%%%%%%%%=.-%*..%%%%%#+..:#%%#:..:+*#%%%#%%%%%%%%#+..=%%%*..%%-.=%%#%..*#%%=...:#%%%-..  " << endl;
                                cout << "\t\t  ...*%#%+..%#:...+#*......*%=.-##%%%-.*+.*%%##+*%%*:-%%%#:.#%%%*....%%-......##:.*%=......%%-.   " << endl;
                                cout << "\t\t  .%%#%=.-%%%#%%%%=.-%%%#%%%%=...=%%=:#=.*%##......+%+....*%:.=%%%%%%....=%+....*%:.=#%%*..%%-.   " << endl;
                                cout << "\t\t  .......-%%%#:.......-%%........-%%*..-#%%+-######=.-####:.*#=......####=.-####:.*#=...:##....   " << endl;
                                cout << "\t\t  .==:...-%%+=..======+%%......:==+%%%%%%#-==+++=#%*==++%#:.=+==-....=+++==+%%##+=#%=....=+...    " << endl;
                                cout << "\t\t  .%%-...-**-:..+*#%%%#**::....-%%---+**-.:%*..::*%%%+..%#:.:-+%#-:..:-..=%#****#%%%=....:-...    " << endl;
                                cout << "\t\t  .%%-......%#:...+%%%*..#%-...-%%%#:.....-%*..%%%%%%+..%#:.#%%%%%*..%%-.=%+....*%##=...:#%....   " << endl;
                                cout << "\t\t  .%%-...-%%....##=.-%%#%%%%%%%%%%%%%%:.....:%#.........%#:.#%%%%%%#%#%%%=.-#%..*%:.=##%*......   " << endl;
                                cout << "\t\t  .%%-.+%+..%#:.....-%*....+%=.-%%..#%#%=...:%%%%%%%%+..%#:.#%=........+%%%+..%%:.*#%%*....%%-.   " << endl;
                                cout << "\t\t ..%%-.+%+..%#:.#%%%%%%%%......-%%%#:.##%%%%%#%%%-.+%+........=%%%#......=%%%%##%%%%%%%%%%%....   " << endl;
                                cout << "\t\t  .:-..:-:..::..:---=%%%%******+--%#:.:-+%###--:-+*=-:........=%%%*..**-.=%*-----:#%+------....   " << endl;
                                cout << "\t\t   .................:%%%%####%%+..%#:...=#%#*....+#=..........=%%%*..#%-.=%+......*%=.........    " << endl;
                                cout << "\t\t ..#%%%%%%%%%%%%#%=...:%%....+%+..%#:...+%*.:%%%%%%=....%%%%:.=%%%%%%%%-.=%+..%%:.*%#%%%*.....    " << endl;
                                cout << "\t\t  .%%-..........#%=.:%#%%%%-.+%%%%%#:.#%%%%%*..#%%%%%+......#%=..........=%+......*%=......%%-.   " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:#*....*%=.-%%%%%%%%=........*%=....%%%%:.=%%%*..%%-.=%%%%%%%%%%#%*.:#%....   " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%###..*%##+::%#-:::=######..+%#####::::..=%#:...%%###%%%%::::*%+:...::...    " << endl;
                                cout << "\t\t  .%%-.+%%%%%#:.#%=.:%#==..*%%%+..%#++++*%#====++=======..=+..=%#++++#%+===+%%....*%*++++++...    " << endl;
                                cout << "\t\t  .%%-.-++++++..#%=.:*+..--*%*++--***++*+*=..--*+=--------+*--=+******+-...-%%..--++++++++*--.    " << endl;
                                cout << "\t\t  .%%-..........#%=......%#%%=.-%%..........:%#..*%%%%%%%#:.#%=............-%%..*%:........#%-.   " << endl;
                                cout << "\t\t  .#%%%%%%%%%%%%%%=.:%*..%%%%=.-%%..#%%%=......%%-........*%:.=%*.:%%%%-......%#:.*%=..........   " << endl;
                                cout << "\t\t                                ....    ...     ...         ...  ......         ......               " << endl;
                                cout << "\n\n\t Escanea el codigo QR para continuar : " << endl;
                                getch(); // Presionar cualquier tecla 
                                cout << "\n\t Procesando pago . . ." << endl;
                                getch(); // Presionar cualquier tecla
                                break;
                            case 'C':
                                do
                                {
                                    cout << "\t\t Ingrese el monto con el que pagara -> ";
                                    cin >> MontoPago;
                                    if (MontoPago < Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal && OpcionEnvio == 'D')
                                    {
                                        cout << "\n\033[31m El monto ingresado es insuficiente, el precio es: \033[0m" << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << "\033[31m ingrese otro monto, por favor \033[0m" << endl;
                                    }
                                    if (MontoPago < Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal && OpcionEnvio != 'D')
                                    {
                                        cout << "\n\033[31m El monto ingresado es insuficiente, el precio es: \033[0m" << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << "\033[31m ingrese otro monto, por favor \033[0m" << endl;
                                    }
                                } while (MontoPago < Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal);
                                if (OpcionEnvio != 'D')
                                {
                                    Vuelto = MontoPago - Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal;
                                }
                                else
                                {
                                    Vuelto = MontoPago - Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + 5;
                                }
                                cout << " Su vuelto sera de: " << Vuelto;
                                break;
                            default: cout << "\n\033[31m Ingrese una opcion valida\033[0m" << endl;
                                break;
                            }
                        } while (!(Clientes[CantidadClientes].MedioPago == 'A' || Clientes[CantidadClientes].MedioPago == 'B' || Clientes[CantidadClientes].MedioPago == 'C'));
                        cout << "\n\t\t***********************************************" << endl;
                        cout << "\t\t*                Opcion de Comprobantes        *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t* Opcion A: Boleta Electronica                *" << endl;
                        cout << "\t\t* Opcion B: Factura                           *" << endl;
                        cout << "\t\t* Opcion C: Nota de venta                     *" << endl;
                        cout << "\t\t*                                             *" << endl;
                        cout << "\t\t***********************************************" << endl;
                        do
                        {
                            cout << "\n\t\t Opcion -> "; cin >> Clientes[CantidadClientes].OpcionComprobante;
                            Clientes[CantidadClientes].OpcionComprobante = toupper(Clientes[CantidadClientes].OpcionComprobante);
                            switch (Clientes[CantidadClientes].OpcionComprobante)
                            {
                            case 'A':
                                cout << "\n\t------------------------------" << endl;
                                cout << "\tBOLETA DE VENTA ELECTRONICA \n" << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Fecha                  : " << Dia << "/" << Mes << "/" << Clientes[CantidadClientes].Anio << endl;
                                cout << "\t Hora                   : " << " (";
                                if (Hora < 10)
                                {
                                    cout << "0";
                                }
                                cout << Hora << ":";
                                if (Minuto < 10) {
                                    cout << "0";
                                }
                                cout << Minuto << ") " << endl;
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 0 && Hora <= 8))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[0].DatosTrabajador.Nombres << " " << DatosCajeros[0].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 8 && Hora <= 16))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[1].DatosTrabajador.Nombres << " " << DatosCajeros[1].DatosTrabajador.Apellido << endl;;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 16 && Hora <= 24))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[2].DatosTrabajador.Nombres << " " << DatosCajeros[2].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\t DNI                    : " << Clientes[CantidadClientes].DatosPersona.DNI << endl;
                                cout << "\t Nombre                 : " << Clientes[CantidadClientes].DatosPersona.Nombres << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Codigo de libro        : " << DatosLibro[i].codigo << endl;
                                cout << "\t Titulo de libro        : " << DatosLibro[i].titulo << endl;
                                cout << "\t Tipo   de libro        : " << DatosLibro[i].tipo << endl;
                                cout << "\t Local                  : " << DatosLibro[i].local << endl;
                                cout << "\t Valor Unitario         : " << DatosLibro[i].precio << endl;
                                cout << "\t Cantidad de libros     : " << Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros << endl;
                                cout << "\t Valor IGV              : " << ValorIGV * 100 << "%" << endl;
                                cout << "\t IGV                    : " << Clientes[CantidadClientes].DatosLibroCliente.IGV << endl;
                                cout << "\t Base Imponible         : " << Clientes[CantidadClientes].DatosLibroCliente.Subtotal << endl;
                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Delivery               : " << CostoDelivery << endl;
                                }

                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << endl;
                                    if (Hora > 0 && Hora <= 8)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[0].DatosTrabajador.Nombres << " " << DatosRepartidores[0].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  938712748" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 8 && Hora <= 16)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[1].DatosTrabajador.Nombres << " " << DatosRepartidores[1].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  902843093" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 16 && Hora <= 24)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[2].DatosTrabajador.Nombres << " " << DatosRepartidores[2].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  989371278" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                }
                                else
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\tBoleta de venta, valido para Sunat" << endl;
                                cout << "\tGracias por su preferencia..." << endl;
                                cout << "\t------------------------------" << endl;
                                break;
                            case 'B':
                                do
                                {
                                    cout << "\n\t Ingrese su numero de RUC (8 digitos sin digitar 10 al inicio y 4 al final) -> "; cin >> RUC;
                                    if (RUC.size() < 8 || RUC.size() > 8)
                                    {
                                        cout << "\n\033[31m Solo debe digitar 8 digitos sin contar 10 al inicio y 4 al final, intentelo de nuevo\033[0m" << endl;
                                    }
                                } while (RUC.size() < 8 || RUC.size() > 8);


                                cout << "\n\t------------------------------" << endl;
                                cout << "\tFACTURA DE VENTA ELECTRONICA \n" << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Fecha                  : " << Dia << "/" << Mes << "/" << Clientes[CantidadClientes].Anio << endl;
                                cout << "\t Hora                   : " << " (";
                                if (Hora < 10)
                                {
                                    cout << "0";
                                }
                                cout << Hora << ":";
                                if (Minuto < 10) {
                                    cout << "0";
                                }
                                cout << Minuto << ") " << endl;
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 0 && Hora <= 8))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[0].DatosTrabajador.Nombres << " " << DatosCajeros[0].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 8 && Hora <= 16))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[1].DatosTrabajador.Nombres << " " << DatosCajeros[1].DatosTrabajador.Apellido << endl;;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 16 && Hora <= 24))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[2].DatosTrabajador.Nombres << " " << DatosCajeros[2].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\t RUC                    : " << " 10" << RUC << "4 " << endl;
                                cout << "\t Razon Social           : " << " Libreria 'Digital Lecture' " << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Codigo de libro        : " << DatosLibro[i].codigo << endl;
                                cout << "\t Titulo de libro        : " << DatosLibro[i].titulo << endl;
                                cout << "\t Tipo   de libro        : " << DatosLibro[i].tipo << endl;
                                cout << "\t Local                  : " << DatosLibro[i].local << endl;
                                cout << "\t Valor Unitario         : " << DatosLibro[i].precio << endl;
                                cout << "\t Cantidad de libros     : " << Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros << endl;
                                cout << "\t Valor IGV              : " << ValorIGV * 100 << "%" << endl;
                                cout << "\t IGV                    : " << Clientes[CantidadClientes].DatosLibroCliente.IGV << endl;
                                cout << "\t Base Imponible         : " << Clientes[CantidadClientes].DatosLibroCliente.Subtotal << endl;
                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Delivery               : " << CostoDelivery << endl;
                                }

                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << endl;
                                    if (Hora > 0 && Hora <= 8)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[0].DatosTrabajador.Nombres << " " << DatosRepartidores[0].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  938712748" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 8 && Hora <= 16)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[1].DatosTrabajador.Nombres << " " << DatosRepartidores[1].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  902843093" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 16 && Hora <= 24)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[2].DatosTrabajador.Nombres << " " << DatosRepartidores[2].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  989371278" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                }
                                else
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\tFactura de venta, valido para Sunat" << endl;
                                cout << "\tGracias por su preferencia..." << endl;
                                cout << "\t------------------------------" << endl;
                                break;
                            case 'C':
                                cout << "\n\t------------------------------" << endl;
                                cout << "\tNOTA DE VENTA ELECTRONICA \n" << endl;
                                cout << "\t------------------------------" << endl;
                                cout << "\t Fecha                  : " << Dia << "/" << Mes << "/" << Clientes[CantidadClientes].Anio << endl;
                                cout << "\t Hora                   : " << " (";
                                if (Hora < 10)
                                {
                                    cout << "0";
                                }
                                cout << Hora << ":";
                                if (Minuto < 10) {
                                    cout << "0";
                                }
                                cout << Minuto << ") " << endl;
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 0 && Hora <= 8))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[0].DatosTrabajador.Nombres << " " << DatosCajeros[0].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 8 && Hora <= 16))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[1].DatosTrabajador.Nombres << " " << DatosCajeros[1].DatosTrabajador.Apellido << endl;;
                                    cout << "\t------------------------------" << endl;
                                }
                                if ((OpcionEnvio == 'R' || Clientes[CantidadClientes].Modalidad == 'A') && (Hora > 16 && Hora <= 24))
                                {
                                    cout << "\t------------------------------" << endl;
                                    cout << "\t Cajero                 : " << DatosCajeros[2].DatosTrabajador.Nombres << " " << DatosCajeros[2].DatosTrabajador.Apellido << endl;
                                    cout << "\t------------------------------" << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\t Codigo de libro        : " << DatosLibro[i].codigo << endl;
                                cout << "\t Titulo de libro        : " << DatosLibro[i].titulo << endl;
                                cout << "\t Tipo   de libro        : " << DatosLibro[i].tipo << endl;
                                cout << "\t Local                  : " << DatosLibro[i].local << endl;
                                cout << "\t Valor Unitario         : " << DatosLibro[i].precio << endl;
                                cout << "\t Cantidad de libros     : " << Clientes[CantidadClientes].DatosLibroCliente.CantidadLibros << endl;
                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Delivery               : " << CostoDelivery << endl;
                                }

                                if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal + CostoDelivery << endl;
                                    if (Hora > 0 && Hora <= 8)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[0].DatosTrabajador.Nombres << " " << DatosRepartidores[0].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  938712748" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 8 && Hora <= 16)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[1].DatosTrabajador.Nombres << " " << DatosRepartidores[1].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  902843093" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                    if (Hora > 16 && Hora <= 24)
                                    {
                                        cout << "\t------------------------------" << endl;
                                        cout << "\t Repartidor             : " << DatosRepartidores[2].DatosTrabajador.Nombres << " " << DatosRepartidores[2].DatosTrabajador.Apellido << endl;
                                        cout << "\t Para algun inconveniente o mencion adicional " << endl;
                                        cout << "\t que desee comentarle al repartidor llamar al" << endl;
                                        cout << "\t  989371278" << endl;
                                        cout << "\t------------------------------" << endl;
                                    }
                                }
                                else
                                {
                                    cout << "\t Total a Pagar          : " << Clientes[CantidadClientes].DatosLibroCliente.PrecioTotal << endl;
                                }
                                cout << "\t------------------------------" << endl;
                                cout << "\tNota de venta, no valido para Sunat" << endl;
                                cout << "\tGracias por su preferencia..." << endl;
                                cout << "\t------------------------------" << endl;
                                break;
                            default:
                                cout << "\n\033[31m Ingrese una opcion valida\033[0m" << endl;
                                break;
                            }
                        } while (Clientes[CantidadClientes].OpcionComprobante != 'A' && Clientes[CantidadClientes].OpcionComprobante != 'B' && Clientes[CantidadClientes].OpcionComprobante != 'C');



                        if (Clientes[CantidadClientes].Modalidad == 'A')
                        {
                            cout << "\n\033[32mPago realizado, gracias por su compra! :D \033[0m" << endl;
                        }
                        if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'D')
                        {
                            cout << "\n\033[32mVenta Exitosa! :D \033[0m" << endl;
                            cout << "\n\t El envio sera enviado a la siguiente direccion: " << endl;
                            cout << "\t\t Direccion: " << Clientes[CantidadClientes].DireccionCliente.Direcion << endl;
                            cout << "\t\t Departamento: " << Clientes[CantidadClientes].DireccionCliente.Departamento << endl;
                            cout << "\t\t Distrito: " << Clientes[CantidadClientes].DireccionCliente.Distrito << endl;
                            cout << "\t\t Provincia: " << Clientes[CantidadClientes].DireccionCliente.Provincia << endl;
                        }
                        else if (Clientes[CantidadClientes].Modalidad == 'B' && OpcionEnvio == 'R')
                        {
                            cout << "\n\033[32mVenta Exitosa! :D \033[0m" << endl;
                        }

                    }
                }
                break;
            default:
                cout << "Opcion " << Clientes[CantidadClientes].DatosLibroCliente.LocalLibro << " invalida" << endl;
                break;
            }


            break;
        default:
            cout << "Ingrese una categoria valida" << endl;
            break;
        }
    } while (Clientes[CantidadClientes].DatosLibroCliente.CategoriaLibro != 'C' && Clientes[CantidadClientes].DatosLibroCliente.CategoriaLibro != 'M');


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < CantidadClientes + 1; j++)
        {
            if (DatosVentaTotal[i].Annio == 2022 && Clientes[j].Anio == 2022)
            {
                DatosVentaTotal[i].CantidadLibrosTotal2022 += Clientes[j].DatosLibroCliente.CantidadLibros;
            }

        }

    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < CantidadClientes + 1; j++)
        {
            if (DatosVentaTotal[i].Annio == 2023 && Clientes[j].Anio == 2023)
            {
                DatosVentaTotal[i].CantidadLibrosTotal2023 += Clientes[j].DatosLibroCliente.CantidadLibros;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < CantidadClientes + 1; j++)
        {
            if (DatosVentaTotal[i].Annio == 2024 && Clientes[j].Anio == 2024)
            {
                DatosVentaTotal[i].CantidadLibrosTotal2024 += Clientes[j].DatosLibroCliente.CantidadLibros;
            }
        }
    }


    CantidadClientes++;

    ContinueFuction(Clientes, CantidadClientes, DatosLibro, DatosVentaTotal);

}


void ContinueFuction(Registro* Clientes, int& CantidadClientes, RegistroLibro* DatosLibro, VentaLibroTotal* DatosVentaTotal) {
    int OpcionContinue;


    do {
        cout << "\n\t Desea Continuar?" << endl;
        cout << "\t Opcion 1: Si (Otro Cliente) " << endl;
        cout << "\t Opcion 2: No (Cierra Programa)" << endl;
        cin >> OpcionContinue;

        switch (OpcionContinue) {
        case 1:
            system("cls");
            MenuRegistro(Clientes, CantidadClientes, DatosVentaTotal);

            break;
        case 2:
            cout << "\nAl final del dia ..." << endl;
            cout << "  ______________________________________________________________\n";
            cout << " /                                                              \\\n";
            cout << "|  Jefe Pacco: Jovenessss, hoy solicito los reportes . . .       |\n";
            cout << " \\______________________________________________________________/\n";
            cout << "       O      \n";
            cout << "      /|\\     \n";
            cout << "      / \\     \n";
            cout << " " << endl;
            cout << "Despues de un par de horas . . . " << endl;
            cout << "Presione cualquier tecla para continuar " << endl;
            getch();
            system("cls");
            ReporteClientesRegistrados(Clientes, CantidadClientes, DatosVentaTotal);
            getch();
            ReporteGanancias(DatosVentaTotal);
            getch();
            ReporteClientesSexo(CantidadClientes, Clientes);
            getch();
            ReporteClientesModalidad(CantidadClientes, Clientes);
            getch();
            ReporteClientesPorMedioPago(CantidadClientes, Clientes);
            getch();
            ReporteComprobantes(CantidadClientes, Clientes);
            getch();
            ReporteVentasAnio2024(CantidadClientes, Clientes);
            getch();
            system("cls");
            Menu2(); 
            break;

        default:
            cout << "\033[31m Ingrese una opcion valida\033[93m" << endl;
            break;
        }
    } while (OpcionContinue != 2);

}

void ReporteClientesRegistrados(Registro* Clientes, int& CantidadCliente, VentaLibroTotal* DatosVentaTotal) {

    cout << "\nLista de Clientes Registrados:\n";
    for (int i = 0; i < CantidadCliente; i++) {
        cout << "\tCliente " << i + 1 << ":\n";
        cout << "\tNombres: " << Clientes[i].DatosPersona.Nombres << endl;
        cout << "\tApellidos: " << Clientes[i].DatosPersona.Apellido << endl;
        cout << "\tDNI: " << Clientes[i].DatosPersona.DNI << endl;
        cout << "\tSexo: " << Clientes[i].DatosPersona.Sexo << endl;
        cout << "\tCorreo: " << Clientes[i].DatosPersona.Correo << endl;
        cout << "\n ===================================================" << endl;
    }


}
void ReporteGanancias(VentaLibroTotal* DatosVentaTotal) {
    float GananciaTotal2022 = 0, GananciaTotal2023 = 0, GananciaTotal2024 = 0;
    float GananciaUltimosAnios = 0, Porcentaje2022 = 0, Porcentaje2023 = 0, Porcentaje2024 = 0;

    GananciaTotal2022 = DatosVentaTotal[0].CantidadLibrosTotal2022 * 2.6;
    GananciaTotal2023 = DatosVentaTotal[1].CantidadLibrosTotal2023 * 2.6;
    GananciaTotal2024 = DatosVentaTotal[2].CantidadLibrosTotal2024 * 2.6;
    GananciaUltimosAnios = GananciaTotal2022 + GananciaTotal2023 + GananciaTotal2024;

    Porcentaje2022 = (GananciaTotal2022 / GananciaUltimosAnios) * 100;
    Porcentaje2023 = (GananciaTotal2023 / GananciaUltimosAnios) * 100;
    Porcentaje2024 = (GananciaTotal2024 / GananciaUltimosAnios) * 100;
    //cada simbolo representa 10%
    cout << "\n\t----------------------------------------" << endl;
    cout << "\tSistema de ganancias de la empresa" << endl;
    cout << "\t----------------------------------------" << endl;
    cout << "\t Nota: Cada bloque equivale al 10% " << endl;
    cout << "\nGanancias 2022: " << GananciaTotal2022 << endl;
    cout << " |";
    for (int i = 0; i < Porcentaje2022 / 10; i++)
    {
        cout << "[ ]";
    }
    cout << " (" << Porcentaje2022 << ") % " << endl;

    cout << "\nGanancias 2023: " << GananciaTotal2023 << endl;
    cout << " |";
    for (int i = 0; i < Porcentaje2023 / 10; i++)
    {
        cout << "[ ]";
    }
    cout << " (" << Porcentaje2023 << ") % " << endl;
    cout << "\nGanancias 2024: " << GananciaTotal2024 << endl;
    cout << " |";
    for (int i = 0; i < Porcentaje2024 / 10; i++)
    {
        cout << "[ ]";
    }
    cout << " (" << Porcentaje2024 << ") % " << endl;


}

void ReporteClientesSexo(int& CantidadClientes, Registro* Clientes) {
    //ADICIONAL 1
    float PorcentajeFemenino = 0, PorcentajeMasculino = 0;
    int CantidadFemenino = 0, CantidadMasculino = 0;

    for (int i = 0; i < CantidadClientes; i++)
    {
        if (Clientes[i].DatosPersona.Sexo == 'F')
        {
            CantidadFemenino++;
        }
        if (Clientes[i].DatosPersona.Sexo == 'M')
        {
            CantidadMasculino++;
        }
    }


    PorcentajeFemenino = (CantidadFemenino * 1.0 / (CantidadClientes)) * 100;
    PorcentajeMasculino = (CantidadMasculino * 1.0 / (CantidadClientes)) * 100;
    cout << "\n\t----------------------------------------" << endl;
    cout << "\tReporte de clientes segun el sexo     " << endl;
    cout << "\t----------------------------------------" << endl;
    cout << "\n Clientes de sexo femenino: " << CantidadFemenino << endl;
    cout << " |";
    for (int i = 0; i < PorcentajeFemenino / 10; i++)
    {
        cout << "[ ]";
    }
    cout << " (" << PorcentajeFemenino << ") % " << endl;
    cout << "\n Clientes de sexo masculino: " << CantidadMasculino << endl;
    cout << " |";
    for (int i = 0; i < PorcentajeMasculino / 10; i++)
    {
        cout << "[ ]";
    }
    cout << " (" << PorcentajeMasculino << ") % " << endl;

}

void ReporteClientesModalidad(int& CantidadClientes, Registro* Clientes)
{
    float PorcentajePrescencial = 0, PorcentajeWhatsapp = 0;
    int CantidadPrescencial = 0, CantidadWhatsapp = 0;
    for (int i = 0; i < CantidadClientes; i++)
    {
        if (Clientes[i].Modalidad == 'A')
        {
            CantidadPrescencial++;
        }
        if (Clientes[i].Modalidad == 'B')
        {
            CantidadWhatsapp++;
        }
    }
    PorcentajePrescencial = (CantidadPrescencial * 1.0 / (CantidadClientes)) * 100;
    PorcentajeWhatsapp = (CantidadWhatsapp * 1.0 / (CantidadClientes)) * 100;

    cout << "\n\t----------------------------------------" << endl;
    cout << "\tReporte de clientes segun la modalidad    " << endl;
    cout << "\t----------------------------------------" << endl;
    cout << "\n Clientes que eligieron la modalidad presencial: " << CantidadPrescencial << endl;
    cout << " |";
    for (int i = 0; i < PorcentajePrescencial / 10; i++)
    {
        cout << "[ ]";
    }
    cout << " (" << PorcentajePrescencial << ") % " << endl;
    cout << "\n Clientes que eligieron la modadlidad Whatsapp: " << CantidadWhatsapp << endl;
    cout << " |";
    for (int i = 0; i < PorcentajeWhatsapp / 10; i++)
    {
        cout << "[ ]";
    }
    cout << " (" << PorcentajeWhatsapp << ") % " << endl;


}

void ReporteClientesPorMedioPago(int& CantidadClientes, Registro* Clientes) {
    //ADICIONAL 2
    int ContadorCredito = 0, ContadorEfectivo = 0, ContadorYapePlin = 0;
    float PorcentajeCredito = 0, PorcentajeEfectivo = 0, PorcentajeYapePlin = 0;
    for (int i = 0; i < CantidadClientes; i++)
    {
        if (Clientes[i].MedioPago == 'A')
        {
            ContadorCredito++;
        }
        if (Clientes[i].MedioPago == 'B')
        {
            ContadorYapePlin++;
        }
        if (Clientes[i].MedioPago == 'C')
        {
            ContadorEfectivo++;
        }
    }
    PorcentajeCredito = (ContadorCredito * 1.0 / (CantidadClientes)) * 100;
    PorcentajeYapePlin = (ContadorYapePlin * 1.0 / (CantidadClientes)) * 100;
    PorcentajeEfectivo = (ContadorEfectivo * 1.0 / (CantidadClientes)) * 100;
    cout << "\n\t-----------------------------------------" << endl;
    cout << "\tReporte de clientes segun el medio de pago " << endl;
    cout << "\t-----------------------------------------" << endl;
    cout << "\n Clientes que eligieron como medio de pago credito: " << ContadorCredito << endl;
    cout << " |";
    for (int i = 0; i < PorcentajeCredito / 10; i++)
    {
        cout << "[ ]";
    }
    cout << " (" << PorcentajeCredito << ") % " << endl;
    cout << "\n Clientes que eligieron como medio de pago Yape/Plin: " << ContadorYapePlin << endl;
    cout << " |";
    for (int i = 0; i < PorcentajeYapePlin / 10; i++)
    {
        cout << "[ ]";
    }
    cout << " (" << PorcentajeYapePlin << ") % " << endl;
    cout << "\n Clientes que eligieron como medio de pago Efectivo: " << ContadorEfectivo << endl;
    cout << " |";
    for (int i = 0; i < PorcentajeEfectivo / 10; i++)
    {
        cout << "[ ]";
    }

    cout << " (" << PorcentajeEfectivo << ") % " << endl;

}

void ReporteComprobantes(int& CantidadClientes, Registro* Clientes) {
    //ADICIONAL 3
    int ContadorBoleta = 0, ContadorFactura = 0, ContadorNotadeVenta = 0;
    float PorcentajeBoleta = 0, PorcentajeFactura = 0, PorcentajeNotadeVenta = 0;
    for (int i = 0; i < CantidadClientes; i++)
    {
        if (Clientes[i].MedioPago == 'A')
        {
            ContadorBoleta++;
        }
        if (Clientes[i].MedioPago == 'B')
        {
            ContadorFactura++;
        }
        if (Clientes[i].MedioPago == 'C')
        {
            ContadorNotadeVenta++;
        }
    }
    PorcentajeBoleta = (ContadorBoleta * 1.0 / (CantidadClientes)) * 100;
    PorcentajeFactura = (ContadorFactura * 1.0 / (CantidadClientes)) * 100;
    PorcentajeNotadeVenta = (ContadorNotadeVenta * 1.0 / (CantidadClientes)) * 100;
    cout << "\n\t-----------------------------------------" << endl;
    cout << "\tReporte de cliente segun tipo de comprobante " << endl;
    cout << "\t-----------------------------------------" << endl;

    cout << "\n Clientes que eligieron como tipo de comprobante boleta : " << ContadorBoleta << endl;
    cout << " |";
    for (int i = 0; i < PorcentajeBoleta / 10; i++)
    {
        cout << "[ ]";
    }
    cout << " (" << PorcentajeBoleta << ") % " << endl;
    cout << "\n Clientes que eligieron como tipo de comprobante factura: " << ContadorFactura << endl;
    cout << " |";
    for (int i = 0; i < PorcentajeFactura / 10; i++)
    {
        cout << "[ ]";
    }
    cout << " (" << PorcentajeFactura << ") % " << endl;
    cout << "\n Clientes que eligieron como tipo de comprobante nota de venta: " << ContadorNotadeVenta << endl;
    cout << " |";
    for (int i = 0; i < PorcentajeNotadeVenta / 10; i++)
    {
        cout << "[ ]";
    }

    cout << " (" << PorcentajeNotadeVenta << ") % " << endl;

}

void ReporteVentasAnio2024(int& CantidadClientes, Registro* Clientes) {
    int ContadorSpiderman = 0, ContadorBatman = 0, ContadorHulk = 0, ContadorNaruto = 0, ContadorBleach = 0, ContadorOnePiece = 0;
    float PorcentajeSpiderman = 0, PorcentajeBatman = 0, PorcentajeHulk = 0, PorcentajeNaruto = 0, PorcentajeBleach = 0, PorcentajeOnePiece = 0;
    cout << "\n\t--------------------------------------------" << endl;
    cout << "\tReporte de numero de ventas por tipo de libro" << endl;
    cout << "\t----------------------------------------------" << endl;

    for (int i = 0; i < CantidadClientes; i++)
    {
        if (Clientes[i].Anio == 2024 && Clientes[i].DatosLibroCliente.CodigoLibroElegido == "C1001") {
            ContadorSpiderman++;
        }
        if (Clientes[i].Anio == 2024 && Clientes[i].DatosLibroCliente.CodigoLibroElegido == "C1002") {
            ContadorBatman++;
        }
        if (Clientes[i].Anio == 2024 && Clientes[i].DatosLibroCliente.CodigoLibroElegido == "C1003") {
            ContadorHulk++;
        }
        if (Clientes[i].Anio == 2024 && Clientes[i].DatosLibroCliente.CodigoLibroElegido == "M1001") {
            ContadorBleach++;
        }
        if (Clientes[i].Anio == 2024 && Clientes[i].DatosLibroCliente.CodigoLibroElegido == "M1002") {
            ContadorNaruto++;
        }
        if (Clientes[i].Anio == 2024 && Clientes[i].DatosLibroCliente.CodigoLibroElegido == "M1003") {
            ContadorOnePiece++;
        }
    }

    PorcentajeSpiderman = (ContadorSpiderman * 1.0 / CantidadClientes) * 100;
    PorcentajeBatman = (ContadorBatman * 1.0 / CantidadClientes) * 100;
    PorcentajeHulk = (ContadorHulk * 1.0 / CantidadClientes) * 100;
    PorcentajeBleach = (ContadorBleach * 1.0 / CantidadClientes) * 100;
    PorcentajeNaruto = (ContadorNaruto * 1.0 / CantidadClientes) * 100;
    PorcentajeOnePiece = (ContadorOnePiece * 1.0 / CantidadClientes) * 100;

    cout << "\n Cantidad de clientes en el 2024 que eligieron Spiderman : " << ContadorSpiderman << endl;

    cout << " |";
    for (int i = 0; i < PorcentajeSpiderman / 10; i++)
    {
        cout << "[ ]";
    }
    cout << " (" << PorcentajeSpiderman << ") % " << endl;
    cout << "\n Cantidad de clientes en el 2024 que eligieron Batman : " << ContadorBatman << endl;
    cout << " |";
    for (int i = 0; i < PorcentajeBatman / 10; i++)
    {
        cout << "[ ]";
    }
    cout << " (" << PorcentajeBatman << ") % " << endl;
    cout << "\n Cantidad de clientes en el 2024 que eligieron Hulk : " << ContadorHulk << endl;
    cout << " |";
    for (int i = 0; i < PorcentajeHulk / 10; i++)
    {
        cout << "[ ]";
    }
    cout << " (" << PorcentajeHulk << ") % " << endl;
    cout << "\n Cantidad de clientes en el 2024 que eligieron Bleach : " << ContadorBleach << endl;
    cout << " |";
    for (int i = 0; i < PorcentajeBleach / 10; i++)
    {
        cout << "[ ]";
    }
    cout << " (" << PorcentajeBleach << ") % " << endl;
    cout << "\n Cantidad de clientes en el 2024 que eligieron Naruto : " << ContadorNaruto << endl;
    cout << " |";
    for (int i = 0; i < PorcentajeNaruto / 10; i++)
    {
        cout << "[ ]";
    }
    cout << " (" << PorcentajeNaruto << ") % " << endl;
    cout << "\n Cantidad de clientes en el 2024 que eligieron One Piece : " << ContadorOnePiece << endl;
    cout << " |";
    for (int i = 0; i < PorcentajeOnePiece / 10; i++)
    {
        cout << "[ ]";
    }
    cout << " (" << PorcentajeOnePiece << ") % " << endl;

}

void Menu2() {
    string CodigoEmpresa;
    int CantidadLibrosFinal = 0;
    float PrecioFinal = 0;
    float IGVFinal = 0;
    float SubtotalFinal = 0;
    // ARREGLO ESTATICO
    PersonalEmpresa DatosTrabajador[3] = {
        {"72892885","Matheo Sebastian","Zavala Silva",'M',"matheozavala818@gmail.com"," Especialista de inventario "," Luna$0608"},
        {"10619116","Paula Virgil","Cosavalente Segovia",'F',"PaulaValiente22@gmail.com"," Jefa de control de stocks "," Cherry_Pau"},
        {"10645060","Sambito Sambrosio","Medrano Santiago",'M',"Sam_Sam_24@gmail.com"," Especialista de inventario "," Sambitx_105"},
    };
    PersonalEmpresa DatosCajeros[3] = {
       {"93476213","Alex Aaron","Hernandez Soliz",'M',"alexx_AA18@gmail.com"," Cajero "," DobleAAron18"},
       {"29870345","Ruth Samira","Torres Wong",'F',"RuthTW_306@gmail.com"," Cajera "," RuthConH&102"},
       {"09128709","Camilo Armando","Lopez Estrada",'M',"CamiloLoEs_24@gmail.com"," Cajero "," CALE_2202"},
    };
    PersonalEmpresa DatosRepartidores[3] = {
        {"98712891","Alondra Maddian","Arriaran Gomez",'F',"aloM_D20@gmail.com"," Repartidora "," Canelita!1416"},
        {"07389472","Paola Mariana","Sutta Pariona",'F',"PaxMar_PM@gmail.com"," Repartidora "," PMSP&AAAA"},
        {"64891263","Ramiro Ernesto","Lopez Estrada",'M',"Coppo14RAERN_@gmail.com"," Repartidor "," R123_E987"},
    };
    cout << "\n\t====================================================================" << endl;
    cout << "\n\t\033[31m ESTA PAGINA ES SOLO PARA PERSONAL AUTORIZADO \033[0m" << endl;
    cout << "\n\t====================================================================" << endl;

    do
    {
        cout << "\n\t\tIngrese el codigo de la empresa -> "; cin >> CodigoEmpresa;
        if (CodigoEmpresa != "1234")
        {
            cout << "\033[31m Empresa con el codigo \033[0m" << CodigoEmpresa << "\033[31m no encontrada \033[0m" << endl; //EL CODIGO DE LA EMPRESA ES 1234 SOLO PARA LA VALIDACION, FUERA DE ELLO, SE PUEDE ELEGIR CUALQUIER CODIGO
        }                                                                                                                  //QUE LA EMPRESA DECIDA
    } while (CodigoEmpresa != "1234");
    do
    {
        cout << "\n\t\tIngrese su clave de trabajador -> "; cin >> DatosTrabajador->Contrasenia;
        if (DatosTrabajador->Contrasenia != "Luna$0608" && DatosTrabajador->Contrasenia != "Cherry_Pau" && DatosTrabajador->Contrasenia != "Sambitx_105")
        {
            cout << "\033[31m No existe ningun trabajador con dicha contrasenia, intentelo denuevo \033[0m" << endl;
        }
    } while (DatosTrabajador->Contrasenia != "Luna$0608" && DatosTrabajador->Contrasenia != "Cherry_Pau" && DatosTrabajador->Contrasenia != "Sambitx_105");
    if (DatosTrabajador->Contrasenia == "Luna$0608")
    {
        cout << "\n\033[32m Bienvenido " << DatosTrabajador[0].DatosTrabajador.Nombres << "  \033[0m" << endl;
    }
    if (DatosTrabajador->Contrasenia == "Cherry_Pau")
    {
        cout << "\n\033[32m Bienvenida " << DatosTrabajador[1].DatosTrabajador.Nombres << "  \033[0m" << endl;
    }
    if (DatosTrabajador->Contrasenia == "Sambitx_105")
    {
        cout << "\n\033[32m Bienvenido " << DatosTrabajador[2].DatosTrabajador.Nombres << "  \033[0m" << endl;
    }

    cout << "\t\033[32m " << endl;
    cout << "\t Accediendo a la web del proveedor . . ." << endl;
    cout << "\t |-------------------------------------|" << endl;
    cout << "\t |             CATEGORIAS              |" << endl;
    cout << "\t |-------------------------------------|" << endl;
    cout << "\t |             Comics  (C)             |" << endl;
    cout << "\t |             Manga   (M)             |" << endl;
    cout << "\t |-------------------------------------|\n\033[0m" << endl;
    ProcesoCompra(DatosTrabajador,DatosCajeros,DatosRepartidores, CantidadLibrosFinal, PrecioFinal, IGVFinal, SubtotalFinal);
}

void ProcesoCompra(PersonalEmpresa* DatosTrabajador,PersonalEmpresa*DatosCajeros,PersonalEmpresa*DatosRepartidores, int& CantidadLibrosFinal, float& PrecioFinal, float& IGVFinal, float& SubtotalFinal) {
    char Categoria2;
    string CodigoLibroElegido2;
    int CantidadLibrosCompra = 0; //VARIABLE ACUMULATIVA YA QUE SE SUMARA PROGRESIVAMENTE
    float ValorIGV = 0.18;
    float PrecioTotal = 0, IGV = 0, Subtotal = 0;

    RegistroLibro DatosLibro2[6] = {
      { "P101", "Spider-Man", 22.2, "San Miguel" "Comic" },
      { "P102", "Batman", 19.9, "Miraflores", "Comic" },
      { "P103", "Hulk", 17.4, "San Miguel", "Comic" },
      { "P104", "Bleach", 23.3, "San Miguel", "Manga" },
      { "P105", "Naruto", 20.9, "Miraflores", "Manga" },
      { "P106", "OnePiece", 18.2, "Miraflores", "Manga" }
    };
    do
    {
        cout << "\tOpcion (C: Comic, M: Manga) -> "; cin >> Categoria2;
        Categoria2 = toupper(Categoria2);
        if (Categoria2 != 'C' && Categoria2 != 'M')
        {
            cout << "\033[31m Opcion de categoria invalida \033[0m" << endl;
        }
    } while (Categoria2 != 'C' && Categoria2 != 'M');



    switch (Categoria2)
    {
    case 'C':  cout << "\tCategoria comic disponible " << endl;
        cout << setw(15) << DatosLibro2[0].codigo
            << setw(25) << DatosLibro2[0].titulo
            << setw(15) << DatosLibro2[0].precio << " soles " << endl;
        for (int i = 0; i < 6; i++)
        {

            if (DatosLibro2[i].tipo == "Comic")
            {


                cout << setw(15) << DatosLibro2[i].codigo
                    << setw(25) << DatosLibro2[i].titulo
                    << setw(15) << DatosLibro2[i].precio << " soles " << endl;

            }
        }
        do
        {
            cout << "\tElige el codigo del libro deseado: "; cin >> CodigoLibroElegido2;
            if (CodigoLibroElegido2 != "P101" && CodigoLibroElegido2 != "P102" && CodigoLibroElegido2 != "P103")
            {
                cout << "\033[31m Opcion de libro invalida \033[0m" << endl;
            }
        } while (CodigoLibroElegido2 != "P101" && CodigoLibroElegido2 != "P102" && CodigoLibroElegido2 != "P103");
        do
        {
            cout << "\tIngrese cantidad de libros deseados -> "; cin >> CantidadLibrosCompra;
            if (CantidadLibrosCompra <= 0)
            {
                cout << "\033[31m Cantidad Ingresada no valida \033[0m" << endl;
            }
        } while (CantidadLibrosCompra <= 0);

        if (CodigoLibroElegido2 == "P101")
        {
            PrecioTotal = DatosLibro2[0].precio * CantidadLibrosCompra;
        }
        if (CodigoLibroElegido2 == "P102")
        {
            PrecioTotal = DatosLibro2[1].precio * CantidadLibrosCompra;
        }
        if (CodigoLibroElegido2 == "P103")
        {
            PrecioTotal = DatosLibro2[2].precio * CantidadLibrosCompra;
        }

        break;
    case 'M':
        cout << "\tCategoria manga disponible " << endl;
        for (int i = 0; i < 6; i++)
        {
            if (DatosLibro2[i].tipo == "Manga")
            {

                cout << setw(15) << DatosLibro2[i].codigo
                    << setw(25) << DatosLibro2[i].titulo
                    << setw(15) << DatosLibro2[i].precio << " soles " << endl;

            }
        }
        do
        {
            cout << "\tElige el codigo del libro deseado: "; cin >> CodigoLibroElegido2;
            if (CodigoLibroElegido2 != "P104" && CodigoLibroElegido2 != "P105" && CodigoLibroElegido2 != "P106")
            {
                cout << "\033[31m Opcion de libro invalida \033[0m" << endl;
            }
        } while (CodigoLibroElegido2 != "P104" && CodigoLibroElegido2 != "P105" && CodigoLibroElegido2 != "P106");
        do
        {
            cout << "\tIngrese cantidad de libros deseados -> "; cin >> CantidadLibrosCompra;
            if (CantidadLibrosCompra <= 0)
            {
                cout << "\033[31m Cantidad Ingresada no valida \033[0m" << endl;
            }
        } while (CantidadLibrosCompra <= 0);
        if (CodigoLibroElegido2 == "P104")
        {
            PrecioTotal = DatosLibro2[3].precio * CantidadLibrosCompra;
        }
        if (CodigoLibroElegido2 == "P105")
        {
            PrecioTotal = DatosLibro2[4].precio * CantidadLibrosCompra;
        }
        if (CodigoLibroElegido2 == "P106")
        {
            PrecioTotal = DatosLibro2[5].precio * CantidadLibrosCompra;
        }
        break;
    }

    IGV = PrecioTotal * ValorIGV;
    Subtotal = PrecioTotal - IGV;
    CantidadLibrosFinal += CantidadLibrosCompra;
    PrecioFinal += PrecioTotal;
    IGVFinal += IGV;
    SubtotalFinal += Subtotal;


    ContinueFunction2(DatosTrabajador,DatosCajeros,DatosRepartidores, CantidadLibrosFinal, PrecioFinal, IGVFinal, SubtotalFinal);
}

void ContinueFunction2(PersonalEmpresa* DatosTrabajador, PersonalEmpresa*DatosCajeros,PersonalEmpresa*DatosRepartidores,int CantidadLibrosFinal, float PrecioFinal, float IGVFinal, float SubtotalFinal) {
    char OpcionContinue2;
    float ValorIGV = 0.18;

    cout << "\n\t Desea Continuar?   :" << endl;
    cout << "\tOpcion 1 = Si  (Comprar mas libros) " << endl;
    cout << "\tOpcion 2 = No  (Imprimir Boleta) \n" << endl;

    cout << "\t\t Opcion -> "; cin >> OpcionContinue2;

    switch (OpcionContinue2) {
    case '1':ProcesoCompra(DatosTrabajador,DatosCajeros,DatosRepartidores, CantidadLibrosFinal, PrecioFinal, IGVFinal, SubtotalFinal);
        break;
    case '2':
        cout << "\t.-----------------------------------." << endl;
        cout << "\n\t\tBoleta Electronica\n" << endl;
        cout << "\t.-----------------------------------." << endl;
        FuncionFecha();
        cout << "\t.-----------------------------------." << endl;
        cout << "\t DATOS DEL COMPRADOR " << endl;
        cout << "\t.-----------------------------------." << endl;
        cout << "\t Empresa    : Digital Lecture" << endl;
        cout << "\t Nombres    : ";
        if (DatosTrabajador->Contrasenia == "Luna$0608")
        {
            cout << DatosTrabajador[0].DatosTrabajador.Nombres << endl;
        }
        if (DatosTrabajador->Contrasenia == "Cherry_Pau")
        {
            cout << DatosTrabajador[1].DatosTrabajador.Nombres << endl;
        }
        if (DatosTrabajador->Contrasenia == "Sambitx_105")
        {
            cout << DatosTrabajador[2].DatosTrabajador.Nombres << endl;
        }
        cout << "\t Apellidos  : ";
        if (DatosTrabajador->Contrasenia == "Luna$0608")
        {
            cout << DatosTrabajador[0].DatosTrabajador.Apellido << endl;
        }
        if (DatosTrabajador->Contrasenia == "Cherry_Pau")
        {
            cout << DatosTrabajador[1].DatosTrabajador.Apellido << endl;
        }
        if (DatosTrabajador->Contrasenia == "Sambitx_105")
        {
            cout << DatosTrabajador[2].DatosTrabajador.Apellido << endl;
        }
        cout << "\t DNI        : ";
        if (DatosTrabajador->Contrasenia == "Luna$0608")
        {
            cout << DatosTrabajador[0].DatosTrabajador.DNI << endl;
        }
        if (DatosTrabajador->Contrasenia == "Cherry_Pau")
        {
            cout << DatosTrabajador[1].DatosTrabajador.DNI << endl;
        }
        if (DatosTrabajador->Contrasenia == "Sambitx_105")
        {
            cout << DatosTrabajador[2].DatosTrabajador.DNI << endl;
        }
        cout << "\t Sexo       : ";
        if (DatosTrabajador->Contrasenia == "Luna$0608")
        {
            cout << DatosTrabajador[0].DatosTrabajador.Sexo << endl;
        }
        if (DatosTrabajador->Contrasenia == "Cherry_Pau")
        {
            cout << DatosTrabajador[1].DatosTrabajador.Sexo << endl;
        }
        if (DatosTrabajador->Contrasenia == "Sambitx_105")
        {
            cout << DatosTrabajador[2].DatosTrabajador.Sexo << endl;
        }
        cout << "\t Cargo      : ";
        if (DatosTrabajador->Contrasenia == "Luna$0608")
        {
            cout << DatosTrabajador[0].Rol << endl;
        }
        if (DatosTrabajador->Contrasenia == "Cherry_Pau")
        {
            cout << DatosTrabajador[1].Rol << endl;
        }
        if (DatosTrabajador->Contrasenia == "Sambitx_105")
        {
            cout << DatosTrabajador[2].Rol << endl;
        }
        cout << "\t.-----------------------------------." << endl;
        cout << "\t Cantidad de libros : " << CantidadLibrosFinal << endl;
        cout << "\t Valor IGV          : " << ValorIGV * 100 << "%" << endl;
        cout << "\t IGV                : " << IGVFinal << endl;
        cout << "\t Subtotal           : " << SubtotalFinal << endl;
        cout << "\t Total a pagar      : " << PrecioFinal << endl;
        cout << "\t.-----------------------------------." << endl;
        cout << "\t Para cualquier consulta o reclamo " << endl;
        cout << "\t contactar al siguiente correo: " << endl;
        if (DatosTrabajador->Contrasenia == "Luna$0608")
        {
            cout << "\t" << DatosTrabajador[0].DatosTrabajador.Correo << endl;
            cout << "\t.-----------------------------------." << endl;
            cout << "\t En todo caso requiera ayuda de un " << endl;
            cout << "\t superior contactar al sgte. correo: " << endl;
            cout << "\t.-----------------------------------." << endl;
            cout << "\t" << DatosTrabajador[1].DatosTrabajador.Correo << endl;
            cout << "\t.-----------------------------------." << endl;
        }
        if (DatosTrabajador->Contrasenia == "Cherry_Pau")
        {
            cout << "\t" << DatosTrabajador[1].DatosTrabajador.Correo << endl;
            cout << "\t.-----------------------------------." << endl;
        }
        if (DatosTrabajador->Contrasenia == "Sambitx_105")
        {
            cout << "\t" << DatosTrabajador[2].DatosTrabajador.Correo << endl;
            cout << "\t.-----------------------------------." << endl;
            cout << "\t En todo caso requiera ayuda de un " << endl;
            cout << "\t superior contactar al sgte. correo: " << endl;
            cout << "\t.-----------------------------------." << endl;
            cout << "\t" << DatosTrabajador[1].DatosTrabajador.Correo << endl;
            cout << "\t.-----------------------------------." << endl;
        }

        getch();
        system("cls");
        cout << "\t.-----------------------------------." << endl;
        cout << "\t Para saber mas informacion sobre nuestro staff" << endl;
        cout << "\t pulse  'I' caso contrario pulse 'S' " << endl;
        cout << "\t.-----------------------------------." << endl;
        char OpcionInfo;
        do
        {
            cout << "\t\t Opcion -> "; cin >> OpcionInfo;
            OpcionInfo = toupper(OpcionInfo);
            switch (OpcionInfo)
            {
            case 'I':
                cout << "\n\t ======================================================================================================" << endl;
                cout << "\t\t\t\t+++++++++++Informacion de nuestro personal+++++++++++" << endl;
                cout << "\t ======================================================================================================" << endl;
                cout << endl;
                cout << left << setw(25) << "\tNombres" << setw(25) << "Apellidos" << setw(35) << "Cargo" << setw(30) << "Correo" << endl;
                cout << "\t" << setw(25) << DatosTrabajador[0].DatosTrabajador.Nombres << setw(25) << DatosTrabajador[0].DatosTrabajador.Apellido << setw(35) << DatosTrabajador[0].Rol << setw(30) << DatosTrabajador[0].DatosTrabajador.Correo << endl;
                cout << "\t" << setw(25) << DatosTrabajador[1].DatosTrabajador.Nombres << setw(25) << DatosTrabajador[1].DatosTrabajador.Apellido << setw(35) << DatosTrabajador[1].Rol << setw(30) << DatosTrabajador[1].DatosTrabajador.Correo << endl;
                cout << "\t" << setw(25) << DatosTrabajador[2].DatosTrabajador.Nombres << setw(25) << DatosTrabajador[2].DatosTrabajador.Apellido << setw(35) << DatosTrabajador[2].Rol << setw(30) << DatosTrabajador[2].DatosTrabajador.Correo << endl;
                cout << "\t" << setw(25) << DatosCajeros[0].DatosTrabajador.Nombres << setw(25) << DatosCajeros[0].DatosTrabajador.Apellido << setw(35) << DatosCajeros[0].Rol << setw(30) << DatosCajeros[0].DatosTrabajador.Correo << endl;
                cout << "\t" << setw(25) << DatosCajeros[1].DatosTrabajador.Nombres << setw(25) << DatosCajeros[1].DatosTrabajador.Apellido << setw(35) << DatosCajeros[1].Rol << setw(30) << DatosCajeros[1].DatosTrabajador.Correo << endl;
                cout << "\t" << setw(25) << DatosCajeros[2].DatosTrabajador.Nombres << setw(25) << DatosCajeros[2].DatosTrabajador.Apellido << setw(35) << DatosCajeros[2].Rol << setw(30) << DatosCajeros[2].DatosTrabajador.Correo << endl;
                cout << "\t" << setw(25) << DatosRepartidores[0].DatosTrabajador.Nombres << setw(25) << DatosRepartidores[0].DatosTrabajador.Apellido << setw(35) << DatosRepartidores[0].Rol << setw(30) << DatosRepartidores[0].DatosTrabajador.Correo << endl;
                cout << "\t" << setw(25) << DatosRepartidores[1].DatosTrabajador.Nombres << setw(25) << DatosRepartidores[1].DatosTrabajador.Apellido << setw(35) << DatosRepartidores[1].Rol << setw(30) << DatosRepartidores[1].DatosTrabajador.Correo << endl;
                cout << "\t" << setw(25) << DatosRepartidores[2].DatosTrabajador.Nombres << setw(25) << DatosRepartidores[2].DatosTrabajador.Apellido << setw(35) << DatosRepartidores[2].Rol << setw(30) << DatosRepartidores[2].DatosTrabajador.Correo << endl;
                cout << "\t ======================================================================================================" << endl;
            case 'S':
                exit(0);
                break;

            default:cout << "\033[31m Ingrese una opcion valida\033[0m" << endl;
                break;
            }

        } while (OpcionInfo != 'I' && OpcionInfo != 'S');



        break;
    default:
        cout << "\033[31m Ingrese una opcion valida\033[32m" << endl;
        break;
    }
}
void FuncionFecha()
{
    auto Actual = chrono::system_clock::now();
    auto ActualEpoch = chrono::system_clock::to_time_t(Actual);
    tm* TiempoLocal = localtime(&ActualEpoch);
    cout << "\t\tFecha de Emision ("
        << TiempoLocal->tm_year + 1900 << '/'
        << TiempoLocal->tm_mon << '/'
        << TiempoLocal->tm_mday << ")" << endl;
}










