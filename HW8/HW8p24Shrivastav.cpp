#include "node.h"
#include <iostream>
using namespace std;

/*
* Pre: takes in head and tail ptrs
* Post: returns empty linked list
*/
void list_clear(node * & head_ptr, node * &tail_ptr){
  while (head_ptr != nullptr) { //make sure to iterate to end of list
    node* tmp = head_ptr->link(); //using tmp to store next value
    delete head_ptr; // delete the old head
    head_ptr = tmp; //reinitialize to new head and delete
  }
  head_ptr = tail_ptr = nullptr; //EMPTY LIST HAS HEAD AND TAIL = to NULLPTR
}

/*
* Pre: takes in head and tail ptrs
* Post: returns reversed linked list
*/
void list_reverse(node * & head_ptr, node * & tail_ptr){
  node *link_after;
  node *link_before = nullptr; //initially set to nullptr because *p = head;
                                // because head's before is nullptr
  for(node*p=head_ptr; p!=nullptr; p=link_after){
    link_after = p->link();
    p->set_link(link_before);
    link_before = p;
  }
  //reset head and tail_ptr
  node *new_tail = head_ptr;
  head_ptr = tail_ptr;
  tail_ptr = new_tail;
}

int main() {
    node* head = new node(4, nullptr);
    node* tail = head;
    node* temp;
    temp = new node(1, nullptr);
    tail->set_link(temp);
    tail = temp;
    head = new node(1, head);
    head = new node(3, head);
    temp = new node(5, nullptr);
    tail->set_link(temp);
    tail = temp;

    for(node*p=head; p!=nullptr; p=p->link()){
      cout << p->data() << " ";
    }
    cout << endl;
    //3 1 4 1 5

    list_reverse(head, tail);
    //5 1 4 1 3
    for(node*p=head; p!=nullptr; p=p->link()){
      cout << p->data() <<  " ";
    }
    cout << endl;

    list_clear(head, tail);
    // try to print but will print nothing
    for(node*p=head; p!=nullptr; p=p->link()){
      cout << p->data() <<  " ";
    }
    cout << endl;
}
