#include <iostream>

#include <string>

#include <iomanip>

#include <conio.h>

#include <vector>

#include <cmath>

#include <ctime>

#include <fstream>

#include <stdlib.h>  //funcion para usar new y delete

#include <algorithm> //para poder ordenar arregos con sort y utras funciones necesarias

#define PI 3.14159265#include <locale.h>

#include <windows.h>

#include <sstream>

using namespace std;

class Cars_Storage {

  string line;
  int line_int;

  public:
    Cars_Storage() {}

  //Vectores con Datos de vehiculos y conductores No habilitados
  vector < int > nA_Orden;
  vector < int > nA_taxis;
  vector < string > nA_nombresComConductores;
  vector < string > nA_placas;
  vector < string > nA_numeroMotores;
  vector < string > nA_marcasVehiculos;
  vector < string > nA_modelosVehiculos;
  vector < string > nA_colorVehiculos;
  vector < int > nA_yearsVehiculos;
  vector < string > nA_catsVehiculos;
  vector < string > nA_vDuis;
  vector < int > nA_vISSS;
  vector < string > nA_vnTels;
  vector < string > nA_vDireccionCon;
  vector < string > nA_v_Fecha;
  vector < string > nA_v_Estado;
  vector < string > nA_Origen;
  vector < string > nA_Destino;
  vector < string > nAConductores;

  //Vectores con Datos de vehiculos y conductores habilitados
  vector < int > v_Orden;
  vector < int > taxis;
  vector < string > placas;
  vector < string > numeroMotores;
  vector < string > marcasVehiculos;
  vector < string > modelosVehiculos;
  vector < string > colorVehiculos;
  vector < int > yearsVehiculos;
  vector < string > catsVehiculos;
  vector < string > vDuis;
  vector < int > vISSS;
  vector < string > vnTels;
  vector < string > nombresComConductores;
  vector < string > vDireccionCon;
  vector < string > v_Fecha;
  vector < string > v_Estado;
  vector < string > v_Origen;
  vector < string > v_Destino;

  void Reset_Vectores() {
    //RESETEAMOS LOS VECTORES PARA QUE NO VUELVA A INGRESAR LOS MISMO DATOS, SINO QUE SE ACTUALICEN TODOS EN CASO EL DOCUMENTO CAMBIE
    v_Orden = {};
    taxis = {};
    nombresComConductores = {};
    placas = {};
    numeroMotores = {};
    marcasVehiculos = {};
    modelosVehiculos = {};
    colorVehiculos = {};
    yearsVehiculos = {};
    catsVehiculos = {};
    vDuis = {};
    vISSS = {};
    vnTels = {};
    vDireccionCon = {};
    v_Fecha = {};
    v_Estado = {};
    v_Origen = {};
    v_Destino = {};
    //Vectores en Ruta
    nA_Orden = {};
    nA_taxis = {};
    nA_nombresComConductores = {};
    nA_placas = {};
    nA_numeroMotores = {};
    nA_marcasVehiculos = {};
    nA_modelosVehiculos = {};
    nA_colorVehiculos = {};
    nA_yearsVehiculos = {};
    nA_catsVehiculos = {};
    nA_vDuis = {};
    nA_vISSS = {};
    nA_vnTels = {};
    nA_vDireccionCon = {};
    nA_Origen = {};
    nA_Destino = {};
    nA_v_Fecha = {};
    nA_v_Estado = {};
  }

