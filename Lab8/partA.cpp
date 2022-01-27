#include "node.h"
#include <iostream>
using namespace std;

std::size_t list_index(node * head_ptr, int target){
  int counter = 0;
  for (const node *p = head_ptr; p != nullptr; p = p->link()){
    if(p->data() == target)
      return counter;
    counter++;
  }
  return (size_t)-1;
}

node* list_at(node * head_ptr, std::size_t n){
  int counter = 0;
  for (node *p = head_ptr; p != nullptr; p = p->link()){
    if(counter == n)
      return p;
    counter++;
  }
  return nullptr;
}


int main(){
  node *head = new node(4, nullptr);
  node *tail = head;
  node *temp;
  temp = new node(1, nullptr);
  tail->set_link(temp);
  tail = temp;
  head = new node(1, head);
  head = new node(3, head);
  temp = new node(5, nullptr);
  tail->set_link(temp);
  tail = temp;
  //3 1 4 1 5
  cout << endl;
  cout <<list_index(head, 3) << endl;
  cout <<list_index(head, 1) << endl;
  cout <<list_index(head, 4) << endl;
  cout <<list_index(head, 5) << endl;
  cout <<list_index(head, 6) << endl;
  cout << "listAt test" << endl;
  cout << list_at(head,0) << endl;
  cout << list_at(head,1) << endl;
  cout << list_at(head,2) << endl;
  return 0;
}
