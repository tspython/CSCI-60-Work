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
      vs.push_back(word); //need duplicates to count
  }

  file.close();

  ofstream out("p1bout.txt");

  //alphabetical sort
  sort(vs.begin(), vs.end());

  int count = 0;
  string words2 = vs[0];
  //counting logic
  for(auto i:vs){
    if(i == words2)
      count++;
    else{
      out << words2 << ": " << count << endl;
      words2 = i;
      count = 1;
    }
  }

  return 0;
}