  void SaveOnVectors() {
    //Si El Archivo existe Guardamos en Vectores los datos del documento en csv
    //	ifstream ip;
    ifstream ip("CARS_STORAGE.csv");
    if (ip.is_open()) {
      int flag = 0;
      //ORDEN,ID,NOMBRE,PLACA,MOTOR,MARCA,MODELO,COLOR,YEAR,CATEGORIA,DUI,ISSS,TELEFONO,DIRECCION,FECHA,ESTADO

      while (ip.good()) {
        //El primer dato de la linea lo saco (en este caso id) y comparo que sea mayor a 0, fue la unica forma con la que pude resolver que no me imprima las lineas en blanco

        getline(ip, line, ',');
        line_int = atoi(line.c_str());
        if (line.length() != 0) {

          v_Orden.push_back(line_int);

          getline(ip, line, ',');
          taxis.push_back(atoi(line.c_str()));

          getline(ip, line, ',');
          nombresComConductores.push_back(line);

          getline(ip, line, ',');
          placas.push_back(line);

          getline(ip, line, ',');
          numeroMotores.push_back(line);

          getline(ip, line, ',');
          marcasVehiculos.push_back(line);

          getline(ip, line, ',');
          modelosVehiculos.push_back(line);

          getline(ip, line, ',');
          colorVehiculos.push_back(line);

          getline(ip, line, ',');
          yearsVehiculos.push_back(atoi(line.c_str()));

          getline(ip, line, ',');
          catsVehiculos.push_back(line);

          getline(ip, line, ',');
          vDuis.push_back(line);

          getline(ip, line, ',');
          vISSS.push_back(atoi(line.c_str()));

          getline(ip, line, ',');
          vnTels.push_back(line);

          getline(ip, line, ',');
          vDireccionCon.push_back(line);

          getline(ip, line, ',');
          v_Fecha.push_back(line);

          getline(ip, line, ',');
          v_Estado.push_back(line);

          getline(ip, line, ',');
          v_Origen.push_back(line);

          getline(ip, line);
          v_Destino.push_back(line);
        }

      } //while
      ip.close();
    } else {
      //si no existe archivo se crea (cuando se ejecuta por primera vez el programa)
      fstream ip;
      ip.open("CARS_STORAGE.csv", ios::out);
      ip.close();
    }
  }

  void SaveOn_nAVectors() {
    //guardamos los taxis en ruta en vector de noAvailable
    for (int i = 0; i < taxis.size(); i++) {

      if (v_Estado[i] == "EN_RUTA") {
        nA_Orden.push_back(v_Orden[i]);
        nA_taxis.push_back(taxis[i]);
        nA_nombresComConductores.push_back(nombresComConductores[i]);
        nA_placas.push_back(placas[i]);
        nA_numeroMotores.push_back(numeroMotores[i]);
        nA_marcasVehiculos.push_back(marcasVehiculos[i]);
        nA_modelosVehiculos.push_back(modelosVehiculos[i]);
        nA_colorVehiculos.push_back(colorVehiculos[i]);
        nA_yearsVehiculos.push_back(yearsVehiculos[i]);
        nA_catsVehiculos.push_back(catsVehiculos[i]);
        nA_vDuis.push_back(vDuis[i]);
        nA_vISSS.push_back(vISSS[i]);
        nA_vnTels.push_back(vnTels[i]);
        nA_vDireccionCon.push_back(vDireccionCon[i]);
        nA_v_Fecha.push_back(v_Fecha[i]);
        nA_v_Estado.push_back(v_Estado[i]);
        nA_Origen.push_back(v_Origen[i]);
        nA_Destino.push_back(v_Destino[i]);
      }
    }
  }

