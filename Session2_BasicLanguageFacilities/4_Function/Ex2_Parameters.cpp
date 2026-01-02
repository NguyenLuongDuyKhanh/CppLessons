#include <iostream>
using namespace std;

void myFunction(string country = "Norway") {
  cout << country << "\n";
}

/*  Only the last parameters can have a default value. 
    Hence the first declaration below is valid while the second isn't.

void sampleFunction(int x, int y=10);
void sampleFunction(int x=10, int y);
*/

int main() {
  myFunction("Sweden");
  myFunction("India");
  myFunction();
  myFunction("USA");
  return 0;
}