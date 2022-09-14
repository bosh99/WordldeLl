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
        //!ll_random.traverse();
        
    }
    else {
        cout << "Gracias por jugar\nFin del programa" << endl;
    } 
}
int main(){
    cout<<"´¨*Bienvendio a WORDLE en VS code*¨´"<<endl;
    opcionInicioFin();

/*
    LinkedList ll;
    char a = 'a';
    char b = 'b';
    char c = 'c';
    ll.add_at_head(a);
    ll.add_at_end(b);
    ll.add_at_end(c);
*/  

    
}

