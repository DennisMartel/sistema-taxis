#include <iostream> //biblioteca est?ndar (STL) del lenguaje de programaci?n C++

#include <string>

#include <iomanip>

#include <conio.h>

#include <vector> //importamos libreria de vectores

#include <cmath>

#include <ctime>

#include <stdlib.h>  //funcion para usar new y delete

#include <algorithm> //para poder ordenar arregos con sort y utras funciones necesarias

#include <locale.h>

#include <windows.h>

#include <fstream>

#include <sstream>

using namespace std;

class Transac_Log {

  private:
    int id;
  string con_nombre;
  string num_placa;
  string num_motor;
  string car_marca;
  string car_modelo;
  string car_color;
  int car_year;
  string car_categoria;
  string con_dui;
  int con_isss;
  string con_tel;
  string con_direccion;
  string origen;
  string destino;
  string fecha_viaje;
  double cobro_viaje;
  string car_estado; //especifica si esta en viaje o no. "on_road" = con viaje, "ended" = viaje finalizado

  public:
    Transac_Log() {}

  string line;
  int line_int;

  //Vectores con Datos de vehiculos y conductores de TRANSANTIONS_LOG
  vector < int > v_TOrden;
  vector < int > v_Tid;
  vector < string > v_Tplacas;
  vector < string > v_TnumMotor;
  vector < string > v_TmarcaVeh;
  vector < string > v_TmodelVeh;
  vector < string > v_TcolorVeh;
  vector < int > v_TyearVeh;
  vector < string > v_TcatVeh;
  vector < string > v_TDuis;
  vector < int > v_TiSSS;
  vector < string > v_TnTels;
  vector < string > v_TnomCon;
  vector < string > v_TDireccionCon;
  vector < string > v_TFecha;
  vector < string > v_TEstado;
  vector < string > v_TOrigen;
  vector < string > v_TDestino;
  vector < double > v_TPrecio;

  void ResetVectores() {
    //Vectores TRANSACTIONS_LOG
    v_TOrden = {};
    v_Tid = {};
    v_TnomCon = {};
    v_Tplacas = {};
    v_TnumMotor = {};
    v_TmarcaVeh = {};
    v_TmodelVeh = {};
    v_TcolorVeh = {};
    v_TyearVeh = {};
    v_TcatVeh = {};
    v_TDuis = {};
    v_TiSSS = {};
    v_TnTels = {};
    v_TDireccionCon = {};
    v_TFecha = {};
    v_TOrigen = {};
    v_TDestino = {};
    v_TPrecio = {};
  }

  void SaveOnVectors() {
    //guardamos en vector los datos de TRANSACTION_LOG.csv
    ifstream iTra("TRANSACTION_LOG.csv");
    if (iTra.is_open()) {
      //ORDEN,ID,NOMBRE,PLACA,MOTOR,MARCA,MODELO,COLOR,YEAR,CATEGORIA,DUI,ISSS,TELEFONO,DIRECCION,FECHA,ESTADO

      while (iTra.good()) {
        //El primer dato de la linea lo saco (en este caso id) y comparo que sea mayor a 0, fue la unica forma con la que pude resolver que no me imprima las lineas en blanco
        getline(iTra, line, ',');
        line_int = atoi(line.c_str());
        if (line.length() != 0) {

          v_TOrden.push_back(line_int);

          getline(iTra, line, ',');
          v_Tid.push_back(atoi(line.c_str()));

          getline(iTra, line, ',');
          v_TnomCon.push_back(line);

          getline(iTra, line, ',');
          v_Tplacas.push_back(line);

          getline(iTra, line, ',');
          v_TnumMotor.push_back(line);

          getline(iTra, line, ',');
          v_TmarcaVeh.push_back(line);

          getline(iTra, line, ',');
          v_TmodelVeh.push_back(line);

          getline(iTra, line, ',');
          v_TcolorVeh.push_back(line);

          getline(iTra, line, ',');
          v_TyearVeh.push_back(atoi(line.c_str()));

          getline(iTra, line, ',');
          v_TcatVeh.push_back(line);

          getline(iTra, line, ',');
          v_TDuis.push_back(line);

          getline(iTra, line, ',');
          v_TiSSS.push_back(atoi(line.c_str()));

          getline(iTra, line, ',');
          v_TnTels.push_back(line);

          getline(iTra, line, ',');
          v_TDireccionCon.push_back(line);

          getline(iTra, line, ',');
          v_TFecha.push_back(line);

          getline(iTra, line, ',');
          v_TOrigen.push_back(line);

          getline(iTra, line, ',');
          v_TDestino.push_back(line);

          getline(iTra, line);
          v_TPrecio.push_back(stod(line));
        }

      } //while
      iTra.close();
    } else {
      //si no existe archivo se crea (cuando se ejecuta por primera vez el programa)
      fstream iTra;
      iTra.open("TRANSACTION_LOG.csv", ios::out);
      iTra.close();
    }
  }

