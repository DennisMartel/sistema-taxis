#include <iostream> //biblioteca est?ndar (STL) del lenguaje de programaci?n C++

#include <string>

#include <iomanip>

#include <conio.h>

#include <vector> //importamos libreria de vectores

#include <cmath>

#include <ctime>

#include <stdlib.h>  //funcion para usar new y delete

#include <algorithm> //para poder ordenar arregos con sort y utras funciones necesarias

#define PI 3.14159265

#include <locale.h>

#include <windows.h>

#include <sstream>

using namespace std;

class Funciones {

  public:
    Funciones() {}

  //Metodo para Convertidor a mayusculas
  void Mayusculas(string & entrada) {
    for (int i = 0; i < entrada.size(); i++) {
      entrada[i] = towupper(entrada[i]);
    }
  }

  //Funcion para validar Entero
  bool valEntero(string entrada) {
    try {
      //si no ingresa ningun valor cae aca
      if (entrada.size() == 0) {
        return false; //returna falso para que usuario ingrese el dato solicitado
        //valida que el dato ingresado contenga al menos 1 digito y que sea diferente a un digito
      } else if (entrada.size() == 1 && !isdigit(entrada[0])) {
        return false;
      } else {
        int inicio;
        //Valida que si hay un signo al principio empiece despues del signo
        if (entrada[0] == '+' || entrada[0] == '-') {

          inicio = 1;
        } else {
          //sino hay signo empieza de 0
          inicio = 0;
          //mientras Datos sean mayores a 0 genera el bucle
          while (inicio < entrada.size()) {
            //valida cada digito si es diferente a un digito(para dejar pasar solo numeros), retorna falso(para que el bucle continue arriba)
            if (!isdigit(entrada[inicio])) {
              return false;
              break;
            }
            //genera los ciclos para cada digito
            inicio++;
          }
        }
      }
      //cuando se completan las validaciones retorna verdadero
      //para entrar en la primer condicional que esta validando el dato de entrada arriba en el "if"
      return true;
    } catch (std::exception) {
      cout << "Error, validando tipo de dato Entero" << endl;
    }
  }

  //Funcion para aceptar solo Letras
  bool valLetras(string entrada) {
    try {
      //valida que haya algun dato ingresado
      if (entrada.size() == 0) {
        return false; //returna false para caer en la condicion 2 de la estructura condicional de la estructura que se esta validando
        //valida que dato ingresado contenga al menos 1 dato y que sea diferente a un digito
      } else {
        int inicio = 0;
        //mientras Datos sean mayores a 0 genera el bucle
        while (inicio < entrada.size()) {
          //valida cada digito si es diferente al alfabeto, retorna falso(para que el bucle continue arriba)
          if (!isalpha(entrada[inicio])) {
            return false;
            break;
          }
          //genera los ciclos para cada digito
          inicio++;
        }
      }
      //cuando se completan las validaciones retorna verdadero
      //para entrar en la primer condicional que esta validando el dato de entrada arriba en el "if"
      return true;
    } catch (std::exception) {
      cout << "Error, validando tipo de entrada Letras" << endl;
    }
  }

  //funcion para ingresar solo letras y espacios para Nombres Completos
  bool valNombres(string entrada) {
    try {
      //valida que haya algun dato ingresado
      if (entrada.size() == 0) {
        return false; //returna false para caer en la condicion 2 de la estructura condicional de la estructura que se esta validando
        //valida que dato ingresado contenga al menos 1 dato y que sea diferente a un digito
      } else {
        int inicio = 0;
        //mientras Datos sean mayores a 0 genera el bucle
        while (inicio < entrada.size()) {
          //valida cada digito si es diferente al alfabeto, retorna falso(para que el bucle continue arriba)
          if (!isalpha(entrada[inicio]) && !isspace(entrada[inicio])) {
            return false;
            break;
          }
          //genera los ciclos para cada digito
          inicio++;
        }
      }
      //cuando se completan las validaciones retorna verdadero
      //para entrar en la primer condicional que esta validando el dato de entrada arriba en el "if"
      return true;
    } catch (std::exception) {
      cout << "Error, validando tipo de entrada Letras" << endl;
    }
  }

  //Funcion para validar Placa
  bool validarPlaca(string entrada) {
    try {
      if (isalpha(entrada[0]) && entrada[1] == '-' && entrada[2] >= '1' && entrada.size() <= 8) {
        int inicio = 2;
        //mientras Datos sean mayores a 0 genera el bucle
        while (inicio < entrada.size()) {
          //valida cada digito si es diferente a un digito(para dejar pasar solo numeros), retorna falso(para que el bucle continue arriba)
          if (!isdigit(entrada[inicio])) {
            return false;
            break;
          } else {
            return true;
          }
          //genera los ciclos para cada digito
          inicio++;
        }
      } else {
        return false;
      }
      //cuando se completan las validaciones retorna verdadero
      //para entrar en la primer condicional que esta validando el dato de entrada arriba en el "if"
      return true;
    } catch (std::exception) {
      cout << "Error, validando tipo de entrada Letras" << endl;
    }
  }