  void upnA_to_A(int pos_nA, int pos_A) {
    //variables para generar un correlativo de campo Orden.
    int valor_orden = -1; //iniciamos varaible
    int ult_valor = v_Orden.size() - 1; //capturamos el tamano del arreglo
    valor_orden = 1 + v_Orden[ult_valor]; //capturamos el valor del ultimo arreglo y le sumamos 1

    //Insertmos en la ultima posicion de Taxis Habilitados, el taxi que viene de ruta
    v_Orden.push_back(valor_orden);
    taxis.push_back(nA_taxis.at(pos_nA));
    nombresComConductores.push_back(nA_nombresComConductores.at(pos_nA));
    placas.push_back(nA_placas.at(pos_nA));
    numeroMotores.push_back(nA_numeroMotores.at(pos_nA));
    marcasVehiculos.push_back(nA_marcasVehiculos.at(pos_nA));
    modelosVehiculos.push_back(nA_modelosVehiculos.at(pos_nA));
    colorVehiculos.push_back(nA_colorVehiculos.at(pos_nA));
    yearsVehiculos.push_back(nA_yearsVehiculos.at(pos_nA));
    catsVehiculos.push_back(nA_catsVehiculos.at(pos_nA));
    vDuis.push_back(nA_vDuis.at(pos_nA));
    vISSS.push_back(nA_vISSS.at(pos_nA));
    vnTels.push_back(nA_vnTels.at(pos_nA));
    vDireccionCon.push_back(nA_vDireccionCon.at(pos_nA));
    v_Fecha.push_back(nA_v_Fecha.at(pos_nA));
    v_Estado.push_back(nA_v_Estado.at(pos_nA));
    v_Origen.push_back(nA_Origen.at(pos_nA));
    v_Destino.push_back(nA_Destino.at(pos_nA));

    //Borramos los datos del taxi en ruta, de la posicion donde se tomo segun los datos de vectores del archivo CARS_STORAGE.csv
    v_Orden.erase(v_Orden.begin() + pos_A);
    taxis.erase(taxis.begin() + pos_A);
    nombresComConductores.erase(nombresComConductores.begin() + pos_A);
    placas.erase(placas.begin() + pos_A);
    numeroMotores.erase(numeroMotores.begin() + pos_A);
    marcasVehiculos.erase(marcasVehiculos.begin() + pos_A);
    modelosVehiculos.erase(modelosVehiculos.begin() + pos_A);
    colorVehiculos.erase(colorVehiculos.begin() + pos_A);
    yearsVehiculos.erase(yearsVehiculos.begin() + pos_A);
    catsVehiculos.erase(catsVehiculos.begin() + pos_A);
    vDuis.erase(vDuis.begin() + pos_A);
    vISSS.erase(vISSS.begin() + pos_A);
    vnTels.erase(vnTels.begin() + pos_A);
    vDireccionCon.erase(vDireccionCon.begin() + pos_A);
    v_Fecha.erase(v_Fecha.begin() + pos_A);
    v_Estado.erase(v_Estado.begin() + pos_A);
    v_Origen.erase(v_Origen.begin() + pos_A);
    v_Destino.erase(v_Destino.begin() + pos_A);

    //Actualizamos los datos del vector de taxi agregado en habilitados que estara en la utima posicion
    v_Estado[taxis.size() - 1] = "_A";
    v_Origen[taxis.size() - 1] = "_O";
    v_Destino[taxis.size() - 1] = "_D";

    //Borramos todos los datos de archivo CARS_STORAGE.csv para ser actualizado, con nuestros datos de vector.
    fstream reset_csv;
    reset_csv.open("CARS_STORAGE.csv", ios::out);
    reset_csv.close();

    //Actualizamos los datos en archivo CARS_STORAGE.csv
    for (int i = 0; i < taxis.size(); i++) {
      update_Datos(v_Orden[i], taxis[i], nombresComConductores[i], placas[i], numeroMotores[i], marcasVehiculos[i], modelosVehiculos[i], colorVehiculos[i], yearsVehiculos[i], catsVehiculos[i],
        vDuis[i], vISSS[i], vnTels[i], vDireccionCon[i], v_Fecha[i], v_Estado[i], v_Origen[i], v_Destino[i]);
    }
  }

