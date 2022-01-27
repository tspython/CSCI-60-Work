#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
  vector<string> vs;

  //file logic
  ifstream file;
  file.open("gentleseduction.txt");

  string word;
  while(file >> word){
    if( find(vs.begin(), vs.end(), word) == vs.end()) //logic to add only unique words
      vs.push_back(word);
  }

  file.close();

  ofstream out("p1out.txt");

  //alphabetical sort
  sort(vs.begin(), vs.end());

  //remove duplicates
  //unique(vs.begin(), vs.end());

  for(auto i:vs){
    out << i << endl;
  }

  return 0;
}
