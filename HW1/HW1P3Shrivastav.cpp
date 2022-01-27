/*
  Filename: HW1P3Shrivastav.cpp
  Course: CSCI 60
  Author: Tushar Shrivastav
*/

#include <iostream>
#include <string>
using namespace std;

class Movie{
  private:
    string name;
    string rating;
    double earned_money;
  public:
    Movie(string n, string r, double em){
      name = n;
      rating = r;
      earned_money = em;
    }

    Movie(){
      name = "";
      rating = "NYR"; //not yet rated
      earned_money= 0;
    }

    string get_name(){
      return name;
    }

    string get_rating(){
      return rating;
    }

    double get_earned_money(){
      return earned_money;
    }

    void set_name(string n){
      name = n;
    }

    void set_rating(string r){
      rating = r;
    }

    void set_earned_money(double em){
      earned_money = em;
    }

    /*
    * Pre: takes number of people at the movie showing as argument
    * Post: returns new earnings after showing
    */
    double movieShowing(int n){
      earned_money += (12*n);
      return earned_money;
    }

    /*
    * Pre: takes a movie object as an argument
    * Post: returns more restrictive rating if same name, other wise returns
    *       object that is named "Could not combine"
    */
    Movie mergeMovie(Movie m){
      //check if name is same
      if(name == m.get_name()){
        //set name and create merged movie
        Movie merged_movie;
        merged_movie.name = name;
        //check ratings using or operator to find more restrictive
        if(rating == "R" || m.get_rating() == "R"){
          merged_movie.rating = "R";
        }
        else if (rating == "PG-13" || m.get_rating() == "PG-13"){
          merged_movie.rating = "PG-13";
        }
        else if (rating == "PG" || m.get_rating() == "PG"){
          merged_movie.rating = "PG";
        }
        else{
          merged_movie.rating = "G";
        }
        //set earned money money and return
        merged_movie.earned_money += earned_money + m.get_earned_money();
        return merged_movie;
      }
      //else if name isn't the same
      Movie error("Could not combine", "NYR", 0 );
      return error;
    }
};


int main(){
  Movie m;
  Movie m1("Cat in the Hat", "G", 100);
  Movie m2("Cat in the Hat", "PG", 100);

  cout << "Pre Theater for m1:" << endl;
  cout << m1.get_earned_money() << endl;
  m1.movieShowing(10);
  cout << "Post Theater for m1:" << endl;
  cout << m1.get_earned_money() << endl;

  Movie m3 = m2.mergeMovie(m1);
  Movie m4 = m2.mergeMovie(m);


  cout<< m3.get_name() << endl;
  cout<< m3.get_rating() << endl;
  cout<< m3.get_earned_money() << endl;

  cout<< m4.get_name() << endl;

  return 0;
}