  void Verficar_csv() {
    //si no existe TRANSACTION_LOG lo creamos
    ifstream it("TRANSACTION_LOG.csv");
    if (!it.is_open()) {
      fstream it;
      it.open("TRANSACTION_LOG.csv", ios::out);
      it.close();
    } else {
      it.close();
    }
  }

  //GUARDA EN ARCHIVO CSV LOS DATOS DE ENVIO A RUTA
  void save_TransLog(int valOrden, vector < int > taxis, vector < string > nombresComConductores, vector < string > placas, vector < string > numeroMotores, vector < string > marcasVehiculos,
    vector < string > modelosVehiculos, vector < string > colorVehiculos, vector < int > yearsVehiculos, vector < string > catsVehiculos, vector < string > vDuis, vector < int > vISSS,
    vector < string > vnTels, vector < string > vDireccionCon, string f_reg, string origen, string destino, double precio_viaje, int i) {

    fstream saveTrans_csv;
    saveTrans_csv.open("TRANSACTION_LOG.csv", ios::app);
    saveTrans_csv << valOrden << "," <<
      taxis[i] << "," <<
      nombresComConductores[i] << "," <<
      placas[i] << "," <<
      numeroMotores[i] << "," <<
      marcasVehiculos[i] << "," <<
      modelosVehiculos[i] << "," <<
      colorVehiculos[i] << "," <<
      yearsVehiculos[i] << "," <<
      catsVehiculos[i] << "," <<
      vDuis[i] << "," <<
      vISSS[i] << "," <<
      vnTels[i] << "," <<
      vDireccionCon[i] << "," <<
      f_reg << "," <<
      origen << "," <<
      destino << "," <<
      precio_viaje << "\n";

    saveTrans_csv.close();

  } //termina metodo

