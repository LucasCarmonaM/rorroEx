#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <omp.h>

using namespace std;


int main(int argc, char** argv ){
    //Lectura de primer archivo csv -> smi.csv
    //Inicialización de variables

    std::ifstream leerDesde;
    std::string linea = "inicio";
    std::string word = "";
    leerDesde.open(argv[1]);
    std::vector<int>  contadorhora;
    std::vector<int> horarios;
    int vectorcont[23];
    int valor= 0;
    for(int i=0; i<24;i++){
        vectorcont[i]=0;
    }

    // Control de error, en caso de que falle el path
    if(leerDesde.fail()){
        std::cout << "El path de la ruta del archivo /archivo.log es erroneo, porfavor verificar "  << '\n';
        std::exit(1);
    }

    #pragma omp parallel
    {
    #pragma omp while
    while(!leerDesde.eof()){
            #pragma omp single private(linea,word,valor)
            {
            std::getline(leerDesde, linea);
            std::stringstream datosEnProceso(linea);
            std::getline(datosEnProceso, word, ':');
            std::getline(datosEnProceso, word, ':');
            std::stringstream datos(word);
            stringstream ss;  
            ss << word;  
            ss >> valor; 
            #pragma omp atomic
            vectorcont[valor] = vectorcont[valor] + 1;
            }
    }
    }   
    // Muestra de datos y resultados 
    // cout << "                         === Resultados de divisa segun año === " << endl;
        for(int i = 0;i< 24;i++){
        cout << i << " contador  "  << vectorcont[i] <<  endl;
    }
    // cout << "                                 === Resultado === " << endl;
    // cout << "                      La funcion de regresion es y = "  << m << "x " << b  << endl;
    // cout << "                                 === Integrantes === " << endl;
    // cout << "                             Rodrigo Andres Estay Poblete " << endl;
   

}