  //metodo ingresar datos al archivo csv
  void Ingresar_Datos(int orden, int id, string con_nombre, string num_placa, string num_motor, string car_marca, string car_modelo, string car_color,
    int car_year, string car_categoria, string con_dui, int con_isss, string con_tel, string con_direccion, string f_reg) {

    fstream guardar_datos;
    guardar_datos.open("CARS_STORAGE.csv", ios::app);
    guardar_datos << orden << "," <<
      id << "," <<
      con_nombre << "," <<
      num_placa << "," <<
      num_motor << "," <<
      car_marca << "," <<
      car_modelo << "," <<
      car_color << "," <<
      car_year << "," <<
      car_categoria << "," <<
      con_dui << "," <<
      con_isss << "," <<
      con_tel << "," <<
      con_direccion << "," <<
      f_reg << "," <<
      "_A" <<
      "," <<
      "_O" <<
      "," <<
      "_D" <<
      "\n";
    system("cls"); //limpiamos pantalla

    guardar_datos.close();

    cout << "\n\nDatos Guardados, Exitosamente." << endl;

  } //termina metodo

  void deltoUpdate_csv() {
    //Borramos todos los datos de archivo CARS_STORAGE.csv para ser actualizado, con nuestros datos de vector.
    fstream reset_csv;
    reset_csv.open("CARS_STORAGE.csv", ios::out);
    reset_csv.close();
  }

  void update_Datos(int orden, int id, string con_nombre, string num_placa, string num_motor, string car_marca, string car_modelo, string car_color,
    int car_year, string car_categoria, string con_dui, int con_isss, string con_tel, string con_direccion, string f_reg, string estado, string origen, string destino) {

    fstream update_cvs;
    update_cvs.open("CARS_STORAGE.csv", ios::app);
    update_cvs << orden << "," <<
      id << "," <<
      con_nombre << "," <<
      num_placa << "," <<
      num_motor << "," <<
      car_marca << "," <<
      car_modelo << "," <<
      car_color << "," <<
      car_year << "," <<
      car_categoria << "," <<
      con_dui << "," <<
      con_isss << "," <<
      con_tel << "," <<
      con_direccion << "," <<
      f_reg << "," <<
      estado << "," <<
      origen << "," <<
      destino << "\n";

    update_cvs.close();

  } //termina metodo

  void pTCliente(int valOrden, string origen, string destino, int i) {
    try {
      //Creacion del HEAD en la tabla de Datos.
      TextTable t('-', '|', '+');
      t.add("Orden"); //ok
      t.add("ID"); //ok
      t.add("Condutor"); //ok
      t.add("# de Placa"); //ok
      t.add("Marca");
      t.add("Modelo");
      t.add("Color");
      t.add("A?o");
      t.add("Categoria");
      t.add("Telefono");
      t.add("Origen");
      t.add("Destino");
      t.endOfRow();

      cout << "\n\nEl taxi asigando para su viaje es el siguiente: " << endl <<
        endl;

      t.add(to_string(valOrden));
      t.add(to_string(taxis.at(i)));
      t.add(nombresComConductores.at(i));
      t.add(placas.at(i));
      t.add(marcasVehiculos.at(i));
      t.add(modelosVehiculos.at(i));
      t.add(colorVehiculos.at(i));
      t.add(to_string(yearsVehiculos.at(i)));
      t.add(catsVehiculos.at(i));
      t.add(vnTels.at(i));
      t.add(origen);
      t.add(destino);
      t.endOfRow();
      t.setAlignment(2, TextTable::Alignment::RIGHT);
      cout << t;
    } catch (std::exception) {
      cout << "Error, no se pueden mostrar Taxi Solicitado." << endl;
    }
  }

