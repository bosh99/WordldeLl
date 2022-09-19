#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

class Banco {
    public:
        string bancoPalabras[10] = {"PARRA", "LUNA", "ORNITORRINCO", "A", "BALON", "DORITOS", "PUENTE", "COMPUTADOR", "AUTOMOVIL", "EDIFICIO"}; // Aqui se le pueden agregar palabras

        // Seleccionar palabra aleatoriamente
        string palabraRandom(){
            srand((unsigned)time(NULL));
            string palabra = bancoPalabras[(rand()%10)];
            return palabra;
        }
};