#include <iostream> //biblioteca est?ndar (STL) del lenguaje de programaci?n C++

#include "Textable.h"

#include "Cars_Storage.h"

#include "Transac_Log.h"

#include "Funciones.h"

#include<string>

#include<iomanip>

#include<conio.h>

#include<vector> //importamos libreria de vectores

#include <cmath>

#include <ctime>

#include <stdlib.h>//funcion para usar new y delete

#include<algorithm>//para poder ordenar arregos con sort y utras funciones necesarias

#define PI 3.14159265

#include <locale.h>

#include <windows.h>

#include <sstream>

using namespace std;

int main(int argc, char ** argv) {

  time_t tiempo = time(NULL); //variables donde guardo el valor de la funcion time. 
  struct tm * tlocal = localtime( & tiempo);

  char fech[11];
  strftime(fech, 11, "%d/%m/%Y", tlocal);
  string fecha(fech);

  setlocale(LC_ALL, "spanish.UTF-8"); //para permitir tildes o letra como ?
  SetConsoleCP(1252); // Cambiar STDIN -  Para m?quinas Windows
  SetConsoleOutputCP(1252); // Cambiar STDOUT - Para m?quinas Windows	

  //Instanciamos las 3 clases
  Cars_Storage Cl_C;
  Transac_Log Cl_T;
  Funciones Cl_Fx;
  Cars_Storage * pCl_C = new Cars_Storage;
  string line;

  char resp = '\0'; //unicamente permite 1 caracter
  int opcion;
  int iT;
  int iE;
  char confirmacion;
  int idReingreso;
  string _idReingreso;
  bool valCampo = true; //se inicializa en true para que el ciclo validador determine cuando salir
  bool valCampo2 = true;
  string validarIntconfuncion;
  //int contador=0;
  //datos para distancia
  int iddestino;
  string id_destino;
  int idorigen;
  string id_origen;
  double latOrigen;
  double longOrigen;
  double latDestino;
  double longDestino;
  double distancia;
  int idCar = -1;
  int mes = -1;
  int s_mes = -1;

  double costoViaje;
  double IVA;
  double costoLinea;
  double totalViaje;
  string t_f;
  string origen;
  string destino;

  vector < string > Meses = {
    "Enero",
    "Febrero",
    "Marzo",
    "Abril",
    "Mayo",
    "Junio",
    "Julio",
    "Agosto",
    "Septiembre",
    "Octubre",
    "Noviembre",
    "Diciembre"
  };
  string sub_mV;
  int s_mesV;
  vector < int > numMeses; //guardamos todos los meses del vector mes en TRANSACTION_LOG para porter ordenarlos y sacar 1 de cada 1

  //latitud y longitud de los departamentos ej 13.868874, -89.055210
  vector < string > v_Deps = {
    "AHUACHAPAN",
    "SANTA ANA",
    "SONSONATE",
    "CHALATENANGO",
    "LA LIBERTAD",
    "SAN SALVADOR",
    "CUSCATLAN",
    "LA PAZ",
    "CABANAS",
    "SAN VICENTE",
    "USULUTAN",
    "SAN MIGUEL",
    "MORAZAN",
    "LA UNION"
  };
  vector < double > v_lat = {
    13.933655,
    13.979989,
    13.711471,
    14.017779,
    13.491122,
    13.693104,
    13.868874,
    13.512094,
    13.897287,
    13.640336,
    13.388490,
    13.479014,
    13.759449,
    13.335693
  };
  vector < double > v_long = {
    -89.846727,
    -89.563681,
    -89.723224,
    -88.912874,
    -89.308695,
    -89.217516,
    -89.055210,
    -88.973495,
    -88.707886,
    -88.783263,
    -88.490154,
    -88.174068,
    -88.096214,
    -87.851100
  };
  vector < string > v_origen;
  vector < string > v_destino;
  string ejecutiva = "EJECUTIVA";
  string tradicional = "TRADICIONAL";
  string estado_A = "_A";
  string estado_nA = "EN_RUTA";
  //Variables para Vehiculos
  int id;
  int idcatVeh;
  string numeroPlaca;
  string catVehiculo;
  string marcaVehiculo;
  string numeroMotor;
  string modeloVehiculo;
  string colorVehiculo;
  string year;
  int yearVehiculo;
  //vectores para Vehiculos No Avilitados

  //Vectores y Variables para Conductores
  int idConductorint;
  string nom_completo;
  string idConductorstring;
  string nombreConductor;
  string apellidoConductor;
  int iSSSint;
  string iSSSstring;
  string nTelstring;
  string direccionCon;
  string sDui;
  vector < int > aux_iD; //vector auxiliar para ordenar iD
  //terminan las variable
  try {
    do {
      //LIMPIAMOS VECTORES
      Cl_C.Reset_Vectores();
      Cl_T.ResetVectores();

      //VERIFICAMOS ARCHIVO CSV Y GUARDAMOS EN VECTORES LOS DATOS
      Cl_C.SaveOnVectors();
      Cl_T.SaveOnVectors();

      //GUARDAMOS EN VECTORES NO AVAILABLE LOS TAXIS EN RUTA
      Cl_C.SaveOn_nAVectors();
      //fin relleno de vectores
      system("cls");
      cout << "Menu principal de opciones:\n\n" << endl;
      cout << "\t\t1. Agregar nuevo taxi a la cola de espera." << endl;
      cout << "\t\t2. Listar Datos Ingresados." << endl;
      cout << "\t\t3. Enviar Taxi a ruta." << endl;
      cout << "\t\t4. Listar Taxis en rutas." << endl;
      cout << "\t\t5. Actualizar estado de Taxis." << endl;
      cout << "\t\t6. Gestion de Reportes." << endl;
      cout << "\t\t7. Salir del Programa." << endl;
      cout << "\nPorfavor, ingrese su opcion: ";
      int contador = 0;
      // ciclo para validar el Dato de entrada.			
      do {
        fflush(stdin);
        getline(cin, validarIntconfuncion);
        //validamos que el valor ingresado sea un numero
        //retornamos verdadero de funcion para que entre en primera condicion
        if (Cl_Fx.valEntero(validarIntconfuncion)) {
          opcion = atoi(validarIntconfuncion.c_str()); //convertimos a Entero la cadena validada de numero
          //condicion que no sea negativo
          if (opcion <= 0) {
            cout << "\nFavor ingresar un numero mayor a 0" << endl;
            valCampo = true; //mantiene el bucle
          } else {
            valCampo = false; //campo valido para salir de bucle
          }
        } else {
          cout << "\nFavor ingresar unicamente un numero entero" << endl;
          valCampo = true; //mantiene el bucle
        }
        contador++;
        if (contador == 2) {
          break;
        }
      } while (valCampo);

      //Creamos el bucle de seleccion multiple
      switch (opcion) {
      case 1:
        system("cls");
        cout << "Menu para ingresar datos de taxi y conductor a cola de espera" << endl;
        cout << "\n+++++++++ Datos de Vehiculo ++++++++" << endl;

        //iD generado autoincrementalmente con formula taxis.size()+1;//cuento el tama;o de vector id +1  para el siguiente id
        /*
        do{			
        // ciclo para validar el Dato de entrada.			
        do {
        cout<<"Taxi ID: ";
        fflush(stdin);//descartamos el salto de l?nea que se ha quedado en el buffer de entrada
        getline(cin,validarIntconfuncion);
        //validamos que el valor ingresado sea un numero
        if (valEntero(validarIntconfuncion) && validarIntconfuncion.size()>0) {
        id = atoi(validarIntconfuncion.c_str());//convertimos a Entero la cadena validada de numero
        valCampo = false;
        }else {
        cout << "\nFavor ingresar unicamente un numero entero" << endl;
        valCampo = true;
        }
        } while (valCampo);
        }while(checkForItemInt(taxis, id));//con el metodo de busqueda checkForItemInt, verificamos que no haya duplicado con el dato ingresado
        */

        //Bloque para ingresar numero de placa.
        do {
          do {
            cout << "\nNumero de Placa: ";
            fflush(stdin); //descartamos el salto de l?nea que se ha quedado en el buffer de entrada
            //	cin.ignore();//descartamos el salto de l?nea que se ha quedado en el buffer de entrada
            getline(cin, numeroPlaca); //Captura el dato ingresado por usuario
            if (Cl_Fx.validarPlaca(numeroPlaca)) {
              //	numeroPlaca[0] = towupper(numeroPlaca[0]);//convertimos en mayusculas la letra de placa
              //	 towupper(numeroPlaca); no se puede convertir cadena directamente
              Cl_Fx.Mayusculas(numeroPlaca); //convertimos en mayusculas la letra de placa
              valCampo = false;
            } else {
              cout << "\nFavor ingresar formato Placa P-XXXXXX" << endl;
              valCampo = true;
            }
          } while (valCampo);
        } while (Cl_Fx.checkForItemInt(Cl_C.placas, numeroPlaca)); //con el metodo de busqueda checkForItemInt, verificamos que no haya duplicado con el dato ingresado

        //Ciclo de captura # De Motor
        do {
          do {

            cout << "\nNumero de Motor: ";
            fflush(stdin); //descartamos el salto de l?nea que se ha quedado en el buffer de entrada
            getline(cin, numeroMotor); //Captura el dato ingresado por usuario
            if (Cl_Fx.validarAlfaNumeros(numeroMotor) && numeroMotor.size() > 2 && numeroMotor.size() <= 15) { //validamos que sea Alfa Numerico el dato ingresado
              Cl_Fx.Mayusculas(numeroMotor);
              valCampo = false;
            } else {
              cout << "\nUnicamente puede ingresar Letras y/o Numeros min 3 max 15\n";
              valCampo = true;
            }
          } while (valCampo);
        } while (Cl_Fx.checkForItemInt(Cl_C.numeroMotores, numeroMotor)); //con el metodo de busqueda checkForItemInt, verificamos que no haya duplicado con el dato ingresado		

        //Ciclo de Marca de Vehiculo
        do {

          cout << "\nMarca de Vehiculo: ";
          fflush(stdin); //descartamos el salto de l?nea que se ha quedado en el buffer de entrada
          getline(cin, marcaVehiculo); //Captura el dato ingresado por usuario
          if (Cl_Fx.valLetras(marcaVehiculo) && marcaVehiculo.size() > 2 && marcaVehiculo.size() <= 15) { //validamos que sea Alfa Numerico el dato ingresado
            Cl_Fx.Mayusculas(marcaVehiculo);
            valCampo = false;
          } else {
            cout << "\nUnicamente puede ingresar Letras min 3 max 15\n";
            valCampo = true;
          }
        } while (valCampo);

        //Ciclo de Modelo de Vehiculo
        do {

          cout << "\nModelo de Vehiculo: ";
          fflush(stdin); //descartamos el salto de l?nea que se ha quedado en el buffer de entrada
          getline(cin, modeloVehiculo); //Captura el dato ingresado por usuario
          if (Cl_Fx.valLetras(modeloVehiculo) && modeloVehiculo.size() > 2 && modeloVehiculo.size() <= 15) { //validamos que sea Alfa Numerico el dato ingresado
            Cl_Fx.Mayusculas(modeloVehiculo);
            valCampo = false;
          } else {
            cout << "\nUnicamente puede ingresar Letras min 3 max 15\n";
            valCampo = true;
          }
        } while (valCampo);

        //Datos de Color de Vehiculo
        do {

          cout << "\nColor de Vehiculo: ";
          fflush(stdin); //descartamos el salto de l?nea que se ha quedado en el buffer de entrada
          getline(cin, colorVehiculo); //Captura el dato ingresado por usuario
          if (Cl_Fx.valLetras(colorVehiculo) && colorVehiculo.size() > 2 && colorVehiculo.size() <= 15) { //validamos que sea Alfa Numerico el dato ingresado
            Cl_Fx.Mayusculas(colorVehiculo);
            valCampo = false;
          } else {
            cout << "\nUnicamente puede ingresar Letras min 3 max 15\n";
            valCampo = true;
          }
        } while (valCampo);

        //Ciclo A?o y Tipo de Vehiculo		
        // ciclo para validar el Dato de entrada.			
        do {
          cout << "\nA?o de Vehiculo: ";
          fflush(stdin); //descartamos el salto de l?nea que se ha quedado en el buffer de entrada
          getline(cin, year);
          //validamos que el valor ingresado sea un numero
          if (Cl_Fx.valEntero(year) && year.size() == 4) {
            yearVehiculo = atoi(year.c_str()); //convertimos a Entero la cadena validada de numero
            if (yearVehiculo >= 2010 && yearVehiculo <= 2019) {

              if (yearVehiculo >= 2010 && yearVehiculo < 2015) {
                catVehiculo = "TRADICIONAL";
                valCampo = false;
              } else if (yearVehiculo >= 2015 && yearVehiculo <= 2019) {
                bool valClase = true;
                cout << "\n\nSELECCIONE LA CATEGORIA: \nOpcion 1 \'Ejecutiva\' \nOpcion 2 \'Tradicional\' " << endl;
                do {
                  fflush(stdin);
                  getline(cin, validarIntconfuncion);
                  if (Cl_Fx.valEntero(validarIntconfuncion) && validarIntconfuncion.size() == 1) {
                    idcatVeh = atoi(validarIntconfuncion.c_str()); //convertimos a Entero la cadena validada de numero
                    //condicion que no sea negativo
                    if (idcatVeh == 1) {
                      catVehiculo = "EJECUTIVA";
                      valClase = false;
                    } else if (idcatVeh == 2) {
                      catVehiculo = "TRADICIONAL";
                      valClase = false;
                    } else if (idcatVeh <= 0 || idcatVeh > 2) {
                      cout << "\nFavor ingresar un numero de Opcion valido." << endl;
                      valClase = true; //mantiene el bucle
                    }
                  } else {
                    cout << "\nFavor ingresar unicamente un numero entero." << endl;
                    valClase = true; //mantiene el bucle
                  }
                } while (valClase);

              } //else if 2015 2019
            } else if (yearVehiculo < 2010) {
              cout << "\nLo sentimos vehiculo NO puede ser registrado por antiguedad" << endl;
              break;
            } else {
              cout << "\nNo puede ingresar un a?o mayor al actual" << endl;
              break;
            }

          } else {
            cout << "\nFavor ingresar unicamente un a?o de vehiculo valido" << endl;
            valCampo = true;
          }
        } while (valCampo);

        if (yearVehiculo >= 2010 && yearVehiculo <= 2019) {
          cout << "+++++++++ Datos del Conductor ++++++++" << endl;
          //Ciclo de iD Conductor
          do {

            // ciclo para validar el Dato de entrada.			
            do {

              cout << "\nDui de Conductor: ";
              fflush(stdin); //descartamos el salto de l?nea que se ha quedado en el buffer de entrada
              getline(cin, sDui);
              //validamos que el formato sea de Dui
              if (Cl_Fx.validarDui(sDui)) {
                valCampo = false;
              } else {
                cout << "\nFavor ingresar un Dui valido formato XXXXXXXX-X" << endl;
                valCampo = true;
              }
            } while (valCampo);
          } while (Cl_Fx.checkForItemInt(Cl_C.vDuis, sDui)); //con el metodo de busqueda checkForItemInt, verificamos que no haya duplicado con el dato ingresado

          //Ciclo de ISSS Conductor
          do {
            // ciclo para validar el Dato de entrada.			
            do {

              cout << "\nISSS de Conductor: ";
              fflush(stdin); //descartamos el salto de l?nea que se ha quedado en el buffer de entrada
              getline(cin, iSSSstring);
              //validamos que el formato sea de ISSS
              if (Cl_Fx.valEntero(iSSSstring) && iSSSstring.size() > 3 && iSSSstring.size() <= 8) {
                iSSSint = atoi(iSSSstring.c_str());
                valCampo = false;
              } else {
                cout << "\nFormato ISSS solo numeros min 4 max 8" << endl;
                valCampo = true;
              }
            } while (valCampo);
          } while (Cl_Fx.checkForItemInt(Cl_C.vISSS, iSSSint)); //con el metodo de busqueda checkForItemInt, verificamos que no haya duplicado con el dato ingresado

          //Ciclo de Telefono de Conductor
          do {
            // ciclo para validar el Dato de entrada.			
            do {

              cout << "\nTelefono de Conductor: ";
              fflush(stdin); //descartamos el salto de l?nea que se ha quedado en el buffer de entrada
              getline(cin, nTelstring);
              //validamos que el formato sea de Telefono
              if (Cl_Fx.validarTel(nTelstring)) {
                valCampo = false;
              } else {
                cout << "\nFavor ingresar un numero valido formato XXXX-XXXX" << endl;
                valCampo = true;
              }
            } while (valCampo);
          } while (Cl_Fx.checkForItemInt(Cl_C.vnTels, nTelstring)); //con el metodo de busqueda checkForItemInt, verificamos que no haya duplicado con el dato ingresado

          //Ciclo de Nombre Conductor
          do {

            cout << "\nNombre Conductor: ";
            fflush(stdin); //descartamos el salto de l?nea que se ha quedado en el buffer de entrada
            getline(cin, nombreConductor); //Captura el dato ingresado por usuario
            if (Cl_Fx.valNombres(nombreConductor) && nombreConductor.size() > 2 && nombreConductor.size() <= 25) { //validamos que sea Alfa Numerico el dato ingresado
              Cl_Fx.Mayusculas(nombreConductor);
              valCampo = false;
            } else {
              cout << "\nUnicamente puede ingresar Letras min 3 max 25\n";
              valCampo = true;
            }
          } while (valCampo);

          //apellido
          do {

            cout << "\nApellido Conductor: ";
            fflush(stdin); //descartamos el salto de l?nea que se ha quedado en el buffer de entrada
            getline(cin, apellidoConductor); //Captura el dato ingresado por usuario
            if (Cl_Fx.valNombres(apellidoConductor) && apellidoConductor.size() > 2 && apellidoConductor.size() <= 25) { //validamos que sea Alfa Numerico el dato ingresado
              Cl_Fx.Mayusculas(apellidoConductor);
              valCampo = false;
            } else {
              cout << "\nUnicamente puede ingresar Letras min 3 max 25\n";
              valCampo = true;
            }
          } while (valCampo);

          //Ciclo de Direccion de Conductor
          do {

            cout << "\nDireccion del Conductor: ";
            fflush(stdin); //descartamos el salto de l?nea que se ha quedado en el buffer de entrada
            getline(cin, direccionCon); //Captura el dato ingresado por usuario
            if (direccionCon.size() >= 5 && nombreConductor.size() <= 50) { //validamos que sea Alfa Numerico el dato ingresado
              Cl_Fx.Mayusculas(direccionCon);
              valCampo = false;
            } else {
              cout << "\nUnicamente puede ingresar Letras min 5 max 50\n";
              valCampo = true;
            }
          } while (valCampo);

          //Guardamos los datos ingresados
          nom_completo = nombreConductor + " " + apellidoConductor;
          int valor_orden = -1; //iniciamos varaible
          int ult_valor = Cl_C.v_Orden.size() - 1; //capturamos el tamano del arreglo
          valor_orden = 1 + Cl_C.v_Orden[ult_valor]; //capturamos el valor del ultimo arreglo y le sumamos 1

          //Ingresamos los Datos ingresados a archivo CARS_STORAGE.csv
          Cl_C.Ingresar_Datos(valor_orden, Cl_C.taxis.size() + 1, nom_completo, numeroPlaca, numeroMotor, marcaVehiculo, modeloVehiculo, colorVehiculo, yearVehiculo,
            catVehiculo, sDui, iSSSint, nTelstring, direccionCon, fecha);

        } //if a?o

        break;

      case 2:
        system("cls");
        cout << "\n\n\t\t\t++++++++++++++ LISTA DE TAXIS Y CONDUCTORES HABILITADOS ++++++++++++++" << endl << endl;
        iT = -1;
        iE = -1;
        iE = Cl_Fx.id_valorSelcted(Cl_C.v_Estado, estado_A, Cl_C.catsVehiculos, ejecutiva); //Buscamos unicamente tipo de categoria en estado habilitado
        iT = Cl_Fx.id_valorSelcted(Cl_C.v_Estado, estado_A, Cl_C.catsVehiculos, tradicional); //Buscamos unicamente tipo de categoria en estado habilitado
        if (iE != -1 || iT != -1) {
          Cl_C.pTDisponibles();
        } else {
          cout << "\nNo se encontro ningun dato." << endl;
          break;
          valCampo = false;
        }
        break;

      case 3:
        system("cls");
        do {
          iT = -1;
          iE = -1;
          idcatVeh = -1;
          iE = Cl_Fx.id_valorSelcted(Cl_C.v_Estado, estado_A, Cl_C.catsVehiculos, ejecutiva); //Buscamos unicamente tipo de categoria en estado habilitado
          iT = Cl_Fx.id_valorSelcted(Cl_C.v_Estado, estado_A, Cl_C.catsVehiculos, tradicional); //Buscamos unicamente tipo de categoria en estado habilitado
          if (iE != -1 && iT == -1) {
            do {
              cout << "\n\nUnicamente hay Linea Ejecutiva Disponible, desea continuar? (S/N): " << endl;
              confirmacion = getche();
              if (confirmacion == 'N' || confirmacion == 'n') {
                valCampo2 = false;
              } else if (confirmacion == 'S' || confirmacion == 's') {
                idcatVeh = 1;
                valCampo = false;
                valCampo2 = false;
              } else {
                cout << "\n\nFavor ingresar unicamente letra S o N" << endl;
                valCampo2 = true;
              }
            } while (valCampo2);
          } else if (iE == -1 && iT != -1) {
            do {
              cout << "\nUnicamente hay Linea Tradicional Disponible, desea continuar? (S/N): " << endl;
              confirmacion = getche();
              if (confirmacion == 'N' || confirmacion == 'n') {
                valCampo2 = false;
              } else if (confirmacion == 'S' || confirmacion == 's') {
                idcatVeh = 2;
                valCampo = false;
                valCampo2 = false;
              } else {
                cout << "\nFavor ingresar unicamente letra S o N" << endl;
                valCampo2 = true;
              }
            } while (valCampo2);

          } else if (iE != -1 && iT != -1) {
            cout << "\n\nSELECCIONE LA CATEGORIA: \nOpcion 1 \'Ejecutiva\' \nOpcion 2 \'Tradicional\' " << endl;
            fflush(stdin);
            getline(cin, validarIntconfuncion);
            if (Cl_Fx.valEntero(validarIntconfuncion) && validarIntconfuncion.size() == 1) {
              idcatVeh = atoi(validarIntconfuncion.c_str()); //convertimos a Entero la cadena validada de numero
              //condicion que no sea negativo
              if (idcatVeh <= 0 || idcatVeh > 2) {
                cout << "\nFavor ingresar un numero de Opcion valido." << endl;
                valCampo = true; //mantiene el bucle
              } else {
                valCampo = false; //campo valido para salir de bucle
              }
            } else {
              cout << "\nFavor ingresar unicamente un numero entero." << endl;
              valCampo = true; //mantiene el bucle
            }
          } else {
            cout << "\nLo sentimos no hay taxis disponibles." << endl;
            break;
            valCampo = false;
          }
        } while (valCampo);

        if (idcatVeh > 0) {
          do {
            cout << "\n\t\t\t  ++++++++++++++++++ DESTINOS HABILES PARA EL SERVICIO DE TAXI ++++++++++++++++++" << endl << endl;
            cout << "-----------------------------------------------------------------" << endl;
            cout << "|  1) Ahuachapan\t 6) San Salvador\t 11) Usulutan   |" << endl;
            cout << "|  2) Santa Ana\t\t 7) Cuscatlan\t\t 12) San Miguel |" << endl;
            cout << "|  3) Sonsonate\t\t 8) La Paz\t\t 13) Morazan    |" << endl;
            cout << "|  4) Chalatenango\t 9) Caba?as\t\t 14) La Union   |" << endl;
            cout << "|  5) La Libertad\t 10) San Vicente \t\t        |" << endl;
            cout << "-----------------------------------------------------------------" << endl << endl;
            cout << "\nPORFAVOR INGRESE SU PUNTO DE PARTIDA: " << endl;
            fflush(stdin);
            getline(cin, id_origen);
            if (Cl_Fx.valEntero(id_origen)) {
              idorigen = atoi(id_origen.c_str()); //convertimos a Entero la cadena validada de numero
              //condicion que no sea negativo
              if (idorigen <= 0 || idorigen > 14) {
                cout << "\nFavor ingresar un numero de Opcion valido" << endl;
                valCampo = true; //mantiene el bucle
              } else if (idorigen > 0 || idorigen <= 14) {
                valCampo = false; //campo valido para salir de bucle
              }
            } else {
              cout << "\nFavor ingresar unicamente un numero entero" << endl;
              valCampo = true; //mantiene el bucle
            }
          } while (valCampo);

          do {
            cout << "\nPORFAVOR INGRESE SU DESTINO: " << endl;
            fflush(stdin);
            getline(cin, id_destino);
            if (Cl_Fx.valEntero(id_destino)) {
              iddestino = atoi(id_destino.c_str()); //convertimos a Entero la cadena validada de numero
              if (iddestino == idorigen) {
                cout << "\nFavor ingresar destino distinto al origen" << endl;
                valCampo = true; //mantiene el bucle
              } else if (iddestino <= 0 || iddestino > 14) {
                cout << "\nFavor ingresar un numero de Opcion valido" << endl;
                valCampo = true; //mantiene el bucle
              } else if (iddestino > 0 || iddestino <= 14) {
                valCampo = false; //campo valido para salir de bucle
              }
            } else {
              cout << "\nFavor ingresar unicamente un numero entero" << endl;
              valCampo = true; //mantiene el bucle
            }
          } while (valCampo);

          system("cls");
          cout << "\n\n" << endl;;
          origen = "";
          destino = "";
          origen = v_Deps[idorigen - 1];
          destino = v_Deps[iddestino - 1];

          v_origen.push_back(origen);
          v_destino.push_back(destino);

          latOrigen = v_lat[idorigen - 1]; //se resta 1 porque el vector empieza de 0
          longOrigen = v_long[idorigen - 1];
          latDestino = v_lat[iddestino - 1];
          longDestino = v_long[iddestino - 1];

          distancia = Cl_Fx.convertirDistancia(latOrigen, longOrigen, latDestino, longDestino);
          float t;
          int hora, min, seg;
          t_f = (distancia < 60) ? " minutos" : " ";
          cout << "\n\n +++++++++++ FACTURA   ++++++++++" << endl << endl;

          if (idcatVeh == 1) {
            cout << "\n Linea de viaje: EJECUTIVA" << endl;
          } else {
            cout << "\n Linea de viaje: TRADICIONAL" << endl;
          }
          costoViaje = distancia * 0.74; //cada kilometro x 0.74 centavos
          costoLinea = (distancia * 0.74) * 0.1; //si es ejecutiva se carga 10%
          cout << "\n Origen de su viaje: ( " << v_Deps[idorigen - 1] << " )\n\n Con destino a: ( " << v_Deps[iddestino - 1] << " )" << endl << endl;
          //Formula para dar formato a hora
          seg = (distancia / 60) * 3600;
          hora = seg / (60 * 60);

          seg %= 60 * 60;
          min = seg / 60;
          //	seg %=60;
          if (hora < 1) {
            cout << " Tiempo estimado: " << min << " minutos" << endl;
          } else if (hora == 1) {
            cout << " Tiempo estimado: " << hora << " hora con " << min << " minutos" << endl;
          } else {
            cout << " Tiempo estimado: " << hora << " horas con " << min << " minutos" << endl;
          }
          cout << "\n Distancia: " << fixed << setprecision(2) << distancia << " kilometros" << endl;
          cout << "\n Costo de viaje: $ " << fixed << setprecision(2) << costoViaje << endl;
          //si es linea Ejecutiva muestra estos datos	

          if (idcatVeh == 1) {
            cout << "\n Costo de linea ejecutiva: $ " << costoLinea << endl; //adiciona 10% si es Ejecutiva
            IVA = (costoViaje + costoLinea) * 0.13;
            cout << "\n IVA: $ " << IVA << endl; //iva si es ejecutiva
            totalViaje = costoViaje + IVA + costoLinea;
            cout << "\n Total: $" << fixed << setprecision(2) << totalViaje << endl;
          } else { //si es tradicional muestra estos
            IVA = costoViaje * 0.13;
            cout << "\n IVA: $ " << IVA << endl; //iva si es ejecutiva
            totalViaje = costoViaje + IVA;
            cout << "\n Total: $" << fixed << setprecision(2) << totalViaje << endl;
          }

          cout << "\n\n +++++++++++++++++++++++++++++++++" << endl;

          //ciclo cuando confirma Taxi a Ruta o No
          do {
            cout << "\nConfirmar Pago (S/N): " << endl;
            confirmacion = getche();

            if (confirmacion == 'S' || confirmacion == 's') {

              int i = -1;
              //creamos un condicional para capturar el primer vector con la linea seleccionada y afectar solo esa fila					
              //Agregando el vehiculo asignado a vector de rutas,elimandolo de habilitados y mostrando tabla de taxi en ruta
              if (idcatVeh == 1) {
                //buscamos la posicion del primer taxi habilitado de la linea solicitada y retornamos la posicion guardandola en la variable i
                i = Cl_Fx.id_valorSelcted(Cl_C.v_Estado, estado_A, Cl_C.catsVehiculos, ejecutiva);
              } else if (idcatVeh == 2) {
                i = Cl_Fx.id_valorSelcted(Cl_C.v_Estado, estado_A, Cl_C.catsVehiculos, tradicional);
              }

              if (i != -1) {
                system("cls");
                cout << "\n\n" << endl;
                //Este condicional es para que en TRANSACTION_LOG se genere el propio orden correlativo de los que se han solicitado los taxis,
                //y que no tome el orden que estan en CARS_STORAGE porque el # de orden debe generarse en orden de como se solicitan.
                int valOrden = 0;
                if (Cl_T.v_TOrden.size() == 0) {
                  valOrden = 1;
                } else {
                  valOrden = 1 + Cl_T.v_TOrden[Cl_T.v_TOrden.size() - 1];
                }
                //Mostramos el Taxi asignado.
                Cl_C.pTCliente(valOrden, origen, destino, i);
                //Guardamos los datos del taxi a ruta en archivo TRANSACTION_LOG.csv
                Cl_T.save_TransLog(valOrden, Cl_C.taxis, Cl_C.nombresComConductores, Cl_C.placas, Cl_C.numeroMotores, Cl_C.marcasVehiculos,
                  Cl_C.modelosVehiculos, Cl_C.colorVehiculos, Cl_C.yearsVehiculos, Cl_C.catsVehiculos, Cl_C.vDuis, Cl_C.vISSS,
                  Cl_C.vnTels, Cl_C.vDireccionCon, fecha, origen, destino, totalViaje, i);
                //Actualizamos el vector de taxi habilitado a taxi en ruta junto con su origen y destino
                Cl_C.v_Orden[i] = valOrden;
                Cl_C.v_Estado[i] = "EN_RUTA";
                Cl_C.v_Origen[i] = origen;
                Cl_C.v_Destino[i] = destino;
                //Borramos todos los datos de archivo CARS_STORAGE.csv para ser actualizado, con nuestros datos de vector.
                Cl_C.deltoUpdate_csv();

                //Actualizamos los datos en archivo CARS_STORAGE.csv
                for (int i = 0; i < Cl_C.taxis.size(); i++) {
                  Cl_C.update_Datos(Cl_C.v_Orden[i], Cl_C.taxis[i], Cl_C.nombresComConductores[i], Cl_C.placas[i], Cl_C.numeroMotores[i], Cl_C.marcasVehiculos[i], Cl_C.modelosVehiculos[i], Cl_C.colorVehiculos[i], Cl_C.yearsVehiculos[i], Cl_C.catsVehiculos[i],
                    Cl_C.vDuis[i], Cl_C.vISSS[i], Cl_C.vnTels[i], Cl_C.vDireccionCon[i], Cl_C.v_Fecha[i], Cl_C.v_Estado[i], Cl_C.v_Origen[i], Cl_C.v_Destino[i]);
                }
              }

              valCampo = false;
            } else if (confirmacion == 'N' || confirmacion == 'n') {
              do {
                cout << "\nSeguro que desea cancelar viaje? (S/N): " << endl;
                confirmacion = getche();
                if (confirmacion == 'N' || confirmacion == 'n') {
                  valCampo2 = false;
                  valCampo = true;
                } else if (confirmacion == 'S' || confirmacion == 's') {
                  valCampo = false;
                  valCampo2 = false;
                } else {
                  cout << "\nFavor ingresar unicamente letra S o N" << endl;
                  valCampo2 = true;
                }
              } while (valCampo2);

            } else {
              cout << "\nFavor ingresar unicamente letra S o N" << endl;
              valCampo = true;
            }

          } while (valCampo);
        } //if
        break;

      case 4:
        system("cls");
        cout << "\n\t\t\t  ++++++++++++++++++ LISTA DE TAXIS EN RUTAS ++++++++++++++++++" << endl << endl;
        //Tabla para mostrar los taxis en ruta
        iT = -1;
        iE = -1;
        iE = Cl_Fx.id_valorSelcted(Cl_C.nA_v_Estado, estado_nA, Cl_C.nA_catsVehiculos, ejecutiva);
        iT = Cl_Fx.id_valorSelcted(Cl_C.nA_v_Estado, estado_nA, Cl_C.nA_catsVehiculos, tradicional);
        if (iE != -1 || iT != -1) {
          Cl_C.pTRuta();
        } else {
          cout << "\nNo hay taxis en ruta." << endl;
          break;
        }
        break;
      case 5:
        system("cls");
        //Tabla para mostrar los taxis en ruta 
        iT = -1;
        iE = -1;
        iE = Cl_Fx.id_valorSelcted(Cl_C.nA_v_Estado, estado_nA, Cl_C.nA_catsVehiculos, ejecutiva);
        iT = Cl_Fx.id_valorSelcted(Cl_C.nA_v_Estado, estado_nA, Cl_C.nA_catsVehiculos, tradicional);
        if (iE != -1 || iT != -1) {
          cout << "\n\t\t\t  ++++++++++++++++++  TAXIS EN RUTA PARA REINGRESO ++++++++++++++++++" << endl << endl;
          Cl_C.pTRuta();

          contador = -1;
          do {
            int pos_A = -1;
            int pos_nA = -1;
            int i = -1;
            cout << "\n\nPorfavor ingrese el ID del taxi que desea reingresar: " << endl;
            fflush(stdin);
            _idReingreso = "";
            getline(cin, _idReingreso);
            if (Cl_Fx.valEntero(_idReingreso)) {
              idReingreso = atoi(_idReingreso.c_str()); //convertimos a Entero la cadena validada de numero
              i = Cl_Fx.id_valReingreso(Cl_C.nA_taxis, idReingreso); //obtengo el id para validar con id ingresado

              //Si el valor ingresao es igual al id de un taxi en ruta entra al ciclo
              if (i == idReingreso) {
                pos_A = Cl_Fx.id_position(Cl_C.taxis, idReingreso); //obtendo la posicion para agregar los vectores de esa posicion a habilitados y aliminar los v de esa posicion
                pos_nA = Cl_Fx.id_position(Cl_C.nA_taxis, idReingreso);
                //Guardamos los datos del taxi en ruta, en la ultima posicion del archivo CARS_STORAGE.csv
                Cl_C.upnA_to_A(pos_nA, pos_A);

                cout << "\n\nTaxi en ruta con id # " << i << " reingresado correctamente, gracias." << endl << endl;
                valCampo = false;
              } else {
                cout << "\nFavor ingresar una opcion valida" << endl;
                valCampo = true; //mantiene el bucle
              }

            } else {
              cout << "\nFavor ingresar una opcion valida" << endl;
              valCampo = true; //mantiene el bucle
            }
            contador++;
            if (contador == 2) {
              break;
            }
          } while (valCampo);

        } else {
          cout << "\nNo hay taxis en ruta." << endl;
          break;
        }

        break;

      case 6:

        system("cls");
        if (Cl_T.v_Tid.size() != 0) {

          cout << "\n\t\t\t  ++++++++++++++++++  GESTION DE REPORTES, PORFAVOR ELIJA UNA OPCION ++++++++++++++++++" << endl << endl;

          cout << "1) Listado de viajes realizados por cada veh?culo (Todos los veh?culos)" << endl;
          cout << "2) Listado de viajes realizados por un veh?culo especifico." << endl;
          cout << "3) Ingresos totales obtenidos en un mes." << endl;
          cout << "4) Ingresos totales obtenidos en un mes por un veh?culo especifico." << endl;
          cout << "5) Regresar a Men? principal." << endl;
          do {

            do {
              fflush(stdin);
              getline(cin, validarIntconfuncion);
              //validamos que el valor ingresado sea un numero
              //retornamos verdadero de funcion para que entre en primera condicion
              if (Cl_Fx.valEntero(validarIntconfuncion)) {
                opcion = atoi(validarIntconfuncion.c_str()); //convertimos a Entero la cadena validada de numero
                //condicion que no sea negativo
                if (opcion <= 0) {
                  cout << "\nFavor ingresar un numero mayor a 0" << endl;
                  valCampo = true; //mantiene el bucle
                } else {
                  valCampo = false; //campo valido para salir de bucle
                }
              } else {
                cout << "\nFavor ingresar unicamente un numero entero" << endl;
                valCampo = true; //mantiene el bucle
              }
              contador++;
              if (contador == 2) {
                break;
              }
            } while (valCampo);
            valCampo = true;

            switch (opcion) {

              //1) Listado de viajes realizados por cada veh?culo (Todos los veh?culos)
            case 1:
              idCar = -1;
              mes = -1;
              system("cls");
              cout << "\n\t\t\t  ++++++++++++++++++  LISTADO DE VIAJES REALIZADOS  ++++++++++++++++++" << endl << endl;

              Cl_T.pTRANSACTION_LOG(idCar, mes);
              valCampo = false;

              break;

            case 2:
              idCar = -1;
              mes = -1;
              aux_iD = {};
              system("cls");

              cout << "\n\n +++++++ REPORTE DE VIAJES REALIZADOS POR # DE ID  ++++++++ " << endl << endl;

              //Guardamos el Id de todos los Taxis con viajes en vector auxiliar.
              for (int i = 0; i < Cl_T.v_Tid.size(); i++) {
                aux_iD.push_back(Cl_T.v_Tid[i]);
              }

              sort(aux_iD.begin(), aux_iD.end()); //ordenamos los numeros de ID de vector aux, 

              //Ciclo para mostrar el iD de Taxis con viajes, y que muestre solo 1 de c/u
              //El vector viene ordenado por tanto va entrar la primera vez,
              //luego entrara hasta que el siguiente ID sea distinto al anterior
              for (int i = 0; i < aux_iD.size(); i++) {

                if (aux_iD[i] != idCar) {
                  idCar = aux_iD[i];
                  //Imprimimos los ID DE TAXIS CON VIAJES
                  cout << "VIAJES REALIZADOS CON TAXI #: " << idCar << endl;
                }
              }

              // ciclo para validar el Dato de entrada.			
              do {
                cout << "\nINGRESE EL # DE ID: " << endl;
                fflush(stdin); //descartamos el salto de l?nea que se ha quedado en el buffer de entrada
                getline(cin, validarIntconfuncion);
                if (Cl_Fx.valEntero(validarIntconfuncion)) {
                  opcion = atoi(validarIntconfuncion.c_str());
                  for (int i = 0; i < Cl_T.v_Tid.size(); i++) {

                    //si El ID SELECCIONADO EXISTE EN LA TABLA ENTRA A MOSTRAR LOS DATOS
                    if (Cl_T.v_Tid[i] == opcion) {
                      //El areglo esta ordenado segun el # de orden 
                      Cl_T.pTRANSACTION_LOG(opcion, mes);
                      valCampo = false;
                      break;
                    } else if (i == Cl_T.v_Tid.size() - 1) {
                      cout << "\nFavor ingresar un # de ID valido" << endl;
                      valCampo = true;
                    }
                  }
                } else {
                  cout << "\nFavor ingresar un valido de nuestra Base de Datos" << endl;
                  valCampo = true;
                }
              } while (valCampo);
              break;

            case 3: //3) Ingresos totales obtenidos en un mes (especificado al generar el reporte).
              idCar = -1;
              mes = -1;
              numMeses = {};
              system("cls");
              // ciclo para validar el Dato de entrada.	
              cout << "\n\t\t\t  ++++++++++++++++++ MESES DISPONIBLES PARA REPORTE  ++++++++++++++++++" << endl << endl;

              //ciclo para ordenar los meses que se puede seleccionar y poder iterar en el segundo for solo 1 mes de los que existem
              for (int i = 0; i < Cl_T.v_TFecha.size(); i++) {
                sub_mV = Cl_T.v_TFecha[i].substr(3, 2);
                s_mesV = atoi(sub_mV.c_str());
                numMeses.push_back(s_mesV);
              }

              //ordenamos los meses en un vector gracias al a libreria <Algorithm>
              sort(numMeses.begin(), numMeses.end());

              for (int i = 0; i < numMeses.size(); i++) {
                //si el mes de la posicion vector es diferente al mes. entra a la condicion, el primero entra porque trae varlor -1
                //luego, mes = recibe el valor del mes ordenado encontrado y si en la siguiente posicion se encuentra
                //no entrara al vector hasta que encuentre una posicion donde el valor sea distinto al ya encontrado!!! 							
                if (numMeses[i] != mes) {
                  mes = numMeses[i];
                  //Imprimimos los meses Disponibles para consultar
                  cout << mes << ") " << Meses[mes - 1] << endl;
                }
              }

              cout << "\n\nPorfavor ingrese el numero del Mes: " << endl;

              mes = -1;
              s_mes = -1;
              do {
                fflush(stdin); //descartamos el salto de l?nea que se ha quedado en el buffer de entrada
                getline(cin, validarIntconfuncion);
                if (Cl_Fx.valEntero(validarIntconfuncion)) {
                  mes = atoi(validarIntconfuncion.c_str());

                  if (mes > 0 && mes <= 12) {
                    for (int i = 0; i < Cl_T.v_Tid.size(); i++) {
                      string sub_m = Cl_T.v_TFecha[i].substr(3, 2);
                      s_mes = atoi(sub_m.c_str());
                      if (s_mes == mes) {
                        Cl_T.pTRANSACTION_LOG(idCar, mes);
                        valCampo = false;
                        break;
                      } else if (i == Cl_T.v_Tid.size() - 1) {
                        cout << "\nNo hay registros de Mes con opcion ingresada" << endl;
                        valCampo = true;
                      }
                    } //for
                  } else {
                    cout << "\nFavor ingresar un mes Valido" << endl;
                    valCampo = true;
                  }

                } else {
                  cout << "\nFavor ingresar un mes Valido" << endl;
                  valCampo = true;
                }
              } while (valCampo);

              break;

            case 4: //Ingresos totales obtenidos en un mes por un veh?culo especifico.
              idCar = -1;
              mes = -1;
              aux_iD = {};
              system("cls");
              cout << "\n\n +++++++ REPORTE DE INGRESOS TOTALES OBTENIDOS POR MES Y TAXI EN ESPECIFICO  ++++++++ " << endl << endl;

              cout << "\n\n ----- TAXIS DISPONIBLES PARA REPORTE ---- " << endl << endl;

              //Guardamos el Id de todos los Taxis con viajes en vector auxiliar.
              for (int i = 0; i < Cl_T.v_Tid.size(); i++) {
                aux_iD.push_back(Cl_T.v_Tid[i]);
              }

              sort(aux_iD.begin(), aux_iD.end()); //ordenamos los numeros de ID de vector aux, 

              //Ciclo para mostrar el iD de Taxis con viajes, y que muestre solo 1 de c/u
              //El vector viene ordenado por tanto va entrar la primera vez,
              //luego entrara hasta que el siguiente ID sea distinto al anterior
              for (int i = 0; i < aux_iD.size(); i++) {

                if (aux_iD[i] != idCar) {
                  idCar = aux_iD[i];
                  //Imprimimos los ID DE TAXIS CON VIAJES
                  cout << "TAXI CON ID #: " << idCar << endl;
                }
              }

              // ciclo para validar el Dato de entrada.			
              do {
                cout << "\nINGRESE EL # DE ID: " << endl;
                fflush(stdin); //descartamos el salto de l?nea que se ha quedado en el buffer de entrada
                getline(cin, validarIntconfuncion);
                if (Cl_Fx.valEntero(validarIntconfuncion)) {
                  opcion = atoi(validarIntconfuncion.c_str());
                  for (int i = 0; i < Cl_T.v_Tid.size(); i++) {

                    //si El ID SELECCIONADO EXISTE EN LA TABLA ENTRA A MOSTRAR LOS DATOS
                    if (Cl_T.v_Tid[i] == opcion) {

                      idCar = opcion;
                      mes = -1;
                      numMeses = {};
                      // ciclo para validar el Dato de entrada.	
                      cout << "\n  ++++++++++++++ MESES DISPONIBLES PARA REPORTE DE TAXI ID # " << idCar << " ++++++++++++++++++" << endl << endl;

                      //ciclo para ordenar los meses que se puede seleccionar y poder iterar en el segundo for solo 1 mes de los que existem
                      for (int i = 0; i < Cl_T.v_TFecha.size(); i++) {
                        //Agregamos el if para que unicamente busque los meses de ID seleccionado
                        if (Cl_T.v_Tid[i] == idCar) {
                          sub_mV = Cl_T.v_TFecha[i].substr(3, 2);
                          s_mesV = atoi(sub_mV.c_str());
                          numMeses.push_back(s_mesV);
                        }
                      }

                      //ordenamos los meses en un vector gracias al a libreria <Algorithm>
                      sort(numMeses.begin(), numMeses.end());

                      for (int i = 0; i < numMeses.size(); i++) {
                        //si el mes de la posicion vector es diferente al mes. entra a la condicion, el primero entra porque trae varlor -1
                        //luego, mes = recibe el valor del mes ordenado encontrado y si en la siguiente posicion se encuentra
                        //no entrara al vector hasta que encuentre una posicion donde el valor sea distinto al ya encontrado!!! 							
                        if (numMeses[i] != mes) {
                          mes = numMeses[i];
                          //Imprimimos los meses Disponibles para consultar
                          cout << mes << ") " << Meses[mes - 1] << endl;
                        }

                      }
                      cout << "\n\nPorfavor ingrese el Mes:" << endl;
                      do {
                        mes = -1;
                        s_mes = -1;

                        fflush(stdin); //descartamos el salto de l?nea que se ha quedado en el buffer de entrada
                        getline(cin, validarIntconfuncion);
                        if (Cl_Fx.valEntero(validarIntconfuncion)) {
                          mes = atoi(validarIntconfuncion.c_str());
                          if (mes > 0 && mes <= 12) {

                            for (int i = 0; i < numMeses.size(); i++) {
                              //Iteramos UNICAMENTE los meses que contenga ID SELECCIONADO
                              if (numMeses[i] == mes) {
                                Cl_T.pTRANSACTION_LOG(idCar, mes);
                                valCampo = false;
                                break;

                                //if
                              } else if (i == numMeses.size() - 1) { //si no existe el mes en el id seleccionado
                                cout << "\nFavor ingresar un mes Valido" << endl;
                                break;
                                valCampo = true;
                              } //else
                            } //for
                          } else { //si mes es menor a 0 o mayor a 12
                            cout << "\nFavor ingresar un mes Valido" << endl;
                            valCampo = true;
                          }

                        } else { //si ingresa Letras, estapacios,Carateres
                          cout << "\nFavor ingresar unicamente Numeros" << endl;
                          valCampo = true;
                        }
                      } while (valCampo);

                      //TERMINA CICLO DE BUSQUEDA POR MES
                      valCampo = false;
                      break;
                    } else if (i == Cl_T.v_Tid.size() - 1) {
                      cout << "\nFavor ingresar un # de ID valido" << endl;
                      valCampo = true;
                    }
                  }
                } else {
                  cout << "\nFavor ingresar un valido de nuestra Base de Datos" << endl;
                  valCampo = true;
                }
              } while (valCampo);

              break;

            case 5: //salir a menu principal
              valCampo = false;
              break;
            default:
              cout << "Opcion NO valida, unicamente numeros del 1 al 5\n";
              break;
            } //switch

          } while (valCampo);

          break; //case 6

        } else { //SI NO EXISTE NINGUN DATO EN TRANSACTIONS_LOC.csv 
          cout << "\n\n  ++ No existe ningun Taxi que haya registrado algun viaje ++" << endl << endl;
          break;
        }

        case 7:
          cout << "El programa ha terminado...\n";
          exit(0);
          break;

        default:
          cout << "\nPorfavor seleccion unicamente un numero del 1 al 7\n";
          break;
      }

      bool validarSN = true;
      do {
        cout << "\n\nDesea continuar en el programa? (S/N)?: ";
        //getch no muestra el valor ingresado. getche lo muestra
        resp = getche();
        if (resp == 'n' || resp == 'N' || resp == 'S' || resp == 's') {
          validarSN = false;
        } else {
          cout << "\n\nPorfavor ingresar solamente S/N\n";
        }
      } while (validarSN);

    } while (resp == 'S' || resp == 's');

  } catch (std::exception) {
    cout << "Error, El programa se detuvo." << endl;
    system("pause");
    exit(0);
  }
  //return 0;
}