  //Tabla Taxis en Ruta
  void pTRuta() {
    try {
      //Creacion del HEAD en la tabla de Datos.
      TextTable t('-', '|', '+');
      t.add("Orden"); //ok
      t.add("ID"); //ok
      t.add("Nombre Condutor"); //ok
      t.add("# de Placa"); //ok
      t.add("# de Motor");
      t.add("Marca");
      t.add("Modelo");
      t.add("Color");
      t.add("A?o");
      t.add("Categoria");
      t.add("Dui");
      t.add("ISSS");
      t.add("Telefono");
      t.add("Direccion");
      t.add("Origen");
      t.add("Destino");
      t.endOfRow();

      for (int i = 0; i < nA_taxis.size(); i++) {
        t.add(to_string(nA_Orden.at(i)));
        t.add(to_string(nA_taxis.at(i)));
        t.add(nA_nombresComConductores.at(i));
        t.add(nA_placas.at(i));
        t.add(nA_numeroMotores.at(i));
        t.add(nA_marcasVehiculos.at(i));
        t.add(nA_modelosVehiculos.at(i));
        t.add(nA_colorVehiculos.at(i));
        t.add(to_string(nA_yearsVehiculos.at(i)));
        t.add(nA_catsVehiculos.at(i));
        t.add(nA_vDuis.at(i));
        t.add(to_string(nA_vISSS.at(i)));
        t.add(nA_vnTels.at(i));
        t.add(nA_vDireccionCon.at(i));
        t.add(nA_Origen.at(i));
        t.add(nA_Destino.at(i));
        t.endOfRow();
      }
      t.setAlignment(2, TextTable::Alignment::RIGHT);
      cout << t;
    } catch (std::exception) {
      cout << "Error, no se pueden mostrar los Taxis Ruta." << endl;
    }
  }

  //Tabla de Taxis Disponibles
  void pTDisponibles()

  {
    try {
      //Creacion del HEAD en la tabla de Datos.
      TextTable t('-', '|', '+');
      t.add("Orden"); //ok
      t.add("ID"); //ok
      t.add("Nombre Condutor"); //ok
      t.add("# de Placa"); //ok
      t.add("# de Motor");
      t.add("Marca");
      t.add("Modelo");
      t.add("Color");
      t.add("A?o");
      t.add("Categoria");
      t.add("Dui");
      t.add("ISSS");
      t.add("Telefono");
      t.add("Direccion");
      t.add("Ingresado");
      t.endOfRow();

      for (int i = 0; i < taxis.size(); i++) {
        if (v_Estado[i] == "_A") {
          t.add(to_string(v_Orden.at(i)));
          t.add(to_string(taxis.at(i)));
          t.add(nombresComConductores.at(i));
          t.add(placas.at(i));
          t.add(numeroMotores.at(i));
          t.add(marcasVehiculos.at(i));
          t.add(modelosVehiculos.at(i));
          t.add(colorVehiculos.at(i));
          t.add(to_string(yearsVehiculos.at(i)));
          t.add(catsVehiculos.at(i));
          t.add(vDuis.at(i));
          t.add(to_string(vISSS.at(i)));
          t.add(vnTels.at(i));
          t.add(vDireccionCon.at(i));
          t.add(v_Fecha.at(i));
          t.endOfRow();
        }
      }
      t.setAlignment(2, TextTable::Alignment::RIGHT);
      cout << t;
    } catch (std::exception) {
      cout << "Error, no se pueden mostrar los Taxis Disponibles." << endl;
    }
  }

  //se crea el metodo para imprimir nuestros datos por medio de la clase TexTable.
  void printTable(vector < int > taxis, vector < string > conductores, vector < string > placas) {
    try {
      //Creacion del HEAD en la tabla de Datos.
      TextTable t('-', '|', '+');
      t.add("Orden");
      t.add("ID");
      t.add("Nombre Condutor");
      t.add("# de Placa");
      t.endOfRow();

      //se recorre el vector de los datos alamcenados
      for (int i = 0; i < taxis.size(); i++) {
        t.add(to_string(i));
        t.add(to_string(taxis.at(i)));
        t.add(conductores.at(i));
        t.add(placas.at(i));
        t.endOfRow();
      }
      t.setAlignment(2, TextTable::Alignment::RIGHT);
      cout << t;
    } catch (std::exception) {
      cout << "Error, no se pueden mostrar los Datos." << endl;
    }
  }
};
