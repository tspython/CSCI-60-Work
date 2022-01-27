#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//problem 2
int main(){
  //part A
  set<string> namesa;
  map<string, int> namesb;
  vector<string> namesc;

  ifstream file;
  file.open("lab4.txt");

  string l;
  while(getline(file, l)){
    int count = 0;
    namesa.insert(l);
    namesc.push_back(l);
    count++;
    namesb[l]++;
  }

  file.close();

  ofstream outa("outa.txt");
  ofstream outb("outb.txt");
  ofstream outc("outc.txt");

  for(auto i:namesa)
    outa << i << endl;
  for(auto i:namesb)
    outb << i.second << " " << i.first << endl;
  int c = 0;
  for(auto i:namesc){
    outc << c << " " << i << endl;
    c++;
  }
  //end of Part A
  //[part B]
  cout << "Number of Meals served in 2019: " << c << endl; //using c that counted number already
  cout << "Number of people served in 2019: "<< namesa.size() << endl; //using set size() func to find w/o duplicates # of ppl served

  int total_servings = 0;
  for(auto i:namesb){
    total_servings += i.second;
  }
  cout << "Average number of times someone received our services : " << (float)total_servings/namesa.size() << endl;


  return 0;
}
