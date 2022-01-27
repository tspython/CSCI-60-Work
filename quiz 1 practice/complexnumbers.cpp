#include <iostream>

class cn{
  private:
    int a;
    int b;
  public:
    cn();
    cn(int ai, int bi);

    int get_a(){
      return a;
    }

    int get_b(){
      return b;
    }
};

cn::cn(){
  a = 0;
  b = 0;
}

cn::cn(int ai, int bi){
  a = ai;
  b = bi;
}

int cn::magnitude(){
  return sqrt(a^2 + b^2) ;
}

cn operator +(cn c, cn d){
  cn e = cn((c.get_a() + d.get_a()), c.get_b() + d.get_b()) )
  return e;
}

void operator ==(cn c, cn d){
  if(d.get_a() == cn.get_a() && d.get_b() == cn.get_b())
    return true;
  return false;
}

std::ostream& operator<<(ostream& out){
  out<<a<<"+"<<b<<"i";
  return out;
}
