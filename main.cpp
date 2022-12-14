#include <iostream>
#include <cctype>
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

    ll.head->value = toupper(palabra_arr[0]);
    Node* curr = ll.head->next;
    int i = 1;
    while(curr != NULL && i <= palabra.length()) {
        curr->value = toupper(palabra_arr[i]);
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

        int i = 1;
        while(i<7) {
            cout<<"Digite su intento #" << i << ": " <<endl;
            cin>>intento;
            if(intento.length() == p_random.length()) {
                LinkedList ll_intento =  pasar_a_lista(intento);
                ll_random.compararListas(ll_intento);
                ll_intento.printearColor();
                if(ll_intento.resultado()) {
                    cout<<"FELICIDADES, GANASTE!!!!!!!!!!!!!"<<endl;
                    break;
                }
                else if (i == 6 and ll_intento.resultado() == false) {
                    ll_random.p_incorrecta();
                    cout << "LA PALABRA ERA: ";
                    ll_random.printearColor();
                    cout << "HAS PERDIDO, INTENTA DE NUEVO!" << endl;
                }
                i++; 
            }
            else {
                cout<<"INGRESE LA PALABRA CON EL NÚMERO DE CARACTERES CORRECTOS"<< " ["<<p_random.length()<<"]" << endl;
            }
        }
        cout << "FINALIZÓ EL JUEGO, MUCHAS GRACIAS" << endl;
    }

    else {
        cout << "Vuelve pronto\nFin del programa..." << endl;
    } 
}


int main(){
    cout<<"´¨*Bienvenido a WORDLE en terminal*¨´"<<endl;
    opcionInicioFin();
}

