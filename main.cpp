#include <iostream>
#include "LinkedList.hpp"
#include "Banco.hpp"
using namespace std;

LinkedList pasar_a_lista(string palabra) {
    LinkedList ll;
    char palabra_arr[palabra.length()];
    strcpy(palabra_arr, palabra.c_str());

    for(int i = 0; i < palabra.length(); i++) {
        ll.add_at_head('A');
    }

    ll.head->value = palabra_arr[0];
    Node* curr = ll.head->next;
    int i = 1;
    while(curr != NULL && i <= palabra.length()) {
        curr->value = palabra_arr[i];
        curr = curr->next;
        i++;
    }
    return ll;
}


void opcionInicioFin() {
    cout << "--Ingrese el 1 si quiere iniciar el juego\n";
    cout << "--Ingrese otro número si quiere finalizar el programa\n";
    string respuesta;
    cin >> respuesta;
    
    if(respuesta == "1") {
        Banco banco = Banco();
        string p_random = banco.palabraRandom();
        cout << "La palabra tiene " << "["<<p_random.length()<<"]"<< " caracteres" << endl;
        LinkedList ll_random = pasar_a_lista(p_random);
        string intento;

        for (int i = 1 ; i < 7 ; i++) {
            cout<<"Digite su intento #" << i << ": " <<endl;
            cin>>intento;
            LinkedList ll_intento =  pasar_a_lista(intento);
            ll_random.compararlistas(ll_intento);
            ll_intento.printearColor();
            if(ll_intento.resultado()) {
                cout<<"FELICIDADES, GANASTE!!!!!!!!!!!!!"<<endl;
                break;
            }
            else if (i == 6 and ll_intento.resultado() == false) {
                cout<<"HAS PERDIDO, INTENTA DE NUEVO!" << endl;
            }
        }
        cout << "FINALIZÓ EL JUEGO, MUCHAS GRACIAS" << endl;
    }

    else {
        cout << "Vuelve pronto\nFin del programa..." << endl;
    } 
}


int main(){
    cout<<"´¨*Bienvendio a WORDLE en VS code*¨´"<<endl;
    opcionInicioFin();
}

