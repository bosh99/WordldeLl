#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

class Banco {
    public:
        string bancoRandom[10] = {"PARRA", "LUNA", "ORNITORRINCO", "A", "BALON", "DORITOS", "PUENTE", "COMPUTADOR", "AUTOMOVIL", "EDIFICIO"};
        string bancoAnimales[10] = {"LEON", "ELEFANTE", "TIGRE", "LORO", "CACATUA", "GATO", "MONO", "PERRO", "PAVO", "CHIGUIRO"};
        string bancoProgramacion[10] = {"PYTHON", "JAVA", "HARDWARE", "SOFTWARE", "SCALA", "MOO", "C", "RUBY", "HASKELL", "LINUX"};

        string palabraRandom(){
            srand((unsigned)time(NULL));
            int input;
            cout<<"INGRESA QUE MODO QUIERES JUGAR: "<< endl;
            cout<<"[1] -> PALABRAS RANDOM"<< endl;
            cout<<"[2] -> ANIMALES"<< endl;
            cout<<"[3] -> PALABRAS RELACIONADAS CON PROGRAMACION"<< endl;
            cin>>input;

            if(input==1) {
                string palabra = bancoRandom[(rand()%10)];
                return palabra;
            }
            else if(input==2) {
                string palabra = bancoAnimales[(rand()%10)];
                return palabra;
            }
            else if(input==3) {
                string palabra = bancoProgramacion[(rand()%10)];
                return palabra;
            }
            else {
                cout<<"ERROR EN EL INPUT, SE SELECCIONO UNA PALABRA RANDOM"<<endl;
                string palabra = bancoRandom[(rand()%10)];
                return palabra;
            }
        }
};
