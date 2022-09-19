#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Node {
    public:
        char value;
        Node* next;
        string color = "blanco";

        Node(char value) {
            this->value = value;
            this->next = NULL;
        }
        
};

class LinkedList {
    public:
        Node* head = NULL;

        void add_at_head(char value) {
            Node* new_node = new Node(value);
            if (this->head == NULL) {
                this->head = new_node;    
            }
            else {
                new_node->next = this->head;
                this->head = new_node;
            }
        }

        void traverse() {
            Node* curr = this->head;
            //curr = this->head;

            while(curr != NULL) {
                std::cout << curr->value << " -> " ;
                curr = curr->next;
            }
            cout<<endl;
        }

        void add_at_end(char value) {
            Node* new_node = new Node(value);
            Node* curr = this->head;

            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = new_node;
        }

        void compararlistas(LinkedList entrada) {
            Node* curr_rand = this->head; 
            Node* curr_entr = entrada.head;

            int i;
            int j = 1;
            while(curr_entr != NULL) {
                i = 1;
                curr_rand = this->head;
                while(curr_rand != NULL) {
                    if(curr_entr->value == curr_rand->value and i == j) {
                        curr_entr->color = "verde";
                        break;
                    }
                    else if(curr_entr->value == curr_rand->value and i !=j) {
                        if( curr_entr->color == "verde"){
                            break;
                        }
                        else{
                            curr_entr->color = "amarillo";
                        }
                    }
                    curr_rand = curr_rand->next;
                    i++;
                }
                curr_entr = curr_entr->next;
                j++;
            }
        }

        int size() {
            int sz = 0;
            Node* curr = this->head;
            while (curr != NULL) {
                sz++;
                curr = curr->next;
            }
            return sz;
        }

        void printearColor() {
            Node* curr = this->head;
            while (curr != NULL) {
                cout << curr->value << " " << curr->color << endl;
                curr = curr->next;
            }
        }

        bool resultado() {
            Node* curr = this->head;
            int sz = this->size();
            int cont = 0;
            while(curr != NULL) {
                if(curr->color == "verde") {
                    cont++;
                }
                curr = curr->next;
            }
            if(cont == sz) {
                return true;
            }
            else {
                return false;
            }
        }
};