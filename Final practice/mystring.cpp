#include
class mystring
{
  public:
  typedef std::size_t size_type;
  mystring(); // default constructor, creates the empty string
  mystring(const mystring &); // copy constructor
  ~mystring(); // destructor
  void operator =(const mystring &); // assignment operator
  void operator +=(char c); // the letter c has been added to the RIGHT of this mystring
  size_type find_first_of(const mystring & source);
  // returns the leftmost position in this mystring that contains a character in source
  // if no characters in source appear in this mystring, return len
  private:
  size_type len; // number of characters in this mystring
  char *data; // data points to a dynamic memory block of len bytes
  // data[0], data[1], ..., data[len-1] are the characters
  // in this mystring, reading from LEFT to RIGHT
  // NOTE: all array elements are used
};

mystring::mystring(){
  len = 0;
  data = new char[len];
}

mystring::mystring(const mystring &m){
  len = m.len;
  data = new char[len];
  for(int i = 0; i< len; i++ )
    data[i] = m.data[i];
}

mystring::~mystring(){
  delete [] data;
}

void mystring::operator =(const mystring &ms){
  if(this==&ms)
    return;
  //deep copy method
  delete [] data;
  len = b.len;
  data_ = new size_type[len];
  for(std::size_t i = 0; i < len; i++)
    data[i] = ms.data[i];
}

void mystring::operator +=(char c){
  char *tmp = new char[len+1];
  for(std::size_t i = 0; i < len+1; i++)
    tmp[i] = data[i];
  tmp[len] = c;
  len++;
  delete [] data;
  data = tmp;
}


size_type mystring::find_first_of(const mystring & source){
  size_type i;
  for(i = 0; i < len; i++){
    for(size_type j = 0; j < source.len; j++){
      if(data[i] == source.data[i])
        return i;
    }
  }
  return i;
}
