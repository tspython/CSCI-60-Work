#include "lbiguint.h"
#include "node.h"
#include <cassert>
#include <sstream>

lbiguint::lbiguint(){
     tail = head = new node(0 , nullptr);
 }

 lbiguint::lbiguint (const std::string & s){
   tail = head = new node( s[0] -'0', nullptr); //need to do char arithmetic

   for (int i = 1; i < s.size(); i++)
     head = new node(s[i] - '0', head);
 }

lbiguint::~lbiguint(){
  for (node *p = head; p != nullptr; p = head){
    node *temp = head->link();
    delete head;
    head = temp;
  }
  head = nullptr;
  tail = nullptr;
}

std::size_t lbiguint::size() const{
  std::size_t size = 0;
  for (node* p = head; p!= nullptr; p = p->link()){
    size++;
  }
  return size;
}

int lbiguint::operator [](std::size_t pos) const{
  int index = 0;
  for (node* p = head; p!= nullptr; p = p->link()){
    if (index == pos){
      return p->data();
    }
    index++;
  }
  return 0;
}

std::ostream & operator << (std::ostream & out, const lbiguint & l){
  for (int i = l.size()-1; i >= 0; i--){
    out << l[i];
  }
  return out;
}

void lbiguint::operator =(const lbiguint & lb){
  //check if they are the same size to use the same nodes
  if(size() < lb.size()){ //need to create new nodes
    node *tmp = head;
    for(node *p = lb.head; p!=nullptr; p=p->link()){
      tmp->set_data(p->data()); //change data to what is in lb
      //check if we are at the end of this lbiguint and we need to creat new nodes
      if(tmp->link() == nullptr && p->link() != nullptr){
          node* tailtmp = new node();
          tail->set_link(tailtmp);
          tail = tailtmp;
      }
      //reset temp to next node
      tmp = tmp->link();
    }
  }
  //else we need to delete/not delete nodes if same size
  else{
    node *tmp = lb.head;
    //need to use this lbiguint's head because it oculd be greater size
    //but if it is equal it doesn't matter
    for(node *p = head; p!=nullptr; p=p->link()){
      p->set_data(tmp->data());
      //check if we are at the end of lb
      if(tmp->link() != nullptr)
        tmp = tmp->link(); // move to next node
      else{
        //need to delete extra ndoes that are not needed
        tail = p; //current node is the new tail
        tail->set_link(nullptr); //reset tail link to nullptr because currently p wouldn't have that
        node* end_nodes_delete = p->link();
        //start at the node we need to delete, and reset to that node because
        //we need to delete the current node, before moving on
        for(node *n = end_nodes_delete; n!=nullptr; n = end_nodes_delete){
          end_nodes_delete = n->link(); //move it to the next node;
          delete n;
        }
        return; //need to exit function after deleting extra nodes
      }
    }
  }
}

/*
int main(){
  lbiguint l = lbiguint("123456789");
  std::cout << l.size() << std::endl;
  std::cout << l[0] << std::endl;
  std::cout << l[1] << std::endl;
  std::cout << l[8] << std::endl;
  std::cout << l[10] << std::endl;
  std::cout << l << std::endl;
  return 0;
}
*/
