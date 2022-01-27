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
   for(node* p = tail; p!=nullptr; p = p->link()){
     node* tmp = tail->link();
     delete tail;
     tail = tmp;
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
  return -1;
}

std::ostream & operator << (std::ostream & out, const lbiguint & l){
  for (int i = l.size()-1; i >= 0; i--){
    out << l[i];
  }
  return out;
}

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
