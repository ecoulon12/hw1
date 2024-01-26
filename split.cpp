#include "split.h"

void push_back(Node*& head, int value);

void split(Node*& in, Node*& odds, Node*& evens)
{
  if (in == nullptr) {
    return;
  }

  int val = in->value;
  Node* next = in->next;

  if (val % 2) { // if val is odd
    if (odds == nullptr) { //there is nothing in odds yet
      odds = in;  // set the front of odds to in
      in->next = nullptr; //set the end of t
    } else {
      in->next = odds->next;
      odds->next = in;
    }
    split(next, odds->next, evens);  
  } else {
    if (evens == nullptr) {
      evens = in;
      in->next = nullptr;
    } else {
      in->next = evens->next;
      evens->next = in;
    }
    split(next, odds, evens->next);  
  }
  in = nullptr;
}
