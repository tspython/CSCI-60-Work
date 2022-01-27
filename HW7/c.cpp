#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
  for (int i = 1; i <= 100; ++i)
  {
      cout << i << " ";
      //this_thread::sleep_for(chrono::seconds(1));
  }
  cout << endl;
  return 0;
}
