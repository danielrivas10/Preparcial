/*Un equipo de ingenieros realiza un estudio preliminar sobre la estabilidad de una estructura compuesta por diferentes elementos.
Para cada elemento se registran sus características y tres cargas aplicadas durante diferentes escenarios de prueba.
El programa deberá registrar los elementos, procesar las cargas, calcular el factor de utilización, determinar el estado de seguridad, identificar el elemento más comprometido, simular un incremento de carga y generar un informe final.
El sistema trabajará con un máximo de 10 elementos
*/
#include <iostream>


// Parte 1.
struct Elemento {

    std:: string codigo[9], nombre;
    double longitud, capacidad;
    float carga[3];
    bool estadoSeguridad;
    };

void registrarElemento(Elemento &elemento){
int opcion;

std:: cout <<"Ingresa cuantos elementos colocaras" << std:: endl;
std:: cin >> opcion;

if (opcion <1 || opcion >10){

std:: cout <<"Opcion invalida" << std::endl;


}
else 
// Parte 2
for (int i=0; i<opcion; i++)
{
std:: cout <<"Codigo del elemento: " << elemento.codigo[9] << std:: endl;    
std:: cout <<"Nombre del elemento: " << elemento.nombre << std:: endl;std:: cout <<"Cual es su longitud? " << elemento.longitud << std:: endl;
std:: cout <<"Cuales son sus cargas?: " << elemento.carga[3] << std:: endl;
std:: cout <<"Cual es su capacidad maxima?: " << elemento.capacidad << std:: endl;
}

for(int i=0; i<3; i++)
{

std:: cout << elemento.carga[3] << std:: endl; 

} 

};

//Parte 3


int main (){

void registrarElemento(Elemento &elemento);
    return 0;
}       