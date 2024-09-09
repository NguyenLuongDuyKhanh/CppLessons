#include <iostream>
#include <utility>
using namespace std;

int main()
{
    // defining a pair
    pair<int, char> PAIR1;
 
    // first part of the pair
    PAIR1.first = 100;
    // second part of the pair
    PAIR1.second = 'G';
 
    cout << PAIR1.first << " ";
    cout << PAIR1.second << endl;
 
    // Different ways to initialize pair:  
    //pair  g1;         //default
    pair  g2(1, 'a');  //initialized,  different data type
    pair  g3(1, 10);   //initialized,  same data type
    pair  g4(g3);    //copy of g3

    pair g5{2, "Something"};
    cout << g5.second << endl;

    pair g6 = make_pair(1, 'a');


    // defining a pair
    pair<string, int> PAIR2("GeeksForGeeks", 1.23);
 
    cout << PAIR2.first << " ";
    cout << PAIR2.second << endl; // = 1 because it is expected as int
 
    PAIR2.first = "somethingelse";

    cout << PAIR2.first << " ";
    cout << PAIR2.second << endl; // = 1 because it is expected as int

    return 0;
}
