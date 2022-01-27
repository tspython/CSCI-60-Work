#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
  set<string> ss;

  //file logic
  ifstream file;
  file.open("gentleseduction.txt");

  string word;
  while(file >> word){
    ss.insert(word);
  }

  file.close();

  ofstream out("p2out.txt");
  for(auto i:ss)
    out << i << endl;

  return 0;
}
