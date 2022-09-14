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
};