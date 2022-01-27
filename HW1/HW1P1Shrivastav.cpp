/*
  Filename: HW1P1Shrivastav.cpp
  Course: CSCI 60
  Author: Tushar Shrivastav
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//prototype
void writeletter(string names[], int size, ofstream& out);
void writeToFile(string names[], int size, char first_letters, ofstream& out);

//main
int main(){
  //variables
  ofstream output ("names_output.txt");
  string name_arr[6];
  int s = 6;

  //copying file content to string arr
  ifstream file("names.txt");
  if(file.is_open()){
    for(int i = 0; i < s; i++){
      file >> name_arr[i];
    }
  }

  //call function
  writeletter(name_arr, s, output);

  return 0;
}

/*
FUNCITON DID NOT ALPHABETICALLY SORT BY FIRST LETTER
void writeletter(string names[], int size, ofstream& out){
  //write first name to ofstream& out
  out << names[0] << endl;
  for(int i = 0; i < size; i++){
    for(int j = 1; j < size; j++){
      if(!names[i].empty()){
        if(names[i].front() == names[j].front()){
          //add names[j] after names[i]
          cout << names[j] << endl;
          out << names[j] << endl;
          //set null
          names[j].clear();
        }
      }
    }
  }
  out.close();
}
*/

void writeletter(string names[], int size, ofstream& out){
  //character array of first letters
  //will be sorted alphabetically
  char first_letters[size];
  for(int i = 0; i < size; i++){
    first_letters[i] = names[i][0];
  }

  for(int j = 0; j < size; j++){
    for(int n = j + 1; n < size; n++){
      if(first_letters[j] == first_letters[n]){ //checking if it is same letter
        for (int l = n; l < size; l++){
          first_letters[n] = first_letters[l+1];
        }
      }
      else if(first_letters[j] > first_letters[n]){ //checking if it is higher letter
        char tmp = first_letters[j];
        first_letters [j] = first_letters[n];
        first_letters[n] = tmp;
      }
    }
  }

  //write to output file
  for(int x = 0; x < size; x++){
    writeToFile(names, size, first_letters[x], out);
  }
  out.close();
}

void writeToFile(string names[], int size, char first_letters, ofstream& out){
  for(int i = 0; i < size; i++){
    if(names[i][0] == first_letters){
      //cout << names[i] << endl;
      out << names[i] << endl;
    }
  }
}
