#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

class Banco {
    public:
        string bancoPalabras[10] = {"SARAMPION", "LUNA", "ORNITORRINCO", "A", "BALON", "DORITOS", "PUENTE", "COMPUTADOR", "AUTOMOVIL", "EDIFICIO"}; // Aqupi se le pueden agregar palabras

        // Seleccionar palabra aleatoriamente
        string palabraRandom(){
            srand((unsigned)time(NULL));
            string palabra = bancoPalabras[(rand()%10)];
            cout << "La palabra tiene " << "["<<palabra.length()<<"]"<< " caracteres" << endl;
            return palabra;
        }
};