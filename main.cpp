#include <iostream>
#include "LinkedList.hpp"
#include "Banco.hpp"
using namespace std;

void opcionInicioFin() {
    cout << "--Ingrese el 1 si quiere iniciar el juego\n";
    cout << "--Ingrese otro número si quiere finalizar el programa\n";
    string respuesta;
    cin >> respuesta;
    if(respuesta == "1") {
        Banco banco = Banco();
        string palabra = banco.palabraRandom();
        cout<<palabra<<endl;
    }
    else {
        cout << "Gracias por jugar\nFin del programa" << endl;
    } 
}

int main(){
    cout<<"´¨*Bienvendio a WORDLE en VS code*¨´"<<endl;
    opcionInicioFin();
}

