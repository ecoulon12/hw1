/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include "split.h"
#include <iostream>
#include<ostream>

using namespace std;

Node* create_in();
void printLL(Node* h);

int main(int argc, char* argv[])
{
    Node* h = create_in();
    Node* odds = nullptr;
    Node* evens = nullptr;
    
    cout << endl << "in" << endl;
    printLL(h);  // Print the original list after calling create_in()
split(h, odds, evens);  // Uncomment this line to split the list into odds and evens
    cout << endl << "odds" << endl;
    printLL(odds);
    cout << endl << "evens" << endl;
    printLL(evens);

    // Free the memory allocated for the nodes
    Node* cur = h;
    while (cur != nullptr) {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }

    return 0;
}

Node* create_in() {
    Node* h = nullptr;
    Node* cur = nullptr;

    for (int i = 0; i < 1; i++) {
        Node* new_node = new Node(i + 1, nullptr);

        if (h == nullptr) {
            h = new_node;
            cur = h;
        } else {
            cur->next = new_node;
            cur = new_node;
        }
    }

    return h;
}

void printLL(Node* h) {
    Node* current = h;
    
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }

    std::cout << std::endl;    
}