  //Tabla de Datos de archivo TRANSACTION_LOG.csv
  void pTRANSACTION_LOG(int idCar, int mes) {
    try {

      //Creacion del HEAD en la tabla de Datos.
      TextTable t('-', '|', '+');
      t.add("Orden"); //ok
      t.add("ID"); //ok
      t.add("Nombre Condutor"); //ok
      t.add("# de Placa"); //ok
      t.add("Marca");
      t.add("Modelo");
      t.add("A?o");
      t.add("Categoria");
      t.add("Dui");
      t.add("Telefono");
      t.add("Direccion");
      t.add("Fecha Ruta");
      t.add("Origen");
      t.add("Destino");
      t.add("Precio");
      t.endOfRow();

      double ingresosT = 0.0;
      int s_mes = -1;
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

      for (int i = 0; i < v_Tid.size(); i++) {
        if (idCar != -1 && mes == -1) {
          //Listado de viajes realizados por un veh?culo especifico.
          if (v_Tid[i] == idCar) {
            t.add(to_string(v_TOrden.at(i)));
            t.add(to_string(v_Tid.at(i)));
            t.add(v_TnomCon.at(i));
            t.add(v_Tplacas.at(i));
            t.add(v_TmarcaVeh.at(i));
            t.add(v_TmodelVeh.at(i));
            t.add(to_string(v_TyearVeh.at(i)));
            t.add(v_TcatVeh.at(i));
            t.add(v_TDuis.at(i));
            t.add(v_TnTels.at(i));
            t.add(v_TDireccionCon.at(i));
            t.add(v_TFecha.at(i));
            t.add(v_TOrigen.at(i));
            t.add(v_TDestino.at(i));
            //creo esto para que pueda imprimir solo 2 decimales, guardando el vador del precio en variable
            //y colocarle un fixed con set precision
            //no uso to_string. porque genera muchos ceros al final
            std::ostringstream capturador_de_dato;
            capturador_de_dato << fixed << setprecision(2) << v_TPrecio.at(i);
            string precio_string = capturador_de_dato.str();
            t.add("$ " + precio_string);
            t.endOfRow();
          }
        } else if (mes != -1 && idCar == -1) {
          //Ingresos totales obtenidos en un mes (especificado al generar el reporte)

          string sub_mes = v_TFecha[i].substr(3, 2);
          s_mes = atoi(sub_mes.c_str());
          if (s_mes == mes) {
            t.add(to_string(v_TOrden.at(i)));
            t.add(to_string(v_Tid.at(i)));
            t.add(v_TnomCon.at(i));
            t.add(v_Tplacas.at(i));
            t.add(v_TmarcaVeh.at(i));
            t.add(v_TmodelVeh.at(i));
            t.add(to_string(v_TyearVeh.at(i)));
            t.add(v_TcatVeh.at(i));
            t.add(v_TDuis.at(i));
            t.add(v_TnTels.at(i));
            t.add(v_TDireccionCon.at(i));
            t.add(v_TFecha.at(i));
            t.add(v_TOrigen.at(i));
            t.add(v_TDestino.at(i));
            //creo esto para que pueda imprimir solo 2 decimales, guardando el vador del precio en variable
            //y colocarle un fixed con set precision
            //no uso to_string. porque genera muchos ceros al final
            std::ostringstream capturador_de_dato;
            capturador_de_dato << fixed << setprecision(2) << v_TPrecio.at(i);
            string precio_string = capturador_de_dato.str();
            t.add("$ " + precio_string);
            t.endOfRow();
            //Iterar y sumar cada precio para el TOTAL DE INGRESO
            ingresosT += v_TPrecio[i];
          }
        } else if (idCar != -1 && mes != -1) {

          string sub_mes = v_TFecha[i].substr(3, 2);
          s_mes = atoi(sub_mes.c_str());
          //Ingresos totales obtenidos en un mes por un veh?culo especifico.
          if (s_mes == mes && v_Tid[i] == idCar) {

            t.add(to_string(v_TOrden.at(i)));
            t.add(to_string(v_Tid.at(i)));
            t.add(v_TnomCon.at(i));
            t.add(v_Tplacas.at(i));
            t.add(v_TmarcaVeh.at(i));
            t.add(v_TmodelVeh.at(i));
            t.add(to_string(v_TyearVeh.at(i)));
            t.add(v_TcatVeh.at(i));
            t.add(v_TDuis.at(i));
            t.add(v_TnTels.at(i));
            t.add(v_TDireccionCon.at(i));
            t.add(v_TFecha.at(i));
            t.add(v_TOrigen.at(i));
            t.add(v_TDestino.at(i));
            //creo esto para que pueda imprimir solo 2 decimales, guardando el vador del precio en variable
            //y colocarle un fixed con set precision
            //no uso to_string. porque genera muchos ceros al final
            std::ostringstream capturador_de_dato;
            capturador_de_dato << fixed << setprecision(2) << v_TPrecio.at(i);
            string precio_string = capturador_de_dato.str();
            t.add("$ " + precio_string);
            t.endOfRow();
            //Para Sacar El Total de Ingresos
            ingresosT += v_TPrecio[i];
          }
        } else if (idCar == -1 && mes == -1) {
          //1) Listado de viajes realizados por cada veh?culo (Todos los veh?culos)
          t.add(to_string(v_TOrden.at(i)));
          t.add(to_string(v_Tid.at(i)));
          t.add(v_TnomCon.at(i));
          t.add(v_Tplacas.at(i));
          t.add(v_TmarcaVeh.at(i));
          t.add(v_TmodelVeh.at(i));
          t.add(to_string(v_TyearVeh.at(i)));
          t.add(v_TcatVeh.at(i));
          t.add(v_TDuis.at(i));
          t.add(v_TnTels.at(i));
          t.add(v_TDireccionCon.at(i));
          t.add(v_TFecha.at(i));
          t.add(v_TOrigen.at(i));
          t.add(v_TDestino.at(i));
          //creo esto para que pueda imprimir solo 2 decimales, guardando el vador del precio en variable
          //y colocarle un fixed con set precision
          //no uso to_string. porque genera muchos ceros al final
          std::ostringstream capturador_de_dato;
          capturador_de_dato << fixed << setprecision(2) << v_TPrecio.at(i);
          string precio_string = capturador_de_dato.str();
          t.add("$ " + precio_string);
          t.endOfRow();
        }
      }
      t.setAlignment(2, TextTable::Alignment::RIGHT);
      cout << t;

      if (mes != -1 && idCar == -1) {
        cout << "\n\nTotal de ingresos Obtenidos en el mes de " << Meses[mes - 1] << ":  $ " << fixed << setprecision(2) << ingresosT << endl <<
          endl;
      } else if (idCar != -1 && mes != -1) {
        cout << "\n\nTotal de ingresos Obtenidos por Taxi ID #: " << idCar << " en el mes de " << Meses[mes - 1] << ":  $ " << fixed << setprecision(2) << ingresosT << endl <<
          endl;
      }
    } catch (std::exception) {
      cout << "Error, no se pueden mostrar los Taxis Disponibles." << endl;
    }
  }
};
