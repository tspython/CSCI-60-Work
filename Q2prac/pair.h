template <typename T1, typename T2>
class pair{
  public:
    T1 first;
    T2 second;
    pair();
    pair(T1 f, T2 s);
};

template <typename T1, typename T2>
pair<T1,T2>::pair(){
  first = T1();
  second = T2();
}

template <typename T1, typename T2>
pair<T1,T2>::pair(T1 f, T2 s){
  first = f;
  second = s;
}

template <typename T1, typename T2>
bool operator <(pair<T1,T2> p1, pair<T1,T2> p2){
  if ((p1.first < p2.first) )
    return true;
  else if(p1.first==p2.first){
    if(p1.second < p2.second){
      return true;
    }
  }
  return false;
}

template <typename T1, typename T2>
std::ostream& operator <<(std::ostream &out, pair<T1,T2> p1){
  out << p1.first << ", " << p1.second ;
  return out;
}