  //Funcion para validar formato Dui XXXXXXXX-X
  bool validarDui(string entrada) {
    try {
      if (entrada[8] == '-' && entrada.size() == 10) {
        int inicio = 0;
        //mientras Datos sean mayores a 0 genera el bucle
        while (inicio < entrada.size()) {
          //valida cada digito si es diferente a un digito(para dejar pasar solo numeros), retorna falso(para que el bucle continue arriba)
          if (inicio <= 7) {
            if (!isdigit(entrada[inicio])) {
              return false;
              break;
            }
          } else if (inicio > 8) {
            if (!isdigit(entrada[inicio])) {
              return false;
              break;
            }
          } else if (inicio == entrada.size()) {
            return true;
          }
          //genera los ciclos para cada digito
          inicio++;
        }
      } else {
        return false;
      }
      //cuando se completan las validaciones retorna verdadero
      //para entrar en la primer condicional que esta validando el dato de entrada arriba en el "if"
      return true;
    } catch (std::exception) {
      cout << "Error, validando tipo de entrada Letras" << endl;
    }
  }

  //realiza una busqueda de comparacion dentro del vector entero
  bool checkForItemInt(vector < int > arr, int data) {
    try {
      //realiza una iteracion dato por dato
      for (int i = 0; i < arr.size(); i++) {
        //valida cada dato si es igual al que se esta ingresando
        if (arr[i] == data) {
          cout << "\nDato registrado en la posicion [" << i << "].\nPorfavor ingrese otro valor.\n";
          return true;
        }
      }
      return false;
    } catch (std::exception) {
      cout << "Error, no puede realizarse la comparacion de valor ingresado" << endl;
    }
  }

  //realiza una busqueda de comparacion dentro del vector cadena
  bool checkForItemInt(vector < string > arr, string data) {
    try {
      for (int i = 0; i < arr.size(); i++) {
        if (arr.at(i) == data) {
          cout << "\nDato registrado en la posicion [" << i << "].\nPorfavor ingrese otro valor.\n";
          return true;
        }
      }
      return false;
    } catch (std::exception) {
      cout << "Error, no puede realizarse la comparacion de valor ingresado" << endl;
    }
    //retorna falso despues de la iteracion para salir del bucle
  }

  //Funcion para validar formato Telefono XXXX-XXXXX
  bool validarTel(string entrada) {
    try {
      if (entrada[4] == '-' && entrada.size() == 9) {
        int inicio = 0;
        //mientras Datos sean mayores a 0 genera el bucle
        while (inicio < entrada.size()) {
          //valida cada digito si es diferente a un digito(para dejar pasar solo numeros), retorna falso(para que el bucle continue arriba)
          if (inicio <= 3) {
            if (!isdigit(entrada[inicio])) {
              return false;
              break;
            }
          } else if (inicio > 4) {
            if (!isdigit(entrada[inicio])) {
              return false;
              break;
            }
          } else if (inicio == entrada.size()) {
            return true;
          }
          //genera los ciclos para cada digito
          inicio++;
        }
      } else {
        return false;
      }
      //cuando se completan las validaciones retorna verdadero
      //para entrar en la primer condicional que esta validando el dato de entrada arriba en el "if"
      return true;
    } catch (std::exception) {
      cout << "Error, validando tipo de entrada Letras" << endl;
    }
  }

  //Funcion para validar datos alfanumericos
  bool validarAlfaNumeros(string entrada) {
    try {
      int i = 0;
      if (entrada.size() > 0 && entrada.size() <= 15) {
        while (i < entrada.size()) {
          if (isalnum(entrada[i])) {
            i++;
          } else {
            return false;
            break;
          }
        }
      } else {
        return false;
      }

      //cuando se completan las validaciones retorna verdadero
      //para entrar en la primer condicional que esta validando el dato de entrada arriba en el "if"
      return true;
    } catch (std::exception) {
      cout << "Error, validando tipo de entrada Letras" << endl;
    }
  }

  //funcion para convertir grados a radianes
  double rad(double & dato) {
    return dato * PI / 180;
  }

  //funcion para medir la distancia en km del origne al destino
  double convertirDistancia(double latOrigen, double longOrigen, double latDestino, double longDestino) {

    double rTierra = 6378.137; // radio de la tierra en kilometros
    double dLatrest = latDestino - latOrigen;
    double dLongrest = longDestino - longOrigen;

    double dLat = rad(dLatrest);
    double dLong = rad(dLongrest);

    double eqxu = sin(dLat / 2) * sin(dLat / 2) + cos(rad(latOrigen)) * cos(rad(latDestino)) * sin(dLong / 2) * sin(dLong / 2);
    double eqyu = 2 * atan2(sqrt(eqxu), sqrt(1 - eqxu));

    return rTierra * eqyu;
  }

  //devuelve la posicion en el vector
  int id_position(vector < int > & taxis, int id) {
    try {

      for (int i = 0; i < taxis.size(); i++) {
        if (taxis.at(i) == id) {
          return i;
          break;
        } //if
      } //for
      return -1;
    } catch (std::exception) {}
  }

  //devuelve el valor del id
  int id_valReingreso(vector < int > nA_taxis, int id) {
    try {

      for (int i = 0; i < nA_taxis.size(); i++) {
        if (nA_taxis.at(i) == id) {
          return nA_taxis[i];
          break;
        } //if
      } //for
      return -1;
    } catch (std::exception) {}
  }

  //devuelve el id
  int id_valorSelcted(vector < string > v_Estado, string _Estado, vector < string > catsVehiculos, string & p_categoria) {
    try {

      if (p_categoria == "EJECUTIVA" || p_categoria == "TRADICIONAL") {
        for (int i = 0; i < catsVehiculos.size(); i++) {
          if (catsVehiculos.at(i) == p_categoria && v_Estado.at(i) == _Estado) {
            return i;
            break;
          } //if
        } //for

      } //if
      return -1;
    } catch (std::exception) {}
  }
};
