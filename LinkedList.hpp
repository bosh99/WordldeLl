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

        bool compararlistas(LinkedList entrada) {
            Node* curr_rand = this->head; 
            Node* curr_entr = entrada.head;

            int i;
            int j = 1;
            while(curr_entr != NULL) {
                i = 1;
                while(curr_rand != NULL) {
                    if(curr_entr->value == curr_rand->value and i == j) {
                        curr_entr->color = "verde";
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
};