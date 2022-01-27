#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main(){
  map<int,pair<int,vector<string>>> mp;
  //int - score
  //pair<int, vector<string>>>
    // int - number f people who got the score
    //vector<string> - string of names who got that score

  //file logic
  ifstream file;
  file.open("scorename.txt");

  int count;
  string name;
  while(!file.eof()){
    file >> count;
    getline(file, name);
    mp[count].first++;
    mp[count].second.push_back(name.substr(1));//remove first Space character from names
  }

  for(int i = 0; i < mp.size(); i++){
    cout << i; //using i to print scores
    for(int j = 0; j < mp[i].first; j++)
      cout << 'x';
    cout << endl;
  }

  int score_input;
  cout << "Of which score would you like to see the names of?";
  cin >> score_input;

  for(auto i : mp[score_input].second)
    cout << i << endl; //was not working with ", " so have ot use endl;

  return 0;
}
